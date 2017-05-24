#include "orphelins.h"


void InitOrphelins()
{
    Tirette = true;
    DebutAttente = false;
    TempsDebutAttente = 0;
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
      //MoteurGaucheTourne(0);
      //MoteurDroitTourne(0);
      ConsigneVitesse = 0;
    }
    ConsigneVitesse = Vitesse[EtatCourant];
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
  if (DebutAttente == false)
  {
      Serial.println("Debut Attente");
      TempsDebutAttente = millis();
      DebutAttente = true;
  }

  if (Param[EtatCourant] < millis() - TempsDebutAttente)
  {
    Serial.println(" Fin Attente ");
    DebutAttente = false;
    EtatComplete = true;
  }
  Serial.println(millis() - TempsDebutAttente);
}
