#ifndef Joueur_H
#define Joueur_H
#include "IArtificelle.h"
#include "MainCarte.h"


enum Statut
{
	SIT_OUT=0,
	SIT= 1,
	CALL=2
	CHECK= 3,
	RAISE= 4,
	FOLD= 5,
	ALL_IN= 6,
	FIN_STATUT
};


/**	@brief structure representant le joueur de poker assis à la table
	@param argent, réel représentant la somme que possède le joueur en main
	@param pseudo, chaine de caractère représentant le pseudo du joueur
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
	@param pseudo : nom du joueur 15 caractères max
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


/**	@brief réinitialise la main du joueur
	@param mainJoueur pointeur sur une MainCarte
*/
void reinitialiseMainJoueur (Joueur & joueur);


/** 	@brief donne un identifiant unique et différent a chaque joueur
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