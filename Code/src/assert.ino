#include "assert.h"


void AsssertIni()
{
  Parcouru = 0;
  PrecisionDroit = 10;
  PrecisionAssert = 10;
  Serial3.begin(115200);
  Serial3.print("R\n"); // Reset de la carte codeuse
  FinDroit = false;
  FinGauche = false;
  

}

void RouleDroitBO()
{
  LireCodeuse();
  if (CodeuseDroit < Consigne)    // Si il reste de la ditance a parcourir pour la roue droite
  {
    if(abs(CodeuseDroit - CodeuseGauche) < PrecisionDroit)  //Si l'ecart entre les deux roues est suffisamment faible
    {
        MoteurDroitTourne(Vitesse[EtatCourant]);
    }
    else if (CodeuseDroit > CodeuseGauche)
    {
        MoteurDroitTourne(Vitesse[EtatCourant]-30);
    }
  }
  else                          // Sinon, on arrete le moteur
  {
    MoteurDroitTourne(0);
    FinDroit = true;
  }

  if (CodeuseGauche < Consigne)     // Si il reste de la ditance a parcourir pour la roue gauche
  {
    if(abs(CodeuseDroit - CodeuseGauche) < PrecisionDroit)
    {
        MoteurGaucheTourne(Vitesse[EtatCourant]);
    }
    else if (CodeuseGauche > CodeuseDroit)
    {
        MoteurGaucheTourne(Vitesse[EtatCourant]-30);
    }
  }
  else
  {
    MoteurGaucheTourne(0);
    FinGauche = true;
  }
  if (FinDroit == true && FinGauche == true)
  {
    Serial.println("Fin de rouler droit");
    Serial.println(CodeuseDroit);
    Serial.println(Consigne);
    Parcouru = 0;
    EtatComplete = true;
    FinDroit = false;
    FinGauche = false;
    MoteurDroitTourne(0);
    MoteurGaucheTourne(0);
    Serial3.print("R\n"); // Reset de la carte codeuse
    Serial.println(CodeuseDroit);
  }
}

void ReculeDroitBO()
{
  LireCodeuse();
  if (CodeuseDroit < Consigne)
  {
    MoteurDroitTourne(100);
  }
  else
  {
    MoteurDroitTourne(0);
  }
  if (CodeuseGauche < Consigne)
  {
    MoteurGaucheTourne(120);
  }
  else
  {
    MoteurGaucheTourne(0);
  }
  if (CodeuseDroit > Consigne && CodeuseGauche > Consigne)
  {
    Serial.println("Fin de rouler droit");
    Serial.println(Consigne - CodeuseDroit);
    Serial.println(Consigne - CodeuseGauche);
    Parcouru = 0;
    EtatComplete = true;
    MoteurDroitTourne(0);
    MoteurGaucheTourne(0);
  }
}




void TourneDroiteBO()
{
  LireCodeuse();
  if (CodeuseDroit < Consigne)
  {
    MoteurDroitTourne(-100);
  }
  else
  {
    MoteurDroitTourne(0);
  }
  if (CodeuseGauche < Consigne)
  {
    MoteurGaucheTourne(120);
  }
  else
  {
    MoteurGaucheTourne(0);
  }
  if (CodeuseDroit > Consigne && CodeuseGauche > Consigne)
  {
    Serial.println("Fin de tourner droit");
    Serial.println(Consigne - CodeuseDroit);
    Serial.println(Consigne - CodeuseGauche);
    Parcouru = 0;
    EtatComplete = true;
    MoteurDroitTourne(0);
    MoteurGaucheTourne(0);
  }
}


void TourneGaucheBO()
{
  LireCodeuse();
  if (CodeuseDroit < Consigne)
  {
    MoteurDroitTourne(100);
  }
  else
  {
    MoteurDroitTourne(0);
  }
  if (CodeuseGauche < Consigne)
  {
    MoteurGaucheTourne(-120);
  }
  else
  {
    MoteurGaucheTourne(0);
  }
  if (CodeuseDroit > Consigne && CodeuseGauche > Consigne)
  {
    Serial.println("Fin de tourner gauche");
    Serial.println(Consigne - CodeuseDroit);
    Serial.println(Consigne - CodeuseGauche);
    Parcouru = 0;
    EtatComplete = true;
    MoteurDroitTourne(0);
    MoteurGaucheTourne(0);
  }
}



void RouleDroit()
{

  LireCodeuse();

//  Temps = millis();
//  unsigned long DeltaAssert = Temps - DateAssert;
//  unsigned long DeltaDroit = CodeuseDroit/DeltaAssert;
//  unsigned long DeltaGauche = CodeuseGauche/DeltaAssert;


  // assert position Moteur droit
  ErreurDroit = Consigne - CodeuseDroit;
  SommeErreurDroit += ErreurDroit;
  DeltaErreurDroit = ErreurDroit - AncienneErreurDroit;
  PWMDroit = P*ErreurDroit + I*SommeErreurDroit + D*DeltaErreurDroit;
  AncienneErreurDroit = ErreurDroit;

  //assert position moteur gauche
  ErreurGauche = Consigne - CodeuseGauche;
  SommeErreurGauche += ErreurGauche;
  DeltaErreurGauche = ErreurGauche - AncienneErreurGauche;
  PWMGauche = P*ErreurGauche + I*SommeErreurGauche + D*DeltaErreurGauche;
  AncienneErreurGauche = ErreurGauche;

  Serial.println("erreur");
  Serial.println(ErreurDroit);
  Serial.println(ErreurGauche);

  //Ecrete commandes
  PWMDroit = PWMEcrete(PWMDroit);
  PWMGauche = PWMEcrete(PWMGauche);



  // roule droit
  if (abs(CodeuseDroit - CodeuseGauche) > PrecisionDroit)
  {
    if (CodeuseDroit > CodeuseGauche)
    {
      PWMDroit -= (PWMDroit/PWMMax)*10; //On ralenti de 10% le moteur en avance
    }
    else
    {
      PWMGauche -= (PWMGauche/PWMMax)*10;
    }
  }



  // envoie des commandes


  MoteurDroitTourne(PWMGauche);
  MoteurGaucheTourne(PWMDroit);



  Parcouru = CodeuseDroit; // On ne s'asservi que sur la distance parcouru par la roue droite
  //Car la roue gauche doit etre pas loing normalement a cause de la condition roule droit



  if (abs(Consigne - CodeuseDroit) < PrecisionAssert && abs(Consigne - CodeuseGauche) < PrecisionAssert)
  {
    Serial.println("Fin de rouler droit");
    Serial.println(Consigne - CodeuseDroit);
    Serial.println(Consigne - CodeuseGauche);
    Parcouru = 0;
    EtatComplete = true;
    MoteurDroitTourne(0);
    MoteurGaucheTourne(0);
  }

  DateAssert = millis();
}

void Tourne()
{

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
