/**
	@brief Fichier H pour l'affichage en mode texte


	gere l'affichage et le debug en mode texte uniquement

	@author  Tristan, James
	@file AfficheTxt.h
	@version 1.3
	@date 2008/05/26
 */

#ifndef AfficheTxt_H
#define AfficheTxt_H

//Librairies Life'Seven Poker
#include "Joueur.h"
#include "Table.h"
#include "Jeu.h"


/**	@brief
	@param t
	@param titre
	@note
*/
void afficheTxtGainTapis(const Table & t,const char* titre);


/**	@brief
	@param tab
	@note
*/
void afficheTab2(int tab[][2],int x);


/**	@brief
	@param tab
	@param x
	@note
*/

void afficheTab3(int tab[][6][2],int x);


/**	@brief
	@param tab
	@param x
	@note
*/
void afficheTab(int tab[],int x);


/**	@brief affiche les informations du joueur j en mode txt (pseudo, argent,mise, statut...)
	@param j Joueur j est celui dont on veut afficher les informations
*/
void afficheInfoJoueur(const Joueur & j);


/**	@brief affiche les informations de la table t en mode txt (liste des joueur avec leur num de place, dealer, blind...)
	@param Table t est la table dont on affiche les informations
*/
void afficheInfoTable(const Table & t);


/**	@brief
	@param m
	@param titre
	@note
*/
void afficheMainCarte(const MainCarte & m,char titre[]);


#endif

