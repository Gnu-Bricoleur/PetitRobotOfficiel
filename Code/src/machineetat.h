#ifndef MACHINE_H_INCLUDED
#define MACHINE_H_INCLUDED

#include "Arduino.h"
#include "define.h"


void MachineEtat();
void InitMachineEtat();
void InitActions();

//A => Avancer; R=> reculer; W => wait; F => funny action; L=> Leve pince : B => baisse pince ; T => tourne


#endif // MACHINE_H_INCLUDED
