#include<iostream>
#include<string>
#include<fstream>
#include"../include/Cellule.h"
#include"../include/Grille.h"

int main(){
  Grille *g = new Grille(); Grille *g2;
  g->iniRand();
  g->ecrire();
  cout<<"la grille g"<<endl;
  cout<<g<<endl;
  g2 = g->lire();
  cout<<"la grille g2"<<endl;
  cout<<g2<<endl;

  g->EtapeSuivante(g2);
  cout<<"la grille g après les règles"<<endl;
  cout<<g<<endl;
  g->ecrire();

  //g.lire();
  //g.iniVoisins();
  //cout<<g<<endl;
  return 0;
}
