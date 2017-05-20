#include "machineetat.h"

void InitMachineEtat()
{
  EtatCourant = 0;
  EtatComplete = false;

  Actions[0] = 'A';//Avance
  Param[0] = 1000;
//  Actions[1] = 'L';//Leve le bras
//  Actions[2] = 'F';//funny action
  Actions[3] = 'E';// end of the line

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
    case 'F':
      JoueFunnyAction();
      break;
    case 'E':
      Serial.println("fin des Actions");
      break;
  }
  if (EtatComplete == true)
  {
    EtatCourant += 1;
    EtatComplete = false;
    Serial.println("fin de l'état");
    Serial3.print("R\n"); // Reset de la carte codeuse
  }
}
