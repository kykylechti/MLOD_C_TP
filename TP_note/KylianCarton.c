//Kylian Carton

#include <stdio.h>
#include <stdlib.h>

//Fonction permettant de calculer la taille du tableau qu'il sera nécessaire de créer pour la fonction repeat
int sizeTab(int taille, int tab[]){
    int total = 0;
    for(int i=0;i<taille;i++){
        total += tab[i];
    }
    return total;
}

int* repeat(int t1[], int t2[], int taille, int tailleRes){

    //Déclaration des variables
    int index = 0;

    //Allocation de la mémoire pour le tableau dont on va renvoyer l'adresse
    int* tabRes = malloc(tailleRes*sizeof(int)); 

    //On remplit notre tableau tabRes comme voulu
    for(int i = 0;i < taille; i ++){
        for(int j = 0; j < t1[i]; j++){
            tabRes[index]=t2[i];
            index++;
        }
    }

    //On renvoie l'adresse du premier élément de notre tableau pour y avoir accès dans le main
    return tabRes;
}

int main(void){

    //Déclaration des variables
    int tailleTab = 3;
    int t1[] = {2,5,1};
    int t2[] = {1,0,7};
    int tailleRes = sizeTab(tailleTab, t1);

    //Appel à la fonction repeat en récupérant l'adresse du premier élément du tableau
    int *t = repeat(t1, t2, tailleTab, tailleRes);

    //Affichage de la fonction repeat
    for(int i = 0; i < tailleRes; i++){
        printf(" %d -> ", t[i]);
    }

    //On libère la mémoire
    free(t);
    return 0;
}