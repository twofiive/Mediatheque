#include "Mediatheque.h" // Classe parent : Mediatheque
#include "CD.h"          // Classe fille : CD
#include "Film.h"        // Classe fille : Film
#include "Livre.h"       // Classe fille : Livre
#include <iostream>
#include <string>

using namespace std;

int main() {
    int choix;

    do {
        /// Menu principal
        cout << "============ MENU MEDIATHEQUE ============" << endl;
        cout << GESTION_CD << " - Gestion des notices CD " << endl;
        cout << GESTION_LIVRE << " - Gestion des notices Livre" << endl;
        cout << GESTION_FILM << " - Gestion des notices Film" << endl;
        cout << QUITTER << " - Quitter " << endl;
        cout << "Saisie : ";
        cin >> choix;

        switch (choix) {
        case GESTION_CD: {
            /// Gestion des CDs
            CD cd;
            cd.chargementdata(CHEMINCD); // Chargement des données
            cd.menucd();                 // Menu de gestion des CDs
            break;
        }
        case GESTION_LIVRE: {
            /// Gestion des livres
            Livre livre;
            livre.chargementdata(CHEMIN_LIVRE); // Chargement des données
            livre.menulivre();                // Menu de gestion des livres
            break;
        }
        case GESTION_FILM: {
            /// Gestion des films
            Film film;
            film.chargementdata(CHEMIN_FILM); // Chargement des données
            film.menufilm();                // Menu de gestion des films
            break;
        }
        case QUITTER:
            cout << " A bientot !" << endl;
            exit(0);
        default:
            cerr << "Saisie incorrecte !" << endl;
            break;
        }
    } while (choix != QUITTER);

    return 0;
}
