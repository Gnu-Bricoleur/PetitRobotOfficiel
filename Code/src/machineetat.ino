#include "machineetat.h"

void InitMachineEtat()
{
  EtatCourant = 0;
  EtatComplete = false;

  Actions[0] = 'W';
  Param[0] = 20000;
  Actions[1] = 'A';//Avance
  Param[1] = 3000;
  Vitesse[1] = 200;
  Actions[2] = 'W';
  Param[2] = 2000;
  Actions[3] = 'A';//Avance
  Param[3] = 1000;
  Vitesse[3] = 100;
//  Actions[1] = 'L';//Leve le bras
//  Actions[2] = 'F';//funny action
  Actions[4] = 'E';// end of the line


}


void InitActions()
{
  /*
  if (Bleu == true)
  {
    Actions[0] = 'A';//Avance
    Param[0] = 3000;
    Vitesse[0] = 200;
    Actions[1] = 'A';//Avance
    Param[1] = 1000;
    Vitesse[1] = 100;
  //  Actions[1] = 'L';//Leve le bras
  //  Actions[2] = 'F';//funny action
    Actions[2] = 'E';// end of the line
  }
  else
  {
    Actions[0] = 'A';//Avance
    Param[0] = 3000; //Distance
    Vitesse[0] = 200;
    Actions[1] = 'A';//Avance
    Param[1] = 2000;
    Vitesse[1] = 100;
  //  Actions[1] = 'L';//Leve le bras
  //  Actions[2] = 'F';//funny action
    Actions[2] = 'E';// end of the line
  }
  */
}


void MachineEtat()
{
  char Action = Actions[EtatCourant];
  switch(Action)
  {
    case 'A':                         //Avancer
      Consigne = Param[EtatCourant];
      RouleDroitBO();
      break;
    case 'R':                         // Reculer
      Consigne = Param[EtatCourant];
      ReculeDroitBO();
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
    case 'W':
      Serial.println("Debut Attente");
      delay(Param[EtatCourant]);
      Serial.println(" Fin Attente ");
      EtatComplete = true;
      break;
    case 'F':
      JoueFunnyAction();
      break;
    case 'E':
      //Serial.println("fin des Actions");
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
