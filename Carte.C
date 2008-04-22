/**
	@brief Fichier C pour les cartes.

	Gere les donnees de type Carte.

	@author Benjamin, Olivier
	@file Carte.h
	@version 1.3
	@date 2008/04/19
*/

#include "Carte.h"


void initialisationCarte(Carte & c)
{
	c.couleur = INIT_COULEUR;
	c.rang = INIT_RANG;
}

Rang getCarteRang(const Carte & c)
{
	return c.rang;
}

Couleur getCarteCouleur(const Carte & c)
{
	return c.couleur;
}

void setCarte(Carte & c,const Couleur & couleur,const Rang & rang)
{
	c.couleur = couleur;
	c.rang = rang;
}

int compareCarte(const Carte & c1, const Carte & c2)
{
	Rang rang1=getCarteRang(c1);
	Rang rang2=getCarteRang(c2);

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
		return 0;
	}
}

void getCarteNomFichier(const Carte & c,char[] sortieNomFichier)
{

    //strcpy (char *dest, const char *src);
    strcpy(sortieNomFichier,c.nomFichier);//copie le tableau c dans le tableau sortieNomFichier

}

