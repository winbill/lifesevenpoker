#include "Carte.h"

void creerCarte(Carte & c)
{
	c=new Carte;
}
void initialisationCarte(Carte* & c)
{
	c->couleur = INIT_COULEUR;
	c->rang = INIT_RANG;
}

Rang getCarteRang(const Carte* & c)
{
	return c->rang;
}

Couleur getCarteCouleur(const Carte* & c)
{
	return c->couleur;
}

void setCarte(Carte* & c,const Couleur & couleur,const Rang & rang)
{
	c->couleur = couleur;
	c->rang = rang;
}

int compareCarte(const Carte* & c1, const Carte* & c2)
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

void testamentCarte(Carte* &c)
{
	delete c;
}
