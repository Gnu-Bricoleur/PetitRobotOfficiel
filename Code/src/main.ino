#include "Arduino.h"
#include "define.h"
#include "moteurs.h"
#include "actionneur.h"
#include "assert.h"
#include "machineetat.h"
#include "orphelins.h"


void setup()
{
  //Initialisations des différentes variables
  InitAsssert();
  InitMoteur();
  InitActionneurs();
  InitMachineEtat();
  InitOrphelins();
  //TestMoteurs();
  //Le robot peut demarrer
  Serial.begin(115200);
  Serial.println("Fin des initialisations !");
}


void loop()
{
  while(Tirette)
  {
    Serial.println("Tirette enclenchée, en attente du début du match ...");
    CheckTirette();
  }

  //Check obstacle
  CheckObstacle();

  //Check temps ecoule
  if (millis() - TempsDebut > 91000)
  {
    timer.disable(TimerId);
    JoueFunnyAction();
    while(true)
    {
      // Fin du match, boucle infinie
      RaZErreur();
      StopMoteur();
    }
  }

  //Machine d'état
  MachineEtat();

  //Assert PeriodiqueAssert
  timer.run();


}
