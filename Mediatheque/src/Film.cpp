#include "Film.h"

Film::Film() {}

Film::Film(const string &titre, int ID, const string &producteur, const string &realisateur)
    : Mediatheque(titre, ID), producteur(producteur), realisateur(realisateur) {}

Film::~Film() {}

void Film::menufilm()
{
    int choixfilm;
    do
    {
        cout << "============ MENU FILM ============" << endl;
        cout << AJOUTER << " - Ajout d'une notice " << endl;
        cout << SUPPRIMER << " - Supprimer des notices " << endl;
        cout << RECHERCHER << " - Rechercher des notices " << endl;
        cout << AFFICHER << " - Afficher une notice " << endl;
        cout << MODIFIER << " - Modifier une notice" << endl;
        cout << RETOUR << " - Retour menu principal" << endl;
        cout << "Saisie : ";
        cin >> choixfilm;

        switch (choixfilm)
        {
        case AJOUTER:
        {
            string titre, producteur, realisateur, data, input, entete;
            int id;

            cout << "============ AJOUT NOTICE ============" << endl;
            cout << "Saisir le titre : ";
            cin >> titre;
            cout << "Saisir le producteur : ";
            cin >> producteur;
            cout << "Saisir le realisateur : ";
            cin >> realisateur;
            do
            {
                cout << "Saisir l'identifiant (4 nombre) : ";
                cin >> id;
            }
            while ( id < 1000 || id >= 10000 );


            const string path = CHEMIN_FILM;

            /// Formatage du fichier
            Film noticefilm(titre, id, producteur, realisateur);
            entete = string("Titre") + ";" + "ID" + ";" + "Producteur" + ";" + "Realisateur";
            noticefilm.Mediatheque::ajouter(path, entete);
            data = titre + ";" + to_string(id) + ";" + producteur + ";" + realisateur;
            noticefilm.Mediatheque::ajouter(path, data);
            break;
        }
        case SUPPRIMER:
        {
            int id;
            string path;
            string basepath;
            path = "film.txt";
            basepath = "film/";
            Film affichefilm;
            affichefilm.Mediatheque::afficher(path);
            cout << "============ SUPPRESSION FILM ============" << endl;
            do
            {
                cout << "Saisir l'identifiant de la notice a supprimer (4 chiffres) : " << endl;
                cin >> id;
            }
            while ( id < 1000 || id > 10000 );
            Film noticesupp;
            noticesupp.Mediatheque::supprimer(path, basepath, id);
            break;
        }
        case RECHERCHER:
        {
            string titre;
            int id;
            string path;
            path = CHEMIN_FILM;
            Film film;
            cout << "============ RECHERCHE LIVRE ============" << endl;
            cout << "Saisir le titre rechercher : ";

            do
            {
                cin.ignore(); // Pour supprimer les entrées précedentes
                getline(cin, titre);
            }
            while ( titre.empty() );

            do
            {
                cout << "Saisir l'ID rechercher : ";
                cin >> id;
                if (id < 1000 && id >= 10000)
                {
                    cout << "L'ID doit être un nombre de 4 chiffres entre 1000 et 9999.\n";
                }
            }
            while ( id < 1000 || id >= 10000 );
            string idstr = to_string(id); // Pour changer le type int en string
            vector <string> element = {titre, idstr}; // Les éléments sont placés dans un vecteur
            vector <string> fichier; // Les éléments sont placés dans un vecteur
            fichier.empty();
            film.chargementdata(path, fichier);
            film.rechercher(fichier, element, path);
            break;
        }
        case AFFICHER:
        {
            const string path = CHEMIN_FILM;
            Film affichefilm;
            affichefilm.Mediatheque::afficher(path);
            break;
        }

        case MODIFIER:
        {
            const string path = CHEMIN_FILM;
            string basepath = "./";
            string to_update;
            string upwd;
            int choix_update;
            Film updatefilm;

            cout << "============ MODIFIER NOTICE  ============" << endl;
            cout << endl;
            cout << TITRE_FILM << " - Titre" << endl;
            cout << PRODUCTEUR_FILM << " - Producteur" << endl;
            cout << REALISATEUR_FILM << " - Realisateur" << endl;
            cout << IDENTIFIANT_FILM << " - ID" << endl;
            cout << RETOUR_MODIF_FILM << " - Retour menu gestion FILM  " << endl;
            cout << "Saisir l'attribut a modifier : ";
            cin >> choix_update;
            cout << endl;

            if ( choix_update != RETOUR_MODIF_FILM )
            {
                cout << "Liste des films : " << endl;
                updatefilm.Mediatheque::afficher(path);
                cout << endl;
            }


            switch (choix_update)
            {
            case TITRE_FILM:
            {
                cout << endl;
                cout << "Saisir le titre a modifier : " << endl;
                cin >> to_update;
                cout << endl;
                cout << "Saisir le nouveau titre : " << endl;
                cin >> upwd;

                updatefilm.Mediatheque::modifier(path, basepath, to_update, upwd);
                break;
            }
            case PRODUCTEUR_FILM:
            {
                cout << endl;
                cout << "Saisir le producteur a modifier : " << endl;
                cin >> to_update;
                cout << endl;
                cout << "Saisir le nouveau producteur : " << endl;
                cin >> upwd;

                updatefilm.Mediatheque::modifier(path, basepath, to_update, upwd);
                break;
            }
            case REALISATEUR_FILM:
            {
                cout << endl;
                cout << "Saisir le realisateur a modifier : " << endl;
                cin >> to_update;
                cout << endl;
                cout << "Saisir le realisateur : " << endl;
                cin >> upwd;

                updatefilm.Mediatheque::modifier(path, basepath, to_update, upwd);
                break;
            }
            case IDENTIFIANT_FILM:
            {
                int to_update_id;
                int update_id;

                cout << endl;
                do
                {
                    cout << "Saisir l'ID a modifier : " << endl;
                    cin >> to_update_id;
                }
                while ( to_update_id < 1000 || to_update_id > 10000 );

                cout << endl;
                do
                {
                    cout << "Saisir le nouvel ID : " << endl;
                    cin >> update_id;
                }
                while ( update_id < 1000 || update_id > 10000 );

                to_update = to_string(to_update_id);
                upwd = to_string(update_id);
                updatefilm.Mediatheque::modifier(path, basepath, to_update, upwd);
                break;
            }
            case RETOUR_MODIF_FILM:
            {
                break;
            }
            default:
                break;
            }
        }
        case RETOUR:
        {
            break;
        }
        default:
            cerr << "Option invalide." << endl;
            break;
        }
    }
    while (choixfilm != RETOUR);
}
