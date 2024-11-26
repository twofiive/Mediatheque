#include "Film.h"
#include <iostream>
#include <sstream>
#include <algorithm>

const string path = CHEMIN_FILM;

// Constructeurs
Film::Film() {}
Film::Film(const string &titre, int ID, const string &producteur, const string &realisateur)
    : Mediatheque(titre, ID), producteur(producteur), realisateur(realisateur) {}
Film::~Film()
{
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
            string titre;
            string producteur;
            string realisateur;
            int id;

            cout << "Saisir le titre : ";
            cin >> titre;
            cout << "Saisir le producteur : ";
            cin >> producteur;
            cout << "Saisir le realisateur : ";
            cin >> realisateur;

            do
            {
                cout << "Saisir l'identifiant (4 chiffres) : ";
                cin >> id;
            }
            while (id < 1000 || id >= 10000);

            string notice = titre + ";" + to_string(id) + ";" + producteur + ";" + realisateur;
            ajouter(notice); // Appelle la méthode de la classe mère
            break;
        }

        case SUPPRIMER:
        {
            int id;
            string titre;
            Film film;
            film.afficher(path);
            cout << "============ SUPPRESSION FILM ============" << endl;

            do
            {
                cout << "Saisir le titre rechercher : ";
                cin.ignore(); // Pour supprimer les entrées précedentes
                getline(cin, titre);
            }
            while ( titre.empty() );

            do
            {
                cout << "Saisir l'ID rechercher : ";
                cin >> id;
            }
            while ( id < 1000 || id >= 10000 );
            string idstr = to_string(id); // Pour changer le type int en string
            vector <string> element = {titre, idstr}; // Les éléments sont placés dans un vecteur
            film.supprimer(element, path); /// Appelle de la m�thode supprimer de la class parent Mediatheque
            break;
        }

        case RECHERCHER:
        {
            int id;
            Film film;
            cout << "============ RECHERCHE FILM ============" << endl;
            cout << "Saisir le titre rechercher : ";
            do
            {
                cin.ignore(); // Pour supprimer les entrées précedentes
                getline(cin, titre);
            }
            while ( titre.empty() );
            do
            {
                cout << "Saisir l'ID rechercher : ";
                cin >> id;
            }
            while (id < 1000 || id >= 10000);
            string idstr = to_string(id);            // Pour changer le type int en string
            vector<string> element = {titre, idstr}; // Les éléments sont placés dans un vecteur
            film.rechercher(element, path);
            break;
        }

        case AFFICHER:
            afficher(path); // Appelle la méthode de la classe mère
            break;

/**
        case MODIFIER:
        {
            int id;

            cout << "Saisir l'identifiant de la notice à modifier : ";
            cin >> id;

            cout << "============ MODIFIER CHAMP ===========" << endl;
            cout << TITRE_FILM << " - Modifier le titre" << endl;
            cout << PRODUCTEUR_FILM << " - Modifier le producteur" << endl;
            cout << REALISATEUR_FILM << " - Modifier le réalisateur" << endl;
            cout << "Votre choix : ";
            int choix;
            cin >> choix;

            modifier(id, choix); // Utilise la méthode de la classe mère
            break;
        }
*/
        case RETOUR:
            cout << "Retour au menu principal." << endl;
            data.clear();
            break;

        default:
            cerr << "Choix invalide !" << endl;
            break;
        }
    }
    while (choixfilm != RETOUR);
}
