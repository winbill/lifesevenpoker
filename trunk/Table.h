/**
	@brief Fichier H pour Table


	gere la table du jeu

	@author Tristan James
	@file Table.h
	@version 1.1
	@date 2008/04/11
	@note exemple d'utilisation:
	@code
		//cree une table dans la pile
		Table table1
		initTable(table1,5,*pileCarte1);

		//ou pour cree une table a partir du tas et l'initialiser
		Table* table2;
		table2 = creeTable();



	@endcode



 */

#ifndef Table_H
#define Table_H
#include "MainCarte.h"
#include "Joueur.h"

/**
	@struct Table
	@brief structure representant la table du jeu de poker, maximum 10 joueurs
	@param nJoueur nombre de joueurs
	@param joueur pointeur sur pointeur de Joueur
	@param nMaxJoueur nombre de joueur maximale (pour le reseau apres)
	@param carteDecouverte represente ladresse de la "main" qui represente les cartes visible par tous
	@param pileCarte represente la pile de carte (celle dou on distribue les cartes)
	@param positionDealer la position du dealer au départ est a 0, il correspond a l'indice dans le tableau de joueurs du dealer
	@param petiteBlind montant de la PB la grosse blind est le double
	@note la position du joueur dans le tableau indique sa position a la table
*/
struct Table
{
	int nJoueur;
	Joueur** joueur;
	int nMaxJoueur;
	MainCarte* carteDecouverte;
	PileCarte* pileCarte;
	int positionDealer;
	int petiteBlind;
};



/**
	@brief initialise la variable table
	@param [in, out] table une table
*/
void initTable(Table & table);


/**	@brief cree dans le tas une variable table puis l'initialise
	@note appel la fonction initTable
	@return renvoie l'adresse dune Table
*/
Table* creeTable();


/**	@brief libere les allocations internes a table
	@param [in] table une table
*/
void tableLibere(Table & table);


/**	@brief libere plus detruit la structure
	@param [in, out] table adresse d une table
	@note appel la fonction tableLibere

*/
void tableDetruit(Table* & table);


/**	@brief Ajoute un joueur a la table
	@param [in, out] table une table
	@param [in,out] joueur un joueur  , on met dans joueur.idJoueur l'indice qu'il a dans le tableau de joueurs
	@note change table.nJoueur en incrementant de 1
*/
void ajoutJoueurTable (Table & table, Joueur* joueur);


/**	@brief supprime le joueur du tableau en effectuant une recherche
	le joueur existe encore apres
	@param [in, out] table une table
	@param [in,out] joueur pointeur vers joueur,on met dans joueur.idJoueur: -1
*/
void supprimeJoueurTable (Table & table, Joueur* joueur);


/**	@brief etablit un nombre de joueurs maximal (pour le reseau)
	@param [in, out] table une table
	@param n nombre de joueur maximum
*/
void setMaxJoueurTable (Table & table, int n);


/**	@brief renvoi le nombre de joueurs maximal
	@param [in] table une table
	@return nombre de joueur max
*/
int getMaxJoueurTable (const Table & table);


/**	@brief renvoi l adresse de la pile de carte
	@param [in] table une table
	@return l'adresse de la pile de carte utilise a la table
*/
PileCarte* getTablePileCarteTable (const Table & table);


/**	@brief etablit un nombre de joueurs n a la table
	@param [in, out] table
	@param [in] n nombre de joueurs desires
*/
void setNJoueurTable (Table & table, int n);


/**	@brief renvoi le nombre de joueurs
	@param [in] table une table
	@return nombre de joueur a la table
*/
int getNJoueurTable (const Table & table);


/**	@brief cherche une place vide dans le tableau de joueur
	@param [in] table une table
	@return renvoi l'indice de la premiere place libre, -1 sinon
	@note cette fonction sera utile si l'on souhaite ajouter un joueur a la table pendant une partie
*/
int placeVide (const Table & table);

/**	@brief change la position du dealer (decale de un en verifiant quil y a un joueur)
	@param [in, out] table une table
*/
void changeDealerTable(Table & table);

/**	@brief renvoi le joueur a la nieme position
	@param [in] table une table
	@param [in] n un entier
	@return renvoi un pointeur vers le joueur qui a pour indice n dans le tableau de joueur de la table
*/
Joueur* getIemeJoueur(const Table & table,int n);

/**	@brief renvoi l adresse des cartes decouvertes
	@param [in] table une table
	@return pointeur sur MainCarte
*/
MainCarte* getMainCarteTable(const Table & table);


/**	@brief etablit ula petite blind
	@param [in, out] table
	@param [in] n montant de la petite blind
*/
void setPetiteBlindTable (Table & table, int n);


/**	@brief renvoi la valeur de la petite blind
	@param [in] table une table
	@return valeur de la Petite Blind
*/
int getPetiteBlindTable (const Table & table);


/**	@brief renvoit l'indice du joueur suivant
	@param [in] table une table
	@param [in] i represente le joueur en cours
	@return entier correspondant a lindice du joueur suivant
*/
int getJoueurSuivant(const Table & table,int i);

/**	@brief renvoit la valeure de positionDealer
	@param [in] table une table
	@return entier correspondant a lindice du dealer
*/
int getPositionDealerTable(const Table & table);




/** @brief juste pr le debug
*/
void afficheInfoTable(const Table & t);
#endif
