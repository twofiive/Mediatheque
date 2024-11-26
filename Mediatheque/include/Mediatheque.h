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
<<<<<<< HEAD
   ~Mediatheque();

    // Méthodes virtuelles
    virtual void afficher();                               // Afficher les données
    virtual void rechercher(vector<string> &loadedData);   // Rechercher une notice
    virtual void ajouter(const string &notice);            // Ajouter une notice
    virtual void modifier(int &choix, int &id);            // Modifier une notice
    virtual void chargementdata(const string &chemin);     // Charger les données depuis un fichier
    virtual void enregistrer(const string &chemin);        // Enregistrer les données dans un fichier
};
=======

    virtual ~Mediatheque(); /** Destructeur virtuel */

    /// Par contenu je fais reference au notice
    virtual void afficher();                                                 /** Methode pour afficher du contenu des classes fille */
    virtual void rechercher(vector<string> &loadedData, const string &path); /** Methode pour rechercher du contenu dans les classes fille */
    virtual void supprimer(vector<string> &loadedData, const string &path);  /** Methode pour supprimer du contenu des classes fille */
    virtual void ajouter(const string notice);                               /** Methode pour ajouter du contenu des classes fille */
    virtual void modifier();                                                 /** Methode pour modifier le contenu des classes fille */
    virtual void chargementdata(const string &path);
    virtual void enregistrer(const string &path)
}
>>>>>>> 992ce3743511e3832702b9e3f71114dd0796d910

#endif // MEDIATHEQUE_H
