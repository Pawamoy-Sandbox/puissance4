/** \file jeu.c
 * \brief Fonctions permettant de jouer (code source)
 */
 
#include "../include/jeu.h"
#define LEVEL 2

///******************///
/// FONCTIONS DE JEU ///
///******************///

/** \brief pointeur de fonction (undo) : 
 * pointe sur undoCP ou sur undoPP
 */
P4 (*undo) (P4); 
/** \brief pointeur de fonction (redo) : 
 * pointe sur redoCP ou sur redoPP
 */
P4 (*redo) (P4); 

P4 undoCP (P4 jeu){
	return retirerPion(retirerPion(jeu));
}

P4 redoCP(P4 jeu){
	if (jeu.ph.iHauteurMax-2 >= jeu.ph.iPosition) return remettrePion(remettrePion(jeu));
	else return jeu;
}

P4 undoPP (P4 jeu){
	return retirerPion(jeu);
}

P4 redoPP(P4 jeu){
	if (jeu.ph.iHauteurMax-1 >= jeu.ph.iPosition) return remettrePion(jeu);
	else return jeu;
}

P4 remettrePion(P4 jeu){
	Nat c;
	Bool b = aquiletour(jeu);
	jeu.ph.iPosition+=1;
	c = colonne(jeu);
	jeu.tPile[c] = empiler(jeu.tPile[c], b);
	return jeu;
}

Nat calculScore(P4 jeu, Bool b){
	// déclaration et initialisation des variables
	Nat sco=0;
	Nat horp=-1, hors=0;
	Nat adj=1;
	Nat i,j;
	// déclaration des tableaux de variables
	Nat diagg[7];
	Nat diagd[7];
	Nat haut[7];
	// initialisation des hauteurs
	for (i=0; i<7; i++) haut[i]=hauteur(jeu.tPile[i]);
	
	// calcul du score pour la première colonne
	// la colonne ne doit pas être vide
	if (haut[0] > 0){
		// le sommet doit être un pion du joueur courant
		if (sommet(jeu.tPile[0]) == b){
			// on ajoute l'alignement vertical au score
			sco+=alignVert(jeu,0);
			// on calcule l'alignement horizontal
			horp=alignHoriz(jeu,0);
			// et on l'ajoute au score
			sco+=horp;
			// on calcule les alignements diagonaux
			diagg[0]=alignDiagGauche(jeu,0);
			diagd[0]=alignDiagDroite(jeu,0);
			// et on les ajoute au score
			sco+=diagg[0];
			sco+=diagd[0];
		}
	}
	
	// calcul du score pour les 6 autres colonnes
	for (i=1; i<7; i++){
		// la pile doit être non vide
		if (haut[i] > 0){
			// le sommet doit être un pion du joueur courant
			if (sommet(jeu.tPile[i]) == b){
				// on ajoute l'alignement vertical au score
				sco+=alignVert(jeu,i);
				// on calcule l'alignement horizontal
				hors=alignHoriz(jeu,i);
				// s'il est égal au précédent et que les hauteurs correspondent
				if (hors==horp && haut[i]==haut[i-1]) ; // on ne fait rien
				// sinon on ajoute l'alignement horizontal au score
				else sco+=hors;
				// on actualise la valeur de l'alignement horizontal précédent
				horp=hors;
				// on calcule l'alignement diagonal gauche
				diagg[i]=alignDiagGauche(jeu,i);
				// pour chaque alignement précédent
				for (j=0; j<i; j++){
					// si l'alignement courant lui est égal
					// et si sa hauteur lui est supérieure de i-j pions
					if (diagg[i]==diagg[j] && haut[i]==haut[j]+(i-j)){
						adj=0; // on n'ajoutera pas au score
						break; // et on sort de la boucle
					}
				}
				if (adj==1) sco+=diagg[i];
				else adj=1;
				// on calcule l'alignement diagonal droit
				diagd[i]=alignDiagDroite(jeu,i);
				// pour chaque alignement précédent
				for (j=0; j<i; j++){
					// si l'alignement courant lui est égal
					// et si sa hauteur lui est inférieure de i-j pions
					if (diagd[i]==diagd[j] && haut[i]==haut[j]-(i-j)){
						adj=0; // on n'ajoutera pas au score
						break; // et on sort de la boucle
					}
				}
				if (adj==1) sco+=diagd[i];
				else adj=1;
			}
		}
	}
	
	// on retourne le score calculé
	return sco;
}

Nat calculMeilleureColonne(P4 jeu){
	Nat i;
	Nat score_courantO=0;
	Nat score_courantJ=0;
	Nat diff=0;
	Nat score_max=0;
	Nat col=-1;
	
	// jouer pour gagner :
	for (i=0; i<7; i++){
		if (alignVert(ajouterPion(jeu,i),i) == 4) return i;
		if (alignHoriz(ajouterPion(jeu,i),i) == 4) return i;
		if (alignDiagGauche(ajouterPion(jeu,i),i) == 4) return i;
		if (alignDiagDroite(ajouterPion(jeu,i),i) == 4) return i;
	}
	
	// rester attentif :
	jeu.ph.iPosition--; // on va placer un pion du joueur
	for (i=0; i<7; i++){ // dans chaque colonne
		// et s'il "gagne", on renvoie l'indice de cette colonne
		if (alignVert(ajouterPion(jeu,i),i) == 4) return i;
		if (alignHoriz(ajouterPion(jeu,i),i) == 4) return i;
		if (alignDiagGauche(ajouterPion(jeu,i),i) == 4) return i;
		if (alignDiagDroite(ajouterPion(jeu,i),i) == 4) return i;
	}
	
	// jouer au score :
	for (i=0; i<7; i++){
		if (hauteur(jeu.tPile[i])<6){
			jeu=ajouterPion(jeu,i);
			score_courantO=calculScore(jeu, !aquiletour(jeu));
			score_courantJ=calculScore(jeu, aquiletour(jeu));
			diff=score_courantO-score_courantJ;
			if (diff >= score_max){ // l'égalité fera que l'ordinateur aura plus tendance à jouer à droite
				score_max=diff;
				col=i;
			}
			jeu=retirerPion(jeu);
		}
	}
	
	// le hasard fait bien les choses :
	if (col==-1){
		do col=rand()%7;
		while(hauteur(jeu.tPile[col])==6);
	}
	return col;
}

P4 aSonTour(P4 jeu){
	Nat i, nbe = nbEtapes(jeu);
	// le temps de réfléchir ;)
	for (i=0; i<30000000; i++) ;
	if (nbe <= 2) return ajouterPion(jeu, rand()%7);
	else return ajouterPion(jeu, calculMeilleureColonne(jeu));
}
	
Bool partieTerminee(P4 jeu){
	Nat c = colonne(jeu);
	Bool b = faux;
	if (alignDiagDroite(jeu, c) >= 4) b=vrai;
	else if (alignDiagGauche(jeu, c) >= 4) b=vrai;
	else if (alignHoriz(jeu, c) >= 4) b=vrai;
	else if (alignVert(jeu, c) >= 4) b=vrai;
	return b;
}

Bool plusDePlace(P4 jeu){
	if (nbEtapes(jeu) >= 42)  return vrai;
	else return faux;
}
	

