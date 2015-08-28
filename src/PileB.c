/** \file PileB.c
 * \brief Gestion des piles de booléens (source)
 */

#include "../include/PileB.h"

///***************************************///
/// PILE DE BOOLEENS STATIQUE DE TAILLE 6 ///
///***************************************///

PileB pilenouv(PileB p){
    p.iTete=0;
    p.pile=0;  
    return p;
}

// PRECONDITION : hauteur(p)<6
PileB empiler(PileB p, Bool b){
	if (b) p.pile |= (1 << (p.iTete));
	else p.pile &= ~(1 << (p.iTete));
    p.iTete+=1;
    return p;
}

// PRECONDITION : !vide(p)
PileB desempiler(PileB p){
    p.iTete--;
    return p;
}

// PRECONDITION : !vide(p)
Bool sommet(PileB p){
	Bool b;
	if (p.pile & (1 << (p.iTete-1))) b=1;
    else b=0;
	return b;
}

Nat hauteur(PileB p){
	return p.iTete;
}

Bool vide(PileB p){
	if (p.iTete==0) return vrai;
	else return faux;
}

// PRECONDITION : !vide(p)
// PRECONDITION : k>0 && k<=hauteur(p)
Bool kieme(PileB p, Nat k){
	Nat d = p.iTete-k;
	while(d != 0){
		p = desempiler(p);
		d--;
	}
	return sommet(p);
}

