# Introduction #
Quelques commandes en vrac svn


## Details ##

  * `svn update` : met à jours les fichiers locaux

  * `svn status` : regarde si les fichiers sont sur le serveur

  * `svn rm --force LIF7` : supprime le répertoire LIF7

  * `svn commit -m "commentaire"` : met à jour le serveur

  * ` svn ls .@36 ` : affiche les fichiers de la version 36

  * `svn update` : met à jours les fichiers locaux

  * `svn add Table.h` : ajoute Table.h sur le net

  * `bg` : si on a oublié de mettre & (par ex 'scite Table.h' ctrl-Z puis bg)

  * `history`


## Ajout fichier ##

tous ce qui est en _italique_ est a remplacer

### pour se connecter ###

---


  * `svn checkout https://lifesevenpoker.googlecode.com/svn/trunk/ lifesevenpoker --username `_tonidgoogle_

  * tu tape ton mot de passe (si demandé)

  * `cd lifesevenpoker`

### envoyer fichiers ###

---


  * `svn add `_fichier_  : uniquement les fichiers locaux sont modifiés

  * `svn commit -m `"_commentaires_"   : tous les changements locaux sont envoyés

### récupèrez fichiers ###

---


  * `svn update `  : récupère les fichiers qui sont sur le serveur (ca met dans ~/lifesevenpoker/ )


---
