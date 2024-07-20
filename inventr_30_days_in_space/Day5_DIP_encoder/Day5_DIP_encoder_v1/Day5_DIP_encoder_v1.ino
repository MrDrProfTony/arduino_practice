// Author: Tony Barsic
// Date: 25 Dec 2023
// Project: 30 Days In Space, "Day 5"
// Purpose: Use a 3-channel DIP switch to make a binary encoder 
//    (translate the 3 inputs into a numerical value from 0-7). 
//    I am doing this using a function!
//    Next, I will write a 2nd function to modulate LED brightness using duty cycling,
//    And use the binary encoder to control LED brightness.
//
//    For this initial version of the code, I am just blinking the LED 
//    the number of times corresponding to the encoded value.
//
//    The physical layout includes a breadboard with the DIP switch, 
//    One side of the DIP tied to 5V, 
//    The other side of the switch tied to ground through 10k resistors.
//    The digital pins of the Arduino Uno are connected between the DIP and the resistors.
//    Open switch means the circuit is open, and the digital pins see ground.
//    Closed switch completed the (5V)-(10k resistor)-(ground) circuit, and the digital pins
//    see HIGH (5V).

#include "Arduino.h"  // include information about our HERO

const byte DIP_1 = 2;  // digital pin for DIP switch 1 (determined by breadboard wiring)
const byte DIP_2 = 3;  // digital pin for DIP switch 2
const byte DIP_3 = 4;  // digital pin for DIP switch 3


// SETUP = = = = = = = + = = = = = = = + = = = = = = = + = = = = = = = + = = = = = = = +
// = = = = = = = + = = = = = = = + = = = = = = = + = = = = = = = + = = = = = = = + = = =
void setup() {
  // declare the built-in LED as an output
  pinMode(LED_BUILTIN, OUTPUT);
  // Configure the switch pins as INPUT pins
  pinMode(DIP_1, INPUT);    // pin connected to switch 1 (cabin lights)
  pinMode(DIP_2, INPUT);  // pin connected to switch 2 (storage lights)
  pinMode(DIP_3, INPUT);  // pin connected to switch 3 (exterior lights)
}


// MAIN LOOP = = = = = = = + = = = = = = = + = = = = = = = + = = = = = = = + = = = = = = = +
// = = = = = = = + = = = = = = = + = = = = = = = + = = = = = = = + = = = = = = = + = = = = =
void loop() {
  // put your main code here, to run repeatedly:
  // byte DIP1_val = digitalRead(DIP_1);
  // byte DIP2_val = digitalRead(DIP_2);
  // byte DIP3_val = digitalRead(DIP_3);

  // int DIPval;
  // DIPval = my_DIP_3bit_binary_encoder(DIP1_val, DIP2_val, DIP3_val);

  int DIPval;
  DIPval = my_DIP_3bit_binary_encoder(digitalRead(DIP_1), digitalRead(DIP_2), digitalRead(DIP_3));

  // Now blink the LED some number of times
  for (int k=1; k<=DIPval; k++) {
    // statement(s);
    digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
    delay(200);                      // wait for a second
    digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW
    delay(200); 
  }
  delay(2000); 
}


// FUNCTION = = = = = = = + = = = = = = = + = = = = = = = + = = = = = = = + = = = = = = = +
// This is my function for taking 3 inputs (on/off) and converting to a 3-bit integer
int my_DIP_3bit_binary_encoder(byte DIP1, byte DIP2, byte DIP3){
  int fun_output;
  fun_output = 4*DIP1 + 2*DIP2 + DIP3;
  return fun_output;
}
// END of my function = = = = = = = + = = = = = = = + = = = = = = = + = = = = = = = +


// END OF SKETCH = = = = = = = + = = = = = = = + = = = = = = = + = = = = = = = + = = = = = = = +
// = = = = = = + = = = = = = = + = = = = END OF SKETCH = = = = + = = = = = = = + = = = = = = = +
// = = = = = = = + = = = = = = = + = = = = = = = + = = = = = = + = = = = = = = + = END OF SKETCH 