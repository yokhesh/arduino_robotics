
int LMT_SW2 = 5; 
void setup() {
  // put your setup code here, to run once:
  pinMode(LMT_SW2, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
    Serial.print("ON");
    delay(1000);
    if ((digitalRead(LMT_SW2) == 0))
    {
      delay(1000);
    Serial.print("Wheel Chair in position");
    delay(1000);
    Serial.print("Start the operation");
    }

}
