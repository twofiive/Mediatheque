#ifndef FILM_H
#define FILM_H
#define AJOUTER 1
#define SUPPRIMER 2
#define RECHERCHER 3
#define AFFICHER 4
#define MODIFIER 5
#define RETOUR 6

#define TITRE_FILM 6
#define PRODUCTEUR_FILM 7
#define REALISATEUR_FILM 8
#define IDENTIFIANT_FILM 9
#define RETOUR_MODIF_FILM 13
#define CHEMIN_FILM "film.txt"
#include <Mediatheque.h>
#include <string.h>

class Film : public Mediatheque
{
public:
    Film();
    Film(const string &titre, int ID, const string &producteur, const string &realisateur);
    ~Film();
    void menufilm();
    void ajouter();
    void supprimer();
//    void rechercher();
    void afficher();
    void modifier();

protected:
    /// Declaration des attributs
    string producteur;
    string realisateur;
    string data;

private:
    const string path;
};

#endif // FILM_H
