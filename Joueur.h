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
	@brief structure representant le joueur de poker assis � la table
	@param argent, r�el repr�sentant la somme que poss�de le joueur en main
	@param pseudo, chaine de caract�re repr�sentant le pseudo du joueur
	@param idJoueur identifiant joueur unique
	@param noPlace placement du joueur sur la table de 1 a 10
	@param statut indique le statut actuel du joueur sur la table
	@param mainCarte pointeur pointant sur la main du joueur
*/
struct Joueur
{
	int argent;
	char pseudo[15];
	int idJoueur;
	int noPlace;
	Statut statut;
	MainCarte* mainJoueur;
};

/**	@brief initialise un joueur
*/
void initJoueur(Joueur & joueur)


/**	@brief creer un joueur
*/
Joueur* creerJoueur (Joureur & joueur);



/**	@brief initialise un joueur
	@param pseudo : nom du joueur 15 caract�res max
*/
void initJoueur (Joueur & joueur,char[15] pseudo);


/** 	@brief cree dans le tas une variable joueur puis l'initialise
	@note appel la fonction initJoueur
	@return renvoie l'adresse d'un Joueur
*/
Joueur* creeJoueur();

/** 	@brief change le statut du joueur en statut
	@note appel la fonction initJoueur
*/
void setStatutJoueur (Joueur & joueur, const Statut statut);


/** 	@brief change le statut du joueur en statut
	@note appel la fonction initJoueur
	@return renvoie le statut actuel du joueur
*/
Statut getStatutJoueur (Joueur & joueur);


/**	@brief libere les allocations internes a joueur
*/
void joueurLibere(Joueur & joueur);


/**	@brief libere plus detruit la structure
	@param joueur adresse d'un joueur
	@note appel la fonction joueurLibere
*/
void joueurDetruit(Joueur* & joueur);


/**	@brief r�initialise la main du joueur
	@param mainJoueur pointeur sur une MainCarte
*/
void reinitialiseMainJoueur (Joueur & joueur);


/** 	@brief donne un identifiant unique et diff�rent a chaque joueur
*/
void setIdJoueur (Joueur & joueur);


/**	@brief renvoi l'identifiant du joueur
	@return idJoueur
*/
int getIdJoueur (const Joueur & joueur);


/**     @brief renvoi l'adresse de mainJoueur
*/
MainCarte* getMainJoueur (const Joueur & joueur);


#endif