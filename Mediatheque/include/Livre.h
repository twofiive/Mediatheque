#ifndef LIVRE_H
#define LIVRE_H
#include <Mediatheque.h>

#define AJOUTER 1
#define SUPPRIMER 2
#define RECHERCHER 3
#define AFFICHER 4
#define MODIFIER 5
#define RETOUR 6

/// Declaration des MACROS pour le menu de modification
#define TITRE_LIVRE 10
#define AUTEUR_LIVRE 11
#define EDITEUR_LIVRE 12
#define IDENTIFIANT_LIVRE 13
#define RETOUR_MODIF_LIVRE 15

#define CHEMIN_LIVRE "livre.txt"

class Livre : public Mediatheque
{
public:
    Livre();
    Livre(const string &titre, int ID, const string &auteur, const string &editeur);

    void ajouter();
    void supprimer();
    void rechercher();
    void afficher();
    void modifier();
    void menulivre();

protected:
    /// Declaration des attributs
    string auteur;
    string editeur;
    string data;

private:
    const string path;
};

#endif // LIVRE_H
