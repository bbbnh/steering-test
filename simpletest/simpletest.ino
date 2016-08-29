int duty = 0x40;

void setup() {
  pinMode(10, OPEN);
  pinMode(9, OPEN);
  analogWriteFrequency(400);
  analogWriteResolution(8);
}

void loop() {
  analogWrite(10, duty);
  analogWrite(9, 0xff - duty);
}
