#include "Livre.h"

Livre::Livre()
{}

Livre::Livre(const string& titre, int ID, const string& auteur, const string& editeur) :
    Mediatheque(titre, ID), auteur(auteur), editeur(editeur){}

void Livre::menulivre(){
    int choixlivre;
    do
    {
        cout << "============ MENU LIVRE ============" << endl;
        cout << AJOUTER << " - Ajout d'une notice " << endl;
        cout << SUPPRIMER << " - Supprimer des notices " << endl;
        cout << RECHERCHER << " - Rechercher des notices " << endl;
        cout << AFFICHER << " - Afficher une notice " << endl;
        cout << RETOUR << " - Retour menu principal" << endl;
        cout << "Saisie : ";
        cin >> choixlivre;

        switch (choixlivre)
        {
        case AJOUTER:
        {
            string titre, auteur, editeur, donnees, input;
            int id;

                cout << "============ AJOUT NOTICE ============" << endl;
                cout << "Saisir le titre : ";
                cin >> titre;
                cout<< "Saisir le auteur : ";
                cin >> auteur;
                cout << "Saisir le editeur : ";
                cin >> editeur;
                cout << "Saisir l'identifiant (4 nombre) : ";
                cin >> id;

                const string chemin = CHEMIN_LIVRE;

                Livre noticelivre(titre, id, auteur, editeur);
                donnees = titre + "," + to_string(id) + "," + auteur + "," + editeur;
                noticelivre.Mediatheque::ajouter(chemin, donnees);
                break;
            }
        case SUPPRIMER:
        {
            int id;
            string chemin;
            string basechemin;
            chemin = "livre.txt";
            basechemin = "livre/";
            Livre affichelivre;
            affichelivre.Mediatheque::afficher(chemin);
            cout << "============ SUPPRESSION LIVRE ============" << endl;
            cout << "Saisir l'identifiant de la notice à supprimer (4 nombre) : " << endl;
            cin >> id;
            Livre noticesupp;
            noticesupp.Mediatheque::supprimer(chemin, basechemin, id);
            break;
        }
        case RECHERCHER:
        {
            string titre;
            int id;
            string chemin;
            chemin = CHEMIN_LIVRE;
            Livre recherchelivre;
            cout << "============ RECHERCHE LIVRE ============" << endl;
            cout << "Saisir le titre rechercher : " ;
            cin >> titre;
            cout << "Saisir l'ID rechercher : " ;
            cin >> id;
            recherchelivre.Mediatheque::rechercher(chemin, titre, id);
            break;
        }
        case AFFICHER:
        {
            const string chemin = CHEMIN_LIVRE;
            Livre affichelivre;
            affichelivre.Mediatheque::afficher(chemin);
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
        while (choixlivre != RETOUR)
            ;
}
