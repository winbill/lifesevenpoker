/**
	@brief Fichier H pour les cartes.

	Gere les donnees de type Carte.

	@author Benjamin, Olivier
	@file Carte.h
	@version 1.3
	@date 2008/04/19
*/

#ifndef _Carte
#define _Carte

/**	@brief Enumeration representant les couleurs des cartes du jeu de poker.
	@note Les couleurs sont Trefle, Carreau, Coeur et Pique.
*/
enum Couleur
{
	INIT_COULEUR = 0,
	TREFLE,
	CARREAU,
	COEUR,
	PIQUE,
	FIN_COULEUR
};

/**	@brief Enumeration representant les 13 cartes de chaque couleur du jeu de poker.
	@note Les differentes cartes sont les chiffres de 2 a 10, le Valet, la Dame, le Roi et l'As.
	@warning Le Joker n'est pas represente car cette carte n'est pas utilisee dans ce jeu.
*/
enum Rang
{
	INIT_RANG = 0,
	DEUX = 2,
	TROIS = 3,
	QUATRE = 4,
	CINQ = 5,
	SIX = 6,
	SEPT = 7,
	HUIT = 8,
	NEUF = 9,
	DIX = 10,
	VALET = 11,
	DAME = 12,
	ROI = 13,
	AS = 14,
	FIN_RANG
};

/**	@brief Structure representant une carte du jeu.
	@param Le champ couleur prend ses valeurs dans l'enumeration Couleur et represente la couleur de la carte.
	@param Le champ rang prend ses valeurs dans l'enumeration Rang et represente le rang de la carte, c'est a dire sa valeur.
*/
struct Carte
{
	Couleur couleur;
	Rang rang;
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
Rang getCarteRang(const Carte & c);

/**	@brief Fonction recuperant la couleur d'une carte.
	@param [in] Carte Une Carte.
	@return Renvoie la valeur de la couleur de la carte.
	@note Accesseur.
*/
Couleur getCarteCouleur(const Carte & c);

/**	@brief Procedure modifiant les valeurs d'une carte.
	@param [in,out] Carte Une carte.
	@param [in] Couleur Une couleur.
	@param [in] Rang Un rang.
	@return Modifie les champs de la variable de type Carte avec les autres parametres donnes.
	@note Mutateur
*/
void setCarte(Carte & c,const Couleur & couleur,const Rang & rang);

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
void getCarteNomFichier(const Carte & c,char[] sortieNomFichier);


#endif

