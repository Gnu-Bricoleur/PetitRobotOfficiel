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
  TimerId = timer.setInterval(1000/FrequenceEchantillonnage, PeriodiqueAssert);
  IndexTableau = 0;
}


void PeriodiqueAssert()
{
  LireCodeuse();
  //Pour verifier la frequence du pid
//  Serial.print("Freq PID : ");
//  Serial.println(millis() - DateDernierPassage);
//  DateDernierPassage = millis();

  //min 40
  //ConsigneVitesse = 50;

if (Actions[EtatCourant] == 'A' || Actions[EtatCourant] == 'R')
{
  //##############################################################################
  //###########   ASSERT LINEAIRE   ##############################################
    ErreurDroit = ConsigneVitesse - (CodeuseDroit - AncienneCodeuseDroit); //P
    ListeIDroit[IndexTableau%NombreValeursI] = ErreurDroit;                //I
    for(int j=0; j<NombreValeursI; j++)
    {
      SommeErreurDroit += ListeIDroit[j%NombreValeursI];
    }
    if (SommeErreurDroit > MaxI)
    {
      SommeErreurDroit = MaxI;
    }
    DeltaErreurDroit = ErreurDroit - AncienneErreurDroit;                   //D
    PWMDroit = PD*ErreurDroit + ID*SommeErreurDroit + DD*DeltaErreurDroit;
    AncienneErreurDroit = ErreurDroit;
    AncienneCodeuseDroit = CodeuseDroit;



    ErreurGauche = ConsigneVitesse - (CodeuseGauche - AncienneCodeuseGauche);//P
    ListeIGauche[IndexTableau%NombreValeursI] = ErreurGauche;                //I
    for(int j=0; j<NombreValeursI; j++)
    {
      SommeErreurGauche += ListeIGauche[j%NombreValeursI];
    }
    if (SommeErreurGauche > MaxI)
    {
      SommeErreurGauche = MaxI;
    }
    DeltaErreurGauche = ErreurGauche - AncienneErreurGauche;
    PWMGauche = PG*ErreurGauche + IG*SommeErreurGauche + DG*DeltaErreurGauche;  //D
    AncienneErreurGauche = ErreurGauche;
    AncienneCodeuseGauche = CodeuseGauche;
  }

  if(Actions[EtatCourant] == 'A' || Actions[EtatCourant] == 'R' || Actions[EtatCourant] == 'T')
  {
    //############################################################################
    //##################   ASSERT ANGULAIRE   ####################################
    PWMDroit = PWMEcrete(PWMDroit);
    PWMGauche = PWMEcrete(PWMGauche);


    ErreurAngulaire = CodeuseDroit - CodeuseGauche;                            //P
    ListeIAngulaire[IndexTableau%NombreValeursI] = ErreurAngulaire;            //I
    for(int j=0; j<NombreValeursI; j++)
    {
      SommeErreurAngulaire += ListeIAngulaire[j%NombreValeursI];
    }
    if (SommeErreurAngulaire > MaxI)
    {
      SommeErreurAngulaire = MaxI;
    }
    DeltaErreurAngulaire = ErreurAngulaire - AncienneErreurAngulaire;
    PWMAngulaire = PA*ErreurAngulaire + IA*SommeErreurAngulaire + DA*DeltaErreurAngulaire;  //D
    AncienneErreurAngulaire = ErreurAngulaire;

    PWMDroit += PWMAngulaire;
    PWMGauche -= PWMAngulaire;
  }
  IndexTableau += 1;              // Pour les trois PID




/*  //Pour ggner de la frequence commenter l'asser

  Serial.print("EA : ");
  Serial.println(ErreurAngulaire);

  Serial.print("D : ");
  Serial.print(ErreurDroit);
  Serial.print(" ; ");
  Serial.println(PWMDroit);

  Serial.print("G : ");
  Serial.print(ErreurGauche);
  Serial.print(" ; ");
  Serial.println(PWMGauche);
  */
  if(Actions[EtatCourant] == 'A' || Actions[EtatCourant] == 'R' || Actions[EtatCourant] == 'T')
  {
    MoteurDroitTourne(PWMDroit);
    MoteurGaucheTourne(PWMGauche);
  }
  else
  {
    MoteurDroitTourne(0);
    MoteurGaucheTourne(0);
  }
  //Serial.println(PWMAngulaire);
  //Serial.println(PWMDroit);
  //Serial.println(PWMGauche);

  //Rouler a peu pres droit en boucle ouverte
  //MoteurDroitTourne(-100);
  //MoteurGaucheTourne(-150);
}

void RaZErreur()
{
  IndexTableau = 0;
  ConsigneAngle = 0;
  ConsigneVitesse = 0;
  ErreurAngulaire = 0;
  ErreurDroit = 0;
  ErreurGauche = 0;
  for(int j=0; j<NombreValeursI; j++)
  {
    ListeIAngulaire[j%NombreValeursI] = 0;
    ListeIDroit[j%NombreValeursI] = 0;
    ListeIGauche[j%NombreValeursI] = 0;
  }
  DeltaErreurAngulaire = 0;
  DeltaErreurDroit = 0;
  DeltaErreurGauche = 0;
  AncienneErreurDroit = 0;
  AncienneErreurGauche = 0;
  AncienneErreurAngulaire = 0;
}



void ReculeDroit()
{
  LireCodeuse();
  if (CodeuseDroit >  Param[EtatCourant])// Le robot roule a peut pres droit, CodeuseDroit suffit
  {
    RaZErreur();
    EtatComplete = true;
  }
  else
  {
    ConsigneVitesse = Vitesse[EtatCourant];
    ConsigneAngle = 0;
  }
}




void RouleDroit()
{
  LireCodeuse();
  if (- CodeuseDroit >  Param[EtatCourant])// Le robot roule a peut pres droit, CodeuseDroit suffit
  {
    RaZErreur();
    Serial.println("Fin roule droit");
    EtatComplete = true;
  }
  else
  {
    ConsigneVitesse = Vitesse[EtatCourant];
    ConsigneAngle = 0;
  }
}


void Tourne()
{
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
