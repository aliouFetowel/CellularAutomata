#ifndef _GRILLE_H
#define _GRILLE_H

#include<vector>
#include<time.h>
#include<string>
#include<fstream>

#include"Cellule.h"

using namespace std;

#define N 10

class Grille{
  private:
    vector<vector<Cellule> > cells;
    string const fichier = "../Ressources/jeux.txt";
    fstream file;
   public:
    Grille();
    //~Grille();

    void affiche(ostream&) const;
    void ecrire();
    Grille& lire();
    Cellule getCellule(int , int);
    void iniRand();
    vector<Cellule>& getVoisins(int, int);
    int voisinsVivant(int, int);
    void EtapeSuivante(Grille&);
};

ostream& operator<<(ostream&, Grille&);

#endif
