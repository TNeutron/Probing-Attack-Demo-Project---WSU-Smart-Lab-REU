#define attackpin 5
#define ModeSel 2

#define ControlMode 0
#define FloatingMode 1 

void attack(){

  digitalWrite(ModeSel, ControlMode);

  // 011 0001 --> 1

  // start bit - 0
  digitalWrite(attackpin, 0);
  delayMicroseconds(104);

  // d0 = 1
  digitalWrite(attackpin, 1);
  delayMicroseconds(104);

  // d54 = 000
  digitalWrite(attackpin, 0);
  delayMicroseconds(104*3);

  // d321 = 11
  digitalWrite(attackpin, 1);
  delayMicroseconds(104*2);

  //d6 = 1
  digitalWrite(attackpin, 0);
  delayMicroseconds(104);
  
  // parity - 0
  digitalWrite(attackpin, 0);
  delayMicroseconds(104);

  //stop bit - 1
  digitalWrite(attackpin, 1);
  delayMicroseconds(104);

  digitalWrite(ModeSel, FloatingMode);
}

void setup() {
  pinMode(attackpin, OUTPUT);
  pinMode(ModeSel, OUTPUT);

  digitalWrite(ModeSel, FloatingMode);
  digitalWrite(attackpin, 1);

}

void loop() {
  delay(1000);
  attack();
  attack();
}
