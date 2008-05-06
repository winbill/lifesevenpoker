/**
	@brief Fichier C pour l'affichage dynamique


	Gere l'affichage dynamique en utilisant le moteur de rendu SDL (Simple Directmedia Layer).

	@author  James Benjamin
	@file AfficheDynamique.C
	@version 1.2
	@date 2008/04/21
 */

#include "AfficheDynamique.h"
#include "Joueur.h"
#include "Table.h"


//Librairies Standard.
#include <stdlib.h>
#include <stdio.h>
#include <cassert>

//Librairies SDL.
#include <SDL/SDL.h>
#include <SDL/SDL_image.h> //Gestion des images.
#include <SDL/SDL_ttf.h> //Gestion des polices True Type Fonts.
//#include <SDL/SDL_mixer.h> //Gestion du multi channeling audio.



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





void AffStartUp(SDL_Surface* affichage)
{
    path logoP="img/logo.png";
    SDL_Surface* logo=load_image(logoP);
    AffAfficheTapis(affichage);
    SDL_Rect logoRect=AffCentrer(logo,affichage,0);
    SDL_SetAlpha(logo, SDL_SRCALPHA, 128);
    apply_surface(logoRect.x,logoRect.y,logo,affichage);
    SDL_Flip(affichage);
    SDL_Delay(500);
    SDL_FreeSurface(logo);

}

void AffAfficheTexte(SDL_Surface* destination,char* message,int x,int y,int r,int g,int b)
{

    //La surface où on va coller le message
    SDL_Surface* texte;
    //Le Font qu'on va utiliser
    TTF_Font *font;

    //La couleur du Font
    SDL_Color textColor = { r, g, b,0};

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
    apply_surface(x,y,texte,destination);

}

int AffMenu(SDL_Surface* affichage)
{

    bool fin = false;
    SDL_Event event;
    int colorDestination = 0;
    int currentColor = 255;


    path menuP="img/menu.bmp";
    SDL_Surface* menu=load_image(menuP);
    AffAfficheTexte(menu,"Nouvelle partie",50,240,255/10,255,255);
    SDL_Rect menuRect = AffCentrer(menu,affichage,0);
    apply_surface(menuRect.x,menuRect.y,menu,affichage);
    SDL_Flip(affichage);

    while(fin!=true)
    {
        SDL_PollEvent(&event);

        switch(event.type)
        {
            case SDL_QUIT :
                fin=true;
            break;

            case SDL_KEYDOWN :
                if(event.key.keysym.sym == SDLK_ESCAPE)
                {
                    return 0;
                }
                break;
            case SDL_MOUSEBUTTONUP :
                if(event.button.button == SDL_BUTTON_LEFT && event.button.x >= menuRect.x && event.button.x <= menu->w + menuRect.x && event.button.y >= 240+menuRect.y && event.button.y <= 268+menuRect.y)
                    return 1;
                break;
            case SDL_MOUSEMOTION:
                if(event.motion.x >= menuRect.x && event.motion.x <= menu->w + menuRect.x && event.motion.y >= 240+menuRect.y && event.motion.y <= 268+menuRect.y)
                {
                    colorDestination = 0;
                }else{
                    colorDestination = 255;
                }
            break;

        }
        if(colorDestination != currentColor)
        {
            if(colorDestination>currentColor)
            {
                currentColor+=10;
                if(currentColor>255)
                    currentColor=255;
            }else{
                currentColor-=10;
                if(currentColor<0)
                    currentColor=0;
            }

            AffAfficheTexte(menu,"Nouvelle partie",50,240,currentColor/10,currentColor,currentColor);
            SDL_Rect menuRect = AffCentrer(menu,affichage,0);
            apply_surface(menuRect.x,menuRect.y,menu,affichage);
            SDL_Flip(affichage);
        }

    }
    SDL_FreeSurface(menu);
    return 0;
}

int lancePartie(SDL_Surface* affichage)
{
    const int nombreJoueurPC = 7;
    Table t;
    PileCarte p;

    initTable(t);
    initPileCarte(p);

    t.pileCarte = &p;
    char nom[20];

    Joueur* player;
    Joueur* joueurs[10];

    for(int i=0;i<nombreJoueurPC;i++)
    {
        sprintf(nom,"%s%d","Ordinateur",i);
        joueurs[i]=creeJoueur();
        initJoueur(*joueurs[i],nom);
        ajoutJoueurTable(t,joueurs[i]);
    }


    player=creeJoueur();
    initJoueur(*player,"moi");
    ajoutJoueurTable(t,player);


    printf("lance jeu\n");
























    for(int i=0;i<nombreJoueurPC;i++)
    {
        joueurDetruit(joueurs[i]);
        joueurs[i]=NULL;
    }


    joueurDetruit(player);

    pileCarteLibere(p);
    tableLibere(t);

}

