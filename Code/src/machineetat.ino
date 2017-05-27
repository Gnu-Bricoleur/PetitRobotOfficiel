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
    /*    TEST ATTAPE BALLES
    Actions[0] = 'R';//Direction le tas de minerais
    Param[0] = 500;

    Actions[1] = 'W';//stabilisation
    Param[1] = 700;

    Actions[2] = 'B';

    Actions[3] = 'R';//tortille pour attraper les balles
    Param[3] = 60;

    Actions[4] = 'A';//tortille pour attraper les balles
    Param[4] = 60;

    Actions[5] = 'T';//tortille pour attraper les balles
    Param[5] = -30;

    Actions[6] = 'T';//tortille pour attraper les balles
    Param[6] = 60;

    Actions[7] = 'T';//tortille pour attraper les balles
    Param[7] = -60;

    Actions[8] = 'T';//tortille pour attraper les balles
    Param[8] = 30;

    Actions[9] = 'B';

    Actions[10] = 'W';//stabilisation
    Param[10] = 700;

    Actions[11] = 'A';//Avance avec les balles
    Param[11] = 500;
    Vitesse[11] = 60;

    Actions[12] = 'E';
    */

    Actions[0] = 'W';
    Param[0] = 35000; //ATTENTION REMETRE 35000 !!!!!!!!!!!!!!!!!!!

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
    Param[5] = -435;

    Actions[6] = 'W';//stabilisation
    Param[6] = 700;

    Actions[7] = 'R';//Sortie de la zone gros robot
    Param[7] = 2500;
    Vitesse[7] = 60;

    Actions[8] = 'W';//stabilisation
    Param[8] = 700;

    Actions[9] = 'T';//remise dans l'axe
    Param[9] = 25;

    Actions[10] = 'W';//stabilisation
    Param[10] = 700;

    Actions[11] = 'T';//deuxieme virage
    Param[11] = 450;

    Actions[12] = 'W';//stabilisation
    Param[12] = 700;

    Actions[13] = 'R';//Direction le tas de minerais
    Param[13] = 580;

    Actions[14] = 'W';//stabilisation
    Param[14] = 700;

    Actions[15] = 'T';//remise dans l'axe
    Param[15] = 25;

    Actions[16] = 'W';//stabilisation
    Param[16] = 700;

    Actions[17] = 'B';

    Actions[18] = 'R';//tortille pour attraper les balles
    Param[18] = 60;

    Actions[19] = 'A';//tortille pour attraper les balles
    Param[19] = 60;

    Actions[20] = 'T';//tortille pour attraper les balles
    Param[20] = -30;

    Actions[21] = 'T';//tortille pour attraper les balles
    Param[21] = 60;

    Actions[22] = 'T';//tortille pour attraper les balles
    Param[22] = -60;

    Actions[23] = 'T';//tortille pour attraper les balles
    Param[23] = 30;

    Actions[24] = 'B';

    Actions[25] = 'W';//stabilisation
    Param[25] = 700;

    Actions[26] = 'A';//Avance avec les balles
    Param[26] = 1000;
    Vitesse[26] = 60;

    Actions[27] = 'W';//stabilisation
    Param[27] = 700;

    Actions[28] = 'T';//remise dans l'axe
    Param[28] = -25;

    Actions[29] = 'W';//stabilisation
    Param[29] = 700;

    Actions[30] = 'T';// virage
    Param[30] = 250;

    Actions[31] = 'W';//stabilisation
    Param[31] = 700;

    Actions[32] = 'R';//Avance avec les balles
    Param[32] = 3000;
    Vitesse[32] = 60;

    Actions[33] = 'W';//stabilisation
    Param[33] = 700;

    Actions[34] = 'E';// end of the line

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

    Actions[4] = 'E';// end of the line*/
    Serial.println("Blue side !");

  }
  else
  {
    Actions[0] = 'W';
    Param[0] = 35000; //ATTENTION REMETRE 40000 !!!!!!!!!!!!!!!!!!!

    Actions[1] = 'A';//Avance pour passer la bascule
    Param[1] = 7000;
    Vitesse[1] = 60;

    Actions[2] = 'W';//stabilisation
    Param[2] = 500;

    Actions[3] = 'T';//remise dans l'axe
    Param[3] = -25;

    Actions[4] = 'W';//stabilisation
    Param[4] = 1000;

    Actions[5] = 'T';//premier virage
    Param[5] = 435;

    Actions[6] = 'W';//stabilisation
    Param[6] = 700;

    Actions[7] = 'R';//Sortie de la zone gros robot
    Param[7] = 2500;
    Vitesse[7] = 60;

    Actions[8] = 'W';//stabilisation
    Param[8] = 700;

    Actions[9] = 'T';//remise dans l'axe
    Param[9] = 25;

    Actions[10] = 'W';//stabilisation
    Param[10] = 700;

    Actions[11] = 'T';//deuxieme virage
    Param[11] = -420;

    Actions[12] = 'W';//stabilisation
    Param[12] = 700;

    Actions[13] = 'R';//Direction le tas de minerais
    Param[13] = 580;

    Actions[14] = 'W';//stabilisation
    Param[14] = 700;

    Actions[15] = 'T';//remise dans l'axe
    Param[15] = 25;

    Actions[16] = 'W';//stabilisation
    Param[16] = 700;

    Actions[17] = 'B';

    Actions[18] = 'R';//tortille pour attraper les balles
    Param[18] = 60;

    Actions[19] = 'A';//tortille pour attraper les balles
    Param[19] = 60;

    Actions[20] = 'T';//tortille pour attraper les balles
    Param[20] = -30;

    Actions[21] = 'T';//tortille pour attraper les balles
    Param[21] = 60;

    Actions[22] = 'T';//tortille pour attraper les balles
    Param[22] = -60;

    Actions[23] = 'T';//tortille pour attraper les balles
    Param[23] = 30;

    Actions[24] = 'B';

    Actions[25] = 'W';//stabilisation
    Param[25] = 700;

    Actions[26] = 'A';//Avance avec les balles
    Param[26] = 1000;
    Vitesse[26] = 60;

    Actions[27] = 'W';//stabilisation
    Param[27] = 700;

    Actions[28] = 'T';//remise dans l'axe
    Param[28] = -25;

    Actions[29] = 'W';//stabilisation
    Param[29] = 700;

    Actions[30] = 'T';//deuxieme virage
    Param[30] = -250;

    Actions[31] = 'W';//stabilisation
    Param[31] = 700;

    Actions[32] = 'R';//Avance avec les balles
    Param[32] = 3000;
    Vitesse[32] = 60;

    Actions[33] = 'W';//stabilisation
    Param[33] = 700;

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
