/**
	@brief Fichier C pour l'intelligence artificielle


	Gere les actions et reactions des joueurs de type 'ordinateur'.

	@author  James Benjamin
	@file IArtificielle.C
	@version 1.4
	@date 2008/05/23
 */

//Librairies Life'Seven Poker
#include "IArtificielle.h"
#include "AfficheTxt.h"


void calculIA(const Table & t,const Joueur & j,int montant,int &relance)
{
    montant=montant;
    getTablePot(t);
    //On récupere le statut de la partie:
    int nbCartesDecouvertes = getMainCarteNbCarte(*getMainCarteTable(t)); //Le nombre de cartes découvertes sur le tapis
    MainCarte mainJoueur = *getMainJoueur(j); //La main de cette IA
    MainCarte cartesDecouvertes = *getMainCarteTable(t); //La main contenant les cartes decouvertes sur la table
    Main res = determineMeilleureMainIA(mainJoueur,cartesDecouvertes); //Code du type de main obtenu

    //printf("resultat : %d\n",(int)res);

    float proba = probaActionIA(t,j,res); //La probabilité que la main actuelle du joueur soit la meilleure dans la partie.

    //printf("proba : %f \n", proba);

    int argent=getArgentJoueur(j); //l'argent actuel de l'IA

    //L'IA réagit selon le nombre de cartes découvertes dans un premier temps:
    switch (nbCartesDecouvertes)
    {
        //Au moment du pré FLOP
    case 0 :
        //si il a une paire
        if (getCarteRang(*getMainCarteIemeCarte(mainJoueur,0))==getCarteRang(*getMainCarteIemeCarte(mainJoueur,1)))
        {
            //si c'est une bonne paire
            if (getCarteRang(*getMainCarteIemeCarte(mainJoueur,1))>10)
            {
                //printf("%s a une bonne paire\n",j.pseudo);
                //ici et partout dans le reste de la fonction, relance n'est pas une relance mais une somme approximative du maximum qu'il est pres a mettre
                relance=100;
            }
            else
            {
                //printf("%s a une paire\n",j.pseudo);
                relance=20;
            }
        }
        //s'il a deux cartes de même couleure
        else if (getCarteCouleur(*getMainCarteIemeCarte(mainJoueur,0))==getCarteCouleur(*getMainCarteIemeCarte(mainJoueur,1)))
        {
            //si les deux cartes se suivent (et sont donc de même couleure
            if (getCarteRang(*getMainCarteIemeCarte(mainJoueur,0))==1+getCarteRang(*getMainCarteIemeCarte(mainJoueur,1)) or getCarteRang(*getMainCarteIemeCarte(mainJoueur,0))+1==getCarteRang(*getMainCarteIemeCarte(mainJoueur,1)))
            {
                //printf("%s a deux cartes qui se suivent de la meme couleure\n",j.pseudo);
                relance=getCarteRang(*getMainCarteIemeCarte(mainJoueur,0))*10;
            }
            else
            {
                //printf("%s a deux carte de la meme couleure\n",j.pseudo);
                relance=getCarteRang(*getMainCarteIemeCarte(mainJoueur,0))*4;
            }
        }
        //si il a deux cartes qui se suivent
        else if (getCarteRang(*getMainCarteIemeCarte(mainJoueur,0))==1+getCarteRang(*getMainCarteIemeCarte(mainJoueur,1)) or getCarteRang(*getMainCarteIemeCarte(mainJoueur,0))+1==getCarteRang(*getMainCarteIemeCarte(mainJoueur,1)))
        {
            //printf("%s a deux cartes qui se suivent\n",j.pseudo);
            relance=getCarteRang(*getMainCarteIemeCarte(mainJoueur,0))*7;
        }
        //on calcul la somme des deux rangs pour savoir si il a de bonnes cartes
        else if (getCarteRang(*getMainCarteIemeCarte(mainJoueur,0))+getCarteRang(*getMainCarteIemeCarte(mainJoueur,1))>20)
        {
            //printf("%s a deux bonnes cartes\n",j.pseudo);
            relance=(5*(getCarteRang(*getMainCarteIemeCarte(mainJoueur,0))+getCarteRang(*getMainCarteIemeCarte(mainJoueur,1))))/2;
        }
        //sinon il est pret a mettre le minimum pr voir le flop
        else
        {
            //printf("%s n'a rien\n",j.pseudo);
            relance=20;
        }
        break;

        //Au moment du FLOP
    case 3 :
        if (res == QUINTE_FLUSH_ROYALE or res == QUINTE_FLUSH)
        {
            //printf("%s a une quinte flush (royale?) \n", j.pseudo);
            relance=int(argent*proba); //il fait tapis
        }
        else if (res == CARRE)
        {
            //printf("%s a un carre  \n", j.pseudo);
            relance=int((argent/2)*proba);
        }
        else if (res == FULL)
        {
            //printf("%s a un full \n", j.pseudo);
            relance=int((argent/3)*proba);
        }
        else if (res == QUINTE or res == COULEUR)
        {
            //printf("%s a une quinte ou une couleur \n", j.pseudo);
            relance=int((argent/4)*proba);
        }

        else if (res == BRELAN)
        {
            //printf("%s a un brelan \n", j.pseudo);
            relance=int(100*proba);
        }
        else if (res == DOUBLE_PAIRE)
        {
            //printf("%s a une double paire \n", j.pseudo);
            relance=int(50*proba);
        }
        else if (res == PAIRE)
        {
            //printf("%s a une paire \n", j.pseudo);
            relance=int(20*proba);
        }
        else
        {
            //printf("%s n'a rien \n", j.pseudo);
            relance=int(0*proba);
        }
        break;

        //Au moment du TURN
    case 4 :
        if (res == QUINTE_FLUSH_ROYALE or res == QUINTE_FLUSH)
        {
            //printf("%s a une quinte flush (royale?) \n", j.pseudo);
            relance=int(argent*proba); //il fait tapis
        }
        else if (res == CARRE)
        {
            //printf("%s a un carre  \n", j.pseudo);
            relance=int((argent/2)*proba);
        }
        else if (res == FULL)
        {
            //printf("%s a un full \n", j.pseudo);
            relance=int((argent/3)*proba);
        }
        else if (res == QUINTE or res == COULEUR)
        {
            //printf("%s a une quinte ou une couleur \n", j.pseudo);
            relance=int((argent/4)*proba);
        }

        else if (res == BRELAN)
        {
            //printf("%s a un brelan \n", j.pseudo);
            relance=int(100*proba);
        }
        else if (res == DOUBLE_PAIRE)
        {
            //printf("%s a une double paire \n", j.pseudo);
            relance=int(50*proba);
        }
        else if (res == PAIRE)
        {
            //printf("%s a une paire \n", j.pseudo);
            relance=int(20*proba);
        }
        else
        {
            //printf("%s n'a rien \n", j.pseudo);
            relance=int(0*proba);
        }
        break;

        //Au moment du RIVER
    case 5 :
        //Si il a une quinte flush royale
        if (res == QUINTE_FLUSH_ROYALE or res == QUINTE_FLUSH)
        {
            //printf("%s a une quinte flush (royale?) \n", j.pseudo);
            relance=int(argent*proba); //il fait tapis
        }
        else if (res == CARRE)
        {
            //printf("%s a un carre  \n", j.pseudo);
            relance=int((argent/2)*proba);
        }
        else if (res == FULL)
        {
            //printf("%s a un full \n", j.pseudo);
            relance=int((argent/3)*proba);
        }
        else if (res == QUINTE or res == COULEUR)
        {
            //printf("%s a une quinte ou une couleur \n", j.pseudo);
            relance=int((argent/4)*proba);
        }

        else if (res == BRELAN)
        {
            //printf("%s a un brelan \n", j.pseudo);
            relance=int(100*proba);
        }
        else if (res == DOUBLE_PAIRE)
        {
            //printf("%s a une double paire \n", j.pseudo);
            relance=int(50*proba);
        }
        else if (res == PAIRE)
        {
            //printf("%s a une paire \n", j.pseudo);
            relance=int(20*proba);
        }
        else
        {
            //printf("%s n'a rien \n", j.pseudo);
            relance=int(0*proba);
        }
        break;
    }
}


void definieStatut(const Table & t,Statut & s,const Joueur & j,int montant,int & relance)
{
    int grosseBlind = getPetiteBlindTable(t)*2;
    //a represente le nombre de thune qu'il doit allonger pour suivre
    int a = montant - getMiseJoueur(j);
    if (relance > 0)
    {
        //si relance(largent qui est pres a mettre) est dans un intervalle de 20 par rapport a montant il suit
        if (relance < montant+grosseBlind and relance > montant-grosseBlind)
        {
            relance=0;
            s=CALL;
        }
        //si relance est superieur a montant plus la grosse blind
        else if (relance >= montant+grosseBlind)
        {
            //on verifie si y a sufissement de thne pr relancer
            if (getArgentJoueur(j) > ( a + relance))
            {
                relance=relance-montant;
                s=RAISE;
            }
            //sinon on regarde si on peut suivre
            else
            {
                if (getArgentJoueur(j) >=  a )
                {
                    relance=0;
                    s=CALL;
                }
                //sinon on se couche
                else
                {
                    relance=0;
                    s=FOLD;
                }
            }
        }
        else
        {
            relance=0;
            s=FOLD;
        }
    }
    //si relance egale 0, on essaye de suivre
    else if (relance==0)
    {
        //on verifie sil a assez de thune
        if (getArgentJoueur(j) >=  a )
        {
            relance=0;
            s=CALL;
        }
        else
        {
            relance=0;
            s=FOLD;
        }
    }
    else
    {
        relance=0;
        s=FOLD;
    }


}

Main determineMeilleureMainIA(const MainCarte & mainJoueur,const MainCarte & cartesDecouvertes)
{
    int nbCartesDecouvertes=getMainCarteNbCarte(cartesDecouvertes);
    //printf("nbCartesDecouvertes = %d \n", nbCartesDecouvertes);
    int nbCartesJoueur=getMainCarteNbCarte(mainJoueur);
    //printf("nbCartesJoueur = %d \n", nbCartesJoueur);
    int nbCartesTotal = nbCartesDecouvertes + nbCartesJoueur;
    //printf("nbCartesTotal = %d \n", nbCartesTotal);

    switch (nbCartesTotal)
    {
    case 2 :
    {
        //printf("=====================+DEBUT CASE 2+===================== \n");


    }
    break;

//=====================================================================================================================>

    case 5 :
    {

                //printf("=====================+DEBUT CASE 5+===================== \n");
                //afficheMainCarte(mainJoueur,"mainJoueur");
                //afficheMainCarte(cartesDecouvertes,"cartesDecouvertes");

                //On cree un histogramme pour referencer les cartes
                int histogramme[5][2]={{0,0},{0,0},{0,0},{0,0},{0,0}};
                int h=0;
                int i=0;
                //On stocke les cartes de la main du joueur dans l'histogramme
                //printf("PREMIER WHILE \n");
                while (i < 2)
                {
                    //printf("HISTO avec i = %d ==> [%d][0] = %d \n", i, h, histogramme[h][0]);
                    if (histogramme[h][0]==0)
                    {
                        //printf("HISTO IF 1 ==> rang de la %d eme carte : %d | valeur de h : %d \n", i , getCarteRang(*getMainCarteIemeCarte(mainJoueur,i)), h);
                        histogramme[h][0]=getCarteRang(*getMainCarteIemeCarte(mainJoueur,i));
                        histogramme[h][1]++;
                        i++;
                        h=0;
                    }
                    else if (histogramme[h][0]==getCarteRang(*getMainCarteIemeCarte(mainJoueur,i)))
                    {
                        //printf("HISTO IF 2 ==> rang de la %d eme carte : %d | valeur de h : %d \n", i , getCarteRang(*getMainCarteIemeCarte(mainJoueur,i)), h);
                        histogramme[h][1]++;
                        i++;
                        h=0;
                    }
                    else h++;
                }



                //On stocke les cartes en jeu découvertes dans l'histogramme
                int j=0;
                //printf("DEUXIEME WHILE \n");
                while (j<3)
                {
                    //printf("HISTO avec j = %d ==> [%d][0] = %d \n", j, h, histogramme[h][0]);
                    if (histogramme[h][0]==0)
                    {
                        //printf("HISTO IF 1 ==> rang de la %d eme carte : %d  | valeur de h : %d \n", j , getCarteRang(*getMainCarteIemeCarte(cartesDecouvertes,j)), h);
                        histogramme[h][0]=getCarteRang(*getMainCarteIemeCarte(cartesDecouvertes,j));
                        histogramme[h][1]++;
                        j++;
                        h=0;
                    }
                    else if (histogramme[h][0]==getCarteRang(*getMainCarteIemeCarte(cartesDecouvertes,j)))
                    {
                        //printf("HISTO IF 2 ==> rang de la %d eme carte : %d | valeur de h : %d \n", j , getCarteRang(*getMainCarteIemeCarte(cartesDecouvertes,j)), h);
                        histogramme[h][1]++;
                        j++;
                        h=0;
                    }
                    else
                    {
                        h++;
                        //printf("HISTO IF 3 ==> rang de la %d eme carte : %d | valeur de h : %d \n", j , getCarteRang(*getMainCarteIemeCarte(cartesDecouvertes,j)), h);
                    }
                }


                //On trie l'histogramme par valeurs décroissantes au niveau du nombre d'occurence des cartes
                //printf("DEBUT DU TRI DE L'HISTOGRAMME \n");
                int indice=0;
                int max=0;
                for (j=0;j<4;j++)
                {
                    for (i=indice;i<4;i++)
                    {
                        if (histogramme[i+1][1]>histogramme[max][1])
                        {
                            max=i+1;
                        }
                    }

                    int temp[2]={histogramme[max][0],histogramme[max][1]};
                    histogramme[max][0]=histogramme[indice][0];
                    histogramme[max][1]=histogramme[indice][1];
                    histogramme[indice][0]=temp[0];
                    histogramme[indice][1]=temp[1];

                    indice++;
                    max=indice;
                }

                //On vérifie avec les valeurs de l'histogramme certaines possibilités de mains
                if (histogramme[0][1]==4) return CARRE;
                else if (histogramme[0][1]==3 and histogramme[1][1]==2) return FULL;
                else if (histogramme[0][1]==3 and histogramme[1][1]==1) return BRELAN;
                else if (histogramme[0][1]==2 and histogramme[1][1]==2) return DOUBLE_PAIRE;
                else if (histogramme[0][1]==2) return PAIRE;


                //On trie maintenant l'histogramme par valeurs décroissantes au niveau du rang des cartes
                indice=0;
                max=0;
                for (j=0;j<4;j++)
                {
                    for (i=indice;i<4;i++)
                    {
                        if (histogramme[i+1][0]>histogramme[max][0])
                        {
                            max=i+1;
                        }
                    }

                    int temp[2]={histogramme[max][0],histogramme[max][1]};
                    histogramme[max][0]=histogramme[indice][0];
                    histogramme[max][1]=histogramme[indice][1];
                    histogramme[indice][0]=temp[0];
                    histogramme[indice][1]=temp[1];

                    indice++;
                    max=indice;
                }

                //On vérifie si c'est une couleur (vive les boucles)
                bool flush=0;
                if (getCarteCouleur(*getMainCarteIemeCarte(mainJoueur,0))==getCarteCouleur(*getMainCarteIemeCarte(mainJoueur,1))
                        and getCarteCouleur(*getMainCarteIemeCarte(mainJoueur,1))==getCarteCouleur(*getMainCarteIemeCarte(cartesDecouvertes,0))
                        and getCarteCouleur(*getMainCarteIemeCarte(cartesDecouvertes,0))==getCarteCouleur(*getMainCarteIemeCarte(cartesDecouvertes,1))
                        and getCarteCouleur(*getMainCarteIemeCarte(cartesDecouvertes,1))==getCarteCouleur(*getMainCarteIemeCarte(cartesDecouvertes,2)))
                {
                    flush=1;
                }

                //On trie les 5 cartes dans un tableau
                int tab[5]={getCarteRang(*getMainCarteIemeCarte(mainJoueur,0)),
                            getCarteRang(*getMainCarteIemeCarte(mainJoueur,1)),
                            getCarteRang(*getMainCarteIemeCarte(cartesDecouvertes,0)),
                            getCarteRang(*getMainCarteIemeCarte(cartesDecouvertes,1)),
                            getCarteRang(*getMainCarteIemeCarte(cartesDecouvertes,2))
                           };

                indice=0;
                max=0;
                for (j=0;j<4;j++)
                {
                    for (i=indice;i<4;i++)
                    {
                        if (tab[i+1]>tab[max])
                        {
                            max=i+1;
                        }
                    }

                    int temp=tab[max];
                    tab[max]=tab[indice];
                    tab[indice]=temp;

                    indice++;
                    max=indice;
                }

                //On vérifie si c'est une suite
                bool straight=0;
                bool royal=0;
                if (tab[0]-tab[4]==4)
                {
                    if (tab[0]==14)
                    {
                        royal=1; //royal straight
                    }
                    straight=1; //straight
                }
                else if (tab[0]==14 and tab[1]==5 and tab[4]==2) straight=1; //wheel

                //On vérifie si c'est une couleur/suite particuliere
                if (flush and straight and royal) return QUINTE_FLUSH_ROYALE;
                if (flush and straight) return QUINTE_FLUSH;
                if (flush) return COULEUR;
                if (straight) return QUINTE;

                //printf("<<<<<<<<     <<<<<<<< SORTIE 5\n");
                //Enfin si aucun des cas précédents n'a correspondu c'est une carte haute
                return CARTE_HAUTE;

    }
    break;

//=====================================================================================================================>

    case 6 :
    {
        //printf("=====================+DEBUT CASE 6+===================== \n");

        //On recupere toutes les combinaisons de 5 cartes parmi 6
        int i,j,k;
        //On travaille sur des mains temporaires
        MainCarte mainTotale;
        initialisationMain(mainTotale);
        MainCarte mainTest1,mainTest2;
        initialisationMain(mainTest1);
        initialisationMain(mainTest2);
        Main meilleureMain=CARTE_HAUTE;
        Main resultatMain=DEF;

        //afficheMainCarte(mainTotale,"mainTotale AVANT ajout");
        //afficheMainCarte(mainTest1,"mainTest1 AVANT ajout");
        //afficheMainCarte(mainTest2,"mainTest2 AVANT ajout");
        //afficheMainCarte(mainJoueur,"mainJoueur dans Case 6");
        //afficheMainCarte(cartesDecouvertes,"cartesDecouvertes dans Case 6");

        ajouteCarte(mainTotale,getMainCarteIemeCarte(mainJoueur,0));
        ajouteCarte(mainTotale,getMainCarteIemeCarte(mainJoueur,1));
        ajouteCarte(mainTotale,getMainCarteIemeCarte(cartesDecouvertes,0));
        ajouteCarte(mainTotale,getMainCarteIemeCarte(cartesDecouvertes,1));
        ajouteCarte(mainTotale,getMainCarteIemeCarte(cartesDecouvertes,2));
        ajouteCarte(mainTotale,getMainCarteIemeCarte(cartesDecouvertes,3));

        //afficheMainCarte(mainTotale,"mainTotale APRES ajout");

        for (i=0;i<6;i++)
        {
            k=0;
            for (j=0;j<6;j++)
            {
                if (j!=i)
                {
                    if (j<2+k)
                    {
                        ajouteCarte(mainTest1,getMainCarteIemeCarte(mainTotale,j));
                    }
                    else
                    {
                        ajouteCarte(mainTest2,getMainCarteIemeCarte(mainTotale,j));
                    }
                }
                else k++;
            }

            //afficheMainCarte(mainTest1,"mainTest1 APRES ajout");
            //afficheMainCarte(mainTest2,"mainTest2 APRES ajout");

            resultatMain=determineMeilleureMainIA(mainTest1,mainTest2);
            reinitialisationMain(mainTest1);
            reinitialisationMain(mainTest2);

            if (resultatMain>meilleureMain)
            {
                meilleureMain=resultatMain;
            }
        }
        MainCarteLibere(mainTest1);
        MainCarteLibere(mainTest2);
        MainCarteLibere(mainTotale);



        //printf("<<<<<<<<     <<<<<<<< SORTIE 6\n");

        return meilleureMain;
    }
    break;
//=====================================================================================================================>

    case 7 :
    {
        //printf("=====================+DEBUT CASE 7+===================== \n");

        //On recupere toutes les combinaisons de 5 cartes parmi 6
        int i,j,k,l;
        //On travaille sur des mains temporaires
        MainCarte mainTotale;
        initialisationMain(mainTotale);
        MainCarte mainTest1,mainTest2;
        initialisationMain(mainTest1);
        initialisationMain(mainTest2);
        Main meilleureMain=CARTE_HAUTE;
        Main resultatMain=DEF;

        //afficheMainCarte(mainTotale,"mainTotale AVANT ajout");
        //afficheMainCarte(mainTest1,"mainTest1 AVANT ajout");
        //afficheMainCarte(mainTest2,"mainTest2 AVANT ajout");
        //afficheMainCarte(mainJoueur,"mainJoueur dans Case 7");
        //afficheMainCarte(cartesDecouvertes,"cartesDecouvertes dans Case 7");

        ajouteCarte(mainTotale,getMainCarteIemeCarte(mainJoueur,0));
        ajouteCarte(mainTotale,getMainCarteIemeCarte(mainJoueur,1));
        ajouteCarte(mainTotale,getMainCarteIemeCarte(cartesDecouvertes,0));
        ajouteCarte(mainTotale,getMainCarteIemeCarte(cartesDecouvertes,1));
        ajouteCarte(mainTotale,getMainCarteIemeCarte(cartesDecouvertes,2));
        ajouteCarte(mainTotale,getMainCarteIemeCarte(cartesDecouvertes,3));
        ajouteCarte(mainTotale,getMainCarteIemeCarte(cartesDecouvertes,4));

        //afficheMainCarte(mainTotale,"mainTotale APRES ajout");

        for (i=0;i<7;i++)
        {
            for (k=i+1;k<7;k++)
            {
                l=0;
                for (j=0;j<7;j++)
                {
                    if (j!=i and j!=k)
                    {
                        if (j<2+l)
                        {
                            ajouteCarte(mainTest1,getMainCarteIemeCarte(mainTotale,j));
                        }
                        else
                        {
                            ajouteCarte(mainTest2,getMainCarteIemeCarte(mainTotale,j));
                        }
                    }
                    else l++;
                }

                //afficheMainCarte(mainTest1,"mainTest1 APRES ajout");
                //afficheMainCarte(mainTest2,"mainTest2 APRES ajout");

                resultatMain=determineMeilleureMainIA(mainTest1,mainTest2);
                reinitialisationMain(mainTest1);
                reinitialisationMain(mainTest2);

                if (resultatMain>meilleureMain)
                {
                    meilleureMain=resultatMain;
                }
            }
        }
        MainCarteLibere(mainTest1);
        MainCarteLibere(mainTest2);
        MainCarteLibere(mainTotale);





        //printf("<<<<<<<<     <<<<<<<< SORTIE CASE 7\n");

        return meilleureMain;
    }
    break;
    }
    //printf("<<<<<<<<     <<<<<<<< SORTIE FCT\n");

    return DEF;
}


float probaActionIA(const Table & table, const Joueur & joueur,Main meilleureMainJoueur)
{
    int i,j,k; //variables de boucle
    Carte c1,c2; //Represente deux cartes potentiellement dans la main d'un adversaire

    //int nbtest=0;

    initialisationCarte(c1);
    initialisationCarte(c2);

    MainCarte mainJoueur = *getMainJoueur(joueur); //On récupere les cartes que le joueur a en main
    MainCarte cartesDecouvertes = *getMainCarteTable(table); //On récupere les cartes du tapis
    int nbCartesDecouvertes = getMainCarteNbCarte(cartesDecouvertes); //On récupere aussi le nombre de cartes du tapis

    //On crée une pile de cartes temporaire et on la rempli des 52 cartes d'un jeu standard
    PileCarte ptemp;
    initPileCarte(ptemp);

    //Variable qui compte le nombres de situations dans lesquelles le joueur est vainqueur a coup sur.
    int compteur=0;

    //On parcourre toutes les combinaisons possibles de deux cartes parmi 52
    for (i=0;i<52;i++)
    {
        for (j=i+1;j<52;j++)
        {
            if(i!=j)
            {

                setCarte(c1,getCarteCouleur(*ptemp.ensembleCarte[i]),getCarteRang(*ptemp.ensembleCarte[i]));
                setCarte(c2,getCarteCouleur(*ptemp.ensembleCarte[j]),getCarteRang(*ptemp.ensembleCarte[j]));

                bool okc1 = true; //Est vrai tant que la carte c1 n'a pas été trouvé dans la main du joueur ou sur le tapis
                bool okc2 = true; //Idem pour c2


                //On teste si la carte c1 n'est pas dans la main du joueur ou sur le tapis
                for (k=0;k<getMainCarteNbCarte(*getMainCarteTable(table))+2;k++)
                {
                    if (k<2)
                    {
                        int comp = compareCarte(c1,*getMainCarteIemeCarte(mainJoueur,k));
                        if (comp == 2)
                        {
                            okc1 = false;
                        }
                    }
                    else
                    {
                        int comp = compareCarte(c1,*getMainCarteIemeCarte(cartesDecouvertes,k-2));
                        if (comp == 2)
                        {
                            okc1 = false;
                        }
                    }
                }

                //On fait pareil pour la carte c2
                for (k=0;k<getMainCarteNbCarte(*getMainCarteTable(table))+2;k++)
                {
                    if (k<2)
                    {
                        int comp = compareCarte(c2,*getMainCarteIemeCarte(mainJoueur,k));
                        if (comp == 2)
                        {
                            okc2 = false;
                        }
                    }
                    else
                    {
                        int comp = compareCarte(c2,*getMainCarteIemeCarte(cartesDecouvertes,k-2));
                        if (comp == 2)
                        {
                            okc2 = false;
                        }
                    }
                }


                //Dans le cas ou le couple c1 c2 est une des possibilités de main adverse alors on procède aux tests.
                if (okc1 and okc2)
                {
                    //On crée une main de test
                    MainCarte mainTest;
                    initialisationMain(mainTest);

                    //On y ajoute nos deux cartes c1 et c2
                    ajouteCarte(mainTest,&c1);
                    ajouteCarte(mainTest,&c2);

                    Main res = DEF;
                    res = determineMeilleureMainIA(mainTest,cartesDecouvertes); //On regarde quelle hauteur de main cela donnerai avec le tapis courrant

                    if (res < meilleureMainJoueur)
                    {
                        //Si cela donne une main moins bonne que celle du joueur alors on incrémente le compteur
                        compteur++;
                        //printf("%d ",compteur);

                    }
                    MainCarteLibere(mainTest);
                }


            }

            //nbtest++;
            //printf(" i : %d  | j : %d \n", i, j);

        }
    }

    float possibilites = (((50 - nbCartesDecouvertes) * (49 - nbCartesDecouvertes)) / 2);

    //On calcule enfin la probabilité qu'a le joueur de gagner à coup sur avec sa main et le tapîs courrant
    float proba = compteur / possibilites ;

    //printf("nb de test: %d \n",nbtest);
    //printf("nbCartesDecouvertes : %d \n", nbCartesDecouvertes);
    //printf("temp : %f\n",temp);

    pileCarteLibere(ptemp);

    //Et on retourne cette valeur
    return proba;

}



