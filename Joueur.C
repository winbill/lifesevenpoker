/**
	@brief Fichier C pour les cartes.

	Gere les donnees de type Carte.

	@author Benjamin
	@file Joueur.h
	@version 1.1
	@date 2008/04/23
*/

#include "Joueur.h"
#include "IArtificielle.h"
#include "MainCarte.h"


void initJoueur(Joueur & joueur)
{
    joueur.argent=0;
    joueur.pseudo="";
    joueur.idJoueur=-1;
    joueur.mise=0;
    joueur.statut=DEF_STATUT;
    joueur.mainJoueur=new MainCarte;
    initialisationMain(*joueur.mainJoueur);
    joueur.type=DEF_TYPE_JOUEUR;
}


void initJoueur (Joueur & joueur, char* pseudo)
{
    initJoueur(joueur);
    joueur.pseudo=pseudo;
}


Joueur* creeJoueur()
{
    Joueur* joueur = new Joueur;
    initJoueur(*joueur);

    return joueur;
}


void setStatutJoueur (Joueur & joueur, const Statut statut)
{
    joueur.statut=statut;
}


Statut getStatutJoueur (Joueur & joueur)
{
    return joueur.statut;
}


void joueurLibere(Joueur & joueur)
{
    MainCarteLibere(*joueur.mainJoueur);
    delete joueur.mainJoueur;
}


void joueurDetruit(Joueur* & joueur)
{
    delete joueur;
}


void reinitialiseMainJoueur(Joueur & joueur)
{
    initialisationMain(*joueur.mainJoueur);
}


void setIdJoueur(Joueur & joueur, const int & n)
{
    joueur.idJoueur=n;
}


int getIdJoueur(const Joueur & joueur)
{
    return joueur.idJoueur;
}


void setMiseJoueur(Joueur & joueur, const int & n)
{
    joueur.mise=n;
}


int getMiseJoueur(const Joueur & joueur)
{
    return joueur.mise;
}


int ajoutMiseJoueur(Joueur & joueur,const int & n)
{
    joueur.mise=(joueur.mise + n);
}


MainCarte* getMainJoueur(const Joueur & joueur)
{
    return joueur.mainJoueur;
}


void setArgentJoueur(Joueur & joueur, const int & n)
{
    joueur.argent=n;
}


int getArgentJoueur(const Joueur & joueur)
{
    return joueur.argent;
}


