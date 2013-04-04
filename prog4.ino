// Supports PDF d'Ateliers Arduino par www.mon-club-elec.fr
// http://www.mon-club-elec.fr/pmwiki_mon_club_elec/pmwiki.php?n=MAIN.ATELIERS
// par X. HINAULT - tous droits réservés - 2012 - GPLv3

// code : 20. Comptage de la fréquence de rotation d'un axe à l'aide d'une interruption externe

//--- entete déclarative = déclarer ici variables et constantes globales 

const int OPTO=2; // broche de l'optocoupleur

volatile int compt=0; // variable de comptage volatile
int compt0=0; // variable pour mémoriser dernière valeur

long millis0=0; // variable mémorisation valeur millis()
int delai=10000; // délai de comptage en millisecondes

//--- la fonction setup() : exécutée au début et 1 seule fois
void setup() {
  
  Serial.begin(115200); // initialise communication série 
  
  pinMode(OPTO, INPUT); // broche en entrée 
  //digitalWrite(OPTO, HIGH); // rappel au plus
  
  attachInterrupt(0, comptage,FALLING); // Attache l'interruption 0 (broche 2) à la fonction
  // RISING : détection sur front montant 
  // FALLING : détection sur front descendant 
  
  millis0=millis(); // initialise la valeur de millis
  
  Serial.println("Arduino OK !") ; // message initial 
  
} // fin de la fonction setup()

//--- la fonction loop() : exécutée ensuite en boucle sans fin 
void loop() {

  // mettre ici le code à exécuter 
  
  if (millis()-millis0>delai) { // si le delai s'est écoulé
    compt0=compt; // mémorise comptage actuel
    millis0=millis() ; // réinitialise millis0
    compt=0; // réinitialise comptage 
    
    Serial.print("Delai ecoule.Comptage="); 
    Serial.print(compt0); 
    Serial.print(" soit "); 
    Serial.print(compt0/2); 
    Serial.print(" tours en 10 secondes"); 
    Serial.print(" soit "); 
    Serial.print(compt0*3); 
    Serial.println(" tours par minute"); 
    
  } // fin si delai écoulé 

} // fin de la fonction loop()

// fonction appelée lors interruption n°0 (broche 2) 
void comptage() { 
  
  compt=compt+1; // incrémente variable comptage 

} // fin gestion interruption   

