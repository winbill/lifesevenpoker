#include <iostream>
#include <cstdio>
#include <stdlib.h>



/**
	@brief Fichier C pour gerer les langages
	@author  James Tristan
	@file Langage.C
	@version 1.1
	@date 2008/05/26
 */


int ecrireDansTableau(char menu[50][50],const char nomFichier[50])
{
    FILE * f;
    f=fopen (nomFichier , "r");
    char c[50];
    int i=0;
    char**tab=(char**)malloc(50*sizeof(char*));
    while (fgets(c,49, f) != NULL)
    {
        strcpy(menu[i],c);
        i++;
    }
    free(tab);
    return 1;
}


void afficherMenu(const char c[50][50],int a)
{
    int i;
    for(i=0;i<a;i++)
    {
        printf("%s",c[i]);
    }
}
