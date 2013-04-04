// Supports PDF d'Ateliers Arduino par www.mon-club-elec.fr
// http://www.mon-club-elec.fr/pmwiki_mon_club_elec/pmwiki.php?n=MAIN.ATELIERS
// par X. HINAULT - tous droits réservés - 2012 - GPLv3

// code : 16. Remarque : utilisation des instructions utilisant des interruptions au sein de la routine d'interruption. 

//--- entete déclarative = déclarer ici variables et constantes globales 

const int OPTO=2; // broche de l'optocoupleur

volatile int compt=0; // variable de comptage volatile
int compt0=0; // variable pour mémoriser dernière valeur

//--- la fonction setup() : exécutée au début et 1 seule fois
void setup() {
  
  Serial.begin(115200); // initialise communication série 
  
  pinMode(OPTO, INPUT); // broche en entrée 
  
  attachInterrupt(0, comptage, RISING); // Attache l'interruption 0 (broche 2) à la fonction
  // RISING : détection sur front montant 
  
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
  
  compt=compt+1; // incrémente variable comptage 

  //Serial.print("Interruption 0 (broche 2) a eu lieu.");
  //Serial.print("Nombre passages = "); 
  //Serial.println(compt); 

} // fin gestion interruption 
