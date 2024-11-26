#include "Mediatheque.h"
#include <string>
#include <iostream>
#include <fstream>

// Constructeur par défaut de la classe mère
Mediatheque::Mediatheque() {};
// Constructeur avec paramètre qui prend en charge les attributs communs au trois classe fille
Mediatheque::Mediatheque(const string &titre, int ID) : titre(titre), id(ID) {}
// Destructeur
Mediatheque::~Mediatheque() {}

void Mediatheque::afficher(const string &path, )
{

    for (int i = 0; i < data.size(); i++)
    {
        cout << data[i] << endl;
    }
}

// Chargement des notices dans le vecteur
void Mediatheque::chargementdata(const string &path, ) // Prend en argument le chemin définies dans les macros des classe fille.
{
    ifstream fichier(path); // ifstream permet de lire un fichier
    string ligne;           // ligne permet de stocker la ligne qui sera lu par getline
    if (fichier.is_open())  // Vérifie si le fichier et bien ouvert
    {
        data.clear();                   // Assure que le vecteur est vide avant de charger les données.
        while (getline(fichier, ligne)) // getline permet de lire chaque ligne du fichier et de stocker la ligne afin de l'output
        {
            data.emplace_back(ligne);
        }
        fichier.close(); // ferme le fichier après que chaque ligne du fichier est était output
    }
    else
    {
        cerr << "Erreur lors du chargement des données : " << path << endl;
    }
}

void Mediatheque::rechercher(vector<string> &loadedData, const string &path) // Les argument passés sont
{
    bool wfind = false; // Permet de definir si le mot à été trouvé par défaut sur false

    for (const auto &line : data)
    {
        if (line.find(loadedData[0]) != string::npos && line.find(loadedData[1]) != string::npos) // Permet de comparer le titre et id passé en
        {
            // argument afin de comparer et de rechercher le titre et l'id dans le fichier
            cout << "Resultat de la recherche : " << endl; // npos est un indicateur de non-correspondance
            cout << line << endl;
            wfind = true;
        }
    }

    if (!wfind)
    {
        cerr << "La notice recherchee n'existe pas dans le fichier : " << path << endl;
    }
}

void Mediatheque::supprimer(vector<string> &loadedData, const string &path)
{
    int index = -1;
    int i;

    for (i = 0; i < data.size(); ++i)
    {
        if (data[i].find(loadedData[0]) != string::npos && data[i].find(loadedData[1]) != string::npos)//Permet de comparer le titre et id passé en
        {
            //argument afin de comparer et de rechercher le titre et l'id dans le fichier
            cout << "Resultat de la recherche : " << endl;                       //npos est un indicateur de non-correspondance
            cout << data[i] << endl;
            cout << i << endl;
            data.erase(data.begin() + i ); // Removes the element at index 1 (value 2)
            cout << "Element supprime avec succes." << endl;
            index = i;
            break;
        }
    }

    if ( index == -1 )
    {
        cerr << "Aucun element supprime." << endl;
    }
}

void Mediatheque::ajouter(const string notice)
{
    data.emplace_back(notice);
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

void Mediatheque::chargementdata(const string &path) // Prend en argument le chemin définies dans les macros des classe fille.
{
    ifstream fichier(path); // ifstream permet de lire un fichier
    string ligne;           // ligne permet de stocker la ligne qui sera lu par getline
    if (fichier.is_open())  // Vérifie si le fichier et bien ouvert
    {
        data.clear();
        while (getline(fichier, ligne)) // getline permet de lire chaque ligne du fichier et de stocker la ligne afin de l'output
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

void Mediatheque::enregistrer(const string &path)
{
    string line;
    ofstream fichier(path, ios::trunc);

    if (fichier.is_open())
    {
        for (int i = 0; i < data.size(); i++)
        {
            fichier << data[i];
        }
        fichier.close();
        cout << "Données enregistrées avec succès dans : " << path << endl;
        chargementdata(path);
    }
    else
    {
        cerr << "Impossible d'enregistrer !" << endl;
    }
}