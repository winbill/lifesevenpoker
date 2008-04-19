/**
	@brief Fichier H pour l'affichage en mode texte


	gere l'affichage et le debug en mode texte uniquement

	@author  James
	@file AfficheTxt.h
	@version 1.1
	@date 2008/04/11
 */

#ifndef AfficheTxt_H
#define AfficheTxt_H
#include "Joueur.h"
/*
	int argent;
	char pseudo[15];
	int idJoueur;
	int noPlace;
	Statut statut;
	MainCarte* mainJoueur;

	*/

/**	@brief affiche les informations personnel dun joueur
	@param [in] joueur
	@note argent, pseudo,idJoueur,noPlace,status,cartes,
*/
void afficheTInfosPersoJoueur(const Joueur & joueur);


/**	@brief affiche les informations publique dun joueurs
	@param [in] joueur
	@note argent, pseudo,idJoueur,noPlace,status
	@note informations non personnel
*/
void afficheTInfosPubliqueJoueur(const Joueur & joueur);

/**	@brief affiche la main dun joueur
	@param [in] joueur
*/
void afficheTMainJoueur(const Joueur & joueur);

/**	@brief affiche successivement les cartes d'une main
	@param [in] mainCarte
*/
void afficheTMainCarte(const MainCarte & mainCarte);

/**	@brief affiche une carte
	@param [in] carte
*/
void afficheTCarte(const Carte & carte);

/**	@brief affiche un texte
	@param [in] char chaine de caractere
*/
void afficheTText(const char & tab[]);





















#endif

