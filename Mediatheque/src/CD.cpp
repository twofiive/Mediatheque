#include "CD.h"
#include <iostream>

CD::CD() {};
/// Surchage du constructeur
CD::CD(const string &titre, int ID, const string &interprete, const string &label)
    : Mediatheque(titre, ID), interprete(interprete), label(label) {}
CD::~CD(vector <string> &data)
{
    data.clear();
}

void CD::menucd()
{
    int choixcd;
    do
    {
        cout << "============ MENU CD ============" << endl;
        cout << AJOUTER << " - Ajout d'une notice " << endl;
        cout << SUPPRIMER << " - Supprimer des notices " << endl;
        cout << RECHERCHER << " - Rechercher des notices " << endl;
        cout << AFFICHER << " - Afficher une notice " << endl;
        cout << MODIFIER << " - Modifier une notice" << endl;
        cout << RETOUR << " - Retour menu principal" << endl;
        cout << "Saisie : " << endl;
        cin >> choixcd;

        switch (choixcd)
        {
        case AJOUTER:
        {

            vector<string> data;
            int id;

            cout << "============ AJOUT NOTICE ============" << endl;
            cout << "Saisir le titre : ";
            cin >> titre;
            cout << "Saisir l'interprete : ";
            cin >> interprete;
            cout << "Saisir le label : ";
            cin >> label;
            do
            {
                cout << "Saisir l'identifiant (4 nombre) : ";
                cin >> id;
            } while (id < 1000 || id >= 10000);


            CD noticecd(titre, id, interprete, label);
            notice = titre + ";" + to_string(id) + ";" + interprete + ";" + label;
            data.emplace_back(notice);
            noticecd.Mediatheque::ajouter(data);
            break;
        }
        case SUPPRIMER:
        {

            const string path = CHEMIN_CD;
            string basepath = "cd/";
            CD affichecd;
            affichecd.Mediatheque::afficher(path);
            cout << "============ SUPPRESSION CD ============" << endl;
            do
            {
                cout << "Saisir l'identifiant de la notice à supprimer (4 nombre) : " << endl;
                cin >> id;
            } while (id < 1000 || id > 10000);
            CD noticesupp;
            noticesupp.Mediatheque::supprimer(path, basepath, id);
            break;
        }
        case RECHERCHER:
        {
            string titre;
            int id;
            string path;
            path = CHEMIN_CD;
            CD recherchecd;
            cout << "============ RECHERCHE CD ============" << endl;
            cout << "Saisir le titre rechercher :" << endl;
            cin >> titre;
            do
            {
                cout << "Saisir l'ID rechercher : ";
                cin >> id;
            } while (id < 1000 || id > 10000);
            recherchecd.Mediatheque::rechercher(path, data);
            break;
        }
        case AFFICHER:
        {
            const string path = CHEMIN_CD;
            CD affichecd;
            affichecd.Mediatheque::afficher(path);
            break;
        }
        case MODIFIER:
        {
            const string path = CHEMIN_CD;
            string basepath = "./";
            string to_update;
            string upwd;
            int choix_update;
            CD updatecd;

            cout << "============ MODIFIER NOTICE ============" << endl;
            cout << endl;
            cout << TITRE_CD << " - Titre" << endl;
            cout << AUTEUR_CD << " - Auteur" << endl;
            cout << LABEL_CD << " - Label" << endl;
            cout << IDENTIFIANT_CD << " - ID" << endl;
            cout << RETOUR_MODIF_CD << " - Retour menu gestion CD " << endl;
            cout << "Saisir l'attribut a modifier : " << endl;
            cin >> choix_update;
            cout << endl;

            if (choix_update != RETOUR_MODIF_CD)
            {
                cout << "Liste des CDs : " << endl;
                updatecd.Mediatheque::afficher(path);
                cout << endl;
            }

            switch (choix_update)
            {
            case TITRE_CD:
            {
                cout << "Saisir le titre a modifier : " << endl;
                cin >> to_update;
                cout << endl;
                cout << "Saisir le nouveau titre : " << endl;
                cin >> upwd;

                updatecd.Mediatheque::modifier(path, data);
                break;
            }
            case AUTEUR_CD:
            {
                cout << "Saisir l'auteur a modifier : " << endl;
                cin >> to_update;
                cout << endl;
                cout << "Saisir le nouvel auteur : " << endl;
                cin >> upwd;

                updatecd.Mediatheque::modifier(path, data);
                break;
            }
            case LABEL_CD:
            {
                cout << "Saisir le label a modifier : " << endl;
                cin >> to_update;
                cout << endl;
                cout << "Saisir le label : " << endl;
                cin >> upwd;

                updatecd.Mediatheque::modifier(path, data);
                break;
            }
            case IDENTIFIANT_CD:
            {
                int to_update_id;
                int update_id;

                cout << endl;
                do
                {
                    cout << "Saisir l'ID a modifier : " << endl;
                    cin >> to_update_id;
                } while (to_update_id < 1000 || to_update_id > 10000);
                cout << endl;
                do
                {
                    cout << "Saisir le nouvel ID : " << endl;
                    cin >> update_id;
                } while (update_id < 1000 || update_id > 10000);

                to_update = to_string(to_update_id);
                upwd = to_string(update_id);

                updatecd.Mediatheque::modifier(path, data);
                break;
            }
            case RETOUR_MODIF_CD:
            {
                break;
            }
            default:
                cerr << "Option invalide." << endl;
                break;
            }
        }
        case RETOUR:
        {
            ~CD cd;
            break;
        }
        default:
            cerr << "Option invalide." << endl;
            break;
        }
    } while (choixcd != RETOUR);
}
