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
	screen = SDL_SetVideoMode( screen_width, screen_height, screen_bpp, SDL_HWSURFACE|SDL_RESIZABLE|SDL_DOUBLEBUF );

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
	if((loadedImage = IMG_Load(filename)) == 0)
	{
	    printf("Impossible de charger l\'image.\n");
	}

	//Si le chargement se passe bien
	if( loadedImage != NULL )
	{
		//Création de l'image optimisée
		if((optimizedImage = SDL_DisplayFormatAlpha( loadedImage )) == 0)
		{
		    printf("Impossible d'optimiser l\'image.\n");
		}

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
	//SDL_UpdateRect(destination,0,0,0,0);
}



void AffAfficheTapis(SDL_Surface* aff)
{
    path tapisP = "img/bkgrd.jpg";

    SDL_Surface* tapis = load_image(tapisP);

    apply_surface(0,0,tapis,aff);
}

void AffActualiser(SDL_Surface* affichage)
{
    SDL_Flip(affichage);
    //SDL_UpdateRect(affichage, 0, 0, 0, 0);
}

SDL_Rect AffCentrer(SDL_Surface* source, SDL_Surface* destination, int option)
{
    SDL_Rect imageRect;
    switch(option)
    {
        case 0 :
            imageRect.x = (destination->w - source->w) / 2;
            imageRect.y = (destination->h - source->h) / 2;
        break;
        case 1 :
            imageRect.x = (destination->w - source->w) / 2;
        break;
        case 2 :
            imageRect.y = (destination->h - source->h) / 2;
        break;
    }
    return imageRect;

}

void AffEffaceEcran(SDL_Surface* aff)
{
    AffAfficheTapis(aff);
}



void AffStartUp(SDL_Surface* affichage,SDL_Surface* logo)
{
    AffAfficheTapis(affichage);
    SDL_Rect logoRect=AffCentrer(logo,affichage,0);
    apply_surface(logoRect.x,logoRect.y,logo,affichage);
    SDL_Delay(500);
    SDL_Flip(affichage);
}

void AffAfficheTexte(SDL_Surface* destination,char* message)
{
    printf("aa\n");

    //La surface où on va coller le message
    SDL_Surface* texte;
    //Le Font qu'on va utiliser
    TTF_Font *font;

    //La couleur du Font
    SDL_Color textColor = { 255, 255, 255,0};

    //Ouverture du Font
    font = TTF_OpenFont( "./fonts/TlwgTypewriter.ttf", 28 );


    //S'il y a une erreur dans le chargement du Font
    if ( font == NULL )
    {
        printf("Erreur de chargement de la font\n");
    }

    //Mise en place du texte sur la surface message
    texte = TTF_RenderText_Solid(font,message,textColor);

    //S'il y a une erreur dans la mise en place du texte
    if ( texte == NULL )
    {
        printf("Erreur de chargement du message\n");
    }

    //Application de la surface du message
    apply_surface(0,0,texte,destination);

}


void AffMenu(SDL_Surface* enCours)
{
    bool fin = false;


    ReAffCentrer(menu,enCours,0);
    apply_surface(0,0,menu,enCours);




    while(fin!=true)
    {
        SDL_WaitEvent(&event);

        switch(event.type)
        {
            case SDL_QUIT :
                fin=true;
            break;

            case SDL_KEYDOWN :
                if(event.key.keysym.sym == SDLK_ESCAPE and menuSwitch==0)
                {
                    fin=true;
                }
                else if(event.key.keysym.sym != SDLK_ESCAPE and menuSwitch==0)
                {
                    AffAfficheTapis(affichage);
                    apply_surface(0,0,menu,affichage);
                    AffActualiser(affichage);
                    menuSwitch=true;
                }
                else if(event.key.keysym.sym == SDLK_ESCAPE and menuSwitch==1)
                {
                    AffEffaceEcran(affichage);
                    AffAfficheTapis(affichage);
                    AffActualiser(affichage);
                    menuSwitch=false;
                }
            break;
        }
        }


}
