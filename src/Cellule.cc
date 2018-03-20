#include<iostream> 
#include"../include/Cellule.h"
using namespace std;

Cellule::Cellule(){
  this.etat = false; 
}

Cellule::Cellule(bool etat)
{
  this.etat = etat;
}

bool Cellule::getEtat() const 
{
  return this.etat;
}

void Cellule::setEtat(bool etat)
{
  this.etat = etat;
}


void  Cellule::affiche(ostream& os) const
{
  os<<etat<<;
}

ostream& operator<<(ostream& os, Cellule& c)
{
  c.affiche(os);
  return os;
}
