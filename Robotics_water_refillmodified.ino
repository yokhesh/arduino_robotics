// constants won't change. They're used here to set pin numbers:

const int buttonPin = 5;      // the number of the pushbutton pin
//const int buttonPintwo = 4;   // the number of the second pushbutton pin
const int greenPin = 2;         // indicator lightconst int redPin = 2;  
const int yellowPin = 3;  
const int redPin = 4;  
const int cleaningPin = 8;    // this is the output pin on the Arduino to power the cleaning cycle
const int refillPin = 9;      // this is the output pin on the Arduino to power the refill cycle

// variables will change:

//int buttonState = 0;         // variable for reading the pushbutton status
//int buttonStatetwo = 0;

void setup() {

  // initialize the LED pin as an output:
  pinMode(cleaningPin, OUTPUT);
  pinMode(refillPin, OUTPUT);
  pinMode(greenPin, OUTPUT);pinMode(yellowPin, OUTPUT);pinMode(redPin, OUTPUT);
  Serial.begin(9600);
  
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT_PULLUP);
//  pinMode(buttonPintwo, OUTPUT);

}

void loop() {

  // read the state of the pushbutton value:


  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (digitalRead(buttonPin) ==  0) {
Serial.print("Limit switch pressed");
delay(1000);
    // turn LED on:
     digitalWrite(greenPin, HIGH);  
     Serial.print("green led");
    digitalWrite(cleaningPin, HIGH);  //opens valve and turns on water pump of the cleaning cycle
    Serial.print("opening cleaning pin");
   

    delay(5000);                     //runs the cleaning cycle for 10 seconds
 digitalWrite(greenPin, LOW);  
    digitalWrite(cleaningPin, LOW);   //stops the cleaning cycle
    Serial.print("Closing cleaning pin");
 digitalWrite(yellowPin, HIGH);  
 Serial.print("yellow led");
    delay(20000);                     //waits 20 seconds for the container under the wheelchair to be emptied
 digitalWrite(yellowPin, LOW);  
  digitalWrite(redPin, HIGH);  
    digitalWrite(refillPin, HIGH);    //opens valve and turns on water pump of the refill cycle
    Serial.print("opening refill pin");
    Serial.print("red led");

    delay(5000);                     //runs the refill cycle for 10 seconds

    digitalWrite(refillPin, LOW);     //stops the cleaning cycle
    Serial.print("Closing refill pin");
    digitalWrite(redPin, LOW);
    
    delay(1000);                      //Wait 1 Second

  } 
}

