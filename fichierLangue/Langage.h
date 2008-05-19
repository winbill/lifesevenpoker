/**
	@brief Fichier H qui gere le langage
	@author Tristan
	@file Langage.h
	@version 1.0
	@date 2008/05/19
 */


#ifndef Langue_H
#define Langue_H

/**	@brief ecrit dans un tableau le menu en choisissant un fichier
	@param menu tableau qui apres la procédure contiendra sur chaque ligne une ligne du menu
	@param nomFichier fichier a choisir (langage)
*/
void ecrireDansTableau(char menu[50][50],const char nomFichier[50]);


/**	@brief affiche un tableau de chaines de caracteres
	@param c tableau contenant les lignes du menu
	@todo je ne sais pas comment faire pour que ca afiche le tableau jusqu'a ce que une ligne soit vide
*/
void afficherMenu(const char c[50][50]);


#endif
