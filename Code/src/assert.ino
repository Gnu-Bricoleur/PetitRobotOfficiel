#include "assert.h"


void InitAsssert()
{
  Parcouru = 0;
  PrecisionDroit = 10;
  PrecisionAssert = 10;
  AncienneErreurDroit = 0;
  AncienneErreurGauche = 0;
  AncienneErreurAngulaire = 0;
  Serial3.begin(115200);
  Serial3.print("R\n"); // Reset de la carte codeuse
  FinDroit = false;
  FinGauche = false;
  IndexTableau = 0;
}

void ReculeDroitBO()
{
  LireCodeuse();
  if (CodeuseDroit > Param[EtatCourant])
  {
    MoteurDroitTourne(0);
    MoteurGaucheTourne(0);
    EtatComplete = true;
  }
  else
  {
    CorrectionEnAngle = CodeuseDroit - CodeuseGauche;
    CorrectionEnAngle = CorrectionEnAngle*2;
    MoteurDroitTourne(-100 + CorrectionEnAngle);
    MoteurGaucheTourne(-135 - CorrectionEnAngle);
  }
}

void RouleDroitBO()
{
  LireCodeuse();
  if (-CodeuseDroit > Param[EtatCourant])
  {
    MoteurDroitTourne(0);
    MoteurGaucheTourne(0);
    EtatComplete = true;
  }
  else
  {
    CorrectionEnAngle = CodeuseDroit - CodeuseGauche;
    CorrectionEnAngle = CorrectionEnAngle*2;
    MoteurDroitTourne(100 + CorrectionEnAngle);
    MoteurGaucheTourne(135 - CorrectionEnAngle);
  }
}

void Tourne()
{
  /*
  LireCodeuse();
  if (- CodeuseDroit >  Param[EtatCourant])// Le robot roule a peut pres droit, CodeuseDroit suffit
  {
    RaZErreur();
    EtatComplete = true;
  }
  else
  {
    ConsigneAngle = Param[EtatCourant];
    ConsigneVitesse = 0;
  }
  */
  LireCodeuse();
  if (Param[EtatCourant] > 0)
  {
    if (-CodeuseDroit > Param[EtatCourant])
    {
      MoteurDroitTourne(0);
      MoteurGaucheTourne(0);
      EtatComplete = true;
    }
    else
    {
      MoteurDroitTourne(100);
      MoteurGaucheTourne(-150);
    }
  }
  else
  {
    if (-CodeuseDroit < Param[EtatCourant])
    {
      MoteurDroitTourne(0);
      MoteurGaucheTourne(0);
      EtatComplete = true;
    }
    else
    {
      MoteurDroitTourne(-100);
      MoteurGaucheTourne(150);
    }
  }
}


void LireCodeuse() {

  String inputString_Codeuse = "";
  String data_Codeuse[10]; // stockage des données découpées
  bool fini = true;
  Serial3.print("C\n");

  while (Serial3.available() && fini)
  {
    char inChar = (char)Serial3.read();
    if (inChar == '\n')
    {
      splitString(inputString_Codeuse, Separateur, data_Codeuse);
      CodeuseDroit = data_Codeuse[1].toInt();
      CodeuseGauche = -data_Codeuse[2].toInt();
      fini = false;
    }
    else
    {
      inputString_Codeuse += inChar;
    }
  }
}



void splitString(String message, char separator, String *data) {
  int index = 0;
  String inputString = "";
  bool stringComplete = false;
  for (int i = 0; i < 10; i++) {
    data[i] = "";
  }
  int cnt = 0;
  do {
    index = message.indexOf(separator);
    if (index != -1) { // s'il y a bien un caractère séparateu
      // on découpe la chaine et on stocke le bout dans le tableau
      data[cnt] = message.substring(0, index);
      cnt++;
      // on enlève du message le bout stocké
      message = message.substring(index + 1, message.length());
    } else {
      // après le dernier espace
      // on s'assure que la chaine n'est pas vide
      if (message.length() > 0) {

        data[cnt] = message.substring(0, index); // dernier bout
        cnt++;
      }
    }
  } while (index >= 0); // tant qu'il y a bien un séparateur dans la chaine
}

/*
void mise_a_jour_POS()
{
  float delta_D = (Codeuse_Droite_PAST - Codeuse_Droite)*TICS2MM; //En tic puis converti en mm
  float delta_G = (Codeuse_Gauche_PAST - Codeuse_Gauche)*TICS2MM; //En tic puis converti en mm

  float localX = 0, localY = 0;
  localY = (float)(((delta_D + delta_G) / 2.0f) * cos(angle_radian +(delta_D - delta_G) / (2* ECARTEMENT_ROUES)));//on parcourt cette distance avec l'angle initial
  localX = (float)(((delta_D + delta_G) / 2.0f) * sin(angle_radian +(delta_D - delta_G) / (2* ECARTEMENT_ROUES)));
  angle_radian += ((float)(delta_D - delta_G) / ECARTEMENT_ROUES); //Mise a jour de l'angle pour le prochain déplacement,toutes les distances doivent avoir les mêmes unités!


  X_POS += localX*0;
  Y_POS -= localY*0;
  ANGLE_POS = (angle_radian * 360 / (float)(2 * PI));
//Serial.println(ANGLE_POS);

}
*/
