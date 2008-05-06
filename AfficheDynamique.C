/**
	@brief Fichier C pour l'affichage dynamique


	Gere l'affichage dynamique en utilisant le moteur de rendu SDL (Simple Directmedia Layer).

	@author  James Benjamin
	@file AfficheDynamique.C
	@version 1.2
	@date 2008/04/21
 */
//Librairies Standard.
#include <stdlib.h>
#include <stdio.h>
#include <cassert>

//Librairies SDL.
#include <SDL/SDL.h>
#include <SDL/SDL_image.h> //Gestion des images.
#include <SDL/SDL_ttf.h> //Gestion des polices True Type Fonts.
//#include <SDL/SDL_mixer.h> //Gestion du multi channeling audio.

#include "AfficheDynamique.h"

bool initSDL(SDL_Surface* & screen, const int & screen_width, const int & screen_height, const int & screen_bpp, path caption)
{
	//Initialisation de tous les sous-systèmes de SDL
	if( SDL_Init( SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER ) == -1 )
	{
	    printf("Impossible d\'initialiser les sous-systèmes de SDL.\n");
		return -1;
	}

	//Mise en place de l'écran
	screen = SDL_SetVideoMode( screen_width, screen_height, screen_bpp, SDL_SWSURFACE );

	//S'il y a une erreur dans la mise en place de l'écran
	if( screen == NULL )
	{
	    printf("Echec de la mise en place de l\'ecran.\n");
		return -1;
	}

	//Initialisation de SDL_TTF
	if( TTF_Init() == -1 )
	{
	    printf("Echec de l\'initialisation de SDL_ttf");
		return -1;
	}

	//Mise en place de la barre de titre de la fenetre principale (caption)
	SDL_WM_SetCaption( caption , NULL );

	//Si tout s'est bien passé
	return 0;
}

SDL_Surface *load_image( path filename )
{
	//Surface tampon qui nous servira pour charger l'image
	SDL_Surface* loadedImage = NULL;

	//L'image optimisée qu'on va utiliser
	SDL_Surface* optimizedImage = NULL;

	//Chargement de l'image
	loadedImage = IMG_Load( filename );

	//Si le chargement se passe bien
	if( loadedImage != NULL )
	{
		//Création de l'image optimisée
		optimizedImage = SDL_DisplayFormat( loadedImage );

		//Libération de l'ancienne image
		SDL_FreeSurface( loadedImage );
	}

	//On retourne l'image optimisée
	return optimizedImage;
}

void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination )
{
	SDL_Rect offset;

	offset.x = x;
	offset.y = y;

	//On blitte la surface
	SDL_BlitSurface( source, NULL, destination, &offset );
	SDL_UpdateRect(destination,0,0,0,0);
}
