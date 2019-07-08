Projet JAVA fait en une semaine.
C'est un jeu de solitaire

Nécésite Maven
Compilation par makefile:

$> make

Lancer le programme:

$> make run

Nettoyage du dossier:

$> make [clean/fclean]


Jamais vu ou réussi auparavant:
- Utilisation de maven pour compilation
- Utilisation de la librairie swing
- Programation évenementielle

Bug connu:
Parfois quand une carte se fait révéllé dans une colonne, le haut de la carte n'est pas rafraichie.

Comment jouer:
cliquer sur un élément, celui ci va faire certaines actions:
- cliquer sur le packet de cartes va révéler la carte suivente
- cliquer sur une carte va la sélectionner avec toutes les autres cartes en dessous de cette colonne (si ça en est une), puis cliquer sur l'endroi ou vous voulez la déplacer, si le déplacement est possible celui-ci va être effectué
- Si un déplacement est possible mais que rien ne se passe c'est qu'il n'a pas de sélection. Je conseille donc de double cliquer sur la/les cartes à déplacer pour bien les sélectioner.

Projet testé et réalisé sur ubuntu 18.04.2
