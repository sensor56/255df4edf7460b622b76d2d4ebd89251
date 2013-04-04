// Supports PDF d'Ateliers Arduino par www.mon-club-elec.fr
// http://www.mon-club-elec.fr/pmwiki_mon_club_elec/pmwiki.php?n=MAIN.ATELIERS
// par X. HINAULT - tous droits réservés - 2012 - GPLv3

// code : 17. Technique : Remarque sur les capteurs ON/OFF « mécaniques » et les interruptions externes

//--- entete déclarative = déclarer ici variables et constantes globales 

const int BP=2; // broche de l'optocoupleur

volatile int compt=0; // variable de comptage volatile
int compt0=0; // variable pour mémoriser dernière valeur

//--- la fonction setup() : exécutée au début et 1 seule fois
void setup() {
  
  Serial.begin(115200); // initialise communication série 
  
  pinMode(BP, INPUT); // broche en entrée 
  digitalWrite(BP,HIGH); // active le rappel au plus
  
  attachInterrupt(0, comptage, FALLING); // Attache l'interruption 0 (broche 2) à la fonction
  // RISING : détection sur front montant 
  // FALLING : détection sur front descendant 
  
  Serial.println("Arduino OK !") ; // message initial 
  
} // fin de la fonction setup()


//--- la fonction loop() : exécutée ensuite en boucle sans fin 
void loop() {

  // mettre ici le code à exécuter 

  if (compt0!=compt) { // test si la variabla a changé
    Serial.print("Interruption 0 (broche 2) a eu lieu.");
    Serial.print("Nombre passages = "); 
    Serial.println(compt); 
    compt0=compt; // mémorise nouvelle valeur 
  } // fin if 
  
} // fin de la fonction loop()

// fonction appelée lors interruption n°0 (broche 2) 
void comptage() { 
  
  //noInterrupts(); // +/- désactive interruption 
  
  compt=compt+1; // incrémente variable comptage 

  //Serial.print("Interruption 0 (broche 2) a eu lieu.");
  //Serial.print("Nombre passages = "); 
  //Serial.println(compt); 
  
  delay(500); // pause anti-rebond pour éviter double prise en compte... 

  // interrupts(); // +/- réactive interruption 
  
} // fin gestion interruption 
