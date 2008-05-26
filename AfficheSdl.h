/**
    @brief Fichier H pour l'affichage en SDL


    Gere les fonctions d'affichage de base avec SDL.

    @author James Benjamin
    @file AfficheSDL.C
    @version 1.4
    @date 2008/05/26
*/

#ifndef AfficheSdl_H
#define AfficheSdl_H


#include "AfficheDynamique.h"


/** @brief Procedure qui met en pause le deroulement du programme en attendant une reaction du joueur (un clic souris)
*/
void pause();


/** @brief Fonction qui initialise SDL et ses sous-systemes.
	@param [in,out] screen La surface principale de SDL.
	@param [in] screen_width La largeur de la surface principale.
	@param [in] screen_height La hauteur de la surface principale.
	@param [in] screen_bpp Le nombre de bits par pixels de la surface principale.
	@param [in] caption Une chaine de caracteres representant le nom de la fenetre du programme.
	@return Renvoie un booleen
*/
bool initSDL(SDL_Surface* & screen, const int & screen_width, const int & screen_height, const int & screen_bpp, const char* caption);


/** @brief Fonction permettant le chargement d'une image dans certains formats.
    @param [in] filename Une chaine de caracteres representant le nom de fichier.
    @return Renvoie un pointeur sur l'image chargée en mémoire.
    @note Formats supportés : BMP, GIF, JPEG, LBM, PCX, PNM, TGA, TIFF, XCF, XPM, XV et PNG.
*/
SDL_Surface *load_image( const char* filename );


/** @brief Procedure qui applique une surface SDL sur une autre selon la méthode du "blitting", qui est en quelque sort un collage simple.
    @param [in] x Coordonnee en x pour le blitting de l'image.
    @param [in] y Coordonnee en y pour le blitting de l'image.
    @param [in] source Le pointeur sur image de ce qu'on veut blitter.
    @param [in] destination Le pointeur sur image de sur quoi on veut blitter.
    @note Attention : le système de coordonnees utilise ici est un systeme X,Y dont l'origine est le coin superieur gauche de l'image et dont l'axe Y est inverse et pointe vers le bas.
*/
void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination );


/** @brief Procedure qui rajoute un effet d'ombre a l'affichage d'une carte.
	@param [in,out] affichage Un pointeur sur la surface SDL representant l'ensemble de l'affichage graphique.
	@param [in] x La coordonnee en x de la position de l'effet d'ombre.
	@param [in] y La coordonned en y de la position de l'effet d'ombre.
	@param [in] zoom La valeur de zoom de l'image.
*/
void affichageOmbreCarte(SDL_Surface* affichage,int x,int y,double zoom);


/** @brief Procedure qui affiche une carte.
	@param [in,out] affichage Un pointeur sur la surface SDL representant l'ensemble de l'affichage graphique.
	@param [in] c Un pointeur sur la carte que l'on veut afficher.
	@param [in] x La coordonnee en x de la position ou l'on veut afficher la carte.
	@param [in] y La coordonnee en y de la position ou l'on veut afficher la carte.
	@param [in] zoom La valeur de zoom de l'image.
*/
void AffAfficheCarte(SDL_Surface* affichage, Carte* c, int x, int y, double zoom);


/** @brief Procedure qui affiche une carte.
	@param [in,out] affichage Un pointeur sur la surface SDL representant l'ensemble de l'affichage graphique.
	@param [in] c Un pointeur sur la carte que l'on veut afficher.
	@param [in] x La coordonnee en x de la position ou l'on veut afficher la carte.
	@param [in] y La coordonnee en y de la position ou l'on veut afficher la carte.
	@param [in] zoom La valeur de zoom de l'image.
	@param [in] evidence Un booleen qui determine si on affiche la carte face cachee ou face decouverte.
*/
void AffAfficheCarte(SDL_Surface* affichage, Carte* c, int x, int y, double zoom,bool evidence);


/** @brief Procedure qui affiche un texte sur une surface SDL.
	@param [in,out] destination Le pointeur sur la surface SDL sur laquelle on veut afficher le message.
	@param [in] message Le tableau de caracteres contenant le message a afficher.
	@param [in] x La coordonnee en x de la position du message.
	@param [in] y La coordonnee en y de la position du message.
	@param [in] r La valeur en rouge de la couleur du message.
	@param [in] g La valeur en vert de la couleur du message.
    @param [in] b La valeur en bleu de la couleur du message.
	@param [in] style Le style utilise pour ecrire le message.
	@param [in] size La taille de police utilisee pour ecrire le message.
*/
void AffAfficheTexte(SDL_Surface* destination,const char* message,int x,int y,int r,int g,int b,int style,int size);


/** @brief Procedure qui affiche un texte sur une surface SDL.
	@param [in,out] destination Le pointeur sur la surface SDL sur laquelle on veut afficher le message.
	@param [in] message Le tableau de caracteres contenant le message a afficher.
	@param [in] x La coordonnee en x de la position du message.
	@param [in] y La coordonnee en y de la position du message.
	@param [in] r La valeur en rouge de la couleur du message.
	@param [in] g La valeur en vert de la couleur du message.
    @param [in] b La valeur en bleu de la couleur du message.
	@note fait appel a AffAfficheTexte(destination,message,x,y,r,g,b,TTF_STYLE_NORMAL,28)
*/
void AffAfficheTexte(SDL_Surface* destination,const char* message,int x,int y,int r,int g,int b);


/** @brief Procedure qui actualise l'affichage graphique.
	@param [in,out] affichage Un pointeur sur la surface SDL representant l'ensemble de l'affichage graphique.
*/
void AffActualiser(SDL_Surface* affichage);


/** @brief Procedure de base qui affiche la surface SDL de base représentant le tapis (image de fond)
	@param [in,out] affichage Un pointeur sur la surface SDL representant l'ensemble de l'affichage graphique.
	@param [in] tapis Un pointeur sur la surface SDL representant le tapis.
	@note
*/
void AffAfficheTapis(SDL_Surface* aff,SDL_Surface* tapis);


#endif

