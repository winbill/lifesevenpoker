/**
	@brief Fichier H pour l'affichage en mode texte
	
	
	gere l'affichage et le debug en mode texte uniquement
     
	@author  James
	@file AfficheTxt.h
	@version 1.1
	@date 2008/04/11
 */
 
#ifndef AfficheTxt_H
#define AfficheTxt_H
/*
	int argent;
	char pseudo[15];
	int idJoueur;
	int noPlace;
	Statut statut;
	MainCarte* mainJoueur;
	
	*/
	
/**	@brief affiche les informations personnel dun joueur
	@note argent, pseudo,idJoueur,noPlace,status,cartes, 
*/
void afficheTInfosPersoJoueur(const Joueur & joueur);


/**	@brief affiche les informations publique dun joueurs
	@note argent, pseudo,idJoueur,noPlace,status 
	@note informations non personnel
*/
void afficheTInfosPubliqueJoueur(const Joueur & joueur);

/**	@brief affiche la main dun joueur
*/
void afficheTMainJoueur(const Joueur & joueu

/**	@brief affiche successivement les cartes d'une main
*/
void afficheTMainCarte(const MainCarte & mainCarte);

/**	@brief affiche une carte
*/
void afficheTCarte(const Carte & carte);

/**	@brief affiche un texte
	@param char chaine de caractere
*/
void afficheTText(const char & tab[]);





















#endif