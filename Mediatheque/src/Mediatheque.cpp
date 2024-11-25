#include "Mediatheque.h"
#include <string>
#include <iostream>
#include <fstream>

//Constructeur par défaut de la classe mère
Mediatheque::Mediatheque() {};
//Constructeur avec paramètre qui prend en charge les attributs communs au trois classe fille
Mediatheque::Mediatheque(const string &titre, int ID) : titre(titre), id(ID) {}
//Destructeur
Mediatheque::~Mediatheque() {}


// Affichage des notice
void Mediatheque::afficher(const string &path)//Prend en argument le chemin définies dans les macros des classe fille.
{
    ifstream fichier(path); // ifstream permet de lire un fichier
    string ligne;// ligne permet de stocker la ligne qui sera lu par getline
    if (fichier.is_open())// Vérifie si le fichier et bien ouvert
    {
        while (getline(fichier, ligne))// getline permet de lire chaque ligne du fichier et de stocker la ligne afin de l'output
        {
            cout << ligne << endl;
        }
        fichier.close(); // ferme le fichier après que chaque ligne du fichier est était output
    }
    else
    {
        cerr << "Erreur d'ouverture du fichier : " << path << endl;
    }
}

void Mediatheque::rechercher(vector <string> &loadedData, vector <string> &data, const string &path) // Les argument passés sont
{
    bool wfind = false; // Permet de definir si le mot à été trouvé par défaut sur false

    for (const auto &line : loadedData)
    {
        if (line.find(data[0]) != string::npos && line.find(data[1]) != string::npos)//Permet de comparer le titre et id passé en
        {
            //argument afin de comparer et de rechercher le titre et l'id dans le fichier
            cout << "Resultat de la recherche : " << endl;                       //npos est un indicateur de non-correspondance
            cout << line << endl;
            wfind = true;
        }
    }

    if (!wfind)
    {
        cerr << "La notice recherchee n'existe pas dans le fichier : " << path << endl;
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

void Mediatheque::chargementdata(const string &path,vector <string> &data)//Prend en argument le chemin définies dans les macros des classe fille.
{
    ifstream fichier(path); // ifstream permet de lire un fichier
    string ligne;// ligne permet de stocker la ligne qui sera lu par getline
    if (fichier.is_open())// Vérifie si le fichier et bien ouvert
    {
        data.clear();
        while (getline(fichier, ligne))// getline permet de lire chaque ligne du fichier et de stocker la ligne afin de l'output
        {
            data.emplace_back(ligne);
        }
        fichier.close(); // ferme le fichier après que chaque ligne du fichier est était output
    }
    else
    {
        cerr << "Erreur d'ouverture du fichier : " << path << endl;
    }
}
