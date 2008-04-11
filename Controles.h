/**
	@brief Fichier H pour les controle
	
	
	gere l'interaction du joueur avec le programme
     
	@author James
	@file Controles.h
	@version 1.1
	@date 2008/04/11
 */
#ifndef Controles_H
#define Controles_H


/**	@brief demande au joueur ce qu il veut faire
	@param [in, out] joueur un joueur
	@note change eventuellement son statut
	@return peut retourner le montant de ca relance
*/
int controleTActionJoueur(Joueur& joueur);

/**	@brief permet d executer des commandes pour le beboguage
	@note comme voir les cartes de d'autres joueur
*/
void controleTDebugMode();













#endif