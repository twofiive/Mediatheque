#include "Film.h"

Film::Film(){}

Film::Film(const string& titre,  int ID, const string& producteur, const string& realisateur)
: Mediatheque(titre, ID), producteur(producteur), realisateur(realisateur){}

Film::~Film(){}

void Film::menufilm(){
    int choixfilm;
    do
    {
        cout << "============ MENU FILM ============" << endl;
        cout << AJOUTER << " - Ajout d'une notice " << endl;
        cout << SUPPRIMER << " - Supprimer des notices " << endl;
        cout << RECHERCHER << " - Rechercher des notices " << endl;
        cout << AFFICHER << " - Afficher une notice " << endl;
        cout << RETOUR << " - Retour menu principal" << endl;
        cout << "Saisie : ";
        cin >> choixfilm;

        switch (choixfilm)
        {
        case AJOUTER:
        {
            string titre, producteur, realisateur, donnees, input;
            int id;

                cout << "============ AJOUT NOTICE ============" << endl;
                cout << "Saisir le titre : ";
                cin >> titre;
                cout<< "Saisir le producteur : ";
                cin >> producteur;
                cout << "Saisir le realisateur : ";
                cin >> realisateur;
                cout << "Saisir l'identifiant (4 nombre) : ";
                cin >> id;

                const string chemin = CHEMIN_FILM;

                Film noticefilm(titre, id, producteur, realisateur);
                donnees = titre + "," + to_string(id) + "," + producteur + "," + realisateur;
                noticefilm.Mediatheque::ajouter(chemin, donnees);
                break;
            }
        case SUPPRIMER:
        {
            int id;
            string chemin;
            string basechemin;
            chemin = "/home/hcosse/gestion_notice/film/film.txt";
            basechemin = "/home/hcosse/gestion_notice/film/";
            Film affichefilm;
            affichefilm.Mediatheque::afficher(chemin);
            cout << "============ SUPPRESSION FILM ============" << endl;
            cout << "Saisir l'identifiant de la notice à supprimer (4 nombre) : " << endl;
            cin >> id;
            Film noticesupp;
            noticesupp.Mediatheque::supprimer(chemin, basechemin, id);
            break;
        }
        case RECHERCHER:
        {
            string titre;
            int id;
            string chemin;
            chemin = CHEMIN_FILM;
            Film recherchefilm;
            cout << "============ RECHERCHE FILM ============" << endl;
            cout << "Saisir le titre rechercher : " ;
            cin >> titre;
            cout << "Saisir l'ID rechercher : " ;
            cin >> id;
            recherchefilm.Mediatheque::rechercher(chemin, titre, id);
            break;
        }
        case AFFICHER:
        {
            const string chemin = CHEMIN_FILM;
            Film affichefilm;
            affichefilm.Mediatheque::afficher(chemin);
        }

        break;
        case RETOUR:
        {
            break;
        }
        default:
            cerr << "Option invalide." << endl;
            break;
        }
        }
        while (choixfilm != RETOUR)
            ;
}
