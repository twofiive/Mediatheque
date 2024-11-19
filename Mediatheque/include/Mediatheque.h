#ifndef MEDIATHEQUE_H
#define MEDIATHEQUE_H
#define GESTION_CD 1
#define GESTION_LIVRE 2
#define GESTION_VIDEO 3
#define QUITTER 4

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Mediatheque
{
public:
    Mediatheque();
    Mediatheque(const string &titre, int ID);

    virtual ~Mediatheque();
    virtual void afficher(const string &chemin);
    virtual void rechercher(const string &chemin,string &titre,int &id);
    virtual void supprimer(string &chemin, string &basechemin, int &id);
    virtual void ajouter(const string &chemin, string &donnees);

protected:
    string titre;
    int id;
};

#endif // MEDIATHEQUE_H
