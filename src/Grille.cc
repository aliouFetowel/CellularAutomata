#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<fstream>
#include<string>
#include<cstring>
#include<sstream>


#include"../include/Cellule.h"
#include"../include/Grille.h"

using namespace std;


Grille::Grille()
{
  srand(time(NULL));
  for(int i = 0; i < N; i++){
    cells.push_back(vector<Cellule>(N)); /* ajouts de ligne N cases */
  }
  for(int i = 0; i < N; i++){
      for(int j = 0; j < N; j++){
          cells[i][j] = Cellule(0, i, j);
      }
  }

  file.open(fichier, fstream::in | fstream::out);
  if(!file){
      cerr<<"erreur lors de l'ouverture du fichier"<<endl;
  }
}

void Grille::iniRand()
{
    for(int i = 0; i < N*5; i++){
        int x = rand() % N;
        int y = rand() % N;

        cells[x][y].setEtat(true);
    }
}

void Grille::ecrire(){
    //ofstream file(fichier.c_str());
    string chaine = "";
    if(file){
        file << "$";
        chaine.append(1,'\n');
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                chaine.append(1, (bool)cells[i][j].getEtat());
            }
            chaine.append(1,'\n');
        }
        file << chaine;
        file << "$";
        file << "\n";
    }else{
        cerr <<"erreur lors de l'ouverture du fichier"<<endl;
    }
}


Cellule Grille::getCellule(int abs, int ord)
{
    return cells[abs][ord];
}

void Grille::iniVoisins()
{
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            vector<Cellule> vois;
            vois.clear();
            if(i == 0 && j == 0){
                vois.push_back(getCellule(j,N-1));
                vois.push_back(getCellule(j+1,N-1));
                vois.push_back(getCellule(N-1,i));
                vois.push_back(getCellule(N-1,i+1));
                vois.push_back(getCellule(N-1,N-1));
                vois.push_back(getCellule(i+1,j));
                vois.push_back(getCellule(i+1,j+1));
                vois.push_back(getCellule(i,j+1));

                cells[i][j].addVoisins(vois);
            }
            else if(i == 0 && j == N-1){
                vois.push_back(getCellule(N-1, N-1));
                vois.push_back(getCellule(i+1,j-1));
                vois.push_back(getCellule(N+1,0));
                vois.push_back(getCellule(0,0));
                vois.push_back(getCellule(1,0));
                vois.push_back(getCellule(i,j-1));
                vois.push_back(getCellule(i+1,j-1));
                vois.push_back(getCellule(i+1,j));

                cells[i][j].addVoisins(vois);
            }
            else if(i == N-1 && j == 0){
                vois.push_back(getCellule(i-1,j));
                vois.push_back(getCellule(i,j+1));
                vois.push_back(getCellule(i-1,j-1));
                vois.push_back(getCellule(j,j));
                vois.push_back(getCellule(j,j+1));
                vois.push_back(getCellule(N-1,N-1));
                vois.push_back(getCellule(i-1,N-1));
                vois.push_back(getCellule(j,N-1));

                cells[i][j].addVoisins(vois);
            }
            else if(i == N-1 && j == N-1){
                vois.push_back(getCellule(i-1,j));
                vois.push_back(getCellule(i-1,j-1));
                vois.push_back(getCellule(i,j-1));
                vois.push_back(getCellule(0,j));
                vois.push_back(getCellule(0,j-1));
                vois.push_back(getCellule(i-1,0));
                vois.push_back(getCellule(i,0));
                vois.push_back(getCellule(0,0));

                cells[i][j].addVoisins(vois);
            }
            else if(i == 0 && j != 0 && j != N-1){
                vois.push_back(getCellule(i,j-1));
                vois.push_back(getCellule(i+1,j-1));
                vois.push_back(getCellule(i+1,j));
                vois.push_back(getCellule(i+1,j+1));
                vois.push_back(getCellule(i,j+1));
                vois.push_back(getCellule(N-1,j-1));
                vois.push_back(getCellule(N-1,j));
                vois.push_back(getCellule(N-1,j+1));

                cells[i][j].addVoisins(vois);
            }
            else if(i == N-1 && j != i && j != 0){
                vois.push_back(getCellule(i,j-1));
                vois.push_back(getCellule(i-1,j-1));
                vois.push_back(getCellule(i-1,j));
                vois.push_back(getCellule(i-1,j+1));
                vois.push_back(getCellule(i,j+1));
                vois.push_back(getCellule(0,j-1));
                vois.push_back(getCellule(0,j));
                vois.push_back(getCellule(0,j+1));

                cells[i][j].addVoisins(vois);
            }
            else if(j == 0 && i != j && i != N-1){
                vois.push_back(getCellule(i-1,j));
                vois.push_back(getCellule(i-1,j+1));
                vois.push_back(getCellule(i,j+1));
                vois.push_back(getCellule(i+1,j+1));
                vois.push_back(getCellule(i+1,j));
                vois.push_back(getCellule(i-1,N-1));
                vois.push_back(getCellule(i,N-1));
                vois.push_back(getCellule(i+1,N-1));

                cells[i][j].addVoisins(vois);
            }
            else if(j == N-1 && i != j && i != 0){
                vois.push_back(getCellule(i-1,j));
                vois.push_back(getCellule(i-1,j-1));
                vois.push_back(getCellule(i,j-1));
                vois.push_back(getCellule(i+1,j-1));
                vois.push_back(getCellule(i+1,j));
                vois.push_back(getCellule(i-1,0));
                vois.push_back(getCellule(i,0));
                vois.push_back(getCellule(i+1,0));

                cells[i][j].addVoisins(vois);
            }
            else{
                vois.push_back(getCellule(i-1,j-1));
                vois.push_back(getCellule(i-1,j));
                vois.push_back(getCellule(i-1,j+1));
                vois.push_back(getCellule(i,j+1));
                vois.push_back(getCellule(i+1,j+1));
                vois.push_back(getCellule(i+1,j));
                vois.push_back(getCellule(i+1, j-1));
                vois.push_back(getCellule(i,j-1));

                cells[i][j].addVoisins(vois);
            }
        }
    }
}

void Grille::lire(){
//    ifstream file(fichier.c_str());
    string chaine = "", ligne = "";
    char delim;
    int k = 0;
    if(file){
        file >> delim; // récuperer $
        while(getline(file, chaine,  delim)){
            stringstream ss(chaine);
            getline(ss,ligne,'\n'); // pour sautetr une ligne
            while(getline(ss, ligne, '\n')){
                for(int j = 0; j < N; j++){
                    cells[k][j].setEtat((bool)ligne[j]);
                }
                k++;
                ligne = "";
            }
        }
    }else{
        cerr << "erreur lors de l'ouverture du fichier" <<endl;
    }
}


void Grille::affiche(ostream& os) const
{
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      cells[i][j].affiche(os);
      os<<" ";
    }
    os<<endl;
  }
}

ostream& operator<<(ostream& os, Grille& p)
{
  p.affiche(os);
  return os;
}
