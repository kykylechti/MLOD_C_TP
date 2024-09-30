#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "linkedListOfMusic.h"

void afficheElement(Element e){
    printf("%s, %s, dans le genre %s, sur l'album %s, disque numéro %d, track numéro %d, le %d \n", ((Music*)(e))->artist, ((Music*)(e))->name, ((Music*)(e))->genre, ((Music*)(e))->album, ((Music*)(e))->discNumber, ((Music*)(e))->trackNumber, ((Music*)(e))->year);
}

bool equalsElement(Element v1, Element v2){
    return ((Music*)(v1))->album==((Music*)(v2))->album && ((Music*)(v1))->artist==((Music*)(v2))->artist && ((Music*)(v1))->name==((Music*)(v2))->name && ((Music*)(v1))->genre==((Music*)(v2))->genre && ((Music*)(v1))->discNumber==((Music*)(v2))->discNumber && ((Music*)(v1))->trackNumber==((Music*)(v2))->trackNumber && ((Music*)(v1))->year==((Music*)(v2))->year;
}

void recupererMusic(Music *morceau, char ligne[]){
    morceau->name=strtok(ligne, ";");
    morceau->artist=strtok(NULL, ";");
    morceau->album=strtok(NULL, ";");
    morceau->genre=strtok(NULL, ";");
    morceau->discNumber=atoi(strtok(NULL, ";"));
    morceau->trackNumber=atoi(strtok(NULL, ";"));
    morceau->year=atoi(strtok(NULL, ";"));
}

Liste fileReader(FILE* f){
    Liste l = NULL;
    Music* temp = malloc(sizeof(Music)); 
    char tab[10000];
    while(feof(f)==0){
        fgets(tab, 10000, f);  
        recupererMusic(temp, tab);
        ajoutFin_i(temp, l);
    }
    return l;
}

int main(void){
    char filename[] = "music.csv";
    char outputFilename[] = "out.csv";

    FILE* musicf = fopen(filename, "r");
    FILE* output = fopen(outputFilename, "w");
    Liste l = fileReader(musicf);

    printf("%s, %s", ((Music*)(l->val))->album, ((Music*)(l->val))->name);
    afficheListe_i(l);

    fclose(musicf);
    fclose(output);
    return 0; 
}