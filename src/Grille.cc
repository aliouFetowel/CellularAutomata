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
          cells[i][j] = Cellule(Etat::vide, i, j);
      }
  }

 /* file.open(fichier, fstream::in | fstream::out);
  if(!file){
      cerr<<"erreur lors de l'ouverture du fichier"<<endl;
  }*/
}

void Grille::iniRand()
{
    for(int i = 0; i < N; i++){
        int x = rand() % N;
        int y = rand() % N;
        int z = rand() % 2;
        if(z == 0) cells[x][y].setEtat(Etat::pred);
        else cells[x][y].setEtat(Etat::proie);

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
                char aEcrire;
                if(cells[i][j].getEtat() == Etat::pred) aEcrire = 'P';
                if(cells[i][j].getEtat() == Etat::proie) aEcrire = 'Q';
                if(cells[i][j].getEtat() == Etat::vide) aEcrire = '.';

                chaine.append(1, aEcrire);
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
                    if(ligne[j] == 'P') cells[k][j].setEtat(Etat::pred);
                    if(ligne[j] == 'Q') cells[k][j].setEtat(Etat::proie);
                    if(ligne[j] == '.') cells[k][j].setEtat(Etat::vide);
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
/*

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
}*/

void Grille::predProieVoisins(int x, int y, int tab[2]){
    int pred = 0, proie = 0;
    //printf("avant appel de getVoisins \n" );

    vector<Cellule> vois;
    //cout<<"la valeur de getVoisins" <<getVoisins(x, y).size()<<endl;
    //return getVoisins(x,y).size();
    Voisins(x, y, vois);
    //cout<<"le nombre de voisins est "<<vois.size()<<endl;
/*    cout<<"\npour la cellule "<<x<<" "<<y<<endl;
    for(unsigned int i = 0; i< vois.size(); i++){
        if(vois[i].getEtat() == Etat::pred) cout<<" p ";
        if(vois[i].getEtat() == Etat::proie) cout<<"q ";
    }*/
    for(unsigned int i = 0; i < vois.size(); i++){
        if(vois[i].getEtat() == Etat::pred) pred++;
        if(vois[i].getEtat() == Etat::proie) proie++;
    }
    tab[0] = pred;
    tab[1] = proie;
}


void Grille::EtapeSuivante(){
    Grille *g = new Grille();
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            int nbVois[2]={0};
            predProieVoisins(i,j,nbVois);

            //cout<<"cellule "<<i<<" "<<j<<" pred "<<nbVois[0]<<" proie "<<nbVois[1]<<endl;

            if(cells[i][j].getEtat() == Etat::pred){
                if(nbVois[1] == 0) g->cells[i][j].setEtat(Etat::vide);
                else if(nbVois[1] >= 1)g->cells[i][j].setEtat(Etat::pred);
            }
            if(cells[i][j].getEtat() == Etat::proie){
                if(nbVois[1] > 7) g->cells[i][j].setEtat(Etat::vide);
                else if(nbVois[0] > 4) g->cells[i][j].setEtat(Etat::pred);
                else if(nbVois[0] > 0 && nbVois[0] < 5) g->cells[i][j].setEtat(Etat::proie);
                else g->cells[i][j].setEtat(Etat::proie);

            }
            if(cells[i][j].getEtat() == Etat::vide){
                if(nbVois[0] == nbVois[1]) g->cells[i][j].setEtat(Etat::vide);
                else if(nbVois[1] > nbVois[0]) g->cells[i][j].setEtat(Etat::proie);
                else if(nbVois[0] > nbVois[1]-1) g->cells[i][j].setEtat(Etat::pred);
                else g->cells[i][j].setEtat(Etat::vide);
            }
        }
    }
    *this =*g;
}

/*
void Grille::EtapeSuivante()
{
    Grille *g = new Grille();
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            //printf("je suis dans la boucle\n");
            int nbVois = voisinsVivant(i,j);
            //Cellule cel = getCellule(i,j);
            if(cells[i][j].getEtat() == false){
                if(nbVois == 3) g->cells[i][j].setEtat(true);
            }
            if(cells[i][j].getEtat() == true){
            //    printf("je suis dans le prémier if\n");
                if(nbVois == 2 || nbVois == 3) g->cells[i][j].setEtat(true);
                else g->cells[i][j].setEtat(false);

            }
        }
    }
    *this = *g;
}
*/


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
