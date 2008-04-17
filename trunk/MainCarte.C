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
	if(nCarte<5)
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
    if(option="couleur")
    {
        //Algo de test avec 2 indices de déplacement. Par Ben :)
        int j=0;
        int i=1;
        while(j<6)
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
    if(option="rang")
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
    if(option="rc")
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


int couleurMainCarte(const MainCarte & m)
{
    char[4] c;
    c = {0,0,0,0};
    for(int i=0;i<=getMainCarteNbCarte(m);i++)
    {
        c[getCarteCouleur(*(m.tabCarte[i]))-1] ++;
    }
    i=0;
    while(i<4)
    {
        if(c[i] >= 5)
            return i+1;
    }
    return 0

}

int suiteMainCarte(const MainCarte & m,int i,int j)
{
    if(j=4)
        return (getCarteRang[i-4]);
    if(i=getMainCarteNbCarte(m)-1)
        return 0;
    if(getCarteRang(*(m.tabCarte[i])) = getCarteRang(*(m.tabCarte[i+1])+1))
    {
        suiteMainCarte(m,i+1,j+1);
    }else{
        suiteMainCarte(m,i+1,0);
    }
}


void nombreOcurenceCarte(const MainCarte & m,int & tab[])
{
    int i;
    for(i=0;i<15;i++)
        tab[i] = 0;
    for(i=0;i<getMainCarteNbCarte(m);i++)
    {
        tab[getCarteRang(*(m.tabCarte[i])]++;
    }
}


int choixCarteMultiple(const MainCarte & m,const int & tab[])
{
    //double triage du tableau tab
        //on trie dabord en fonction de tab[i] puis en fonction de i dans un tableau a 2d tab[x][y]
        //de sorte que tab[x][0] contient un entier compris entre 0 et 4 (trié d'abord par rapport a x puis a y)
        //et tab[x][1] contient le rang de la carte
        //exemple : tab[1][0] = 2  tab[1][1] = 6  => une paire de 6 en 2e position
        //donc tab[0][0] > 2 ou tab[0][1] >6 => soit un brelan ou mieu soit une paire de 7 ou+
            //A FAIRE  (il va de 0 a 14)



    int k=0;    //variable qui compte le nombre de carte
                //(ne dois jamais depasse 5 et doit etre a 5 a la fin de la boucle)
    int l =0;   //variable d'incrementation (on change le rang)


    //boucle qui permet de choisir les 5cartes
    while(k!=5)
    {
        assert(tab[l][0] != 0); //si tab[l][0] == 0 le tableau ne pas etre bien trie ou le tableau est foireu
        if(k+tab[l][0] <=5)
        {
            k = k+tab[l][0];
        }else{
            //on met a zero pour dire que cette combinaison ne sera pas selectionnée
            tab[l][0] = 0;
        }
        l++;
    }

    //a lissue de la boucle on a toutes les informations pour donner un nom et des valeur a la main:
    switch (tab[0][0])
    {
        case 4:
            return 60000+tab[0][1];
        break;
        case 3:
            if(k+tab[l+1][0] ==2)
            {
                return 50000+tab[0][1]*100+tab[1][1];
            }else{
                return 40000+tab[0][1];
            }
        break;
        case 2:
            if(k+tab[l+1][0] ==2)
            {
                return 30000+tab[0][1]*100+tab[1][1];
            }else{
                return 20000+tab[0][1];
            }
        break;
        case 1:
            return 10000+tab[0][1]*100+tab[1][1];
        break;
    }

}
