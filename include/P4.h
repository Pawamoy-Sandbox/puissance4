/** \file P4.h
 * \brief Gestion de la grille de jeu (header)
 */

#ifndef __P4_H
#define __P4_H

#include "PileB.h"
#include "PileH.h"

///***************************///
/// GRILLE DE JEU PUISSANCE 4 ///
///***************************///

/** \struct P4
 * \relatesalso PileB
 * \relatesalso PileH
 */
typedef struct{
	PileB tPile[7]; /**< tableau de 7 piles de booléens*/
	PileH ph; /**< pile contenant l'historique des étapes*/
}P4;

/** 
 * \brief construit une grille vide
 * \relatesalso P4
 * \param jeu déclaration de la grille P4 à construire
 * \return grille vide
 */
P4 jeunouv(P4 jeu);

/** 
 * \brief ajoute un pion dans une colonne donnée
 * \relatesalso P4
 * \relatesalso Nat
 * \param jeu grille P4
 * \param c numéro de colonne
 * \return grille modifiée
 */
P4 ajouterPion(P4 jeu, Nat c);

/** 
 * \brief retire le dernier pion placé
 * \relatesalso P4
 * \param jeu grille P4
 * \return grille modifiée
 */
P4 retirerPion(P4 jeu);

/** 
 * \brief indique à qui est le tour (vrai:joueur)
 * \relatesalso P4
 * \relatesalso Bool
 * \param jeu grille P4
 * \return booléen
 */
Bool aquiletour(P4 jeu);

/** 
 * \brief récupère l'indice de colonne du dernier pion placé
 * \relatesalso P4
 * \relatesalso Nat
 * \param jeu grille P4
 * \return indice de colonne
 * \pre nbEtapes(jeu)>0
 */
Nat colonne(P4 jeu);

/** 
 * \brief indique le nombre actuel de pions dans la grille
 * \relatesalso P4
 * \relatesalso Nat
 * \param jeu grille P4
 * \return nombre de pions dans la grille
 */
Nat nbEtapes(P4 jeu);

/** 
 * \brief nombre max de pions alignés horizontalement incluant le pion au sommet de la colonne donnée
 * \relatesalso P4
 * \relatesalso Nat
 * \param jeu grille P4
 * \param c indice de colonne
 * \return nombre de pions alignés
 */
Nat alignHoriz(P4 jeu, Nat c);

/** 
 * \brief nombre max de pions alignés verticalement incluant le pion au sommet de la colonne donnée
 * \relatesalso P4
 * \relatesalso Nat
 * \param jeu grille P4
 * \param c indice de colonne
 * \return nombre de pions alignés
 */
Nat alignVert(P4 jeu, Nat c);

/** 
 * \brief nombre max de pions alignés sur la diagonale gauche incluant le pion au sommet de la colonne donnée
 * \relatesalso P4
 * \relatesalso Nat
 * \param jeu grille P4
 * \param c indice de colonne
 * \return nombre de pions alignés
 */
Nat alignDiagGauche(P4 jeu, Nat c);

/** 
 * \brief nombre max de pions alignés sur la diagonale droite incluant le pion au sommet de la colonne donnée
 * \relatesalso P4
 * \relatesalso Nat
 * \param jeu grille P4
 * \param c indice de colonne
 * \return nombre de pions alignés
 */
Nat alignDiagDroite(P4 jeu, Nat c);

#endif // __P4_H défini

