// Supports PDF d'Ateliers Arduino par www.mon-club-elec.fr
// http://www.mon-club-elec.fr/pmwiki_mon_club_elec/pmwiki.php?n=MAIN.ATELIERS
// par X. HINAULT - tous droits réservés - 2012 - GPLv3

// code : 24. Comptage de la fréquence de rotation d'un axe à l'aide d'une interruption externe 

//--- inclusion des librairies 

#include <MsTimer2.h> // inclusion de la librairie Timer2

//--- entete déclarative = déclarer ici variables et constantes globales 

const int LED=2; //declaration constante de broche 

//--- la fonction setup() : exécutée au début et 1 seule fois
void setup() {
  
  pinMode(LED, OUTPUT); //met la broche en sortie 
  
  // initialisation interruption Timer 2
  MsTimer2::set(1000, interruptTimer2); // période 1000ms 
  MsTimer2::start(); // active Timer 2 


} // fin de la fonction setup()

//--- la fonction loop() : exécutée ensuite en boucle sans fin 
void loop() {

  // laissée vide 
  
  
} // fin de la fonction loop()

// fonction appelée lors interruption Timer2
void InterruptTimer2() { // debut de la fonction d'interruption Timer2

  static boolean etatLED=HIGH; // variable statique initialisée à HIGH
  
  digitalWrite(LED, etatLED);
  etatLED=!etatLED; // inverse la variable 
  

} // fin InterruptTimer2() 
