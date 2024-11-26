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


#define CHEMINCD "cd.txt"

using namespace std;

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

};

#endif // CD_H
