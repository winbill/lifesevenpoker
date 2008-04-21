//Librairies Life'Seven Poker
#include "Jeu.h"


//Librairies Standard.
#include <stdlib.h>
#include <stdio.h>

//Librairies SDL.
#include <SDL/SDL.h>
#include "SDL/SDL_image.h" //Gestion des images.
#include "SDL/SDL_ttf.h" //Gestion des polices True Type Fonts.
#include "SDL/SDL_mixer.h" //Gestion du multi channeling audio.

int main( int argc, char *argv[ ] )
{
    //Les attributs de notre écran
    const int SCREEN_WIDTH = 640;
    const int SCREEN_HEIGHT = 480;
    const int SCREEN_BPP = 32;

    //Les attributs temporels
    const int STD_DELAY_TIME = 3000;

    //Les elements de surface
    SDL_Surface *screen;


    //Initialisation des systemes
    if( SDL_Init( SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER ) == -1 )
    {
        printf( "Can't init SDL:  %s\n", SDL_GetError( ) );
        return EXIT_FAILURE;
    }

    //Si l'utilisateur ferme l'application
    atexit( SDL_Quit );

    screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_HWSURFACE );

    if( screen == NULL )
    {
        printf( "Can't set video mode: %s\n", SDL_GetError( ) );
        return EXIT_FAILURE;
    }

    SDL_Delay( STD_DELAY_TIME );

    return EXIT_SUCCESS;
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






    return 0;
}
