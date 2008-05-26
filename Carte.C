/**
	@brief Fichier C pour les cartes.

	Gere les donnees de type Carte.

	@author Benjamin, Olivier
	@file Carte.h
	@version 1.4
	@date 2008/05/26
*/

//Librairies Standard
#include <cstring>

//Librairies Life'Seven Poker
#include "Carte.h"


void initialisationCarte(Carte & c)
{
	c.couleur = 0;
	c.rang = 0;
}

int getCarteRang(const Carte & c)
{
	return c.rang;
}

int getCarteCouleur(const Carte & c)
{
	return c.couleur;
}

void setCarte(Carte & c,const int & couleur,const int & rang)
{
	c.couleur = couleur;
	c.rang = rang;
}

int compareCarte(const Carte & c1, const Carte & c2)
{
	int rang1=getCarteRang(c1);
	int rang2=getCarteRang(c2);

	if(rang1<rang2)
	{
		return 1;
	}
	else if(rang1>rang2)
	{
		return -1;
	}
	else
	{
	    if(getCarteCouleur(c1) == getCarteCouleur(c2))
	    {
	        return 2;
	    }
		return 0;
	}
}

void getCarteNomFichier(const Carte & c, char* sortieNomFichier)
{
    //copie le tableau c dans le tableau sortieNomFichier
    strcpy(sortieNomFichier,c.nomFichier);
}

