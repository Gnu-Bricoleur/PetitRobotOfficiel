#include "actionneur.h"


void InitActionneurs()
{
  Lasso.attach(LassoPin);
  FunnyAction.attach(FunnyActionPin);
  LassoHaut();
  EtatComplete = false;
  FunnyAction.write(90);
}


void LassoHaut()
{
  Serial.println("LassoHaut");
  Lasso.write(130);
  EtatComplete = true;
  delay(500);

}

void LassoBas()
{
  Serial.println("LassoBas");
  Lasso.write(90);
  EtatComplete = true;
    delay(500);
}


void JoueFunnyAction()
{
  Serial.println("FunnyAction");
  FunnyAction.write(180);
  delay(800);
  FunnyAction.write(90);
  EtatComplete = true;
  Serial.println("Fin du match !");
}
