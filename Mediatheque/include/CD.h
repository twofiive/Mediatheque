#ifndef CD_H
#define CD_H

#include "Mediatheque.h"

using namespace std;

// Menu gestion des CDs
#define AJOUTER 1
#define SUPPRIMER 2
#define RECHERCHER 3
#define AFFICHER 4
#define MODIFIER 5
#define ENREGISTRER 6
#define RETOUR 7

// Menu modification des CDs
#define TITRE_CD 10
#define AUTEUR_CD 11
#define LABEL_CD 12
#define IDENTIFIANT_CD 13
#define RETOUR_MODIF_CD 14

#define CHEMINCD "cd.txt"

class CD : public Mediatheque {
public:
    // Constructeurs
    CD();
    CD(const string &titre, int ID, const string &interprete, const string &label);
    ~CD();

    void menucd(); // Menu spécifique à la gestion des CDs

protected:
    string interprete; // Interprète d'un CD
    string label;      // Label d'un CD

private:
    static const string path; // Chemin constant pour le fichier CD
};

#endif // CD_H
