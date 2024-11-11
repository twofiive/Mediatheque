#ifndef MEDIATHEQUE_H
#define MEDIATHEQUE_H
#include <iostream>

using namespace std;

class Mediatheque
{
    public:
        # Constructeur commun aux trois classe fille
        Mediatheque();
        Mediatheque(const string& titre, int ID);

        # Méthode commune aux trois classe fille
        virtual ~Mediatheque();
        virtual void afficher();
        virtual void rechercher();
        virtual supprimer();

    protected:
        # Attribut communs aux trois classes filles
        string Titre;
        int ID;

};

#endif // MEDIATHEQUE_H
