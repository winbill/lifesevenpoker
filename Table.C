/**
       @brief Fichier C pour Table


       gere la table du jeu

       @author Tristan James
       @file Table.C
       @version 1.1
       @date 2008/04/11
*/


#include "MainCarte.h"
#include "PileCarte.h"
#include "Joueur.h"
#include "Table.h"
#include <stdlib.h>
#include <stdio.h>
/*

struct Table
{
       int nJoueur;
       Joueur* joueur[10];
       int nMaxJoueur;
       MainCarte* carteDecouverte;
       PileCarte* pileCarte;
       int positionDealer
};
*/


void initTable (Table & table)
{

       table.nJoueur = 0;
       table.joueur = new Joueur* [10];
       setMaxJoueurTable(table,0);
       memset(table.joueur,0,sizeof(*table.joueur)*10);
       table.carteDecouverte=new MainCarte;
       initialisationMain(*(table).carteDecouverte);
       table.pileCarte = NULL;
       table.positionDealer = 0;
       table.petiteBlind = 0;

}




Table* creeTable()
{
       Table* t = new Table;
       initTable(*t);
       return t;
}


void tableLibere(Table & table)
{
       delete[] table.joueur;
//      table.joueur = NULL;
       delete table.carteDecouverte;
       table.carteDecouverte = NULL;
       table.pileCarte = NULL;
}


void tableDetruit(Table* & table)
{
       tableLibere(*table);
       delete table;
       table = NULL;
}


void ajoutJoueurTable (Table & table,Joueur* joueur)
{
//      assert(getNJoueurTable(table)  < getMaxJoueurTable(table));
   int i =0;
   while(table.joueur[i] != NULL)
   {
       i++;
   }
       table.joueur[i] = joueur;
       setNJoueurTable(table,getNJoueurTable(table)+1);
       setIdJoueur(*joueur,i);
}


void supprimeJoueurTable (Table & table,Joueur* joueur)
{

       setNJoueurTable(table,getNJoueurTable(table)-1);
       table.joueur[joueur->idJoueur]=NULL;
       setIdJoueur(*joueur,-1);
}


void setMaxJoueurTable (Table & table, int n)
{
//      assert(n<=10&&n>0&&n>table.nJoueur);
       table.nMaxJoueur = n;
}


int getMaxJoueurTable (const Table & table)
{
       return table.nMaxJoueur;
}


PileCarte* getTablePileCarteTable(const Table & table)
{
       return table.pileCarte;
}

void setNJoueurTable (Table & table, int n)
{
//      assert(n<=10 && n>=0 && n <= getMaxJoueur(table));
       table.nJoueur=n;
}


int getNJoueurTable (const Table & table)
{
       return table.nJoueur;
}

int placeVide (const Table & table)
{
   int i=0;
   for(i=0;i<table.nJoueur;i++)
   {
       if(table.joueur[i] != 0)
           return i;
   }
   return -1;

}


void changeDealerTable(Table & table)
{
       table.positionDealer++;
   if(table.positionDealer >= getNJoueurTable(table))
       table.positionDealer =0;
       while(table.joueur[table.positionDealer] == 0)
       {
               table.positionDealer++;
       if(table.positionDealer >= getNJoueurTable(table))
           table.positionDealer =0;
       }


}


Joueur* getIemeJoueur(const Table & table,int n)
{
       return table.joueur [n];
}


MainCarte* getMainCarteTable (const Table & table)
{
   return table.carteDecouverte;
}


void setPetiteBlindTable (Table & table, int n)
{
//    assert(n>0 && n<99999);
   table.petiteBlind = n;
}



int getPetiteBlindTable (const Table & table)
{
   return table.petiteBlind;
}



int getJoueurSuivant(const Table & table,int i)
{
   int k=table.positionDealer;
   i++;
   if(i >= getNJoueurTable(table))
           i =0;
       while(table.joueur[i] == 0)
       {
               i++;
       if(k >= getNJoueurTable(table))
           k =0;
       }
   return i;
}



int getPositionDealerTable(const Table & table)
{
   return table.positionDealer;
}
