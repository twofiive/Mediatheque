#ifndef LIVRE_H
#define LIVRE_H

#include "Mediatheque.h"
#include <string>

using namespace std;

// Menu gestion des livres
#define AJOUTER 1
#define SUPPRIMER 2
#define RECHERCHER 3
#define AFFICHER 4
#define MODIFIER 5
#define RETOUR 6

// Menu modification des livres
#define TITRE_LIVRE 10
#define AUTEUR_LIVRE 11
#define EDITEUR_LIVRE 12
#define IDENTIFIANT_LIVRE 13
#define RETOUR_MODIF_LIVRE 14

#define CHEMIN_LIVRE "livre.txt" // Chemin constant pour le fichier des livres

class Livre : public Mediatheque {
public:
    // Constructeurs
    Livre();
    Livre(const string &titre, int ID, const string &auteur, const string &editeur);
    ~Livre();

    void menulivre(); // Menu spécifique à la gestion des livres

protected:
    string auteur;    // Auteur du livre
    string editeur;   // Éditeur du livre

};

#endif // LIVRE_H
