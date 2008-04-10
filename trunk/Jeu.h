#ifndef Jeu_H
#define Jeu_H
#include "AfficheTxt.h"
#include "Table.h"
#include "Controles.h"
//#include "AfficheDynamique.h"


/**	@brief initialise le jeu
	@note donne 1000c a chacun des joueurs, affecte les IA, les places, le dealer....
*/
void initialiseJeu(Table & table);

/**	@brief donne deux carte a chacun des joueurs de la table
*/
void distribuerCarteJoueursJeu(Table & table);

/**	@brief decouvre n carte sur la table
*/
void distribuerCarteDecouverteJeu(Table & table,int n);

/**	@brief relance une nouvelle partie
	@note remet la main de tous à zero et re remplit pileCarte (en changeant la taille)
	@note change la position du dealer
	@note mise de la petite et grosse blind
*/
void lanceJeu(Table & table);

/**	@brief donne la victoire a un (ou plus) joueur(s)
	@note analyse la (ou les) main(s) gagnante et répartie le pot en fonction
*/
void donneVictoireJeu(Table & table);

