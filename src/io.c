/** \file io.c
 * \brief Gestion des entrées/sorties : clavier/écran (code source)
 */
 
#include "../include/io.h"

///**********************************///
/// AFFICHAGE DU JEU EN MODE CONSOLE ///
///**********************************///

/** \brief pointeur de fonction (mode de jeu, 1 ou 2 joueurs) : 
 * pointe sur unJoueur (par défaut) ou sur deuxJoueurs
 */
Nat (*modeDeJeu) (P4* jeu) = unJoueur ;
/** \brief défini dans jeu.c*/
extern P4 (*undo) (P4); 
/** \brief défini dans jeu.c*/
extern P4 (*redo) (P4);


void affiche_trait(){
	int i;
	printf("\t");
	for (i=0; i<7; ++i) printf ("|- -");
	printf("|\n");
	return;
}

void affiche_ligne(P4 jeu, Nat l){
	int i;
	printf("\t");
	for (i=0; i<7; ++i){
		if (hauteur(jeu.tPile[i]) < l) printf ("|   "); 
		else{
			if (kieme(jeu.tPile[i], l) == faux) printf ("| X ");
			else printf ("| O ");
		}
	}
	printf("|\n");
	return;
}

void affiche_jeu(P4 jeu){
	int i;
	printf("\n");
	affiche_trait();
	for (i=6; i>0; i--) {
		affiche_ligne(jeu, i);
		affiche_trait();
	}	
	printf("\n"); 
	printf("\t  1   2   3   4   5   6   7\n");
	return;
}

void efface_jeu(){
	printf("\n\e[%dA",18); 
}

void efface_ecran(){
	printf("\n\e[%dA",12); 
}

void debut_jeu(P4 jeu){
	char c; 
	while (1){
		c = getchar(); 
		switch (c) {
			case '1' :
				jeu = ajouterPion(jeu, 0);
				while(getchar() != '\n');
				break;
			
			case '2' :
				jeu = ajouterPion(jeu, 1);
				while(getchar() != '\n');
				break;
			
			case '3' :
				jeu = ajouterPion(jeu, 2);
				while(getchar() != '\n');
				break;
			
			case '4' :
				jeu = ajouterPion(jeu, 3);
				while(getchar() != '\n');
				break;
			
			case '5' :
				jeu = ajouterPion(jeu, 4);
				while(getchar() != '\n');
				break;
			
			case '6' :
				jeu = ajouterPion(jeu, 5);
				while(getchar() != '\n');
				break;
			
			case '7' :
				jeu = ajouterPion(jeu, 6);
				while(getchar() != '\n');
				break;
			
			case 'u' :
				jeu = undo(jeu);
				while(getchar() != '\n');
				break;
			
			case 'r' :
				jeu = redo(jeu);
				while(getchar() != '\n');
				break;
				
			case 'q' :
				while(getchar() != '\n');
				return;
			
			default : // touche non traitée
				break;
		}
		efface_jeu();
		affiche_jeu(jeu);
		
		if(modeDeJeu(&jeu)) break;
			
		if (plusDePlace(jeu) == vrai){
			printf("\nLa grille est remplie... Partie terminée !\n");
			while(getchar() != '\n');
			break;
		}
	}
	return;	
}

Nat unJoueur(P4* jeu){
	if ((*jeu).ph.iHauteurMax == (*jeu).ph.iPosition){
		if (partieTerminee(*jeu) == vrai){
			printf("\nVous avez gagné en %d coups !", nbEtapes(*jeu)/2 + 1);
			while(getchar() != '\n');
			return 1;
		}
		else{
			if (aquiletour(*jeu) == faux){
				*jeu = aSonTour(*jeu);
				printf("\n");
				efface_jeu();
				affiche_jeu(*jeu);
				if (partieTerminee(*jeu) == vrai){
					printf("\nL'ordinateur a gagné en %d coups.", nbEtapes(*jeu)/2);
					while(getchar() != '\n');
					return 1;
				}
			}
		}
	}
	return 0;
}

Nat deuxJoueurs(P4* jeu){
	if ((*jeu).ph.iHauteurMax == (*jeu).ph.iPosition){
		if (partieTerminee(*jeu) == vrai){
			switch(!aquiletour(*jeu)){
				case vrai :
					printf("\nLe joueur 1 a gagné en %d coups !", nbEtapes(*jeu)/2 + 1);
					while(getchar() != '\n');
					break;
					
				case faux :
					printf("\nLe joueur 2 a gagné en %d coups !", nbEtapes(*jeu)/2);
					while(getchar() != '\n');
					break;
					
				default :
					printf("\n?!?");
					while(getchar() != '\n');
					break;
			}
			return 1;
		}
	}
	return 0;
}
