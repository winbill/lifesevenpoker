/**
	@brief Fichier H pour les mains des joueurs.

	Gere les donnees de type MainCarte.

	@author Benjamin, Olivier, James
	@file MainCarte.h
	@version 1.2
	@date 2008/04/23
*/
#ifndef _MainCarte
#define _MainCarte
#include "Carte.h"
#include "PileCarte.h"

/**	@brief Structure representant une main de cartes.
	@param Le champ tabMain est un pointeur sur un pointeur de tableau de Carte.
	@param Le champ nCarte est un entier representant le nombre de pointeurs sur Carte valides dans le tableau, c'est a dire le nombre de cartes contenues dans la main.
	@note La main peut contenir de 0 à 5 cartes.
*/
struct MainCarte
{
  Carte** tabMain;
  int nCarte;
};

enum Main
{
    DEF=0,
    CARTE_HAUTE=1,
    PAIRE=2,
    DOUBLE_PAIRE=3,
    BRELAN=4,
    QUINTE=5,
    FLUSH=6,
    FULL_HOUSE=7,
    CARRE=8,
    QUINTE_FLUSH=9,
    QUINTE_FLUSH_ROYALE=10
};


int compareMain(int tabResultat1[6][2],int tabResultat2[6][2]);

/**	@brief Procedure initialisant une main de cartes.
	@param Prend en entree une variable de type MainCarte correctement cree.
	@return Initialise la variable de type MainCarte.
*/
void initialisationMain(MainCarte & m);


/**	@brief Fonction recuperant le nombre de pointeurs sur Carte contenus dans le tableau de la variable de type MainCarte.
	@param Prend en entree une variable de type MainCarte.
	@return Renvoie la valeur du champ nCarte de la variable de type MainCarte.
*/
int getMainCarteNbCarte(const MainCarte & m);


/** @brief Procedure ajoutant une carte dans la main.
    @param Prend en entree une variable de type MainCarte et une variable de type Carte.
    @return Ajoute une valeur au tableau du champ de MainCarte tabMain.
*/
void ajouteCarte(MainCarte & m, Carte* c);



/** @brief Enumeration representant les differentes mains du jeu de poker.
*/


/** @brief Procedure qui prepare une variable de type MainCarte a la destruction.
    @param Prend en entree une variable de type MainCarte.
    @return Libère le tableau de pointeurs sur carte et met a 0 le champ nCarte.
*/
void MainCarteLibere(MainCarte & m);

/** @brief test si la main presente une couleur (5 cartes de meme couleur)
    @param [in] tab7Carte tableau des cartes (voir codageScoreMain)
    @return 0 si pas de couleur puis 1,2,3,4 pour TREFLE,CARREAU,COEUR,PIQUE
    @author James
*/
int couleurMainCarte(int tab7Carte[8][2]);

/**	@brief Procedure de tri de main.
	@param Prend en entree le tableau des 7 cartes du joueur
	@return modifie le tableau de sorte que les cartes soient tri� dans l'ordre d�croissant
	@author Tristan
*/
void trieTableauRang(int tab7Carte[7][2]);


/** @brief fonction qui permet de savoir si on peut faire une quinte avec la main
    @note appel la fonction suiteMainCarte2
    @param [in,out] tab7Carte renvoie trie DECROISSANT @see codageScoreMain
    @return 0 s'il n'y a pas de suite, 14 suite a l'AS, 13 au roi ..... 5
    @author James Tristan
*/
int suiteMainCarte(int tab7Carte[8][2]);


/** @brief fonction qui permet de compter le nombre d'occurence d'une main
        de carte indiféremment de sa couleur
    @param [in] tab7Carte tableau representatif des 7 cartes
    @see Jeu.h codageScoreMain
    @param [out] tab tableau de taille 15
    @return renvoie les valeurs dans tab
    @note par exemple : si tab[11] = 4 => carré de valet
        si tab[2]=3 et tab[14]=2 brelan aux 2 par les As
    @author James

*/
void nombreOcurenceCarte(const int tab7Carte[10][2],int tab[]);


int quinteFlushMainCarte(int tab7Carte[8][2],int couleur);


/** @brief fonction directement lié a nombreOcurenceCarte, et permet de faire le choix des cartes
    @param [in] tab tableau de taille 15 (0 a 14)
    @param [out] tabResultat renvoit un tableau (le 1er element est le code de
    la forme et les 5 derniers sont les cartes ordonnés pour une comparaison avec
    une autre main du meme code de forme)
    @author James
    @todo fonction qui trie le tableau en fonction des 2 dimensions (voir commentaires de MainCarte.C)

*/
void choixCarteMultiple(int tab7Carte[][2],const int tabO[],int tabResultat[][2]);

void afficheMainCarte(const MainCarte & m,char titre[]);


#endif

