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
#include "Langage.h"
//#include "AfficheTxt.h"



//Librairies SDL.
#include <SDL/SDL.h>
#include <SDL/SDL_image.h> //Gestion des images.
#include <SDL/SDL_ttf.h> //Gestion des polices True Type Fonts.
#include <SDL/SDL_rotozoom.h> //traitement de surface
//#include <SDL/SDL_mixer.h> //Gestion du multi channeling audio.


int main (/*int argc, char** argv */)
{
    char configuration[50][50];
    ecrireDansTableau(configuration,"config");
    char langue[50][50];
    int nombreJoueur=3;
	int argentDepart=1000;
	const char* nomJoueur="moi";
    switch (configuration[0][0])
    {
    case 'f':
        ecrireDansTableau(langue,"languages/french");
        break;
    case 'e':
        ecrireDansTableau(langue,"languages/english");
        break;
    }
    //on cherche le nombre de joueur
    sscanf(configuration[1],"%d",&nombreJoueur);
    sscanf(configuration[2],"%d",&argentDepart);
    assert(nombreJoueur<=8);

    //on recupere le nom du joueur local
    nomJoueur=configuration[3];


    SDL_Surface* affichage;
    const char* caption="Life\'Seven Poker";

    if (initSDL(affichage,1024,768,32,caption)!=0)
    {
        return 1;
    }

    atexit(clean_up);

    //Chargement des fichiers
    const char* backgroundP="img/bkgrd.jpg";
    SDL_Surface* tapis=load_image(backgroundP);






//    SDL_Event event;




    AffStartUp(affichage,tapis);
    AffAfficheTapis(affichage,tapis);
    SDL_Flip(affichage);
    bool nouvellePartie=true;
    int v;//valleur que renvoit lancerPartie
    int aM;//valeur que renvoit affMenu
    bool finPartie=true;

    while (finPartie)
    {
        finPartie=false;
        nouvellePartie=true;
        aM=AffMenu(affichage,langue);
        if (aM==1)
        {

            while (nouvellePartie)
            {
                nouvellePartie=false;
                AffAfficheTapis(affichage,tapis);
                SDL_Flip(affichage);
                nouvellePartie = 0;
                v=lancePartie(affichage,tapis,langue,nombreJoueur,argentDepart,nomJoueur);
                if (v==1)
                {
                    nouvellePartie=true;
                }
                else if (v==4)
                {
                    nouvellePartie=false;
                    finPartie=true;
                }
            }

        }
        else if (aM==2)
        {
            printf("\n----------------\n");
            printf("Develope par:\nJames DAVIS\nBenjamin GUILLON\nTristan ROLLET\nOlivier DELYS\n");
            printf("----------------\n\n");
            nouvellePartie=false;
            finPartie=true;
        }

    }






    SDL_FreeSurface(tapis);
    SDL_FreeSurface(affichage);
    clean_up();

    return 0;
}

