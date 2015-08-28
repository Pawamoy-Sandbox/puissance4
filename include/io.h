/** \file io.h
 * \brief Gestion des entrées/sorties : clavier/écran (header)
 */

#ifndef __IO_H
#define __IO_H

#include "base.h"
#include "P4.h"
#include "jeu.h"

///**********************************///
/// AFFICHAGE DU JEU EN MODE CONSOLE ///
///**********************************///

/** 
 * \brief effacement d'une grille
 */
void efface_jeu();

/** 
 * \brief effacement de l'écran du menu
 */
void efface_ecran();

/** 
 * \brief affiche un trait de la grille de jeu
 */
void affiche_trait();

/** 
 * \brief affiche une ligne de la grille de jeu
 * \relatesalso P4
 * \param jeu la grille
 * \param l le numéro de ligne
 */
void affiche_ligne(P4 jeu, Nat l);

/** 
 * \brief affiche une grille de jeu complète
 * \relatesalso P4
 * \param jeu la grille
 */
void affiche_jeu(P4 jeu);

/** 
 * \brief démarre la partie
 * \relatesalso P4
 * \param jeu la grille dans laquelle jouer
 */
void debut_jeu(P4 jeu);

/** 
 * \brief mode un joueur
 * \relatesalso P4
 * \param jeu (pointeur vers) la grille de jeu
 */
Nat unJoueur(P4* jeu);

/** 
 * \brief mode deux joueur
 * \relatesalso P4
 * \param jeu (pointeur vers) la grille de jeu
 */
Nat deuxJoueurs(P4* jeu);

#endif // __IO_H défini
