#ifndef CBATEAU_H
#define CBATEAU_H

#include "BiblioStd.h"

class CBateau {

    // Atributs 
    private :
        int m_taille ; // nombre de cases occupées (horizontalement) sur la grille
        string m_nom ; // nom du bateau
        pair<int,int> m_position; // coord. (int ligneHoriz, int colonneVert) du point d'ancrage. m_position.first = le numéro de la ligne horizontale. m_position.second = le numéro de la colonne verticale
        bool* m_pDegats;  // tableau des dégâts de taille m_taille (case à faux si pas de dégât)


    // Constructeurs
    public :
        CBateau() ; // Constructeur par défaut : "neant", (0,0), 0, NULL
        CBateau(string n, pair<int,int> p, int t ); // Constructeur, le bateau n'a encore aucune case touchée (m_pDegats à faux partout)
        CBateau(const CBateau& other); // Copie-Constructeur
        CBateau& operator=(const CBateau& other); // Opérateur d'affectation

    public :
        bool getDegats ( int i ); // Renvoie vrai si la case numéro i du bateau est touchée ( 0 <= i < m_taille )
        string getNom(); // Renvoie le nom du bateau
        int getTaille(); // Renvoie nombre de cases occupées (horizontalement) sur la grille
        pair<int,int> getPosition(); // Renvoie la position du bateau
        void setPosition ( int i, int j ); // Modifie la position du bateau sur la grille en ième ligne, jème colonne (nouveau point d'ancrage)
        bool estCoule(); // Renvoie vrai si le bateau est coulé
        bool tirAdverse ( pair<int,int> p ); // Tir adverse : renvoie vrai si la coordonnée passée en paramètre est un tir victorieux (une case du bateau est touchée). Si le tir est victorieux il doit être marqué dans le tableau m_pDegats.
        friend ostream& operator<< ( ostream& os, CBateau& theB ); // Surcharge de l'opérateur << pour afficher à l'écran les caractéristiques du bateau

    // Destructeur
    ~CBateau();
};

#endif