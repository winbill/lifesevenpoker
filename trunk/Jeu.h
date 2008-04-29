/**
	@brief Fichier H qui gere le jeu


	fichier principal qui sert a initialiser une partie et la terminer

	@author James
	@file Jeu.h
	@version 1.1
	@date 2008/04/11
 */

#ifndef Jeu_H
#define Jeu_H
#include "Table.h"

//#include "AfficheDynamique.h"




/**	@brief initialise le jeu automatiquement pour une partie contre l'ordinateur (9 IA au max)
	@note donne de largent a chacun des joueurs, affecte les IA, les places, le dealer....
	@param [in, out] table une table
	@param [in] argent montant au depart
	@note getNJoueurTable(), setArgentJoueur()
*/
void initialiseJeu(Table & table,int argent);

/**	@brief donne deux carte a chacun des joueurs de la table
	@param [in, out] table une table
*/
void distribuer2CartesJoueursJeu(Table & table);

/**	@brief decouvre n carte sur la table
	@param [in, out] table une table
	@param [in] n un entier qui correspond au nombre de carte a retourner sur  la table
*/
void distribuer1CarteDecouverteJeu(Table & table,int n);


/** @brief fonction PRINCIPALE pour obtenir le code d'une main donc ca force
        pour la comparer aux autres mains,la fonction renvoit dans un tableau un code
        qui permet de pouvoir savoir qu'elle main est plus forte qu'une autre
    @param [in] m la main de carte qui donnera le code
    @param [out] tabResultat contient le code
    @param [in] table du jeu
    @return renvoit 1 si tout c'est bien passé
    @note le code renvoyé est composé de la facon suivante : le premier element du tableau
        correspond au code de la forme (8 Quinte flush,7 Carre,6 Full ...., 1 paire,0 carte haute)
        puis sont classés dans un ordre (fonction du code de la forme) les 5 cartes qui permettent de
        former cette combinaison
    @note la fonction appel toutes les autres fonctions de test de forme
    @author James
*/
int codageScoreMain(const MainCarte &m, int tabResultat[6], const Table & table);


#endif
