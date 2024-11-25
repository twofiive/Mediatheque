#ifndef MEDIATHEQUE_H
#define MEDIATHEQUE_H
/** Declaration des choix pour le menu principal */
#define GESTION_CD 1
#define GESTION_LIVRE 2
#define GESTION_FILM 3
#define QUITTER 4

/** Declaration des bibliotheques */
#include <iostream>
#include <string>
#include <fstream> /** Pour la gestion de fichiers */
#include <vector>

using namespace std;

class Mediatheque
{
    
protected:
/// Ces attributs sont accesibles par les classes fille
    static vector<string> data;
public:
    /** Declaration des constructeurs */
    Mediatheque();
    Mediatheque(const string &titre, int ID);

    virtual ~Mediatheque(); /** Destructeur virtuel */

  /// Par contenu je fais reference au notice
    virtual void afficher(); /** Methode pour afficher du contenu des classes fille */
    virtual void rechercher( vector <string> &loadedData, const string &path); /** Methode pour rechercher du contenu dans les classes fille */
    virtual void supprimer(); /** Methode pour supprimer du contenu des classes fille */
    virtual void ajouter(const string notice); /** Methode pour ajouter du contenu des classes fille */
    virtual void modifier(); /** Methode pour modifier le contenu des classes fille */
    virtual void chargementdata(const string &path,);
    virtual void enregistrer(const string &path,)

}

#endif // MEDIATHEQUE_H
