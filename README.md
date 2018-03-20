# Rapport de Projet

(19/03/2018)
## Travail effectué
Nous avons commencé l'implémentation de l'automate cellule, pour ce faire nous avons choisie le langage C++,
non seulement pour sa partie Objet mais aussi pour acquérir de nouvelle compétence dans ce langage qui est
très utilisé.

### Choix des structures
Les cellules et les Planche (le tableau contenant les cellules ) sont représenté par des cellules afin de les
manipuler plus facilement.

La classe Cellule contient pour ce début l'état de la cellule, une valeur booléenne soit 1 ou O,
nous comptons améliorer cette classe afin de stocker sont état à l'instant `t` et prévoir par rapport
à la disposition de ses voisins son état à l'instant `t+1` et de pouvoir afficher les états des cellules
avec une couleur.

La classe Planche contient quand à elle une grille de `vector` de cellules, permettant de manipuler les cellules
et de passer d'un instant `t` à un instant `t+1` en utilisant les règles des automates cellulaires.

### Choix de l'implémentation

Pour un début la Planche est généré aléatoirement au moment de sa construction, par la suite nous allons parser un fichier
text et récupérer l'état initial et stocker les différente phase de l'évolution de l'automate. avec l’intelligence artificielle
nous pourrons par la suite revenir aux états précédents, en manipulant le fichier.

Par la suite nous pourrons utiliser ce fichier comme parseur pour un rendu graphique de l'exécution de l'automate cellulaire

### Limite
pour ce premier travail nous nous somme limité à un simple affichage de la Planche sur la sortie standard.
