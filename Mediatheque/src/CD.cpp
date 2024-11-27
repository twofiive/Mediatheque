#include "CD.h"
#include <iostream>
#include <algorithm> // Pour std::remove_if
#include <string>

const string path = CHEMINCD;

// Constructeur par défaut
CD::CD() {}

// Surcharge du constructeur
CD::CD(const string &titre, int ID, const string &interprete, const string &label)
    : Mediatheque(titre, ID), interprete(interprete), label(label) {}

// Destructeur
CD::~CD() {}

// Menu spécifique à la gestion des CDs
void CD::menucd()
{
    int choixcd;
    do
    {
        cout << "============ MENU CD ============" << endl;
        cout << AJOUTER << " - Ajout d'une notice" << endl;
        cout << SUPPRIMER << " - Supprimer une notice" << endl;
        cout << RECHERCHER << " - Rechercher une notice" << endl;
        cout << AFFICHER << " - Afficher toutes les notices" << endl;
        cout << MODIFIER << " - Modifier une notice" << endl;
        cout << ENREGISTRER << " - Sauvegarder les notices" << endl;
        cout << RETOUR << " - Retour au menu principal" << endl;
        cout << "Votre choix : ";
        cin >> choixcd;

        switch (choixcd)
        {
        case AJOUTER:
        {
            string titre;
            string interprete;
            string label;
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
                cout << "Saisir l'interprete: ";
                cin.ignore();
                getline(cin, interprete);
            }
            while ( interprete.empty() );
            do
            {
                cout << "Saisir le label: ";
                cin.ignore();
                getline(cin, label);
            }
            while ( label.empty() );

            do
            {
                cout << "Saisir l'identifiant (4 chiffres) : ";
                cin >> id;
            }
            while (id < 1000 || id >= 10000);

            cout << "N'oubliez pas de sauvegarder votre notice ;)" << endl;

            string notice = titre + ";" + to_string(id) + ";" + interprete + ";" + label;
            ajouter(notice);
            break;
        }
        case SUPPRIMER:
        {
            int id;
            string titre;
            CD affichecd;
            affichecd.afficher(path);
            cout << "============ SUPPRESSION CD ============" << endl;

            do
            {
                cout << "Saisir le titre rechercher : ";
                cin.ignore(); // Pour supprimer les entrées précedentes
                getline(cin, titre);
            }
            while ( titre.empty() );

            do
            {
                cout << "Saisir l'ID rechercher ( 4 chiffres ): ";
                cin >> id;
            }
            while ( id < 1000 || id >= 10000 );
            string idstr = to_string(id); // Pour changer le type int en string
            vector <string> element = {titre, idstr}; // Les éléments sont placés dans un vecteur
            affichecd.supprimer(element, path); /// Appelle de la m�thode supprimer de la class parent Mediatheque
            break;
        }
        case RECHERCHER:
        {
            int id;
            CD cd;
            cout << "============ RECHERCHE CD ============" << endl;
            cout << "Saisir le titre rechercher : ";
            do
            {
                cin.ignore(); // Pour supprimer les entrées précedentes
                getline(cin, titre);
            }
            while ( titre.empty() );
            do
            {
                cout << "Saisir l'ID rechercher ( 4 chiffres  ) : ";
                cin >> id;
            }
            while (id < 1000 || id >= 10000);
            string idstr = to_string(id);            // Pour changer le type int en string
            vector<string> element = {titre, idstr}; // Les éléments sont placés dans un vecteur
            cd.rechercher(element, path);
            break;
        }
        case AFFICHER:
            afficher(path);
            break;

        case MODIFIER:
        {
            int id;

            cout << "Saisir l'identifiant de la notice a modifier : ";
            cin >> id;

            cout << "============ MODIFIER CHAMP ===========" << endl;
            cout << TITRE << " - Modifier le titre" << endl;
            cout << ARG_A << " - Modifier l'interprète" << endl;
            cout << ARG_B << " - Modifier le label" << endl;
            cout << "Votre choix : ";
            int choix;
            cin >> choix;

            modifier(id, choix);
            break;
        }

        case ENREGISTRER:
            enregistrer(CHEMINCD);
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
    while (choixcd != RETOUR);
}
