#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <assert.h>

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
char** readWinners(FILE* f, int* nbLigne){
    int maxline = 1024; 
    char* line = malloc(maxline*sizeof(char));
    *nbLigne = numberOfWinners(f);
    
    //Retour au début du fichier
    fseek(f, 0, 0);

    char** res = malloc((*nbLigne)*sizeof(*res));
    for(int i = 0; i<(*nbLigne); i++){
        //Allocation de la mémoire
        res[i]=malloc(maxline*sizeof(char));
        //Lecture depuis le fichier
        fgets(res[i], maxline, f);
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