//Librairies Life'Seven Poker
//#include "Jeu.h"
#include "PileCarte.h"
#include "Table.h"
#include "Joueur.h"


//Librairies Standard.
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

//Librairies SDL.
#include <SDL/SDL.h>
#include <SDL/SDL_image.h> //Gestion des images.
#include <SDL/SDL_ttf.h> //Gestion des polices True Type Fonts.
//#include <SDL/SDL_mixer.h> //Gestion du multi channeling audio.

#ifdef __cplusplus
    #include <cstdlib>
#else
    #include <stdlib.h>
#endif
#include <SDL/SDL.h>

int main ( /*int argc, char** argv */ )
{
    /*// screen attributes
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
    SDL_Surface* bmp = SDL_LoadBMP("cb.bmp");
    if (!bmp)
    {
        printf("Unable to load bitmap: %s\n", SDL_GetError());
        return 1;
    }

    // centre the bitmap on screen
    SDL_Rect dstrect;
    dstrect.x = (screen->w - bmp->w) / 2;
    dstrect.y = (screen->h - bmp->h) / 2;

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
                {
                    // exit if ESCAPE is pressed
                    if (event.key.keysym.sym == SDLK_ESCAPE)
                        done = true;
                    break;
                }
            } // end switch
        } // end of message processing

        // DRAWING STARTS HERE

        // clear screen
        SDL_FillRect(screen, 0, SDL_MapRGB(screen->format, 0, 0, 0));

        // draw bitmap
        SDL_BlitSurface(bmp, 0, screen, &dstrect);

        // DRAWING ENDS HERE

        // finally, update the screen :)
        SDL_Flip(screen);
    } // end main loop

    // free loaded bitmap
    SDL_FreeSurface(bmp);

    // all is well ;)
    printf("Exited cleanly\n");

    */

    //srand (time (0));
    PileCarte p;
    Table t;

    initTable(t);

    initPileCarte(p);
    Carte* carte=tirerCarte(p);
    printf("taille pile Carte : %d \n",p.taille);
    printf("rang : %d \n", getCarteRang(*carte));
    printf("couleur : %d \n", getCarteCouleur(*carte));

    Joueur j1;


    //ajouteCarte(*getMainJoueur(*getIemeJoueur(table,i)),*tirerCarte(*getTablePileCarteTable(table)));


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



