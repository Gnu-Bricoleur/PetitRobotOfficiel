#include "machineetat.h"

void InitMachineEtat()
{
  EtatCourant = 0;
  EtatComplete = false;
}


void InitActions()
{
  if (Bleu == true)
  {

//    Actions[0] = 'A';//Avance
//    Param[0] = 30;
//    Vitesse[0] = 200;
//    Actions[1] = 'A';//Avance
//    Param[1] = 10;
//    Vitesse[1] = 100;
  //  Actions[1] = 'L';//Leve le bras
  //  Actions[2] = 'F';//funny action
    Actions[0] = 'E';// end of the line
    Serial.println("Blue side !");
  }
  else
  {
//    Actions[0] = 'A';//Avance
//    Param[0] = 30; //Distance
//    Vitesse[0] = 200;
//    Actions[1] = 'A';//Avance
//    Param[1] = 2;
//    Vitesse[1] = 100;
  //  Actions[1] = 'L';//Leve le bras
  //  Actions[2] = 'F';//funny action
    Actions[0] = 'E';// end of the line
    Serial.println("Yellow side !");
  }
}


void MachineEtat()
{
  Consigne = Param[EtatCourant];
  char Action = Actions[EtatCourant];
  switch(Action)
  {
    case 'A':                         //Avancer
      RouleDroit();
      break;
    case 'T':
      Tourne();
      break;
    case 'L':
      LassoHaut();
      break;
    case 'B':
      LassoBas();
      break;
    case 'W':
      Attente();
      break;
    case 'E':                           // End
      // On ne fait rien et on boucle en attendant la fin du match
      // Fin des actions
      break;
    default:
      EtatComplete = true;
      break;
  }
  if (EtatComplete == true)
  {
    EtatCourant += 1;
    EtatComplete = false;
    Serial.println("Fin de l'état");
    Serial3.print("R\n"); // Reset de la carte codeuse
  }
}
