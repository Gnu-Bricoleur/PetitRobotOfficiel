#ifndef MOTEUR_H_INCLUDED
#define MOTEUR_H_INCLUDED

#include "Arduino.h"
#include "define.h"

int PWMEcrete(int PWM);
void MoteurDroitTourne(int PWM);
void InitMoteur();
void MoteurGaucheTourne(int PWM);
void StopMoteur();

#endif // MOTEUR_H_INCLUDED
