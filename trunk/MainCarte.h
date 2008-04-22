/**
	@brief Fichier H pour les mains des joueurs.

	Gere les donnees de type MainCarte.

	@author Benjamin, Olivier, James
	@file MainCarte.h
	@version 1.2
	@date 2008/04/15
*/
#ifndef _MainCarte
#define _MainCarte
#include "Carte.h"
#include "PileCarte.h"

/**	@brief Structure representant une main de cartes.
	@param Le champ tabMain est un tableau de pointeurs sur Carte.
	@param Le champ nCarte est un entier representant le nombre de pointeurs sur Carte valides dans le tableau, c'est a dire le nombre de cartes contenues dans la main.
	@note La main peut contenir de 0 à 5 cartes.
*/
struct MainCarte
{
  Carte* tabMain; // 2 cartes dans la main + 5 sur la table = 7 cartes au maximum.
  int nCarte;
};

/**	@brief Procedure initialisant une main de cartes.
	@param Prend en entree une variable de type MainCarte correctement cree.
	@return Initialise la variable de type MainCarte.
*/
void initialisationMain(MainCarte & m);

/**	@brief Fonction recuperant le tableau de pointeurs sur Carte de la structure MainCarte.
	@param Prend en entree une variable de type MainCarte.
	@return Renvoie le premier pointeur sur Carte contenu dans le tableau de pointeurs sur Carte de la variable de type MainCarte.
*/
Carte* getMainCarteTabMain(const MainCarte & m);

/**	@brief Fonction recuperant le nombre de pointeurs sur Carte contenus dans le tableau de la variable de type MainCarte.
	@param Prend en entree une variable de type MainCarte.
	@return Renvoie la valeur du champ nCarte de la variable de type MainCarte.
*/
int getMainCarteNbCarte(const MainCarte & m);

/**	@brief Procedure modifiant toutes les valeurs de la structure MainCarte.
	@param Prend en entree une variable de type MainCarte, une variable de type tableau de pointeur sur Carte et une variable de type int.
	@return Remplace les champs de la structure de type MainCarte par les valeurs des deux autres parametres.
*/
void setMainCarte(MainCarte & m, const Carte* & tabMain, const int & nCarte);

/** @brief Procedure ajoutant une carte dans la main.
    @param Prend en entree une variable de type MainCarte et une variable de type Carte.
    @return Ajoute une valeur au tableau du champ de MainCarte tabMain.
*/
void ajouteCarte(MainCarte & m, const Carte* & c);

/** @brief Procedure de tri de main.
    @param Prend en entree une variable de type MainCarte et une option de tri.
    @note Differentes options :
            - couleur : trie par couleur sans ordre de couleur precis.
            - rang : trie par rang décroissant et place l'as en carte haute.
            - rc : trie par couleur puis par rang pour chacune des couleurs.
    @return Trie la main selon l'option donnee.

*/
void trieMain(MainCarte & m, char option);

/** @brief Enumeration representant les differentes mains du jeu de poker.
*/
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

/** @brief Procedure d'identification de main.
    @param Prend en entree une variable de type MainCarte.
    @return Renvoie le type de la meilleur combinaison possible avec cette main.
*/
Main identifieMainCarte(const MainCarte & m);

/** @brief Fonction de comparaison de deux variables de type MainCarte.
    @param Prend en entree deux variables de type MainCarte.
    @return Renvoie la meilleure main.
*/
MainCarte compareMain(const MainCarte & m1, const MainCarte & m2);

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
int couleurMainCarte(const int & tab7Carte[8][2]);

/** @brief fonction qui permet de savoir si on peut faire une quinte avec la main
    @note appel récursif utilisé
    @note est appelé par suiteMainCarte
    @param [in] m MainCarte trie dans l'ordre DECROISSANT si il y a un AS il
            doit etre mis en premiere et derniere position
    @param [in] i utilisé pour l'appel récursif à 0 quand on appel la fonction
    @param [in] j utilisé pour l'appel récursif à 0 quand on appel la fonction
    @param [in] l nombre de carte dans le tableau
    @return 0 s'il n'y a pas de suite, 14 suite a l'AS, 13 au roi ..... 5
    @author James
*/
int suiteMainCarte2(const int & tab7Carte[8][2],int i,int j,int l);


/** @brief fonction qui permet de savoir si on peut faire une quinte avec la main
    @note appel la fonction suiteMainCarte2
    @param [in,out] tab7Carte renvoyé trie DECROISSANT @see codageScoreMain
    @return 0 s'il n'y a pas de suite, 14 suite a l'AS, 13 au roi ..... 5
    @author James
    @todo il faut faire une fonction qui trie le tableau en fonction du rang (DECROISSANT) (tableau a 2d)
*/
int suiteMainCarte(int & tab7Carte[8][2]);

/** @brief fonction qui identifie une Quinte flush
    @param [in] couleur couleur de la quinte flush s'il y en a une
    @return 0 s'il n'y a pas de quinte flush, 14 quinte flush a l'AS, 13 au roi ..... 5
    @todo il faut faire cette fonction, on peut imiter la fonction suiteMainCarte (a voir)
*/
int quinteFlushMainCarte(int & tab7Carte[10][2],int couleur,int quinte);


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
void nombreOcurenceCarte(const int & tab7Carte[10][2],int & tab[]);


/** @brief fonction directement lié a nombreOcurenceCarte, et permet de faire le choix des cartes
    @param [in] tab tableau de taille 15 (0 a 14)
    @param [out] tabResultat renvoit un tableau (le 1er element est le code de
    la forme et les 5 derniers sont les cartes ordonnés pour une comparaison avec
    une autre main du meme code de forme)
    @author James
    @todo fonction qui trie le tableau en fonction des 2 dimensions (voir commentaires de MainCarte.C)

*/
void choixCarteMultiple(const int & tab[],int & tabResultat[6]);




#endif

