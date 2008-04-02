#include "Carte.h"
#include "PileCarte.h"
#include "assert.h"

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
	for(i=1;i<=4;i++)
	{
		for(j=2;j<=14;j++)
		{
			carte = new Carte;
			setCarte(carte,i,j);
			pileCarte.ensembleCarte[k] = *carte;
			k++;
		}
	}
	
}

PileCarte* creePileCarte()
{
	pileCarte = new PileCarte;
	initPileCarte(pileCarte);
	return *pileCarte;
}


Carte* tirerCarte(PileCarte& pileCarte)
{
	int x = hasard(0,pileCarte.taille-1);
	carte = new Carte;
	*carte = pileCarte.ensembleCarte[x];
	//ou carte  ?????
	
	//on permute pour que la carte soit a la fin (apres le rang taille -2 du tableau)
	if(x!=pileCarte.taille-1)
		pileCarte.ensembleCarte[x] = pileCarte.ensembleCarte[pileCarte.taille-1];
	
	//on enleve une carte a la taille, mais la carte est toujours présente dans le tableau
	pileCarte.taille --;
	
	
	return *carte
	//ou carte ??
	
}
