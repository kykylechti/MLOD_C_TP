#include "beer_song.h"
#include <stdint.h>
#include <stdio.h>

#define MAX_LINE_LENGTH (1024)
#define MAX_LINE_COUNT (299)

void recite(uint8_t start_bottles, uint8_t take_down, char **song){
    for(int i=start_bottles; i>start_bottles-take_down; i--){
        if(i!=0){
            sprintf("%d bottles of beer on the wall, %d bottles of beer.", song[3*(start_bottles-i)], i, i);
            sprintf("Take one down and pass it around, %d bottles of beer on the wall.", song[3*(start_bottles-i)+1], i);
            song[3*(start_bottles-i)+2]="";
        } else {
            song[3*start_bottles] = "No more bottles of beer on the wall, no more bottles of beer.";
            song[3*start_bottles+1] = "Go to the store and buy some more, 99 bottles of beer on the wall.";
        }
    }
}