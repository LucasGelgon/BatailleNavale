#include "CArmada.h"
void testConstructeurEtAccesseurs() ;
void testAjouterBateau() ;
void testGetEffectifTotal() ;
void testGetEffectif() ;
void testGetArmadaFromFile() ; 
void testPlacerAleatoirement() ;



int main() {
   cout << "\n *** Test de la classe CArmada ***" << endl;
    testConstructeurEtAccesseurs();
    testAjouterBateau();
    testGetEffectifTotal();
    testGetEffectif();
    testGetArmadaFromFile(); 
    testPlacerAleatoirement();
    return 0 ;
}

void testConstructeurEtAccesseurs() {
   cout << "\n *** Test du constructeur par défaut ***" << endl ;
  
   // Cas normal
   CArmada armada1 ;
   cout << "Test cas normal:" << endl ;
   cout << "Effectif attendu: 0, obtenu: " << armada1.getEffectifTotal() << endl ;
   cout << "Liste bateaux vide attendue: " << armada1.getBateau(0) << endl ;
   
}

void testAjouterBateau() {
   cout << "\n *** Test de ajouterBateau ***" << endl ;

   // Cas normal
   CArmada armada2 ;
   CBateau bateau1("BateauTest", make_pair(0,0), 2) ;
   armada2.ajouterBateau(bateau1);
   cout << "Test cas normal:" << endl ;
   cout << "Effectif attendu: 1, obtenu: " << armada2.getEffectifTotal() << endl ;

   // Cas limite 
   CBateau bateau2;  // Bateau vide
   armada2.ajouterBateau(bateau2) ;
   cout << "\nTest cas limite:" << endl ;
   cout << "Ajout bateau vide - Effectif: " << armada2.getEffectifTotal() << endl ;
}

void testGetEffectifTotal() {
   cout << "\n *** Test de getEffectifTotal ***" << endl ;
  
   // Cas normal
   CArmada armada3 ;
   CBateau bateau3("Bateau3", make_pair(0,0), 2) ;
   armada3.ajouterBateau(bateau3) ;
   cout << "Test cas normal:" << endl ;
   cout << "Effectif attendu: 1, obtenu: " << armada3.getEffectifTotal() << endl ;
   
   // Cas limite
   CArmada armada4;
   cout << "\nTest cas limite:" << endl ;
   cout << "Armada vide - Effectif: " << armada4.getEffectifTotal() << endl ;
   
}

void testGetEffectif() {
   cout << "\n *** Test de getEffectif ***" << endl ;
  
   // Cas normal - aucun bateau coulé
   CArmada armada5 ;
   CBateau bateau4("Bateau4", make_pair(0,0), 2) ;
   armada5.ajouterBateau(bateau4) ;
   cout << "Test cas normal:" << endl ; 
   cout << "Bateaux non coulés: " << armada5.getEffectif() << endl ;
   
   // Cas limite - tous bateaux coulés
   bateau4.tirAdverse(make_pair(0,0)) ;
   bateau4.tirAdverse(make_pair(0,1)) ;
   cout << "\nTest cas limite:" << endl ;
   cout << "Tous bateaux coulés: " << armada5.getEffectif() << endl ;
   
   // Cas d'erreur - armada vide
   CArmada armada6 ; 
   cout << "\nTest cas d'erreur:" << endl ;
   cout << "Armada vide: " << armada6.getEffectif() << endl ;
   
}

void testGetArmadaFromFile() {
   cout << "\n *** Test de getArmadaFromFile ***" << endl ;
  
   // Cas normal avec fichier existant et valide
   CArmada armada7 ;
   armada7.getArmadaFromFile() ;
   cout << "Test cas normal:" << endl ;
   cout << "Nombre bateaux chargés: " << armada7.getEffectifTotal() << endl ;
   
   // Cas limite - fichier vide
   CArmada armada8 ;
   armada8.getArmadaFromFile() ;  // Modifier flotille.txt pour qu'il soit vide
   cout << "\nTest cas limite:" << endl;
   cout << "Fichier vide - Nombre bateaux: " << armada8.getEffectifTotal() << endl ;
   
   // Cas d'erreur - fichier inexistant ou invalide
   CArmada armada9 ;
   armada9.getArmadaFromFile() ;  // Modifier flotille.txt pour qu'il soit invalide
   cout << "\nTest cas d'erreur:" << endl ;
   cout << "Fichier invalide - Nombre bateaux: " << armada9.getEffectifTotal() << endl ;
}

void testPlacerAleatoirement() {
   cout << "\n *** Test de placerAleatoirement ***" << endl ;
  
   // Cas normal
   CArmada armada10 ;
   armada10.getArmadaFromFile() ;
   cout << "Test cas normal:" << endl ;
   cout << "Placement standard: " << armada10.placerAleatoirement() << endl ;
   
   // Cas limite - un seul bateau
   CArmada armada11 ;
   CBateau bateau("BateauUnique", make_pair(0,0), 2) ;
   armada11.ajouterBateau(bateau) ;
   cout << "\nTest cas limite:" << endl ;
   cout << "Placement un bateau: " << armada11.placerAleatoirement() << endl ;
   
   // Cas d'erreur - trop de bateaux
   CArmada armada12 ;
   for(int i = 0; i < 100; i++) {  // Trop de bateaux, au dessus de la limite max
       CBateau b("BateauTest", make_pair(0,0), 4) ;
       armada12.ajouterBateau(b) ;
   }
   cout << "\nTest cas d'erreur:" << endl ;
   cout << "Placement impossible: " << armada12.placerAleatoirement() << endl ;
   
}