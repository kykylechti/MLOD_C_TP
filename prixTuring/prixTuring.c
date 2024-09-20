#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <assert.h>

typedef struct
{
    int annee;
    char* nom;
    char* sujet;
} prixTuring;


//Fonction permettant de calculer la taille d'un fichier
int numberOfWinners(FILE* f){
    int tailleFichier = 0;
    int maxline = 1024; 
    char* line = malloc(maxline*sizeof(char));

    while(feof(f)==0){
        fgets(line, maxline, f);
        tailleFichier++;
    }

    return tailleFichier;
}

void affichagePrixTuring(prixTuring prix){
    printf("%d - %s - %s \n", prix.annee, prix.nom, prix.sujet);
}

int recupererDate(FILE* f, char tab[10000]){
    char res[5];
    for(int i = 0; i<4; i++){
        res[i]=tab[i];
    }
    res[4]='\0';
    return atoi(res);
}

char* recupererNom(FILE* f, char tab[10000]){
    int i=5;
    char curseur;
    while(tab[i]!=';'){
        i++;
    }
    char* res = malloc((i-5)*sizeof(char));
    for(int j=0;j<i-5;j++){
        res[j]=tab[j+5];
    }
    res[i-5]='\0';
    return res;
}

char* recupererSujet(FILE* f, char tab[10000]){
    int fin = 0;
    while(tab[fin]!='\n'){
        fin++;
    }
    int debut = 0; 
    int i=0;
    while((tab[debut]!=';')||(i<2)){
        debut++;
        if(tab[debut]==';'){i++;}
    }
    debut++;
    char* res = malloc((fin-debut+1)*sizeof(char));
    for(int j=0;j<fin-debut;j++){
        res[j]=tab[debut+j];
    }
    res[fin-debut]='\0';
    return res;
}

//Fonction permettant de stocker en mémoire les informations du fichier en paramètre
prixTuring* readWinners(FILE* f, int* tailleFichier){
    *tailleFichier = numberOfWinners(f);
    prixTuring* res = malloc((*tailleFichier)*sizeof(prixTuring));
    
    //Retour au début du fichier
    fseek(f, 0, 0);
    char curseur;
    int i = 0;
    char* temp;
    char tab[10000];

    for(i = 0; i<(*tailleFichier); i++){
        fgets(tab, 10000, f);
        (res+i)->annee = recupererDate(f, tab);
        (res+i)->nom = recupererNom(f, tab);
        (res+i)->sujet = recupererSujet(f, tab);
    }

    return res;
}

int main(void){

    //Chemin d'accès aux fichiers
    char filename[] = "turingWinners.csv";
	char outputFilename[] = "out.csv";

    int maxline = 1024;
    int tailleFichier=0;

    FILE* f = fopen(filename, "r");
    FILE* output = fopen(outputFilename, "r");
    char* line = malloc(maxline*sizeof(char));

    prixTuring* test = readWinners(f, &tailleFichier);

    for(int i = 0; i<tailleFichier; i++){
        affichagePrixTuring(test[i]);
    }
    
    printf("\n Nombre de ligne dans le fichier : %d \n", tailleFichier);

    for(int i=0;i<tailleFichier;i++){
        free(test[i].nom);
        free(test[i].sujet);
    }

    free(test);
    free(line);
    fclose(f);
    fclose(output);
    return 0;
}