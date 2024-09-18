//Kylian Carton

#include <stdio.h>
#include <stdlib.h>

int sizeTab(int taille, int tab[taille]){
    int total = 0;
    for(int i=0;i<taille;i++){
        total += tab[i];
    }
    return total;
}

int* repeat(int t1[], int t2[], int taille){
    int tailleRes = sizeTab(taille, t1);
    int* tabRes = malloc(tailleRes*sizeof(int)); 
    for(int i = 0;i < taille; i ++){
        for(int j = 0; j < t1[taille]; j++){
            tabRes[i+j]=t2[i];
        }
    }
    return tabRes;
}

int main(void){
    int t1[] = {1,2,4};
    int t2[] = {10,3,8};
    int *t = repeat(t1, t2, 3);
    for(int i = 0; i < sizeTab(3, t1); i++){
        printf(" %d -> ", t[i]);
    }
    free(t);
    return 0;
}