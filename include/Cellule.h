/** file Cellule.h
* Class représentant une cellule
*/
#ifndef _CELLULE_H
#define _CELLULE_H

#include<vector>
#include<iostream>

using namespace std;

enum class Etat {pred, proie, vide} ;

class Cellule{
  private:
    Etat etat;
    int abs;
    int ord;

  public:
  /* constructeurs */
    Cellule(Etat = Etat::vide, int = 0, int = 0);
  /* getteurs et setteurs */
    Etat getEtat() const;
    int getAbs() const;
    int getOrd() const;
    void setEtat(Etat);

    void affiche(ostream&) const;

    //operator
    Cellule& operator=(const Cellule&);
};

ostream& operator<<(ostream&, Cellule&);
#endif
