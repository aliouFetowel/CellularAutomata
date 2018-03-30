#include<iostream>
#include<string>
#include<fstream>
#include"../include/Cellule.h"
#include"../include/Grille.h"

int main(){
  Grille g = Grille();
  cout<<g<<endl;
  g.iniRand();
  g.ecrire();
  g.lire();
  cout<<g<<endl;
  return 0;
}
