#ifndef FILM_H
#define FILM_H

#include <Mediatheque.h>


class Film : public Mediatheque
{
    public:
        Film();
        # Constructeur h�rite du constructeur de base de la classe m�diath�que avec titre et ID et
        # ajoute les attributs sp�cifique � la classe interpr�te et label
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
