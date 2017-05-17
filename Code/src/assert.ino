#include "assert.ino"

void RouleDroit()
{

  Temps = millis();
  unsigned long DeltaAssert = Temps - DateAssert;
  unsigned long DeltaDroit = CodeuseDroit/DeltaAssert;
  unsigned long DeltaGauche = CodeuseGauche/DeltaAssert;






  // assert vitesse Moteur droit
  ErreurDroit = Consigne - ParcouruDroit;
  SommeErreurDroit += ErreurDroit;
  DeltaErreurDroit = ErreurDroit - AncienneErreurDroit;
  PWMDroit = P*ErreurDroit + I*SommeErreurDroit + D*DeltaErreurDroit;

  //assert vitesse moteur gauche
  ErreurGauche = Consigne - ParcouruGauche;
  SommeErreurGauche += ErreurGauche;
  DeltaErreurGauche = ErreurGauche - AncienneErreurGauche;
  PWMGauche = P*ErreurGauche + I*SommeErreurGauche + D*DeltaErreurGauche;


  //Ecrete commandes

  // roule droit
  if (ParcouruDroit - ParcouruGauche > PrecisionDroit)
  {
    if (ParcouruDroit > ParcouruGauche)
    {
      PWMDroit -= (PWMDroit/PWMMax)*10; //On ralenti de 10% le moteur en avance
    }
    else
    {
      PWMGauche -= (PWMGauche/PWMMax)*10;
    }
  }

  // envoie des commandes




  if (Consigne - Parcouru < PrecisionAssert)
  {
    EtatComplete = true;
  }

  DateAssert = millis();
}

void Tourne()
{

}


void LireCodeuse(byte A) {

  String inputString_Codeuse = "";
  String data_Codeuse[10]; // stockage des données découpées
  bool fini = true;
  Serial3.print("C\n");

  while (Serial3.available() && fini) {
    char inChar = (char)Serial3.read();

    if (inChar == '\n') {

      splitString(inputString_Codeuse, SEPARATEUR, data_Codeuse);
      Codeuse_Droite = data_Codeuse[1].toInt();
      Codeuse_Gauche = -data_Codeuse[2].toInt();
      fini = false;

    } else
    inputString_Codeuse += inChar;
  }
}




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
