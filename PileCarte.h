/**	@brief module Table.h
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
	@param taille taille du tableau des cartes (au depart dune partie 52)
*/
struct PileCarte
{
	Carte* pileDesCartes[52];
	int taille;
};

/**	@brief initialise la pile de carte
*/
void initPileCarte (PileCarte & pileCarte);

/**	@brief detruit la pile de carte proprement
*/
void testamentPileCarte (PileCarte & pileCarte);



#endif