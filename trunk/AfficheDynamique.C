/**
	@brief Fichier C pour l'affichage dynamique


	Gere l'affichage dynamique en utilisant le moteur de rendu SDL (Simple Directmedia Layer).

	@author  James Benjamin
	@file AfficheDynamique.C
	@version 1.2
	@date 2008/04/21
 */


#include "AfficheDynamique.h"
#include "Language.h"



void affAffichageVainqueur(SDL_Surface* affichage,Table & t)
{
    //on alloue le tableau qui va contenir le resultat de la partie
    int tabResultat[10][6][2];


    //s'il n'y a pas d'égalité
    if (fonctionGlobaleDetrminationVainqueur(t,tabResultat)==0)
    {
        char message2[30];
        char message[30];
        //on affiche les cartes des joueurs faces découvertes
        AffCartesJoueursJeu(affichage,t,false);
        //on rajoute une image transaparente sur les images qui permettent d'avoir la forme
        //sur les cartes decouvertes
        AffCarteDecouvertes(t,affichage,true,tabResultat[0]);
        //et sur les cartes du joueur concerné
        AffCartesJoueursJeuFinale(affichage,t,tabResultat[0],tabResultat[0][0][1]);



        switch (tabResultat[0][0][0])
        {
        case 0:
            sprintf(message2,"une carte haute");
            break;
        case 1:
            sprintf(message2,"une paire");
            break;
        case 2:
            sprintf(message2,"une double paire");
            break;
        case 3:
            sprintf(message2,"un brelan");
            break;
        case 4:
            sprintf(message2,"une quinte");
            break;
        case 5:
            sprintf(message2,"une couleur");
            break;
        case 6:
            sprintf(message2,"un full");
            break;
        case 7:
            sprintf(message2,"un carre");
            break;
        case 8:
            sprintf(message2,"une quinte flush");
            break;
        default:
            sprintf(message2,"ERREUR DETERMINATION FORME MAIN");
            break;

        }
        //affichage en texte du vainqueur et de la forme
        sprintf(message,"vainqueur:%s avec %s\n",(*getIemeJoueur(t,tabResultat[0][0][1])).pseudo,message2);
        AffAfficheTexte(affichage,message,240,420,320,255,255,TTF_STYLE_NORMAL,22);
        SDL_Flip(affichage);

        if (getStatutJoueur(*getIemeJoueur(t,tabResultat[0][0][1]))!=ALL_IN)
        {
            setArgentJoueur(*getIemeJoueur(t,tabResultat[0][0][1]),getArgentJoueur(*getIemeJoueur(t,tabResultat[0][0][1]))+getTablePot(t));
            setTablePot(t,0);
        }
        else
        {
            for (int i=0;i<getMaxJoueurTable(t);i++)
            {
                if (tabResultat[0][0][1]!=i)
                {
                    if (getGainTapisJoueur(*getIemeJoueur(t,i))>getTapisJoueur(*getIemeJoueur(t,tabResultat[0][0][1])))
                    {

                    }
                    else
                    {
                    }
                }


            }


        }

        SDL_Delay(3000);
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


void AffAffichePot(SDL_Surface* affichage,const Table & t)
{
    //affiche le contenu du pot
    char message[30];
    sprintf(message,"Pot:%d",getTablePot(t));
    AffAfficheTexte(affichage,message,900,600,255,255,255,TTF_STYLE_NORMAL,22);

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
//recuperation des coordonnés ou il doit etre placé
    int posx = getPositionJoueurX(j);
    int posy = getPositionJoueurY(j);
    char message[30];

//affichage de son pseudo
    sprintf(message,"%s:%d",j.pseudo,j.argent);

//si c'est le joueur qui est en train de jouer on change ca couleur
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


//affichage du statut
    AffAfficheTexte(affichage,message,posx,posy+20*1+91,255,255,255,TTF_STYLE_NORMAL,18);



//si c'est le dealer : on le marque
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

    AffCartesJoueursJeu( affichage,t,false);
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
    apply_surface(620,530+20*4-50,bouton,affichage);
    bouton=load_image(boutonP);
    AffAfficheTexte(bouton,"Couche",10,10,255,0,0,TTF_STYLE_NORMAL,18);
    apply_surface(620,530+20*4,bouton,affichage);
    bouton=load_image(boutonP);
    AffAfficheTexte(bouton,"Relance",10,10,255,0,0,TTF_STYLE_NORMAL,18);
    apply_surface(620,530+20*4+50,bouton,affichage);
    bouton=load_image(boutonP);
    AffAfficheTexte(bouton,"Tapis",10,10,255,0,0,TTF_STYLE_NORMAL,18);
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
            for (int i=-1;i<3;i++)
            {
                if (event.button.button == SDL_BUTTON_LEFT && event.button.x >= 620 && event.button.x <= 820 && event.button.y >= 610+i*50 && event.button.y <= 610+i*50+50)
                {
                    switch (i)
                    {
                    case -1:
                        s=CALL;
                        break;
                    case 0:
                        s=FOLD;
                        break;
                    case 1:
                        s=RAISE;
                        relance = 50;
                        break;
                    case 2:
                        s=ALL_IN;
                        break;

                    }
                    printf("statut::%d\n",i);
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

void miseDansPot(Table & t)
{
    //on_met_toute_les_mises_dans_le_pot
    for (int h=0;h<=getMaxJoueurTable(t);h++)
    {
        if (getIemeJoueur(t,h)!=NULL)
        {
            if (getMiseJoueur(*getIemeJoueur(t,h))!=0)
            {
                setTablePot(t,getTablePot(t)+getMiseJoueur(*getIemeJoueur(t,h)));
                setMiseJoueur(*getIemeJoueur(t,h),0);
            }
        }
    }
}



int lancePartie(SDL_Surface* affichage,SDL_Surface* tapis)
{
    char** tabLanguage=creeTableauLanguage("languages/french");


    //nombre d'IA:
    const int NOMBRE_JOUEUR_PC = 4;
    const int ARGENT_DEPART = 1000;
    Table t;
    PileCarte p;
    double zoom = 1;


    initTable(t);
    initPileCarte(p);

    //petite blind a 10
    setPetiteBlindTable (t,10);
    setMaxJoueurTable(t,NOMBRE_JOUEUR_PC+1);
    t.positionDealer=1;


    t.pileCarte = &p;
    char nom[20];

    Joueur* player;
    Joueur* joueurs[10];

    //intitialisation et creation des joueurs artificiels
    for (int i=0;i<NOMBRE_JOUEUR_PC;i++)
    {
        sprintf(nom,"%s%d%s","Ordinateur",i,"  ");
        joueurs[i]=creeJoueur();
        initJoueur(*joueurs[i],nom);
        ajoutJoueurTable(t,joueurs[i]);
        setTypeJoueur(*joueurs[i],IA);
        setArgentJoueur(*joueurs[i],ARGENT_DEPART);

    }

    //initialisation du joueur humain
    player=creeJoueur();
    initJoueur(*player,"moi");
    setStatutJoueur(*player,SIT);
    setTypeJoueur(*player,JoueurLocal);
    setArgentJoueur(*player,ARGENT_DEPART);
    ajoutJoueurTable(t,player);



    SDL_Event event;
    bool gameOn=true;//variable conditionnel de boucle
    bool blindAMettre=true;
    int finTour=getNJoueurTable(t);//nombre de joueur qui reste a ineroger
    bool retour = true;//variable pour l'interraction entre l'ordinateur et l'humain
    printf("lance jeu\n");
    int renvoyer=0;//valuer que l'on renvoit
    int joueurJouant;//indice du joueur qui joue
    int a;
    int montant;//variable qui memorise la mise a mettre en cours
    int boucleJeu=0;//compte le nombre de tour (au total 4)
    Statut statut;//permet de memoriser le nouveau statu du joueur
    int relance = 0; //variable pour memoriser la relance d'un joueur
    int debug=0;
    /*
    void afficheInfoJoueur(const Joueur & j)
    void afficheMainCarte(const MainCarte & m,char titre[])*/

    AffAffichageInfosJoueurs(affichage,t,joueurJouant); //on lance l'affichage, pour initialiser les positins des joueurs


    while (gameOn)
    {
        //joueurJouant = personne apres le dealer
        joueurJouant = getPositionDealerTable(t);
        joueurJouant =getJoueurSuivant(t,joueurJouant);

        if (blindAMettre==true)
        {

            //nouveau lancement de 4 tour
            //on met a zero les carte des joueurs et de la table
            reinitialisationMainJoueurTable(t);
            reinitialisationMain(*getMainCarteTable(t));
            nouvellePileCarte(p);//la pile de carte contient de nouveau 52carte
            distribuer2CartesJoueursJeu(t);

            //les joueurs mettent les petites blind et grosses blind
            joueurPetiteBlind(t,*t.joueur[joueurJouant]);
            joueurJouant =getJoueurSuivant(t,joueurJouant);
            joueurGrosseBlind(t,*t.joueur[joueurJouant]);
            joueurJouant =getJoueurSuivant(t,joueurJouant);

            //la mise minimale a mettre est la grosse blind
            montant = getPetiteBlindTable(t)*2;
            blindAMettre=false;//au prochain tour il n'est plus nécessaire de faire ces opérations
        }






        AffAfficheTapis(affichage,tapis);//affiche l'arrie plan : le tapis
        AffCarteDecouvertes(t,affichage);//affiche les cartes découvertes
        AffCartesJoueursJeu(affichage,t);//affiche les cartes de tous les joueurs
        AffInfosJoueur(affichage,*player,t);//affiche les informations personelles du joueur humain
        AffAffichageInfosJoueurs(affichage,t,joueurJouant);//affiche les informations personelles des ordinateurs
        AffAffichePot(affichage,t);//affiche l'etat du pot


        if (zoom != 1)//le zoom sert lors du redimensionnement
        {
            SDL_Surface* surfaceZoom = rotozoomSurface(affichage,0,zoom,0);
            apply_surface(0,0,surfaceZoom,affichage);
            SDL_FreeSurface(surfaceZoom);
        }
        SDL_Flip(affichage);//actualisation de l'affichage

        while (finTour!=0 && gameOn)
        {
            printf("Debug:%d\n",debug);
            debug++;



            if (t.joueur[joueurJouant]!=NULL)
            {
                if ( getStatutJoueur(*t.joueur[joueurJouant]) != SIT_OUT && getStatutJoueur(*t.joueur[joueurJouant]) != FOLD && getStatutJoueur(*t.joueur[joueurJouant]) != ALL_IN)
                {
                    //le joueur existe et il peut jouer
                    while (retour)
                    {
                        //on attends ce qu'il a choisit de faire
                        relance=0;
                        a = atendsActionJoueur(affichage,t,*t.joueur[joueurJouant],relance,statut,montant);
                        if (a==-1)//le joueur a choisit de quitter
                        {
                            gameOn = false;
                            renvoyer=3;
                            break;
                        }
                        else if (a==2)// d'afficher le menu
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
                                AffAffichePot(affichage,t);
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
                            //il n'as pas cliqué sur des options de menu donc il continue a jouer avec son action pris en compte
                            actionJoueur(*t.joueur[joueurJouant],statut,montant,relance);
                            retour=false;//inutile de reattendre son action
                        }
                    }
                    retour = true;
                }
                if (relance==0)
                {
                    //si il ne relance pas, alors il reste un joueur en moins a faire jouer
                    finTour--;
                }
                else
                {
                    //sil relance il faut demander a tout les joueurs sauf lui sil veule suivre
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
                        AffAffichePot(affichage,t);
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


            joueurJouant =getJoueurSuivant(t,joueurJouant);//on passe au joueur suivant
            //on reaffiche tout
            AffAfficheTapis(affichage,tapis);
            AffAffichageInfosJoueurs(affichage,t,joueurJouant);
            AffCarteDecouvertes(t,affichage);
            AffCartesJoueursJeu(affichage,t);
            AffInfosJoueur(affichage,*player,t);
            AffAffichageInfosJoueurs(affichage,t,joueurJouant);
            AffAffichePot(affichage,t);
            if (zoom != 1)
            {
                SDL_Surface* surfaceZoom = rotozoomSurface(affichage,0,zoom,0);
                apply_surface(0,0,surfaceZoom,affichage);
                SDL_FreeSurface(surfaceZoom);
            }
            SDL_Flip(affichage);




        }
        if (gameOn)
        {
            //si tout le monde s'est couchees
            int i=0;
            int j=0;
            int k=0;

            while (i<=1)
            {
                if (t.joueur[j]!=NULL && (getStatutJoueur(*t.joueur[j]) != FOLD && getStatutJoueur(*t.joueur[j]) != SIT_OUT))
                {
                    i++;
                    k=j;
                }
                j++;

            }
            //if(i==1)
            //tout le monde sest couche sauf k


            finTour=getNJoueurTable(t);
            joueurJouant=getPositionDealerTable(t);
            boucleJeu++;
            printf("boucleJeu:%d\n",boucleJeu);
            if (boucleJeu==1)
            {
                miseDansPot(t);
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
                miseDansPot(t);
                distribuer1CarteDecouverteJeu(t,1);
            }
            else
            {
                miseDansPot(t);
                affAffichageVainqueur(affichage,t);
                printf("determine_vainqueur_donne_mise_redistribue_retourner_carte\n");
                blindAMettre=true;
                boucleJeu = 0;
            }
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

    detruitTableauLanguage(tabLanguage);
    return renvoyer;

}

