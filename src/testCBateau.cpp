#include "CBateau.h"
void testConstructeur1EtAccesseurs() ;
void testConstructeur2EtAccesseurs() ;
void testGetDegats() ;
void testSetPosition() ;
void testEstCoule() ;
void testTirAdverse() ;
void testOperator() ;


int main() {
    cout << "\n *** Test de la classe CBateau ***" << endl;
    testConstructeur1EtAccesseurs();
    testConstructeur2EtAccesseurs();
    testGetDegats();
    testSetPosition();
    testEstCoule();
    testTirAdverse();
    testOperator();
    return 0; 
}

void testConstructeur1EtAccesseurs() {
   cout << "\n *** Test du constructeur par défaut et accesseurs ***" << endl ;
   
   // Cas normal
   CBateau* bateau1 = new CBateau() ;
   string nom1 = bateau1->getNom() ;
   int taille1 = bateau1->getTaille() ;
   pair<int,int> pos1 = bateau1->getPosition() ;
   
   cout << "Test cas normal:" << endl ;
   cout << "Nom attendu: 'neant', obtenu: '" << nom1 << "'" << endl ; 
   cout << "Taille attendue: 0, obtenue: " << taille1 << endl ;
   cout << "Position attendue: (0,0), obtenue: (" << pos1.first << "," << pos1.second << ")" << endl ;
   
   // Vérification des valeurs 
   if (nom1 == "neant" && taille1 == 0 && pos1.first == 0 && pos1.second == 0) {
       cout << "Test constructeur par défaut: OK" << endl ;
   } else {
       cout << "Test constructeur par défaut: ERREUR" << endl ;
   }
   
   delete bateau1 ;
}

void testConstructeur2EtAccesseurs() {
   cout << "\n *** Test du constructeur avec paramètres ***" << endl ;
   
   // Cas normal
   pair<int,int> pos(5,2) ;
   CBateau* bateau2 = new CBateau("BateauLucas", pos, 3) ;
   
   cout << "Test cas normal:" << endl ;
   cout << "Nom attendu: 'BateauLucas', obtenu: '" << bateau2->getNom() << "'" << endl ;
   cout << "Taille attendue: 3, obtenue: " << bateau2->getTaille() << endl ;
   cout << "Position attendue: (5,2), obtenue: (" << bateau2->getPosition().first << "," << bateau2->getPosition().second << ")" << endl ;
   
   // Cas limite: taille = 0
   CBateau* bateau3 = new CBateau("TestLimite", pos, 0) ;
   cout << "\nTest cas limite (taille 0):" << endl ;
   cout << "Taille obtenue: " << bateau3->getTaille() << endl ;

   // Cas d'erreur: taille = -1
   CBateau* bateau4 = new CBateau("TestErreur", pos, -1) ;
   cout << "\nTest cas d'erreur (taille négative):" << endl ;
   cout << "Taille obtenue (forcée à 0): " << bateau3->getTaille() << endl ;
   
   delete bateau2 ;
   delete bateau3 ;
   delete bateau4 ;
}

void testGetDegats() {
   cout << "\n *** Test de getDegats ***" << endl ;
  
   // Cas normal
   pair<int,int> pos(5,2) ;
   CBateau* bateau5 = new CBateau("BateauTest", pos, 3) ;
   
   cout << "Test cas normal:" << endl ;
   bateau5->tirAdverse(pos) ;
   cout << "Dégâts attendus position touchée: " << bateau5->getDegats(0) << endl ;
  
   // Cas limite
   cout << "\nTest cas limite:" << endl ; 
   cout << "Dernière case (index 2): " << bateau5->getDegats(2) << endl ;
  
   // Cas d'erreur
   cout << "\nTest cas d'erreur:" << endl ;
   cout << "Index négatif: " << bateau5->getDegats(-1) << endl ;
   cout << "Index trop grand: " << bateau5->getDegats(3) << endl ;
  
   delete bateau5 ;
}

void testSetPosition() {
   cout << "\n *** Test de setPosition ***" << endl ;

   CBateau* bateau6 = new CBateau("BateauTest", make_pair(0,0), 2);
  
   // Cas normal
   bateau6->setPosition(5, 5) ;
   cout << "Test cas normal:" << endl ;
   cout << "Position obtenue: (" << bateau6->getPosition().first << "," << bateau6->getPosition().second << ")" << endl ;

   // Cas limite  
   bateau6->setPosition(5, 8) ; // Un bateau de taille 2 à la position 8 atteindrait le bord
   cout << "\nTest cas limite:" << endl ;
   cout << "Position aux bords: (" << bateau6->getPosition().first << "," << bateau6->getPosition().second << ")" << endl ;

   // Cas d'erreur
   bateau6->setPosition(-1, -1);
   cout << "\nTest cas d'erreur:" << endl;
   cout << "Position conservée après erreur: (" << bateau6->getPosition().first << "," << bateau6->getPosition().second << ")" << endl;
   
   delete bateau6 ;
}

void testEstCoule() {
   cout << "\n *** Test de estCoule ***" << endl ;
  
   // Cas normal
   CBateau* bateau7 = new CBateau("BateauTest", make_pair(0,0), 2) ;
   cout << "Test cas normal:" << endl ;
   cout << "Bateau neuf: " << bateau7->estCoule() << endl ;
   bateau7->tirAdverse(make_pair(0,0)) ;
   bateau7->tirAdverse(make_pair(0,1)) ;
   cout << "Bateau coulé: " << bateau7->estCoule() << endl ;

   // Cas limite
   CBateau* bateau8 = new CBateau("BateauLimite", make_pair(0,0), 1) ;
   cout << "\nTest cas limite:" << endl ;
   cout << "Bateau taille 1: " << bateau8->estCoule() << endl ;

   // Cas d'erreur 
   CBateau* bateau9 = new CBateau("BateauErreur", make_pair(0,0), 0) ;
   cout << "\nTest cas d'erreur:" << endl ;
   cout << "Bateau taille 0: " << bateau9->estCoule() << endl ;

   delete bateau7 ;
   delete bateau8 ;
   delete bateau9 ;
}

void testTirAdverse() {
   cout << "\n *** Test de tirAdverse ***" << endl ;
  
   // Cas normal
   CBateau* bateau10 = new CBateau("BateauTest", make_pair(0,0), 3) ;
   cout << "Test cas normal:" << endl ;
   cout << "Premier tir: " << bateau10->tirAdverse(make_pair(0,0)) << endl ;
   cout << "Deuxième tir même position: " << bateau10->tirAdverse(make_pair(0,0)) << endl ;
  
   // Cas limite
   cout << "\nTest cas limite:" << endl ;
   cout << "Tir dernière case: " << bateau10->tirAdverse(make_pair(0,2)) << endl ;
  
   // Cas d'erreur
   cout << "\nTest cas d'erreur:" << endl ;
   cout << "Tir hors bateau: " << bateau10->tirAdverse(make_pair(1,0)) << endl ;
   cout << "Tir position négative: " << bateau10->tirAdverse(make_pair(-1,-1)) << endl ;
  
   delete bateau10 ;
}

void testOperator () {
   cout << "\n *** Test de operator<< ***" << endl ;

   CBateau bateau11("BateauOperator", make_pair(2,2), 5) ;
   bateau11.tirAdverse(make_pair(2,2)) ;
   cout << bateau11 << endl ;

}



