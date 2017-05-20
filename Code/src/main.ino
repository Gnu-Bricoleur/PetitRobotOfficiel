#include "Arduino.h"
#include "define.h"
#include "moteurs.h"
#include "actionneur.h"
#include "assert.h"
#include "machineetat.h"
#include "orphelins.h"


void setup()
{
  AsssertIni();
  InitMoteur();
  InitActionneurs();
  InitMachineEtat();
  Tirette = true;
  Serial.begin(9600);
  Serial.println("Fin des initialisations !");
}
void loop()
{
  while(Tirette)
  {
    CheckTirette();
    Serial.println("Tirette enclenchée, en attente du début du match !");
  }

  //Check obstacle

  //Check temps ecoule
  if (millis() - TempsDebut > 90000)
  {
    JoueFunnyAction();
    while(true)
    {
      // Fin du match, boucle infinie
      Serial.println("Fin du match !");
    }
  }

  //Machine d'état
  MachineEtat();

  //update assert

  //Pour tests
  //MoteurDroitTourne(true, 100);
  //MoteurGaucheTourne(true, 100);
}
