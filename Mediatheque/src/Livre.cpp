#include "Livre.h"

Livre::Livre() {}
/** Constructeur herite du constructeur de base de la classe mediatheque avec titre et ID et
ajoute les attributs specifique a la classe interprete et label */
Livre::Livre(const string &titre, int ID, const string &auteur, const string &editeur) : Mediatheque(titre, ID), auteur(auteur), editeur(editeur) {}

void Livre::menulivre()
{
    /// Implementation du menu de la classe fille Livre
    int choixlivre;
    do
    {
        cout << "============ MENU LIVRE ============" << endl;
        cout << AJOUTER << " - Ajout d'une notice " << endl;
        cout << SUPPRIMER << " - Supprimer des notices " << endl;
        cout << RECHERCHER << " - Rechercher des notices " << endl;
        cout << AFFICHER << " - Afficher une notice " << endl;
        cout << MODIFIER << " - Modifier une notice" << endl;
        cout << RETOUR << " - Retour menu principal" << endl;
        cout << "Saisie : ";
        cin >> choixlivre;

        switch (choixlivre)
        {
        case AJOUTER:
        {
            /// D�claration des variables
            string titre, auteur, editeur, data, input, entete;
            int id;

            cout << "============ AJOUT NOTICE ============" << endl;
            cout << "Saisir le titre : ";
            cin >> titre;
            cout << "Saisir le auteur : ";
            cin >> auteur;
            cout << "Saisir le editeur : ";
            cin >> editeur;
            /// Blindage de la variable ID
            do
            {
                cout << "Saisir l'identifiant (4 nombre) : ";
                cin >> id;
            }
            while ( id < 1000 || id >= 10000 );

            const string path = CHEMIN_LIVRE;

            Livre noticelivre(titre, id, auteur, editeur);
            entete = string("Titre") + ";" + "ID" + ";" + "Auteur" + ";" + "Editeur";
            noticelivre.Mediatheque::ajouter(path, entete);
            data = titre + ";" + to_string(id) + ";" + auteur + ";" + editeur;
            noticelivre.Mediatheque::ajouter(path, data);
            break;
        }
        case SUPPRIMER:
        {
            int id;
            string path;
            string basepath;
            path = "livre.txt";
            basepath = "livre/";
            Livre affichelivre;
            affichelivre.Mediatheque::afficher(path); /// Appelle de la m�thode afficher de la class parent Mediatheque
            cout << "============ SUPPRESSION LIVRE ============" << endl;
            do
            {
                cout << "Saisir l'identifiant de la notice a supprimer (4 nombre) : " << endl;
                cin >> id;
            }
            while ( id < 1000 || id >= 10000 );
            Livre noticesupp;
            noticesupp.Mediatheque::supprimer(path, basepath, id); /// Appelle de la m�thode supprimer de la class parent Mediatheque
            break;
        }
        case RECHERCHER:
        {
            string titre;
            int id;
            string path;
            path = CHEMIN_LIVRE;
            Livre recherchelivre;
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
                    cout << "L'ID doit etre un nombre de 4 chiffres entre 1000 et 9999.\n";
                }
            }
            while ( id < 1000 || id >= 10000 );
            string idstr = to_string(id); // Pour changer le type int en string
            vector <string> element = {titre, idstr}; // Les éléments sont placés dans un vecteur
            vector <string> fichier; // Les éléments à m'intérieur du vecteur viennent du fichier
            fichier.empty();
            recherchelivre.chargementdata(path, fichier);
            recherchelivre.rechercher(fichier, element, path);
            break;
        }
        case AFFICHER:
        {
            const string path = CHEMIN_LIVRE;
            Livre affichelivre;
            affichelivre.Mediatheque::afficher(path);
            break;
        }
        case MODIFIER:
        {
            const string path = CHEMIN_LIVRE; // Chemin du fichier d�clar� en MACRO
            string basepath = "./"; // Chemin du dossier dans lequel se trouve le fichier
            string to_update;
            string upwd; // Nouvelle valeur
            int choix_update;
            Livre updatelivre;

            cout << "============ MODIFIER NOTICE  ============" << endl;
            cout << endl;
            cout << TITRE_LIVRE << " - Titre" << endl;
            cout << AUTEUR_LIVRE << " - Auteur" << endl;
            cout << EDITEUR_LIVRE << " - Editeur" << endl;
            cout << IDENTIFIANT_LIVRE << " - ID" << endl;
            cout << RETOUR_MODIF_LIVRE << " - Retour menu gestion Livre " << endl;
            cout << "Saisir l'attribut a modifier : " << endl;
            cin >> choix_update;
            cout << endl;

            /// Blindage de l'affichage au cas o� l'utilisateur sorte du menu
            if (choix_update != RETOUR_MODIF_LIVRE )
            {
                cout << "Liste des livres : " << endl;
                updatelivre.Mediatheque::afficher(path);
                cout << endl;
            }

            switch (choix_update)
            {
            case TITRE_LIVRE:
            {
                cout << endl;
                cout << "Saisir le titre a modifier : " << endl;
                cin >> to_update;
                cout << endl;
                cout << "Saisir le nouveau titre : " << endl;
                cin >> upwd;

                updatelivre.Mediatheque::modifier(path, basepath, to_update, upwd); // Appel de la m�thode pour effectuer la modification des valeurs
                break;
            }
            case AUTEUR_LIVRE:
            {
                cout << endl;
                cout << "Saisir l'auteur a modifier : " << endl;
                cin >> to_update;
                cout << endl;
                cout << "Saisir le nouvel auteur : " << endl;
                cin >> upwd;

                updatelivre.Mediatheque::modifier(path, basepath, to_update, upwd); // Appel de la m�thode pour effectuer la modification des valeurs
                break;
            }
            case EDITEUR_LIVRE:
            {
                cout << endl;
                cout << "Saisir l'editeur a modifier : " << endl;
                cin >> to_update;
                cout << endl;
                cout << "Saisir le nouvel editeur : " << endl;
                cin >> upwd;

                updatelivre.Mediatheque::modifier(path, basepath, to_update, upwd); // Appel de la m�thode pour effectuer la modification des valeurs
                break;
            }
            case IDENTIFIANT_LIVRE:
            {
                int to_update_id;
                int update_id;

                cout << endl;
                do
                {
                    cout << "Saisir l'ID a modifier : " << endl;
                    cin >> to_update_id;
                }
                while ( to_update_id < 1000 || to_update_id >= 10000 );

                do
                {
                    cout << endl;
                    cout << "Saisir le nouvel ID : " << endl;
                    cin >> update_id;
                }
                while ( update_id < 1000 || update_id >= 10000 );

                to_update = to_string(to_update_id);
                upwd = to_string(update_id);

                updatelivre.Mediatheque::modifier(path, basepath, to_update, upwd); // Appel de la methode pour effectuer la modification des valeurs
                break;
            }
            case RETOUR_MODIF_LIVRE:
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
    while (choixlivre != RETOUR);
}
