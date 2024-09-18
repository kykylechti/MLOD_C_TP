#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <assert.h>

struct prixTuring
{
    int annee;
    char* nom;
    char* sujet;
};


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

//Fonction permettant de stocker en mémoire les informations du fichier en paramètre
struct prixTuring* readWinners(FILE* f){
    int nbLigne = numberOfWinners(f);
    struct prixTuring* res = malloc(nbLigne*sizeof(struct prixTuring));
    
    //Retour au début du fichier
    fseek(f, 0, 0);
    char curseur;
    char* temp;

    for(int i = 0; i<(*nbLigne); i++){
        curseur = getc(f)
        while(curseur!=';'){

        }
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

    char** test = readWinners(f, &tailleFichier);

    for(int i = 0; i<tailleFichier; i++){
        printf("%s", test[i]);
    }
    
    printf("\n Nombre de ligne dans le fichier : %d \n", tailleFichier);


    for(int i = 0; i<tailleFichier; i++){
        free(test[i]);
    }
    free(test);
    free(line);
    fclose(f);
    fclose(output);
    return 0;
}