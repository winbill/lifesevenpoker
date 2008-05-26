/**
	@brief Fichier H pour l'affichage en mode texte


	Gere l'affichage et le debug en mode texte uniquement.

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


/**	@brief Procedure d'affichage des gains des tapis des joueurs de la table.
	@param [in] t Une table.
	@param [in] titre Un tableau de caracteres contenant un titre pour l'affichage.
	@note Utilisee pour le Debug uniquement.
*/
void afficheTxtGainTapis(const Table & t,const char* titre);


/**	@brief Procedure qui affiche le contenu d'un nombre donne de colonnes d'un tableau a deux dimensions.
	@param [in] tab Le tableau en question.
	@param [in] x Le nombres de colonnes a afficher.
	@note Utilisee pour le Debug uniquement.
*/
void afficheTab2(int tab[][2],int x);


/**	@brief Procedure qui affiche le contenu d'un nombre donne de colonnes d'un tableau à trois dimensions.
	@param [in] tab Le tableau en question.
	@param [in] x Le nombres de colonnes a afficher.
	@note Utilisee pour le Debug uniquement.
*/
void afficheTab3(int tab[][6][2],int x);


/**	@brief Procedure qui affiche le contenu d'un nombre donne de colonnes d'un tableau à une dimension.
	@param [in] tab Le tableau en question.
	@param [in] x Le nombres de colonnes a afficher.
	@note Utilisee pour le Debug uniquement.
*/
void afficheTab(int tab[],int x);


/**	@brief Procedure qui affiche les informations d'un joueur en mode texte (pseudo, argent, mise, statut, etc...).
	@param [in] j Un joueur.
	@note Utilisee pour le debug uniquement.
*/
void afficheInfoJoueur(const Joueur & j);


/**	@brief Procedure qui affiche les informations d'une table en mode texte (liste des joueur avec leur numero de place, dealer, blind...).
	@param [in] t Une table.
	@note Utilisee pour le debug uniquement.
*/
void afficheInfoTable(const Table & t);


/**	@brief Procedure qui affiche le contenu d'une main de cartes en mode texte.
	@param [in] m La main qui contient les cartes.
	@param [in] titre Un tableau de caracteres contenant un titre pour l'affichage.
	@note Utilisee pour le debug uniquement.
*/
void afficheMainCarte(const MainCarte & m,char titre[]);


#endif

