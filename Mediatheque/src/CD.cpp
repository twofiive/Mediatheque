#include "CD.h"
#include <iostream>

CD::CD() {};
CD::CD(const string &titre, int ID, const string &interprete, const string &label)
    : Mediatheque(titre, ID), interprete(interprete), label(label) {}
CD::~CD() {}

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
            string titre, interprete, label, data, input;
            int id;

            cout << "============ AJOUT NOTICE ============" << endl;
            cout << "Saisir le titre : ";
            cin >> titre;
            cout << "Saisir l'interprete : ";
            cin >> interprete;
            cout << "Saisir le label : ";
            cin >> label;
            cout << "Saisir l'identifiant (4 nombre) : ";
            cin >> id;

            const string path = CHEMIN_CD;

            CD noticecd(titre, id, interprete, label);
            data = titre + "," + to_string(id) + "," + interprete + "," + label;
            noticecd.Mediatheque::ajouter(path, data);
            break;
        }
        case SUPPRIMER:
        {

            const string path = CHEMIN_CD;
            string basepath = "/home/hcosse/gestion_notice/cd/";
            CD affichecd;
            affichecd.Mediatheque::afficher(path);
            cout << "============ SUPPRESSION CD ============" << endl;
            cout << "Saisir l'identifiant de la notice à supprimer (4 nombre) : " << endl;
            cin >> id;
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
            cout << "Saisir l'ID rechercher : " << endl;
            cin >> id;
            recherchecd.Mediatheque::rechercher(path, titre, id);
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
            string basepath = "/home/hcosse/gestion_notice/cd/";
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
            cout << "Saisir l'attribut à modifier : " << endl;
            cin >> choix_update;
            cout << endl;

            switch (choix_update)
            {
            case TITRE_CD:
            {
                cout << endl;
                cout << "Saisir le titre à modifier : " << endl;
                cin >> to_update;
                cout << endl;
                cout << "Saisir le nouveau titre : " << endl;
                cin >> upwd;

                updatecd.Mediatheque::modifier(path, basepath, to_update, upwd);
                break;
            }
            case AUTEUR_CD:
            {
                cout << endl;
                cout << "Saisir l'auteur à modifier : " << endl;
                cin >> to_update;
                cout << endl;
                cout << "Saisir le nouvel auteur : " << endl;
                cin >> upwd;

                updatecd.Mediatheque::modifier(path, basepath, to_update, upwd);
                break;
            }
            case LABEL_CD:
            {
                cout << endl;
                cout << "Saisir le label à modifier : " << endl;
                cin >> to_update;
                cout << endl;
                cout << "Saisir le label : " << endl;
                cin >> upwd;

                updatecd.Mediatheque::modifier(path, basepath, to_update, upwd);
                break;
            }
            case IDENTIFIANT_CD:
            {
                int to_update_id;
                int update_id;

                cout << endl;
                cout << "Saisir l'ID à modifier : " << endl;
                cin >> to_update_id;
                cout << endl;
                cout << "Saisir le nouvel ID : " << endl;
                cin >> update_id;

                to_update = to_string(to_update_id);
                upwd = to_string(update_id);

                updatecd.Mediatheque::modifier(path, basepath, to_update, upwd);
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
            break;
        }
        default:
            cerr << "Option invalide." << endl;
            break;
        }
    } while (choixcd != RETOUR);
}
