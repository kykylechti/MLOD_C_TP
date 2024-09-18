#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <assert.h>

int main(void){

    //Chemin d'accès aux fichiers
    char filename[] = "turingWinners.csv";
	char outputFilename[] = "out.csv";

    FILE* f = fopen(filename, "r");

    fclose(f);
    return 0;
}