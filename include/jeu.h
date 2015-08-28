/** \file jeu.h
 * \brief Fonctions permettant de jouer (header)
 */

#ifndef __JEU_H
#define __JEU_H

#include "base.h"
#include "P4.h"

///******************///
/// FONCTIONS DE JEU ///
///******************///

/** 
 * \brief retire les deux derniers pions placés, celui de l'ordinateur et celui du joueur
 * \relatesalso P4
 * \param jeu grille P4
 * \return grille modifiée
 * \pre nbEtapes(j)>1
 */
P4 undoCP (P4 jeu);

/** 
 * \brief remet en place les pions retirés par undoCP
 * \relatesalso P4
 * \param jeu grille P4
 * \return grille modifiée
 * \pre jeu.ph.iHauteurMax-2 >= jeu.ph.iPosition
 */
P4 redoCP(P4 jeu);

/** 
 * \brief retire le dernier pion placé
 * \relatesalso P4
 * \param jeu grille P4
 * \return grille modifiée
 * \pre nbEtapes(j)>0
 */
P4 undoPP (P4 jeu);

/** 
 * \brief remet en place le pion retiré par undoPP
 * \relatesalso P4
 * \param jeu grille P4
 * \return grille modifiée
 * \pre jeu.ph.iHauteurMax-1 >= jeu.ph.iPosition
 */
P4 redoPP(P4 jeu);

/** 
 * \brief remet en place le pion retiré
 * \relatesalso P4
 * \param jeu grille P4
 * \return grille modifiée
 * \pre jeu.ph.iHauteurMax-1 >= jeu.ph.iPosition
 */
P4 remettrePion(P4 jeu);

/** 
 * \brief calcule le score courant de la grille
 * \relatesalso P4
 * \relatesalso Bool
 * \param jeu grille P4
 * \param b le joueur en cours
 * \return le score
 */
Nat calculScore(P4 jeu, Bool b);

/** 
 * \brief renvoie la colonne offrant le plus de chances de gagner
 * \relatesalso P4
 * \param jeu grille P4
 * \return indice de colonne
 */
Nat calculMeilleureColonne(P4 jeu);

/** 
 * \brief fait jouer l'ordinateur
 * \relatesalso P4
 * \param jeu grille P4
 * \return grille modifiée
 */
P4 aSonTour(P4 jeu);

/** 
 * \brief indique si la partie est terminée
 * \relatesalso P4
 * \param jeu grille P4
 * \return vrai si oui, faux sinon
 */
Bool partieTerminee(P4 jeu);

/** 
 * \brief indique si la grille est remplie
 * \relatesalso P4
 * \param jeu grille P4
 * \return vrai si oui, faux sinon
 */
Bool plusDePlace(P4 jeu);

#endif // __JEU_H défini
