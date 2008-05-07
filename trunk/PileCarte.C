#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <cassert>
#include "PileCarte.h"

/*struct PileCarte
{
        Carte* ensembleCarte[52];
        int taille;
};
*/


void initPileCarte (PileCarte & pileCarte)
{
        int i;
        int j;
        int k=0;
        Carte* carte = NULL;
        pileCarte.taille = 52;
        for(i=1;i<=4;i++)
        {
                for(j=2;j<=14;j++)
                {
                        carte = new Carte;
                        setCarte(*carte,i,j);
                        sprintf(carte->nomFichier,"%s%d%s","cards/",(j-2)+13*(i-1),".png");
                        pileCarte.ensembleCarte[k] = carte;
                        k++;
                }
        }

}

PileCarte* creePileCarte()
{
        PileCarte* pileCarte = new PileCarte;
        initPileCarte(*pileCarte);
        return pileCarte;
}

void pileCarteLibere (PileCarte & pileCarte)
{
        delete[] *pileCarte.ensembleCarte;
        pileCarte.ensembleCarte[0] = NULL;
        pileCarte.taille = 0;

}

void pileCarteDetruit(PileCarte* & pileCarte)
{
        pileCarteLibere(*pileCarte);
        delete pileCarte;
        pileCarte = NULL;
}

Carte* tirerCarte(PileCarte& pileCarte)
{
        int x = hasard(0,pileCarte.taille-1);
        Carte* carte;
        carte = pileCarte.ensembleCarte[x];
        //ou carte  ?????

        //on permute pour que la carte soit a la fin (apres le rang taille -2 du tableau)
        if(x!=pileCarte.taille-1)
        {
                pileCarte.ensembleCarte[x] = pileCarte.ensembleCarte[pileCarte.taille-1];
                pileCarte.ensembleCarte[pileCarte.taille-1] = carte;
        }
        //on enleve une carte a la taille, mais la carte est toujours présente dans le tableau
        pileCarte.taille --;


        return carte;
        //ou carte ??

}


void nouvellePileCarte(PileCarte & pileCarte)
{
        pileCarte.taille = 52;
}



int hasard(int x,int y)
{
    static int first=0;
    if(first == 0)
    {
        srand (time (NULL));
        first = 1;
    }
    assert(x<y and x>=0 and y<52);

    return rand() % (y - x) +x;
}
