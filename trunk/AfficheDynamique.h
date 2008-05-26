/**
	@brief Fichier H pour l'affichage dynamique


	Gere l'affichage dynamique en utilisant le moteur de rendu SDL (Simple Directmedia Layer).

	@author  Tristan James Benjamin
	@file AfficheDynamique.h
	@version 1.3
	@date 2008/05/25
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
#include "AfficheTxt.h"


/**	@brief détermine le ou les vainqueurs et fait l'affichage en fonction
	@param [in,out] affichage
	@param [in] t
*/
void affAffichageVainqueur(SDL_Surface* affichage,Table & t,const char langue[][50],bool afficheCarteGagnant);


/**	@brief
	@param t
	@param tabResultat
	@note
*/
void calulVainqueurTapis(Table & t,int tabResultat[][6][2]);


/**	@brief
	@param source
	@param destination
	@param option
	@return SDL_Rect
	@note
*/
SDL_Rect AffCentrer(SDL_Surface* source, SDL_Surface* destination, int option);


/**	@brief
	@param affichage
	@param tapis
	@note
*/
void AffStartUp(SDL_Surface* affichage,SDL_Surface* tapis);


/**	@brief
	@param affichage
	@param t
	@param langue
	@note
*/
void AffAffichePot(SDL_Surface* affichage,const Table & t,const char langue[][50]);


/**	@brief
	@param affichage
	@param [in] langue
	@return int
	@note
*/
int AffMenu(SDL_Surface* affichage,const char langue[][50]);


/**	@brief
	@param affichage
	@param j
	@param table
	@param joueurJouant
	@param langue
	@note
*/
void AffAfficheJoueur(SDL_Surface* affichage,const Joueur & j,const Table & table,int joueurJouant,const char langue[][50]);


/**	@brief
	@param affichage
	@param t
	@param joueurJouant
	@param langue
	@note
*/
void AffAffichageInfosJoueurs(SDL_Surface* affichage,const Table & t,int joueurJouant,const char langue[][50]);


/**	@brief affiche les cartes des joueurs face cachée (sauf les siennes)
	@param [in,out] affichage
	@param [in] t
	@note utilise AffAfficheCarte
*/
void AffCartesJoueursJeu(SDL_Surface* affichage,const Table & t);


/**	@brief affiche les cartes des joueurs
	@param [in,out] affichage
	@param [in] t
	@param [in] cache si vraie affiche les cartes des autres joueurs face cachee
	@note utilise AffAfficheCarte
*/
void AffCartesJoueursJeu(SDL_Surface* affichage,const Table & t,bool cache);


/**	@brief
	@param
	@param
	@param
	@return
	@note
*/
void AffCarteDecouvertes(const Table & t,SDL_Surface* affichage);


/**	@brief
	@param affichage
	@param evidence
	@param tabResultat
	@note
*/
void AffCarteDecouvertes(const Table & t,SDL_Surface* affichage,bool evidence,int tabResultat[6][2]);


/**	@brief affiche les cartes des joueurs face cachée (sauf les siennes)
	@param [in,out] affichage
	@param [in] t
	@param tabResultat
	@param i
	@note
*/
void AffCartesJoueursJeuFinale(SDL_Surface* affichage,const Table & t,int tabResultat[6][2],int i);


/**	@brief
	@param affichage
	@param j
	@param table
	@param langue
	@note
*/
void AffInfosJoueur(SDL_Surface* affichage,const Joueur &j,const Table & table,const char langue[][50]);


/**	@brief
	@param affichage
	@param relance
	@param dessus
	@param langue
	@note
*/
void AffAfficheBoutonRelance(SDL_Surface* affichage,int relance,bool dessus,const char langue[][50]);


/**	@brief
	@param affichage
	@param relance
	@param s
    @param montant
	@param j
	@param t
	@param langue
	@return int
	@note
*/
int scanActionJoueur(SDL_Surface* affichage,int & relance,Statut & s,int & montant,const Joueur & j,const Table & t,const char langue[][50]);


/**	@brief
	@param t
	@note
*/
void miseDansPot(Table & t);


/**	@brief
	@param t
	@note
*/
void calculGainTapisJoueur(Table & t);


/**	@brief lance la partie de poker
	@param affichage
	@param tapis
	@param langue fichier langue a prendre pour la partie (anglais ou francais)
	@param NOMBRE_JOUEUR_PC nombre de joueur manoeuvre par le PC
	@param argentDepart argent de départ pour chaque joueur
	@return int
	@note
*/
int lancePartie(SDL_Surface* affichage,SDL_Surface* tapis,const char langue[][50],int NOMBRE_JOUEUR_PC,int argentDepart);


#endif
