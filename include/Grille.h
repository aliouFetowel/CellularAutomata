#ifndef _GRILLE_H
#define _GRILLE_H

#include<vector>
#include<time.h>
#include"Cellule.h"

using namespace std;

#define N 10

class Grille{
  private:
    vector<vector<Cellule> > cells;
   public:
    Grille();

    void affiche(ostream&) const;
};

std::ostream& operator<<(ostream&, Grille&);

#endif
