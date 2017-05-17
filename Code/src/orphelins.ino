

void Mise_A_Jour_Tirette()
{
    //Serial.println("Waiting Tirette");
  if(digitalRead(GPIO_TIRRETTE)==LOW)
  {
    //Serial.println("GOOOO");
    if(digitalRead(GPIO_COULEUR_JAUNE)==LOW)
    {
      //Couleur Jaune
          //Serial.println("yellow");
    }
    else if(digitalRead(GPIO_COULEUR_BLEU)==LOW)
    {
      //Serial.println("Blue");
      //Couleur Bleu
    }
    Robot_Principal=En_Route;
  }
}
