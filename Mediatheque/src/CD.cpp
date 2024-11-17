#include "CD.h"
#include <iostream>

CD::CD(const string& titre, int ID, const string& interprete, const string& label)
    : Mediatheque(titre, ID), interprete(interprete), label(label) {}

void CD::menucd()
{
    int choixcd;

    cout << "============ MENU MEDIATHEQUE ============" << endl;
    cout << "1- Gestion des notice CD " << endl;
    cout << "2- Gestion des notice Livre" << endl;
    cout << "3- Gestion des notice Video" << endl;
    cout << "4- Quitter " << endl;
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

        CD noticecd(titre, id, interprete, label);
        donnees = titre + "," + to_string(id) + "," + interprete + "," + label;
        noticecd.Mediatheque::ajouter(donnees, CHEMIN_CD); // Si tu veux appeler la méthode de la classe de base
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
}
