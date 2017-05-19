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
    }
    else if(digitalRead(GpioBleu)==LOW)
    {
      Bleu = true;
    }
  }
}
