#include "CD.h"
#include <iostream>

CD::CD() {};
CD::CD(const string &titre, int ID, const string &interprete, const string &label)
    : Mediatheque(titre, ID), interprete(interprete), label(label) {}
CD::~CD() {}

void CD::menucd()
{
    int choixcd;
do{
    cout << "============ MENU MEDIATHEQUE ============" << endl;
    cout << "1- Ajout d'une notice CD " << endl;
    cout << "2- Supprimer des notices CD" << endl;
    cout << "3- Rechercher des notices CD" << endl;
    cout << "4- Afficher une notice CD" << endl;
    cout << "0- Retour menu principal" << endl;
    cin >> choixcd;

    switch (choixcd)
    {
    case AJOUTER:
    {
        string titre, interprete, label, donnees;
        int id;
        string chemin;

        cout << "Saisir le titre : " << endl;
        cin >> titre;
        cout << "Saisir l'interprete :" << endl;
        cin >> interprete;
        cout << "Saisir le label : " << endl;
        cin >> label;
        cout << "Saisir l'identifiant (4 nombre) : " << endl;
        cin >> id;

        CD noticecd(titre, id, interprete, label);
        chemin = CHEMIN_CD;
        donnees = titre + "," + to_string(id) + "," + interprete + "," + label;
        noticecd.Mediatheque::ajouter(chemin,donnees); 
        break;
    }
    case SUPPRIMER:

        break;
    case RECHERCHER:

        break;
    case AFFICHER:

        break;
    default:
        cerr << "Option invalide." << endl;
        break;
    }
}while(choixcd != RETOUR);
}
