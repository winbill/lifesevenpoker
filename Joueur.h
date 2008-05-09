/**	@brief Fichier H pour Joeur


	Gere la structure joueur et ses parametres.

	@author Tristan James Benjamin
	@file Joueur.h
	@version 1.2
	@date 2008/04/23
*/
#ifndef Joueur_H
#define Joueur_H
//#include "IArtificielle.h"
#include "MainCarte.h"









/** 	@brief Statut du joueur
*/
enum Statut
{
    DEF_STATUT=0,   /**< Valeur d'initialisation */
	SIT_OUT, 	    /**< Joueur pas assis */
	SIT,		    /**< Joueur assis */
	CALL,		    /**< Joueur suis */
	CHECK,	        /**< Joueur check */
	RAISE,	        /**< Joueur relance */
	FOLD,	        /**< Joueur se couche */
	ALL_IN,	        /**< Joueur fait tapis */
	FIN_STATUT	    /**< Joueur erreur*/
};

/** 	@brief Indique le type du joueur
*/
enum TypeJoueur
{
    DEF_TYPE_JOUEUR=0,  /**< Valeur d'initialisation */
	Humain, 	        /**< Joueur humain mais pas le joueur qui joue (pour le reseau)*/
	IA,		            /**< Joueur simulé par l'ordinateur */
	JoueurLocal,	    /**< Joueur qui joue sur la machine locale */
	FIN_TYPE	        /**< Joueur erreur */
};

/**	@struct Joueur
	@brief Structure representant le joueur de poker assis à la table.
	@param argent Reel représentant la somme d'argent que possede le joueur.
	@param pseudo Chaine de caractere representant le pseudo du joueur.
	@param idJoueur Identifiant du joueur, unique, correspondant a sa place a la table, ainsi qu'a son indice dans le tableau de joueurs de la table ou il est assis. Egal a -1 s'il nest pas associe a une table (dans ce cas il peut ne pas etre unique).
	@param statut Indique le statut actuel du joueur sur la table.
	@param mainCarte Pointeur vers la main du joueur.
	@param type Type du joueur: humain, IA ou joueur local (sinon valeur par defaut).
	@param mise la somme des derniere mis quil a joue
*/
struct Joueur
{
	int argent;
	char* pseudo;
	int idJoueur;
	int mise;
	Statut statut;
	MainCarte* mainJoueur;
	TypeJoueur type;
	int posX;
	int posY;
};

void actionJoueur(Joueur & j,Statut s,int & montant,int relance);

int getPositionJoueurX(const Joueur & j);

int getPositionJoueurY(const Joueur & j);

void setPositionJoueurX(Joueur & j,int x);

void setPositionJoueurY(Joueur & j,int y);



/**	@brief Initialise un joueur.
	@param [in,out] joueur Un joueur.
	@note On initialise le champ idJoueur avec la valeur -1.
*/
void initJoueur(Joueur & joueur);

/**	@brief Initialise un joueur.
	@param [in,out] joueur Un joueur.
	@param [in] pseudo Nom du joueur (15 caracteres au maximum).
*/
void initJoueur (Joueur & joueur,const char* pseudo);

/** 	@brief Cree dans le tas une variable joueur puis l'initialise.
	@note Appelle la fonction initJoueur.
	@return Renvoie l'adresse d'un Joueur.
*/
Joueur* creeJoueur();

/**	@brief Change le statut du joueur.
	@param [in,out] joueur Un joueur.
	@param [in] statut La valeur de statut qui sera attribuee au joueur.
*/
void setStatutJoueur (Joueur & joueur, const Statut statut);

/** 	@brief Recupere le statut du joueur.
	@param [in,out] joueur Un joueur.
	@return Renvoie le valeur de statut actuelle de joueur.
*/
Statut getStatutJoueur (Joueur & joueur);






void setTypeJoueur(Joueur & joueur, const TypeJoueur typejoueur);

TypeJoueur getTypeJoueur(Joueur & joueur);





/**	@brief Libere les allocations memoire internes a la structure joueur.
	@param [in,out] joueur Un joueur.
*/
void joueurLibere(Joueur & joueur);

/**	@brief Libere puis detruit le joueur et toutes les allocations memoires dependantes.
	@param [in, out] joueur Adresse d'un joueur.
	@note Appelle la fonction joueurLibere.
*/
void joueurDetruit(Joueur* & joueur);

/**	@brief Reinitialise la main d'un joueur.
	@param [in,out] joueur Un joueur.
*/
void reinitialiseMainJoueur(Joueur & joueur);

/** @brief Modifie l'id du joueur.
	@param [in] n Un entier.
	@param [in,out] joueur Un joueur.
*/
void setIdJoueur(Joueur & joueur, int n);

/**	@brief Renvoie la valeur d'id du joueur.
	@param [in,out] joueur Un joueur.
	@return idJoueur Un entier.
*/
int getIdJoueur(const Joueur & joueur);

/** @brief Modifie la mise d'un joueur.
	@param [in] n Entier representant la valeur de la mise totale faite par le joueur lors de la manche.
	@param [in,out] joueur Un joueur.
*/
void setMiseJoueur(Joueur & joueur, const int & n);

/**	@brief Recupere la mise totale qu'a effectue un joueur lors de la manche.
	@param [in,out] joueur Un joueur.
	@return mise Un entier.
*/
int getMiseJoueur(const Joueur & joueur);

/** @brief Repercute la nouvelle mise d'un joueur sur sa mise totale.
	@param [in] n Entier representant la valeur de la mise ajoutee a la valeur de sa mise courrante.
	@param [in,out] joueur Un joueur.
	@return mise Sa nouvelle valeur de mise (mise d'avant + n)
	@note C'est une sorte de get et set sur la mise du joueur dans la meme fonction.
*/
int ajoutMiseJoueur(Joueur & joueur,int n);

/**	@brief Renvoie l'adresse de mainJoueur dans la structure joueur.
	@param [in] joueur Un joueur.
*/
MainCarte* getMainJoueur(const Joueur & joueur);

/** @brief Modifie la somme d'argent que possede un joueur.
	@param [in] n Un entier.
	@param [in,out] joueur Un joueur.
*/
void setArgentJoueur(Joueur & joueur, int n);

/**	@brief Recupere le montant que possede un joueur.
	@param [in,out] joueur Un joueur.
	@return argent Un entier representant la somme d'argent que possede joueur.
*/
int getArgentJoueur(const Joueur & joueur);

/** @brief affiche les infos du joueurs
    @note fonction debug
*/
void afficheInfoJoueur(const Joueur & j);




#endif

