#Script de checkout du server googlecode et lancement de l'appli codeblocks.
#Penser à modifier son login.
#Ecrit par Benjamin.


#A utiliser dans la directorie ou est fait le checkout habituellement.
#Par exemple si vous travaillez dans /hone/xxx/lifesevenpoker/ il faut executer ce script dans /home/xxx/   c'est à dire dans votre répertoire de #connection.

svn checkout https://lifesevenpoker.googlecode.com/svn/trunk/ lifesevenpoker --username bengrunt

codeblocks LifeSevenPoker.cbp &
