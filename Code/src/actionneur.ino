#include "actionneur.h"


void InitActionneurs()
{
  Lasso.attach(LassoPin);
  FunnyAction.attach(FunnyActionPin);
  Lasso.write(0);
  FunnyAction.write(0);
}


void LassoHaut()
{
  Lasso.write(0);
  EtatComplete = true;
}

void LassoBas()
{
  Lasso.write(85);
  EtatComplete = true;
}


void JoueFunnyAction()
{
  FunnyAction.write(20);
  delay(30);
  FunnyAction.write(0);
}
