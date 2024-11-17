#ifndef MEDIATHEQUE_H
#define MEDIATHEQUE_H
#define GESTION_CD 1 
#define GESTION_LIVRE 2 
#define GESTION_VIDEO 3 
#define QUITTER 0

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Mediatheque
{
    public:
        Mediatheque();
        Mediatheque(const string& titre, int ID);

        virtual ~Mediatheque();
        virtual void afficher(string& chemin);
        virtual void rechercher(string& chemin, string& recherche);
        virtual void supprimer(string& chemin, string& basechemin, int& ID);
        virtual void ajouter(const string& chemin, string& donnees);

    protected:
        string titre;
        int id;
};

#endif // MEDIATHEQUE_H
