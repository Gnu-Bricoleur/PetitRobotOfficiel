#include "machineetat.h"

void InitMachineEtat()
{
  EtatCourant = 0;
  EtatComplete = false;

  Actions[0] = 'A';
  Param[0] = 100;
}



void MachineEtat()
{
  char Action = Actions[EtatCourant];
  switch(Action)
  {
    case 'A':
      Consigne = Param[EtatCourant];
      RouleDroit();
      break;
    case 'T':
      Consigne = Param[EtatCourant];
      Tourne();
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
