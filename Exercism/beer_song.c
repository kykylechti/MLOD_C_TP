#include "beer_song.h"
#include <stdint.h>
#include <stdio.h>

#define MAX_LINE_LENGTH (1024)
#define MAX_LINE_COUNT (299)

void recite(uint8_t start_bottles, uint8_t take_down, char **song){
    for(int i = start_bottles; i>start_bottles-take_down; i--){
        if(i>=2){
            sprintf(*song, "%d bottles of beer on the wall, %d bottles of beer.", i, i);
            song++;
            sprintf(*song, "Take one down and pass it around, %d %s of beer on the wall.", i-1, (i-1==1 ? "bottle":"bottles"));
            song++;
        }
        else if (i==1){
            sprintf(*song, "1 bottle of beer on the wall, 1 bottle of beer.");
            song++;
            sprintf(*song, "Take it down and pass it around, no more bottles of beer on the wall.");
            song++;
        }
        else if(i==0){
            sprintf(*song, "No more bottles of beer on the wall, no more bottles of beer.");
            song++;
            sprintf(*song, "Go to the store and buy some more, 99 bottles of beer on the wall.");
            song++;
        }
        song++;
    }
}