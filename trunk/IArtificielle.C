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
    printf("argentJoueur : %d \n", argentJoueur);
    printf("differenceMiseMontant : %d \n", differenceMiseMontant);

    //L'IA réagit selon le nombre de cartes découvertes dans un premier temps:
    switch (nbCartesDecouvertes)
    {
        //Au moment du pré FLOP
        case 0 :
        {
            if (miseJoueur == montant){ printf("CHECK \n"); return CHECK;} //Soit le joueur est au niveau de la mise et il check

            else if (differenceMiseMontant <= argentJoueur and montant <= getPetiteBlindTable(t)*2) {printf("CALL \n"); return CALL;}//Soit il suis au niveau des blinds si il peut

            else {printf("FOLD \n"); return FOLD;} //Soit il se couche
        }

        //Au moment du FLOP
        case 3 :
        {
            if (argentJoueur <= montant) //Si il n'est pas riche par rapport à ce qui se joue
            {
                if (getCarteRang(*getMainCarteIemeCarte(mainJoueur,0)) == getCarteRang(*getMainCarteIemeCarte(mainJoueur,1))) //Il tente quand même l'aventure en cas de paire à la donne ...
                {
                    if(differenceMiseMontant >= argentJoueur) // ... selon si il a assez d'argent pour suivre ...
                    {
                        return ALL_IN; // ... il fait tapis
                    }
                    else
                    {
                        if(differenceMiseMontant <= argentJoueur)
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
        }

        //Au moment du TURN
        case 4 :
        {
            if (argentJoueur <= montant) //Si il n'est pas riche par rapport à ce qui se joue
            {
                if (getCarteRang(*getMainCarteIemeCarte(mainJoueur,0)) == getCarteRang(*getMainCarteIemeCarte(mainJoueur,1))) //Il tente quand même l'aventure en cas de paire à la donne ...
                {
                    if(differenceMiseMontant >= argentJoueur) // ... selon si il a assez d'argent pour suivre ...
                    {
                        return ALL_IN; // ... il fait tapis
                    }
                    else
                    {
                        if(differenceMiseMontant <= argentJoueur)
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
        }

        //Au moment du RIVER
        case 5 :
        {
            if (argentJoueur <= montant) //Si il n'est pas riche par rapport à ce qui se joue
            {
                if (getCarteRang(*getMainCarteIemeCarte(mainJoueur,0)) == getCarteRang(*getMainCarteIemeCarte(mainJoueur,1))) //Il tente quand même l'aventure en cas de paire à la donne ...
                {
                    if(differenceMiseMontant >= argentJoueur) // ... selon si il a assez d'argent pour suivre ...
                    {
                        return ALL_IN; // ... il fait tapis
                    }
                    else
                    {
                        if(differenceMiseMontant <= argentJoueur)
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
        }

        //Si y'a un probleme l'IA se couche
        default :

            return FOLD;
    }
    //Fin du switch
}
