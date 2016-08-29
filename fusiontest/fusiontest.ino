/*
 * This is a preliminary version of the Ford Fusion steering
 * gear test interface. This is a re-write which uses
 * the new analogWriteFrequency and analogWriteResolution
 * functions instead of writing to the clock/timer registers
 * directly. Hopefully, this will simplify things and allow
 * for easier readability.
 * 
 * The sketch is intended to read an analog input from a
 * potentiometer on inPin and output a PWM signal on pwmPin
 * with the defined frequency and resolution. The duty cycle
 * should be between 12.5% and 87.5%, or 0x20 to 0xE0.
 * 
 * This code is written with the uC32 in mind; the function
 * analogWriteFrequency() takes only one argument here.
 */

const int freq = 1900; // arbitrary value for frequency; will be updated
const int res = 8; // resolution, 8 bits should be fine
const int inPin = A0;
const int pwmPin1 = 9;
const int pwmPin2 = 10;

void setup() {
  pinMode(inPin, INPUT);
  pinMode(pwmPin1, OPEN);
  pinMode(pwmPin2, OPEN);
  
  analogWriteFrequency(freq);
  analogWriteResolution(res);
}

void loop() {
  float duty = input();
  int bits = pow(2, res) * duty;
  analogWrite(pwmPin1, bits);
  analogWrite(pwmPin2, pow(2, res) - bits);
}

