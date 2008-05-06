/**
	@brief Fichier C pour les mains des joueurs.

	Gere les donnees de type MainCarte.

	@author Benjamin, Olivier, James, Tristan
	@file MainCarte.h
	@version 1.2
	@date 2008/04/15
*/
#include <cstdio>
#include "Carte.h"
#include "MainCarte.h"
#include "PileCarte.h"

/*struct MainCarte
{
  Carte* tabMain;
  int nCarte;
}; */

void initialisationMain(MainCarte & m)
{
    m.tabMain = new Carte*[5];
    memset(m.tabMain,0,sizeof(*m.tabMain)*5);

    m.nCarte=0;
}

int getMainCarteNbCarte(const MainCarte & m)
{
    return m.nCarte;
}






void ajouteCarte(MainCarte & m, Carte* c)
{
    //assert(m.nCarte <5);
    m.tabMain[m.nCarte] = c;
    m.nCarte++;

}
void MainCarteLibere(MainCarte & m)
{
    delete [] m.tabMain;
    m.nCarte=0;
}




int couleurMainCarte(int tab7Carte[8][2])
{
    char c[4];
    int i;
    for (i=0;i<4;i++)
    {
        c[i] = 0;    //tableau qui va contenir le nombre de carte de chaque couleur
    }
    //on compte le nombre de carte de chaque couleur
    for (i=0;i<=7;i++)
    {
        c[tab7Carte[i][1]-1] ++; //on incremente chaque celulle correspondant a la couleur
        //du tableau de un
    }
    //on regarde sil y en a une superieur a 5
    i=0;
    while (i<4)
    {
        if (c[i] >= 5)
            return i+1; //s'il y a une couleur presente 5 fois on renvoit son code
        i++;
    }
    return 0;
}

void trieTableauRang(int tab7Carte[7][2])
{
    int i,k,temp;
    for (k=0;k<7;k++)
    {
        for (i=0;i<7;i++)
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




//l a besoin d1 tab trie DEC
int suiteMainCarte(int tab7Carte[8][2])
{
    int k=7;// variable qui indique le nombre de carte

    //s'il y a un (ou plus) AS on le rajoute a la fin
    if (tab7Carte[0][0] == 14)
    {
        k = 8;
        tab7Carte[7][0] = 1;
        tab7Carte[7][1] = tab7Carte[0][1];
    }

    int nCarteConsecutive = 0;
    int compteurCarte = 0;
    while (nCarteConsecutive != 4 && compteurCarte < (k-1))
    {
        //test si les deux cartes se suivent
        if (tab7Carte[compteurCarte][0] == tab7Carte[compteurCarte+1][0]+1)
        {
            nCarteConsecutive++;
            //si elle sont egales on ne fait rien
        }
        else if (tab7Carte[compteurCarte][0] == tab7Carte[compteurCarte+1][0])
        {
        }
        //si elle sont differentes on remet le compteur a 0
        else
        {
            nCarteConsecutive=0;
            if (k-compteurCarte<6) //on test sil est encore possible de faire une suite
                return 0;
        }
        compteurCarte++;
    }

    if (nCarteConsecutive>=4)
    {
        return tab7Carte[compteurCarte][0]+4;//si suite on renvoit le rang de la meilleure carte de la suite
    }
    return 0;
}


int quinteFlushMainCarte(int tab7Carte[8][2],int couleur)
{
    int k=7;// variable qui indique le nombre de carte

    //s'il y a un (ou plus) AS on le rajoute a la fin
    for(int i=0;i<3;i++)
    {
        if (tab7Carte[i][0] == 14 && tab7Carte[i][1] == couleur)
        {
            k = 8;
            tab7Carte[7][0] = 1;
            tab7Carte[7][1] = tab7Carte[i][1];
        }
    }

    int nCarteConsecutive = 0;
    int compteurCarte = 0;
    while (nCarteConsecutive != 4 && compteurCarte < (k-1))
    {
        //test si les deux cartes se suivent
        if (tab7Carte[compteurCarte][0] == tab7Carte[compteurCarte+1][0]+1)
        {
            if(tab7Carte[compteurCarte][1] == couleur)
            {
                nCarteConsecutive++;
            }else{
                nCarteConsecutive =0;
            }
            //si elle sont egales on ne fait rien
        }
        else if (tab7Carte[compteurCarte][0] == tab7Carte[compteurCarte+1][0])
        {
        }
        //si elle sont differentes on remet le compteur a 0
        else
        {
            nCarteConsecutive=0;
            if (k-compteurCarte<6) //on test sil est encore possible de faire une suite
                return 0;
        }
        compteurCarte++;
    }

    if (nCarteConsecutive>=4)
    {
        return tab7Carte[compteurCarte][0]+4;//si suite on renvoit le rang de la meilleure carte de la suite
    }
    return 0;
}



void nombreOcurenceCarte(const int tab7Carte[][2],int tab[])
{
    int i;

    for (i=0;i<15;i++)
        tab[i] = 0;

    for (i=0;i<7;i++)
    {
        tab[tab7Carte[i][0]]++;
    }
}

int mainCarteTrouveCouleur(const int tab7Carte[7][2],int rang,int & i)
{

    while (tab7Carte[i][0] != rang)
    {
        i++;
    }
    return tab7Carte[i][1];

}

void initTableau(int tab[],int taille)
{
    for (int i=0;i<taille;i++)
    {
        tab[i]=0;
    }
}

void initTableau2(int tab[][2],int taille)
{
    for (int i=0;i<taille;i++)
    {
        tab[i][0]=0;
        tab[i][1]=0;
    }
}




void choixCarteMultiple(int tab7Carte[][2],const int tabO[],int tabResultat[][2])
{
    //double triage du tableau tab
    //on trie dabord en fonction de tab[i] puis en fonction de i dans un tableau a 2d tab[x][y]
    //de sorte que tab[x][0] contient un entier compris entre 0 et 4 (trie d'abord par rapport a x puis a y)
    //et tab[x][1] contient le rang de la carte
    //exemple : tab[1][0] = 2  tab[1][1] = 6  => une paire de 6 en 2e position
    //donc tab[0][0] > 2 ou tab[0][1] >6 => soit un brelan ou mieu soit une paire de 7 ou+
    //A FAIRE  (il va de 0 a 14)


    //rajoute dune nelle colonne :
    int i=0;
    int k=0;
    int c=4;
    int d=0;
    int tab[7][2];
    initTableau2(tab,7);
    while (i!=7)
    {
        for (k=14;k>0;k--)
        {
            if (tabO[k]==c)
            {
                tab[d][0]=c;
                tab[d][1]=k;
                i+=c;
                d++;
            }
        }
        c--;
    }

    tabResultat[0][1]=0;

    i=0;
    k=0;
    c=0;
    //a lissue de la boucle on a toutes les informations pour donner un nom et des valeurs a la main:
    switch (tab[0][0])
    {
    case 4:
        tabResultat[0][0]=7;
        tabResultat[1][0]=tab[0][1];
        tabResultat[1][1]=1;
        tabResultat[2][0]=tab[0][1];
        tabResultat[2][1]=2;
        tabResultat[3][0]=tab[0][1];
        tabResultat[3][1]=3;
        tabResultat[4][0]=tab[0][1];
        tabResultat[4][1]=4;

        //on cherche la derniere meilleure carte
        i=1;
        k=0;
        while (tab[i][0] != 0)
        {
            if (tab[i][1]>k)
            {
                k=tab[i][1];
            }
            i++;
        }

        c = 0;
        tabResultat[5][0]=k;
        tabResultat[5][1]=mainCarteTrouveCouleur(tab7Carte,k,c);

        break;
    case 3:

        c=0;

        for (i=0;i<3;i++)
        {
            tabResultat[i+1][0] =tab[0][1];
            tabResultat[i+1][1] =mainCarteTrouveCouleur(tab7Carte,tab[0][1],c);
            c++;
        }

        if (tab[1][0] >=2)
        {
            tabResultat[0][0]=6;
            c=0;
            tabResultat[4][0] = tab[1][1];
            tabResultat[4][1] = mainCarteTrouveCouleur(tab7Carte,tab[1][1],c);

            c++;
            tabResultat[5][0] = tab[1][1];
            tabResultat[5][1] = mainCarteTrouveCouleur(tab7Carte,tab[1][1],c);
        }
        else
        {
            c=0;
            tabResultat[0][0]=3;
            tabResultat[4][0] =tab[1][1];
            tabResultat[4][1] =mainCarteTrouveCouleur(tab7Carte,tab[1][1],c);

            c=0;
            tabResultat[5][0] =tab[2][1];
            tabResultat[5][1] =mainCarteTrouveCouleur(tab7Carte,tab[2][1],c);
        }
        break;
    case 2:


        c=0;
        tabResultat[1][0] =tab[0][1];
        tabResultat[1][1] =mainCarteTrouveCouleur(tab7Carte,tab[0][1],c);

        c++;
        tabResultat[2][0] =tab[0][1];
        tabResultat[2][1] =mainCarteTrouveCouleur(tab7Carte,tab[0][1],c);

        if (tab[1][0] ==2)
        {

            tabResultat[0][0]=2;
            c=0;
            tabResultat[3][0] =tab[1][1];
            tabResultat[3][1] = mainCarteTrouveCouleur(tab7Carte,tab[1][1],c);

            c++;
            tabResultat[4][0] =tab[1][1];
            tabResultat[4][1] =mainCarteTrouveCouleur(tab7Carte,tab[1][1],c);


            i=1;
            k=0;
            while (tab[i][0] != 0)
            {
                if (tab[i][1]>k)
                {
                    k=tab[i][1];
                }
                i++;
            }
            c=0;
            tabResultat[5][0] =k;
            tabResultat[5][1] =mainCarteTrouveCouleur(tab7Carte,k,c);
        }
        else
        {
            tabResultat[0][0]=1;
            c=0;
            tabResultat[3][0] =tab[1][1];
            tabResultat[3][1] =mainCarteTrouveCouleur(tab7Carte,tab[1][1],c);

             c=0;
            tabResultat[4][0] =tab[2][1];
            tabResultat[4][1] =mainCarteTrouveCouleur(tab7Carte,tab[2][1],c);

             c=0;
            tabResultat[5][0] =tab[3][1];
            tabResultat[5][1] =mainCarteTrouveCouleur(tab7Carte,tab[3][1],c);

        }
        break;
    case 1:
        tabResultat[0][0]=0;


        for(i=1;i<6;i++)
        {
            c=0;
            tabResultat[i][0] =tab[i-1][1];
            tabResultat[i][1] =mainCarteTrouveCouleur(tab7Carte,tab[i-1][1],c);
        }
        break;
    }

    //codage dans un tableau d'entier (faudrait faire un tableau de quadret parce que
    //stoquer des nombres qui ne depasse pas 14 sur 32bits c'est gros
    //le premier indice du tableau correspond au code de la forme
    //vous l'aurez compris (paire brelan carrÃ©...)
    //les 5 dernier elements sont le rang des cartes et la couleur
}



