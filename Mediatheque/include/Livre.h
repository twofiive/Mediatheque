#ifndef LIVRE_H
#define LIVRE_H

#include <Mediatheque.h>
#define AJOUTER 1
#define SUPPRIMER 2
#define RECHERCHER 3
#define AFFICHER 4
#define RETOUR 5
#define CHEMIN_LIVRE "livre.txt"

class Livre : public Mediatheque
{
    public:
        Livre();
        //Constructeur hérite du constructeur de base de la classe médiathèque avec titre et ID et
        //ajoute les attributs spécifique à la classe interprète et label
        Livre(const string& titre, int ID, const string& auteur, const string& editeur);
        void ajouter();
        void supprimer();
        void rechercher();
        void afficher();
        void menulivre();

    protected:
        string auteur;
        string editeur;
        string donnees;

    private:
        const string nomfichier;

};

#endif // LIVRE_H
