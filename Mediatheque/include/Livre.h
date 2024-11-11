#ifndef LIVRE_H
#define LIVRE_H

#include <Mediatheque.h>


class Livre : public Mediatheque
{
    public:
        Livre();
        Livre(const Livre& other);

    protected:
        string auteur;
        string editeur;
        string donnees;

    private:
        const string nomfichier = livre.txt

};

#endif // LIVRE_H
