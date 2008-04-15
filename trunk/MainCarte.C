#include <cstdio>
#include "Carte.h"
#include "MainCarte.h"
#include "PileCarte.h"

/*struct MainCarte
{
  Carte* tabMain[5];
  int nCarte;
}; */

void initialisationMain(MainCarte & m)
{
	m.tabMain=new Carte* [7];
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

void setMainCarte(MainCarte & m, const Carte* & tabMain, int nCarte)
{
    int i;
	for(i=0;i<nCarte;i++)
	{
	    m.tabMain[i]=(tabMain+i*sizeof(Carte));
	}
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

void trieMain(MainCarte & m, char option)
{
    if(option="couleur")
    {
        int ctab[4]={0,0,0,0}; //Tableau où sont stockés les nombres de carte pour chaque couleur.
        int i;
        for(i=0;i<7;i++)
        {
            switch(m.tabMain[i]->couleur)
            {
                case 1 :
                    ctab[0]=ctab[0]+1;
                    break;
                case 2 :
                    ctab[1]=ctab[1]+1;
                    break;
                case 3 :
                    ctab[2]=ctab[2]+1;
                    break;
                case 4 :
                    ctab[3]=ctab[3]+1;
                    break;
            }
        }
        int domCoul; //Numéro de la couleur ayant 5 carte ou plus si elle éxiste.
        for(i=1;i<=4;i++)
        {
            ctab[i]>=5 ? domCoul=i : domCoul=0;
        }
        //Début du tri selon la couleur dominante.

        //ALGO TENDU DU SLIP A FINIR
        //Note : il me semblait qu'Olivier avait fait un algo là dessus; A voir avec lui, il l'a pas mis en ligne apparement.
    }
    if(option="rang")
    {
        int rtab[13]={0,0,0,0,0,0,0,0,0,0,0,0,0};

        //ALGO TENDU DU SLIP A FINIR

    }
}

Main identifieMainCarte(const MainCarte & m)
{
    trieMain(m,couleur);
    if(
    trieMain(m,rang);
    if(

    //ALGO TENDU DU SLIP A FINIR
}
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

void MainCarteLibere(MainCarte & m)
{
    delete [] m.tabMain;
	m.nCarte=0;
}


