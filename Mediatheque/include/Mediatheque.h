#ifndef MEDIATHEQUE_H
#define MEDIATHEQUE_H
#define GESTION_CD 1
#define GESTION_LIVRE 2
#define GESTION_FILM 3
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
    virtual void afficher(const string &path);
    virtual void rechercher(const string &path, string &titre, int &id);
    virtual void supprimer(const string &path, string &basepath, int &id);
    virtual void ajouter(const string &path, string &data);
    virtual void modifier(const string &path, string &basepath, string &to_update, string &updw);

protected:
    string titre;
    int id;
};

#endif // MEDIATHEQUE_H
