//Librairies Life'Seven Poker
//#include "Jeu.h"
#include "PileCarte.h"
#include "Table.h"
#include "Joueur.h"
#include "Jeu.h"

//Librairies Standard.
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "AfficheTxt.h"
//Librairies SDL.
#include <SDL/SDL.h>
#include <SDL/SDL_image.h> //Gestion des images.
#include <SDL/SDL_ttf.h> //Gestion des polices True Type Fonts.
#include <SDL/SDL_mixer.h> //Gestion du multi channeling audio.

#ifdef __cplusplus
    #include <cstdlib>
#else
    #include <stdlib.h>
#endif
#include <SDL/SDL.h>

int main ( /*int argc, char** argv */ )
{
    PileCarte p;Table t;
    initTable(t);
    initPileCarte(p);
    t.pileCarte = &p;
    Joueur* j1;
    Joueur* j2;
    Joueur* j3;
    Joueur j4;

    setMaxJoueurTable(t,6);
    j1 = creeJoueur();initJoueur(*j1,"j1");
    j2 = creeJoueur();initJoueur(*j2,"j2");
    j3 = creeJoueur();initJoueur(*j3,"j3");
    initJoueur(j4,"j4");



    ajoutJoueurTable(t,j1);
    ajoutJoueurTable(t,j2);
    ajoutJoueurTable(t,j3);


    afficheInfoTable(t);

    afficheInfoJoueur(*j1);
    afficheInfoJoueur(*j2);
    afficheInfoJoueur(*j3);


    supprimeJoueurTable(t,j1);

    //ajoutJoueurTable(t,&j4);


    afficheInfoJoueur(*j1);
    afficheInfoJoueur(*j2);
    afficheInfoJoueur(*j3);
    afficheInfoJoueur(j4);

    afficheInfoTable(t);

    distribuer2CartesJoueursJeu(t);



    afficheMainCarte(*getMainJoueur(*j1),"main de j1");
    afficheMainCarte(*getMainJoueur(*j2),"main de j2");
    afficheMainCarte(*getMainJoueur(*j3),"main de j3");
    afficheMainCarte(*getMainJoueur(j4),"main de j4");

    joueurDetruit(j1);
    joueurDetruit(j2);
    joueurDetruit(j3);
    joueurLibere(j4);







    pileCarteLibere(p);
    tableLibere(t);

    return 0;
}
