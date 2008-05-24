/**
	@brief Fichier H pour l'intelligence artificielle



	Gere les actions et reactions des joueurs de type 'ordinateur'.

	@author  James Benjamin
	@file IArtificielle.h
	@version 1.3
	@date 2008/05/23
 */

#ifndef IArtificielle_H
#define IArtificielle_H

//Librairies Life'Seven Poker
#include "Joueur.h"
#include "Table.h"

//Librairies Standard.
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <cassert>

//Librairies SDL.
#include <SDL/SDL.h>
#include "SDL/SDL_image.h" //Gestion des images.
#include "SDL/SDL_ttf.h" //Gestion des polices True Type Fonts.
#include <SDL/SDL_rotozoom.h>
//#include "SDL/SDL_mixer.h" //Gestion du multi channeling audio.


/**	@brief Calcule ce que va faire le joueur de type ordinateur a son prochain coup.
	@param [in] t Une table.
	@param [in] j Un joueur.
	@param [in] montant Le montant de la mise actuel.
	@param [in,out] relance La valeur de relance.
	@return Une valeur de type Statut.
	@author James
*/
Statut calculIA(const Table & t,const Joueur & j,int montant,int &relance);

/** @brief Definie le statut du joueur de type ordinateur selon ce qui aura ete calcule au prealable par calculIA.
    @param [in] t Une table.
    @param [in,out] s Un statut.
	@param [in] j Un joueur.
	@param [in] montant Le montant de la mise actuel.
	@param [in,out] relance La valeur de relance.
	@author James
**/
void definieStatut(const Table & t,Statut & s,const Joueur & j,int montant,int & relance);

/** @brief Identifie la meilleure main qu'a un joueur de type ordinateur donne quelque soit la phase de la partie dans laquelle on se trouve.
    @param [in] mainJoueur La main du joueur concerne.
    @param [in] cartesDecouvertes La main contenant les cartes deja decouvertes si il y en a.
    @return Une valeur de type Main.
    @author Benjamin
**/
Main determineMeilleureMainIA(const MainCarte & mainJoueur,const MainCarte & cartesDecouvertes);

#endif
