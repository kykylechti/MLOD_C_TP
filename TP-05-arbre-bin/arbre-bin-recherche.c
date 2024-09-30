#include "arbre-bin-recherche.h"
#include <stdlib.h>
#include <stdbool.h>

// retourne TRUE si a est l'arbre vide et FALSE sinon
bool estVide(ArbreBinaire a) {
	return a==NULL;
}

// initialise l'arbre a à l'arbre vide
void initialiser(ArbreBinaire* a) {
	*a=NULL;
}

// créer un arbre contenant un seul noeud ayant la valeur e
ArbreBinaire creer(Element e) {
	ArbreBinaire a;
	a=malloc(sizeof(Noeud));
	a->val=e;
	a->filsGauche=NULL;
	a->filsDroit=NULL;
	return a;
}

// insere e dans a sachant que a est un arbre binaire de recherche
// si a contient déjà un element e, ce dernier n'est pas insérer afin d'éviter les doublons
// version itérative
ArbreBinaire insere_i(ArbreBinaire a, Element e) {
	ArbreBinaire pere_p, p=a;
	while(!estVide(p)&&p->val!=e){
		pere_p=p;
		if(p->val>=e)
			p=p->filsGauche;
		else	
			p=p->filsDroit;
	}
	if(estVide(p)){
		if(estVide(pere_p)){
			a=creer(e);
		}
		else{
			if(pere_p->val>e)
				pere_p->filsGauche = creer(e);
			if(pere_p->val<e)
				pere_p->filsDroit = creer(e);
		}
	}
	return a;
	// ArbreBinaire curseur = a;
	// if(estVide(a)){
	// 	return creer(e);
	// }
	// while(curseur->filsDroit!=NULL||curseur->filsGauche!=NULL){
	// 	if(curseur->val==e){
	// 		return a;
	// 	}
	// 	if(e<=curseur->val&&curseur->filsGauche!=NULL){
	// 		curseur = curseur->filsGauche;
	// 	}
	// 	else if(e<=curseur->val&&curseur->filsGauche==NULL){
	// 		curseur->filsGauche = creer(e);
	// 		return a;
	// 	}
	// 	if(e>curseur->val&&curseur->filsDroit!=NULL){
	// 		curseur = curseur->filsDroit;
	// 	}
	// 	else if(e>curseur->val&&curseur->filsDroit==NULL){
	// 		curseur->filsDroit = creer(e);
	// 		return a;
	// 	}
	// }
	// if(e<=curseur->val){
	// 	curseur->filsGauche = creer(e);
	// }
	// if(e>curseur->val){
	// 	curseur->filsDroit = creer(e);
	// }
	// return a;
}	

// insere e dans a sachant que a est un arbre binaire de recherche
// si a contient déjà un element e, ce dernier n'est pas insérer afin d'éviter les doublons
// version récursive
ArbreBinaire insere_r(ArbreBinaire a, Element e) {
	if(a==NULL){
		return creer(e);
	}
	if(a->val == e){
		return a;
	}
	if(e<a->val){
		a->filsGauche = insere_r(a->filsGauche, e);
	}
	if(e>a->val){
		a->filsDroit = insere_r(a->filsDroit, e);
	}
	return a;
}

// retourne le nombre de noeud contenus dans l'arbre a
int nombreDeNoeud(ArbreBinaire a){

		return 0;
}


// retourne la profondeur du noeud ayant la valeur e dans a
// retourne -1 si a est vide ou si e n'est pas dans a
int profondeur(ArbreBinaire a, Element e){

		return 0;
}

// retourne la hauteur de l'arbre a
int hauteur(ArbreBinaire a){
	return 0;
}

// retourne le pere de elem dans l'arbre a ou NULL s'il n'existe pas
ArbreBinaire pere(ArbreBinaire a, Element elem){

	return NULL;
}


void afficheRGD_r(ArbreBinaire a){
	printf("(");
	printf("%d ", a->val);
	if(a->filsGauche!=NULL)
		afficheGRD_r(a->filsGauche);
	if(a->filsDroit!=NULL)
		afficheGRD_r(a->filsDroit);
	printf(")");
}

void afficheGRD_r(ArbreBinaire a){
	printf("(");
	if(a->filsGauche!=NULL)
		afficheGRD_r(a->filsGauche);
	printf("%d ", a->val);
	if(a->filsDroit!=NULL)
		afficheGRD_r(a->filsDroit);
	printf(")");
}

void afficheGDR_r(ArbreBinaire a){
	printf("(");
	if(a->filsGauche!=NULL)
		afficheGRD_r(a->filsGauche);
	if(a->filsDroit!=NULL)
		afficheGRD_r(a->filsDroit);
	printf("%d ", a->val);
	printf(")");
}

// retourne le noeud dont la valeur est minimum dans l'arbre
// Suppose que a est un arbre binaire de recherche sans doublons
ArbreBinaire min(ArbreBinaire a){
	return NULL;
}

// retourne le noeud dont la valeur est maximum dans l'arbre
// Suppose que a est un arbre binaire de recherche sans doublons
ArbreBinaire max(ArbreBinaire a){
	return NULL;
}


// retourne l'arbre dont la valeur de la racine est elem et NULL si elem n'existe dans a 
// version récursive
ArbreBinaire recherche_r(ArbreBinaire a, Element elem){

	return NULL;
}


// suppime x de a
ArbreBinaire supprimer_r(ArbreBinaire a,Element x)
{

	return NULL;
}

void detruire_r(ArbreBinaire a){

}

