/**
	@brief Fichier H pour les mains des joueurs.

	Gere les donnees de type MainCarte.

	@author Benjamin, Olivier
	@file MainCarte.h
	@version 1.0
	@date 2008/04/14
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
  Carte* tabMain[5];
  int nCarte;
};

/**	@brief Procedure creant une main de cartes.
	@param Prend en entree une variable de type MainCarte.
	@return Alloue un espace memoire a la variable de type MainCarte.
*/
void creeMain(MainCarte & m);

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

/**	@brief Procedure modifiant le tableau de pointeur sur Carte de la structure MainCarte.
	@param Prend en entree une variable de type MainCarte et une variable de type tableau de pointeur sur Carte.
	@return La structure de type MainCarte a son champ tabMain remplace par l'adresse du tableau de pointeur sur Carte.
*/
void setMainCarteTabMain(MainCarte & m, const Carte* & tabMain[]);

/**	@brief Procedure modifiant la valeur de du nombre de Carte dans la structure MainCarte.
	@param Prend en entree une variable de type MainCarte et une variable de type int.
	@return La structure de type MainCarte a son champ nCarte remplace par la valeur de l'int.
*/
void setMainCarteNbCarte(MainCarte & m, const int & nCarte);

/**	@brief Procedure modifiant toutes les valeurs de la structure MainCarte.
	@param Prend en entree une variable de type MainCarte, une variable de type tableau de pointeur sur Carte et une variable de type int.
	@return Remplace les champs de la structure de type MainCarte par les valeurs des deux autres parametres.
*/
void MainCarte setMainCarte(MainCarte & m, const Carte* & tabMain[], const int & nCarte);

/** @brief Procedure ajoutant une carte dans la main.
    @param Prend en entree une variable de type MainCarte et une variable de type Carte.
    @return Ajoute une valeur au tableau du champ de MainCarte tabMain.
*/
void ajouteCarte(MainCarte & m, const Carte & c);

/** @brief Procedure d'insertion d'une carte dans une main.
    @param Prend en entree une variable de type Carte et une variable de type MainCarte.
    @return La carte est inseree correctement dans la main.
*/
void insereCarte(MainCarte & m, const Carte & c, int position);

/** @brief Fonction de comparaison de deux variables de type MainCarte.
    @param Prend en entree deux variables de type MainCarte.
    @return Renvoie la meilleure main.
*/
MainCarte compareMain(const MainCarte & m1, const MainCarte & m2);

/** @brief Procedure d'affectation de mains.
    @param Prend en entree deux variables de type MainCarte.
    @return Affecte la deuxieme main a la premiere.
*/
void affectation(MainCarte & m1, const MainCarte & m2);

/** @brief Procedure de tri de main.
    @param Prend en entree une variable de type MainCarte et une option de tri.
    @return Trie la main selon l'option donnee.
*/
void tri(MainCarte & m, int option);

/** @brief Procedure qui prepare une variable de type MainCarte a la destruction.
    @param Prend en entree une variable de type MainCarte.
    @return La variable est prete a etre detruite.
*/
void testament(MainCarte & m);

#endif
