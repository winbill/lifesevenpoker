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
#include "Joueur.h"
#include "Table.h"
#include "IArtificielle.h"
//#include "AfficheTxt.h"



//Librairies SDL.
#include <SDL/SDL.h>
#include <SDL/SDL_image.h> //Gestion des images.
#include <SDL/SDL_ttf.h> //Gestion des polices True Type Fonts.
#include <SDL/SDL_rotozoom.h> //traitement de surface
//#include <SDL/SDL_mixer.h> //Gestion du multi channeling audio.


int main (/*int argc, char** argv */)
{



    SDL_Surface* affichage;
    path caption="Life\'Seven Poker";

    if(initSDL(affichage,1024,768,32,caption)!=0)
    {
        return 1;
    }

    atexit(SDL_Quit);

    //Chargement des fichiers
    path backgroundP="img/bkgrd.jpg";
    SDL_Surface* tapis=load_image(backgroundP);






//    SDL_Event event;




    AffStartUp(affichage,tapis);
    AffAfficheTapis(affichage,tapis);
    SDL_Flip(affichage);
    int nouvellePartie=1;
    int v;

    if(AffMenu(affichage)==1)
    {

        while(nouvellePartie)
        {
            AffAfficheTapis(affichage,tapis);
            SDL_Flip(affichage);
            nouvellePartie = 0;
            v=lancePartie(affichage,tapis);
            if(v==1)
                nouvellePartie=1;
        }

    }
    else if(AffMenu(affichage)==2)
    {
        //AFFICHER CREDITS
        printf("AFFICHER CREDITS");
    }













    SDL_FreeSurface(tapis);
    SDL_FreeSurface(affichage);
    SDL_Quit();

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



