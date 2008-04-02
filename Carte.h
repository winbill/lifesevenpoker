#ifndef _Carte
#define _Carte

/**	@brief Enum�ration repr�sentant les couleurs des cartes du jeu de poker.
	@note Les couleurs sont Tr�fle, Carreau, Coeur et Pique.
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

/**	@brief Enum�ration repr�sentant les 13 cartes de chaque couleur du jeu de poker.
	@note Les diff�rentes cartes sont les chiffres de 2 � 10, le Valet, la Dame, le Roi et l'As.
	@warning Le Joker n'est pas repr�sent� car cette carte n'est pas utilis�e dans ce jeu.
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
	
/**	@brief Structure r�pr�sentant une carte du jeu.
	@param Le champ couleur prend ses valeurs dans l'�num�ration Couleur et repr�sente la couleur de la carte.
	@param Le champ rang prend ses valeurs dans l'�num�ration Rang et repr�sente le rang de la carte, c'est � dire sa valeur.
*/
struct Carte
{
	Couleur couleur;
	Rang rang;
};

/**	@brief Proc�dure initialisant une nouvelle carte.
	@param Prend en entr�e une variable de type Carte.
	@return Initialise la variable de type Carte avec des valeurs par d�faut : rang = INIT_RANG et couleur = INIT_COULEUR.
	@warning Ces deux valeurs par d�faut sont consid�r�es commes des 0.
*/
void initialisationCarte(Carte & c);

/**	@brief Fonction r�cup�rant le rang d'une carte.
	@param Prend en entr�e une variable de type Carte.
	@return Renvoie la valeur du rang de la variable de type Carte.
	@note Accesseur.
*/
Rang getCarteRang(const Carte & c);

/**	@brief Fonction r�cup�rant la couleur d'une carte.
	@param Prend en entr�e une variable de type Carte.
	@return Renvoie la valeur de la couleur de la variable de type Carte.
	@note Accesseur.
*/
Couleur getCarteCouleur(const Carte & c);

/**	@brief Proc�dure modifiant les valeurs d'une carte.
	@param Prend en entr�e une variable de type Carte, une variable de type Couleur et une variable de type Rang.
	@return Modifie les champs de la variable de type Carte avec les autres param�tres donn�s.
	@note Mutateur
*/
void setCarte(Carte & c,const Couleur & couleur,const Rang & rang);

/**	@brief Fonction comparant deux carte par rapport � leur valeur.
	@param Prend en entr�es deux variables de type Carte.
	@return Renvoie diff�rentes valeurs num�riques selon le r�sultat de la comparaison :
			->	1 si la deuxi�me carte est plus forte que la premi�re
			->	0 si les deux cartes sont de m�me force
			->	-1 si la premi�re carte est plus forte que la deuxi�me
*/
int compareCarte(const Carte & c1, const Carte & c2);

#endif

