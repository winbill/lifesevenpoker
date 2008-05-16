
#include "IArtificielle.h"

Statut calculIA(const Table & t,const Joueur & j,int &relance,int & montant)
{
    getTablePot(t);
    relance=0;
    //printf("mise:%d   montant:%d\n",j.mise,montant);
    if(j.mise==montant)
        return CHECK;
    int a=montant-getMiseJoueur(j);
    if(a>=getArgentJoueur(j))
    {
        return ALL_IN;
    }




    return CALL;
}
