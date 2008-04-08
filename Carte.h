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
};

/**	@brief Procedure creant une carte.
	@param Prend en entree une variable de type Carte.
	@return Alloue un espace memoire sur le tas pour la variable de type Carte en la creant.
*/
void creerCarte(Carte & c);

/**	@brief Procedure initialisant une nouvelle carte.
	@param Prend en entree une variable de type Carte.
	@return Initialise la variable de type Carte avec des valeurs par defaut : rang = INIT_RANG et couleur = INIT_COULEUR.
	@warning Ces deux valeurs par defaut sont considerees commes des 0.
*/
void initialisationCarte(Carte & c);

/**	@brief Fonction recuperant le rang d'une carte.
	@param Prend en entree une variable de type Carte.
	@return Renvoie la valeur du rang de la variable de type Carte.
	@note Accesseur.
*/
Rang getCarteRang(const Carte & c);

/**	@brief Fonction recuperant la couleur d'une carte.
	@param Prend en entree une variable de type Carte.
	@return Renvoie la valeur de la couleur de la variable de type Carte.
	@note Accesseur.
*/
Couleur getCarteCouleur(const Carte & c);

/**	@brief Procedure modifiant les valeurs d'une carte.
	@param Prend en entree une variable de type Carte, une variable de type Couleur et une variable de type Rang.
	@return Modifie les champs de la variable de type Carte avec les autres parametres donnes.
	@note Mutateur
*/
void setCarte(Carte & c,const Couleur & couleur,const Rang & rang);

/**	@brief Fonction comparant deux carte par rapport a leur valeur.
	@param Prend en entrees deux variables de type Carte.
	@return Renvoie differentes valeurs numeriques selon le resultat de la comparaison :
			->	1 si la deuxieme carte est plus forte que la premiere
			->	0 si les deux cartes sont de meme force
			->	-1 si la premiere carte est plus forte que la deuxieme
*/
int compareCarte(const Carte & c1, const Carte & c2);

/**	@brief Procedure qui detruit une carte et desalloue son espace memoire.
	@param Prend en entree une variable de type pointeur sur Carte.
	@return Desalloue la zone memoire pointeée par le pointeur sur Carte et detruit ce pointeur.
*/
void testamentCarte(Carte* &c);

#endif

