#define VITESSE 340 //vitesse du son 340 m/s

const int USTrig = 8; // Déclencheur sur la broche 8
const int USEcho = 9; // Réception sur la broche 9
const int USTrig2 = 10; // Déclencheur sur la broche 10
const int USEcho2 = 11; // Réception sur la broche 11
float temps1;
float temps2;
float distance1;
float distance2;
unsigned long duree1;
unsigned long duree2;
const int avant = 7;
const int arriere = 6;
const int avantled = 5;
const int arriereled = 4;



void setup() {
    pinMode(USTrig, OUTPUT);
    pinMode(USEcho, INPUT);
    pinMode(USTrig2, OUTPUT);
    pinMode(USEcho2, INPUT);
    pinMode(avant,OUTPUT);
    pinMode(arriere,OUTPUT);
    pinMode(avantled,OUTPUT);
    pinMode(arriereled,OUTPUT);
    
    digitalWrite(USTrig, LOW);
    digitalWrite(USTrig2, LOW);
    digitalWrite(avant, LOW);
    digitalWrite(arriere, LOW);
    digitalWrite(avantled, LOW);
    digitalWrite(arriereled, LOW);
    Serial.begin(9600);
}

void loop()
{
   // 1. Un état haut de 10 microsecondes est mis sur la broche "Trig"
   digitalWrite(USTrig, HIGH);
   delayMicroseconds(10); //on attend 10 µs
   // 2. On remet à l’état bas la broche Trig
   digitalWrite(USTrig, LOW);  
   // 3. On lit la durée d’état haut sur la broche "Echo"
   duree1 = pulseIn(USEcho, HIGH);

    if(duree1 > 30000)
   {
      // si la durée est supérieure à 30ms, l'onde est perdue
      Serial.println("Onde perdue, mesure échouée !");
   }
   else
   {
      // 4. On divise cette durée par deux pour n'avoir qu'un trajet
      duree1 = duree1/2;
      // 5. On calcule la distance 
      temps1 = duree1/10000.0; //on met en secondes
      distance1 = temps1*VITESSE; //on multiplie par la vitesse
      // 6. On affiche la distance
      /*Serial.print("Duree = ");
      Serial.println(temps); //affiche le temps de vol d'un trajet en secondes*/
      //Serial.print("Distance avant = ");
      //Serial.println(distance1); //affiche la distance mesurée (en centimètres)
      
   }

   if(distance1<20.0){
      digitalWrite(avant,HIGH);
      digitalWrite(avantled,HIGH);
   }
   else{
      digitalWrite(avant,LOW);
      digitalWrite(avantled,LOW);
   }

   //2ème télémètre ultrason
   digitalWrite(USTrig2, HIGH);
   delayMicroseconds(10); //on attend 10 µs
   digitalWrite(USTrig2, LOW);
   duree2 = pulseIn(USEcho2, HIGH);
   Serial.println(duree2);

   if(duree2 > 30000){
      // si la durée est supérieure à 30ms, l'onde est perdue
      Serial.println("Onde perdue, mesure échouée !");
   }
   else{
      duree2 = duree2/2;
      temps2 = duree2/10000.0; //on met en secondes
      distance2 = temps2*VITESSE; //on multiplie par la vitesse
      //Serial.println(distance2);
   }
  if(distance2<20.0){
      digitalWrite(arriere,HIGH);
      digitalWrite(arriereled,HIGH);
   }
   else{
      digitalWrite(arriere,LOW);
      digitalWrite(arriereled,LOW);
   }
   
}
