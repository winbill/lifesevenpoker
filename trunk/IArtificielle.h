/**
	@brief Fichier H pour l'intelligence artificielle



	@author James
	@file IArtificielle.h
	@version 0.0
	@date 2008/05/09
*/

#ifndef IArtificielle_H
#define IArtificielle_H

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



Statut calculIA(const Table & t,const Joueur & j,int &relance,int & montant);

Statut calculIAJames(const Table & t,const Joueur & j,int montant,int &relance);

void definieStatut(const Table & t,Statut & s,const Joueur & j,int montant,int & relance);
#endif
