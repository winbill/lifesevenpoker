#include <iostream>
#include <cstdio>
#include <stdlib.h>

using namespace std;

int main()
{
    FILE * f;
    //f=fopen ("menuFrancais.txt" , "r");
    f=fopen ("menuAnglais.txt" , "r");
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
    return 0;
}
