#ifndef _MainCarte
#define _MainCarte
#include "Carte.h"
#include "PileCarte.h"

/**	@brief Structure représentant une main de cartes.
	@param Le champ tabMain est un tableau de pointeurs sur Carte.
	@param Le champ nCarte est un entier représentant le nombre de pointeurs sur Carte valides dans le tableau, c'est à dire le nombre de cartes contenues dans la main.
	@note La main peut contenir de 0 à 5 cartes.
*/
struct MainCarte
{
  Carte* tabMain[5];
  int nCarte;
};

/**	@brief Procédure créant une main de cartes.
	@param Prend en entrée une variable de type MainCarte.
	@return Alloue un espace mémoire à la variable de type MainCarte.
*/
void creeMain(MainCarte & m);

/**	@brief Procédure initialisant une main de cartes.
	@param Prend en entrée une variable de type MainCarte correctement crée.
	@return Initialise la variable de type MainCarte.
*/
void initialisationMain(MainCarte & m);

/**	@brief Fonction récupérant le tableau de pointeurs sur Carte de la structure MainCarte.
	@param Prend en entrée une variable de type MainCarte.
	@return Renvoie le premier pointeur sur Carte contenu dans le tableau de pointeurs sur Carte de la variable de type MainCarte.
*/
Carte* getMainCarteTab_main(const MainCarte & m);

/**	@brief Fonction récupérant le nombre de pointeurs sur Carte contenus dans le tableau de la variable de type MainCarte.
	@param Prend en entrée une variable de type MainCarte.
	@return Renvoie la valeur du champ nCarte de la variable de type MainCarte.
*/
int getMainCarteNb_carte(const MainCarte & m);

/**	@brief Procédure modifiant le tableau
*/
void setMainCarteTab_main(MainCarte & m, const char & tabMain[]);
void setMainCarteNb_carte(MainCarte & m, const char & nCarte);
void MainCarte setMainCarte(MainCarte & m, const char & tabMain[], const char & nCarte);
//pré: m est initialisée
//post: modifie certaines valeurs de la structure m

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