#include "Film.h"

Film::Film() {}

Film::Film(const string &titre, int ID, const string &producteur, const string &realisateur)
    : Mediatheque(titre, ID), producteur(producteur), realisateur(realisateur) {}

Film::~Film() {}

void Film::menufilm()
{
    int choixfilm;
    do
    {
        cout << "============ MENU FILM ============" << endl;
        cout << AJOUTER << " - Ajout d'une notice " << endl;
        cout << SUPPRIMER << " - Supprimer des notices " << endl;
        cout << RECHERCHER << " - Rechercher des notices " << endl;
        cout << AFFICHER << " - Afficher une notice " << endl;
        cout << MODIFIER << " - Modifier une notice" << endl;
        cout << RETOUR << " - Retour menu principal" << endl;
        cout << "Saisie : ";
        cin >> choixfilm;

        switch (choixfilm)
        {
        case AJOUTER:
        {
            string titre, producteur, realisateur, data, input;
            int id;

            cout << "============ AJOUT NOTICE ============" << endl;
            cout << "Saisir le titre : ";
            cin >> titre;
            cout << "Saisir le producteur : ";
            cin >> producteur;
            cout << "Saisir le realisateur : ";
            cin >> realisateur;
            cout << "Saisir l'identifiant (4 nombre) : ";
            cin >> id;

            const string path = CHEMIN_FILM;

            Film noticefilm(titre, id, producteur, realisateur);
            data = titre + "," + to_string(id) + "," + producteur + "," + realisateur;
            noticefilm.Mediatheque::ajouter(path, data);
            break;
        }
        case SUPPRIMER:
        {
            int id;
            string path;
            string basepath;
            path = "/home/hcosse/gestion_notice/film/film.txt";
            basepath = "/home/hcosse/gestion_notice/film/";
            Film affichefilm;
            affichefilm.Mediatheque::afficher(path);
            cout << "============ SUPPRESSION FILM ============" << endl;
            cout << "Saisir l'identifiant de la notice � supprimer (4 nombre) : " << endl;
            cin >> id;
            Film noticesupp;
            noticesupp.Mediatheque::supprimer(path, basepath, id);
            break;
        }
        case RECHERCHER:
        {
            string titre;
            int id;
            string path;
            path = CHEMIN_FILM;
            Film recherchefilm;
            cout << "============ RECHERCHE FILM ============" << endl;
            cout << "Saisir le titre rechercher : ";
            cin >> titre;
            cout << "Saisir l'ID rechercher : ";
            cin >> id;
            recherchefilm.Mediatheque::rechercher(path, titre, id);
            break;
        }
        case AFFICHER:
        {
            const string path = CHEMIN_FILM;
            Film affichefilm;
            affichefilm.Mediatheque::afficher(path);
            break;
        }

        case MODIFIER:
        {
            const string path = CHEMIN_FILM;
            string basepath = "/home/hcosse/gestion_notice/cd/";
            string to_update;
            string upwd;
            int choix_update;
            Film updatefilm;

            cout << "============ MODIFIER NOTICE  ============" << endl;
            cout << endl;
            cout << TITRE_FILM << " - Titre" << endl;
            cout << PRODUCTEUR_FILM << " - Producteur" << endl;
            cout << REALISATEUR_FILM << " - Realisateur" << endl;
            cout << IDENTIFIANT_FILM << " - ID" << endl;
            cout << RETOUR_MODIF_FILM << " - Retour menu gestion FILM  " << endl;
            cout << "Saisir l'attribut à modifier : " << endl;
            cin >> choix_update;
            cout << endl;

            switch (choix_update)
            {
            case TITRE_FILM:
            {
                cout << endl;
                cout << "Saisir le titre à modifier : " << endl;
                cin >> to_update;
                cout << endl;
                cout << "Saisir le nouveau titre : " << endl;
                cin >> upwd;

                updatefilm.Mediatheque::modifier(path, basepath, to_update, upwd);
                break;
            }
            case PRODUCTEUR_FILM:
            {
                cout << endl;
                cout << "Saisir le producteur à modifier : " << endl;
                cin >> to_update;
                cout << endl;
                cout << "Saisir le nouveau producteur : " << endl;
                cin >> upwd;

                updatefilm.Mediatheque::modifier(path, basepath, to_update, upwd);
                break;
            }
            case REALISATEUR_FILM:
            {
                cout << endl;
                cout << "Saisir le realisateur a modifier : " << endl;
                cin >> to_update;
                cout << endl;
                cout << "Saisir le realisateur : " << endl;
                cin >> upwd;

                updatefilm.Mediatheque::modifier(path, basepath, to_update, upwd);
                break;
            }
            case IDENTIFIANT_FILM:
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
                updatefilm.Mediatheque::modifier(path, basepath, to_update, upwd);
                break;
            }
            case RETOUR_MODIF_FILM:
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
    } while (choixfilm != RETOUR);
}
