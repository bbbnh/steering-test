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
  int in = analogRead(inPin);
  float duty = 0.75*(in/1023) + 0.125;
  
  return duty;
}

