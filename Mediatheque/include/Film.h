#ifndef FILM_H
#define FILM_H
#define AJOUTER 1
#define SUPPRIMER 2
#define RECHERCHER 3
#define AFFICHER 4
#define RETOUR 5
#define CHEMIN_FILM "film.txt"
#include <Mediatheque.h>

class Film : public Mediatheque
{
    public:
        Film();
        Film(const string& titre, int ID,const string& producteur, const string& realisateur);
        ~Film();
        void menufilm();
        void ajouter();
        void supprimer();
        void rechercher();
        void afficher();

    protected:
        string producteur;
        string realisateur;
        string donnees;

    private:
        const string nomfichier;
};

#endif // FILM_H
