#ifndef ASSERT_H_INCLUDED
#define ASSERT_H_INCLUDED

#include "Arduino.h"
#include "define.h"
#include <SimpleTimer.h>

void InitAsssert();
void RouleDroit();
void Tourne();
void LireCodeuse();
void splitString(String message, char separator, String *data);
void PeriodiqueAssert();
void RaZErreur();
void ReculeDroit();
void RouleDroitBO();
void ReculeDroitBO();


SimpleTimer timer;


#endif // ASSERT_H_INCLUDED
