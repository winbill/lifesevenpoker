/**
	@brief Fichier H pour l'affichage en mode texte


	gere l'affichage et le debug en mode texte uniquement

	@author  Tristan, James
	@file AfficheTxt.h
	@version 1.2
	@date 2008/05/05
 */

#ifndef AfficheTxt_H
#define AfficheTxt_H
#include "Joueur.h"
#include "Table.h"
#include "Jeu.h"


void afficheTab2(int tab[][2],int x);

void afficheTab(int tab[],int x);

/**	@brief affiche les informations du joueur j en mode txt (pseudo, argent,mise, statut...)
	@param Joueur j est celui dont on veut afficher les informations
*/
void afficheInfoJoueur(const Joueur & j);


/**	@brief affiche les informations de la table t en mode txt (liste des joueur avec leur num de place, dealer, blind...)
	@param Table t est la table dont on affiche les informations
*/
void afficheInfoTable(const Table & t);




















#endif

