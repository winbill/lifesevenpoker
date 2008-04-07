#include <cstdio>
#include "Carte.h"
#include "MainCarte.h"
#include "PileCarte.h"

/*struct MainCarte
{
  Carte* tabMain[5];
  int nCarte;
}; */

void creeMain(MainCarte & m)
{
	m.tabMain=new Carte* [5];
	m.nCarte=0;
}

void initMain(MainCarte & m)
{
	m.tabMain=NULL;
	m.nCarte=0;
}

Carte* getMainCarteTab_main(const MainCarte & m)
{
	return m.tabMain;
}
int getMainCarteNb_carte(const MainCarte & m)
{
	return m.nCarte;
}
//pré: m est initialisée
//post: renvoie certaines valeurs de la structure m

void setMainCarteTab_main(MainCarte & m, const Carte* & tabMain[])
{
	m.tabMain=&tabMain;
}
void setMainCarteNb_carte(MainCarte & m, const int & nCarte)
{
	m.nCarte=nCarte;
}
void setMainCarte(MainCarte & m, const Carte* & tabMain[], const int & nCarte)
{
	m.tabMain=&tabMain;
	m.nCarte=nCarte;
}
//pré: m est initialisée
//post: modifie certaines valeurs de la structure m

void ajouteCarte(MainCarte & m, const Carte* & c)
{
	if(nCarte<5)
	{
		Carte* temp[]=new Carte* [m.nCarte+1];
		int i;
		for(i=0;i<m.nCarte;i++)
		{
			temp[i]=m.tabMain[i];
		}
		temp[i+1]=c;
	}
	else
	{
		printf("Main pleine \n");
	}
}
//pré: m et c sont initialisées
//post: c est une carte de m

Main identifierMainCarte(const MainCarte & m)
{
	
MainCarte compareMain(const MainCarte & m1, const MainCarte & m2)
{
	Main main1=identifierMainCarte(m1);
	Main main2=identifierMainCarte(m2);
	
	if(main1>main2)
		return m1;
	else if(main1<main2)
		return m2;
	else 
		return 0;
}
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
