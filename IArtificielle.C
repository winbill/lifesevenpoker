#include "IArtificielle.h"

Statut calculIA(const Table & t,const Joueur & j,int &relance,int & montant)
{
    //On récupere le statut de la partie:
    int nbCartesDecouvertes = getMainCarteNbCarte(*getMainCarteTable(t)); //Le nombre de cartes découvertes sur le tapis
    MainCarte mainJoueur = *getMainJoueur(j); //La main de cette IA
    int miseJoueur = getMiseJoueur(j); //La mise actuelle de cette IA dans ce tour
    int argentJoueur = getArgentJoueur(j); //L'argent de cette IA
    int differenceMiseMontant = montant-getMiseJoueur(j); //Difference d'argent entre ce qu'a déjà misé l'IA et le montant de la mise actuelle

    printf("-------------------- Joueur %d --------------------- \n",getIdJoueur(j));
    printf("VALEUR RELANCE : %d \t VALEUR MONTANT : %d \n", relance, montant);
    printf("---------------------------------\n| nbCartesDecouvertes : %d |\n ---------------------------------\n", nbCartesDecouvertes);
    printf("miseJoueur : %d \n", miseJoueur);
    printf("montant : %d \n", montant);
    printf("differenceMiseMontant : %d \n", differenceMiseMontant);

    //L'IA réagit selon le nombre de cartes découvertes dans un premier temps:
    switch (nbCartesDecouvertes)
    {
        //Au moment du pré FLOP
    case 0 :

        if (miseJoueur == montant)
        {
            printf("CHECK \n");    //Soit le joueur est au niveau de la mise et il check
            return CHECK;
        }

        else if (differenceMiseMontant <= argentJoueur and montant <= getPetiteBlindTable(t)*2)
        {
            printf("CALL \n");    //Soit il suis au niveau des blinds si il peut
            return CALL;
        }

        else
        {
            printf("FOLD \n");    //Soit il se couche
            return FOLD;
        }
        break;

        //Au moment du FLOP
    case 3 :

        if (argentJoueur <= montant) //Si il n'est pas riche par rapport à ce qui se joue
        {
            if (getCarteRang(*getMainCarteIemeCarte(mainJoueur,0)) == getCarteRang(*getMainCarteIemeCarte(mainJoueur,1))) //Il tente quand même l'aventure en cas de paire à la donne ...
            {
                if (differenceMiseMontant >= argentJoueur) // ... selon si il a assez d'argent pour suivre ...
                {
                    return ALL_IN; // ... il fait tapis
                }
                else
                {
                    if (differenceMiseMontant <= argentJoueur)
                    {
                        return CALL;  // ... ou bien suis simplement
                    }
                    else return CHECK; // ... ou alors il check
                }
            }
            else return FOLD; //Sinon il se couche
        }

        if (differenceMiseMontant <= argentJoueur and argentJoueur >= montant*2 and argentJoueur > 800) //Si il a plein de tunes
        {
            relance = 50;
            printf("===========================================%d:%d\n",montant*2,miseJoueur);

            return RAISE;  // ... il relance
        }

        else  //Et le reste du temps ...
        {
            if (miseJoueur == montant) return CHECK; // ... il check pour rester dans la partie

            else if (miseJoueur < montant) return CALL; // ... ou alors il suis pour tenter sa chance plus tard
        }
        break;

        //Au moment du TURN
    case 4 :

        if (argentJoueur <= montant) //Si il n'est pas riche par rapport à ce qui se joue
        {
            if (getCarteRang(*getMainCarteIemeCarte(mainJoueur,0)) == getCarteRang(*getMainCarteIemeCarte(mainJoueur,1))) //Il tente quand même l'aventure en cas de paire à la donne ...
            {
                if (differenceMiseMontant >= argentJoueur) // ... selon si il a assez d'argent pour suivre ...
                {
                    return ALL_IN; // ... il fait tapis
                }
                else
                {
                    if (differenceMiseMontant <= argentJoueur)
                    {
                        return CALL;  // ... ou bien suis simplement
                    }
                    else return CHECK; // ... ou alors il check
                }
            }
            else return FOLD; //Sinon il se couche
        }

        if (differenceMiseMontant <= argentJoueur and argentJoueur >= montant*2 and argentJoueur > 500) //Si il a plein de tunes
        {
            relance = montant*2 - miseJoueur;

            return RAISE;  // ... il relance
        }

        else  //Et le reste du temps ...
        {
            if (miseJoueur == montant) return CHECK; // ... il check pour rester dans la partie

            else if (miseJoueur < montant) return CALL; // ... ou alors il suis pour tenter sa chance plus tard
        }
        break;

        //Au moment du RIVER
    case 5 :

        if (argentJoueur <= montant) //Si il n'est pas riche par rapport à ce qui se joue
        {
            if (getCarteRang(*getMainCarteIemeCarte(mainJoueur,0)) == getCarteRang(*getMainCarteIemeCarte(mainJoueur,1))) //Il tente quand même l'aventure en cas de paire à la donne ...
            {
                if (differenceMiseMontant >= argentJoueur) // ... selon si il a assez d'argent pour suivre ...
                {
                    return ALL_IN; // ... il fait tapis
                }
                else
                {
                    if (differenceMiseMontant <= argentJoueur)
                    {
                        return CALL;  // ... ou bien suis simplement
                    }
                    else return CHECK; // ... ou alors il check
                }
            }
            else return FOLD; //Sinon il se couche
        }

        if (differenceMiseMontant <= argentJoueur and argentJoueur >= montant*2 and argentJoueur > 500) //Si il a plein de tunes
        {
            relance = montant*2 - miseJoueur;

            return RAISE;  // ... il relance
        }

        else  //Et le reste du temps ...
        {
            if (miseJoueur == montant) return CHECK; // ... il check pour rester dans la partie

            else if (miseJoueur < montant) return CALL; // ... ou alors il suis pour tenter sa chance plus tard
        }
        break;


    }
    return FOLD;
    //Fin du switch
}
Statut calculIAJames(const Table & t,const Joueur & j,int montant,int &relance)
{
    //On récupere le statut de la partie:
    int nbCartesDecouvertes = getMainCarteNbCarte(*getMainCarteTable(t)); //Le nombre de cartes découvertes sur le tapis
    MainCarte mainJoueur = *getMainJoueur(j); //La main de cette IA

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
                printf("%s a une bonne paire\n",j.pseudo);
				//ici et partout dans le reste de la fonction, relance n'est pas une relance mais une somme approximative du maximum qu'il est pres a mettre
                relance=100;
            }
            else
            {
                printf("%s a une paire\n",j.pseudo);
                relance=20;
            }
        }
		//s'il a deux cartes de même couleure
        else if (getCarteCouleur(*getMainCarteIemeCarte(mainJoueur,0))==getCarteCouleur(*getMainCarteIemeCarte(mainJoueur,1)))
        {
			//si les deux cartes se suivent (et sont donc de même couleure
            if (getCarteRang(*getMainCarteIemeCarte(mainJoueur,0))==1+getCarteRang(*getMainCarteIemeCarte(mainJoueur,1)) or getCarteRang(*getMainCarteIemeCarte(mainJoueur,0))+1==getCarteRang(*getMainCarteIemeCarte(mainJoueur,1)))
            {
                printf("%s a deux cartes qui se suivent de la meme couleure\n",j.pseudo);
                relance=getCarteRang(*getMainCarteIemeCarte(mainJoueur,0))*10;
            }
            else
            {
                printf("%s a deux carte de la meme couleure\n",j.pseudo);
                relance=getCarteRang(*getMainCarteIemeCarte(mainJoueur,0))*4;
            }
        }
		//si il a deux cartes qui se suivent
        else if (getCarteRang(*getMainCarteIemeCarte(mainJoueur,0))==1+getCarteRang(*getMainCarteIemeCarte(mainJoueur,1)) or getCarteRang(*getMainCarteIemeCarte(mainJoueur,0))+1==getCarteRang(*getMainCarteIemeCarte(mainJoueur,1)))
        {
            printf("%s a deux cartes qui se suivent\n",j.pseudo);
            relance=getCarteRang(*getMainCarteIemeCarte(mainJoueur,0))*7;
        }
		//on calcul la somme des deux rangs pour savoir si il a de bonnes cartes
        else if (getCarteRang(*getMainCarteIemeCarte(mainJoueur,0))+getCarteRang(*getMainCarteIemeCarte(mainJoueur,1))>20)
        {
            printf("%s a deux bonnes cartes\n",j.pseudo);
            relance=(5*(getCarteRang(*getMainCarteIemeCarte(mainJoueur,0))+getCarteRang(*getMainCarteIemeCarte(mainJoueur,1))))/2;
        }
		//sinon il est pret a mettre le minimum pr voir le flop
        else
        {
            printf("%s n'a rien\n",j.pseudo);
            relance=20;
        }
        break;

        //Au moment du FLOP
    case 3 :

        //test de forme sur cinq cartes
        break;

        //Au moment du TURN
    case 4 :

        //test de forme sur 6 cartes
        break;

        //Au moment du RIVER
    case 5 :

        //test sur 7 cartes
        break;



    }
    return FOLD;
}


void definieStatut(const Table & t,Statut & s,const Joueur & j,int montant,int & relance)
{
	//a represente le nombre de thune qu'il doit allonger pour suivre
    int a = montant - getMiseJoueur(j);
    if (relance > 0)
    {
		//si relance(largent qui est pres a mettre) est dans un intervalle de 20 par rapport a montant il suit
        if (relance < montant+20 and relance > montant-20 )
        {
            relance=0;
            s=CALL;
        }
		//si relance est superieur a montant plus la grosse blind
        else if (relance >= montant+20)
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
    int nbCartesTotal = nbCartesDecouvertes + 2;

    switch(nbCartesTotal)
    {
        case 2 :
        {

        }
        break;

//=====================================================================================================================>

        case 5 :
        {
            //On cree un histogramme pour referencer les cartes
            int histogramme[5][2]={{0,0},{0,0},{0,0},{0,0},{0,0}};
            int h=0;
            int i=0;
            //On stocke les cartes de la main du joueur dans l'histogramme
            while(i < 2)
            {
                if(histogramme[h][0]==0)
                {
                    histogramme[h][0]=getCarteRang(*getMainCarteIemeCarte(mainJoueur,i));
                    histogramme[h][1]++;
                    i++;
                    h=0;
                }
                else if(histogramme[h][0]==getCarteRang(*getMainCarteIemeCarte(mainJoueur,i)))
                {
                    histogramme[h][1]++;
                    i++;
                    h=0;
                }
                else h++;
            }
            //On stocke les cartes en jeu découvertes dans l'histogramme
            int j=0;
            while(j<3)
            {
                if(histogramme[h][0]==0)
                {
                    histogramme[h][0]=getCarteRang(*getMainCarteIemeCarte(cartesDecouvertes,i));
                    histogramme[h][1]++;
                    i++;
                    h=0;
                }
                else if(histogramme[h][0]==getCarteRang(*getMainCarteIemeCarte(cartesDecouvertes,i)))
                {
                    histogramme[h][1]++;
                    i++;
                    h=0;
                }
                else h++;
            }
            //On trie l'histogramme par valeurs décroissantes au niveau du nombre d'occurence des cartes
            int indice=0;
            int max=0;
            for(j=0;j<4;j++)
            {
                for(i=indice;i<4;i++)
                {
                    if(histogramme[i+1][1]>histogramme[max][1])
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
            if(histogramme[0][1]==4) return FOUR_OF_A_KIND;
            else if(histogramme[0][1]==3 and histogramme[1][1]==2) return FULL_HOUSE;
            else if(histogramme[0][1]==3 and histogramme[1][1]==1) return THREE_OF_A_KIND;
            else if(histogramme[0][1]==2 and histogramme[1][1]==2) return TWO_TWO_OF_A_KIND;
            else if(histogramme[0][1]==2) return TWO_OF_A_KIND;

            //On trie maintenant l'histogramme par valeurs décroissantes au niveau du rang des cartes
            indice=0;
            max=0;
            for(j=0;j<4;j++)
            {
                for(i=indice;i<4;i++)
                {
                    if(histogramme[i+1][0]>histogramme[max][0])
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

            //On vérifie si c'est une couleur
            bool flush=0;
            if(getCarteCouleur(*getMainCarteIemeCarte(mainJoueur,0))==getCarteCouleur(*getMainCarteIemeCarte(mainJoueur,1))
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
                        getCarteRang(*getMainCarteIemeCarte(cartesDecouvertes,2))};

            indice=0;
            max=0;
            for(j=0;j<4;j++)
            {
                for(i=indice;i<4;i++)
                {
                    if(tab[i+1]>tab[max])
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
            if(tab[0]-tab[4]==4)
            {
                if(tab[0]==14)
                {
                    royal=1; //royal straight
                }
                straight=1; //straight
            }
            else if(tab[0]==14 and tab[1]==5 and tab[4]==2) straight=1; //wheel

            //On vérifie si c'est une couleur/suite particuliere
            if(flush and straight and royal) return ROYAL_STRAIGHT_FLUSH;
            if(flush and straight) return STRAIGHT_FLUSH;
            if(flush) return FLUSH;
            if(straight) return STRAIGHT;

            //Enfin si aucun des cas précédents n'a correspondu c'est une carte haute
            return HIGH_CARD;
        }
        break;

//=====================================================================================================================>

        case 6 :
        {
            //On recupere toutes les combinaisons de 5 cartes parmi 6
            int i,j,k;
            //On travaille sur des mains temporaires
            MainCarte mainTotale;
            MainCarte mainReduite;
            MainCarte mainTest1,mainTest2;

            Main meilleureMain=HIGH_CARD;
            Main resultatMain=DEF;

            ajouteCarte(mainTotale,getMainCarteIemeCarte(mainJoueur,0));
            ajouteCarte(mainTotale,getMainCarteIemeCarte(mainJoueur,1));
            ajouteCarte(mainTotale,getMainCarteIemeCarte(cartesDecouvertes,0));
            ajouteCarte(mainTotale,getMainCarteIemeCarte(cartesDecouvertes,1));
            ajouteCarte(mainTotale,getMainCarteIemeCarte(cartesDecouvertes,2));
            ajouteCarte(mainTotale,getMainCarteIemeCarte(cartesDecouvertes,3));

            for(i=0;i<6;i++)
            {
                for(j=0;j<6;j++)
                {
                    if(j!=i)
                    {
                        ajouteCarte(mainReduite,getMainCarteIemeCarte(mainTotale,j));
                    }
                }
                for(k=0;k<5;k++)
                {
                    if(k<2)
                    {
                        ajouteCarte(mainTest1,getMainCarteIemeCarte(mainReduite,k));
                    }
                    else
                    {
                        ajouteCarte(mainTest2,getMainCarteIemeCarte(mainReduite,k));
                    }
                }

                resultatMain=determineMeilleureMainIA(mainTest1,mainTest2);

                if(resultatMain>meilleureMain)
                {
                    meilleureMain=resultatMain;
                }
            }

            return meilleureMain;
        }
        break;

//=====================================================================================================================>

        case 7 :
        {

        }
        break;

    }

    return DEF;
}



