/**
	@brief Fichier C qui gere le jeu


	fichier principal qui sert a initialiser une partie et la terminer

	@author James
	@file Jeu.C
	@version 1.1
	@date 2008/04/16
 */

#include "Jeu.h"
#include "Carte.h"
#include "PileCarte.h"
#include "MainCarte.h"
#include "Joueur.h"
#include "Table.h"
#include "AfficheTxt.h"
#include <stdlib.h>
#include <stdio.h>



int atendsActionJoueur(SDL_Surface* aff,const Table & t,const Joueur & j,int & relance,Statut & s,int & montant,const char langue[][50], int historiqueIA[][3])
{
    assert(relance==0);
    if (getTypeJoueur(j) == IA)
    {
        s = calculIAJames(t,j,montant,relance,historiqueIA);
        definieStatut(t,s,j,montant,relance);
        if (s==CALL)
        {
            if (getMiseJoueur(j)==montant)
                s=CHECK;
        }
        if (getMiseJoueur(j) == getArgentJoueur(j))
        {
            s=ALL_IN;
        }
        if (getArgentJoueur(j) <getMiseJoueur(j))
        {
            s=FOLD;
        }

        SDL_Delay(200);
        return 1;
    }
    else if (j.type == JoueurLocal)
    {
        int a = scanActionJoueur(aff,relance,s,montant,j,t,langue);
        if (s==CALL)
        {
            if (j.mise==montant)
                s=CHECK;
        }
        return a;
    }
    else
    {
        return 1;//mode multijoueurs
    }
    return CALL;
}

void joueurPetiteBlind(Table & t,Joueur & j)
{
    setStatutJoueur(j,CALL);
    setArgentJoueur(j, getArgentJoueur(j)-getPetiteBlindTable(t));
    ajoutMiseJoueur(j,getPetiteBlindTable(t));
}
void joueurGrosseBlind(Table & t,Joueur & j)
{
    setStatutJoueur(j,CALL);
    setArgentJoueur(j, getArgentJoueur(j)-getPetiteBlindTable(t)*2);
    ajoutMiseJoueur(j,getPetiteBlindTable(t)*2);
}


void distribuer2CartesJoueursJeu(Table & table)
{
    int i;
    for (i=0;i<getMaxJoueurTable(table);i++)
    {
        if (table.joueur[i] != NULL && getStatutJoueur(*getIemeJoueur(table,i))!=SIT_OUT)
        {
            ajouteCarte(*getMainJoueur(*getIemeJoueur(table,i)),tirerCarte(*table.pileCarte));
            ajouteCarte(*getMainJoueur(*getIemeJoueur(table,i)),tirerCarte(*table.pileCarte));
        }
    }
}




void distribuer1CarteDecouverteJeu(Table & table,int n)
{
    for (int i=0;i<n;i++)
    {
        ajouteCarte(*getMainCarteTable(table),tirerCarte(*getTablePileCarteTable(table)));
    }
}

void intitialiseTab3d(int tabResultat[10][6][2])
{
    int i,j,k;
    for (i=0;i<10;i++)
    {
        for (j=0;j<6;j++)
        {
            for (k=0;k<2;k++)
            {
                tabResultat[i][j][k] = 0;
            }
        }
    }
}


void jeuDetermineVainqueur(const Table & t,int tabResultat[10][6][2])
{
    int i;

    for (i=0;i<getMaxJoueurTable(t);i++)
    {
        if (t.joueur[i] != NULL)
        {
            if (getStatutJoueur((*getIemeJoueur(t,i)))!=SIT_OUT && getStatutJoueur((*getIemeJoueur(t,i)))!=SIT && getStatutJoueur((*getIemeJoueur(t,i)))!=FOLD)
            {
                codageScoreMain(*getMainJoueur(*getIemeJoueur(t,i)),tabResultat[i],t);
                tabResultat[i][0][1]=i;
            }

        }
    }
}

int trieTab3d(int tabResultat[10][6][2])
{
    int egalite=0;
    int i,k,temp,l;
    int j=0;
    int plusGrand=0;
    //k parcours tous les joueurs
    for (k=0;k<10;k++)
    {
        //i parcours une 2e fois tous les joueurs
        for (i=0;i<9;i++)
        {
            while (plusGrand==0 && j<6)
            {
                if (tabResultat[i][j][0] < tabResultat[i+1][j][0])
                {
                    for (l=0;l<6;l++)
                    {
                        temp = tabResultat[i][l][0];
                        tabResultat[i][l][0] = tabResultat[i+1][l][0];
                        tabResultat[i+1][l][0] = temp;

                        temp = tabResultat[i][l][1];
                        tabResultat[i][l][1] = tabResultat[i+1][l][1];
                        tabResultat[i+1][l][1] = temp;
                    }
                    plusGrand = 1;
                }
                else if (tabResultat[i][j][0] > tabResultat[i+1][j][0])
                {
                    plusGrand = 1;
                }
                j++;
            }
            if (j==6 && plusGrand==0 && tabResultat[i][0][1]!=0)
                egalite++;

            j=0;
            plusGrand = 0;
        }
    }
    return egalite;
}


int fonctionGlobaleDetrminationVainqueur(const Table & t,int tabResultat[10][6][2])
{
    intitialiseTab3d(tabResultat);
    jeuDetermineVainqueur(t,tabResultat);
    return trieTab3d(tabResultat);
}


void trieTableauRang(int tab7Carte[7][2])
{
    int i,k,temp;
    for (k=0;k<7;k++)
    {
        for (i=0;i<6;i++)   // MODIFF : James ne serait ce pas 6 et non 7 ?? tristan ?
        {
            if (tab7Carte[i][0]<tab7Carte[i+1][0])
            {
                temp=tab7Carte[i][0]; //temp du rang
                tab7Carte[i][0]=tab7Carte[i+1][0];
                tab7Carte[i+1][0]=temp;
                temp=tab7Carte[i][1]; //temp de la couleur
                tab7Carte[i][1]=tab7Carte[i+1][1];
                tab7Carte[i+1][1]=temp;
            }
        }
    }
}


int codageScoreMain(const MainCarte &m, int tabResultat[6][2],const Table & table)
{
    //on utilise un tableau a 2 dimensions representant les 7 cartes (8 car l'as peut etre rajouter une deuxieme fois)
    int tabMainTotale[8][2];
    //on recupere les deux cartes du joueur
    tabMainTotale[0][0] = getCarteRang(*(m.tabMain[0]));
    tabMainTotale[0][1] = getCarteCouleur(*(m.tabMain[0]));
    tabMainTotale[1][0] = getCarteRang(*(m.tabMain[1]));
    tabMainTotale[1][1] = getCarteCouleur(*(m.tabMain[1]));


    //plus les 5 cartes decouvertes
    int i;
    for (i=0;i<5;i++)
    {
        tabMainTotale[i+2][0]=getCarteRang(*((*(table.carteDecouverte)).tabMain[i]));
        tabMainTotale[i+2][1]=getCarteCouleur(*((*(table.carteDecouverte)).tabMain[i]));
    }
    tabMainTotale[7][0]=0;
    tabMainTotale[7][1]=0;



    tabResultat[0][1] = 0;
    //regle : si on a une couleur on a au mieux une quinte flush
    //regle : si on a une quinte on a au mieux une quinte flush ou une couleure ou au pire une quinte
    //on test la suite
    int couleur=0;
    int quinte=0;
    int k=0;

    trieTableauRang(tabMainTotale);
    //on regarde en 1er s'il y a une couleure
    couleur = couleurMainCarte(tabMainTotale);
    //one ragarde s'il y a une quinte
    quinte = suiteMainCarte(tabMainTotale);

    //sil y a une quinte et une couleur on regarde s'il y a une quinte flush
    if ((couleur!=0)&&(quinte!=0))
    {
        //int tabMainTotale2[10][2];
        //strcpy(tabMainTotale2,tabMainTotale); //on fait une copie du tableau
        k=quinteFlushMainCarte(tabMainTotale,couleur);
        if (k!=0)
        {
            tabResultat[0][0] = 8;
            tabResultat[1][0] = k;
            tabResultat[2][0] = k-1;
            tabResultat[3][0] = k-2;
            tabResultat[4][0] = k-3;
            tabResultat[5][0] = k-4;
            for (k=1;k<=5;k++) tabResultat[k][1]=couleur;
        }
    }
    else if (couleur != 0)
    {
        //s'il y a qu'une couleure c'est la meillleur possibilité
        tabResultat[0][0] = 5;

        //on doit prendre les 5 meilleurs cartes de la couleur correspondante
        i=0;
        k=0;
        while (k<5)
        {
            assert(i<7);
            if (tabMainTotale[i][1] == couleur)
            {
                tabResultat[1+k][0] = tabMainTotale[i][0];
                tabResultat[1+k][1] = tabMainTotale[i][1];
                k++;
            }
            i++;
        }
        return 1; //on renvoit 1 pour quitter la fonction

    }
    else if (quinte != 0)
    {
        //s'il y a qu'une suite c'est la meilleur possibilité
        tabResultat[0][0] = 4;
        //on doit prendre les 5 cartes de la suite
        // /!\ il faut verifier que yen ai pas deux egale
        // cas 10 9 9 8 7 6 2 1 -> 10 9 8 7 6 et non 10 9 9 8 7
        i=0;
        k =0;
        while (k<5)
        {
            assert(i<7);
            if (tabMainTotale[i][0]==quinte -k)
            {
                tabResultat[k+1][0] = tabMainTotale[i][0];
                tabResultat[k+1][1] = tabMainTotale[i][1];
                k++;
            }
            i++;
            //s'il a ni couleur ni quinte on regarde le reste
        }
        return 1;//on renvoit 1 pour quitter la fonction
    }
    else
    {

        int tabOccurence[15];       //on cree le tableau d'occurence
        nombreOcurenceCarte(tabMainTotale,tabOccurence);    //on met dans un tableau le nombre d'occurence de chaque carte
        choixCarteMultiple(tabMainTotale,tabOccurence,tabResultat);     //on obtient directement le code dans tabResultat
        if (tabResultat[0][0] >= 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    return 0;
}



