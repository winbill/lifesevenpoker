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
#include <stdlib.h>
#include <stdio.h>



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
	    //ajouteCarte(*j3->mainJoueur,tirerCarte(*t.pileCarte));
	    printf("----------------------%d---------------bababa",getNJoueurTable(table));
	    ajouteCarte(*getMainJoueur(*getIemeJoueur(table,2)),tirerCarte(*table.pileCarte));

	}
}


void distribuer1CarteDecouverteJeu(Table & table,int n)
{
    for(int i=0;i<n;i++)
    {
        ajouteCarte(*getMainCarteTable(table),tirerCarte(*getTablePileCarteTable(table)));
    }
}
/*
int codageScoreMain(const MainCarte &m, int & tabResultat[6][2],const Table & table)
{
	//on utilise un tableau a 2 dimensions representant les 7 cartes (8 car l'as peut etre rajouter une deuxieme fois)
	int tabMainTotale[8][2];
	//on recupere les deux cartes du joueur
	tabMainTotale[0][0] = getCarteRang(*(m.tabMain[0]));
	tabMainTotale[0][1] = getCarteCouleur(*(m.tabMain[0]));
	tabMainTotale[1][0] = getCarteRang(*(m.tabMain[0]));
	tabMainTotale[1][1] = getCarteCouleur(*(m.tabMain[0]));
	//plus les 5 cartes decouvertes
	int i;
	for(i=0;i<5;i++)
	{
		tabMainTotale[i+2][0]=getCarteRang((*(table.carteDecouverte[i])))
		tabMainTotale[i+2][1]=getCarteCouleur((*(table.carteDecouverte[i])))
	}


   //regle : si on a une couleur on a au mieux une quinte flush
   //regle : si on a une quinte on a au mieux une quinte flush ou une couleure ou au pire une quinte
   //on test la suite
   int couleur=0;
   int quinte=0;
   int k=0;

   //on regarde en 1er s'il y a une couleure
   couleur = couleurMainCarte(tabMainTotale);
   //one ragarde s'il y a une quinte
   quinte = suiteMainCarte(tabMainTotale);

   //sil y a une quinte et une couleur on regarde s'il y a une quinte flush
   if((couleur!=0)&&(quinte!=0))
   {
       int tabMainTotale2[10][2];
       strcpy(tabMainTotale2,tabMainTotale); //on fait une copie du tableau
       k=quinteFlushMainCarte(tabMainTotale2,couleur);
       if(k!=0)
       {
		tabResultat[0][0] = 8;
		tabResultat[1][0] = k;
		tabResultat[2][0] = k-1;
		tabResultat[3][0] = k-2;
		tabResultat[4][0] = k-3;
		tabResultat[5][0] = k-4;
		for(k=1;k<=5;k++) tabResultat[k][1]=couleur;
       }
   }
   //s'il y a qu'une couleure c'est la meillleur possibilité
   if(couleur != 0)
   {
       tabResultat[0][0] = 5;
       //on doit prendre les 5 meilleurs cartes de la couleur correspondante
       tabResultat[1][0] = ; //TROUVER UNE METHODE POUR RENVOYER LES 5 MEILLEURES CARTES DE LA COULEUR
       tabResultat[2] = k-1;
       tabResultat[3] = k-2;
       tabResultat[4] = k-3;
       tabResultat[5] = k-4;



       return 1; //on renvoit 1 pour quitter la fonction

   }
   //s'il y a qu'une suite c'est la meilleur possibilité
   if(quinte != 0)
   {
	tabResultat[0][0] = 4;
	//on doit prendre les 5 cartes de la suite
	// /!\ il faut verifier que yen ai pas deux egale
	// cas 10 9 9 8 7 6 2 1 -> 10 9 8 7 6 et non 10 9 9 8 7
	int i=1;
	while (i<=5) ////
	{
		if (tabMainTotale[k][0]==
			tabResultat[1][0] = tabMainTotale[][];
		tabResultat[2] =quinte-1;
		tabResultat[3] =quinte-2;
		tabResultat[4] =quinte-3;
		tabResultat[5] =quinte-4;
		return 1;//on renvoit 1 pour quitter la fonction
	}
   //s'il a ni couleur ni quinte on regarde le reste

   int tabOccurence[15];       //on cree le tableau d'occurence
   nombreOcurenceCarte(tabMainTotale,tabOccurence);    //on met dans un tableau le nombre d'occurence de chaque carte
   choixCarteMultiple(tabOccurence,tabResultat);     //on obtient directement le code dans tabResultat
   if(tabResultat[0] >= 0)
   {
       return 1;
   }else{
       return 0;
   }

}
*/


