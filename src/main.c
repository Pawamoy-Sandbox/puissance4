/** \file main.c
 * \brief Programme principal
 */

#include "../include/P4.h"
#include "../include/io.h"

///*********************///
/// PROGRAMME PRINCIPAL ///
///*********************///

/** \brief défini dans jeu.c*/
extern Nat (*modeDeJeu) (P4*); 
/** \brief défini dans jeu.c*/
extern P4 (*undo) (P4); 
/** \brief défini dans jeu.c*/
extern P4 (*redo) (P4);

/** \brief programme principal
 * \return 0
 */
int main(){
	srand(time(NULL));
	P4 jeu = jeunouv(jeu);
	char choix;
	
	system("clear");
	
	while(choix != '3'){
		efface_ecran();
		printf("\n\tBienvenue dans le jeu de Puissance 4 !\n");
		printf("\n 1. Jouer contre l'ordinateur.");
		printf("\n 2. Faire une partie à deux joueurs.");
		printf("\n 3. Quitter le jeu.");
		printf("\n 4. Afficher l'aide.");
		printf("\n\n\tVotre choix :");
		choix = getchar();
		
		switch(choix){
			case '1' :
				modeDeJeu = unJoueur;
				undo = undoCP;
				redo = redoCP;
				system("clear");
				affiche_jeu(jeu);
				debut_jeu(jeu);
				choix=0;
				system("clear");
				break;
				
			case '2' :
				modeDeJeu = deuxJoueurs;
				undo = undoPP;
				redo = redoPP;
				system("clear");
				affiche_jeu(jeu);
				debut_jeu(jeu);
				choix=0;
				system("clear");
				break;
				
			case '3' :
				printf("\tProgramme terminé. Libération de la mémoire");
				printf("\n\n");
				while(getchar() != '\n');
				break;
				
			case '4' :
				printf(" Entrez \"1\", \"2\" ou \"3\" puis appuyez sur \"Entrée\"    \n pour choisir une des trois options.\n");
				printf(" Pendant le jeu, procédez de la même façon pour\n choisir de placer un pion dans une colonne.\n");
				printf(" Vous pouvez aussi annuler des placements successifs\n de pions avec la touche 'u', et les réitérer avec 'r'\n");
				printf(" Vous pouvez également arrêter la partie en cours\n en appuyant sur \"q\" puis \"Entrée\".");
				while(getchar() != '\n');
				while(getchar() != '\n');
				printf("\n\e[%dA",9);
				printf("                                                            \n");
				printf("                                                            \n");
				printf("                                                            \n");
				printf("                                                            \n");
				printf("                                                            \n");
				printf("                                                            \n");
				printf("                                                            \n");
				printf("                                                            \n");
				printf("\n\e[%dA",9);
				break;
				
			default :
				printf("\tChoix incorrect.");
				printf(" Veuillez tapper 1, 2, ou 3");
				while(getchar() != '\n');
				break;
		}
	}
	return 0;
}
