#include "Table.h"


/*
struct Table
{
	int nJoueur;
	Joueur* joueur[10];
	int nMaxJoueur;
	MainCarte* carteDecouverte;
	PileCarte* pileCarte;
};
*/


void initTable (Table& table)
{
	table.nJoueur = 0;
	table.joueur = new Joueur* [10];
	setMaxJoueur (table,0);
	memset(table.joueur,0,sizeof(*table.joueur));
	carteDecouverte=new MainCarte;
	table.pileCarte = NULL;
	
}

void initTable (Table& table,int nJoueur)
{
	table.nJoueur = nJoueur;
	table.joueur = new Joueur* [10];
	setMaxJoueur (table, n);
	carteDecouverte=new MainCarte;
	memset(table.joueur,0,sizeof(*table.joueur));
	table.pileCarte = NULL;
}

void initTable (Table& table,int nJoueur,PileCarte* & pileCarte)
{
	table.nJoueur = nJoueur;
	table.joueur = new Joueur* [10];
	setMaxJoueur (table, n);
	carteDecouverte=new MainCarte;
	memset(table.joueur,0,sizeof(*table.joueur));
	setTablePileCarte(table,pileCarte);
}

Table* creeTable()
{
	Table* t = new Table;
	initTable(*table);
	return table;	
}

void tableLibere(Table& table)
{
	delete[]	table.joueur;
	table.joueur = NULL;
	delete table.carteDecouverte;
	table.carteDecouverte = NULL;
	table.pileCarte = NULL;
}


void tableDetruit(Table* & table)
{
	tableLibere(*table);
	delete table;
	table = NULL;	
}

void ajoutJoueurTable (Table & table, const Joueur* & joueur)
{
	int tmp = getNJoueur(table);
	table.joueur[tmp] = joueur;
	setNJoueur(table,tmp+1);
}

void supprimeJoueurTable (Table & table,const Joueur* & joueur)
{
	int tmp = joueurTrouver (table, joueur);
	assert (tmp<10);
	setNJoueur(table,getNJoueur(table)-1);
	table.joueur[tmp]=NULL;
}

int joueurTrouver (Table & table, const Joueur* & joueur)
{
	int i;
	for(i=0;i<=getNJoueur(table) || table.joueur == joueur;i++);
	if(i==10) {printf("erreur le joueur n'a pas été trouvé (Table.C)");assert(0);}
	return i;
}

void setMaxJoueurTable (Table & table, int n)
{
	assert(n<=10&&n>0&&n>table.nJoueur);
	table.nMaxJoueur = n;
}

int getMaxJoueurTable (const Table & table)
{
	return table.nMaxJoueur;
}

void setTablePileCarteTable(Table & table,PileCarte* & pileCarte)
{
	table.pileCarte = pileCarte;
}

PileCarte* getTablePileCarteTable(const Table & table)
{
	return table.pileCarte;
}

void setNJoueurTable (Table & table, int n)
{
	assert(n<=10 && n>=0 && n <= getMaxJoueur(table));
	table.nJoueur=n;
}

int getNJoueur (const Table & table)
{
	return table.nJoueur;
}
