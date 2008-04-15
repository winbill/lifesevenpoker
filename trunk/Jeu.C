/**
	@brief Fichier C qui gere le jeu
	
	
	fichier principal qui sert a initialiser une partie et la terminer
     
	@author James
	@file Jeu.C
	@version 1.1
	@date 2008/04/16
 */
 



/**	@brief initialise le jeu
	@note donne 1000c a chacun des joueurs, affecte les IA, les places, le dealer....
	@param [in, out] table une table
*/
void initialiseJeu(Table & table)
{
	int i;
	for(i=0;i<getNJoueurTable(table);i++);
	{
		setArgentJoueur(*getIemeJoueur(table,i),1000);
	}
	
//etc... atand IArtificielle.h	
	
}


void distribuer2CartesJoueursJeu(Table & table)
{	
	int i;
	for(i=0;i<getNJoueurTable(table);i++);
	{
		ajouteCarte(*getMainJoueur(*getIemeJoueur(table,i)),*tirerCarte(*getTablePileCarteTable(table)));
		ajouteCarte(*getMainJoueur(*getIemeJoueur(table,i)),*tirerCarte(*getTablePileCarteTable(table)));	
	}
	
}


void distribuer1CarteDecouverteJeu(Table & table,int n)
{
	ajouteCarte(*getMainCarteTable(table),*tirerCarte(*getTablePileCarteTable(table)));
}

/**	@brief relance une nouvelle partie
	@param [in, out] table une table
	@note remet la main de tous à zero et re remplit pileCarte (en changeant la taille)
	@note change la position du dealer
	@note mise de la petite et grosse blind
*/
void lanceJeu(Table & table)
{
	int i;
	//nouvelle pile de carte pleine
	nouvellePileCarte(table);
	//remise a zero des mains des autres joueurs
	for(i=0;i<getNJoueurTable(table);i++);
	{
		initialisationMain(*getMainJoueur(*getIemeJoueur(table,i)))
	}
	//remise des cartes decouvertes a 0
	initialisationMain(*getMainCarteTable(table));
	
}

/**	@brief donne la victoire a un (ou plus) joueur(s)
	@param [in, out] table une table
	@note analyse la (ou les) main(s) gagnante et répartie le pot en fonction
*/
void donneVictoireJeu(Table & table);

/**	@brief fonction utilise lorsque le joueur change de status
	@param [in, out] table une table
	@param [in, out] joueur sujet de l'action
	@param [in] statut son nouveau statut
	@param [in] n s'il relance on met le montant dedans
*/
void actionJoueurJeu(Table & table,Joueur & joueur,Statut statut,int n);

/**	@brief interroge les joueurs tours à tours
	@param [in, out] table une table

	s'arrete lorsque les mises sont egales
*/
void lanceTourJeu(Table & table);