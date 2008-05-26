#ifndef Langue_H
#define Langue_H

/**
	@brief Fichier H pour la gestion des langues
	@author  Tristan
	@file Langage.h
	@version 1.1
	@date 2008/05/26
 */


/**	@brief ecrit dans un tableau le menu en choisissant un fichier
	@param menu tableau qui apres la procédure contiendra sur chaque ligne une ligne du menu
	@param nomFichier fichier a choisir (langage)
	@author Tristan James
*/
int ecrireDansTableau(char menu[50][50],const char nomFichier[50]);


/**	@brief affiche un tableau de chaines de caracteres
	@param c tableau contenant les lignes du menu
*/
void afficherMenu(const char c[50][50],int a);


#endif
