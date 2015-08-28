/** \file base.h
 * \brief Définition des typedefs et define
 */

#ifndef __BASE_H
#define __BASE_H

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define vrai (1==1)
#define faux !vrai
typedef int Nat;
typedef Nat Bool;
#define SIZEOF(x) ((Nat) sizeof(x))
#define MALLOC(t) ((t*)malloc(sizeof(t)))
#define MALLOCN(n,t) ((t*)malloc((n)*sizeof(t)))
#define FREE(t) free(t)

#endif // __BASE_H défini
