#ifndef Table_H
#define Table_H
#include "Carte.h"
#include "PileCarte.h"


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


/**	@brief structure representant le joueur de poker assis � la table
	@param argent, r�el repr�sentant la somme que poss�de le joueur en main
	@param pseudo, chaine de caract�re repr�sentant le pseudo du joueur
	@param idJoueur identifiant joueur unique
	@param noPlace placement du joueur sur la table de 1 a 10
	@param statut indique le statut actuel du joueur sur la table
	@param mainCarte pointeur pointant sur la main du joueur
	@param carte1 et carte2 pointeur sur carte pointant sur les 2 cartes que le joueur a en main
*/
struct Joueur
{
	int argent;
	char pseudo[15];
	int idJoueur;
	int noPlace;
	Statut statut;
	MainCarte* main; // on doit mettre rien

};


/**	@brief creer un joueur
*/
void creerJoueur (Joureur& joueur);




#endif