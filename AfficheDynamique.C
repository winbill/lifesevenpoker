/**
	@brief Fichier C pour l'affichage dynamique


	Gere l'affichage dynamique en utilisant le moteur de rendu SDL (Simple Directmedia Layer).

	@author  James Benjamin
	@file AfficheDynamique.C
	@version 1.2
	@date 2008/04/21
 */


#include "AfficheDynamique.h"


void affAffichageVainqueur(SDL_Surface* affichage,const Table & t)
{
    int tabResultat[10][6][2];

    if (fonctionGlobaleDetrminationVainqueur(t,tabResultat)==0)
    {
        char message[30];
        AffCartesJoueursJeu(affichage,t,false);
        AffCarteDecouvertes(t,affichage,true,tabResultat[0]);
        AffCartesJoueursJeuFinale(affichage,t,tabResultat[0],tabResultat[0][0][1]);


        SDL_Flip(affichage);
        printf("vainqueur:%s\n",(*getIemeJoueur(t,tabResultat[0][0][1])).pseudo);



        switch (tabResultat[0][0][0])
        {
        case 0:
            sprintf(message,"Carte haute");
            break;
        case 1:
            sprintf(message,"Paire");
            break;
        case 2:
            sprintf(message,"Double paire");
            break;
        case 3:
            sprintf(message,"Brelan");
            break;
        case 4:
            sprintf(message,"Quinte");
            break;
        case 5:
            sprintf(message,"Couleur");
            break;
        case 6:
            sprintf(message,"Full");
            break;
        case 7:
            sprintf(message,"Carre");
            break;
        case 8:
            sprintf(message,"Quinte Flush");
            break;
        default:
            sprintf(message,"ERREUR DETERMINATION FORME MAIN");
            break;

        }
        printf("Forme:%s\n",message);
        SDL_Delay(400000);
    }


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




void AffStartUp(SDL_Surface* affichage,SDL_Surface* tapis)
{
    path logoP="img/logo.png";
    SDL_Surface* logo=load_image(logoP);
    AffAfficheTapis(affichage,tapis);
    SDL_Rect logoRect=AffCentrer(logo,affichage,0);
    SDL_SetAlpha(logo, SDL_SRCALPHA, 128);
    apply_surface(logoRect.x,logoRect.y,logo,affichage);
    SDL_Flip(affichage);
    SDL_Delay(200);
    SDL_FreeSurface(logo);

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

/*
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

*/




void AffAfficheJoueur(SDL_Surface* affichage,const Joueur & j,const Table & table,int joueurJouant)
{
    int posx = getPositionJoueurX(j);
    int posy = getPositionJoueurY(j);
    char message[30];


    sprintf(message,"%s:%d",j.pseudo,j.argent);


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
    case CALL:
        sprintf(message,"mise : %d",getMiseJoueur(j));
        break;
    case CHECK:
        sprintf(message,"check");
        break;
    case RAISE:
        sprintf(message,"relance : %d",getMiseJoueur(j));
        break;
    case FOLD:
        sprintf(message,"se couche");
        break;
    case ALL_IN:
        sprintf(message,"tapis : %d",getTapisJoueur(j));
        break;
    default:
        sprintf(message," ");
        break;
    }



    AffAfficheTexte(affichage,message,posx,posy+20*1+91,255,255,255,TTF_STYLE_NORMAL,18);




    if (j.idJoueur == getPositionDealerTable(table))
    {
        sprintf(message,"Dealer");
        AffAfficheTexte(affichage,message,posx,posy+91+20*2,255,0,0,TTF_STYLE_BOLD,20);
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

    AffCartesJoueursJeu( affichage,t,true);
}

void AffCartesJoueursJeu(SDL_Surface* affichage,const Table & t,bool cache)
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

            if (getStatutJoueur(*getIemeJoueur(t,i)) != FOLD and getStatutJoueur(*getIemeJoueur(t,i)) !=SIT_OUT)
            {
                for (j=0;j<2;j++)
                {
                    x= getPositionJoueurX(*t.joueur[i]);
                    y= getPositionJoueurY(*t.joueur[i]);
                    if (cache)
                    {
                        AffAfficheCarte(affichage,NULL,x+j*20+3,y+20,0.35);
                    }
                    else
                    {
                        AffAfficheCarte(affichage,getMainCarteIemeCarte(*getMainJoueur(*getIemeJoueur(t,i)),j),x+j*20+3,y+20,0.35);
                    }
                }
            }
        }

        i++;
    }
}

void AffCarteDecouvertes(const Table & t,SDL_Surface* affichage)
{
    int tabResultat[6][2];
    AffCarteDecouvertes(t,affichage,false,tabResultat);
}

void AffCarteDecouvertes(const Table & t,SDL_Surface* affichage,bool evidence,int tabResultat[6][2])
{
    int i;
    if (!evidence)
    {
        for (i=0;i<getMainCarteNbCarte(*(t.carteDecouverte));i++)
        {
            AffAfficheCarte(affichage,getMainCarteIemeCarte(*(t.carteDecouverte),i),(113+5)*(i)+210,250,0.6,evidence);
        }
    }
    else
    {
        for (i=0;i<getMainCarteNbCarte(*(t.carteDecouverte));i++)
        {
            int j=1;
            int a=0;
            while (a==0 && j<6)
            {
                if (tabResultat[j][0]==getCarteRang(*getMainCarteIemeCarte(*(t.carteDecouverte),i)) && tabResultat[j][1]==getCarteCouleur(*getMainCarteIemeCarte(*(t.carteDecouverte),i)))
                {
                    a=1;
                    AffAfficheCarte(affichage,getMainCarteIemeCarte(*(t.carteDecouverte),i),(113+5)*(i)+210,250,0.6,evidence);
                }
                j++;
            }
            if (a==0)
                AffAfficheCarte(affichage,getMainCarteIemeCarte(*(t.carteDecouverte),i),(113+5)*(i)+210,250,0.6,false);
        }
    }


}


void AffCartesJoueursJeuFinale(SDL_Surface* affichage,const Table & t,int tabResultat[6][2],int i)
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
            int k=1;
            int a=0;
            while (a==0 && k<6)
            {
                if (tabResultat[k][0]==getCarteRang(*getMainCarteIemeCarte(*getMainJoueur(*getIemeJoueur(t,i)),j)) && tabResultat[k][1]==getCarteCouleur(*getMainCarteIemeCarte(*getMainJoueur(*getIemeJoueur(t,i)),j)))
                {
                    a=1;
                    AffAfficheCarte(affichage,getMainCarteIemeCarte(*getMainJoueur(*getIemeJoueur(t,i)),j),x,y+15,0.8,true);
                }
                k++;
            }
            if (a==0)
                AffAfficheCarte(affichage,getMainCarteIemeCarte(*getMainJoueur(*getIemeJoueur(t,i)),j),x,y+15,0.8,false);

        }
    }
    else
    {
        assert(getTypeJoueur( *getIemeJoueur(t,i)) != 1);

        if (getStatutJoueur(*getIemeJoueur(t,i)) != FOLD and getStatutJoueur(*getIemeJoueur(t,i)) !=SIT_OUT)
        {
            for (j=0;j<2;j++)
            {
                x= getPositionJoueurX(*t.joueur[i]);
                y= getPositionJoueurY(*t.joueur[i]);
                int k=1;
                int a=0;
                while (a==0 && k<6)
                {
                    if (tabResultat[k][0]==getCarteRang(*getMainCarteIemeCarte(*getMainJoueur(*getIemeJoueur(t,i)),j)) && tabResultat[k][1]==getCarteCouleur(*getMainCarteIemeCarte(*getMainJoueur(*getIemeJoueur(t,i)),j)))
                    {
                        a=1;
                        AffAfficheCarte(affichage,getMainCarteIemeCarte(*getMainJoueur(*getIemeJoueur(t,i)),j),x+j*20+3,y+20,0.35,true);
                    }
                    k++;
                }
                if (a==0)
                    AffAfficheCarte(affichage,getMainCarteIemeCarte(*getMainJoueur(*getIemeJoueur(t,i)),j),x+j*20+3,y+20,0.35,false);


            }
        }
    }


}

void AffInfosJoueur(SDL_Surface* affichage,const Joueur &j,const Table & table)
{
    char message[30];
    sprintf(message,"%s : %d",j.pseudo,j.argent);


    AffAfficheTexte(affichage,message,620,530+20*0,255,255,255,TTF_STYLE_NORMAL,22);


    switch (j.statut)
    {
    case CALL:
        sprintf(message,"mise : %d",getMiseJoueur(j));
        break;
    case CHECK:
        sprintf(message,"check");
        break;
    case RAISE:
        sprintf(message,"relance : %d",getMiseJoueur(j));
        break;
    case FOLD:
        sprintf(message,"se couche");
        break;
    case ALL_IN:
        sprintf(message,"tapis : %d",getTapisJoueur(j));
        break;
    default:
        sprintf(message," ");
        break;
    }


    AffAfficheTexte(affichage,message,620,530+20*1,255,255,255,TTF_STYLE_NORMAL,18);




    if (j.idJoueur == getPositionDealerTable(table))
    {
        sprintf(message,"Dealer");
        AffAfficheTexte(affichage,message,620,530+20*2,255,0,0,TTF_STYLE_BOLD,20);
    }

}
int scanActionJoueur(SDL_Surface* affichage,int & relance,Statut & s,int & montant)
{

    bool fin = false;
    SDL_Event event;

    path boutonP="img/bouton.png";
    SDL_Surface* bouton;
    s=CALL;
    relance=0;

    bouton=load_image(boutonP);
    AffAfficheTexte(bouton,"Suivre / Check",10,10,255,0,0,TTF_STYLE_NORMAL,18);
    apply_surface(620,530+20*4,bouton,affichage);
    bouton=load_image(boutonP);
    AffAfficheTexte(bouton,"Couche",10,10,255,0,0,TTF_STYLE_NORMAL,18);
    apply_surface(620,530+20*4+50,bouton,affichage);
    bouton=load_image(boutonP);
    AffAfficheTexte(bouton,"Relance",10,10,255,0,0,TTF_STYLE_NORMAL,18);
    apply_surface(620,530+20*4+100,bouton,affichage);

    SDL_Flip(affichage);




    while (fin!=true)
    {
        SDL_PollEvent(&event);

        switch (event.type)
        {
        case SDL_QUIT :
            SDL_FreeSurface(bouton);
            return -1;
            break;

        case SDL_KEYDOWN :
            if (event.key.keysym.sym == SDLK_m)
            {
                SDL_FreeSurface(bouton);
                return 2;
            }
            else if (event.key.keysym.sym == SDLK_ESCAPE)
            {
                SDL_FreeSurface(bouton);
                return -1;
                break;
            }
            break;
        case SDL_MOUSEBUTTONUP :
            for (int i=0;i<3;i++)
            {
                if (event.button.button == SDL_BUTTON_LEFT && event.button.x >= 620 && event.button.x <= 820 && event.button.y >= 610+i*50 && event.button.y <= 610+i*50+50)
                {
                    switch (i)
                    {
                    case 0:
                        s=CALL;
                        break;
                    case 1:
                        s=FOLD;
                        break;
                    case 2:
                        s=RAISE;
                        relance = 50;
                        break;

                    }
                    SDL_FreeSurface(bouton);
                    return 1;
                }
            }
            break;
        case SDL_MOUSEMOTION:
            for (int i=0;i<3;i++)
            {
                if (event.motion.x >= 620 && event.motion.x <= 820 && event.motion.y >=610+i*50 && event.motion.y <=610+i*50+50)
                {

                }
                break;
            }
        }



    }
    SDL_FreeSurface(bouton);
    return 0;
}





int lancePartie(SDL_Surface* affichage,SDL_Surface* tapis)
{




    const int NOMBRE_JOUEUR_PC = 4;
    const int ARGENT_DEPART = 1000;
    Table t;
    PileCarte p;
    double zoom = 1;


    initTable(t);
    initPileCarte(p);

    setPetiteBlindTable (t,10);
    setMaxJoueurTable(t,NOMBRE_JOUEUR_PC+1);
    t.positionDealer=1;

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
    bool blindAMettre=true;
    int finTour=getNJoueurTable(t);
    bool retour = true;
    printf("lance jeu\n");
    int renvoyer=0;
    int joueurJouant = getPositionDealerTable(t);
    int joueurRestant =0;
    int relance = 0;
    int a;
    int montant;
    int boucleJeu=0;
    int pot=0;
    Statut statut;
    joueurRestant++;




    while (gameOn)
    {
        joueurJouant = getPositionDealerTable(t);
        joueurJouant =getJoueurSuivant(t,joueurJouant);
        if (blindAMettre==true)
        {
            reinitialisationMainJoueurTable(t);
            reinitialisationMain(*getMainCarteTable(t));
            nouvellePileCarte(p);
            distribuer2CartesJoueursJeu(t);
            joueurPetiteBlind(t,*t.joueur[joueurJouant]);
            joueurJouant =getJoueurSuivant(t,joueurJouant);
            joueurGrosseBlind(t,*t.joueur[joueurJouant]);
            joueurJouant =getJoueurSuivant(t,joueurJouant);
            montant = getPetiteBlindTable(t)*2;
            blindAMettre=false;
        }

        AffAfficheTapis(affichage,tapis);
        AffAffichageInfosJoueurs(affichage,t,joueurJouant);
        AffCarteDecouvertes(t,affichage);
        AffCartesJoueursJeu(affichage,t);
        AffInfosJoueur(affichage,*player,t);
        AffAffichageInfosJoueurs(affichage,t,joueurJouant);
        if (zoom != 1)
        {
            SDL_Surface* surfaceZoom = rotozoomSurface(affichage,0,zoom,0);
            apply_surface(0,0,surfaceZoom,affichage);
            SDL_FreeSurface(surfaceZoom);
        }
        SDL_Flip(affichage);

        while (finTour!=0 && gameOn)
        {
            printf("joueurJouant:%d\n",joueurJouant);

            if (t.joueur[joueurJouant]!=NULL)
            {
                if ( getStatutJoueur(*t.joueur[joueurJouant]) != SIT_OUT && getStatutJoueur(*t.joueur[joueurJouant]) != FOLD && getStatutJoueur(*t.joueur[joueurJouant]) != ALL_IN)
                {

                    while (retour)
                    {
                        relance=0;
                        a = atendsActionJoueur(affichage,t,*t.joueur[joueurJouant],relance,statut,montant);
                        if (a==-1)//onquitte
                        {
                            gameOn = false;
                            renvoyer=3;
                            break;
                        }
                        else if (a==2)//menu
                        {

                            switch (AffMenu(affichage))
                            {
                            case 1:
                                gameOn = false;
                                retour=false;
                                renvoyer=1;
                                break;
                            case 3:
                                gameOn = false;
                                retour=false;
                                renvoyer=3;
                                break;
                            case 0:
                                AffAfficheTapis(affichage,tapis);
                                AffCartesJoueursJeu(affichage,t);
                                AffCarteDecouvertes(t,affichage);
                                AffAffichageInfosJoueurs(affichage,t,joueurJouant);
                                AffInfosJoueur(affichage,*player,t);
                                if (zoom != 1)
                                {
                                    SDL_Surface* surfaceZoom = rotozoomSurface(affichage,0,zoom,0);
                                    apply_surface(0,0,surfaceZoom,affichage);
                                    SDL_FreeSurface(surfaceZoom);
                                }
                                SDL_Flip(affichage);
                                break;
                            }
                        }
                        else
                        {
                            actionJoueur(*t.joueur[joueurJouant],statut,montant,relance);
                            retour=false;
                        }
                    }
                    retour = true;
                }
                if (relance==0)
                {
                    finTour--;
                }
                else
                {
                    finTour=getNJoueurTable(t)-1;
                }
            }
            printf("fintour:  %d\n",finTour);

            SDL_PollEvent(&event);

            switch (event.type)
            {
            case SDL_QUIT:
                gameOn = false;
                renvoyer=3;
                break;
            case SDL_VIDEORESIZE:/*
                zoom = (double)event.resize.w/1024;
                affichage = SDL_SetVideoMode( event.resize.w, event.resize.h, 32, SDL_HWSURFACE|SDL_RESIZABLE|SDL_DOUBLEBUF );
                AffAfficheTapis(affichage,tapis);
                AffCartesJoueursJeu(affichage,t);
                AffCarteDecouvertes(t,affichage);
                AffAffichageInfosJoueurs(affichage,t,joueurJouant);
                apply_surface(0,0,rotozoomSurface(affichage,0,zoom,0),affichage);
                SDL_Flip(affichage);
                break;*/
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
                        AffAfficheTapis(affichage,tapis);
                        AffCartesJoueursJeu(affichage,t);
                        AffCarteDecouvertes(t,affichage);
                        AffAffichageInfosJoueurs(affichage,t,joueurJouant);
                        AffInfosJoueur(affichage,*player,t);
                        if (zoom != 1)
                        {
                            SDL_Surface* surfaceZoom = rotozoomSurface(affichage,0,zoom,0);
                            apply_surface(0,0,surfaceZoom,affichage);
                            SDL_FreeSurface(surfaceZoom);
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

            joueurJouant =getJoueurSuivant(t,joueurJouant);
            AffAfficheTapis(affichage,tapis);
            AffAffichageInfosJoueurs(affichage,t,joueurJouant);
            AffCarteDecouvertes(t,affichage);
            AffCartesJoueursJeu(affichage,t);
            AffInfosJoueur(affichage,*player,t);
            AffAffichageInfosJoueurs(affichage,t,joueurJouant);
            if (zoom != 1)
            {
                SDL_Surface* surfaceZoom = rotozoomSurface(affichage,0,zoom,0);
                apply_surface(0,0,surfaceZoom,affichage);
                SDL_FreeSurface(surfaceZoom);
            }
            SDL_Flip(affichage);
        }
        //si tout le monde s'est couché
        int i=0;
        int j=0;

        while (i<=1)
        {
            if (t.joueur[j]!=NULL && (getStatutJoueur(*t.joueur[j]) != FOLD && getStatutJoueur(*t.joueur[j]) != SIT_OUT))
                i++;
            j++;

        }
        //if(i==1)
        //tout le monde sest couche


        finTour=getNJoueurTable(t);
        joueurJouant=getPositionDealerTable(t);
        boucleJeu++;
        if (boucleJeu==1)
        {

            distribuer1CarteDecouverteJeu(t,1);
            AffCarteDecouvertes(t,affichage);
            SDL_Flip(affichage);
            SDL_Delay(200);
            distribuer1CarteDecouverteJeu(t,1);
            AffCarteDecouvertes(t,affichage);
            SDL_Flip(affichage);
            SDL_Delay(200);
            distribuer1CarteDecouverteJeu(t,1);
            AffCarteDecouvertes(t,affichage);
        }
        else if (boucleJeu<4)
        {
            distribuer1CarteDecouverteJeu(t,1);
        }
        else
        {
            affAffichageVainqueur(affichage,t);
            printf("determine_vainqueur_redistribue_retourner_carte\n");
            blindAMettre=true;
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

