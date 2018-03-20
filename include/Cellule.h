/** file Cellule.h
* Class représentant une cellule
*/
#ifndef _CELLULE_H
#define _CELLULE_H

#include<iostream>

using namespace std;

class Cellule{
  private: 
    bool etat;
  
  public:
  /* constructeurs */
    Cellule();
    Cellule(bool);
  /* getteurs et setteurs */
    bool getEtat() const;
    void setEtat(bool);
    
    ostream& affiche(ostream&);
};

ostream& operator<<(ostream&, Cellule&)
#endif
