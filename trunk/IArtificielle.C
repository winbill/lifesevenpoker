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
                relance+=a;
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

