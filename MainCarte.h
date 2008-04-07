#ifndef _MainCarte
#define _MainCarte
#include "Carte.h"
#include "PileCarte.h"

/**	@brief Structure repr�sentant une main de cartes.
	@param Le champ tabMain est un tableau de pointeurs sur Carte.
	@param Le champ nCarte est un entier repr�sentant le nombre de pointeurs sur Carte valides dans le tableau, c'est � dire le nombre de cartes contenues dans la main.
	@note La main peut contenir de 0 � 5 cartes.
*/
struct MainCarte
{
  Carte* tabMain[5];
  int nCarte;
};

/**	@brief Proc�dure cr�ant une main de cartes.
	@param Prend en entr�e une variable de type MainCarte.
	@return Alloue un espace m�moire � la variable de type MainCarte.
*/
void creeMain(MainCarte & m);

/**	@brief Proc�dure initialisant une main de cartes.
	@param Prend en entr�e une variable de type MainCarte correctement cr�e.
	@return Initialise la variable de type MainCarte.
*/
void initialisationMain(MainCarte & m);

/**	@brief Fonction r�cup�rant le tableau de pointeurs sur Carte de la structure MainCarte.
	@param Prend en entr�e une variable de type MainCarte.
	@return Renvoie le premier pointeur sur Carte contenu dans le tableau de pointeurs sur Carte de la variable de type MainCarte.
*/
Carte* getMainCarteTab_main(const MainCarte & m);

/**	@brief Fonction r�cup�rant le nombre de pointeurs sur Carte contenus dans le tableau de la variable de type MainCarte.
	@param Prend en entr�e une variable de type MainCarte.
	@return Renvoie la valeur du champ nCarte de la variable de type MainCarte.
*/
int getMainCarteNb_carte(const MainCarte & m);

/**	@brief Proc�dure modifiant le tableau
*/
void setMainCarteTab_main(MainCarte & m, const char & tabMain[]);
void setMainCarteNb_carte(MainCarte & m, const char & nCarte);
void MainCarte setMainCarte(MainCarte & m, const char & tabMain[], const char & nCarte);
//pr�: m est initialis�e
//post: modifie certaines valeurs de la structure m

void ajouteCarte(MainCarte & m, const Carte & c);
//pr�: m et c sont initialis�es
//post: c est une carte de m

MainCarte compareMain(const MainCarte & m1, const MainCarte & m2);
//pr�: m1 et m2 sont initialis�es et contiennent exactement 5 cartes(m1.nb_carte ==5 && m2.nb_carte==5)
//post: renvoie la meilleur main. renvoie les 2 mains dans le cas o� les 2 mains ont m�me valeur

void testament(MainCarte & m);
//pr�: m est initialis�e
//post: m est supprim�e

//proc�dure d'ajout et d'insertion d'un �l�ment
void ajouteElementTableauDynamique(TableauDynamique & t,const int & e);
void insereElementTableauDynamique(TableauDynamique & t,const int & e,int i);



//proc�dure d'affectation
void affectation(TableauDynamique & t1,const TableauDynamique & t2);


//proc�dure de tri
void tri(TableauDynamique & t,int(*pcomparaison)(const int &,const int &));



#endif