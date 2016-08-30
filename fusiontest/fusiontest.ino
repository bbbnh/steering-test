/*
   This is a preliminary version of the Ford Fusion steering
   gear test interface. This is a re-write which uses
   the new analogWriteFrequency and analogWriteResolution
   functions instead of writing to the clock/timer registers
   directly. Hopefully, this will simplify things and allow
   for easier readability.

   The sketch is intended to read an analog input from a
   potentiometer on inPin and output a PWM signal on pwmPin
   with the defined frequency and resolution. The duty cycle
   should be between 47% and 53%.

   This code is written with the uC32 in mind; the function
   analogWriteFrequency() takes only one argument here.
*/

const int inPin = A0;
const int pwmPin1 = 9;
const int pwmPin2 = 10;
const int freq = 2000; // correct frequency
const int res = 12; // resolution
const int scale = pow(2, res);
const int low = scale * 0.4;
const int high = scale * 0.6;

void setup() {
  pinMode(inPin, INPUT);
  pinMode(pwmPin1, OPEN);
  pinMode(pwmPin2, OPEN);

  analogWriteFrequency(freq);
  analogWriteResolution(res);

  /*
  Serial.begin(9600);
  
  Serial.print(high);
  Serial.print("\n");\
  Serial.print(low);
  Serial.print("\n");
  */
}

void loop() {
  int volt = analogRead(inPin);
  int bits = map(volt, 0, 1024, low, high);
  analogWrite(pwmPin1, bits);
  analogWrite(pwmPin2, pow(2, res) - bits);
  delay(100);
}
