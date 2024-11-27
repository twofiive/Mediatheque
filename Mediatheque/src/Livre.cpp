#include "Livre.h"
#include <iostream>
#include <sstream>
#include <algorithm>

const string path = CHEMIN_LIVRE;

// Constructeurs
Livre::Livre() {}
Livre::Livre(const string &titre, int ID, const string &auteur, const string &editeur)
    : Mediatheque(titre, ID), auteur(auteur), editeur(editeur) {}
Livre::~Livre() {
    data.clear();
}

// Menu spécifique à la gestion des livres
void Livre::menulivre()
{
    int choixlivre;
    do
    {
        cout << "============ MENU LIVRE ============" << endl;
        cout << AJOUTER << " - Ajouter une notice" << endl;
        cout << SUPPRIMER << " - Supprimer une notice" << endl;
        cout << RECHERCHER << " - Rechercher une notice" << endl;
        cout << AFFICHER << " - Afficher toutes les notices" << endl;
        cout << MODIFIER << " - Modifier une notice" << endl;
        cout << ENREGISTRER << " - Sauvegarder les notices" << endl;
        cout << RETOUR << " - Retour au menu principal" << endl;
        cout << "Votre choix : ";
        cin >> choixlivre;

        switch (choixlivre)
        {
        case AJOUTER:
        {
            string titre;
            string auteur;
            string editeur;
            int id;

            do
            {
                cout << "Saisir le titre : ";
                cin.ignore(); // Pour supprimer les entrées précedentes
                getline(cin, titre);
            }
            while ( titre.empty() );
            do
            {
                cout << "Saisir le auteur : ";
                cin.ignore();
                getline(cin, auteur);
            }
            while ( auteur.empty() );
            do
            {
                cout << "Saisir l'editeur : ";
                cin.ignore();
                getline(cin, editeur);
            }
            while ( editeur.empty() );
            do
            {
                cout << "Saisir l'identifiant (4 chiffres) : ";
                cin >> id;
            } while (id < 1000 || id >= 10000);

            string notice = titre + ";" + to_string(id) + ";" + auteur + ";" + editeur;
            ajouter(notice); // Appelle la méthode de la classe mère
            break;
        }

        case SUPPRIMER:
        {
            int id;
            string titre;
            Livre livre;
            livre.afficher(path);
            cout << "============ SUPPRESSION LIVRE ============" << endl;

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
            livre.supprimer(element, path); /// Appelle de la m�thode supprimer de la class parent Mediatheque
            break;
        }

        case RECHERCHER:
        {
            int id;

            Livre livre;
            cout << "============ RECHERCHE LIVRE ============" << endl;
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
            livre.rechercher(element, path);
            break;
        }

        case AFFICHER:
            afficher(path); // Appelle la méthode de la classe mère
            break;

        case MODIFIER:
        {
            int id;

            cout << "Saisir l'identifiant de la notice a modifier : ";
            cin >> id;

            cout << "============ MODIFIER CHAMP ===========" << endl;
            cout << TITRE << " - Modifier le titre" << endl;
            cout << ARG_A << " - Modifier l'auteur" << endl;
            cout << ARG_B << " - Modifier l'editeur" << endl;
            cout << "Votre choix : ";
            int choix;
            cin >> choix;

            modifier(id, choix); // Utilise la méthode de la classe mère
            break;
        }


        case ENREGISTRER:
            enregistrer(CHEMIN_LIVRE);
            break;

        case RETOUR:
            cout << "Retour au menu principal." << endl;
            break;

        default:
            cerr << "Choix invalide !" << endl;
            break;
        }
    } while (choixlivre != RETOUR);
}
