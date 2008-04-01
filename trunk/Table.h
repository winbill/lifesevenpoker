#ifndef Table_H
#define Table_H
#include "Carte.h"
#include "PileCarte.h"

struct Table
{
	int nJoueur;
	Joueur* joueur[10];
	int nMaxJoueur;
	Carte* carteDecouverte[5];
	PileCarte* pileCarte;
};

void initTable (Table& table);
//initialise la table

void setNJoueur (Table& table, int n);
//établit un nombre de joueurs n a la table

int getNJoueur (const Table& table);
//renvoi le nombre de joueurs

void ajoutJoueurTable (Table& table, const Joueur* joueur);
//Ajoute un joueur à la table

void supprimeJoueurTable (Table& table,const Joueur* joueur);
//supprime le joueur du tableau en effectuant une recherche
//le joueur existe encore après

int joueurTrouver (Table& table, Joueur* joueur);
//renvoi le rang dans le tableau du joueur

void ajoutCarteDecouverte (Table& table, const Carte* carteDecouverte);
//ajoute une carte découverte

void reinitialiseCarteDecouverte (Table& table); 
//enleve toutes les cartes du tableau des cartes découverte
//lors d'un changement de partie

void initPileCarte (table& table,const pile& pileCarte)
//initialise un nouveau jeu de carte pour la table avec une pile donnée

void setMaxJoueur (Table& table, int n);
//établit un nombre de joueurs maximal n à la table

int getMaxJoueur (const Table& table);
//renvoi le nombre de joueurs maximal


#endif