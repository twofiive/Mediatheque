#ifndef FILM_H
#define FILM_H

#include "Mediatheque.h"
#include <string>

using namespace std;

// Menu gestion des films
#define AJOUTER 1
#define SUPPRIMER 2
#define RECHERCHER 3
#define AFFICHER 4
#define MODIFIER 5
#define RETOUR 6

// Menu modification des films
#define TITRE_FILM 10
#define PRODUCTEUR_FILM 11
#define REALISATEUR_FILM 12
#define IDENTIFIANT_FILM 13
#define RETOUR_MODIF_FILM 14

#define CHEMIN_FILM "film.txt"

class Film : public Mediatheque
{
protected:
    string producteur;  // Producteur du film
    string realisateur; // Réalisateur du film
public:
    // Constructeurs
    Film();
    Film(const string &titre, int ID, const string &producteur, const string &realisateur);
    ~Film();

    void menufilm(); // Menu spécifique à la gestion des films


};

#endif // FILM_H
