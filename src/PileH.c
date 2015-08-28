/** \file PileH.c
 * \brief Gestion de la pile contenant l'historique des étapes pendant le jeu (source)
 */

#include "../include/PileH.h"

///*************************************************///
/// PILE HISTORIQUE DES AJOUTS, STATIQUE, TAILLE 42 ///
///*************************************************///

PileH hpilenouv(PileH p){
	p.iPosition=0;
	p.iHauteurMax=0;
	return p;
}

// PRECONDITION : hauteur(p)<42
PileH hempiler(PileH p, Nat c){
	p.pile[p.iPosition]=c;
	p.iPosition=p.iHauteurMax+=1;
	return p;
}

// PRECONDITION : !hvide(p)
PileH hdesempiler(PileH p){
	p.iPosition--;
	return p;
}

PileH hsynchauteur(PileH p){
	p.iHauteurMax=p.iPosition;
	return p;
}

// PRECONDITION : !hvide(p)
Nat hsommet(PileH p){
	return p.pile[p.iPosition-1];
}

Nat hhauteur(PileH p){
	return p.iPosition;
}

Bool hvide(PileH p){
	if (p.iPosition==0) return vrai;
	else return faux;
}

