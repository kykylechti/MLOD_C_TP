#include <stdio.h>

//énumération des mois de l'année
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

//création du type date
struct Date {
    int day;
    Mois mois; 
    int year;
};
typedef struct Date Date;

//Initialisation d'une date par adresse
void initialiseDate(Date* d){
    int tmp=0;
    printf("Jour : ");
    scanf("%d", &d->day);
    printf("Mois : ");
    scanf("%d", &tmp);
    d->mois = (Mois)tmp;
    printf("Année : ");
    scanf("%d", &d->year);
    printf("\n");
}

//Initialisation d'une date par copie
Date creerDateParCopie(){
    int tmp=0;
    Date t;
    printf("Jour : ");
    scanf("%d", &(t.day));
    printf("Mois : ");
    scanf("%d", &tmp);
    t.mois = (Mois)tmp;
    printf("Année : ");
    scanf("%d", &(t.year));
    printf("\n");
    return t;
}

//Affichage de la date 
void afficheDate(Date* d){
    printf("%d/%d/%d", d->day, d->mois, d->year);
}

int main(void){
    Date d;
    initialiseDate(&d);
    afficheDate(&d);
    d = creerDateParCopie();
    afficheDate(&d);
    return 0;
}