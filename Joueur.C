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
#include <stdlib.h>
#include <stdio.h>
#include <cassert>


int getTapisJoueur(const Joueur & j)
{
    return j.tapis;
}
void setTapisJoueur(Joueur & j,int n)
{
    j.tapis=n;
}

void initJoueur(Joueur & joueur)
{
    joueur.argent=0;
    joueur.tapis=0;

    joueur.pseudo = new char[20];
    memset(joueur.pseudo,0,sizeof(*joueur.pseudo)*20);
    joueur.posX=0;
    joueur.posY =0;

    joueur.idJoueur=-1;
    joueur.mise=0;
    joueur.statut=DEF_STATUT;
    joueur.mainJoueur=new MainCarte;
    initialisationMain(*(joueur).mainJoueur);
    joueur.type=DEF_TYPE_JOUEUR;
}


int getPositionJoueurX(const Joueur & j)
{
    return j.posX;
}
int getPositionJoueurY(const Joueur & j)
{
    return j.posY;
}
void setPositionJoueurX(Joueur & j,int x)
{
    j.posX=x;
}
void setPositionJoueurY(Joueur & j,int y)
{
    j.posY=y;
}


void initJoueur (Joueur & joueur,const char* pseudo)
{
    initJoueur(joueur);
    strcpy(joueur.pseudo,pseudo);
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

void setTypeJoueur(Joueur & joueur, const TypeJoueur typejoueur)
{
    joueur.type = typejoueur;
}

TypeJoueur getTypeJoueur(Joueur & joueur)
{
    return joueur.type;
}

void joueurLibere(Joueur & joueur)
{
    MainCarteLibere(*joueur.mainJoueur);
    delete[] joueur.pseudo;
    delete joueur.mainJoueur;
}


void joueurDetruit(Joueur* & joueur)
{
    joueurLibere(*joueur);
    delete joueur;
}


void reinitialiseMainJoueur(Joueur & joueur)
{
    initialisationMain(*joueur.mainJoueur);
}


void setIdJoueur(Joueur & joueur, int n)
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


int ajoutMiseJoueur(Joueur & joueur,int n)
{
    joueur.mise=(joueur.mise + n);
    return joueur.mise;
}


MainCarte* getMainJoueur(const Joueur & joueur)
{
    return joueur.mainJoueur;
}


void setArgentJoueur(Joueur & joueur, int n)
{
    joueur.argent=n;
}


int getArgentJoueur(const Joueur & joueur)
{
    return joueur.argent;
}
/*
    DEF_STATUT=0,
	SIT_OUT,1
	SIT,2
	CALL,3
	CHECK,4
	RAISE,5
	FOLD,6
	ALL_IN,7
	FIN_STATUT8

struct Joueur
{
	int argent;
	char* pseudo;
	int idJoueur;
	int mise;
	Statut statut;
	MainCarte* mainJoueur;
	TypeJoueur type;
};
*/

void reinitialisationMainJoueur(Joueur & j)
{
    reinitialisationMain(*getMainJoueur(j));
}

void actionJoueur(Joueur & j,Statut s,int & montant,int relance)
{
    int a;
    switch (s)
    {
    case SIT_OUT:
        setStatutJoueur(j,s);
        break;
    case SIT:
        assert(j.statut == SIT_OUT);
        setStatutJoueur(j,s);
        break;
    case CALL:
        //printf("call:%s - montant:%d - relance:%d\n",j.pseudo,montant,relance);
        a = montant - getMiseJoueur(j);
        assert(a > 0 && getArgentJoueur(j) > a);
        ajoutMiseJoueur(j,a);
        setArgentJoueur(j,getArgentJoueur(j)-a);
        setStatutJoueur(j,s);
        break;
    case CHECK:
        //printf("check:%s - montant:%d - relance:%d\n",j.pseudo,montant,relance);
        assert(montant == getMiseJoueur(j));
        setStatutJoueur(j,s);
        break;
    case RAISE:
        //printf("raise:%s - montant:%d - relance:%d\n",j.pseudo,montant,relance);
        a = montant - getMiseJoueur(j);
        assert(a >= 0 && getArgentJoueur(j) > ( a + relance));
        ajoutMiseJoueur(j,a+relance);
        setArgentJoueur(j,getArgentJoueur(j)-a-relance);
        setStatutJoueur(j,s);
        montant = montant+relance;
        break;
    case FOLD:
        setStatutJoueur(j,s);
        break;
    case ALL_IN:
        ajoutMiseJoueur(j,getArgentJoueur(j));
        setStatutJoueur(j,s);
        montant = getMiseJoueur(j);
        setArgentJoueur(j,0);
        setTapisJoueur(j,montant);
    default:
        break;


    }
}

