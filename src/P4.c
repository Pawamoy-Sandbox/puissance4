/** \file P4.c
 * \brief Gestion de la grille de jeu (source)
 */

#include "../include/P4.h"

///***************************///
/// GRILLE DE JEU PUISSANCE 4 ///
///***************************///

P4 jeunouv(P4 jeu){
	Nat i;
	for (i=0; i<7; i++) jeu.tPile[i] = pilenouv(jeu.tPile[i]);
	jeu.ph = hpilenouv(jeu.ph);
	return jeu;
}

P4 ajouterPion(P4 jeu, Nat c){
	if (c>=0 && c<7){
		if (hauteur(jeu.tPile[c])<6){
			jeu.tPile[c] = empiler(jeu.tPile[c], aquiletour(jeu));
			jeu.ph = hsynchauteur(jeu.ph);
			jeu.ph = hempiler(jeu.ph, c);
		}
	}
	return jeu;
}

P4 retirerPion(P4 jeu){
	if (nbEtapes(jeu)>0){
		Nat c = colonne(jeu);
		if (!vide(jeu.tPile[c])) jeu.tPile[c] = desempiler(jeu.tPile[c]);
		if (!hvide(jeu.ph)) jeu.ph = hdesempiler(jeu.ph);
	}
	return jeu;
}

Bool aquiletour(P4 jeu){
	if (nbEtapes(jeu)>0) return (!sommet(jeu.tPile[colonne(jeu)]));
	else return vrai;
}

// PRECONDITION: nbEtapes(jeu)>0
Nat colonne(P4 jeu){
	return hsommet(jeu.ph);
}

Nat nbEtapes(P4 jeu){
	return hhauteur(jeu.ph);
}

Nat alignHoriz(P4 jeu, Nat c){
	if (c>=0 && c<7){
		if (!vide(jeu.tPile[c])){
			Nat align = 1;
			Bool pion = sommet(jeu.tPile[c]);
			Nat position = hauteur(jeu.tPile[c]);
			Nat i;
			// partie gauche
			for (i=1; i<7; i++){
				if (c-i>=0){
					if (hauteur(jeu.tPile[c-i])>=position){
						if (kieme(jeu.tPile[c-i], position) == pion){
							align+=1;
						}
						else break;
					}
					else break;
				}
				else break;
			}
			// partie droite
			for (i=1; i<7; i++){
				if (c+i<7){
					if (hauteur(jeu.tPile[c+i])>=position){
						if (kieme(jeu.tPile[c+i], position) == pion){
							align+=1;
						}
						else break;
					}
					else break;
				}
				else break;
			}
			return align;
		}
		else return 0;
	}
	else return 0;
}

Nat alignVert(P4 jeu, Nat c){
	if (c>=0 && c<7){
		if (!vide(jeu.tPile[c])){
			Nat align = 1;
			Bool pion = sommet(jeu.tPile[c]);
			Nat position = hauteur(jeu.tPile[c]);
			Nat i;
			for (i=1; i<6; i++){
				if (position-i>0){
					if (kieme(jeu.tPile[c], position-i) == pion){
						align+=1;
					}
					else break;
				}
				else break;
			}
			return align;
		}
		else return 0;
	}
	else return 0;
}

Nat alignDiagGauche(P4 jeu, Nat c){
	if (c>=0 && c<7){
		if (!vide(jeu.tPile[c])){
			Nat align = 1;
			Bool pion = sommet(jeu.tPile[c]);
			Nat position = hauteur(jeu.tPile[c]);
			Nat i,j = 1;
			// partie gauche
			for (i=1; i<7; i++){
				if (c-i>=0){
					if (position-j>0){
						if (hauteur(jeu.tPile[c-i])>=position-j){
							if (kieme(jeu.tPile[c-i], position-j) == pion){
								align+=1;
								j++;
								if (j>5) break;
							}
							else break;
						}
						else break;
					}
					else break;
				}
				else break;
			}
			// partie droite
			j = 1;
			for (i=1; i<7; i++){
				if (c+i<7){
					if (position+j<7){
						if (hauteur(jeu.tPile[c+i])>=position+j){
							if (kieme(jeu.tPile[c+i], position+j) == pion){
								align+=1;
								j++;
								if (j>5) break;
							}
							else break;
						}
						else break;
					}
					else break;
				}
				else break;
			}
			return align;
		}
		else return 0;
	}
	else return 0;
}

Nat alignDiagDroite(P4 jeu, Nat c){
	if (c>=0 && c<7){
		if (!vide(jeu.tPile[c])){
			Nat align = 1;
			Bool pion = sommet(jeu.tPile[c]);
			Nat position = hauteur(jeu.tPile[c]);
			Nat i,j = 1;
			// partie gauche
			for (i=1; i<7; i++){
				if (c-i>=0){
					if (position+j<7){
						if (hauteur(jeu.tPile[c-i])>=position+j){
							if (kieme(jeu.tPile[c-i], position+j) == pion){
								align+=1;
								j++;
								if (j>5) break;
							}
							else break;
						}
						else break;
					}
					else break;
				}
				else break;
			}
			// partie droite
			j = 1;
			for (i=1; i<7; i++){
				if (c+i<7){
					if (position-j>0){
						if (hauteur(jeu.tPile[c+i])>=position-j){
							if (kieme(jeu.tPile[c+i], position-j) == pion){
								align+=1;
								j++;
								if (j>5) break;
							}
							else break;
						}
						else break;
					}
					else break;
				}
				else break;
			}
			return align;
		}
		else return 0;
	}
	else return 0;
}


	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	

