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
        virtual void afficher(string& Chemin);
        virtual void rechercher();
        virtual void supprimer();
        virtual void ecriturefichier(string& Chemin, string& Donnees);

    protected:
        //Attribut communs aux trois classes filles
        string Titre;
        int ID;

};

#endif // MEDIATHEQUE_H
