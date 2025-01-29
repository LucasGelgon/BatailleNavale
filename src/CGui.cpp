#include "CGui.h"
#include "CCoups.h"
#include "CBaseJeu.h"


// Constructeurs

CGui :: CGui () {
    this->m_pArmada = nullptr ;
    this->m_pCoups = nullptr ;

    for (int i = 0; i < TAILLE_GRILLE-1; i++) {
        for (int j = 0; j < TAILLE_GRILLE-1; j++) {
            this->m_grilleJou[i][j] = ' ' ; 
            this->m_grilleAdv[i][j] = ' ' ;
        }
    }
}

CGui :: CGui ( CArmada* pArmada, CCoups* pCoups ) {
    this->m_pArmada = pArmada ;
    this->m_pCoups = pCoups ;

    for (int i = 0; i < TAILLE_GRILLE-1; i++) {
        for (int j = 0; j < TAILLE_GRILLE-1; j++) {
            this->m_grilleJou[i][j] = ' ' ;
            this->m_grilleAdv[i][j] = ' ' ;
        }
    }
}

// Méthodes

/**********************************************/

void CGui :: setArmadaCoups ( CArmada* pArmada, CCoups* pCoups ) {
    this->m_pArmada = pArmada ;
    this->m_pCoups = pCoups ;
}

/**********************************************/

bool CGui :: positionnerBateaux() {
    bool result ;
    result = this->m_pArmada->placerAleatoirement() ;
    return result ; // Renvoie false si le placement a échoué
}

/**********************************************/

pair<int, int> CGui::choisirAttaque() {
    pair<int, int> result ; 
    char ligne[10] ; 
    char colonne[10] ;
    int ligneNum ;
    int colonneNum ;
    
    cout << "Saisir les coordonnées de l'attaque" << endl ;
    cout << "Ligne (0-9): " << endl ;
    cin.getline(ligne, 2) ;
    cout << "Colonne (0-9):" << endl ;
    cin.getline(colonne, 2) ;

    // Si ce ne sont pas des chiffres, retourner coordonnées par défaut
    if (!isdigit(ligne[0]) || !isdigit(colonne[0])) {
        result = make_pair(0, 0) ; 
    } else {

        ligneNum = ligne[0] - '0' ;
        colonneNum = colonne[0] - '0' ;

        if (ligneNum < 0 || ligneNum >= TAILLE_GRILLE-1 || colonneNum < 0 || colonneNum >= TAILLE_GRILLE-1) {
            result = make_pair(0, 0) ;  // Valeur par défaut si hors grille
        } else {
            result = make_pair(ligneNum, colonneNum) ;  // Valeurs valides
        }
    }

    return result ;
}

/**********************************************/

void CGui :: afficheGagne() {
    cout << "La partie est gagnée !" << endl ;
}

/**********************************************/

void CGui :: affichePerdu() {
    cout << "La partie est perdue !" << endl ;
}

/**********************************************/

ostream& operator<<( ostream& os, CGui& theG ) {
    theG.remplirDeuxGrilles(os) ;
    return os ;
}

/**********************************************/

void CGui::remplirDeuxGrilles(ostream& os) {

    // Initalisation des grilles
    for (int i = 0; i < TAILLE_GRILLE-1; i++) {
        for (int j = 0; j < TAILLE_GRILLE-1; j++) {
            this->m_grilleJou[i][j] = '-' ;
            this->m_grilleAdv[i][j] = '-' ;
        }
    }

    if (this->m_pArmada != nullptr) {
        for (int i = 0; i < this->m_pArmada->getEffectifTotal(); i++) {
            CBateau* bateau = this->m_pArmada->getBateau(i) ;
            if (bateau != nullptr) {
                pair<int,int> pos = bateau->getPosition() ;
                if (pos.first >= 0 && pos.first < TAILLE_GRILLE-1) {
                    for (int j = 0; j < bateau->getTaille() && pos.second + j < TAILLE_GRILLE-1; j++) {
                        // Si la case détruite ou pas
                        if (bateau->getDegats(j)) {
                            this->m_grilleJou[pos.first][pos.second + j] = 'X' ;
                        } else {
                            this->m_grilleJou[pos.first][pos.second + j] = 'B' ;
                        }
                    }
                }
            }
        }
    }

    // Tir adverses dans la grille du joueur
    if (this->m_pCoups != nullptr) {
        int nbPloufs = this->m_pCoups->getTaille("ploufAdverse") ;
        for (int i = 0; i < nbPloufs; i++) {
            pair<int,int> pos = this->m_pCoups->getPair("ploufAdverse", i) ;
            if (pos.first >= 0 && pos.first < TAILLE_GRILLE-1 && pos.second >= 0 && pos.second < TAILLE_GRILLE-1) {
                this->m_grilleJou[pos.first][pos.second] = 'O' ;
            }
        }
    }

    // Affichage grille joueur
    afficherLaGrille(os, "joueur");

    // Tirs du joueur dans la grille adverse
    if (this->m_pCoups != nullptr) {
        // Tirs réussis
        int nbTouches = this->m_pCoups->getTaille("touche") ;
        for (int i = 0; i < nbTouches; i++) {
            pair<int,int> pos = this->m_pCoups->getPair("touche", i) ;
            if (pos.first >= 0 && pos.first < TAILLE_GRILLE-1 && pos.second >= 0 && pos.second < TAILLE_GRILLE-1) {
                this->m_grilleAdv[pos.first][pos.second] = 'X' ;
            }
        }

        // Tirs ratés
        int nbPloufs = this->m_pCoups->getTaille("dansLEau") ;
        for (int i = 0; i < nbPloufs; i++) {
            pair<int,int> pos = this->m_pCoups->getPair("dansLEau", i) ;
            if (pos.first >= 0 && pos.first < TAILLE_GRILLE-1 && pos.second >= 0 && pos.second < TAILLE_GRILLE-1) {
                this->m_grilleAdv[pos.first][pos.second] = 'O' ;
            }
        }
    }

    // Affichage grille adversaire
    afficherLaGrille(os, "adversaire");
}

/**********************************************/

void CGui::afficherLaGrille(ostream& os, string jouOuAdv) {

    os << "\n" << jouOuAdv << " :" ;
    os << "\n  " ;
    
    // Afficher les numéros de colonnes
    for (int i = 0; i < TAILLE_GRILLE-1; i++) {
        os << i << " " ;
    }
    os << endl ;

    // Afficher la grille avec les numéros de lignes
    for (int i = 0; i < TAILLE_GRILLE-1; i++) {
        os << i << " " ;
        for (int j = 0; j < TAILLE_GRILLE-1; j++) {
            if (jouOuAdv == "joueur") {
                os << m_grilleJou[i][j] << " " ;
            } else {
                os << m_grilleAdv[i][j] << " " ;
            }
        }
        os << endl ;
    }
}

/**********************************************/


// Destructeur
CGui :: ~CGui() {
    this->m_pArmada = nullptr ;
    this->m_pCoups = nullptr ;
}