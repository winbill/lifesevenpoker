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


void ajouteCarte(MainCarte & m, const Carte & c);
//pré: m et c sont initialisées
//post: c est une carte de m

MainCarte compareMain(const MainCarte & m1, const MainCarte & m2);
//pré: m1 et m2 sont initialisées et contiennent exactement 5 cartes(m1.nb_carte ==5 && m2.nb_carte==5)
//post: renvoie la meilleur main. renvoie les 2 mains dans le cas où les 2 mains ont même valeur

void testament(MainCarte & m);
//pré: m est initialisée
//post: m est supprimée

//procédure d'ajout et d'insertion d'un élément
void ajouteElementTableauDynamique(TableauDynamique & t,const int & e);
void insereElementTableauDynamique(TableauDynamique & t,const int & e,int i);



//procédure d'affectation
void affectation(TableauDynamique & t1,const TableauDynamique & t2);


//procédure de tri
void tri(TableauDynamique & t,int(*pcomparaison)(const int &,const int &));



#endif