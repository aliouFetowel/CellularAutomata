#include<iostream>
#include<time.h>

#include"../include/Cellule.h"
#include"../include/Planche.h"

using namespace std;

Planche::Planche()
{
  this.n = N;
  for(int i = 0; i < n; i++){
      int x = rand() % n;
      int y = rand() % n;
      if(Cells[x][y] != 1) Cells[x][y] = 1;
  }
}


void Planche::affiche(ostream& os) const 
{
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cells[i][j]->affiche(os);
      os<<endl;
    }
  }
}

ostream& operator<<(ostream& os, Planche& p)
{
  p.affiche(os);
  return os;
}