#include "beer_song.h"
#include <stdint.h>
#include <stdio.h>

#define MAX_LINE_LENGTH (1024)
#define MAX_LINE_COUNT (299)

void recite(uint8_t start_bottles, uint8_t take_down, char **song){
    for(int i=start_bottles; i>start_bottles-take_down; i--){
        if(i>=2){
            sprintf(song[3*i], "%d bottles of beer on the wall, %d bottles of beer.", i, i);
            sprintf(song[3*i+1], "Take one down and pass it around, %d %s of beer on the wall.", i-1, (i-1==1 ? "bottle":"bottles"));
        } else if(i==1){
            sprintf(song[3*i], "1 bottle of beer on the wall, 1 bottle of beer.");
            sprintf(song[3*i+1], "Take it down and pass it around, no more bottles of beer on the wall.");
        }
        else if(i==0){
            song[3*i] = "No more bottles of beer on the wall, no more bottles of beer.";
            song[3*i+1] = "Go to the store and buy some more, 99 bottles of beer on the wall.";
        }
    }
}