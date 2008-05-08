/**
	@brief Fichier H pour l'affichage dynamique


	Gere l'affichage dynamique en utilisant le moteur de rendu SDL (Simple Directmedia Layer).

	@author  James Benjamin
	@file AfficheDynamique.h
	@version 1.2
	@date 2008/04/21
 */

//Librairies Standard.
#include <stdlib.h>
#include <stdio.h>

//Librairies SDL.
#include <SDL/SDL.h>
#include "SDL/SDL_image.h" //Gestion des images.
#include "SDL/SDL_ttf.h" //Gestion des polices True Type Fonts.
#include <SDL/SDL_rotozoom.h>
//#include "SDL/SDL_mixer.h" //Gestion du multi channeling audio.


#include "Joueur.h"
#include "Table.h"
#include "AfficheTxt.h"

/** @brief Type cree pour manipuler les chemins de fichier.

*/
typedef char path[100];

int AffMenu(SDL_Surface* affichage);

int AffMenu(SDL_Surface* affichage);

void AffAfficheTexte(SDL_Surface* destination,char* message,int x,int y,int r,int g,int b);

void AffAfficheTexte(SDL_Surface* destination,char* message,int x,int y,int r,int g,int b,int style,int size);

void AffStartUp(SDL_Surface* affichage);

void AffAfficheTapis(SDL_Surface* aff);

void AffActualiser(SDL_Surface* affichage);

SDL_Rect AffCentrer(SDL_Surface* source, SDL_Surface* destination, int option);

void AffEffaceEcran(SDL_Surface* aff);

int lancePartie(SDL_Surface* affichage);

void AffAfficheCredits(SDL_Surface* affichage);














/** @brief Fonction qui initialise SDL et ses sous-systemes.
	@param [in,out] screen La surface principale de SDL.
	@param [in] screen_width La largeur de la surface principale.
	@param [in] screen_height La hauteur de la surface principale.
	@param [in] screen_bpp Le nombre de bits par pixels de la surface principale.
	@param [in] caption Une chaine de caracteres representant le nom de la fenetre du programme.
	@return Renvoie un booleen
	@note
*/
bool initSDL(SDL_Surface* & screen, const int & screen_width, const int & screen_height, const int & screen_bpp, path caption);


/** @brief Fonction permettant le chargement d'une image dans certains formats.
    @param [in] filename Une chaine de caracteres representant le nom de fichier.
    @return Renvoie un pointeur sur l'image chargée en mémoire.
    @note Formats supportés : BMP, GIF, JPEG, LBM, PCX, PNM, TGA, TIFF, XCF, XPM, XV et PNG.
*/
SDL_Surface *load_image( path filename );

/** @brief Procedure qui applique une surface SDL sur une autre selon la méthode du "blitting", qui est en quelque sort un collage simple.
    @param [in] x Coordonnee en x pour le blitting de l'image.
    @param [in] y Coordonnee en y pour le blitting de l'image.
    @param [in] source Le pointeur sur image de ce qu'on veut blitter.
    @param [in] destination Le pointeur sur image de sur quoi on veut blitter.
    @note Attention : le système de coordonnees utilise ici est un systeme X,Y dont l'origine est le coin superieur gauche de l'image et dont l'axe Y est inverse et pointe vers le bas.
*/
void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination );
