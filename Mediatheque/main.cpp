#include <Mediatheque.h>
#include <CD.h>
#include <film.h>
#include <livre.h>

int main()
{
    int choix;

    do
    {

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
            CD cd;
            cd.menucd();
            break;
        }
        case GESTION_LIVRE:
        {
            Livre livreA;
            livreA.menulivre();
            break;
        }

        case GESTION_FILM:
        {
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
    } while (choix == GESTION_CD || choix == GESTION_LIVRE || choix == GESTION_FILM || choix == QUITTER);
}
