#include<iostream>
#include<string>
#include<fstream>
#include"../include/Cellule.h"
#include"../include/Grille.h"

int main(){
  Grille g; Grille g2;
  g.iniRand();
  g.ecrire();
  cout<<"la grille g"<<endl;
  cout<<g<<endl;

  g.lire();
  cout<<"après lecture"<<endl;
  cout<<g<<endl;

  g.EtapeSuivante();
  cout<<"la grille g après les règles"<<endl;
  //cout<<g<<endl;
  g.ecrire();

  cout<<g<<endl;

  //vector<Cellule> vois  = g.getVoisins(0,0);


  g.lire();

  cout<<g<<endl;

  //g.lire();
  //g.iniVoisins();
  //cout<<g<<endl;
  return 0;
}
