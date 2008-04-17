/**
	@brief Fichier H pour les mains des joueurs.

	Gere les donnees de type MainCarte.

	@author Benjamin, Olivier
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
    @return Trie la main selon l'option donnee.
*/
void trieMain(MainCarte & m, char option);

/** @brief Enumeration representant les differentes mains du jeu de poker.
*/
enum Main
{
    DEF=0;
    CARTE_HAUTE=1;
    PAIRE=2;
    DOUBLE_PAIRE=3;
    BRELAN=4;
    QUINTE=5;
    FLUSH=6;
    FULL_HOUSE=7;
    CARRE=8;
    QUINTE_FLUSH=9;
    QUINTE_FLUSH_ROYALE=10;
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
    @param [in] m MainCarte
    @return 0 si pas de couleur puis 1,2,3,4 pour TREFLE,CARREAU,COEUR,PIQUE
    @author James
*/
int couleurMainCarte(const MainCarte & m);

/** @brief fonction qui permet de savoir si on peut faire une suite avce la main
    @note appel récursif utilisé
    @param [in] m MainCarte trie dans l'ordre DECROISSANT si il y a un AS il
            doit etre mis en premiere et derniere position
    @param [in] i utilisé pour l'appel récursif à 0 quand on appel la fonction
    @param [in] j utilisé pour l'appel récursif à 0 quand on appel la fonction
    @return 0 s'il n'y a pas de suite, 14 suite a l'AS, 13 au roi ..... 5
    @author James
*/
int suiteMainCarte(const MainCarte & m,int i,int j);


#endif

