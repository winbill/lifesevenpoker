#ifndef Table_H
#define Table_H
#include "Carte.h"
#include "PileCarte.h"

/**	@brief structure representant le joueur de poker assis à la table
	@param argent, réel représentant la somme que possède le joueur en main
	@param pseudo, chaine de caractère représentant le pseudo du joueur
	@param idJoueur identifiant joueur unique
	@param noPlace placement du joueur sur la table de 1 a 10
	@param statut indique le statut actuel du joueur sur la table
	@param mainCarte pointeur pointant sur la main du joueur
	@param carte1 et carte2 pointeur sur carte pointant sur les 2 cartes que le joueur a en main
*/
enum Statut //on peut faire sans mais si on veut faire en deux langues ca sera plus pratique
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



struct Joueur
{
	float argent;
	char pseudo[15];
	int idJoueur;
	int noPlace;
	Statut statut;
	mainCarte* main[5]; // on doit mettre 2, 5 ou 7 là ???? il aura en main 2 cartes, mais avec celles découvertes ca sera 7carte qu'il a, ds le diagramme ya marké ke mainCarte cé o max 5.....pti pb
	Carte* carte1;
	Carte* carte2;
};


/**	@brief creer un joueur
*/
void creerJoueur (Joureur& joueur);




#endif