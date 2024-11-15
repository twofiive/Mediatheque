#include "Mediatheque.h"
#include <string>

Mediatheque::Mediatheque()
{
}
Mediatheque::~Mediatheque()
{
}
void Mediatheque::afficher(string &chemin)
{
    ifstream fichier(chemin);
    string ligne;
    if (fichier.is_open())
    {
        while (getline(fichier, ligne))
        {
            cout << ligne << endl;
        }
    }
    else
    {
        cerr << "Erreur d'ouverture du fichier : " << chemin << std::endl;
    }
    fichier.close();
}

void Mediatheque::rechercher(string &chemin, string &recherche)
{
    ifstream fichier(chemin);
    string line;
    bool mot_trouuve = false;
    if (fichier.is_open())
    {

        while (getline(fichier, line))
        {

            if (line.find(recherche) != string::npos)
            {
                cout << "Resultat de la recherrche : " << endl;
                cout << line << endl;
                mot_trouuve = true;
            }
            if (mot_trouuve != true)
            {
                cerr << "La notice recherché n'existe pas ! " << chemin << endl;
            }
            else
            {
                cerr << "Erreur d'ouverture du fichier : " << chemin << std::endl;
            }

            fichier.close();
        }
    }
}

void Mediatheque::supprimer(string &chemin, string &basechemin, int &id)
{
    string chemin_temp = basechemin + "cd_temp.txt";
    string line;
    string id = to_string(id);
    ifstream fichier(chemin);
    ofstream fichier_temp(chemin_temp);

    bool id_trouve = false;

    if (fichier.is_open() && fichier_temp.is_open())
    {

        while (getline(fichier, line))
        {

            if (line.find(id) == string::npos)
            {
                fichier_temp << line << endl;
            }
            else
            {
                cout << endl;
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

void Mediatheque::ecriturefichier(string &chemin, string &Donnees)
{
    ofstream fichier(chemin);
    if (fichier)
    {
        fichier << Donnees << endl;
    }
    else
    {
        cerr << "Erreur d'ouverture du fichier : " << chemin << std::endl;
    }
    fichier.close();
}