#include "machineetat.h"

void InitMachineEtat()
{
  EtatCourant = 0;
  EtatSuivant = 0;
  EtatComplete = false;
}



void MachineEtat()
{
  char Action = Actions[EtatCourant];
  switch(Action)
  {
    case 'A':
      RouleDroit();
      Consigne = Param[EtatCourant];
      break;
    case 'T':
      Tourne():
      Consigne = Param[EtatCourant];
      break;
    case 'L':
      LassoHaut();
      break;
    case 'B':
      LassoBas();
      break;
  }
  if (EtatComplete == true)
  {
    EtatCourant += 1;
    EtatComplete = false;
  }
}
