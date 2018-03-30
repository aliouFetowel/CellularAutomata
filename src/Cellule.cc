#include<iostream>
#include<vector>

#include"../include/Cellule.h"

using namespace std;


Cellule::Cellule(bool etat, int abs, int ord)
{
  this->etat = etat;
  this->abs = abs;
  this->ord = ord;
}

bool Cellule::getEtat() const
{
  return this->etat;
}

void Cellule::setEtat(bool etat)
{
  this->etat = etat;
}

int Cellule::getAbs() const
{
    return this->abs;
}

int Cellule::getOrd() const
{
    return this->ord;
}

void  Cellule::affiche(ostream& os) const
{
  os<<etat;
}

ostream& operator<<(ostream& os, Cellule& c)
{
  c.affiche(os);
  return os;
}

Cellule& Cellule::operator=(const Cellule& celCopie)
{
     this->etat = celCopie.etat;
     this->abs = celCopie.abs;
     this->ord = celCopie.ord;
     return *this;
}
