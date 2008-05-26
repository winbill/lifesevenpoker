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
	@param [in,out] langue fichier de langue
	@param [in] t
	@param [in] afficheCarteGagnant à true si on doit afficher les cartes du gagnant
*/
void affAffichageVainqueur(SDL_Surface* affichage,Table & t,const char langue[][50],bool afficheCarteGagnant);


/**	@brief reparti l'argent entre les joueurs, est appelée si le meilleur joueur a fait un tapis
	@param t table
	@param tabResultat tableau a 3dimension contenant les vainqueurs
	@note aucune
*/
void calulVainqueurTapis(Table & t,int tabResultat[][6][2]);


/**	@brief fonction de centrage
	@param source sur quoi on doit centrer
	@param destinationce qui doit etre centré
	@param option de centrage 0 : centrage h et v  1 : centrage h,2 : centrage v
	@return SDL_Rect contient les coordonnées de centrage
	@note
*/
SDL_Rect AffCentrer(SDL_Surface* source, SDL_Surface* destination, int option);


/**	@brief affiche le logo du debut
	@param affichage
	@param tapis le fond
	@note 
*/
void AffStartUp(SDL_Surface* affichage,SDL_Surface* tapis);


/**	@brief affiche le pot
	@param affichage
	@param t table
	@param langue fichier de langue
	@note
*/
void AffAffichePot(SDL_Surface* affichage,const Table & t,const char langue[][50]);


/**	@brief affiche le menu
	@param affichage
	@param [in] langue fçichier de langue
	@return int renvoit un code qui correspond à ceux sur quoi l'on a clique
	@note
*/
int AffMenu(SDL_Surface* affichage,const char langue[][50]);


/**	@brief affiche les infos des joueurs (non locaux)
	@param affichage
	@param j le joueurZ
	@param table
	@param joueurJouant le joueur a qui c'est au tour de jouer
	@param langue fichier de langue
	@note
*/
void AffAfficheJoueur(SDL_Surface* affichage,const Joueur & j,const Table & table,int joueurJouant,const char langue[][50]);


/**	@brief affiche des infos sur tous les joueurs et les dispose suivant leurs nombre sur la table
	@param affichage
	@param t table
	@param joueurJouant le joueur a qui c'est au tour de jouer
	@param langue fichier de langue
	@note appel AffAfficheJoueur
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


/**	@brief affiche les cartes qui sont disposées sur le tapis
	@param t table
	@param affichage 
	@param evidence
	@note appel la fonction AffCarteDecouvertes(const Table & t,SDL_Surface* affichage,bool evidence,int tabResultat[6][2]);
*/
void AffCarteDecouvertes(const Table & t,SDL_Surface* affichage);


/**	@brief affiche les cartes qui sont disposées sur le tapis, si evidence est à true affiche en évidence celle présente dans le tableau
	@param affichage
	@param evidence à true pour mettre les cartes en évidence
	@param tabResultat contient les cartes à mettre en évidence
	@note
*/
void AffCarteDecouvertes(const Table & t,SDL_Surface* affichage,bool evidence,int tabResultat[6][2]);


/**	@brief affiche les cartes du gagnant en surbrillance
	@param [in,out] affichage
	@param [in] t
	@param tabResultat
	@param i id du gagnant
	@note
*/
void AffCartesJoueursJeuFinale(SDL_Surface* affichage,const Table & t,int tabResultat[6][2],int i);


/**	@brief affichage des infos perso du joueur local
	@param affichage
	@param j
	@param table
	@param langue fichier de langue
	@note
*/
void AffInfosJoueur(SDL_Surface* affichage,const Joueur &j,const Table & table,const char langue[][50]);


/**	@brief gestion de l'affichage du bouton relance
	@param affichage
	@param relance valuer de la relance
	@param dessus est ce que la souris est dessus ?
	@param langue
	@note
*/
void AffAfficheBoutonRelance(SDL_Surface* affichage,int relance,bool dessus,const char langue[][50]);


/**	@brief scan les actions du joueur, affiche des boutons pour récupérer ces actions
	@param affichage 
	@param relance 
	@param s statut
	@param montant mise maximale
	@param j joueur
	@param t table
	@param langue
	@return renvoit un entier au cas ou il clique sur le menu
	@note
*/
int scanActionJoueur(SDL_Surface* affichage,int & relance,Statut & s,int & montant,const Joueur & j,const Table & t,const char langue[][50]);


/**	@brief met l'ensemble des mises dans le pot
	@param t table
	@note
*/
void miseDansPot(Table & t);


/**	@brief calcul combien gagnge au maximum un joueur lorsquil fait un tapis
	@param t table
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
