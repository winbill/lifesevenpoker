#include "Carte.h"
#include "PileCarte.h"
#include "Table.h"
#include "assert.h"
#include "Joueur.h"






void initTable (Table& table)
{
	table.nJoueur = 0;
	table.joueur = new Joueur* [10];
	setMaxJoueur (table, 0);
	table.carteDecouverte=new Carte* [5];
}


void setNJoueur (Table& table, int n)
{
	assert(n<=10 && n>=0 && n <= getMaxJoueur(table));
	table.nJoueur=n;
}


int getNJoueur (const Table& table)
{
	return table.nJoueur;
}


void ajoutJoueurTable (Table& table, const Joueur* joueur)
{
	int tmp = getNJoueur(table);
	table.joueur[tmp] = joueur;
	setNJoueur(table,tmp+1);
}

void supprimeJoueurTable (Table& table,const Joueur* joueur)
{
	int tmp = joueurTrouver (table, joueur);
	assert (tmp<10);
	setNJoueur(table,getNJoueur(table)-1);
	table.joueur[tmp]=NULL;
}

int joueurTrouver (Table& table, Joueur* joueur)
{
	int i;
	for(i=0;i<=getNJoueur(table) || table.joueur == joueur;i++);
	if(i==10) {printf("erreur le joueur n'a pas été trouvé (Table.C)");assert(0);}
	return i;
}

int carteDecouverteTrouver (const Table& table)
{
	int i;
	for(i=0;i<=4 || table.carteDecouverte[i] != NULL;i++);
	if(i==5) {printf("Déjà 5 carte dans carteDecouverte (Table.C)");assert(0);}
	return i;
}

void ajoutCarteDecouverte (Table& table, const Carte* carteDecouverte)
{
	int tmp=carteDecouverteTrouver (table);
	assert (tmp<5);
	table.carteDecouverte[tmp]=new Carte;
}


void reinitialiseCarteDecouverte (Table& table)
{
	int i;
	for (i=0;i<5;i++)
		table.carteDecouverte[i]=NULL;
}

void initPileCarte (table& table,const PileCarte* pileCarte)
{
	table.pileCarte = pileCarte;
}

void setMaxJoueur (Table& table, int n)
{
	assert(n<=10&&n>0&&n>table.nJoueur);
	table.nMaxJoueur = n;
}

int getMaxJoueur (const Table& table)
{
	return table.nMaxJoueur;
}
