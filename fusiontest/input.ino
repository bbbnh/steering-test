/*
 * This handles the input department.
 * 
 * Features will inlcude multiple types of inputs, ideally
 * using a single input pin and a set of type selection
 * switches to handle which type of input to use.
 */

int input() {
  /*
   * This function will eventually be expanded to allow
   * translation of multiple types of inputs, probably
   * through the use of type selection switches.
   */
  int volt = analogRead(inPin);
  int duty = volt * pow(2, res) / 1023;
  
  return duty;
}

