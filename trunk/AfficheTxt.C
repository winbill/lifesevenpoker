/**
	@brief Fichier C pour l'affichage en mode texte


	gere l'affichage et le debug en mode texte uniquement

	@author  James
	@file AfficheTxt.h
	@version 1.1
	@date 2008/05/01
 */

#ifndef AfficheTxt_H
#define AfficheTxt_H
#include "Joueur.h"
#include "Table.h"
#include "AfficheTxt.h"
#include <stdlib.h>
#include <stdio.h>


void afficheInfoJoueur(const Joueur & j)
{
    printf("--Infos Joueur--\n");
    printf("Argent : %d\n",j.argent);
    printf("pseudo : %s\n",j.pseudo);
    printf("idJoueur : %d\n",j.idJoueur);
    printf("mise : %d\n",j.mise);
    printf("statut : %d\n",j.statut);
    printf("type : %d\n",j.type);
    printf("-----FIN-----\n");


}

void afficheInfoTable(const Table & t)
{
    printf("--Infos Table--\n");
    //printf("Argent : %d\n",t.carteDecouverte);

    for(int i=0;i<10;i++)
    {
        if(t.joueur[i] != NULL)
        {
            printf("Joueur no:%d nom:%s\n",i,getIemeJoueur(t,i)->pseudo);
        }else{
            printf("Joueur no:%d   INEXISTANT\n",i);
        }
    }

    printf("nJoueur : %d\n",t.nJoueur);
    printf("nMaxJoueur : %d\n",t.nMaxJoueur);
    printf("petiteBlind : %d\n",t.petiteBlind);
    printf("positionDealer : %d\n",t.positionDealer);

    printf("-----FIN-----\n");

}
void afficheMainCarte(const MainCarte & m,char titre[])
{
    printf("--Infos MainCarte  %s--\n",titre);
    printf("nCarte : %d\n",m.nCarte);
    for(int i=0;i<5;i++)
    {
        if(m.tabMain[i] != NULL)
        {
            printf("Carte no:%d rg:%d couleur:%d\n",i,(*m.tabMain[i]).rang,(*m.tabMain[i]).couleur);
        }else{
            printf("Carte no:%d    INEXISTANT\n",i);
        }
    }



    printf("-----FIN-----\n");


}





















#endif


