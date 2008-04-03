#ifndef Table_H
#define Table_H
#include "MainCarte.h"
#include "PileCarte.h"
#include "Joueur.h"


/**	@brief structure representant la table du jeu de poker, maximum 10 joueurs
	@param nJoueur nombre de joueurs
	@param joueur tableau de pointeur de joueurs
	@param nMaxJoueur nombre de joueur maximale (pour le reseau apres)
	@param carteDecouverte represente les cartes qui sont sur la table , visible par tous
	@param pileCarte represente la pile de carte (celle dou on distribue les cartes)
*/
struct Table
{
	int nJoueur;
	Joueur* joueur[10];
	int nMaxJoueur;
	Carte* carteDecouverte[5];
	PileCarte* pileCarte;
};



/**	@brief initialise la variable table
*/
void initTable (Table& table);


/**	@brief initialise la variable table
	@param nJoueur nombre de joueur souhaite et nombre de joueur maximal
*/
void initTable (Table& table,int nJoueur);


/**	@brief initialise lune variable table
	@param nJoueur nombre de joueur souhaite et nombre de joueur maximal
	@param pileCarte adresse de la pile de carte
*/
void initTable (Table& table,int nJoueur,PileCarte* & pileCarte);


/**	@brief cree dans le tas une variable table puis l'initialise
	@note appel la fonction initTable
	@return renvoie l'adresse dune Table
*/
Table* creeTable();


/**	@brief libere les allocations internes a camion
*/
void tableLibere(Table& table);


/**	@brief libere plus detruit la structure
	@param table adresse d une table
	@note appel la fonction tableLibere
*/
void tableDetruit(Table* & table);

/**	@brief etablit un nombre de joueurs n a la table
	@param n nombre de joueurs desires
*/
void setNJoueur (Table & table, int n);


/**	@brief renvoi le nombre de joueurs
*/
int getNJoueur (const Table & table);


/**	@brief Ajoute un joueur a la table
*/
void ajoutJoueurTable (Table & table, const Joueur* & joueur);


/**	@brief supprime le joueur du tableau en effectuant une recherche
	le joueur existe encore apres
	@param joueur pointeur vers joueur
*/
void supprimeJoueurTable (Table & table,const Joueur* & joueur);


/**	@brief renvoi le rang dans le tableau du Joueur
	@param joueur pointeur vers joueur
	@note appel la fonction joueurTrouver
	@warning affiche un message derreur sur la sortie standart si aucun joueur correspondant n'a ete trouve
*/
int joueurTrouver (Table & table, Joueur* joueur);


/**	@brief renvoi le rang dans le tableau de la 1ere case vide de 0 a 5 inclus
	@warning affiche un message derreur sur la sortie standart si aucun joueur correspondant n'a ete trouve
*/
int carteDecouverteTrouver (const Table & table);


/**	@brief ajoute une carte decouverte
	@param carteDecouverte pointeur vers Carte
	@note appel carteDecouverteTrouver 
*/
void ajoutCarteDecouverte (Table & table, const Carte* & carteDecouverte);


/**	@brief enleve toutes les cartes du tableau des cartes decouverte
	lors d un changement de partie
*/
void reinitialiseCarteDecouverte (Table & table); 


/**	@brief initialise un nouveau jeu de carte pour la table avec une pile donnee
	@param pileCarte pointeur vers PileCarte
*/
void initPileCarte (Table & table,const pile & pileCarte)


/**	@brief etablit un nombre de joueurs maximal (pour le reseau)
	@param n nombre de joueur maximum
*/
void setMaxJoueur (Table & table, int n);


/**	@brief renvoi le nombre de joueurs maximal
	@return nombre de joueur max
*/
int getMaxJoueur (const Table & table);


/**	@brief etablit un ladresse de la pile de carte
	@param pileCarte pointeur
*/
void setTablePileCarte(Table & table,PileCarte* & pileCarte);


/**	@brief renvoi l adresse de la pile de carte
*/
PileCarte* getTablePileCarte(const Table & table);

#endif