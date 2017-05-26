#include "machineetat.h"

void InitMachineEtat()
{
  EtatCourant = 0;
  EtatComplete = false;
}


//##############################################################################
//AJOUTER LES TEMPS DE STABILISATION ET LES REMISES DANS L4AXE


void InitActions()      // Vitesse min 40 !!!!!!!!!!!!!!!!!!!!!!
{
  if (Bleu == true)
  {

    Actions[0] = 'A';
    Param[0] = 4000;

    Actions[1] = 'T';
    Param[1] = -25;

    Actions[2] = 'R';
    Param[2] = 4000;

    Actions[3] = 'T';
    Param[3] = 25;
/* Strat minimale
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

    Actions[4] = 'E';// end of the line
    Serial.println("Blue side !");
    */
  }
  else
  {
    Actions[0] = 'W';
    Param[0] = 40000; //ATTENTION REMETRE 40000 !!!!!!!!!!!!!!!!!!!

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
    Param[6] = 700;

    Actions[7] = 'R';//Sortie de la zone gros robot
    Param[7] = 2700;
    Vitesse[7] = 60;

    Actions[8] = 'W';//stabilisation
    Param[8] = 700;

    Actions[9] = 'T';//remise dans l'axe
    Param[9] = 25;

    Actions[10] = 'W';//stabilisation
    Param[10] = 700;

    Actions[11] = 'T';//deuxieme virage
    Param[11] = -450;

    Actions[12] = 'W';//stabilisation
    Param[12] = 700;

    Actions[13] = 'R';//Direction le tas de minerais
    Param[13] = 450;

    Actions[14] = 'W';//stabilisation
    Param[14] = 700;

    Actions[15] = 'T';//remise dans l'axe
    Param[15] = 25;

    Actions[16] = 'W';//stabilisation
    Param[16] = 700;

    Actions[17] = 'B';

    Actions[18] = 'T';//tortille pour attraper les balles
    Param[18] = -150;

    Actions[19] = 'T';//tortille pour attraper les balles
    Param[19] = 300;

    Actions[20] = 'T';//tortille pour attraper les balles
    Param[20] = -300;

    Actions[21] = 'T';//tortille pour attraper les balles
    Param[21] = 150;

    Actions[22] = 'B';

    Actions[23] = 'W';//stabilisation
    Param[23] = 700;

    Actions[24] = 'A';//Avance avec les balles
    Param[24] = 1000;
    Vitesse[24] = 60;

    Actions[25] = 'W';//stabilisation
    Param[25] = 700;

    Actions[26] = 'T';//remise dans l'axe
    Param[26] = -25;

    Actions[27] = 'W';//stabilisation
    Param[27] = 700;

    Actions[28] = 'T';//deuxieme virage
    Param[28] = -380;

    Actions[29] = 'W';//stabilisation
    Param[29] = 700;

    Actions[30] = 'R';//Avance avec les balles
    Param[30] = 1000;
    Vitesse[30] = 60;

    Actions[31] = 'W';//stabilisation
    Param[31] = 700;

    Actions[32] = 'T';//remise dans l'axe
    Param[32] = 25;

    Actions[33] = 'R';
    Param[33] = 300;


    Actions[34] = 'E';// end of the line*/
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
    delay(700);
    EtatCourant += 1;
    EtatComplete = false;
    Serial3.print("r\n"); // Reset de la carte codeuse
    LireCodeuse();
  /*  Serial.print(CodeuseDroit);
    Serial.print(" : ");
    Serial.print(CodeuseGauche);
    Serial.println(" D & G ");*/
    Serial3.print("r\n"); // Reset de la carte codeuse
    LireCodeuse();
  /*  Serial.print(CodeuseDroit);
    Serial.print(" : ");
    Serial.print(CodeuseGauche);
    Serial.println(" D & G 2");*/
    Serial3.print("r\n"); // Reset de la carte codeuse
    LireCodeuse();
    Serial.print(CodeuseDroit);
    Serial.print(" : ");
    Serial.print(CodeuseGauche);
    Serial.println(" D & G");
    ConsigneVitesse = 0; //Arret du mouvement des moteurs
    Serial.println("################Fin de l'état##########################");
  }
}
