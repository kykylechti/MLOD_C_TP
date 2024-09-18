#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <assert.h>

//Fonction permettant de calculer la taille d'un fichier
int nbLigneFichier(char* filepath){
    FILE* f = fopen(filepath, "r");
    int tailleFichier = 0;
    int maxline = 1024; 
    char* line = malloc(maxline*sizeof(char));

    while(feof(f)==0){
        fgets(line, maxline, f);
        tailleFichier++;
    }

    fclose(f);
    return tailleFichier;
}

int main(void){

    //Chemin d'accès aux fichiers
    char filename[] = "turingWinners.csv";
	char outputFilename[] = "out.csv";

    int maxline = 1024;
    int tailleFichier=1;

    FILE* f = fopen(filename, "r");
    FILE* output = fopen(outputFilename, "r");
    char* line = malloc(maxline*sizeof(char));

    printf(" %s \n", fgets(line, maxline, f));
    fwrite(line, sizeof(char), maxline, output);
    
    
    printf("Nombre de ligne dans le fichier : %d \n", nbLigneFichier(filename));

    free(line);
    fclose(f);
    fclose(output);
    return 0;
}