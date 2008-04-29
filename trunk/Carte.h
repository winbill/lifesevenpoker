
/**
	@brief Fichier H pour les cartes.

	Gere les donnees de type Carte.

	@author Benjamin, Olivier
	@file Carte.h
	@version 1.3
	@date 2008/04/19
*/

#ifndef _Carte_H
#define _Carte_H

/**	@brief Structure representant une carte du jeu.
	@param Le champ couleur prend ses valeurs dans l'intervalle ]0,4] et represente la couleur de la carte.
	@param Le champ rang prend ses valeurs dans l'intervalle [2,14] et represente le rang de la carte, c'est a dire sa valeur.
*/
struct Carte
{
	int couleur;
	int rang;
	char nomFichier[15];
};

/**	@brief Procedure initialisant une nouvelle carte.
	@param [in,out] Carte Une carte.
	@warning Deux valeurs par defaut existent: Init_Rang et Init_Couleur. Elles sont considerees commes des 0.
*/
void initialisationCarte(Carte & c);

/**	@brief Fonction recuperant le rang d'une carte.
	@param [in] Carte Une Carte.
	@return Renvoie la valeur du rang de la carte.
	@note Accesseur.
*/
int getCarteRang(const Carte & c);

/**	@brief Fonction recuperant la couleur d'une carte.
	@param [in] Carte Une Carte.
	@return Renvoie la valeur de la couleur de la carte.
	@note Accesseur.
*/
int getCarteCouleur(const Carte & c);

/**	@brief Procedure modifiant les valeurs d'une carte.
	@param [in,out] Carte Une carte.
	@param [in] Couleur Une couleur.
	@param [in] Rang Un rang.
	@return Modifie les champs de la variable de type Carte avec les autres parametres donnes.
	@note Mutateur
*/
void setCarte(Carte & c,const int & couleur,const int & rang);

/**	@brief Fonction comparant deux carte par rapport a leur valeur.
	@param [in,out] Carte Une carte.
	@param [in,out] Carte Une autre carte.
	@return Renvoie differentes valeurs numeriques selon le resultat de la comparaison :
			->	1 si la deuxieme carte est plus forte que la premiere
			->	0 si les deux cartes sont de meme force
			->	-1 si la premiere carte est plus forte que la deuxieme
*/
int compareCarte(const Carte & c1, const Carte & c2);

/** @brief procedure qui renvoit dans un tableau le nom de l'image associe a la carte
    @param [in] c Carte
    @param [out] sortieNomFichier : chemin de l'image
*/
void getCarteNomFichier(const Carte & c, char* sortieNomFichier);


#endif

