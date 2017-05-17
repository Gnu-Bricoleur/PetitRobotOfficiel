#include "Arduino.h"
#include "define.h"
#include "moteurs.h"
#include "actionneur.h"
#include "assert.h"
#include "machineetat.h"



void setup()
{
  InitMoteur();
  InitActionneurs();
  InitMachineEtat();
}
void loop()
{
  //Check obstacle

  //Check temps ecoule
  if (millis() > 80000)
  {
    JoueFunnyAction();
    While(true)
    {
      // Fin du match, boucle infinie
    }
  }
  
  //Machine d'état
  MachineEtat();

  //update assert

  //Pour tests


}
