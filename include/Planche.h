#ifndef _PLANCHE_H
#define _PLANCHE_H

#include<vector>
#include<time.h>
#include"Cellule.h"

define N 10;

class Planche{
  private:
    std::vector<Cellule> cells[N][N];
    int n;
   public:
    Planche();

    void affiche(std::ostream) const;
};
  
std::ostream& operator<<(std::ostream&, Planche&);

#endif