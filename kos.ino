const int rpin = 4;  // Analog input pin that the potentiometer is attached to
int br=-1;
int sensorValue = 0;        // value read from the pot
int outputValue = 0;        // value output to the PWM (analog out)
int niz[10]={5,19,23,22,15,14,13,12,26,27};

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
  for(int x=0;x<10;x++)
    pinMode(niz[x],OUTPUT);
}

void loop() {
  // read the analog in value:
  sensorValue = analogRead(rpin);
  // map it to the range of the analog out:
  outputValue = map(sensorValue, 1000, 1200, 0, 255);
  // change the analog out value:

  // print the results to the serial monitor:
 Serial.print("sensor = ");
  Serial.print(sensorValue);
  Serial.print("\t output = ");
  Serial.println(outputValue);

  // wait 2 milliseconds before the next loop
  // for the analog-to-digital converter to settle
  // after the last reading:
  if(outputValue>200)
  {
    br++;
    digitalWrite(niz[br-1],LOW);
    digitalWrite(niz[br],HIGH);
    Serial.println('KOS');
    Serial.println(br);
    if(br==9)
    {
      for(int y=0;y<2;y++)
      {
        for(int x=9;x>=0;x--)
        {
            digitalWrite(niz[x+1],LOW);
            digitalWrite(niz[x],HIGH);
            delay(150);
        }
         for(int x=0;x<10;x++)
        {
            digitalWrite(niz[x-1],LOW);
            digitalWrite(niz[x],HIGH);
            delay(150);
        }        
      }

        digitalWrite(niz[9],LOW);
        br=-1;
    }
    delay(5000);
  }
  delay(20);

}
