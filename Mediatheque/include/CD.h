#ifndef CD_H
#define CD_H
#define CHEMIN_CD "C:/Users/Administrator/Documents/mediatheque/cd"
#define AJOUTER 1
#define SUPPRIMER 2
#define RECHERCHER 3
#define AFFICHER 4


#include "Mediatheque.h"

using namespace std;

class CD : public Mediatheque
{
public:
    CD(const string& titre, int ID, const string& interprete, const string& label);
    ~CD();

    void menucd();
    void ajouter(); 
    void supprimer();
    void rechercher();
    void afficher();

protected:
    string interprete;
    string label;
    string donnees;

private:
    const string nomfichier = "cd.txt";
};

#endif
