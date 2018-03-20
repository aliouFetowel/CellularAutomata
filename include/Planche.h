#ifndef _PLANCHE_H
#define _PLANCHE_H

#include<vector>
#include<time.h>
#include"Cellule.h"

using namespace std;

#define N 10

class Planche{
  private:
    vector<vector<Cellule> > cells;
   public:
    Planche();

    void affiche(ostream&) const;
};

std::ostream& operator<<(ostream&, Planche&);

#endif
