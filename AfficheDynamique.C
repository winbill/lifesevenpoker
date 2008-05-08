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
#include "AfficheTxt.h"


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
    if ( SDL_Init( SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER ) == -1 )
    {
        printf("Impossible d\'initialiser les sous-systèmes de SDL.\n");
        return -1;
    }

    //Mise en place de l'écran
    screen = SDL_SetVideoMode( screen_width, screen_height, screen_bpp, SDL_HWSURFACE|SDL_RESIZABLE|SDL_DOUBLEBUF );

    //S'il y a une erreur dans la mise en place de l'écran
    if ( screen == NULL )
    {
        printf("Echec de la mise en place de l\'ecran.\n");
        return -1;
    }

    //Initialisation de SDL_TTF
    if ( TTF_Init() == -1 )
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
    if ((loadedImage = IMG_Load(filename)) == 0)
    {
        printf("Impossible de charger l\'image.\n");
    }

    //Si le chargement se passe bien
    if ( loadedImage != NULL )
    {
        //Création de l'image optimisée
        if ((optimizedImage = SDL_DisplayFormatAlpha( loadedImage )) == 0)
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
    switch (option)
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
    SDL_Delay(200);
    SDL_FreeSurface(logo);

}

void AffAfficheTexte(SDL_Surface* destination,char* message,int x,int y,int r,int g,int b)
{
    AffAfficheTexte(destination,message,x,y,r,g,b,TTF_STYLE_NORMAL,28);
}

void AffAfficheTexte(SDL_Surface* destination,char* message,int x,int y,int r,int g,int b,int style,int size)
{


    //La surface où on va coller le message
    SDL_Surface* texte;
    //Le Font qu'on va utiliser
    TTF_Font *font;

    //La couleur du Font
    SDL_Color textColor = { r, g, b,0};

    //Ouverture du Font
    font = TTF_OpenFont( "./fonts/Qlassik_TB.otf", size );
    TTF_SetFontStyle(font,style);


    //S'il y a une erreur dans le chargement du Font
    if ( font == NULL )
    {
        printf("Erreur de chargement de la font\n");
    }

    //Mise en place du texte sur la surface message
    texte = TTF_RenderText_Blended(font,message,textColor);

    //S'il y a une erreur dans la mise en place du texte
    if ( texte == NULL )
    {
        printf("Erreur de chargement du message\n");
    }

    //Application de la surface du message
    apply_surface(x,y,texte,destination);

    TTF_CloseFont(font);
    SDL_FreeSurface(texte);

}


int AffMenu(SDL_Surface* affichage)
{

    bool fin = false;
    SDL_Event event;
    int colorDestination[5] = {255,255,255,255,255};
    int currentColor[5] = {255,255,255,255,255};
    char* listeChoix;


    path menuP="img/menu.bmp";
    SDL_Surface* menu=load_image(menuP);
    AffAfficheTexte(menu,"Nouvelle partie",50,240,255/10,255,255);
    AffAfficheTexte(menu,"Credits",50,270,255/10,255,255);
    AffAfficheTexte(menu,"Quitter",50,300,255/10,255,255);
    SDL_Rect menuRect = AffCentrer(menu,affichage,0);
    apply_surface(menuRect.x,menuRect.y,menu,affichage);
    SDL_Flip(affichage);




    while (fin!=true)
    {
        SDL_PollEvent(&event);

        switch (event.type)
        {
        case SDL_QUIT :
            fin=true;
            break;

        case SDL_KEYDOWN :
            if (event.key.keysym.sym == SDLK_ESCAPE)
            {
                SDL_FreeSurface(menu);
                return 0;
            }
            break;
        case SDL_MOUSEBUTTONUP :
            for (int i=0;i<3;i++)
            {
                if (event.button.button == SDL_BUTTON_LEFT && event.button.x >= menuRect.x && event.button.x <= menu->w + menuRect.x && event.button.y >= 240+i*30+menuRect.y && event.button.y <= 268+i*30+menuRect.y)
                {
                    SDL_FreeSurface(menu);
                    return i+1;
                }
            }
            break;
        case SDL_MOUSEMOTION:
            for (int i=0;i<3;i++)
            {
                if (event.motion.x >= menuRect.x && event.motion.x <= menu->w + menuRect.x && event.motion.y >= 240+i*30+menuRect.y && event.motion.y <= 268+i*30+menuRect.y)
                {
                    colorDestination[i] = 0;
                }
                else
                {
                    colorDestination[i] = 255;
                }
            }
            break;

        }
        for (int i=0;i<3;i++)
        {
            if (colorDestination[i] != currentColor[i])
            {
                if (colorDestination[i]>currentColor[i])
                {
                    currentColor[i]+=20;
                    if (currentColor[i]>255)
                        currentColor[i]=255;
                }
                else
                {
                    currentColor[i]-=20;
                    if (currentColor[i]<0)
                        currentColor[i]=0;
                }
                switch (i)
                {
                case 0:
                    listeChoix = "Nouvelle partie";
                    break;
                case 1:
                    listeChoix = "Credits";
                    break;
                case 2:
                    listeChoix = "Quitter";
                    break;
                }

                AffAfficheTexte(menu,listeChoix,50,240+i*30,currentColor[i]/10,currentColor[i],currentColor[i]);
                SDL_Rect menuRect = AffCentrer(menu,affichage,0);
                apply_surface(menuRect.x,menuRect.y,menu,affichage);
                SDL_Flip(affichage);
            }
        }

    }
    SDL_FreeSurface(menu);
    return 0;
}


void AffAfficheCredits(SDL_Surface* affichage)
{
    bool fin=false;
    SDL_Event event;

    AffEffaceEcran(affichage);

    path creditsP="img/credits.jpg";
    SDL_Surface* credits = load_image(creditsP);
    SDL_Rect creditsRect = AffCentrer(credits,affichage,0);
    apply_surface(creditsRect.x,creditsRect.y,credits,affichage);
    SDL_Flip(affichage);


    while (!fin)
    {
        SDL_PollEvent(&event);

        if (event.type == SDL_KEYDOWN)
        {
            if (event.key.keysym.sym == SDLK_m)
            {
                AffMenu(affichage);
                fin=true;
            }
        }
    }

    SDL_FreeSurface(credits);
}


void AffAfficheCarte(SDL_Surface* affichage, Carte* c, int x, int y, double zoom)
{
    SDL_Surface* carte;
    if (c== NULL)
        carte=load_image("img/doscarte.jpg");
    else
        carte=load_image(c->nomFichier);

    apply_surface(x,y,rotozoomSurface(carte, 0, zoom, 1),affichage);
    SDL_FreeSurface(carte);
}



void AffAfficheJoueur(SDL_Surface* affichage,const Joueur & j,const Table & table,int joueurJouant)
{
    int posx = getPositionJoueurX(j);
    int posy = getPositionJoueurY(j);
    char message[30];
    TTF_Font *font;
    int h,w1,w2,w3;

    sprintf(message,"%s",j.pseudo);
    font = TTF_OpenFont( "./fonts/Qlassik_TB.otf", 22 );
    TTF_SizeText(font,message,&w1,&h);

    if (getIdJoueur(j) != joueurJouant)
    {
        AffAfficheTexte(affichage,message,posx,posy+30*0,255,255,255,TTF_STYLE_NORMAL,22);
    }
    else
    {
        AffAfficheTexte(affichage,message,posx,posy+30*0,255,0,0,TTF_STYLE_NORMAL,22);
    }


    switch (j.statut)
    {
    case SIT:
        sprintf(message,"assis");
        break;
    case CALL:
        sprintf(message,"mise");
        break;
    case CHECK:
        sprintf(message,"check");
        break;
    case RAISE:
        sprintf(message,"relance");
        break;
    case FOLD:
        sprintf(message,"couché");
        break;
    case ALL_IN:
        sprintf(message,"tapis");
        break;
    default:
        sprintf(message,"aa");
        break;
    }


    font = TTF_OpenFont( "./fonts/Qlassik_TB.otf", 18 );



    AffAfficheTexte(affichage,message,posx,posy+20*1,255,255,255,TTF_STYLE_NORMAL,18);

    sprintf(message,"%d",j.argent);
    TTF_SizeText(font,message,&w2,&h);

    AffAfficheTexte(affichage,message,posx+w1-w2,posy+20*1,255,255,255,TTF_STYLE_NORMAL,18);


    sprintf(message,"Mise :");
    AffAfficheTexte(affichage,message,posx,posy+20*2+91,255,255,255,TTF_STYLE_NORMAL,18);

    sprintf(message,"%d",j.mise);
    TTF_SizeText(font,message,&w3,&h);


    AffAfficheTexte(affichage,message,posx+w1-w3,posy+20*2+91,255,255,255,TTF_STYLE_NORMAL,18);


    if (j.idJoueur == getPositionDealerTable(table))
    {
        sprintf(message,"Dealer");
        AffAfficheTexte(affichage,message,posx,posy+91+20*3,255,0,0,TTF_STYLE_BOLD,20);
    }
}

void AffAffichageInfosJoueurs(SDL_Surface* affichage,const Table & t,int joueurJouant)
{
    const int LARGEUR=200;

    int i;
    int a =getMaxJoueurTable(t)-1;
    int g=0;
    int h=0;
    int d=0;

    switch (a)
    {
    case 1:
        h=1;
        break;
    case 2:
        h=2;
        break;
    case 3:
        h=1;
        d=1;
        g=1;
        break;
    case 4:
        h=2;
        d=1;
        g=1;
        break;
    case 5:
        h=3;
        d=1;
        g=1;
        break;
    case 6:
        h=2;
        d=2;
        g=2;
        break;
    case 7:
        h=3;
        d=2;
        g=2;
        break;
    }
    int bordure = 12;
    int separation;
    if (h!=1)
    {
        separation = (int)(((1024-h*LARGEUR)/(h+1)));
    }
    else
    {
        separation = (int)(1024-LARGEUR)/2;
    }

    for (i=0;i<d;i++)
    {
        setPositionJoueurX(*t.joueur[(d-1)-i],bordure);
        setPositionJoueurY(*t.joueur[(d-1)-i],200+200*i);
        AffAfficheJoueur(affichage,*t.joueur[(d-1)-i],t,joueurJouant);
    }
    for (i=d;i<h+d;i++)
    {
        setPositionJoueurX(*t.joueur[i],bordure+separation*(i-d+1)+LARGEUR*(i-d));
        setPositionJoueurY(*t.joueur[i],bordure);
        AffAfficheJoueur(affichage,*t.joueur[i],t,joueurJouant);
    }
    for (i=h+d;i<g+h+d;i++)
    {
        setPositionJoueurX(*t.joueur[i],862);
        setPositionJoueurY(*t.joueur[i],200+200*(i-h-d));
        AffAfficheJoueur(affichage,*t.joueur[i],t,joueurJouant);
    }
}

/*

      1  SIT_OUT
      2  SIT,
      3  CALL,
      4  CHECK,
      5  RAISE,
      6  FOLD,
      7  ALL_IN,

*/


void AffCartesJoueursJeu(SDL_Surface* affichage,const Table & t)
{

    int i = 0;
    while ( getIemeJoueur(t,i) != NULL)
    {
        const int largeurCarte = 189;
        const int hauteurCarte = 260;

        int x;
        int y;
        int j;
        if ( getTypeJoueur( *getIemeJoueur(t,i)) == JoueurLocal)
        {
            for (j=0;j<2;j++)
            {
                int ecart =-30;
                x = (1024 - 2*largeurCarte -ecart)/2+j*(largeurCarte+ecart)-100;
                y = 768 - hauteurCarte - ecart;
                AffAfficheCarte(affichage,getMainCarteIemeCarte(*getMainJoueur(*getIemeJoueur(t,i)),j),x,y+15,0.8);
            }
        }
        else
        {
            assert(getTypeJoueur( *getIemeJoueur(t,i)) != 1);

            for (j=0;j<2;j++)
            {
                x= getPositionJoueurX(*t.joueur[i]);
                y= getPositionJoueurY(*t.joueur[i]);

                AffAfficheCarte(affichage, NULL,x+j*20+3,y+40,0.35);
            }
        }

        i++;
    }
}

void AffCarteDecouvertes(const Table & t,SDL_Surface* affichage)
{
    int i;
    for (i=0;i<getMainCarteNbCarte(*(t.carteDecouverte));i++)
    {
        AffAfficheCarte(affichage,getMainCarteIemeCarte(*(t.carteDecouverte),i),(113+5)*(i)+210,250,0.6);
    }



}

void AffInfosJoueur(SDL_Surface* affichage,const Joueur &j,const Table & table)
{
    char message[30];
    sprintf(message,"%s",j.pseudo);


    AffAfficheTexte(affichage,message,620,530+20*0,255,255,255,TTF_STYLE_UNDERLINE,22);


    switch (j.statut)
    {
    case SIT:
        sprintf(message,"assis");
        break;
    case CALL:
        sprintf(message,"mise");
        break;
    case CHECK:
        sprintf(message,"check");
        break;
    case RAISE:
        sprintf(message,"relance");
        break;
    case FOLD:
        sprintf(message,"couché");
        break;
    case ALL_IN:
        sprintf(message,"tapis");
        break;
    default:
        sprintf(message,"aa");
        break;
    }

    AffAfficheTexte(affichage,message,620,530+20*1,255,255,255,TTF_STYLE_NORMAL,18);

    sprintf(message,"%d",j.argent);
    AffAfficheTexte(affichage,message,620+50,530+20*1,255,255,255,TTF_STYLE_NORMAL,18);


    sprintf(message,"Mise actuelle: %d",j.mise);
    AffAfficheTexte(affichage,message,620,530+20*2,255,255,255,TTF_STYLE_NORMAL,18);

    if (j.idJoueur == getPositionDealerTable(table))
    {
        sprintf(message,"Dealer");
        AffAfficheTexte(affichage,message,620,530+20*3,255,0,0,TTF_STYLE_BOLD,20);
    }

}



int lancePartie(SDL_Surface* affichage)
{
    const int NOMBRE_JOUEUR_PC = 4;
    const int ARGENT_DEPART = 1000;
    Table t;
    PileCarte p;
    double zoom = 1;

    initTable(t);
    initPileCarte(p);

    setMaxJoueurTable(t,NOMBRE_JOUEUR_PC+1);

    t.pileCarte = &p;
    char nom[20];

    Joueur* player;
    Joueur* joueurs[10];

    for (int i=0;i<NOMBRE_JOUEUR_PC;i++)
    {
        sprintf(nom,"%s%d%s","Ordinateur",i,"  ");
        joueurs[i]=creeJoueur();
        initJoueur(*joueurs[i],nom);
        ajoutJoueurTable(t,joueurs[i]);
        setTypeJoueur(*joueurs[i],IA);
        setArgentJoueur(*joueurs[i],ARGENT_DEPART);

    }


    player=creeJoueur();
    initJoueur(*player,"moi");
    setStatutJoueur(*player,SIT);
    setTypeJoueur(*player,JoueurLocal);
    setArgentJoueur(*player,ARGENT_DEPART);
    ajoutJoueurTable(t,player);



    SDL_Event event;
    bool gameOn=true;
    printf("lance jeu\n");
    int renvoyer=0;
    int joueurJouant = 0;


    distribuer2CartesJoueursJeu(t);
    distribuer1CarteDecouverteJeu(t,5);

    AffEffaceEcran(affichage);
    AffAffichageInfosJoueurs(affichage,t,joueurJouant);

    AffCarteDecouvertes(t,affichage);
    AffCartesJoueursJeu(affichage,t);
    AffInfosJoueur(affichage,*player,t);
    AffAffichageInfosJoueurs(affichage,t,joueurJouant);


    SDL_Flip(affichage);
    while (gameOn)
    {


        SDL_PollEvent(&event);

        switch (event.type)
        {
        case SDL_QUIT:
            gameOn = false;
            renvoyer=3;
            break;
        case SDL_VIDEORESIZE:


            zoom = (double)event.resize.w/1024;
            affichage = SDL_SetVideoMode( event.resize.w, event.resize.h, 32, SDL_HWSURFACE|SDL_RESIZABLE|SDL_DOUBLEBUF );
            AffEffaceEcran(affichage);
            AffCartesJoueursJeu(affichage,t);
            AffAffichageInfosJoueurs(affichage,t,joueurJouant);
            apply_surface(0,0,rotozoomSurface(affichage,0,zoom,0),affichage);
            SDL_Flip(affichage);
            break;


        case SDL_KEYDOWN :
            switch (event.key.keysym.sym)
            {
            case SDLK_ESCAPE:
                gameOn = false;
                renvoyer=3;
                break;
            case SDLK_m:
                switch (AffMenu(affichage))
                {
                case 1:
                    gameOn = false;
                    renvoyer=1;
                    break;
                case 3:
                    gameOn = false;
                    renvoyer=3;
                    break;
                case 0:

                    AffEffaceEcran(affichage);
                    AffCartesJoueursJeu(affichage,t);
                    AffCarteDecouvertes(t,affichage);
                    AffAffichageInfosJoueurs(affichage,t,joueurJouant);
                    AffInfosJoueur(affichage,*player,t);
                    if (zoom != 1)
                    {
                        apply_surface(0,0,rotozoomSurface(affichage,0,zoom,0),affichage);
                                  }
                                  SDL_Flip(affichage);
                    break;
                }
                break;
            default:
                break;
            }
            break;
        }
    }

    for (int i=0;i<NOMBRE_JOUEUR_PC;i++)
    {
        joueurDetruit(joueurs[i]);
        joueurs[i]=NULL;
    }


    joueurDetruit(player);

    pileCarteLibere(p);
    tableLibere(t);


    return renvoyer;

}
