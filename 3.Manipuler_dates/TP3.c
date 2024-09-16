#include <stdio.h>

typedef enum {
    Janvier=1,
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
}Mois;

struct Date {
    int day;
    Mois mois; 
    int year;
};

void initialiseDate(struct Date* d){
    int tmp=0;
    printf("Jour : ");
    scanf("%d", &d->day);
    printf("Mois : ");
    scanf("%d", &tmp);
    d->mois = (Mois)tmp;
    printf("Année : ");
    scanf("%d", &d->year);
}

void afficheDate(struct Date* d){
    printf("%d/%d/%d", d->day, d->mois, d->year);
}

int main(void){
    struct Date d;
    initialiseDate(&d);
    afficheDate(&d);
    return 0;
}