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
    Param[0] = 4000; //ATTENTION REMETRE 40000 !!!!!!!!!!!!!!!!!!!

    Actions[1] = 'A';//Avance pour passer la bascule
    Param[1] = 5000;
    Vitesse[1] = 60;

    Actions[2] = 'W';//stabilisation
    Param[2] = 500;

    Actions[3] = 'T';//remise dans l'axe
    Param[3] = -25;

    Actions[4] = 'W';//stabilisation
    Param[4] = 500;


/*
    Actions[3] = 'W';
    Param[3] = 10000;

    Actions[4] = 'A';//Avance
    Param[4] = 5000;
    Vitesse[4] = 60;

    Actions[4] = 'T';
    Param[4] = -450;

    Actions[5] = 'A';
    Param[5] = 1666;
    Vitesse[5] = 60;

    Actions[6] = 'T';
    Param[6] = -450;

    Actions[7] = 'B';
    Actions[8] = 'L';
    Actions[9] = 'B';

    Actions[10] = 'R';
    Param[10] = 3000;
    Vitesse[10] = 60;
*/

  //  Actions[4] = 'W';
  //  Param[4] = 2000;
  //  Actions[5] = 'A';
  //  Param[5] = 3000;
  //  Vitesse[5] = 50;
//    Param[1] = 10;
//    Vitesse[1] = 100;
  //  Actions[1] = 'L';//Leve le bras
  //  Actions[2] = 'F';//funny action
    Actions[4] = 'E';// end of the line
    Serial.println("Blue side !");
  }
  else
  {
    Actions[0] = 'W';
    Param[0] = 4000; //ATTENTION REMETRE 40000 !!!!!!!!!!!!!!!!!!!

    Actions[1] = 'A';//Avance pour passer la bascule
    Param[1] = 6500;
    Vitesse[1] = 60;

    Actions[2] = 'W';//stabilisation
    Param[2] = 500;

    Actions[3] = 'T';//remise dans l'axe
    Param[3] = -25;

    Actions[4] = 'W';//stabilisation
    Param[4] = 1000;

    Actions[5] = 'T';//premier virage
    Param[5] = 450;

    Actions[6] = 'W';//stabilisation
    Param[6] = 500;

    Actions[7] = 'R';
    Param[7] = 2700;
    Vitesse[7] = 60;

    Actions[8] = 'W';//stabilisation
    Param[8] = 500;

    Actions[9] = 'T';//deuxieme virage
    Param[9] = -430;

    Actions[10] = 'W';//stabilisation
    Param[10] = 500;

    Actions[11] = 'R';
    Param[11] = 400;

    Actions[12] = 'B';

    Actions[13] = 'E';// end of the line*/
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
    delayMicroseconds(10);
    LireCodeuse();
    Serial.print(CodeuseDroit);
    Serial.print(CodeuseGauche);
    Serial.println("  odsjfdlsng");
    ConsigneVitesse = 0; //Arret du mouvement des moteurs
  }
}
