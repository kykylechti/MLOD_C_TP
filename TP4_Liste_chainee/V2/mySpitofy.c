#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "linkedListOfMusic.h"

typedef struct{
	char* name;
	char* artist; 
	char* album; 
	char* genre;
	int discNumber;
	int trackNumber;
	int year;
} Music;

void detruireElement(Element e) {
    free(((Music*)(e))->name);
    free(((Music*)(e))->artist);
    free(((Music*)(e))->album);
    free(((Music*)(e))->genre);
	free(e);
}

void afficheElement(Element e){
    printf("%s, %s, dans le genre %s, sur l'album %s, disque numéro %d, track numéro %d, en %d \n", ((Music*)(e))->artist, ((Music*)(e))->name, ((Music*)(e))->genre, ((Music*)(e))->album, ((Music*)(e))->discNumber, ((Music*)(e))->trackNumber, ((Music*)(e))->year);
}

bool equalsElement(Element v1, Element v2){
    return strcmp(((Music*)(v1))->album,((Music*)(v2))->album)==0 && ((Music*)(v1))->artist==((Music*)(v2))->artist && ((Music*)(v1))->name==((Music*)(v2))->name && ((Music*)(v1))->genre==((Music*)(v2))->genre && ((Music*)(v1))->discNumber==((Music*)(v2))->discNumber && ((Music*)(v1))->trackNumber==((Music*)(v2))->trackNumber && ((Music*)(v1))->year==((Music*)(v2))->year;
}

void recupererMusic(Music *morceau, char ligne[]){
    char* temp = strtok(ligne, ",");
    morceau->name=malloc(strlen(temp)*sizeof(char));
    strcpy(morceau->name,temp);
    
    temp = strtok(NULL, ",");
    morceau->artist=malloc(strlen(temp)*sizeof(char));
    strcpy(morceau->artist,temp);

    temp = strtok(NULL, ",");
    morceau->album=malloc(strlen(temp)*sizeof(char));
    strcpy(morceau->album,temp);

    temp = strtok(NULL, ",");
    morceau->genre=malloc(strlen(temp)*sizeof(char));
    strcpy(morceau->genre,temp);

    morceau->discNumber=atoi(strtok(NULL, ","));
    morceau->trackNumber=atoi(strtok(NULL, ","));
    morceau->year=atoi(strtok(NULL, "\n"));
}

Liste fileReader(FILE* f){
    rewind(f);
    Liste l = NULL;
    char tab[10000];
    while(feof(f)==0){
        Music* temp = malloc(sizeof(Music));
        fgets(tab, 10000, f);  
        recupererMusic(temp, tab);
        l = ajoutFin_i(temp, l);
    }
    return l;
}

int main(void){
    char filename[] = "music.csv";
    char outputFilename[] = "out.csv";

    FILE* musicf = fopen(filename, "r");
    FILE* output = fopen(outputFilename, "w");
    Liste l = fileReader(musicf);

    afficheListe_i(l);
    detruire_i(l);

    fclose(musicf);
    fclose(output);
    return 0; 
}