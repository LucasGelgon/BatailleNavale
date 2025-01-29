#include "CBateau.h"

// Constructeurs
CBateau :: CBateau () {
    this->m_nom = "neant" ;
    this->m_pDegats = nullptr ;
    this->m_taille = 0 ;
    this->m_position = make_pair (0, 0) ;

}

CBateau :: CBateau(string n, pair<int,int> p, int t) {
    this->m_nom = n ;
    this->m_position = p ;
    // Vérifie que la taille n'est pas négative
    if(t < 0) {
       this->m_taille = 0 ;
       this->m_pDegats = nullptr ;
   } else {
       this->m_taille = t ;
       if(t > 0) {
        // Crée le tableau de dégâts de taille t
           this->m_pDegats = new bool[t] ;
           for(int i = 0; i < t; i++) {
               this->m_pDegats[i] = false ;
           }
       } else {
        // Si t n'est pas supérieur à 0, le tableau de dégâts est nul
           this->m_pDegats = nullptr ;
       }
   }
}

// Méthodes

/**********************************************/

bool CBateau :: getDegats ( int i ) {
    bool result = false ;
    // On regarde si la case numéro i du bateau est touchée
    if  ((0 <= i) && (i < this->m_taille) && ( this->m_pDegats != nullptr)) {
        result = this->m_pDegats[i] ;
    }
    return result ; 
}

/**********************************************/

string CBateau :: getNom() {
    return this->m_nom ;
}

/**********************************************/

int CBateau :: getTaille() {
    return this->m_taille ;
}

/**********************************************/

pair<int,int> CBateau :: getPosition() {
    return this->m_position ;
}

/**********************************************/

void CBateau::setPosition(int i, int j) {
    // On vérifie que la nouvelle position soit bien dans la grille
    if(i >= 0 && i < TAILLE_GRILLE-1 && j >= 0 && j < TAILLE_GRILLE-1 
       && j + m_taille <= TAILLE_GRILLE-1) {
        this->m_position = make_pair(i, j) ;
    } else {
        // On garde l'ancienne position si la nouvelle n'est pas valide
        this->m_position = this->m_position ; 
    }
}

/**********************************************/

bool CBateau :: estCoule() {
    bool result = false ;
    if(this->m_pDegats != nullptr && this->m_taille != 0) {
        result = true ; // On présume que le bateau est coulé jusqu'à preuve du contraire
        for(int i = 0; i < m_taille; i++) {
            if(!this->m_pDegats[i]) { 
                result = false ; // Si la case était déjà touchée, il faut renvoyer faux
                break ;
            }
        }
    }
    
    return result ;
}

/**********************************************/

bool CBateau::tirAdverse(pair<int,int> p) {

   bool result = false ;
   
   if(this->m_pDegats != nullptr && p.first == this->m_position.first) {
       int relativePos = p.second - this->m_position.second ;
       if(relativePos >= 0 && relativePos < this->m_taille && !this->m_pDegats[relativePos]) {
           this->m_pDegats[relativePos] = true ;
           result = true ;
       }
   }
   
   return result ;
}

/**********************************************/

ostream& operator<<( ostream& os, CBateau& theB ) {
    os << "Nom\t:" << theB.m_nom << endl ;
    os << "Taille\t:" << theB.m_taille << endl ;
    os << "Degats:\t" ;
    for(int i = 0; i < theB.m_taille; i++) {
        os << theB.m_pDegats[i] << " " ;
    }
    os << endl ;
    os << "Position\t:" << theB.m_position.first << ", " << theB.m_position.second << endl ;
    return os ;
}

/**********************************************/

// Copy-constructeur
CBateau::CBateau(const CBateau& other) {
    this->m_nom = other.m_nom ;
    this->m_position = other.m_position ;
    this->m_taille = other.m_taille ;
    
    if (other.m_pDegats != nullptr && other.m_taille > 0) {
        this->m_pDegats = new bool[other.m_taille] ;
        for (int i = 0; i < other.m_taille; i++) {
            this->m_pDegats[i] = other.m_pDegats[i] ;
        }
    } else {
        this->m_pDegats = nullptr ;
    }
}

/**********************************************/

// Opérateur d'affectation
CBateau& CBateau::operator=(const CBateau& other) {
    if (this != &other) { 
        delete[] this->m_pDegats ; 
        
        this->m_nom = other.m_nom;
        this->m_position = other.m_position ;
        this->m_taille = other.m_taille ;
        
        if (other.m_pDegats != nullptr && other.m_taille > 0) {
            this->m_pDegats = new bool[other.m_taille] ;
            for (int i = 0; i < other.m_taille; i++) {
                this->m_pDegats[i] = other.m_pDegats[i] ;
            }
        } else {
            this->m_pDegats = nullptr ;
        }
    }
    return *this ;
}

/**********************************************/


// Destructeur
CBateau::~CBateau() {
    delete[] this->m_pDegats ;
}
