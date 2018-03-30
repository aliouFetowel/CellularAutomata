/** file Cellule.h
* Class représentant une cellule
*/
#ifndef _CELLULE_H
#define _CELLULE_H

#include<vector>
#include<iostream>

using namespace std;

class Cellule{
  private:
    bool etat;
    int abs;
    int ord;

  public:
  /* constructeurs */
    Cellule(bool = false, int = 0, int = 0);
  /* getteurs et setteurs */
    bool getEtat() const;
    int getAbs() const;
    int getOrd() const;
    void setEtat(bool);

    void affiche(ostream&) const;

    //operator
    Cellule& operator=(const Cellule&);
};

ostream& operator<<(ostream&, Cellule&);
#endif
