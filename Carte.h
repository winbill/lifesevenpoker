#ifndef _Carte
#define _Carte

/**	@brief Enumération représentant les couleurs des cartes du jeu de poker.
	@note Les couleurs sont Trèfle, Carreau, Coeur et Pique.
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

/**	@brief Enumération représentant les 13 cartes de chaque couleur du jeu de poker.
	@note Les différentes cartes sont les chiffres de 2 à 10, le Valet, la Dame, le Roi et l'As.
	@warning Le Joker n'est pas représenté car cette carte n'est pas utilisée dans ce jeu.
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
	
/**	@brief Structure réprésentant une carte du jeu.
	@param Le champ couleur prend ses valeurs dans l'énumération Couleur et représente la couleur de la carte.
	@param Le champ rang prend ses valeurs dans l'énumération Rang et représente le rang de la carte, c'est à dire sa valeur.
*/
struct Carte
{
	Couleur couleur;
	Rang rang;
};

/**	@brief Procédure initialisant une nouvelle carte.
	@param Prend en entrée une variable de type Carte.
	@return Initialise la variable de type Carte avec des valeurs par défaut : rang = INIT_RANG et couleur = INIT_COULEUR.
	@warning Ces deux valeurs par défaut sont considérées commes des 0.
*/
void initialisationCarte(Carte & c);

/**	@brief Fonction récupérant le rang d'une carte.
	@param Prend en entrée une variable de type Carte.
	@return Renvoie la valeur du rang de la variable de type Carte.
	@note Accesseur.
*/
Rang getCarteRang(const Carte & c);

/**	@brief Fonction récupérant la couleur d'une carte.
	@param Prend en entrée une variable de type Carte.
	@return Renvoie la valeur de la couleur de la variable de type Carte.
	@note Accesseur.
*/
Couleur getCarteCouleur(const Carte & c);

/**	@brief Procédure modifiant les valeurs d'une carte.
	@param Prend en entrée une variable de type Carte, une variable de type Couleur et une variable de type Rang.
	@return Modifie les champs de la variable de type Carte avec les autres paramètres donnés.
	@note Mutateur
*/
void setCarte(Carte & c,const Couleur & couleur,const Rang & rang);

/**	@brief Fonction comparant deux carte par rapport à leur valeur.
	@param Prend en entrées deux variables de type Carte.
	@return Renvoie différentes valeurs numériques selon le résultat de la comparaison :
			->	1 si la deuxième carte est plus forte que la première
			->	0 si les deux cartes sont de même force
			->	-1 si la première carte est plus forte que la deuxième
*/
int compareCarte(const Carte & c1, const Carte & c2);

#endif

