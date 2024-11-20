#include "Mediatheque.h"
#include <string>
#include <iostream>
#include <fstream>
Mediatheque::Mediatheque() {};
Mediatheque::Mediatheque(const string &titre, int ID) : titre(titre), id(ID) {}
Mediatheque::~Mediatheque() {}

void Mediatheque::afficher(const string &path)
{
    ifstream fichier(path);
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
        cerr << "Erreur d'ouverture du fichier : " << path << endl;
    }
}

void Mediatheque::rechercher(const string &path, string &titre, int &id)
{
    ifstream fichier(path);
    string line;
    bool wfind = false;
    string idStr = to_string(id);

    if (fichier.is_open())
    {
        while (getline(fichier, line))
        {
            if (line.find(titre) != string::npos && line.find(idStr) != string::npos)
            {
                cout << "Resultat de la recherche : " << endl;
                cout << line << endl;
                wfind = true;
            }
        }
        fichier.close();

        if (!wfind)
        {
            cerr << "La notice recherchée n'existe pas dans le fichier : " << path << endl;
        }
    }
    else
    {
        cerr << "Erreur d'ouverture du fichier : " << path << endl;
    }
}

void Mediatheque::supprimer(const string &path, string &basepath, int &id)
{
    string path_temp = basepath + "cd_temp.txt";
    string line;
    string idtostr = to_string(id);
    ifstream fichier(path);
    ofstream fichier_temp(path_temp);

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
            if (remove(path.c_str()) != 0)
            {
                cerr << "Erreur lors de la suppression du fichier original." << endl;
            }
            else if (rename(path_temp.c_str(), path.c_str()) != 0)
            {
                cerr << "Erreur lors du renommage du fichier temporaire." << endl;
            }
        }
        else
        {
            remove(path_temp.c_str());
            cerr << "L'ID recherché n'a pas été trouvé : " << id << endl;
        }
    }
    else
    {
        cerr << "Erreur lors de l'ouverture des fichiers." << endl;
    }
}

void Mediatheque::ajouter(const string &path, string &data)
{
    ofstream fichier(path, ios::app);
    if (fichier.is_open())
    {
        fichier << data << endl;
        fichier.close();
    }
    else
    {
        cerr << "Erreur d'ouverture du fichier : " << path << endl;
    }
}

void Mediatheque::modifier(const string &path, string &basepath, string &to_update, string &upwd)
{
    string path_temp = basepath + "cd_temp.txt";
    string line;
    ifstream fichier(path);
    ofstream fichier_temp(path_temp);
    size_t indexw;

    bool update_find = false;

    if (fichier.is_open() && fichier_temp.is_open())
    {
        while (getline(fichier, line))
        {
            indexw = line.find(to_update);
            if (indexw != string::npos)
            {

                line.replace(indexw, to_update.length(), upwd);
                cout << endl;
                cout << "Modification :" << line << endl;
                cout << endl;
                update_find = true;
            }
            fichier_temp << line << endl;
        }

        fichier.close();
        fichier_temp.close();

        if (update_find)
        {
            if (remove(path.c_str()) != 0)
            {
                cerr << "Erreur lors de la suppression du fichier original." << endl;
            }
            else if (rename(path_temp.c_str(), path.c_str()) != 0)
            {
                cerr << "Erreur lors du renommage du fichier temporaire." << endl;
            }
        }
        else
        {
            remove(path_temp.c_str());
            cerr << "Impossible de trouvé : " << upwd << endl;
        }
    }
    else
    {
        cerr << "Erreur lors de l'ouverture des fichiers." << endl;
    }
}