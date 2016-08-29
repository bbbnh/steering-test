int duty = 0x80;

void setup() {
  pinMode(10, OUTPUT);
}

void loop() {
  analogWrite(10, duty);
}
