#include "machineetat.h"

void InitMachineEtat()
{
  EtatCourant = 0;
  EtatComplete = false;
}


void InitActions()      // Vitesse min 40 !!!!!!!!!!!!!!!!!!!!!!
{
  if (Bleu == true)
  {
    // NE PAS OUBLIER D'AVANCER
    Actions[0] = 'T';//Quart de tour
    Param[0] = -450;

    Actions[1] = 'A';
    Param[1] = 1000;
    Vitesse[1] = 60;

    Actions[2] = 'T';//Quart de tour
    Param[2] = -450;

    Actions[3] = 'A';
    Param[3] = 1000;
    Vitesse[3] = 60;

    Actions[4] = 'B';
    Actions[5] = 'L';
    Actions[6] = 'B';

    Actions[7] = 'R';
    Param[7] = 1000;
    Vitesse[7] = 60;


  //  Actions[4] = 'W';
  //  Param[4] = 2000;
  //  Actions[5] = 'A';
  //  Param[5] = 3000;
  //  Vitesse[5] = 50;
//    Param[1] = 10;
//    Vitesse[1] = 100;
  //  Actions[1] = 'L';//Leve le bras
  //  Actions[2] = 'F';//funny action
    Actions[8] = 'E';// end of the line
    Serial.println("Blue side !");
  }
  else
  {
    Actions[0] = 'A';//Avance
    Param[0] = 4000; //Distance
    Vitesse[0] = 60;

    Actions[1] = 'W';//Avance
    Param[1] = 1000;

    Actions[2] = 'R';
    Param[2] = 2000;
    Vitesse[2] = 60;

    Actions[3] = 'B';

    Actions[4] = 'E';// end of the line
    Serial.println("Yellow side !");
  }
}


void MachineEtat()
{
  Consigne = Param[EtatCourant];
  char Action = Actions[EtatCourant];
  //Serial.println(Actions[EtatCourant]);
  switch(Action)
  {
    case 'A':                         //Avancer
      RouleDroit();
      break;
    case 'R':                         //Avancer
      ReculeDroit();
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
    ConsigneVitesse = 0; //Arret du mouvement des moteurs
  }
}
