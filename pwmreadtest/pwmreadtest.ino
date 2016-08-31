/*
 * This test checks the frequency and duty cycle of a PWM signal.
 * 
 * Serial output includes frequency, pulse width, and duty percentage. Input
 * is on pin 14 (A0). Open-drain input is expected; thus, input pullups are
 * enabled. 
 */

const byte inPin = 14;

void setup() {
  pinMode(inPin, INPUT_PULLUP);

  Serial.begin(9600);
}

void loop() {
  // this is a bit of a brute-force method, but it works
  int totalPulse = 0;
  int pulseCount = 0;
  int currentTime = 0;
  int startTime = millis();
  while (currentTime - startTime < 100) {
    totalPulse += pulseIn(inPin, HIGH); // track total pulse-high time
    pulseCount += 1; // track number of pulses
    currentTime = millis();
  }
  int timeDiff = currentTime - startTime;
  float freq = pulseCount / 100.0; // kHz
  int pulse = totalPulse / pulseCount; // microseconds
  float duty = pulse * freq / timeDiff * 10; // percent

  // formatted output
  Serial.print("Frequency\tPulse Width\tDuty\n");
  Serial.print(freq, 3);
  Serial.print(" kHz\t");
  Serial.print(pulse);
  Serial.print(" us\t\t");
  Serial.print(duty);
  Serial.print("%\n\n");
}
