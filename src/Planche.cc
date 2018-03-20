#include<iostream>
#include<stdlib.h>
#include<time.h>

#include"../include/Cellule.h"
#include"../include/Planche.h"

using namespace std;


Planche::Planche()
{
  srand(time(NULL));
  for(int i = 0; i < N; i++){
    cells.push_back(vector<Cellule>(N)); /* ajouts de ligne N cases */
  }
  for(int i = 0; i < N; i++){
      int x = rand() % N;
      int y = rand() % N;
      if(cells[x][y].getEtat() != true) cells[x][y] = true;
  }
}


void Planche::affiche(ostream& os) const
{
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      cells[i][j].affiche(os);
      os<<" ";
    }
    os<<endl;
  }
}

ostream& operator<<(ostream& os, Planche& p)
{
  p.affiche(os);
  return os;
}
