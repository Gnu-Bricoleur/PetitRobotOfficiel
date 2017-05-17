#ifndef MOTEUR_H_INCLUDED
#define MOTEUR_H_INCLUDED

#include "Arduino.h"
#include "define.h"

int PWMEcrete(int PWM);
void MoteurDroitTourne(bool sens, int PWM);
void InitMoteur();
void MoteurGaucheTourne(bool sens, int PWM);

#endif // MOTEUR_H_INCLUDED
