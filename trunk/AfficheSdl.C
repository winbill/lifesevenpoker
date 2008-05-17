#include "AfficheSdl.h"





bool initSDL(SDL_Surface* & screen, const int & screen_width, const int & screen_height, const int & screen_bpp, const char* caption)
{
    //Initialisation de tous les sous-systèmes de SDL
    if ( SDL_Init( SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER ) == -1 )
    {
        printf("Impossible d\'initialiser les sous-systèmes de SDL.\n");
        return -1;
    }

    //Mise en place de l'écran
    screen = SDL_SetVideoMode( screen_width, screen_height, screen_bpp, SDL_HWSURFACE|SDL_RESIZABLE|SDL_DOUBLEBUF );

    //S'il y a une erreur dans la mise en place de l'écran
    if ( screen == NULL )
    {
        printf("Echec de la mise en place de l\'ecran.\n");
        return -1;
    }

    //Initialisation de SDL_TTF
    if ( TTF_Init() == -1 )
    {
        printf("Echec de l\'initialisation de SDL_ttf");
        return -1;
    }

    //Mise en place de la barre de titre de la fenetre principale (caption)
    SDL_WM_SetCaption( caption , NULL );

    //Si tout s'est bien passé
    return 0;
}

SDL_Surface *load_image( const char* filename )
{
    //Surface tampon qui nous servira pour charger l'image
    SDL_Surface* loadedImage = NULL;

    //L'image optimisée qu'on va utiliser
    SDL_Surface* optimizedImage = NULL;

    //Chargement de l'image
    if ((loadedImage = IMG_Load(filename)) == 0)
    {
        printf("Impossible de charger l\'image.\n");
    }

    //Si le chargement se passe bien
    if ( loadedImage != NULL )
    {
        //Création de l'image optimisée
        if ((optimizedImage = SDL_DisplayFormatAlpha( loadedImage )) == 0)
        {
            printf("Impossible d'optimiser l\'image.\n");
        }

        //Libération de l'ancienne image
        SDL_FreeSurface( loadedImage );
    }

    //On retourne l'image optimisée
    return optimizedImage;
}




void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination )
{
    SDL_Rect offset;

    offset.x = x;
    offset.y = y;

    //On blitte la surface
    SDL_BlitSurface( source, NULL, destination, &offset );
    //SDL_UpdateRect(destination,0,0,0,0);
}


void affichageOmbreCarte(SDL_Surface* affichage,int x,int y,double zoom)
{
    SDL_Surface* carte;
    carte=load_image("cards/black.png");

    SDL_Surface* surfaceZoom = rotozoomSurface(carte, 0, zoom, 1);
    SDL_FreeSurface(carte);

    apply_surface(x,y,surfaceZoom,affichage);
    SDL_FreeSurface(surfaceZoom);


}
void AffAfficheCarte(SDL_Surface* affichage, Carte* c, int x, int y, double zoom)
{
    AffAfficheCarte(affichage,c, x, y, zoom,false);
}


void AffAfficheCarte(SDL_Surface* affichage, Carte* c, int x, int y, double zoom,bool evidence)
{
    SDL_Surface* carte;
    if (!evidence)
    {
        if (c== NULL)
            carte=load_image("img/doscarte.jpg");
        else
            carte=load_image(c->nomFichier);
    }
    else
    {
        carte=load_image("img/white.png");
    }

    SDL_Surface* surfaceZoom = rotozoomSurface(carte, 0, zoom, 1);
    SDL_FreeSurface(carte);
    apply_surface(x,y,surfaceZoom,affichage);
    SDL_FreeSurface(surfaceZoom);





}




void AffAfficheTexte(SDL_Surface* destination,const char* message,int x,int y,int r,int g,int b,int style,int size)
{


    //La surface où on va coller le message
    SDL_Surface* texte;
    //Le Font qu'on va utiliser
    TTF_Font *font;

    //La couleur du Font
    SDL_Color textColor = { r, g, b,0};

    //Ouverture du Font
    font = TTF_OpenFont( "./fonts/Qlassik_TB.otf", size );
    TTF_SetFontStyle(font,style);


    //S'il y a une erreur dans le chargement du Font
    if ( font == NULL )
    {
        printf("Erreur de chargement de la font\n");
    }

    //Mise en place du texte sur la surface message
    texte = TTF_RenderText_Blended(font,message,textColor);

    //S'il y a une erreur dans la mise en place du texte
    if ( texte == NULL )
    {
        printf("Erreur de chargement du message\n");
    }

    //Application de la surface du message
    apply_surface(x,y,texte,destination);

    TTF_CloseFont(font);
    SDL_FreeSurface(texte);

}

void AffAfficheTexte(SDL_Surface* destination,const char* message,int x,int y,int r,int g,int b)
{
    AffAfficheTexte(destination,message,x,y,r,g,b,TTF_STYLE_NORMAL,28);
}

void AffActualiser(SDL_Surface* affichage)
{
    SDL_Flip(affichage);
    //SDL_UpdateRect(affichage, 0, 0, 0, 0);
}



void AffAfficheTapis(SDL_Surface* aff,SDL_Surface* tapis)
{
    apply_surface(0,0,tapis,aff);

}













