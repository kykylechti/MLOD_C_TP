#include "liste-chainee.h"
#include <stdlib.h>
#include <stdio.h>

#define TODO NULL;

// retourne vrai si l est vide et faux sinon
bool estVide(Liste l) {
	return l == NULL;
}

// créer une liste d'un seul élément contenant la valeur v
Liste creer(Element v){
    Liste res = malloc(sizeof(Cellule)); 
    res->val = v;
    res->suiv = NULL;
	return res;
}

void afficheElement(Element e){
	printf("%i ", e);
}

// ajoute l'élément v en tete de la liste l
Liste ajoutTete(Element v, Liste l) {
	Liste res = creer(v);
	res->suiv = l; 
	return res;
}

// affiche tous les éléments de la liste l
// Attention, cette fonction doit être indépendante du type des éléments de la liste
// utiliser une fonction annexe affiche_element
// Attention la liste peut être vide !
// version itérative
void afficheListe_i(Liste l) {
	while(l!=NULL){
		afficheElement(l->val);
		l = l->suiv;
	}
	printf("\n");
}

// version recursive
void afficheListe_r(Liste l) {
	if(l->suiv!=NULL){
		afficheElement(l->val);
		afficheListe_r(l->suiv);
	}
	else {
		afficheElement(l->val);
	}
}

void detruireElement(Element e) {
}

// Détruit tous les éléments de la liste l
// version itérative
void detruire_i(Liste l) {
	Liste temp = l;
	while(l->suiv!=NULL){
		temp=l;
		l=l->suiv;
		detruireElement(l->val);
		free(temp);
	}
}

// version récursive
void detruire_r(Liste l) {
	if(l!=NULL){
		detruireElement(l->val);
		detruire_r(l->suiv);
	    free(l);
	}
}

// retourne la liste dans laquelle l'élément v a été ajouté en fin
// version itérative
Liste ajoutFin_i(Element v, Liste l) {
	if(l==NULL){
        return creer(v);
    }
    Liste derniereCellule=l; 
    while(derniereCellule->suiv!=NULL){
        derniereCellule=derniereCellule->suiv;
    }
    derniereCellule->suiv=creer(v);
    return l;
}

// version recursive
Liste ajoutFin_r(Element v, Liste l) {
	if(l==NULL){
        return creer(v);
    }
    l->suiv = ajoutFin_r(v, l->suiv);
	return l;
}

// compare deux elements
bool equalsElement(Element e1, Element e2){
	return e1 == e2;
}

// Retourne un pointeur sur l'élément de la liste l contenant la valeur v ou NULL
// version itérative
Liste cherche_i(Element v,Liste l) {
	while(l!=NULL){
		if(equalsElement(l->val, v)){
			return l; 
		}
		l = l->suiv; 
	}
	return NULL;
}

// version récursive
Liste cherche_r(Element v,Liste l) {
	if(l==NULL){
		return NULL;
	}
	if(equalsElement(l->val, v)){
		return l;
	} 
	return cherche_r(v, l->suiv);
}

// Retourne la liste modifiée dans la laquelle le premier élément ayant la valeur v a été supprimé
// ne fait rien si aucun élément possède cette valeur
// version itérative
Liste retirePremier_i(Element v, Liste l) {
	Liste curseur = l;
	if(l==NULL){
		return NULL;
	}
    if(equalsElement(l->val, v)){
        detruireElement(l->val);
        curseur = l->suiv;
        free(l); return curseur;
    }
	while(curseur->suiv!=NULL && !equalsElement(v, curseur->suiv->val)){
		curseur = curseur->suiv;
	}
	if(equalsElement(v, curseur->suiv->val)){
		curseur->suiv = curseur->suiv->suiv;
	}
	return l; 
}


// version recursive
Liste retirePremier_r(Element v, Liste l) {
	if(l==NULL){
		return NULL;
	}
	if(equalsElement(v, l->val)){
		detruireElement(v);
		return l->suiv; 
	}
	l->suiv = retirePremier_r(v, l->suiv);
	return l; 
}


void afficheEnvers_r(Liste l) {
	if(l->suiv!=NULL){
		afficheEnvers_r(l->suiv);
	}
	afficheElement(l->val);
}   