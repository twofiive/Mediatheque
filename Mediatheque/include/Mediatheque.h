#ifndef MEDIATHEQUE_H
#define MEDIATHEQUE_H
/** Declaration des choix pour le menu principal */
#define GESTION_CD 1
#define GESTION_LIVRE 2
#define GESTION_FILM 3
#define QUITTER 4

/** Declaration des bibilioth�ques */
#include <iostream>
#include <string>
#include <fstream> /** Pour la gestion de fichiers */

using namespace std;

class Mediatheque
{
public:
    /** Declaration des constructeurs */
    Mediatheque();
    Mediatheque(const string &titre, int ID);

    virtual ~Mediatheque(); /** Destructeur virtuel */

    /// Par contenu je fais r�f�rence au notice
    virtual void afficher(const string &path); /** M�thode pour afficher du contenu des classes fille */
    virtual void rechercher(const string &path, string &titre, int &id); /** M�thode pour rechercher du contenu dans les classes fille */
    virtual void supprimer(const string &path, string &basepath, int &id); /** M�thode pour supprimer du contenu des classes fille */
    virtual void ajouter(const string &path, string &data); /** M�thode pour ajouter du contenu des classes fille */
    virtual void modifier(const string &path, string &basepath, string &to_update, string &updw); /** M�thode pour modifier le contenu des classes fille */

protected:

    /// Ces attributs sont accesibles par les classes fille

    string titre;
    int id;
};

#endif // MEDIATHEQUE_H
