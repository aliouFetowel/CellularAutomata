#include<iostream>
#include"../include/Cellule.h"
#include"../include/Planche.h"

int main(){
  Planche p = Planche();
  cout<<p.affiche(cout)<<endl;
  return 0;
}