#include<iostream>
#include<string>
#include<fstream>
#include<stdio.h>
#include"../include/Cellule.h"
#include"../include/Grille.h"

int main(){
  Grille *g = new Grille();
  g->iniRand();
  g->ecrire();
  do{
      cout<<"\ntapez entrer pour continuer \n'q' pour quitter\n"<<endl;

      g->lire();
      g->EtapeSuivante();
      cout<<*g<<endl;
      g->ecrire();
  }while(fgetc(stdin) != 'q');
  return 0;
}
