/// Ici on appelle les différentes classes crées
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
            /// Création d'une classe et appel du menu
            CD cd;
            cd.menucd();
            break;
        }
        case GESTION_LIVRE:
        {
            /// Création d'une classe et appel du menu
            Livre livreA;
            livreA.menulivre();
            break;
        }

        case GESTION_FILM:
        {
            /// Création d'une classe et appel du menu
            Film film;
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
