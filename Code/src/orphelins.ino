#include "orphelins.h"

void CheckTirette()
{
  if(digitalRead(GpioTirette)==LOW)
  {
    TempsDebut = millis();
    Tirette = false;
    Serial.print("Début du match !");
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
  }
}



void CheckObstacle()
{
  if (Actions[EtatCourant] == 'A' && digitalRead(DetectAvant)==HIGH)
  {
    while(digitalRead(DetectAvant)==HIGH)
    {
      MoteurGaucheTourne(0);
      MoteurGaucheTourne(0);
      Serial.println("Detect Avant");
    }
  }
  if (Actions[EtatCourant] == 'R' && digitalRead(DetectArriere)==HIGH)
  {
    while (digitalRead(DetectArriere)==HIGH)
    {
      MoteurGaucheTourne(0);
      MoteurGaucheTourne(0);
      Serial.println("Detect Arriere");
    }
  }
}
