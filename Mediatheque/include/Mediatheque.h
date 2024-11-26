#ifndef MEDIATHEQUE_H
#define MEDIATHEQUE_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

// Menu principal
#define GESTION_CD 1
#define GESTION_LIVRE 2
#define GESTION_FILM 3
#define QUITTER 4

class Mediatheque {
protected:
    string titre;          // Titre de la médiathèque
    int id;                // Identifiant de la médiathèque
    vector<string> data;   // Vecteur pour stocker les données

public:
    // Constructeurs
    Mediatheque();
    Mediatheque(const string &titre, int ID);
   ~Mediatheque();

    // Méthodes virtuelles
    virtual void afficher();                               // Afficher les données
    virtual void rechercher(vector<string> &loadedData);   // Rechercher une notice
    virtual void supprimer();                              // Supprimer une notice
    virtual void ajouter(const string &notice);            // Ajouter une notice
    virtual void modifier(int &choix, int &id);            // Modifier une notice
    virtual void chargementdata(const string &chemin);     // Charger les données depuis un fichier
    virtual void enregistrer(const string &chemin);        // Enregistrer les données dans un fichier
};

#endif // MEDIATHEQUE_H
