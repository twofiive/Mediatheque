#include "Mediatheque.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

// Constructeur par défaut de la classe mère
Mediatheque::Mediatheque() {}

// Constructeur avec paramètres pour les attributs communs
Mediatheque::Mediatheque(const string &titre, int ID) : titre(titre), id(ID) {}

// Destructeur
Mediatheque::~Mediatheque() {}

// Afficher les données dans le vecteur
void Mediatheque::afficher()
{
    for (const auto &ligne : data)
    {
        cout << ligne << endl;
    }
}

// Chargement des données depuis un fichier
void Mediatheque::chargementdata(const string &path)
{
    ifstream fichier(path);
    string ligne;

    if (fichier.is_open())
    {
        data.clear();
        while (getline(fichier, ligne))
        {
            data.emplace_back(ligne);
        }
        fichier.close();
        cout << "Données chargées avec succès depuis : " << path << endl;
    }
    else
    {
<<<<<<< HEAD
        cerr << "Erreur d'ouverture du fichier : " << path << endl;
    }
}

// Enregistrer les données dans un fichier
void Mediatheque::enregistrer(const string &path)
{
    ofstream fichier(path, ios::trunc);

    if (fichier.is_open())
    {
        for (const auto &ligne : data)
        {
            fichier << ligne << endl;
        }
        fichier.close();
        cout << "Données enregistrées avec succès dans : " << path << endl;
=======
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
>>>>>>> 992ce3743511e3832702b9e3f71114dd0796d910
    }

    if ( index == -1 )
    {
<<<<<<< HEAD
        cerr << "Impossible d'enregistrer dans le fichier : " << path << endl;
=======
        cerr << "Aucun element supprime." << endl;
>>>>>>> 992ce3743511e3832702b9e3f71114dd0796d910
    }
}

// Ajouter une nouvelle notice
void Mediatheque::ajouter(const string &notice)
{
    data.emplace_back(notice);
    cout << "Notice ajoutée : " << notice << endl;
}

// Modifier un champ spécifique dans une notice
void Mediatheque::modifier(int &id, int &choix)
{
    bool trouve = false;

    for (auto &ligne : data)
    {
        if (ligne.find(to_string(id)) != string::npos)
        {
            trouve = true;

            vector<string> champs;
            stringstream ss(ligne);
            string champ;
            while (getline(ss, champ, ';'))
            {
                champs.emplace_back(champ);
            }

            if (champs.size() != 4)
            {
                cerr << "Erreur : Format incorrect pour la ligne : " << ligne << endl;
                return;
            }

            switch (choix)
            {
            case TITRE_CD:
            {
                cout << "Titre actuel : " << champs[0] << endl;
                cout << "Nouveau titre : ";
                string nouveauTitre;
                cin.ignore();
                getline(cin, nouveauTitre);
                if (!nouveauTitre.empty())
                    champs[0] = nouveauTitre;
                break;
            }
            case AUTEUR_CD:
            {
                cout << "Interprète actuel : " << champs[2] << endl;
                cout << "Nouvel interprète : ";
                string nouvelInterprete;
                cin.ignore();
                getline(cin, nouvelInterprete);
                if (!nouvelInterprete.empty())
                    champs[2] = nouvelInterprete;
                break;
            }
            case LABEL_CD:
            {
                cout << "Label actuel : " << champs[3] << endl;
                cout << "Nouveau label : ";
                string nouveauLabel;
                cin.ignore();
                getline(cin, nouveauLabel);
                if (!nouveauLabel.empty())
                    champs[3] = nouveauLabel;
                break;
            }
            default:
                cerr << "Choix invalide !" << endl;
                return;
            }

            ligne = champs[0] + ";" + champs[1] + ";" + champs[2] + ";" + champs[3];
            cout << "Notice modifiée avec succès : " << ligne << endl;
            break;
        }
    }

    if (!trouve)
    {
        cout << "Aucune notice trouvée avec l'ID : " << id << endl;
    }
}
