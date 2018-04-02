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

string Grille::fichier = "../Ressources/jeux.txt";
//fstream Grille::file(fichier, fstream::in | fstream::out | fstream::app);

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

 /* file.open(fichier, fstream::in | fstream::out);
  if(!file){
      cerr<<"erreur lors de l'ouverture du fichier"<<endl;
  }*/
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
    file.open(fichier, fstream::in | fstream::app);
    //cout<<"position avant écriture "<<file.tellp()<<endl;
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
    //cout<<"position après écriture "<<file.tellg()<<endl;
    /*cout<<"position "<<file.tellp()<<endl;
    file.seekp(-114, ios::cur);
    cout<<"position "<<file.tellp()<<endl;*/
    file.close();

}

void Grille::lire(){
//  ifstream file(fichier.c_str());
    //Grille *g2 = new Grille();
    file.open(fichier, fstream::out | fstream::app);
    //cout<<"dans lire position "<<file.tellg()<<endl;
    if(file.tellg() != 0) file.seekg(-(N*N+14), ios::cur); //pour lire la dernière grille
    //cout<<"dans lire position "<<file.tellg()<<endl;

    string chaine = "", ligne = "";
    char delim;
    int k = 0;
    if(file){
        file >> delim; // récuperer $
    //    cout<<"le delimitateur est"<<delim<<endl;
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
        //    cout<<"dans la lecture position "<<file.tellg()<<endl;
        }
        //file.seekg(-114, ios::cur); //pour lire la dernière grille
    }else{
        cerr << "erreur lors de l'ouverture du fichier" <<endl;
    }
    //cout<<"position après lecture "<<file.tellg()<<endl;
    file.close();
}


Cellule Grille::getCellule(int abs, int ord)
{
    return cells[abs][ord];
}

 void Grille::Voisins(int i, int j, vector<Cellule>& vois)
{
            //vector<Cellule> *vois = NULL;
        //    cout<<"dans getVoisins "<<vois.size()<<endl;

            if(i == 0 && j == 0){
                vois.push_back(getCellule(j,N-1));
                vois.push_back(getCellule(j+1,N-1));
                vois.push_back(getCellule(N-1,i));
                vois.push_back(getCellule(N-1,i+1));
                vois.push_back(getCellule(N-1,N-1));
                vois.push_back(getCellule(i+1,j));
                vois.push_back(getCellule(i+1,j+1));
                vois.push_back(getCellule(i,j+1));

            }
            else if(i == 0 && j == N-1){
                vois.push_back(getCellule(N-1, N-1));
                vois.push_back(getCellule(i+1,j-1));
                vois.push_back(getCellule(j-1,N-1));
                vois.push_back(getCellule(0,0));
                vois.push_back(getCellule(i+1,0));
                vois.push_back(getCellule(i,j-1));
                vois.push_back(getCellule(i+1,j));
                vois.push_back(getCellule(j,0));

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

            }
            /*cout<<"la taille des voisins est "<<vois->size()<<endl;
        return *vois;*/
}

int Grille::voisinsVivant(int x, int y)
{
    int cpt = 0;
    //printf("avant appel de getVoisins \n" );

    vector<Cellule> vois;
    //cout<<"la valeur de getVoisins" <<getVoisins(x, y).size()<<endl;
    //return getVoisins(x,y).size();
    Voisins(x, y, vois);
    //cout<<"le nombre de voisins est "<<vois.size()<<endl;
    for(unsigned int i = 0; i < vois.size(); i++){
        if(vois[i].getEtat() == true) cpt++;
    }
    return cpt;
}

void Grille::EtapeSuivante()
{
    Grille *g = new Grille();
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            //printf("je suis dans la boucle\n");
            int nbVoisins = voisinsVivant(i,j);
            //Cellule cel = getCellule(i,j);
            if(cells[i][j].getEtat() == false){
                if(nbVoisins == 3) g->cells[i][j].setEtat(true);
            }
            if(cells[i][j].getEtat() == true){
            //    printf("je suis dans le prémier if\n");
                if(nbVoisins == 2 || nbVoisins == 3) g->cells[i][j].setEtat(true);
                else g->cells[i][j].setEtat(false);

            }
        }
    }
    
    *this = *g;
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

Grille* Grille::operator=(const Grille& g)
{
    this->cells = g.cells;
    //file = g.file;
    return this;
}

/*
fstream& Grille::operator=(const fstream& f)
{
    file = f;
    return *f;
}*/
