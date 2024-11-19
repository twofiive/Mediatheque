#include <Mediatheque.h>
#include <CD.h>

int main()
{
    int choix;

    do
    {

        cout << "============ MENU MEDIATHEQUE ============" << endl;
        cout << "1- Gestion des notice CD " << endl;
        cout << "2- Gestion des notice Livre" << endl;
        cout << "3- Gestion des notice Video" << endl;
        cout << "4- Quitter " << endl;
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
            /* code */
            break;
        }

        case GESTION_VIDEO:
        {
            /* code */
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
    } while (choix == GESTION_CD || choix == GESTION_LIVRE || choix == GESTION_VIDEO || choix == QUITTER);
}