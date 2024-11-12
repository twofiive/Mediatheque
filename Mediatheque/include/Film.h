#ifndef FILM_H
#define FILM_H

#include <Mediatheque.h>


class Film : public Mediatheque
{
    public:
        Film();
        # Constructeur hérite du constructeur de base de la classe médiathèque avec titre et ID et
        # ajoute les attributs spécifique à la classe interprète et label
        Film(const Film& other, const string& producteur, const string& realisateur, int ID) :
          Mediatheque(Titre, ID), producteur(producteur), realisateur(realisateur);
        void ajouter();
        void supprimer();
        void rechercher();
        void afficher();

    protected:
        string producteur;
        string realisateur;
        string donnees;

    private:
        const string nomfichier = film.txt
};

#endif // FILM_H
