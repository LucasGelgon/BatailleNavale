#include "CGui.h"

void testConstructeur1EtAccesseurs() ;
void testConstructeur2EtAccesseurs() ;
void testDestructeur() ;
void testSetArmadaCoups() ;
void testPositionnerBateaux() ;
void testChoisirAttaque() ;
void testAfficheGagne() ;
void testAffichePerdu() ;
void testOperator() ;
void testRemplirDeuxGrilles() ;
void testAfficherLaGrille() ;

int main() {
    cout << "\n *** Test de la classe CGui ***" << endl;
    testConstructeur1EtAccesseurs();
    testConstructeur2EtAccesseurs();
    testDestructeur();
    testSetArmadaCoups();
    testPositionnerBateaux();
    testChoisirAttaque();
    testAfficheGagne();
    testAffichePerdu();
    testOperator();
    testRemplirDeuxGrilles();
    testAfficherLaGrille();
    return 0;
}

void testConstructeur1EtAccesseurs() {
    cout << "\n *** Test du constructeur par défaut ***" << endl ;
  
    // Cas normal
    CGui gui1 ;
    cout << "Test cas normal:" << endl ;
    cout << "Pointeurs attendus NULL - test de la grille:" << endl ;
    gui1.afficherLaGrille(cout, "joueur") ;
    
    cout << "Cas limite déjà testé dans le cas normal pour le constructeur par défaut" << endl ;
    cout << "Pas de cas d'erreur pour le constructeur par défaut" << endl ;
}

void testConstructeur2EtAccesseurs() {
    cout << "\n *** Test du constructeur avec paramètres ***" << endl ;
   
    // Cas normal
    CArmada* armada = new CArmada() ;
    CCoups* coups = new CCoups() ;
    CGui gui(armada, coups) ;
    cout << "Test cas normal:" << endl ;
    cout << "Construction avec pointeurs valides - test de la grille:" << endl ;
    gui.afficherLaGrille(cout, "joueur") ;
    
    // Cas limite 
    CGui gui2(nullptr, nullptr) ;
    cout << "\nTest cas limite:" << endl ;
    cout << "Construction avec pointeurs NULL" << endl ;
    gui2.afficherLaGrille(cout, "joueur") ; 
    
    delete armada ;
    delete coups ;
}

void testDestructeur() {
    cout << "\n *** Test du destructeur ***" << endl ;
  
    // Cas normal
    cout << "Test cas normal:" << endl ;
    CArmada* armada = new CArmada() ;
    CCoups* coups = new CCoups() ;
    CGui* gui = new CGui(armada, coups) ;
    delete gui ;
    cout << "Destruction réussie" << endl ;

    // Cas limite
    cout << "\nTest cas limite:" << endl ;
    CGui* gui2 = new CGui() ;
    delete gui2 ;
    cout << "Destruction avec pointeurs NULL réussie" << endl ;
}

void testSetArmadaCoups() {
    cout << "\n *** Test de setArmadaCoups ***" << endl ;
  
    // Cas normal
    CGui gui ;
    CArmada* armada = new CArmada() ;
    CCoups* coups = new CCoups() ; 
    cout << "Test cas normal:" << endl ;
    gui.setArmadaCoups(armada, coups) ;
    cout << "Modification réussie - test :" << endl ;
    gui.afficherLaGrille(cout, "joueur") ;

    // Cas limite
    cout << "\nTest cas limite:" << endl ;
    gui.setArmadaCoups(nullptr, nullptr) ;
    cout << "Modification avec pointeurs NULL réussie" << endl ;
    
    delete armada;
    delete coups;
}

void testPositionnerBateaux() {
    cout << "\n *** Test de positionnerBateaux ***" << endl ;
  
    // Cas normal
    CArmada* armada = new CArmada() ;
    CCoups* coups = new CCoups() ;
    CGui gui(armada, coups) ;
    cout << "Test cas normal:" << endl ;
    armada->getArmadaFromFile() ; 
    bool resultat = gui.positionnerBateaux() ;
    cout << "Positionnement réussi: " << resultat << endl ;
    gui.afficherLaGrille(cout, "joueur") ;

    // Cas limite
    cout << "\nTest cas limite:" << endl ;
    CGui gui2(nullptr, nullptr) ;
    cout << "Positionnement avec armada NULL: false" << endl ; // On sait que ça va échouter

    delete armada ;
    delete coups ;
}

void testChoisirAttaque() {
    cout << "\n *** Test de choisirAttaque ***" << endl ;
  
    // Cas normal
    CGui gui ;
    cout << "Test cas normal:" << endl ;
    cout << "Veuillez entrer des coordonnées valides " << endl ;
    pair<int,int> coord = gui.choisirAttaque() ;
    cout << "Coordonnées saisies: (" << coord.first << "," << coord.second << ")" << endl ;

    // Cas limite
    cout << "\nTest cas limite:" << endl ;
    cout << "Veuillez entrer des coordonnées aux limites (exemple: 0 0 ou 9 9)" << endl ;
    coord = gui.choisirAttaque() ;
    cout << "Coordonnées saisies: (" << coord.first << "," << coord.second << ")" << endl ;

    // Cas d'erreur
    cout << "\nTest cas d'erreur:" << endl ;
    cout << "Veuillez entrer des coordonnées invalides" << endl ;
    coord = gui.choisirAttaque() ;
    cout << "Coordonnées retournées: (" << coord.first << "," << coord.second << ")" << endl ;
}

void testAfficheGagne() {
    cout << "\n *** Test de afficheGagne ***" << endl ;
  
    // Cas normal
    CGui gui ;
    cout << "Test cas normal:" << endl ;
    gui.afficheGagne() ;
}

void testAffichePerdu() {
    cout << "\n *** Test de affichePerdu ***" << endl ;
  
    // Cas normal
    CGui gui ;
    cout << "Test cas normal:" << endl ;
    gui.affichePerdu() ;
}

void testOperator() {
    cout << "\n *** Test de l'opérateur << ***" << endl ;
  
    // Cas normal
    CArmada* armada = new CArmada() ;
    CCoups* coups = new CCoups() ;
    CGui gui(armada, coups) ;
    cout << "Test cas normal:" << endl ;
    cout << gui << endl ;

    // Cas limite
    CGui gui2 ;
    cout << "\nTest cas limite:" << endl ;
    cout << "Affichage avec pointeurs NULL:" << endl ;
    cout << gui2 << endl ;

    delete armada ;
    delete coups ;
}

void testRemplirDeuxGrilles() {
    cout << "\n *** Test de remplirDeuxGrilles ***" << endl ;
  
    // Cas normal
    CArmada* armada = new CArmada() ;
    CCoups* coups = new CCoups() ;
    CGui gui(armada, coups) ;
    cout << "Test cas normal:" << endl ;
    armada->getArmadaFromFile() ;
    gui.positionnerBateaux() ;
    gui.remplirDeuxGrilles(cout) ;

    // Cas limite
    CGui gui2;
    cout << "\nTest cas limite:" << endl ;
    cout << "Remplissage avec pointeurs NULL:" << endl ;
    gui2.remplirDeuxGrilles(cout) ;

    delete armada ;
    delete coups ;
}

void testAfficherLaGrille() {
    cout << "\n *** Test de afficherLaGrille ***" << endl ;
  
    // Cas normal
    CArmada* armada = new CArmada() ; 
    CCoups* coups = new CCoups() ;
    CGui gui(armada, coups) ;
    cout << "Test cas normal:" << endl ;
    cout << "Grille joueur:" << endl ;
    gui.afficherLaGrille(cout, "joueur") ;
    cout << "Grille adversaire:" << endl ;
    gui.afficherLaGrille(cout, "adversaire") ;

    // Cas limite
    cout << "\nTest cas limite:" << endl ;
    gui.afficherLaGrille(cout, "invalide") ;

    delete armada ;
    delete coups ;
}