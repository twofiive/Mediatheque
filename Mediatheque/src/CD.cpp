#include "CD.h"
#include <iostream>
#include <algorithm> // Pour std::remove_if
#include <string>
using namespace std;

// Constructeur par défaut
CD::CD() {}

// Surcharge du constructeur
CD::CD(const string &titre, int ID, const string &interprete, const string &label)
    : Mediatheque(titre, ID), interprete(interprete), label(label) {}

// Destructeur
CD::~CD() {}

// Menu spécifique à la gestion des CDs
void CD::menucd() {
    int choixcd;
    do {
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

        switch (choixcd) {
        case AJOUTER: {
            string titre, interprete, label;
            int id;

            cout << "Saisir le titre : ";
            cin.ignore();
            getline(cin, titre);
            cout << "Saisir l'interprète : ";
            getline(cin, interprete);
            cout << "Saisir le label : ";
            getline(cin, label);

            do {
                cout << "Saisir l'identifiant (4 chiffres) : ";
                cin >> id;
            } while (id < 1000 || id >= 10000);

            string notice = titre + ";" + to_string(id) + ";" + interprete + ";" + label;
            ajouter(notice);
            break;
        }
<<<<<<< HEAD
        case SUPPRIMER: {
            cout << "Saisir l'identifiant de la notice à supprimer : ";
            int id;
            cin >> id;

            auto it = remove_if(data.begin(), data.end(), [&](const string &ligne) {
                return ligne.find(to_string(id)) != string::npos;
            });

            if (it != data.end()) {
                data.erase(it, data.end());
                cout << "Notice supprimée avec succès !" << endl;
            } else {
                cout << "Notice introuvable !" << endl;
            }
=======
        case SUPPRIMER:
        {
            int id;
            string titre;
            const string path = CHEMIN_CD;
            CD affichecd;
            affichecd.Mediatheque::afficher(path);
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
                cout << "Saisir l'ID rechercher : ";
                cin >> id;
            }
            while ( id < 1000 || id >= 10000 );
            string idstr = to_string(id); // Pour changer le type int en string
            vector <string> element = {titre, idstr}; // Les éléments sont placés dans un vecteur
            affichecd.supprimer(element, path); /// Appelle de la m�thode supprimer de la class parent Mediatheque
>>>>>>> 992ce3743511e3832702b9e3f71114dd0796d910
            break;
        }
        case RECHERCHER: {
            cout << "Saisir l'identifiant de la notice à rechercher : ";
            int id;
<<<<<<< HEAD
            cin >> id;

            bool trouve = false;
            for (const auto &ligne : data) {
                if (ligne.find(to_string(id)) != string::npos) {
                    cout << "Notice trouvée : " << ligne << endl;
                    trouve = true;
                    break;
                }
            }

            if (!trouve) {
                cout << "Notice introuvable !" << endl;
            }
=======
            string path;
            path = CHEMIN_CD;
            CD cd;
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
            } while (id < 1000 || id >= 10000);
            string idstr = to_string(id);            // Pour changer le type int en string
            vector<string> element = {titre, idstr}; // Les éléments sont placés dans un vecteur
            cd.rechercher(element, path);
>>>>>>> 992ce3743511e3832702b9e3f71114dd0796d910
            break;
        }
        case AFFICHER:
            afficher();
            break;

        case MODIFIER: {
            cout << "Saisir l'identifiant de la notice à modifier : ";
            int id;
            cin >> id;

            cout << "============ MODIFIER CHAMP ===========" << endl;
            cout << TITRE_CD << " - Modifier le titre" << endl;
            cout << AUTEUR_CD << " - Modifier l'interprète" << endl;
            cout << LABEL_CD << " - Modifier le label" << endl;
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
    } while (choixcd != RETOUR);
}
