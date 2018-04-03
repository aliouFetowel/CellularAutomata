#ifndef _GRILLE_H
#define _GRILLE_H

#include<vector>
#include<time.h>
#include<string>
#include<fstream>

#include"Cellule.h"

using namespace std;

#define N 60

class Grille{
  private:
    vector<vector<Cellule> > cells;
    static string fichier;
    fstream file;
   public:
    Grille();
    

    void affiche(ostream&) const;
    void ecrire();
    void lire();
    Cellule getCellule(int , int);
    void iniRand();
    void Voisins(int, int, vector<Cellule>&);
    void predProieVoisins(int x, int y, int tab[]);

    void EtapeSuivante();
    Grille* operator=(const Grille&);
   
};

ostream& operator<<(ostream&, Grille&);


#endif
