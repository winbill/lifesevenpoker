/**
	@brief Fichier C pour l'affichage dynamique


	gere l'affichage dynamique en utilisant l'affichage de "bas niveau"

	@author  James
	@file AfficheDynamique.C
	@version 1.0
	@date 2008/04/17
 */
#include "AfficheSdl.h"



void initialiseSdl()
{
    //dans notre programme on gere la video le son et le temps
    assert(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER)==0);
}


void fermeSdl()
{
      SDL_Quit();
}

void ouvreFenetreSdl()
{
    //nouvelle fenetre
    SDL_SetVideoMode(1024  , 768, 32, SDL_HWSURFACE | SDL_DOUBLEBUF );
    //titre de la fenetre
    SDL_WM_SetCaption("Life'Seven Poker", NULL);

}
