/**
	@brief Fichier H pour l'affichage dynamique


	Gere l'affichage dynamique en utilisant le moteur de rendu SDL (Simple Directmedia Layer).

	@author  James Benjamin
	@file AfficheDynamique.h
	@version 1.2
	@date 2008/04/21
 */

#ifndef AfficheDynamique_H
#define AfficheDynamique_H

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

#include "Joueur.h"
#include "Table.h"
#include "AfficheTxt.h"
#include "AfficheSdl.h"
#include "Jeu.h"
#include "IArtificielle.h"

/** @brief Type cree pour manipuler les chemins de fichier.

*/
typedef char path[100];
void AffCartesJoueursJeu(SDL_Surface* affichage,const Table & t,bool cache);
void AffCartesJoueursJeu(SDL_Surface* affichage,const Table & t);

void affAffichageVainqueur(SDL_Surface* affichage,const Table & t);


int scanActionJoueur(SDL_Surface* affichage,int & relance,Statut & s,int & montant);

int AffMenu(SDL_Surface* affichage,Table* t,int joueurJouant,SDL_Surface* sortie);
int AffMenu(SDL_Surface* affichage);



void AffStartUp(SDL_Surface* affichage,SDL_Surface* tapis);


SDL_Rect AffCentrer(SDL_Surface* source, SDL_Surface* destination, int option);



int lancePartie(SDL_Surface* affichage,SDL_Surface* tapis);

void AffAfficheCredits(SDL_Surface* affichage);


void AffCarteDecouvertes(const Table & t,SDL_Surface* affichage);
void AffCarteDecouvertes(const Table & t,SDL_Surface* affichage,bool evidence,int tabResultat[6][2]);





void AffAfficheJoueur(SDL_Surface* affichage,const Joueur & j,const Table & table,int joueurJouant);

void AffAffichageInfosJoueurs(SDL_Surface* affichage,const Table & t,int joueurJouant);















#endif
