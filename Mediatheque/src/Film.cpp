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

/** Menu spécifique à la gestion des films */
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
        cout << ENREGISTRER << " - Sauvegarder les notices" << endl;
        cout << RETOUR << " - Retour au menu principal" << endl;
        cout << "Votre choix : ";
        cin >> choixfilm;

        switch (choixfilm)
        {
        /** Ajout de notice  */
        case AJOUTER:
        {
            // Les attributs de la classe Film
            string titre;
            string producteur;
            string realisateur;
            int id;

            /** Blindage des entrées */
            do
            {
                cout << "Saisir le titre : ";
                cin.ignore(); // Pour supprimer les entrées précedentes
                getline(cin, titre); // Prends en compte l'espace dans une phrase
            }
            while ( titre.empty() );
            do
            {
                cout << "Saisir le producteur : ";
                cin.ignore();
                getline(cin, producteur);
            }
            while ( producteur.empty() );
            do
            {
                cout << "Saisir le realisateur: ";
                cin.ignore();
                getline(cin, realisateur);
            }
            while ( realisateur.empty() );

            do
            {
                cout << "Saisir l'identifiant (4 chiffres) : ";
                cin >> id;
            }
            while (id < BORNE_BASSE || id >= BORNE_HAUTE );

            string notice = titre + ";" + to_string(id) + ";" + producteur + ";" + realisateur; // Formattage de la notice
            ajouter(notice); // Appelle la méthode de la classe mère
            break;
        }

        /** Suppression de notice */
        case SUPPRIMER:
        {
            int id;
            string titre;
            Film film;
            film.afficher(path); // Affichage pour permettre à l'utilisateur d'identifier la notice à supprimer
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
            while ( id < BORNE_BASSE || id >= BORNE_HAUTE );
            string idstr = to_string(id); // Pour changer le type int en string
            vector <string> element = {titre, idstr}; // Les éléments sont placés dans un vecteur
            film.supprimer(element, path); /// Appelle de la methode supprimer de la class parent Mediatheque
            choixcd = 7;
            break;
        }

        /** Recherche une notice */
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
            while (id < BORNE_BASSE || id >= BORNE_HAUTE );
            string idstr = to_string(id);            // Pour changer le type int en string
            vector<string> element = {titre, idstr}; // Les éléments sont placés dans un vecteur
            film.rechercher(element, path);
            break;
        }

        /** Affichage de notice */
        case AFFICHER:
            afficher(path); // Appelle la méthode de la classe mère
            break;

        /** Modification de notice */
        case MODIFIER:
        {
            int id;


            do
            {
                cout << "Saisir l'identifiant de la notice a modifier : ";
                cin >> id;
            }
            while (id < BORNE_BASSE || id >= BORNE_HAUTE );


            cout << "============ MODIFIER CHAMP ===========" << endl;
            cout << TITRE << " - Modifier le titre" << endl;
            cout << ARG_A << " - Modifier le producteur" << endl;
            cout << ARG_B << " - Modifier le realisateur" << endl;
            cout << "Votre choix : ";
            int choix;
            cin >> choix;

            modifier(id, choix); // Utilise la méthode de la classe mère
            choixcd = 7;
            break;
        }

        /** Enregistrer les données */
        case ENREGISTRER:
            enregistrer(CHEMIN_FILM);
            break;

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
