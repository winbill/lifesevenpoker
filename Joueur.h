/**
	@brief Fichier H pour Joeur
	
	
	gere la structure joueur et leur parametre
     
	@author Tristan James
	@file Joueur.h
	@version 1.1
	@date 2008/04/11
 */
#ifndef Joueur_H
#define Joueur_H
#include "IArtificelle.h"
#include "MainCarte.h"

/** 	@brief Statut du joueur
*/
enum Statut
{
	SIT_OUT=0, 	/**< Joueur pas assis */
	SIT= 1,		/**< Joueur assis */
	CALL=2,		/**< Joueur suis */
	CHECK= 3,	/**< Joueur check */
	RAISE= 4,	/**< Joueur relance */
	FOLD= 5,		/**< Joueur se couche */
	ALL_IN= 6,	/**< Joueur fait tapis */
	FIN_STATUT	/**< Joueur erreur*/
};


/**	
	@struct Joueur
	@brief structure representant le joueur de poker assis à la table
	@param argent, réel représentant la somme que possède le joueur en main
	@param pseudo, chaine de caractère représentant le pseudo du joueur
	@param idJoueur identifiant joueur unique, correspond a sa place a la table, et a son indice dans le tableau de joueur de la table ou il est, egale a -1 s'il nest pas associe a une table (dans ce cas il peut ne pas etre unique)
	@param noPlace placement du joueur sur la table de 0 a 10
	@param statut indique le statut actuel du joueur sur la table
	@param mainCarte pointeur pointant sur la main du joueur
*/
struct Joueur
{
	int argent;
	char pseudo[15];
	int idJoueur;
	int mise;
	Statut statut;
	MainCarte* mainJoueur;
};

/**	@brief initialise un joueur
	@param [in,out] joueur
	@note on initialise idJoueur avec -1
*/
void initJoueur(Joueur & joueur)


/**	@brief creer un joueur
	@param [in,out] joueur
*/
Joueur* creerJoueur (Joureur & joueur);



/**	@brief initialise un joueur
	@param pseudo : nom du joueur 15 caractères max
	@param [in,out] joueur
*/
void initJoueur (Joueur & joueur,char[15] pseudo);


/** 	@brief cree dans le tas une variable joueur puis l'initialise
	@note appel la fonction initJoueur
	@return renvoie l'adresse d'un Joueur
*/
Joueur* creeJoueur();

/** 	@brief change le statut du joueur en statut
	@param [in,out] joueur
	@param [in] statut
	@note appel la fonction initJoueur
*/
void setStatutJoueur (Joueur & joueur, const Statut statut);


/** 	@brief change le statut du joueur en statut
	@param [in,out] joueur
	@note appel la fonction initJoueur
	@return renvoie le statut actuel du joueur
*/
Statut getStatutJoueur (Joueur & joueur);


/**	@brief libere les allocations internes a joueur
	@param [in,out] joueur
*/
void joueurLibere(Joueur & joueur);


/**	@brief libere plus detruit la structure
	@param [in, out] joueur adresse d'un joueur
	@note appel la fonction joueurLibere
*/
void joueurDetruit(Joueur* & joueur);


/**	@brief réinitialise la main du joueur
	@param [in,out] joueur
	@param mainJoueur pointeur sur une MainCarte
*/
void reinitialiseMainJoueur (Joueur & joueur);


/** 	@brief donne un id unique et différent a chaque joueur
	@param [in] n entier
	@param [in,out] joueur
*/
void setIdJoueur (Joueur & joueur,int n);


/**	@brief renvoi l'id du joueur
	@param [in,out] joueur
	@return idJoueur
*/
int getIdJoueur (const Joueur & joueur);

/** 	@brief entre la mise d'un joueur
	@param [in] n valeur de la mise
	@param [in,out] joueur
*/
void setMiseJoueur (Joueur & joueur,int n);


/**	@brief renvoi la mise qu'a effectuer un joueur
	@param [in,out] joueur
	@return mise du joueur
*/
int getMiseJoueur (const Joueur & joueur);

/** 	@brief entre la mise d'un joueur
	@param [in] n valeur de la mise ajouter a la valeur de ca mise courante
	@param [in,out] joueur
	@return ca nouvelle mise (mise davant + n);
	@note sorte de get et set sur la mise du joueur
*/
int ajoutMiseJoueur(Joueur & joueur,int n);


/**	@brief renvoi l'adresse de mainJoueur
	@param [in] joueur
*/
MainCarte* getMainJoueur (const Joueur & joueur);


#endif