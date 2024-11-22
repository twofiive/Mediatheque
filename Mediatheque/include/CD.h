#ifndef CD_H
#define CD_H
#define AJOUTER 1
#define SUPPRIMER 2
#define RECHERCHER 3
#define AFFICHER 4
#define MODIFIER 5
#define RETOUR 6

#define TITRE_CD 10
#define AUTEUR_CD 11
#define LABEL_CD 12
#define IDENTIFIANT_CD 13
#define RETOUR_MODIF_CD 14
#define CHEMIN_CD "cd.txt"

#include "Mediatheque.h"

using namespace std;

class CD : public Mediatheque
{
public:
    CD();
    CD(const string &titre, int ID, const string &interprete, const string &label);
    ~CD();

    void menucd();
    void ajouter();
    void supprimer();
    void rechercher();
    void afficher();
    void modifier();

protected:
    string interprete;
    string label;
    string data;

private:
    const string path;
};

#endif
