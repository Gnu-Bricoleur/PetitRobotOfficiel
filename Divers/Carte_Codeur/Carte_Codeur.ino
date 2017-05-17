
int32_t Codeur_total1=0;

int32_t Codeur_total2=0;

String inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete
void setup() {
  pinMode(4, INPUT);
  pinMode(2, INPUT_PULLUP);
    pinMode(5, INPUT);
  pinMode(3, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(2), Codeur1, RISING);
   attachInterrupt(digitalPinToInterrupt(3), Codeur2, RISING);
  Serial.begin(115200);
}

void loop() {
    if (stringComplete) {
      if(inputString=="C")
      {
       Serial.print("C;");
       Serial.print(Codeur_total1);
       Serial.print(";");
       Serial.print(Codeur_total2);
       Serial.print("\n");
      }
      else if(inputString=="r"||inputString=="R")
      {
         Codeur_total1=0;
         Codeur_total2=0;
      }

    // clear the string:
    inputString = "";
    stringComplete = false;
  }


}

void Codeur1() {
  if(digitalRead(4)==HIGH)
  {
    Codeur_total1++;
  }
  if(digitalRead(4)==LOW)
  {
    Codeur_total1--;
  }
}

void Codeur2() {
  if(digitalRead(5)==HIGH)
  {
    Codeur_total2++;
  }
  if(digitalRead(5)==LOW)
  {
    Codeur_total2--;
  }
}

void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    // add it to the inputString:

    // if the incoming character is a newline, set a flag
    // so the main loop can do something about it:
    if (inChar == '\n') {
      stringComplete = true;}
    else
      inputString += inChar;

  }
}
