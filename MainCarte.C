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
  Carte* tabMain[5];
  int nCarte;
}; */

void initialisationMain(MainCarte & m)
{
	m.tabMain=new Carte* [7];
	m.nCarte=0;
}

Carte* getMainCarteTabMain(const MainCarte & m)
{
	return m.tabMain;
}

int getMainCarteNbCarte(const MainCarte & m)
{
	return m.nCarte;
}

void setMainCarte(MainCarte & m, const Carte* & tabMain, int nCarte)
{
    int i;
	for(i=0;i<nCarte;i++)
	{
	    m.tabMain[i]=(tabMain+i*sizeof(Carte));
	}
    m.nCarte=nCarte;
}

void ajouteCarte(MainCarte & m, const Carte* & c)
{
	if(m.nCarte<5)
	{
		Carte* temp[]=new Carte* [m.nCarte+1];
		int i;
		for(i=0;i<m.nCarte;i++)
		{
			temp[i]=m.tabMain[i];
		}
		temp[i+1]=c;
	}
	else
	{
		printf("Main pleine \n");
	}
}

void trieMain(MainCarte & m, char option)
{
    if(option=="couleur")
    {
        //Algo de test avec 2 indices de déplacement. Par Ben :)
        int j=0;
        int i=1;
        while(j<m.nCarte-1)
        {
            if(i==6)
            {
                i=j+1;
            }
            if(((m.tabMain[j])->couleur) == ((m.tabMain[i])->couleur))
            {
                i=i+1;
                j=j+1;
            }
            else
            {
                Carte* temp=m.tabMain[i+1];
                m.tabMain[i+1]=m.tabMain[i];
                m.tabMain[i]=temp;

                i=i+1;
            }
        }
    }
    if(option=="rang")
    {
        //Principe du tri minimum sur les rangs des 7 (au maximum) cartes d'une main.
        int i,j;
        int posmin;
        Carte* rmin;

        for(i=0;i<m.nCarte-1;i++)
        {
            posmin=i;
            rmin=m.tabMain[i];
            for(j=i+1;j<m.nCarte;j++)
            {
                if(((m.tabMain[j])->rang) < ((m.tabMain[posmin])->rang))
                {
                    posmin=j;
                }
            }
            rmin=m.tabMain[posmin];
            m.tabMain[posmin]=m.tabMain[i];
            m.tabMain[i]=rmin;
        }
    }
    if(option=="rc")
    {
        //ALGO A FAIRE.

        //TRIER PAR COULEUR PUIS CHAQUE COULEUR PAR RANG
        //J'AI DEJA UNE PETITE IDEE DE COMMENT FAIRE EN RECYCLANT LES DEUX OPTIONS DU DESSUS ET EN DECOUPANT LE TABLEAU DE MAINCARTE.
    }
}

Main identifieMainCarte(const MainCarte & m)
{
    trieMain(m,couleur);
    if(
    trieMain(m,rang);
    if(

    //ALGO TENDU DU SLIP A FINIR
}
MainCarte compareMain(const MainCarte & m1, const MainCarte & m2)
{
	Main main1=identifierMainCarte(m1);
	Main main2=identifierMainCarte(m2);

	if(main1>main2)
		return m1;
	else if(main1<main2)
		return m2;
	else
		return 0;
}

void MainCarteLibere(MainCarte & m)
{
    delete [] m.tabMain;
	m.nCarte=0;
}

int couleurMainCarte(int tab7Carte[8][2])
{
    char[4] c;
    c = {0,0,0,0}; //tableau qui va contenir le nombre de carte de chaque couleur
    //on compte le nombre de carte de chaque couleur
    for(int i=0;i<=7;i++)
    {
        c[tab7Carte[i][1]-1] ++; //on incremente chaque celulle correspondant a la couleur
                                                    //du tableau de un
    }
    //on regarde sil y en a une superieur a 5
    i=0;
    while(i<4)
    {
        if(c[i] >= 5)
            return i+1; //s'il y a une couleur presente 5 fois on renvoit son code
    }
    return 0
}

void trieTableauRang(int tab7Carte[7][2])
{
    int temp,i,k;
    for(k=0,k<7,k++)
    {
        for(i=0,i<7,i++)
        {
            if(tab7Carte[i][0]<tab7Carte[i+1][0])
            {
                tab7Carte[i][0]=temp; //temp du rang
                tab7Carte[i][0]=tab7Carte[i+1][0];
                tab7Carte[i+1][0]=temp;
                tab7Carte[i][1]=temp; //temp de la couleur
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
    if(tab7Carte[0][0] == 14)
    {
        k = 8;
        tab7Carte[7][0] = 1;
        tab7Carte[7][1] = tab7Carte[0][1];
    }

    int nCarteConsecutive = 0;
    int compteurCarte = 0;
    while(nCarteConsecutive != 4 && compteurCarte < (k-1))
    {
        //test si les deux cartes se suivent
        if(tab7Carte[compteurCarte][0] == tab7Carte[compteurCarte+1][0]+1)
        {
            nCarteConsecutive++;
        //si elle sont egales on ne fait rien
        }else if(tab7Carte[compteurCarte][0] == tab7Carte[compteurCarte+1][0]){
        }
        //si elle sont differentes on remet le compteur a 0
        else{
            nCarteConsecutive=0;
            if(k-compteurCarte<6) //on test sil est encore possible de faire une suite
                return 0;
        }
        k++;
    }

    if(nCarteConsecutive>=4)
    {
        return tab7Carte[compteurCarte][0]+3;//si suite on renvoit le rang de la meilleure carte de la suite
    }
    return 0;
}


int suiteMainCarte(int tab7Carte[8][2])
{
    //on trie le tableau en fonction du RANG (DECROISSANT)
    int temp,i,k;
    for(k=0,k<7,k++)
    {
        for(i=0,i<7,i++)
        {
            if(tab[i][0]<tab[i+1][0])
            {
                tab[i][0]=temp; //temp du rang
                tab[i][0]=tab[i+1][0];
                tab[i+1][0]=temp;
                tab[i][1]=temp; //temp de la couleur
                tab[i][1]=tab[i+1][1];
                tab[i+1][1]=temp;
            }
        }
    }

    if(tab[0][0]!=14) //test pour savoir s'il y a un as
    {
        return suiteMainCarte2(tab7Carte,0,0,7);
    }else{
        tab[7][0] = 1;//on rajoute un 1 (as) pour LA suite du type (1 2 3 4 5)
        tab[7][1] = 1;//on se fout de la couleur de l'as
        int k = suiteMainCarte2(tab7Carte,0,0,8);
        //on enleve l'as rajoute
        tab[7][1]=0;
        tab[7][0] = 0;
        return k;
    }


}



int quinteFlushMainCarte(int tab7Carte[10][2],int couleur);
{
    int l =7;
    //on met a zero les cartes qui ne sont pas de la couleur dominante
    int i;
    for(i=0;i<7;i++)
    {
        if(tab7Carte[i][1]!=couleur)
        {
            tab7Carte[i][1]=0;
            tab7Carte[i][0]=0;
        }
    }
    //on rajoute sil y a un AS un "1" a la fin du tableau
    if(tab7Carte[0][0] == 14)
    {
        tab7Carte[7][0]=1;
        l++;
    }else if(tab7Carte[1][0] == 14)
    {
        tab7Carte[7][0]=1;
        l++;
    }else if(tab7Carte[2][0] == 14)
        tab7Carte[7][0]=1;
        l++;
    }

    return suiteMainCarte2(tab7Carte,0,0,l);


}



void nombreOcurenceCarte(const int & tab7Carte[10][2],int & tab[])
{
    int i;
    for(i=0;i<15;i++)
        tab[i] = 0;
    for(i=0;i<7;i++)
    {
        tab[tab7Carte[i][0]]++;
    }
}


void choixCarteMultiple(int tab7Carte[7][2],const int & tab[],int & tabResultat[6][2])
{
    //double triage du tableau tab
        //on trie dabord en fonction de tab[i] puis en fonction de i dans un tableau a 2d tab[x][y]
        //de sorte que tab[x][0] contient un entier compris entre 0 et 4 (trie d'abord par rapport a x puis a y)
        //et tab[x][1] contient le rang de la carte
        //exemple : tab[1][0] = 2  tab[1][1] = 6  => une paire de 6 en 2e position
        //donc tab[0][0] > 2 ou tab[0][1] >6 => soit un brelan ou mieu soit une paire de 7 ou+
            //A FAIRE  (il va de 0 a 14)



    int i;
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

            //on cherche la couleur de la carte correspondant au rang
            i=0;
            while(tab7Carte[i][0] != tab[1][1])
            {
                i++
            }
            tabResultat[5][0]=tab[1][1];
            tabResultat[5][1]=tab7Carte[i][1];

        break;
        case 3:
            if(k+tab[l+1][0] >=2)
            {
                tabResultat[0]=6;
                tabResultat[1] =tab[0][1];
                tabResultat[2] =tab[0][1];
                tabResultat[3] =tab[0][1];
                tabResultat[4] = tab[1][1];
                tabResultat[5] = tab[1][1];
            }else{
                tabResultat[0]=3;
                tabResultat[1] =tab[0][1];
                tabResultat[2] =tab[0][1];
                tabResultat[3] =tab[0][1];
                tabResultat[4] =tab[1][1];
                tabResultat[5] =tab[2][1];
            }
        break;
        case 2:
            if(k+tab[l+1][0] ==2)
            {
                tabResultat[0]=2;
                tabResultat[1] =tab[0][1];
                tabResultat[2] =tab[0][1];
                tabResultat[3] =tab[1][1];
                tabResultat[4] =tab[1][1];
                tabResultat[5] =tab[2][1];
            }else{
                tabResultat[0]=1;
                tabResultat[1] =tab[0][1];
                tabResultat[2] =tab[0][1];
                tabResultat[3] =tab[1][1];
                tabResultat[4] =tab[2][1];
                tabResultat[5] =tab[3][1];
            }
        break;
        case 1:
                tabResultat[0]=0;
                tabResultat[1] =tab[0][1];
                tabResultat[2] =tab[1][1];
                tabResultat[3] =tab[2][1];
                tabResultat[4] =tab[3][1];
                tabResultat[5] =tab[4][1];
        break;
    }

    //codage dans un tableau d'entier (faudrait faire un tableau de quadret parce que
    //stoquer des nombres qui ne depasse pas 14 sur 32bits c'est gros
    //le premier indice du tableau correspond au code de la forme
    //vous l'aurez compris (paire brelan carré...)
    //les 4 dernier elements sont le rang des cartes
}

