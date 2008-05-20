#include "Langage.h"
#include <iostream>
#include <cstdio>
#include <stdlib.h>

using namespace std;

int main()
{
    char c[50][50];

    afficherMenu(c,ecrireDansTableau(c,"menuFrancais.txt"));
    //ecrireDansTableau(c,"menuAnglais.txt");
    //  afficherMenu(c);
    return 0;
}
