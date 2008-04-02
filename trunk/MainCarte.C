#include "MainCarte.h"

struct MainCarte
{
  Carte * tab_main[5];
  int nb_carte;
};

void initialisationMain(MainCarte & m);
{
	m=new Carte[5];
}
	

char getMainCarteTab_main(const MainCarte & m);
char getMainCarteNb_carte(const MainCarte & m);
MainCarte getMainCarte(const MainCarte & m);
//pré: m est initialisée
//post: renvoie certaines valeurs de la structure m

void setMainCarteTab_main(MainCarte & m, const char & tab_main[]);
void setMainCarteNb_carte(MainCarte & m, const char & nb_carte);
void MainCarte setMainCarte(MainCarte & m, const char & tab_main[], const char & nb_carte);
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
