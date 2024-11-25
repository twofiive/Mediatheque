/// Ici on appelle les diff�rentes classes cr�es
#include "Mediatheque.h" /// La classe parent
/// Les classes fille
#include "CD.h"
#include "Film.h"
#include "Livre.h"



int main()
{
    int choix;

    do
    {
        /// Implementation du menu principal
        cout << "============ MENU MEDIATHEQUE ============" << endl;
        cout << GESTION_CD << " - Gestion des notice CD " << endl;
        cout << GESTION_LIVRE << " - Gestion des notice Livre" << endl;
        cout << GESTION_FILM << " - Gestion des notice Film" << endl;
        cout << QUITTER << " - Quitter " << endl;
        cout << "Saisie : ";
        cin >> choix;

        switch (choix)
        {
        case GESTION_CD:
        {
            /// Chargement des données de la collection cd 
            /// Appel du menu gestion cd
            CD cd;
            string path = "cd.txt";
            vector<string> data;
            cd.chargementdata(path,data);
            cd.menucd();
            break;
        }
        case GESTION_LIVRE:
        {
            // Chargement des données de la collection livre 
            /// Appel du menu gestion livre
            Livre livre;
            string path = "livre.txt";
            livre.chargementdata(path,data);
            livre.menulivre();
            break;
        }

        case GESTION_FILM:
        {
            // Chargement des données de la collection film
            /// Appel du menu gestion film
            Film film;
            string path = "film.txt";
            livre.chargementdata(path,data);
            film.menufilm();
            break;
        }
        case QUITTER:
        {
            exit(0);
        }
        default:
        {
            cout << "Saisie incorrect ! " << endl;
        }
        break;
        }
    }
    while (choix == GESTION_CD || choix == GESTION_LIVRE || choix == GESTION_FILM || choix == QUITTER);
}
