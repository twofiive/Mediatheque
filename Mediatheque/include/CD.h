#ifndef CD_H
#define CD_H

#include <Mediatheque.h>


class CD : public Mediatheque
{
    public:
        CD();
        # Constructeur hérite du constructeur de base de la classe médiathèque avec titre et ID et
        # ajoute les attributs spécifique à la classe interprète et label
        CD(const CD& other, const string& interprete, const string& label, int ID) :
          Mediatheque(Titre, ID), interprete(interprete), label(label);
        void ajouter();
        void supprimer();
        void rechercher();
        void afficher();

    protected:
        string interprete;
        string label;
        string donnees;

    private:
        const string nomfichier = cd.txt
};

#endif // CD_H
