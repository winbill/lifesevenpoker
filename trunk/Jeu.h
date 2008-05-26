/**
	@brief Fichier H qui gere le jeu


	Fichier principal qui sert a initialiser une partie et a la terminer.

	@author James
	@file Jeu.h
	@version 1.2
	@date 2008/04/11
 */


#ifndef Jeu_H
#define Jeu_H

//Librairies Life'Seven Poker
#include "Table.h"
#include "AfficheDynamique.h"


/**	@brief Fonction permettant de comparer deux tableaux de dimensions [6][2].
	@param [in] tabResultat1 Un tableau [6][2].
	@param [in] tabResultat2 Un autre tableau [6][2].
	@return Un booleen qui vaut true si les deux tableaux sont identiques et false sinon.
*/
bool compareTabResultat(const int tabResultat1[6][2],const int tabResultat2[6][2]);


/**	@brief attends l'action du joueur, si c'est l'ia appel la fonction d'ia si c'est humain appel la fonction de scan
	@param aff affichage
	@param 	t table
	@param j joueur concerne
	@param relance
	@param s statut
	@param montant
	@param langue language
	@note
*/
int atendsActionJoueur(SDL_Surface* aff,const Table & t,const Joueur & j,int & relance,Statut & s,int & montant,const char langue[][50]);


/**	@brief Le joueur j de la table t paie la petite blind
	@param t table
	@param j Joueur
	@note
*/
void joueurPetiteBlind(Table & t,Joueur & j);


/**	@brief Le joueur j de la table t paie la grosse blind
	@param t table
	@param j Joueur
	@note
*/
void joueurGrosseBlind(Table & t,Joueur & j);


/**	@brief donne deux carte a chacun des joueurs de la table
	@param [in, out] table une table
*/
void distribuer2CartesJoueursJeu(Table & table);


/**	@brief decouvre n carte sur la table
	@param [in, out] table une table
	@param [in] n un entier qui correspond au nombre de carte a retourner sur  la table
*/
void distribuer1CarteDecouverteJeu(Table & table,int n);


/**	@brief initialise un tableau a 3 dimensions
	@param tabResultat
	@note
*/
void intitialiseTab3d(int tabResultat[10][6][2]);


/**	@brief Determine le vainqueur de la manche
	@param t
	@param tabResultat
	@note
*/
void jeuDetermineVainqueur(const Table & t,int tabResultat[10][6][2]);


/**	@brief trie un tableau a 3 dimensions
	@param tabResultat
	@note
*/
int trieTab3d(int tabResultat[10][6][2]);


/**	@brief determine le vainqueur de la table t
	@param t table
	@param 	tabResultat tableau a 3 dimensions
	@note appel pour chaque joueur (qui joue pas i.e. pas couche) la fonction codageScoreMain
*/
int fonctionGlobaleDeterminationVainqueur(const Table & t,int tabResultat[10][6][2]);


/**	@brief Procedure de tri de main.
	@param Prend en entree le tableau des 7 cartes du joueur
	@return modifie le tableau de sorte que les cartes soient trié dans l'ordre décroissant
	@author Tristan
*/
void trieTableauRang(int tab7Carte[7][2]);


/** @brief fonction PRINCIPALE pour obtenir le code d'une main donc ca force
        pour la comparer aux autres mains,la fonction renvoit dans un tableau un code
        qui permet de pouvoir savoir qu'elle main est plus forte qu'une autre
    @param [in] m la main de carte qui donnera le code
    @param [out] tabResultat contient le code
    @param [in] table du jeu
    @return renvoit 1 si tout c'est bien passé
    @note le code renvoyé est composé de la facon suivante : le premier element du tableau
        correspond au code de la forme (8 Quinte flush,7 Carre,6 Full ...., 1 paire,0 carte haute)
        puis sont classés dans un ordre (fonction du code de la forme) les 5 cartes qui permettent de
        former cette combinaison
    @note la fonction appel toutes les autres fonctions de test de forme
    @author James
*/
int codageScoreMain(const MainCarte &m, int  tabResultat[6][2],const Table & table);


#endif
