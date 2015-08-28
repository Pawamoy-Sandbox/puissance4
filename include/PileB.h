/** \file PileB.h
 * \brief Gestion des piles de booléens (header)
 */

#ifndef __PILEB_H
#define __PILEB_H

#include "base.h"

///***************************************///
/// PILE DE BOOLEENS STATIQUE DE TAILLE 6 ///
///***************************************///

/** \struct PileB
 * \relatesalso Nat
 */
typedef struct{
    Nat iTete; /**< hauteur de la pile*/
    unsigned char pile; /**< 8 bits réservés pour la pile*/
} PileB;

/** 
 * \brief construit une pile vide
 * \relatesalso PileB
 * \param p déclaration de la pile à construire
 * \return pile vide
 */
PileB pilenouv(PileB p);

/** 
 * \brief empile un booléen
 * \relatesalso PileB
 * \relatesalso Bool
 * \param p pile
 * \param b booléen
 * \return pile modifiée
 * \pre hauteur(p)<6
 */
PileB empiler(PileB p, Bool b);

/** 
 * \brief retire un booléen du sommet
 * \relatesalso PileB
 * \param p pile
 * \return pile modifiée
 * \pre !vide(p)
 */
PileB desempiler(PileB p);

/** 
 * \brief accède au sommet de la pile
 * \relatesalso PileB
 * \relatesalso Bool
 * \param p pile
 * \return sommet (vrai ou faux)
 * \pre !vide(p)
 */
Bool sommet(PileB p);

/** 
 * \brief indique la hauteur de la pile
 * \relatesalso PileB
 * \relatesalso Nat
 * \param p pile
 * \return hauteur
 */
Nat hauteur(PileB p);

/** 
 * \brief test de vacuité
 * \relatesalso PileB
 * \relatesalso Bool
 * \param p pile
 * \return booléen (vide: vrai, faux sinon)
 */
Bool vide(PileB p);

/** 
 * \brief accède au k-ième élément de la pile
 * \relatesalso PileB
 * \relatesalso Nat
 * \relatesalso Bool
 * \param p pile
 * \param k numéro d'élément dans la pile (1=base)
 * \return booléen (vrai ou faux)
 * \pre !vide(p)
 * \pre k>0 et k<=hauteur(p)
 */
Bool kieme(PileB p, Nat k);

#endif // __PILE_B défini
