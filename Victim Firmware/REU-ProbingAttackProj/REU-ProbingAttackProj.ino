#define AnalogPin 2
#define LEDPin 15

void setup() {
  Serial.begin(9600);
  pinMode(LEDPin, OUTPUT);
}

void loop() {
  int val = analogRead(AnalogPin);

  Serial.println(val);

  if(val > 10) digitalWrite(LEDPin, 1);
  else digitalWrite(LEDPin, 0);

  delay(200);

}
