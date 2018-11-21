# include <Servo.h>
Servo dispservo;
int DIR_PIN = 12;
int PWM_PIN = 10;
int LMT_SW_OPEN_PIN = 4;
int LMT_SW_CLOS_PIN = 5; 
int PWM_val = 0;
void setup() {
  Serial.begin(9600);
  pinMode(DIR_PIN, OUTPUT);
  pinMode(PWM_PIN, OUTPUT);
  
  pinMode(LMT_SW_OPEN_PIN, INPUT_PULLUP);
  pinMode(LMT_SW_CLOS_PIN, INPUT_PULLUP);
}
// This Closes the Gate
void forward() {
  // Forward -> PWM = H && DIR = L
  analogWrite(PWM_PIN, PWM_val);
  digitalWrite(DIR_PIN, LOW);
}

// This Opens the Gate
void reverse() {
  // Reverse -> PWM = H && DIR = H
  analogWrite(PWM_PIN, PWM_val);
  digitalWrite(DIR_PIN, HIGH);
}

// This Stops the Gate
void stopgate() {
  // Reverse -> PWM = H && DIR = H
  analogWrite(PWM_PIN, 0);
}


void loop() {
  PWM_val = 255;
  int matsensor = analogRead(A0);
  Serial.println(matsensor);  
  delay(1000);
      
// Fluffer
if (matsensor > 150)
{
  delay(5000);
  int matsensor = analogRead(A0);
  Serial.println(matsensor); 

  if ((matsensor >155) && (matsensor <= 400))
  {
    Serial.print("Fluffers eating first");
    Serial.print("Gate close");
    while (digitalRead(LMT_SW_OPEN_PIN) == 1)
    {
      forward();
    }
    Serial.print("Limit switch pressed during gate close");
    stopgate();
    delay(1000);
    dispservo.attach(11);
    dispservo.write(180);
    Serial.print("Open dispenser for small dog");
    delay(3000);
    Serial.print("Close dispenser for small dog");
    dispservo.write(115);
    delay(3000);
    int smallbowlsensor = analogRead(A1);
    Serial.println(smallbowlsensor);
    while(smallbowlsensor > 115)
    {
      
      smallbowlsensor = analogRead(A1);
      Serial.println(smallbowlsensor);
      Serial.println("Fluffer still eating");
    }
    Serial.println("Gate is opened after fluffer completed eating");
    while (digitalRead(LMT_SW_CLOS_PIN) == 1)
    {
     reverse();
    }
    Serial.print("Limit switch pressed during gate open");
    stopgate();
    delay(5000);

    Serial.println("It takes 10 seconds for the systems to reset");
    // Giving some time for the dog to get out.
    matsensor = analogRead(A0);
    while (matsensor < 400)
    {
       matsensor = analogRead(A0);
       Serial.println(matsensor);
      Serial.println("Brutus not in the cage");
    }
    delay(6000);
    dispservo.attach(11);
    dispservo.write(50);
    Serial.print("Open dispenser for Big dog");

    delay(3000);
    Serial.print("Close dispenser for Big dog");
    dispservo.write(115);
    matsensor = analogRead(A0);
    while (matsensor > 400)
    {
      matsensor = analogRead(A0);
      Serial.println(matsensor);
      Serial.println("Brutus still eating");
    }
    Serial.println("Brutus completed eating");

  }


 // Brutus
  
  if (matsensor > 400)
  {
    dispservo.attach(11);
    dispservo.write(50);
    Serial.print("Open dispenser for Big dog");

    delay(5000);
    Serial.print("Close dispenser for Big dog");
    dispservo.write(115);

    while (matsensor > 400)
    {
      matsensor = analogRead(A0);
      Serial.println(matsensor);
      Serial.println("Brutus still eating");
    }
    Serial.println("Brutus completed eating");
    Serial.println("It takes 10 seconds for the systems to reset");
   delay(10000);
    Serial.print("Gate close");
    while (digitalRead(LMT_SW_OPEN_PIN) == 1)
    {
      forward();
    }
    Serial.print("Limit switch pressed during gate close");
    stopgate();
     matsensor = analogRead(A0);
     while (matsensor <155)
    {
      matsensor = analogRead(A0);
      Serial.println("Fluffers not in the cage");
      delay(2000);
      Serial.println(matsensor);
    }
    delay(4000);
    dispservo.attach(11);
    dispservo.write(180);
    Serial.print("Open dispenser for small dog");
    delay(3000);
    Serial.print("Close dispenser for small dog");
    dispservo.write(115);
    delay(5000);
    int smallbowlsensor = analogRead(A1);
        while(smallbowlsensor > 115)
    {
      
      smallbowlsensor = analogRead(A1);
      Serial.println(smallbowlsensor);
      Serial.println("Fluffer still eating");
    }
    Serial.println("Gate is opened after fluffer completed eating");
    while (digitalRead(LMT_SW_CLOS_PIN) == 1)
    {
     reverse();
    }
    Serial.print("Limit switch pressed during gate open");
    stopgate();
    delay(6000);
  }
}
    delay(1000);
  }



