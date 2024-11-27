#ifndef MEDIATHEQUE_H
#define MEDIATHEQUE_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>


// Menu principal
#define GESTION_CD 1
#define GESTION_LIVRE 2
#define GESTION_FILM 3
#define QUITTER 4

// Menu modification des CDs
#define TITRE 10
#define ARG_A 11
#define ARG_B 12
#define RETOUR_MODIF 14

// Borne de ID
#define BORNE_HAUTE 10000
#define BORNE_BASSE 1000

using namespace std;

class Mediatheque
{
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
    virtual void afficher(const string &path);                               // Afficher les données
    virtual void rechercher(vector<string> &loadedData, const string &path); /** Rechercher une notice */
    virtual void supprimer(vector<string> &loadedData, const string &path);  /** Supprimer une notice */
    virtual void ajouter(const string &notice);            // Ajouter une notice
    virtual void modifier(int &choix, int &id);            // Modifier une notice
    virtual void chargementdata(const string &chemin);     // Charger les données depuis un fichier
    virtual void enregistrer(const string &chemin);        // Enregistrer les données dans un fichier
};


#endif // MEDIATHEQUE_H
