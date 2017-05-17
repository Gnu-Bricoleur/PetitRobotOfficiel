#include "moteurs.h"


void InitMoteur()
{
  
  pinMode(MoteurGauche, OUTPUT);
  pinMode(MoteurDroit, OUTPUT);
  pinMode(In1MoteurDroit, OUTPUT);
  pinMode(In2MoteurDroit, OUTPUT);
  pinMode(In3MoteurGauche, OUTPUT);
  pinMode(In4MoteurGauche, OUTPUT);
}

int PWMEcrete(int PWM)
{
  if (PWM > PWMMax)
  {
    return PWMMax;
  }
  else
  {
    return PWM;
  }
}


// donner une commande au moteur droit
// sens, puissance
void MoteurDroitTourne(bool sens, int PWM)
{
  if (sens == true)
  {
    digitalWrite(In1MoteurDroit, LOW);
    digitalWrite(In2MoteurDroit, HIGH);
  }
  else
  {
    digitalWrite(In1MoteurDroit, HIGH);
    digitalWrite(In2MoteurDroit, LOW);
  }
  PWM = PWMEcrete(PWM);
  analogWrite(MoteurDroit, PWM);
}



void MoteurGaucheTourne(bool sens, int PWM)
{
  if (sens == true)
  {
    digitalWrite(In3MoteurGauche, LOW);
    digitalWrite(In4MoteurGauche, HIGH);
  }
  else
  {
    digitalWrite(In3MoteurGauche, HIGH);
    digitalWrite(In4MoteurGauche, LOW);
  }
  PWM = PWMEcrete(PWM);
  analogWrite(MoteurGauche, PWM);
}
