/*
  AnalogReadSerial
  Reads an analog input on pin 0, prints the result to the serial monitor.
  Graphical representation is available using serial plotter (Tools > Serial Plotter menu)
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

  This example code is in the public domain.
*/

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  // print out the value you read:
  Serial.println(sensorValue);
    delay(1000);        // delay in between reads for stability
// Mat weight
  if ((sensorValue > 300) && (sensorValue < 500))
  {
    Serial.print("Gate close");
    Serial.print("Open dispenser for small dog");
  }
  if ((sensorValue > 500) && (sensorValue < 700))
  {
    Serial.print("Open dispenser for big dog");
  }
    delay(1000);
  }
// Bowl Weight
// if (bowlweight < 110)
// {
//   Serial.print("Gate open");
// }
// if (bowlweight > 110)
// {
//   Serial.print("Gate close");
// }



