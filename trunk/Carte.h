#ifndef _Carte
#define _Carte

enum Couleur
{
	INIT_COULEUR = 0,
	TREFLE,
	CARREAU,
	COEUR,
	PIQUE,
	FIN_COULEUR
};

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
	

struct Carte
{
	Couleur couleur;
	Rang rang;
	//adresse image
};

void initialisationCarte(Carte & c);
//pré: aucune
//post: c est initialisée

Rang getCarteRang(const Carte & c);
Couleur getCarteCouleur(const Carte & c);
//Carte getCarte(const Carte & c);
//pré: c est initialisée
//post: renvoie certaines valeurs de la structure c

void setCarte(Carte & c,const Couleur & couleur,const Rang & rang);
//pré: c est initialisée
//post: modifie certaines valeurs de la structure c

int compareCarte(const Carte & c1, const Carte & c2);
//pré: c1 et c2 sont initialisées
/*post: renvoie 
				1 si c2 plus forte que c1
				0 si c1 et c2 sont de même force
				-1 si c1 plus forte que c2                     */

//void testamentCarte(Carte & c);
//pré: c est initialisée
//post: c est supprimée

#endif

