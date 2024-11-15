#ifndef MEDIATHEQUE_H
#define MEDIATHEQUE_H

#include <iostream>
#include <string>
#include <fstream>


using namespace std;

class Mediatheque
{
    public:
        //Constructeur commun aux trois classe fille
        Mediatheque();
        Mediatheque(const string& titre, int ID);

        //Methode commune aux trois classe fille
        virtual ~Mediatheque();
        virtual void afficher(string& chemin);
        virtual void rechercher(string& chemin,string& recherche);
        virtual void supprimer(string &chemin,string& basechemin, int& ID);
        virtual void ecriturefichier(string& chemin, string& donnees);

    protected:
        //Attribut communs aux trois classes filles
        string titre;
        int id;

};

#endif // MEDIATHEQUE_H
