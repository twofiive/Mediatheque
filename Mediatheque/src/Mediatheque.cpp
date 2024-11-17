#include "Mediatheque.h"
#include <string>
#include <iostream>
#include <fstream>

Mediatheque::Mediatheque() {}
Mediatheque::~Mediatheque() {}

void Mediatheque::afficher(string& chemin) 
{
    ifstream fichier(chemin);
    string ligne;
    if (fichier.is_open())
    {
        while (getline(fichier, ligne))
        {
            cout << ligne << endl;
        }
        fichier.close();
    }
    else
    {
        cerr << "Erreur d'ouverture du fichier : " << chemin << endl;
    }
}

void Mediatheque::rechercher(string& chemin, string& recherche) // Retirer const si non souhaité
{
    ifstream fichier(chemin);
    string line;
    bool wfind = false;

    if (fichier.is_open())
    {
        while (getline(fichier, line))
        {
            if (line.find(recherche) != string::npos)
            {
                cout << "Resultat de la recherche : " << endl;
                cout << line << endl;
                wfind = true;
            }
        }
        fichier.close();

        if (!wfind)
        {
            cerr << "La notice recherchée n'existe pas dans le fichier : " << chemin << endl;
        }
    }
    else
    {
        cerr << "Erreur d'ouverture du fichier : " << chemin << endl;
    }
}

void Mediatheque::supprimer(string& chemin, string& basechemin, int& id) // Retirer const si non souhaité
{
    string chemin_temp = basechemin + "cd_temp.txt";
    string line;
    string idtostr = to_string(id);
    ifstream fichier(chemin);
    ofstream fichier_temp(chemin_temp);

    bool id_trouve = false;

    if (fichier.is_open() && fichier_temp.is_open())
    {
        while (getline(fichier, line))
        {
            if (line.find(idtostr) == string::npos)
            {
                fichier_temp << line << endl;
            }
            else
            {
                cout << "Suppression de la ligne : " << line << endl;
                id_trouve = true;
            }
        }

        fichier.close();
        fichier_temp.close();

        if (id_trouve)
        {
            if (remove(chemin.c_str()) != 0)
            {
                cerr << "Erreur lors de la suppression du fichier original." << endl;
            }
            else if (rename(chemin_temp.c_str(), chemin.c_str()) != 0)
            {
                cerr << "Erreur lors du renommage du fichier temporaire." << endl;
            }
        }
        else
        {
            remove(chemin_temp.c_str());
            cerr << "L'ID recherché n'a pas été trouvé : " << id << endl;
        }
    }
    else
    {
        cerr << "Erreur lors de l'ouverture des fichiers." << endl;
    }
}

void Mediatheque::ajouter(string& chemin, string& donnees) // Retirer const si non souhaité
{
    ofstream fichier(chemin);
    if (fichier.is_open())
    {
        fichier << donnees << endl;
        fichier.close();
    }
    else
    {
        cerr << "Erreur d'ouverture du fichier : " << chemin << endl;
    }
}
