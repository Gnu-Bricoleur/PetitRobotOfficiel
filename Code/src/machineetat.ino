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

    Actions[0] = 'W';
    Param[0] = 40000;

    Actions[1] = 'R';//Quart de tour
    Param[1] = 10000;
    Vitesse[1] = 60;

    Actions[2] = 'T';
    Param[2] = -450;

    Actions[3] = 'R';//Quart de tour
    Param[3] = 1666;
    Vitesse[3] = 60;

    Actions[4] = 'T';
    Param[4] = -450;

    Actions[5] = 'B';
    Actions[6] = 'L';
    Actions[7] = 'B';

    Actions[8] = 'A';
    Param[8] = 3000;
    Vitesse[8] = 60;


  //  Actions[4] = 'W';
  //  Param[4] = 2000;
  //  Actions[5] = 'A';
  //  Param[5] = 3000;
  //  Vitesse[5] = 50;
//    Param[1] = 10;
//    Vitesse[1] = 100;
  //  Actions[1] = 'L';//Leve le bras
  //  Actions[2] = 'F';//funny action
    Actions[9] = 'E';// end of the line
    Serial.println("Blue side !");
  }
  else
  {
    Actions[0] = 'W';
    Param[0] = 40000;
    Actions[1] = 'R';//Avance
    Param[1] = 4000; //Distance
    Vitesse[1] = 60;// niveau de la bascule
  //  Actions[1] = 'A';//Avance
  //  Param[1] = 10000; //Distance
  //  Vitesse[1] = 60;// niveau de la bascule
    Actions[2] = 'B';
    Actions[3] = 'E';


  //  TEST PASSAGE BASCULE
  /*  Actions[0] = 'R';//Avance
    Param[0] = 2000; //Distance
    Vitesse[0] = 60;// niveau de la bascule

    Actions[1] = 'W';//Avance
    Param[1] = 500;

    Actions[2] = 'R';
    Param[2] = 700; //Distance
    Vitesse[2] = 60;

    Actions[3] = 'W';//Avance
    Param[3] = 500;

    Actions[4] = 'B';

    Actions[5] = 'R';
    Param[5] = 700;
    Vitesse[5] = 60;

    Actions[6] = 'W';//Avance
    Param[6] = 700;

    Actions[7] = 'R';
    Param[7] = 700;
    Vitesse[7] = 60;

    Actions[8] = 'L';

    Actions[9] = 'E';// end of the line*/
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
      RouleDroitBO();
      break;
    case 'R':                         //Avancer
      ReculeDroitBO();
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
