//Librairies Life'Seven Poker
//#include "Jeu.h"
//#include "PileCarte.h"
//#include "Table.h"
//#include "Joueur.h"
//#include "Jeu.h"

//Librairies Standard.
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "AfficheDynamique.h"
//#include "AfficheTxt.h"


//Librairies SDL.
#include <SDL/SDL.h>
#include <SDL/SDL_image.h> //Gestion des images.
#include <SDL/SDL_ttf.h> //Gestion des polices True Type Fonts.
//#include <SDL/SDL_mixer.h> //Gestion du multi channeling audio.


int main (int argc, char** argv )
{
    SDL_Surface* affichage;
    path caption="Life\'Seven Poker";

    if(initSDL(affichage,1024,768,32,caption)!=0)
    {
        return 1;
    }

    atexit(SDL_Quit);
    path backgroundP="img/bkgrd.bmp";
    SDL_Surface* background=load_image(backgroundP);
    apply_surface(0,0,background,affichage);
    path menuP="img/menu.bmp";
    SDL_Surface* menu=load_image(menuP);

    bool fin=false;
    bool menuSwitch=false;
    bool gameOn=false;

    SDL_Event event;

    while(fin!=true)
    {
        SDL_UpdateRect(affichage, 0, 0, 0, 0);
        SDL_WaitEvent(&event);

        if(menuSwitch)
        {
            apply_surface(0,0,menu,affichage);
        }
        switch(event.type)
        {
            case SDL_QUIT : fin=true;
            break;

            case SDL_KEYDOWN :
            {
                if(event.key.keysym.sym == SDLK_ESCAPE and menuSwitch==0)
                {
                    fin=true;
                }
                else if(event.key.keysym.sym != SDLK_ESCAPE and menuSwitch==0)
                {
                    menuSwitch=true;
                }
                else if(event.key.keysym.sym == SDLK_ESCAPE and menuSwitch==1)
                {
                    menuSwitch=false;
                    SDL_FreeSurface(menu);
                }
            }
            break;
        }
    }


    SDL_FreeSurface(menu);
    SDL_FreeSurface(background);
    SDL_FreeSurface(affichage);



  /*  // screen attributes
    const int SCREEN_WIDTH = 1024;
    const int SCREEN_HEIGHT = 768;
    const int SCREEN_BPP = 32;

    // initialize SDL video
    if ( SDL_Init( SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER ) < 0 )
    {
        printf( "Unable to init SDL: %s\n", SDL_GetError() );
        return 1;
    }

    // make sure SDL cleans up before exit
    atexit(SDL_Quit);

    // create a new window
    SDL_Surface* screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_HWSURFACE|SDL_DOUBLEBUF);
    if ( !screen )
    {
        printf("Unable to set %d x %d video: %s\n", SCREEN_WIDTH , SCREEN_HEIGHT , SDL_GetError());
        return 1;
    }

    // load an image
    SDL_Surface* background = SDL_LoadBMP("img/bkgrd.bmp");
    if (!background)
    {
        printf("Unable to load bitmap: %s\n", SDL_GetError());
        return 1;
    }
    SDL_Surface* logo = SDL_LoadBMP("img/logo.bmp");
    if (!logo)
    {
        printf("Unable to load bitmap: %s\n", SDL_GetError());
        return 1;
    }

    // centre the bitmap on screen
    SDL_Rect dstrect;
    dstrect.x = (screen->w - background->w) / 2;
    dstrect.y = (screen->h - background->h) / 2;

    SDL_Rect dstlogo;
    dstlogo.x = (screen->w - logo->w ) /2;
    dstlogo.y = (screen->h - logo->h ) /2;

    //Initialisation de SDL_TTF
    if ( TTF_Init() == -1 )
    {
        return false;
    }

    // program main loop
    bool done = false;
    while (!done)
    {
        // message processing loop
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            // check for messages
            switch (event.type)
            {
                // exit if the window is closed
            case SDL_QUIT:
                done = true;
                break;

                // check for keypresses
            case SDL_KEYDOWN:
                // exit if ESCAPE is pressed
                if (event.key.keysym.sym == SDLK_ESCAPE)
                    done = true;

                if (event.key.keysym.sym == SDLK_LEFT)
                {
                    //La surface du message
                    SDL_Surface *message = NULL;

                    //Le Font qu'on va utiliser
                    TTF_Font *font;

                    //La couleur du Font
                    SDL_Color textColor = { 255, 255, 255,0};

                    //Ouverture du Font
                    font = TTF_OpenFont( "./fonts/TlwgTypeWriter.ttf", 28 ); //attention mettre le dossier fonts DANS bin ou obj
                    //S'il y a une erreur dans le chargement du Font
                    if ( font == NULL )
                    {
                        printf("font == null\n");
                        return false;
                    }

                    //Mise en place du texte sur la surface message
                    message = TTF_RenderText_Solid( font, "Test pour sdl_ttf", textColor );

                    //S'il y a une erreur dans la mise en place du texte
                    if ( message == NULL )
                    {
                        printf("message == null\n");
                        return 1;
                    }

                    //Application de la surface du message
                    apply_surface( 0, 200, message, screen );

                    SDL_FreeSurface( message );

                    //Fermeture des Fonts qu'on a utilisé
                    TTF_CloseFont( font );

                } //end ENTER
                break;
            } // end switch
        } // end of message processing

        // DRAWING STARTS HERE

        // clear screen
        SDL_FillRect(screen, 0, SDL_MapRGB(screen->format, 0, 0, 0));

        // draw bitmap
        SDL_BlitSurface(background, 0, screen, &dstrect);
        SDL_BlitSurface(logo, 0, screen, &dstlogo);

        // DRAWING ENDS HERE

        // finally, update the screen :)
        SDL_Flip(screen);
    } // end main loop

    // free loaded bitmap
    SDL_FreeSurface(background);
    SDL_FreeSurface(logo);



    //On quitte SDL_ttf
    TTF_Quit();

    // all is well ;)
    printf("Exited cleanly\n");


*/
    return 0;
}

// INITIALISATION DE L'AFFICHAGE, DU SON & DES PERIPHERIQUES DE CONTROLE

//INTRO :
// Logo lifesevenpoker , petit jingle ...

//AFFICHAGE DU MENU PRINCIPAL:
//UN JOUEUR
//MULTIJOUEURS
//OPTIONS
//CREDITS
//QUITTER

// + musique ambiance ? sons particuliers sur clicks ?


//=> UN JOUEUR
// Fait démarrer une nouvelle partie contre IA.
// REGLAGES PREALABLES : Nombre IA, difficulté IA. Argent de départ. Peut etre d'autres options liées aux regles ??

//=> MULTIJOUEUR
// Formulaire pour Creer/rejoindre une partie. Par IP a priori ... détails multijoueurs à voir plus tard ... optionnel.

//=> OPTIONS
//Pouvoir modifier la résolution d'affichage, les raccourcis clavier, niveau sonore musique/effets
//  /!\ Utilisation d'un fichier de configuration externe ??? A voir.
//=> CREDITS
//Affichage des credits mode déroulement ou autre. A priori assez simple.

//=> QUITTER
//Destruction de tout ce qui est chargé en mémoire.
//Fermeture de tous les systemes propre.
//Fermeture Fenetre.




/* MODE UN JOUEUR:


    BOUCLE DE BASE :

        INITIALISATION DE TOUTES LES DONNEES NECESSAIRE A L'AFFICHAGE
        AFFICHAGE MESSAGE BIENVENUE / DEBUT DE PARTIE

        AFFICHAGE TABLE DE JEU
            basique => tapis vert type solitaire windows
                noms et argent des joueurs

        GENERATION DE LA PILE DE CARTES

        ATTRIBUTION DES ROLES SELON PLACES :
                    - DEALER
                    - PETITE BLIND
                    - GROSSE BLIND
                    - JOUEUR

        DISTRIBUTION DES CARTES AUX JOUEURS
            deux cartes à chaque joueur
                animation ? pourquoi pas
            pas de carte au milieu

        PREMIERE PHASE DE MISES:
            Cycle : pour chaque joueur demande de mise
                        prise en compte des blinds
                        possibilité de se coucher
                    continue tant que les mises sont pas finies, plusieurs tours de table possibles

        FLOP:
            3 cartes découvertes au milieu
            possibilité de se coucher

        DEUXIEME PHASE DE MISES:
            Cycle : idem

        TURN:
            4e carte découverte au milieu

        TROISIEME PHASE DE MISES:
            Cycle ...

        RIVER
            5e carte découverte au milieu

        DERNIERE PHASE DE MISES:
            Cycle ...



            Résolution des mains
            Determiner gagnant(s)
            Attribuer gains
            Sit out si plus d'argent

        REINITIALISATION PILE/MAINS

        RETOUR DEBUT DU CYCLE


        //!\\ A TOUT MOMENT : POSSIBILITE DE : SIT OUT, FOLD, QUIT, (ACCES OPTIONS).


    */

//MODE MULTIJOUEUR ASSEZ SIMILAIRE


//GESTION DE L'IA ET DES AUTRES JOUEURS ENCORE A DETERMINER



