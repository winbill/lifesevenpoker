#Script de checkout du server googlecode et lancement de l'appli codeblocks.
#Penser à modifier son login.
#Ecrit par Benjamin.

svn checkout https://lifesevenpoker.googlecode.com/svn/trunk/ lifesevenpoker --username bengrunt

codeblocks LifeSevenPoker.cbp &
