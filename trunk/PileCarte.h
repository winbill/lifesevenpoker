/**
	@brief Fichier H pour la pile de Carte
	
	
	gere la pile de carte d'ou sont distribuees les cartes
     
	@author Tristan James
	@file PileCarte.h
	@version 1.1
	@date 2008/04/11
 */
#ifndef Pilecarte_H
#define Pilecarte_H
#include "Carte.h"



/**	@brief structure representant le jeu (de 52 cartes au depart) dou sont distribuees les cartes
	@param ensembleCarte tableau contenant les cartes
	@param taille du tableau des cartes (au depart dune partie 52)
*/
struct PileCarte
{
	Carte* ensembleCarte[52];
	int taille;
};


/**	@brief initialise la pile de carte, en creant 52 cartes dans le tas
	@param [in,out] pileCarte une pile de carte
	@note ne melange pas les cartes
*/
void initPileCarte (PileCarte & pileCarte);


/**	@brief cree la pile de carte
	@return renvoie l'adresse dune PileCarte
*/
PileCarte* creePileCarte();



/**	@brief libere les allocations internes a pileCarte
	@param [in,out] pileCarte une pile de carte
*/
void pileCarteLibere (PileCarte & pileCarte);

/**	@brief detruit la pile de carte proprement
	@param [in,out] pileCarte une adresse de pile de carte
	@note appel pileCarteLibere
*/
void pileCarteDetruit(PileCarte* & pileCarte);


/**	@brief sort une carte au hasard de pileDesCartes

	ne la supprime pas du tableau donc pas la peine de reinitialiser
	pileCarte a chaque debut de partie ,il suffit de mettre la taille a 52
	@param [in,out] pileCarte une pile de carte
	@note utilise la fonction hasard
*/
Carte* tirerCarte(PileCarte & pileCarte);


/**	@brief reinitialise la pile de carte en mettant la taille a 52
	@param [in,out] pileCarte une pile de carte (on change uniquement la taille)
*/
void nouvellePileCarte(PileCarte & pileCarte);


/**	@brief renvoi un nombre au hasard dans l'intervalle (inclus)
	@param x le plus petit chiffre qui peut etre renvoye
	@param y le plus grand chiffre qui peut etre renvoye
	@return entier aleatoire compris entre x et y (compris)
*/
int hasard(x,y);



#endif