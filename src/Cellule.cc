#include<iostream>
#include<vector>

#include"../include/Cellule.h"

#define RED "\033[00;31m"
#define GREEN "\033[00;33m"
#define BLACK "\033[00;30m"
#define DEFAULT "\033[00m"

using namespace std;


Cellule::Cellule(Etat etat, int abs, int ord)
{
  this->etat = etat;
  this->abs = abs;
  this->ord = ord;
}

Etat Cellule::getEtat() const
{
  return this->etat;
}

void Cellule::setEtat(Etat etat)
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

    if(etat == Etat::pred) os<<RED<<"x"<<DEFAULT;
    else if(etat == Etat::proie) os<<GREEN<<"x"<<DEFAULT;
    else os<<BLACK<<"."<<DEFAULT;
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
