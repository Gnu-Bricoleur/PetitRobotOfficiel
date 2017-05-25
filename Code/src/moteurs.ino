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

void TestMoteurs()
{
  MoteurDroitTourne(200);
  MoteurGaucheTourne(200);
  delay(150);
  MoteurDroitTourne(-200);
  MoteurGaucheTourne(-200);
  delay(150);
  MoteurDroitTourne(0);
  MoteurGaucheTourne(0);
  delay(500);
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
void MoteurDroitTourne(int PWM)
{
  if (PWM > 0)
  {
    digitalWrite(In1MoteurDroit, LOW);
    digitalWrite(In2MoteurDroit, HIGH);
  }
  else
  {
    digitalWrite(In1MoteurDroit, HIGH);
    digitalWrite(In2MoteurDroit, LOW);
  }
  PWM = abs(PWM);
  PWM = PWMEcrete(PWM);
  analogWrite(MoteurDroit, PWM);


}



void MoteurGaucheTourne(int PWM)
{
  if (PWM > 0)
  {
    digitalWrite(In3MoteurGauche, LOW);
    digitalWrite(In4MoteurGauche, HIGH);
  }
  else
  {
    digitalWrite(In3MoteurGauche, HIGH);
    digitalWrite(In4MoteurGauche, LOW);
  }
  PWM = abs(PWM);
  PWM = PWMEcrete(PWM);
  analogWrite(MoteurGauche, PWM);
}


void StopMoteur()
{
  analogWrite(MoteurGauche, 0);
  analogWrite(MoteurDroit, 0);
  digitalWrite(In1MoteurDroit, LOW);
  digitalWrite(In2MoteurDroit, LOW);
  digitalWrite(In3MoteurGauche, LOW);
  digitalWrite(In4MoteurGauche, LOW);
}
