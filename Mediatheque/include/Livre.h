#ifndef LIVRE_H
#define LIVRE_H

#include <Mediatheque.h>


class Livre : public Mediatheque
{
    public:
        Livre();
        # Constructeur h�rite du constructeur de base de la classe m�diath�que avec titre et ID et
        # ajoute les attributs sp�cifique � la classe interpr�te et label
        Livre(const Livre& other, const string& auteur, const string& editeur, int ID) :
          Mediatheque(Titre, ID), auteur(auteur), editeur(editeur);
        void ajouter();
        void supprimer();
        void rechercher();
        void afficher();

    protected:
        string auteur;
        string editeur;
        string donnees;

    private:
        const string nomfichier = livre.txt

};

#endif // LIVRE_H
