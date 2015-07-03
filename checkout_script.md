# Introduction #

Petit script pour les feignants.

_Note : ne fonctionne qu'une fois la copie de travail initialisée localement, c'est à dire lorsque le svn checkout a été réalisée au moins une fois._


---


# Détails #

Ouvrez votre terminal habituel.
Placez vous dans le dossier dans lequel vous effectuez votre checkout habituellement, c'est à dire le dossier parent de lifesevenpoker sur votre machine.

Créez un fichier checkout.sh et éditez le avec gedit ou scite par exemple:
```
gedit checkout.sh
```

Et ajoutez y le code suivant:

```
#Script de checkout et lancement de codeblocks.
#Par Benjamin.

svn checkout https://lifesevenpoker.googlecode.com/svn/trunk/ lifesevenpoker --username xxxxx

codeblocks lifesevenpoker/LifeSevenPoker.cbp &
```

Les xxxxx représentent le nom d'utilisateur que vous utilisez pour vous connecter à la base de code google.

Sauvegardez les modifications et fermez l'editeur de texte.

Puis dans le terminal faites:
```
chmod u+x checkout.sh
```

Ceci devrait normalement ajouter le droit d'execution sinon vous ne pourriez pas lancer ce script.

Ensuite dans votre terminal, lancez le script avec la commande suivante:
```
./checkout.sh
```

Les opérations se lancent automatiquement et vous pouvez vous mettre au travail ;)

Bon courrage.