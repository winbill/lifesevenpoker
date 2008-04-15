#include <cstdio>
#include "Carte.h"
#include "MainCarte.h"
#include "PileCarte.h"

/*struct MainCarte
{
  Carte* tabMain[5];
  int nCarte;
}; */

MainCarte* creeMain()
{
	MainCarte* m = new MainCarte;
	initialisationMain(m);
	return m;
}

void initialisationMain(MainCarte & m)
{
	m.tabMain=new Carte* [5];
	m.nCarte=0;
}

Carte* getMainCarteTabMain(const MainCarte & m)
{
	return m.tabMain;
}

int getMainCarteNbCarte(const MainCarte & m)
{
	return m.nCarte;
}

void setMainCarteTabMain(MainCarte & m, const Carte* & tabMain[])
{
	m.tabMain=&tabMain;
}

void setMainCarteNbCarte(MainCarte & m, const int & nCarte)
{
	m.nCarte=nCarte;
}

void setMainCarte(MainCarte & m, const Carte* & tabMain[], const int & nCarte)
{
	m.tabMain=&tabMain;
	m.nCarte=nCarte;
}

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

void MainCarteLibere(MainCarte &m)
{
	delete [] m.tabMain;
	m.nCarte=0;
}

void MainCarteDetruit(MainCarte & m)
{
	delete m;
}
