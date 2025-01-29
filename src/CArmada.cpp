#include "CArmada.h"


/**********************************************/

void CArmada :: ajouterBateau ( const CBateau& unBat ) {
    this->m_listeBateaux.push_back(unBat) ;
}

/**********************************************/

CBateau* CArmada::getBateau(int i) {
   CBateau* result = nullptr ;
   if(i >= 0 && (size_t)i < m_listeBateaux.size()) {
       result = &m_listeBateaux[i] ;
   }
   return result ;
}


/**********************************************/

int CArmada :: getEffectifTotal() {
    return m_listeBateaux.size() ;
}

/**********************************************/

int CArmada :: getNbreTotCases() {
    int total = 0 ;
    for(CBateau& bateau : m_listeBateaux) {
        total += bateau.getTaille() ;
    }
    return total ;
}

/**********************************************/

int CArmada :: getEffectif() {
    int vivants = 0 ;
    for(CBateau& bateau : m_listeBateaux) {
        if(!bateau.estCoule()) {
            vivants++ ;
        }
    }
    return vivants ;
}

/**********************************************/

void CArmada::getArmadaFromFile() {
    const char* nomFich = "../ws/flotille.txt" ;
    ifstream fluxIn(nomFich, ios::in) ;
    
    if (!fluxIn) {
        cerr << "Erreur: Impossible d'ouvrir le fichier " << nomFich << endl ;
        return ;
    }

    string ligne;
    while (getline(fluxIn, ligne)) {
        // Ignore les lignes de commentaires
        if (ligne.empty() || ligne[0] == '#') continue ;
        
        istringstream iss(ligne) ;
        string nom ;
        int nombre ;
        int taille ;
        
        // Vérifie que la lecture des 3 valeurs est réussie
        if (iss >> nom >> nombre >> taille) {
            if (nombre > 0 && taille > 0) {
                for (int i = 0; i < nombre; i++) {
                    CBateau bateau(nom, make_pair(0,0), taille) ;
                    ajouterBateau(bateau) ;
                }
            }
        }
    }
    
    fluxIn.close() ;
}

/**********************************************/

bool CArmada::placerAleatoirement() {
    
    bool result = true ;

    if (m_listeBateaux.size() > TAILLE_GRILLE * 2) { 
        result = false ;
    }

    srand(time(NULL)) ;

    for(CBateau& bateau : m_listeBateaux) {
        bool place = false ;
        int essais = 0 ;
       
        while(!place && essais < MAXESSAIS) {
            int maxColonne = TAILLE_GRILLE - bateau.getTaille() ;
            if (maxColonne < 0) {
                result = false ; // Bateau trop grand pour la grille
            } 

            int ligne = rand() % TAILLE_GRILLE ;
            int colonne = rand() % (maxColonne + 1) ;
            bool collision = false ;

            for(CBateau& autre : m_listeBateaux) {
                if(&autre != &bateau && autre.getPosition().first == ligne) {
                    int debut = autre.getPosition().second ;
                    int fin = debut + autre.getTaille() ;
                    if((colonne >= debut && colonne < fin) || 
                       (colonne + bateau.getTaille() > debut && colonne < fin)) {
                        collision = true ;
                        break ;
                    }
                }
            }
           
            if(!collision) {
                bateau.setPosition(ligne, colonne) ;
                place = true ;
            }
            essais++ ;
        }
       
        if(!place) {
            result = false ;
            break ;
        }
    }
    return result;
}