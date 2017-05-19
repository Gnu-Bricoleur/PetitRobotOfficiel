#ifndef ACTI_H_INCLUDED
#define ACTI_H_INCLUDED

#include <Arduino.h>
#include <Servo.h>
#include "define.h"

void InitActionneurs();
void LassoHaut();
void LassoBas();
void JoueFunnyAction();


Servo Lasso;
Servo FunnyAction;


#endif // ACTI_H_INCLUDED
