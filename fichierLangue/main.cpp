#include "Langage.h"
#include <iostream>
#include <cstdio>
#include <stdlib.h>

using namespace std;

int main()
{
    char c[50][50];
    ecrireDansTableau(c,"menuFrancais.txt");
  //  afficherMenu(c);
    ecrireDansTableau(c,"menuAnglais.txt");
  //  afficherMenu(c);
    return 0;
}
