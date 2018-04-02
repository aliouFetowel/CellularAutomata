#ifndef _GRILLE_H
#define _GRILLE_H

#include<vector>
#include<time.h>
#include<string>
#include<fstream>

#include"Cellule.h"

using namespace std;

#define N 30

class Grille{
  private:
    vector<vector<Cellule> > cells;
    static string fichier;
    fstream file;
   public:
    Grille();
    //~Grille();

    void affiche(ostream&) const;
    void ecrire();
    void lire();
    Cellule getCellule(int , int);
    void iniRand();
    void Voisins(int, int, vector<Cellule>&);
    int voisinsVivant(int, int);
    void EtapeSuivante();
    Grille* operator=(const Grille&);
    //fstream& operator=(const fstream&);
};

ostream& operator<<(ostream&, Grille&);


#endif
