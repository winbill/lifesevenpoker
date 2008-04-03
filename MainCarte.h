#ifndef _MainCarte
#define _MainCarte
#include "Carte.h"



struct MainCarte
{
  Carte * tabMain[5];
  char nCarte;
};

void initialisationMain(MainCarte & m);
//pr�: aucune
//post: m est initialis�e

char getMainCarteTab_main(const MainCarte & m);
char getMainCarteNb_carte(const MainCarte & m);
MainCarte getMainCarte(const MainCarte & m);
//pr�: m est initialis�e
//post: renvoie certaines valeurs de la structure m

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