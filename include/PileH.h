/** \file PileH.h
 * \brief Gestion de la pile contenant l'historique des étapes pendant le jeu (header)
 */

#ifndef __PILEH_H
#define __PILEH_H

#include "base.h"

///*************************************************///
/// PILE HISTORIQUE DES AJOUTS, STATIQUE, TAILLE 42 ///
///*************************************************///

/** \struct PileH
 * \relatesalso Nat
 */
typedef struct{
	Nat iPosition; /**< position dans la pile*/
	Nat iHauteurMax; /**< hauteur max atteinte (utile à undo et redo)*/
    Nat pile[42]; /**< pile d'entiers (numéro de colonne du dernier pion ajouté)*/
} PileH;

/** 
 * \brief construit une pile vide
 * \relatesalso PileH
 * \param p déclaration de la pile à construire
 * \return pile vide
 */
PileH hpilenouv(PileH p);

/** 
 * \brief empile un numéro de colonne
 * \relatesalso PileH
 * \relatesalso Nat
 * \param p pile
 * \param c numero de colonne à empiler
 * \return pile modifiée
 * \pre hauteur(p)<42
 */
PileH hempiler(PileH p, Nat c);

/** 
 * \brief retire un numéro de colonne
 * \relatesalso PileH
 * \param p pile
 * \return pile modifiée
 * \pre !vide(p)
 */
PileH hdesempiler(PileH p);

/** 
 * \brief synchronise la hauteur max et la position actuelle
 * \relatesalso PileH
 * \param p pile
 * \return pile p
 */
PileH hsynchauteur(PileH p);

/** 
 * \brief accède au sommet de la pile
 * \relatesalso PileH
 * \relatesalso Nat
 * \param p pile
 * \return numéro de colonne
 * \pre !vide(p)
 */
Nat hsommet(PileH p);

/** 
 * \brief indique la hauteur (position actuelle) de la pile
 * \relatesalso PileH
 * \relatesalso Nat
 * \param p pile
 * \return hauteur
 */
Nat hhauteur(PileH p);

/** 
 * \brief test de vacuité
 * \relatesalso PileH
 * \relatesalso Bool
 * \param p pile
 * \return booléen (vide: vrai, faux sinon)
 */
Bool hvide(PileH p);

#endif // __PILEH_H défini

