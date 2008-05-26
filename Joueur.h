/**	@brief Fichier H pour Joeur


	Gere la structure joueur et ses parametres.

	@author Tristan James Benjamin
	@file Joueur.h
	@version 1.3
	@date 2008/05/26
*/
#ifndef Joueur_H
#define Joueur_H

//Librairies Life'Seven Poker
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
	@param mise La somme des dernieres mises qu'a mis le joueur dans cette manche.
	@param statut Indique le statut actuel du joueur sur la table.
	@param mainCarte Pointeur vers la main du joueur.
	@param type Type du joueur: humain, IA ou joueur local (sinon valeur par defaut).
    @param posx Position en X de l'affichage du joueur.
    @param posy Position en Y de l'affichage du joueur.
    @param tapis La valeur du tapis du joueur si il en a fait un dans cette manche.
    @param gainTapis La valeur des gains de ce joueur en cas de tapis victorieux.
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
	int tapis;
	int gainTapis;
};


/** @brief Fonction qui renvoie la valeur du champ tapis d'une structure joueur.
    @param [in]
    @return Une valeur de type int.
*/
int getTapisJoueur(const Joueur & j);


/** @brief Procedure qui modifie la valeur du champ tapis d'une structure joueur.
    @param [in,out] j Un joueur.
    @param [in] n La nouvelle valeur de tapis.
*/
void setTapisJoueur(Joueur & j,int n);


/** @brief Fonction qui renvoie la valeur du champ gainTapis de la structure joueur.
    @param [in] j Un joueur.
    @return Une valeur de type int.
*/
int getGainTapisJoueur(const Joueur & j);


/** @brief Procedure qui modifie la valeur du champ gainTapis de la structure joueur.
    @param [in,out] j Un joueur.
    @param [in] n La nouvelle valeur de gainTapis.
*/
void setGainTapisJoueur(Joueur & j,int n);


/** @brief Procedure qui ajoute a un joueur ses gains de tapis.
    @param [in,out] j Un joueur.
    @param [in] n La quantite d'argent que le joueur a gagne lors du tapis.
    @note Modifie la valeur du champ 'gainTapis' de la structure joueur.
*/
void  ajouteGainTapisJoueur(Joueur & j,int n);


/**	@brief Initialise un joueur.
	@param [in,out] joueur Un joueur.
	@note On initialise le champ idJoueur avec la valeur -1.
*/
void initJoueur(Joueur & joueur);


/** @brief Fonction qui renvoie la position en X de l'affichage d'un joueur.
    @param [in] j Un joueur.
*/
int getPositionJoueurX(const Joueur & j);


/** @brief Fonction qui renvoie la position en Y de l'affichage d'un joueur.
    @param [in] j Un joueur.
*/
int getPositionJoueurY(const Joueur & j);


/** @brief Procedure qui modifie la valeur du champ posx d'une structure joueur.
    @param [in,out] j Un joueur.
    @param [in] x La nouvelle valeur de posx.
*/
void setPositionJoueurX(Joueur & j,int x);


/** @brief Procedure qui modifie la valeur du champ posy d'une structure joueur.
    @param [in,out] j Un joueur.
    @param [in] y La nouvelle valeur de posy.
*/
void setPositionJoueurY(Joueur & j,int y);


/**	@brief Initialise un joueur.
	@param [in,out] joueur Un joueur.
	@param [in] pseudo Nom du joueur (15 caracteres au maximum).
*/
void initJoueur (Joueur & joueur,const char* pseudo);


/** @brief Cree dans le tas une variable joueur puis l'initialise.
	@note Appelle la fonction initJoueur.
	@return Renvoie l'adresse d'un Joueur.
*/
Joueur* creeJoueur();


/**	@brief Change le statut du joueur.
	@param [in,out] joueur Un joueur.
	@param [in] statut La valeur de statut qui sera attribuee au joueur.
*/
void setStatutJoueur (Joueur & joueur, const Statut statut);


/** @brief Recupere le statut du joueur.
	@param [in,out] joueur Un joueur.
	@return Renvoie le valeur de statut actuelle de joueur.
*/
Statut getStatutJoueur (const Joueur & joueur);


/** @brief Procedure qui modifie la valeur du champ type d'une structure joueur.
    @param [in,out] joueur Un joueur.
    @param [in] typejoueur La nouvelle valeur de type.
*/
void setTypeJoueur(Joueur & joueur, const TypeJoueur typejoueur);


/** @brief Fonction qui renvoie la valeur du champ type d'une structure joueur.
    @param [in] joueur Un joueur.
*/
TypeJoueur getTypeJoueur(const Joueur & joueur);


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


/** @brief Procedure d'ajout d'argent a un joueur donne.
    @param [in,out] joueur Un joueur.
    @param [in] n La quantite d'argent que l'on va donner au joueur.
    @note Modifie la valeur du champ'argent' de la structure joueur.
*/
void ajoutArgentJoueur(Joueur & joueur, int n);


/** @brief Procedure qui reinitialise le champ mainJoueur d'une structure joueur.
    @param [in,out] j Un joueur.
*/
void reinitialisationMainJoueur(Joueur & j);


/** @brief Procedure qui rend effective l'action d'un joueur.
    @param [in,out] j Un joueur.
    @param [in] s Un statut.
    @param [in,out] montant La valeur du montant actuelle des mises.
    @param [in] relance La quantite d'argent qu'est pres a mettre le joueur pour continuer la manche.
*/
void actionJoueur(Joueur & j,Statut s,int & montant,int relance);


#endif
