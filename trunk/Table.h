#ifndef Table_H
#define Table_H
#include "MainCarte.h"
#include "PileCarte.h"
#include "Joueur.h"


/**	@brief structure representant la table du jeu de poker, maximum 10 joueurs
	@param nJoueur nombre de joueurs
	@param joueur tableau de pointeur de joueurs
	@param nMaxJoueur nombre de joueur maximale (pour le reseau apres)
	@param carteDecouverte represente ladresse de la "main" qui represente les cartes visible par tous
	@param pileCarte represente la pile de carte (celle dou on distribue les cartes)
	@note la position du joueur dans le tableau indique sa position a la table
*/
struct Table
{
	int nJoueur;
	Joueur* joueur[10];
	int nMaxJoueur;
	MainCarte* carteDecouverte;
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


/**	@brief libere les allocations internes a table
*/
void tableLibere(Table& table);


/**	@brief libere plus detruit la structure
	@param table adresse d une table
	@note appel la fonction tableLibere
*/
void tableDetruit(Table* & table);


/**	@brief Ajoute un joueur a la table
*/
void ajoutJoueurTable (Table & table, Joueur* joueur);


/**	@brief supprime le joueur du tableau en effectuant une recherche
	le joueur existe encore apres
	@param joueur pointeur vers joueur
*/
void supprimeJoueurTable (Table & table,Joueur* joueur);


/**	@brief renvoi le rang dans le tableau du Joueur
	@param joueur pointeur vers joueur
	@warning affiche un message derreur sur la sortie standart si aucun joueur correspondant n'a ete trouve
*/
int joueurTrouver (Table & table, Joueur* joueur);


/**	@brief etablit un nombre de joueurs maximal (pour le reseau)
	@param n nombre de joueur maximum
*/
void setMaxJoueurTable (Table & table, int n);


/**	@brief renvoi le nombre de joueurs maximal
	@return nombre de joueur max
*/
int getMaxJoueurTable (const Table & table);


/**	@brief renvoi l adresse de la pile de carte
*/
PileCarte* getTablePileCarteTable (const Table & table);


/**	@brief etablit un nombre de joueurs n a la table
	@param n nombre de joueurs desires
*/
void setNJoueurTable (Table & table, int n);


/**	@brief renvoi le nombre de joueurs
*/
int getNJoueurTable (const Table & table);

/**	@brief etablit un numero de place à un joueur
	@note appel la fonction placeVide
*/
void setJoueurTable (Joueur* & joueur, Table & table);

/**     @brief renvoi le numero de la premiere place libre, 0 sinon
*/
int placeVide (const Table & table);




#endif