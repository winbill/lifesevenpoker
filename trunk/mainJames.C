//Librairies Life'Seven Poker
#include "PileCarte.h"
#include "Table.h"
#include "Joueur.h"
#include "Jeu.h"
#include "AfficheTxt.h"

//Librairies Standard.
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <cassert>

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
    PileCarte p;
    Table t;
    initTable(t);
    initPileCarte(p);
    t.pileCarte = &p;
    Joueur* j1;


    setMaxJoueurTable(t,6);
    j1 = creeJoueur();
    initJoueur(*j1,"j1");




    ajoutJoueurTable(t,j1);



    j1->statut=RAISE;



   afficheInfoJoueur(*j1);


    afficheInfoTable(t);


    distribuer2CartesJoueursJeu(t);
    distribuer1CarteDecouverteJeu(t,5);





    afficheMainCarte(*t.carteDecouverte,"table");
    afficheMainCarte(*getMainJoueur(*j1),"main de j1");
    //afficheMainCarte(*getMainJoueur(*j2),"main de j2");
    //afficheMainCarte(*getMainJoueur(*j3),"main de j3");
    //afficheMainCarte(*getMainJoueur(j4),"main de j4");
    //setCarte(getMainCarteIemeCarte(*getMainJoueur(j),0),12,3)


/*
    int  tabResultat[6][2];
    assert(codageScoreMain(*getMainJoueur(*j1), tabResultat,t));
    afficheTab2(tabResultat,6);
*/


    int tabResultat[10][6][2];




    intitialiseTab3d(tabResultat);
    jeuDetermineVainqueur(t,tabResultat);
    trieTab3d(tabResultat);
    afficheTab3(tabResultat,10);



    joueurDetruit(j1);


    pileCarteLibere(p);
    tableLibere(t);

/*
    int tabMainTotale[8][2];
    tabMainTotale[0][0] = 9;
    tabMainTotale[0][1] = 3;

    tabMainTotale[1][0] = 12;
    tabMainTotale[1][1] = 1;

    tabMainTotale[2][0] = 13;
    tabMainTotale[2][1] = 1;

    tabMainTotale[3][0] = 10;
    tabMainTotale[3][1] = 1;

    tabMainTotale[4][0] = 12;
    tabMainTotale[4][1] = 3;

    tabMainTotale[5][0] = 2;
    tabMainTotale[5][1] = 1;

    tabMainTotale[6][0] = 3;
    tabMainTotale[6][1] = 1;


    trieTableauRang(tabMainTotale);
    printf("------------------------\n");
    int couleur = couleurMainCarte(tabMainTotale);
    printf("couleur? : %d\n",couleur);
    printf("------------------------\n");
    printf("suite? : %d\n",suiteMainCarte(tabMainTotale));
    printf("------------------------\n");
    printf("quinte flush? : %d\n",quinteFlushMainCarte(tabMainTotale,couleur));
    printf("------Tab main trie-----\n");
    afficheTab2(tabMainTotale,9);


    int tabO[15];
    int tabResultat[10][2];

    nombreOcurenceCarte(tabMainTotale,tabO);




    choixCarteMultiple(tabMainTotale,tabO,tabResultat);
    printf("-----Tableau Resultat----\n");

    afficheTab2(tabResultat,6);
*/
        return 0;



}
/*







    */
