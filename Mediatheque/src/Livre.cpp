#include "Livre.h"

Livre::Livre()
{
}

Livre::Livre(const string &titre, int ID, const string &auteur, const string &editeur) : Mediatheque(titre, ID), auteur(auteur), editeur(editeur) {}

void Livre::menulivre()
{
    int choixlivre;
    do
    {
        cout << "============ MENU LIVRE ============" << endl;
        cout << AJOUTER << " - Ajout d'une notice " << endl;
        cout << SUPPRIMER << " - Supprimer des notices " << endl;
        cout << RECHERCHER << " - Rechercher des notices " << endl;
        cout << AFFICHER << " - Afficher une notice " << endl;
        cout << MODIFIER << " - Modifier une notice" << endl;
        cout << RETOUR << " - Retour menu principal" << endl;
        cout << "Saisie : ";
        cin >> choixlivre;

        switch (choixlivre)
        {
        case AJOUTER:
        {
            string titre, auteur, editeur, data, input;
            int id;

            cout << "============ AJOUT NOTICE ============" << endl;
            cout << "Saisir le titre : ";
            cin >> titre;
            cout << "Saisir le auteur : ";
            cin >> auteur;
            cout << "Saisir le editeur : ";
            cin >> editeur;
            cout << "Saisir l'identifiant (4 nombre) : ";
            cin >> id;

            const string path = CHEMIN_LIVRE;

            Livre noticelivre(titre, id, auteur, editeur);
            data = titre + "," + to_string(id) + "," + auteur + "," + editeur;
            noticelivre.Mediatheque::ajouter(path, data);
            break;
        }
        case SUPPRIMER:
        {
            int id;
            string path;
            string basepath;
            path = "livre.txt";
            basepath = "livre/";
            Livre affichelivre;
            affichelivre.Mediatheque::afficher(path);
            cout << "============ SUPPRESSION LIVRE ============" << endl;
            cout << "Saisir l'identifiant de la notice a supprimer (4 nombre) : " << endl;
            cin >> id;
            Livre noticesupp;
            noticesupp.Mediatheque::supprimer(path, basepath, id);
            break;
        }
        case RECHERCHER:
        {
            string titre;
            int id;
            string path;
            path = CHEMIN_LIVRE;
            Livre recherchelivre;
            cout << "============ RECHERCHE LIVRE ============" << endl;
            cout << "Saisir le titre rechercher : ";
            cin >> titre;
            cout << "Saisir l'ID rechercher : ";
            cin >> id;
            recherchelivre.Mediatheque::rechercher(path, titre, id);
            break;
        }
        case AFFICHER:
        {
            const string path = CHEMIN_LIVRE;
            Livre affichelivre;
            affichelivre.Mediatheque::afficher(path);
            break;
        }
        case MODIFIER:
        {
            const string path = CHEMIN_LIVRE;
            string basepath = "/home/hcosse/gestion_notice/cd/";
            string to_update;
            string upwd;
            int choix_update;
            Livre updatelivre;

            cout << "============ MODIFIER NOTICE  ============" << endl;
            cout << endl;
            cout << TITRE_LIVRE << " - Titre" << endl;
            cout << AUTEUR_LIVRE << " - Auteur" << endl;
            cout << EDITEUR_LIVRE << " - Editeur" << endl;
            cout << IDENTIFIANT_LIVRE << " - ID" << endl;
            cout << RETOUR_MODIF_LIVRE << " - Retour menu gestion Livre " << endl;
            cout << "Saisir l'attribut a modifier : " << endl;
            cin >> choix_update;
            cout << endl;

            if (choix_update == TITRE_LIVRE || choix_update == AUTEUR_LIVRE || choix_update == EDITEUR_LIVRE || choix_update == IDENTIFIANT_LIVRE )
            {
                cout << "Liste des livres : " << endl;
                updatelivre.Mediatheque::afficher(path);
                cout << endl;
            }

            switch (choix_update)
            {
            case TITRE_LIVRE:
            {
                cout << endl;
                cout << "Saisir le titre a modifier : " << endl;
                cin >> to_update;
                cout << endl;
                cout << "Saisir le nouveau titre : " << endl;
                cin >> upwd;

                updatelivre.Mediatheque::modifier(path, basepath, to_update, upwd);
                break;
            }
            case AUTEUR_LIVRE:
            {
                cout << endl;
                cout << "Saisir l'auteur a modifier : " << endl;
                cin >> to_update;
                cout << endl;
                cout << "Saisir le nouvel auteur : " << endl;
                cin >> upwd;

                updatelivre.Mediatheque::modifier(path, basepath, to_update, upwd);
                break;
            }
            case EDITEUR_LIVRE:
            {
                cout << endl;
                cout << "Saisir l'editeur a modifier : " << endl;
                cin >> to_update;
                cout << endl;
                cout << "Saisir le nouvel editeur : " << endl;
                cin >> upwd;

                updatelivre.Mediatheque::modifier(path, basepath, to_update, upwd);
                break;
            }
            case IDENTIFIANT_LIVRE:
            {
                int to_update_id;
                int update_id;

                cout << endl;
                cout << "Saisir l'ID a modifier : " << endl;
                cin >> to_update_id;
                cout << endl;
                cout << "Saisir le nouvel ID : " << endl;
                cin >> update_id;

                to_update = to_string(to_update_id);
                upwd = to_string(update_id);

                updatelivre.Mediatheque::modifier(path, basepath, to_update, upwd);
                break;
            }
            case RETOUR_MODIF_LIVRE:
            {
                break;
            }
            default:
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
    }
    while (choixlivre != RETOUR);
}
