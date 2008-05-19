
#include <iostream>
#include <cstdio>
#include <stdlib.h>


/**
	@brief Fichier C qui gere le langage
	@author Tristan
	@file Langage.C
	@version 1.0
	@date 2008/05/19
 */

using namespace std;

void ecrireDansTableau(char menu[50][50],const char nomFichier[50])
{
    FILE * f;
    f=fopen (nomFichier , "r");
    char c[50];
    int i=0;
    char**tab=(char**)malloc(50*sizeof(char*));
    while (fgets(c, 50, f) != NULL)
    {
        tab[i]=c;
        printf("%s",tab[i]);
        i++;
    }
    free(tab);
}


void afficherMenu(const char c[50][50])
{
    int i;
    for(i=0;i<50;i++)
    {
        printf("%s",c[i]);
    }
}

