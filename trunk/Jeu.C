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



void initialiseJeu(Table & table,int argent)
{
	int i;
	for(i=0;i<getNJoueurTable(table);i++);
	{
		setArgentJoueur(*getIemeJoueur(table,i),argent);
	}

//etc... attend IArtificielle.h

}


void distribuer2CartesJoueursJeu(Table & table)
{
	int i;
	for(i=0;i<getNJoueurTable(table);i++);
	{
	    ajouteCarte(*getMainJoueur(*getIemeJoueur(table,i)),tirerCarte(*getTablePileCarteTable(table)));
	}
}


void distribuer1CarteDecouverteJeu(Table & table,int n)
{
    for(int i=0;i<n;i++)
    {
        ajouteCarte(*getMainCarteTable(table),tirerCarte(*getTablePileCarteTable(table)));
    }
}



