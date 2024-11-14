#include "Mediatheque.h"
#include <string>

Mediatheque::Mediatheque()
{
}
Mediatheque::~Mediatheque()
{
}
void Mediatheque::afficher(string &Chemin)
{
    ifstream fichier(Chemin);
    string ligne;
    if (fichier)
    {
        while (getline(fichier, ligne))
        {
            cout << ligne << endl;
        }
    }
    else
    {
        cerr << "Erreur d'ouverture du fichier : " << Chemin << std::endl;
    }
}
void Mediatheque::rechercher()
{
}
void Mediatheque::supprimer()
{
}

void Mediatheque::ecriturefichier(string &Chemin, string &Donnees)
{
    ofstream fichier(Chemin, std::ios::app);
    if (fichier)
    {
        fichier << Donnees << endl;
    }
    else
    {
        cerr << "Erreur d'ouverture du fichier : " << Chemin << std::endl;
    }
}