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
#include "IArtificielle.h"
#include "Controles.h"


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
		ajouteCarte(*getMainJoueur(*getIemeJoueur(table,i)),*tirerCarte(*getTablePileCarteTable(table)));
		ajouteCarte(*getMainJoueur(*getIemeJoueur(table,i)),*tirerCarte(*getTablePileCarteTable(table)));
	}
}


void distribuer1CarteDecouverteJeu(Table & table,int n)
{
	ajouteCarte(*getMainCarteTable(table),*tirerCarte(*getTablePileCarteTable(table)));
}

void lanceJeu(Table & table)
{
	int i;
	//nouvelle pile de carte pleine
	nouvellePileCarte(table);
	//remise a zero des mains des autres joueurs
	for(i=0;i<getNJoueurTable(table);i++);
	{
		initialisationMain(*getMainJoueur(*getIemeJoueur(table,i)))
	}
	//remise des cartes decouvertes a 0
	initialisationMain(*getMainCarteTable(table));
	//change la position du dealer
	changeDealerTable(table);

}

/**	@brief donne la victoire a un (ou plus) joueur(s)
	@param [in, out] table une table
	@note analyse la (ou les) main(s) gagnante et répartie le pot en fonction
*/
void donneVictoireJeu(Table & table)
{


}

/** @brief fonction qui attent une action d'une personne humaine
	@param [in] table une table qui normellement n'est pas modifiee
	@param [in, out] Joueur un joueur
	@return entier de notification : relance -> 1, reste dans leu sans relance -> 0, quit ->-1
	@note   cette fonction appel actionJoueurJeu(...) pour les
            modifications du joueur
*/
int atendActionJoueurHumain(const Table & table,Joueur & joueur)
{


}

/**	@brief fonction utilise lorsque le joueur change de status
	@param [in, out] table une table
	@param [in, out] joueur sujet de l'action
	@param [in] statut son nouveau statut
	@param [in] n s'il relance on met le montant dedans
*/
void actionJoueurJeu(Table & table,Joueur & joueur,Statut statut,int n)
{



}

/**	@brief interroge les joueurs tours à tours
	@param [in, out] table une table

	s'arrete lorsque les mises sont egales
*/
void lanceTourJeu(Table & table)
{
    int k=getNJoueurTable(table)+2; //on fait joueur les PB et GB deux fois
    //au premier tour
    int i;

    while(k>0)
    {
        if(ta


    }


}




int codageScoreMain(const MainCarte &m, int & tabResultat[6],const Table & table)
{
    int i;
    //on utilise un tableau a 2 dimensions representant les 7 cartes (8 car l'as peut etre rajouter une deuxieme fois)
    int tabMainTotale[8][2];
    //on recupere les deux cartes du joueur
    tabMainTotale[0][0] = getCarteRang(*(m.tabMain[0]));
    tabMainTotale[0][1] = getCarteCouleur(*(m.tabMain[0]));
    tabMainTotale[1][0] = getCarteRang(*(m.tabMain[0]));
    tabMainTotale[1][1] = getCarteCouleur(*(m.tabMain[0]));
    //plus les 5 cartes decouvertes
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

    //on regarde en 1er s'il y a une couleure
    couleur = couleurMainCarte(tabMainTotale);
    //one ragarde s'il y a une quinte
    quinte = suiteMainCarte(tabMainTotale);

    //sil y a une quinte et une couleur on regarde s'il y a une quinte flush
    if((couleur!=0)&&(quinte!=0))
    {
        if(testquinteflush()!=0)
        {
            tabResultat[0] = 8 ou 9;
            ...
            return;
        }
    }
    //s'il y a qu'une couleure c'est la meillleur possibilité
    if(couleur != 0)
    {
        tabResultat[0] = 5;
        //on doit prendre les 5 meilleurs cartes de la couleur correspondante
        tabResultat[1...6] =...;



        return 1; //on renvoit 1 pour quitter la fonction

    }
    //s'il y a qu'une suite c'est la meilleur possibilité
    if(quinte != 0)
    {
        tabResultat[0] = 4;
        //on doit prendre les 5 cartes de la suite
        // /!\ il faut verifier que yen ai pas deux egale
        // cas 10 9 9 8 7 6 2 1 -> 10 9 8 7 6 et non 10 9 9 8 7
        ...;
        tabResultat[1] =quinte;
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

