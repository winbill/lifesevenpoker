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
#include "AfficheTxt.h"
#include "Table.h"
#include "Controles.h"
//#include "AfficheDynamique.h"




/**	@brief initialise le jeu automatiquement pour une partie contre l'ordinateur (9 IA au max)
	@note donne de largent a chacun des joueurs, affecte les IA, les places, le dealer....
	@param [in, out] table une table
	@param [in] argent montant au depart
	@param [in] nombreJoueur le nombre de joueur total
*/
void initialiseJeu(Table & table,int argent,int nombreJoueur);

/**	@brief donne deux carte a chacun des joueurs de la table
	@param [in, out] table une table
*/
void distribuer2CartesJoueursJeu(Table & table)

/**	@brief decouvre n carte sur la table
	@param [in, out] table une table
	@param [in] n un entier qui correspond au nombre de carte a retourner sur  la table
*/
void distribuer1CarteDecouverteJeu(Table & table,int n);

/**	@brief relance une nouvelle partie
	@param [in, out] table une table
	@note remet la main de tous à zero et re remplit pileCarte (en changeant la taille)
	@note change la position du dealer
*/
void lanceJeu(Table & table);

/**	@brief donne la victoire a un (ou plus) joueur(s)
	@param [in, out] table une table
	@note analyse la (ou les) main(s) gagnante et répartie le pot en fonction
*/
void donneVictoireJeu(Table & table);

/** @brief fonction qui attent une action d'une personne humaine
	@param [in] table une table qui normellement n'est pas modifiee
	@param [in, out] Joueur un joueur
	@return entier de notification de relance (a 1 si relance)
	@note   cette fonction appel actionJoueurJeu(...) pour les
            modifications du joueur
*/
int atendActionJoueurHumain(const Table & table,Joueur & joueur);

/**	@brief fonction utilise lorsque le joueur change de status
	@param [in, out] table une table
	@param [in, out] joueur sujet de l'action
	@param [in] statut son nouveau statut
	@param [in] n s'il relance on met le montant dedans
*/
void actionJoueurJeu(Table & table,Joueur & joueur,Statut statut,int n);

/**	@brief interroge les joueurs tours à tours
	@param [in, out] table une table

	s'arrete lorsque les mises sont egales
*/
void lanceTourJeu(Table & table);


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
int codageScoreMain(const MainCarte &m, int & tabResultat[6],const Table & table);


#endif
