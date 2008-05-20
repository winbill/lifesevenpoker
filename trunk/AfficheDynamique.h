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

void AffAfficheBoutonRelance(SDL_Surface* affichage,int relance,bool dessus);

void calulVainqueurTapis(Table & t,int tabResultat[][6][2]);

/**	@brief
	@param
	@param
*/

/**	@brief affiche les cartes des joueurs
	@param [in,out] affichage
	@param [in] t
	@param [in] cache si vraie affiche les cartes des autres joueurs face cachee
	@note utilise AffAfficheCarte
*/
void AffCartesJoueursJeu(SDL_Surface* affichage,const Table & t,bool cache);

/**	@brief affiche les cartes des joueurs face cachée (sauf les siennes)
	@param [in,out] affichage
	@param [in] t
	@note utilise AffAfficheCarte
*/
void AffCartesJoueursJeu(SDL_Surface* affichage,const Table & t);

/**	@brief détermine le ou les vainqueurs et fait l'affichage en fonction
	@param [in,out] affichage
	@param [in] t
*/
void affAffichageVainqueur(SDL_Surface* affichage,Table & t);

/**	@brief affiche les cartes des joueurs face cachée (sauf les siennes)
	@param [in,out] affichage
	@param [in] t
*/
void AffCartesJoueursJeuFinale(SDL_Surface* affichage,const Table & t,int tabResultat[6][2],int i);


int scanActionJoueur(SDL_Surface* affichage,int & relance,Statut & s,int & montant,const Joueur & j,const Table & t,const char langue[][50]);

void AffInfosJoueur(SDL_Surface* affichage,const Joueur &j,const Table & table,const char langue[][50]);


int AffMenu(SDL_Surface* affichage,Table* t,int joueurJouant,SDL_Surface* sortie);

int AffMenu(SDL_Surface* affichage,const char langue[][50]);





void AffStartUp(SDL_Surface* affichage,SDL_Surface* tapis);


SDL_Rect AffCentrer(SDL_Surface* source, SDL_Surface* destination, int option);



int lancePartie(SDL_Surface* affichage,SDL_Surface* tapis,const char langue[][50]);

void AffAfficheCredits(SDL_Surface* affichage);


void AffCarteDecouvertes(const Table & t,SDL_Surface* affichage);


void AffCarteDecouvertes(const Table & t,SDL_Surface* affichage,bool evidence,int tabResultat[6][2]);

void AffAffichePot(SDL_Surface* affichage,const Table & t);


void miseDansPot(Table & t);



void AffAfficheJoueur(SDL_Surface* affichage,const Joueur & j,const Table & table,int joueurJouant);

void AffAffichageInfosJoueurs(SDL_Surface* affichage,const Table & t,int joueurJouant);















#endif
