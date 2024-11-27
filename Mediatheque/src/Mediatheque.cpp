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

/** Afficher les données dans le vecteur */
void Mediatheque::afficher(const string &path)
{
    if (data.empty())  // Vérifie si les données ont déjà été chargées
    {
        Mediatheque::chargementdata(path); // Si le vecteur est vide, appelle la méthode pour charger les données
    }
    for (const auto &ligne : data)
    {
        cout << ligne << endl;
    }
}

/** Chargement des données depuis un fichier */
void Mediatheque::chargementdata(const string &path)
{
    ifstream fichier(path);
    string ligne;

    if (fichier.is_open()) // Ouverture du fichier
    {
        while (getline(fichier, ligne)) // Parcours le fichier ligne par ligne
        {
            data.emplace_back(ligne); // Introduis chaque ligne dans le vecteur
        }
        fichier.close(); // Fermeture du fichier
        cout << "Donnees chargees avec succes depuis : " << path << endl;
    }
    else
    {
        cerr << "Erreur d'ouverture du fichier : " << path << endl;
    }
}

/** Enregistrer les données dans un fichier */
void Mediatheque::enregistrer(const string &path)
{
    ofstream fichier(path, ios::trunc); // TODO

    if (fichier.is_open())
    {
        for (const auto &ligne : data)
        {
            fichier << ligne << endl;
        }
        fichier.close();
        cout << "Donnees enregistrees avec succes dans : " << path << endl;
    }
    else
    {
        cerr << "Impossible d'enregistrer dans le fichier : " << path << endl;
    }
}

/** Rechercher les données dans le fichier  */
void Mediatheque::rechercher(vector<string> &loadedData, const string &path) // Les argument passés font références aux attibuts(Titre, ID)
{
    if (data.empty())
    {
        cout << "Les donnees ne sont pas chargees, rechargement en cours..." << endl;
        chargementdata(path);
    }


    bool wfind = false; // Permet de definir si le mot à été trouvé par défaut sur false

    for (const auto &line : data)
    {
        /** Permet de comparer le titre et id passé en argument afin de comparer et
            de rechercher le titre et l'id dans le fichier
            npos est un indicateur de non-correspondance */
        if (line.find(loadedData[0]) != string::npos && line.find(loadedData[1]) != string::npos)
        {
            cout << "Resultat de la recherche : " << endl;
            cout << line << endl;
            wfind = true; // En cas de correspondance wfind passe à true
        }
    }

    if (!wfind)
    {
        cerr << "La notice recherchee n'existe pas dans le fichier : " << path << endl;
    }
}

/** Supprimer des données dans le fichier */
void Mediatheque::supprimer(vector<string> &loadedData, const string &path)
{
    int index = -1;
    int i;
    char choix;

    if (data.empty())
    {
        cout << "Les donnees ne sont pas chargees, rechargement en cours..." << endl;
        chargementdata(path);
    }


    for (i = 0; i < data.size(); ++i)
    {
        /** Les itérateurs sont utilisés ici pour connaitre l'index de la valeur correspondante et par la suite l'a supprimé */
        if (data[i].find(loadedData[0]) != string::npos && data[i].find(loadedData[1]) != string::npos)
        {
            cout << "Resultat de la recherche : " << endl;
            cout << data[i] << endl;
            data.erase(data.begin() + i ); // Removes the element at index 1 (value 2)
            cout << "Element supprime avec succes." << endl;
            index = i;

            /** Donne la possibilité à l'utilisateur de sauvegarder
            directement la modification éffectués dans le fichier  */
            cout << "Voulez-vous sauvegarder avant de quitter ? (o/n) : ";
            cin >> choix;
            if (choix == 'o' || choix == 'O')
            {
                Mediatheque::enregistrer(path);
            }
            break;
        }
    }


    if ( index == -1 )
    {
        cerr << "Aucun element supprime." << endl;
    }
}

/** Ajouter une nouvelle notice  */
void Mediatheque::ajouter(const string &notice)
{
    data.emplace_back(notice); // Ajout de la notice dans le vecteur
    cout << "Notice ajoutee : " << notice << endl;
    cout << "N'oubliez pas de sauvegarder ;)" << endl;
}



/** Modifier un champ spécifique dans une notice */
// TODO
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
            case TITRE:
            {
                cout << " Valeur actuelle : " << champs[0] << endl;
                cout << " Nouveau valeur : ";
                string nouveauTitre;
                cin.ignore();
                getline(cin, nouveauTitre);
                if (!nouveauTitre.empty())
                    champs[0] = nouveauTitre;
                break;
            }
            case ARG_A:
            {
                cout << " Valeur actuelle : " << champs[2] << endl;
                cout << " Nouvelle valeur : ";
                string nouvelInterprete;
                cin.ignore();
                getline(cin, nouvelInterprete);
                if (!nouvelInterprete.empty())
                    champs[2] = nouvelInterprete;
                break;
            }
            case ARG_B:
            {
                cout << " Valeur actuelle : " << champs[3] << endl;
                cout << " Nouvelle valeur : ";
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
            cout << "Notice modifiee avec succes : " << ligne << endl;

            cout << "N'oubliez pas de sauvegarder ;)" << endl;
            break;
        }
    }

    if (!trouve)
    {
        cout << "Aucune notice trouvee avec l'ID : " << id << endl;
    }
}

