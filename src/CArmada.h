#ifndef CARMADA_H
#define CARMADA_H

#include "BiblioStd.h"
#include "CBateau.h"

class CArmada {

    // Atributs 
    private :
        vector<CBateau> m_listeBateaux;  // la collection de bateaux qui est VIDE au départ

    // Méthodes
    public :
        void ajouterBateau ( const CBateau& unBat ); // Ajoute un bateau dans la structure m_listeBateaux (à la suite avec la méthode push_back de la classe vector)
        CBateau* getBateau ( int i ); // Accesseur : renvoie (par pointeur) le bateau qui se trouve à l'index i dans le tableau (0 <= i < taille)
        int getEffectifTotal(); // Renvoie le nombre total de bateaux de l'armada
        int getNbreTotCases(); // Accesseur : renvoie le nombre total de cases occupées par l'armada
        int getEffectif(); // Renvoie le nombre de bateaux qui ne sont pas encore coulés (flottille encore en vie sur l'eau)
        void getArmadaFromFile(); // Lecture du fichier flotille.txt qui contient la liste complète de tous les bateaux
        bool placerAleatoirement(); // Placement aléatoire ET automatique horizontalement de TOUS les bateaux sur la grille. Renvoie faux si le positionnement automatique a échoué.

    // Destructeur
    ~CArmada() = default;
};

#endif