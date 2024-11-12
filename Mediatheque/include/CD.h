#ifndef CD_H
#define CD_H

#include <Mediatheque.h>


class CD : public Mediatheque
{
    public:
        CD();
        # Constructeur h�rite du constructeur de base de la classe m�diath�que avec titre et ID et
        # ajoute les attributs sp�cifique � la classe interpr�te et label
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
