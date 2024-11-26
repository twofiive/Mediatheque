#include "Film.h"
#include <iostream>
#include <sstream>
#include <algorithm>

const string Film::path = CHEMIN_FILM;

// Constructeurs
Film::Film() {}
Film::Film(const string &titre, int ID, const string &producteur, const string &realisateur)
    : Mediatheque(titre, ID), producteur(producteur), realisateur(realisateur) {}
Film::~Film() {
    data.clear();
}

// Menu spécifique à la gestion des films
void Film::menufilm()
{
    int choixfilm;
    do
    {
        cout << "============ MENU FILM ============" << endl;
        cout << AJOUTER << " - Ajouter une notice" << endl;
        cout << SUPPRIMER << " - Supprimer une notice" << endl;
        cout << RECHERCHER << " - Rechercher une notice" << endl;
        cout << AFFICHER << " - Afficher toutes les notices" << endl;
        cout << MODIFIER << " - Modifier une notice" << endl;
        cout << RETOUR << " - Retour au menu principal" << endl;
        cout << "Votre choix : ";
        cin >> choixfilm;

        switch (choixfilm)
        {
        case AJOUTER:
        {
            string titre, producteur, realisateur;
            int id;

            cout << "Saisir le titre : ";
            cin >> titre;
            cout << "Saisir le producteur : ";
            cin >> producteur;
            cout << "Saisir le réalisateur : ";
            cin >> realisateur;

            do
            {
                cout << "Saisir l'identifiant (4 chiffres) : ";
                cin >> id;
            } while (id < 1000 || id >= 10000);

            string notice = titre + ";" + to_string(id) + ";" + producteur + ";" + realisateur;
            ajouter(notice); // Appelle la méthode de la classe mère
            break;
        }

        case SUPPRIMER:
        {
            cout << "Saisir l'identifiant de la notice à supprimer : ";
            int id;
            cin >> id;

            auto it = remove_if(data.begin(), data.end(), [&](const string &ligne)
                                { return ligne.find(to_string(id)) != string::npos; });

            if (it != data.end())
            {
                data.erase(it, data.end());
                cout << "Notice supprimée avec succès !" << endl;
            }
            else
            {
                cout << "Notice introuvable !" << endl;
            }
            break;
        }

        case RECHERCHER:
        {
            cout << "Saisir l'identifiant de la notice à rechercher : ";
            int id;
            cin >> id;

            bool trouve = false;
            for (const auto &ligne : data)
            {
                if (ligne.find(to_string(id)) != string::npos)
                {
                    cout << "Notice trouvée : " << ligne << endl;
                    trouve = true;
                    break;
                }
            }

            if (!trouve)
            {
                cout << "Notice introuvable !" << endl;
            }
            break;
        }

        case AFFICHER:
            afficher(); // Appelle la méthode de la classe mère
            break;

        case MODIFIER:
        {
            cout << "Saisir l'identifiant de la notice à modifier : ";
            int id;
            cin >> id;

            cout << "============ MODIFIER CHAMP ===========" << endl;
            cout << TITRE_FILM << " - Modifier le titre" << endl;
            cout << PRODUCTEUR_FILM << " - Modifier le producteur" << endl;
            cout << REALISATEUR_FILM << " - Modifier le réalisateur" << endl;
            cout << "Votre choix : ";
            int choix;
            cin >> choix;

            modifierChamp(id, choix); // Utilise la méthode de la classe mère
            break;
        }

        case RETOUR:
            cout << "Retour au menu principal." << endl;
            data.clear();
            break;

        default:
            cerr << "Choix invalide !" << endl;
            break;
        }
    } while (choixfilm != RETOUR);
}
