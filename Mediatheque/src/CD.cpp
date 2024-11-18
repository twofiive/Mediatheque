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
        cout << "============ MENU MEDIATHEQUE ============" << endl;
        cout << "1- Ajout d'une notice CD " << endl;
        cout << "2- Supprimer des notices CD" << endl;
        cout << "3- Rechercher des notices CD" << endl;
        cout << "4- Afficher une notice CD" << endl;
        cout << "5- Retour menu principal" << endl;
        cin >> choixcd;

        switch (choixcd)
        {
        case AJOUTER:
        {
            string titre, interprete, label, donnees;
            int id;

            cout << "Saisir le titre : " << endl;
            cin >> titre;
            cout << "Saisir l'interprete :" << endl;
            cin >> interprete;
            cout << "Saisir le label : " << endl;
            cin >> label;
            cout << "Saisir l'identifiant (4 nombre) : " << endl;
            cin >> id;

            const string chemin = CHEMIN_CD;

            CD noticecd(titre, id, interprete, label);
            donnees = titre + "," + to_string(id) + "," + interprete + "," + label;
            noticecd.Mediatheque::ajouter(chemin, donnees);
            break;
        }
        case SUPPRIMER:
        {
            string chemin;
            string basechemin;
            chemin = "/home/hcosse/gestion_notice/cd/cd.txt";
            basechemin = "/home/hcosse/gestion_notice/cd/";
            CD affichecd;
            affichecd.Mediatheque::afficher(chemin);
            cout << "Saisir l'identifiant de la notice à supprimer (4 nombre) : " << endl;
            cin >> id;
            CD noticesupp;
            noticesupp.Mediatheque::supprimer(chemin, basechemin, id);
            break;
        }
        case RECHERCHER:
        {
            string titre;
            int id;
            string chemin;
            chemin = CHEMIN_CD;
            CD recherchecd;
            cout << "Saisir le titre rechercher :" << endl;
            cin >> titre;
            cout << "Saisir l'ID rechercher :" << endl;
            cin >> id;
            recherchecd.Mediatheque::rechercher(chemin, titre, id);
            break;
        }
        case AFFICHER:
        {
            const string chemin = CHEMIN_CD;
            CD affichecd;
            affichecd.Mediatheque::afficher(chemin);
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
    } while (choixcd != RETOUR);
}
