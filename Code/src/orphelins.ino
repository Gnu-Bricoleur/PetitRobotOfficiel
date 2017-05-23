#include "orphelins.h"


void InitOrphelins()
{
    Tirette = true;
}



void CheckTirette()
{
  if(digitalRead(GpioTirette)==LOW)
  {
    TempsDebut = millis();            // on fixe le repere pour calculer la duree du match
    Tirette = false;
    Serial.println("Début du match !");
    if(digitalRead(GpioJaune)==LOW)
    {
      Bleu = false;
      InitActions();
    }
    else if(digitalRead(GpioBleu)==LOW)
    {
      Bleu = true;
      InitActions();
    }
    else                            //Si aucune Tirette n'est mise, on joue bleu (au pif)
    {
      Bleu = true;
      InitActions();
    }
  }
}



void CheckObstacle()
{
  if (Actions[EtatCourant] == 'A' && digitalRead(DetectAvant)==HIGH)
  {
    Serial.println("Debut detect Avant");
    while(digitalRead(DetectAvant)==HIGH)
    {
      MoteurGaucheTourne(0);
      MoteurDroitTourne(0);
    }
    Serial.println("Fin detect Avant");
  }
  if (Actions[EtatCourant] == 'R' && digitalRead(DetectArriere)==HIGH)
  {
    Serial.println("Debut detect Avant");
    while (digitalRead(DetectArriere)==HIGH)
    {
      MoteurGaucheTourne(0);
      MoteurDroitTourne(0);
    }
        Serial.println("Fin detect Arriere");
  }
}



void Attente()
{
  Serial.println("Debut Attente");
  delay(Param[EtatCourant]);
  Serial.println(" Fin Attente ");
  EtatComplete = true;
}
