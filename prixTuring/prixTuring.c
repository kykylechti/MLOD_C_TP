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
    char line[maxline]; // C99

    while(feof(f)==0){
        fgets(line, maxline, f);
        tailleFichier++;
    }

    return tailleFichier;
}

void affichagePrixTuring(prixTuring prix){
    printf("%d - %s - %s \n", prix.annee, prix.nom, prix.sujet);
}

int recupererDate(char tab[10000]){
    char res[5];
    for(int i = 0; i<4; i++){
        res[i]=tab[i];
    }
    res[4]='\0';
    return atoi(res);
}

char* recupererNomSujet(char tab[10000], int champVoulu){
    if(champVoulu==1){
    int i=5;
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
    else if(champVoulu==2){
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
}


//Fonction permettant de stocker en mémoire les informations du fichier en paramètre
prixTuring* readWinners(FILE* f, int* tailleFichier){
    *tailleFichier = numberOfWinners(f);
    prixTuring* res = malloc((*tailleFichier)*sizeof(prixTuring));
    
    //Retour au début du fichier
    rewind(f);
    int i = 0;
    char tab[10000];

    for(i = 0; i<(*tailleFichier); i++){
        fgets(tab, 10000, f);
        (res+i)->annee = recupererDate(tab);
        (res+i)->nom = recupererNomSujet(tab, 1);
        (res+i)->sujet = recupererNomSujet(tab, 2);
    }

    return res;
}

void printWinners(FILE* f, prixTuring* prix, int taille){
    for(int i = 0; i<taille;i++){
        fprintf(f, "%d;%s;%s\n", prix[i].annee,prix[i].nom,prix[i].sujet);
    }
}

int main(void){

    //Chemin d'accès aux fichiers
    char filename[] = "turingWinners.csv";
	char outputFilename[] = "out.csv";

    int tailleFichier=0;

    FILE* f = fopen(filename, "r");
    FILE* output = fopen(outputFilename, "w");
  
    prixTuring* winners = readWinners(f, &tailleFichier);

    printWinners(output, winners, tailleFichier);

    //for(int i = 0; i<tailleFichier; i++){
        //affichagePrixTuring(test[i]);
    //}
    
    printf("\n Nombre de ligne dans le fichier : %d \n", tailleFichier);

    for(int i=0;i<tailleFichier;i++){
        free(winners[i].nom);
        free(winners[i].sujet);
    }

    free(winners);
    
    fclose(f);
    fclose(output);
    return 0;
}