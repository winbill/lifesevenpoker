/**	@brief module PileCarte.h
	@author James
	@version 1.0
        @date 2008/04/01
*/

#ifndef Pilecarte_H
#define Pilecarte_H
#include "Carte.h"
#include "Table.h"


/**	@brief structure representant le jeu (de 52 cartes au depart) dou sont distribuees les cartes
	@param pileDesCartes tableau contenant les cartes
	@param taille du tableau des cartes (au depart dune partie 52)
*/
struct PileCarte
{
	Carte* pileDesCartes[52];
	int taille;
};

/**	@brief initialise la pile de carte, en creant 52 cartes dans le tas
	@note ne melange pas les cartes
*/
void initPileCarte (PileCarte & pileCarte);

/**	@brief detruit la pile de carte proprement
*/
void testamentPileCarte (PileCarte & pileCarte);

/**	@brief sort une carte au hasard de pileDesCartes

	ne la supprime pas du tableau donc pas la peine de reinitialiser
	pileCarte a chaque debut de partie ,il suffit de mettre la taille a 52
	@note utilise la fonction hasard
*/
Carte* recevoirCarte(PileCarte & pileCarte);

/**	@brief renvoi un nombre au hasard dans l'intervalle (inclus)
	@param x le plus petit chiffre qui peut etre renvoye
	@param y le plus grand chiffre qui peut etre renvoye
	@return entier aleatoire compris entre x et y (compris)
*/
int hasard(x,y);



#endif