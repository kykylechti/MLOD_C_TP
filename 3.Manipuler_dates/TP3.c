#include <stdio.h>

enum Mois{
    Janvier,
    Fevrier,
    Mars,
    Avril,
    Mai,
    Juin,
    Juillet,
    Aout,
    Septembre,
    Octobre,
    Novembre,
    Decembre
}

Struct Date {
    int day;
    Mois mois; 
    int year;
}

void initialiseDate(Date* d){
    d->day = 00;
    d->mois = Janvier;
    d->year = 0000;
}

void afficheDate(Date* d){
    printf("%d/%s/%d", d->day, d->mois, d->year);
}

int main(void){
    Date d;
    initialiseDate(&d);
    afficheDate(&d);
    return 0;
}