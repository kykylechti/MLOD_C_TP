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
	Liste res = malloc(sizeof(Cellule));
	res->val = v; 
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
	Liste tmp = l;
	while(tmp->suiv!=NULL){
		tmp=tmp->suiv;
	}
	tmp->suiv=malloc(sizeof(Cellule));
	tmp=tmp->suiv;
	tmp->val = v;
	return l;
}

// version recursive
Liste ajoutFin_r(Element v, Liste l) {
	if(l->suiv!=NULL){
		l->suiv=ajoutFin_r(v, l->suiv);
	}
	else {
		l->suiv = (Cellule*) malloc(sizeof(Cellule));
		l->suiv->val=v;
		l->suiv->suiv=NULL;
	}
	return l;
}

// compare deux elements
bool equalsElement(Element e1, Element e2){
	return e1 == e2;
}

// Retourne un pointeur sur l'élément de la liste l contenant la valeur v ou NULL
// version itérative
Liste cherche_i(Element v,Liste l) {
	while((l->val!=v) && (l->suiv!=NULL)){
		l=l->suiv;
	}
	if(l->val==v){
		return l;
	} else {
		return NULL;
	}
}

// version récursive
Liste cherche_r(Element v,Liste l) {
	if((l->val!=v) && (l->suiv==NULL)){
		l=NULL;
	}
	else if((l->val!=v) && (l->suiv!=NULL)){
		l = cherche_r(v, l->suiv);
	}
	return l;
}

// Retourne la liste modifiée dans la laquelle le premier élément ayant la valeur v a été supprimé
// ne fait rien si aucun élément possède cette valeur
// version itérative
Liste retirePremier_i(Element v, Liste l) {
	Liste res = l; 
	if(l->val==v){
		l=l->suiv;
	}
	else {
		while((res->suiv->val!=v) && (res->suiv->suiv!=NULL)){
			res=res->suiv;
		}
		if(res->suiv->val==v){
			detruireElement(res->val);
			res->suiv=res->suiv->suiv;
		}

	}
	return l;
}


// version recursive
Liste retirePremier_r(Element v, Liste l) {
	if((l->val!=v) && (l->suiv!=NULL)){
		l->suiv = retirePremier_r(v, l->suiv);
	} else if (l->val==v){
		l=l->suiv;
	}
	return l;
}


void afficheEnvers_r(Liste l) {
	if(l->suiv!=NULL){
		afficheEnvers_r(l->suiv);
	}
	afficheElement(l->val);
}   