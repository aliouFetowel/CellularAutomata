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
          cells[i][j] = Cellule(false, i, j);
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
    /*cout<<"position "<<file.tellp()<<endl;
    file.seekp(-114, ios::cur);
    cout<<"position "<<file.tellp()<<endl;*/

}


Cellule Grille::getCellule(int abs, int ord)
{
    return cells[abs][ord];
}

 vector<Cellule>& Grille::getVoisins(int i, int j)
{
            vector<Cellule> * vois = NULL;

            if(i == 0 && j == 0){
                vois->push_back(getCellule(j,N-1));
                vois->push_back(getCellule(j+1,N-1));
                vois->push_back(getCellule(N-1,i));
                vois->push_back(getCellule(N-1,i+1));
                vois->push_back(getCellule(N-1,N-1));
                vois->push_back(getCellule(i+1,j));
                vois->push_back(getCellule(i+1,j+1));
                vois->push_back(getCellule(i,j+1));

            }
            else if(i == 0 && j == N-1){
                vois->push_back(getCellule(N-1, N-1));
                vois->push_back(getCellule(i+1,j-1));
                vois->push_back(getCellule(j-1,N-1));
                vois->push_back(getCellule(0,0));
                vois->push_back(getCellule(i+1,0));
                vois->push_back(getCellule(i,j-1));
                vois->push_back(getCellule(i+1,j));
                vois->push_back(getCellule(j,0));

            }
            else if(i == N-1 && j == 0){
                vois->push_back(getCellule(i-1,j));
                vois->push_back(getCellule(i,j+1));
                vois->push_back(getCellule(i-1,j-1));
                vois->push_back(getCellule(j,j));
                vois->push_back(getCellule(j,j+1));
                vois->push_back(getCellule(N-1,N-1));
                vois->push_back(getCellule(i-1,N-1));
                vois->push_back(getCellule(j,N-1));

            }
            else if(i == N-1 && j == N-1){
                vois->push_back(getCellule(i-1,j));
                vois->push_back(getCellule(i-1,j-1));
                vois->push_back(getCellule(i,j-1));
                vois->push_back(getCellule(0,j));
                vois->push_back(getCellule(0,j-1));
                vois->push_back(getCellule(i-1,0));
                vois->push_back(getCellule(i,0));
                vois->push_back(getCellule(0,0));

            }
            else if(i == 0 && j != 0 && j != N-1){
                vois->push_back(getCellule(i,j-1));
                vois->push_back(getCellule(i+1,j-1));
                vois->push_back(getCellule(i+1,j));
                vois->push_back(getCellule(i+1,j+1));
                vois->push_back(getCellule(i,j+1));
                vois->push_back(getCellule(N-1,j-1));
                vois->push_back(getCellule(N-1,j));
                vois->push_back(getCellule(N-1,j+1));

            }
            else if(i == N-1 && j != i && j != 0){
                vois->push_back(getCellule(i,j-1));
                vois->push_back(getCellule(i-1,j-1));
                vois->push_back(getCellule(i-1,j));
                vois->push_back(getCellule(i-1,j+1));
                vois->push_back(getCellule(i,j+1));
                vois->push_back(getCellule(0,j-1));
                vois->push_back(getCellule(0,j));
                vois->push_back(getCellule(0,j+1));

            }
            else if(j == 0 && i != j && i != N-1){
                vois->push_back(getCellule(i-1,j));
                vois->push_back(getCellule(i-1,j+1));
                vois->push_back(getCellule(i,j+1));
                vois->push_back(getCellule(i+1,j+1));
                vois->push_back(getCellule(i+1,j));
                vois->push_back(getCellule(i-1,N-1));
                vois->push_back(getCellule(i,N-1));
                vois->push_back(getCellule(i+1,N-1));

            }
            else if(j == N-1 && i != j && i != 0){
                vois->push_back(getCellule(i-1,j));
                vois->push_back(getCellule(i-1,j-1));
                vois->push_back(getCellule(i,j-1));
                vois->push_back(getCellule(i+1,j-1));
                vois->push_back(getCellule(i+1,j));
                vois->push_back(getCellule(i-1,0));
                vois->push_back(getCellule(i,0));
                vois->push_back(getCellule(i+1,0));

            }
            else{
                vois->push_back(getCellule(i-1,j-1));
                vois->push_back(getCellule(i-1,j));
                vois->push_back(getCellule(i-1,j+1));
                vois->push_back(getCellule(i,j+1));
                vois->push_back(getCellule(i+1,j+1));
                vois->push_back(getCellule(i+1,j));
                vois->push_back(getCellule(i+1, j-1));
                vois->push_back(getCellule(i,j-1));

            }
        return *vois;
}

int Grille::voisinsVivant(int x, int y)
{
    int cpt = 0;
    vector<Cellule> vois = getVoisins(x, y);
    for(unsigned int i = 0; i < vois.size(); i++){
        if(vois[i].getEtat() == true) cpt++;
    }
    return cpt;
}

void Grille::EtapeSuivante(Grille& grille)
{
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            int nbVoisins = voisinsVivant(i,j);
            if(nbVoisins == 3){
                cells[i][j].setEtat(true);
            }
            else if( nbVoisins == 4 || nbVoisins == 1 || nbVoisins == 0){
                cells[i][j].setEtat(false);
            }
        }
    }
    ecrire();
}



Grille& Grille::lire(){
//    ifstream file(fichier.c_str());
    Grille *g = new Grille();
    if(file.tellg() != 0) file.seekg(-114, ios::cur); //pour lire la dernière grille
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
                    g->cells[k][j].setEtat((bool)ligne[j]);
                }
                k++;
                ligne = "";
            }
        }
    }else{
        cerr << "erreur lors de l'ouverture du fichier" <<endl;
    }
    return *g;
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
