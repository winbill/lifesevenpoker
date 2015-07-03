## Introduction ##
Doxygen sert a créer des doc à partir de code source


---


## Details ##

  * Installer Doxygen (`sudo apt-get...`)
  * taper `Doxygen Doxyfile` Doxyfile etant le fichier de configuration (langues, titre du projet...) qui est sur le serveur svn, cela va vous crer un repertoire html, allez dedans et double cliquez sur index.html


---


## mettre en forme les commentaires ##

  * `/** commentaire doxygen */`
  * `@brief` balise de description rapide
  * il existe aussi `@param @note @warning @return`


---


## petit exemple ##

```
/**	@brief renvoi le rang dans le tableau du Joueur
	@param _joueur_ pointeur vers joueur
	@note appel la fonction joueurTrouver
	@warning affiche un message derreur sur la sortie standart si aucun joueur correspondant n'a ete trouve
        @return renvoi l entier correspondant
*/
int fonctionTruc(Joueur* joueur);
```