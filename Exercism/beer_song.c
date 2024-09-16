#include "beer_song.h"
#include <stdint.h>
#include <stdio.h>

#define MAX_LINE_LENGTH (1024)
#define MAX_LINE_COUNT (299)

void recite(uint8_t start_bottles, uint8_t take_down, char **song){
    for(size_t i=0; i<take_down; i++){
        if(i!=start_bottles){
            sprintf(song[3*i], "%d bottles of beer on the wall, %d bottles of beer.", start_bottles-(int)i, start_bottles-(int)i);
            sprintf(song[3*i+1], "Take one down and pass it around, %d bottles of beer on the wall.", start_bottles-2*(int)i);
            song[3*i+2]="";
        } else {
            song[3*i] = "No more bottles of beer on the wall, no more bottles of beer.";
            song[3*i+1] = "Go to the store and buy some more, 99 bottles of beer on the wall.";
        }
    }
}