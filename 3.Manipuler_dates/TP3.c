#include <stdio.h>
#include <stdlib.h>

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
    return t;
}

//Création d'une date par malloc
Date* newDate(){
    Date* t = malloc(sizeof(Date));
    int tmp=0;
    printf("Jour : ");
    scanf("%d", &t->day);
    printf("Mois : ");
    scanf("%d", &tmp);
    t->mois = (Mois)tmp;
    printf("Année : ");
    scanf("%d", &t->year);
    return t;
}

//Affichage de la date 
void afficheDate(Date* d){
    printf("%d/%d/%d", d->day, d->mois, d->year);
    printf("\n");
}

int main(void){
    Date d;
    //initialiseDate(&d);
    //afficheDate(&d);
    //d = creerDateParCopie();
    //afficheDate(&d);

    Date *date;
    date = newDate();
    afficheDate(date);
    free(date);date=NULL;
    return 0;
}