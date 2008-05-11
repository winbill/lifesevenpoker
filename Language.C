#include <iostream>
#include <cstdio>
#include <stdlib.h>

using namespace std;

char** creeTableauLanguage(char* fichier)
{
    FILE * f;
    //f=fopen ("menuFrancais.txt" , "r");
    f=fopen (fichier , "r");
    char c[50];
    int i=0;
    char**tab=(char**)malloc(50*sizeof(char*));
    while (fgets(c, 50, f) != NULL);
    {
        tab[i]=c;
        //printf("%s",tab[i]);
        i++;
    }

    return tab;
}
void detruitTableauLanguage(char** tab)
{
    free(tab);
}
