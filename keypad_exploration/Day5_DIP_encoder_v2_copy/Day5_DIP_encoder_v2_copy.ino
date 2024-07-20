// Author: Tony Barsic
// Date: 25 Dec 2023
// Project: 30 Days In Space, "Day 5"
// Purpose: Use a 3-channel DIP switch to make a binary encoder 
//    (translate the 3 inputs into a numerical value from 0-7). 
//    I am doing this using a function!
//    Next, I will write a 2nd function to modulate LED brightness using duty cycling,
//    And use the binary encoder to control LED brightness.
//
//    For this version of the code, I am just blinking the on-board LED 
//    the number of times corresponding to the encoded value, but modulating 
//    the brightness of a breadboard LED
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

const byte PIN_for_EX_LED = 8;  // pin controlling the external LED

// SETUP = = = = = = = + = = = = = = = + = = = = = = = + = = = = = = = + = = = = = = = +
// = = = = = = = + = = = = = = = + = = = = = = = + = = = = = = = + = = = = = = = + = = =
void setup() {
  // declare the built-in LED as an output
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(PIN_for_EX_LED, OUTPUT);  // pin controlling the external LED
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

  // Now blink the on-board LED some number of times
  my_LED_blinker_Ntimes_onboard(LED_BUILTIN, DIPval);

  // Now blink the breadboard LED some number of times
  // my_LED_dimmer(PIN_for_EX_LED, DIPval*10);
}


// FUNCTION = = = = = = = + = = = = = = = + = = = = = = = + = = = = = = = + = = = = = = = +
// This is my function for taking 3 inputs (on/off) and converting to a 3-bit integer
int my_DIP_3bit_binary_encoder(byte DIP1, byte DIP2, byte DIP3){
  int fun_output;
  fun_output = 4*DIP1 + 2*DIP2 + DIP3;
  return fun_output;
}
// END of my function = = = = = = = + = = = = = = = + = = = = = = = + = = = = = = = + = = =


// FUNCTION = = = = = = = + = = = = = = = + = = = = = = = + = = = = = = = + = = = = = = = +
// This is my function for blinking the on-board LED N times
void my_LED_blinker_Ntimes_onboard(int Pin_to_Blink, int Nblinks){
  for (int k=1; k<=Nblinks; k++) {
    // statement(s);
    digitalWrite(Pin_to_Blink, HIGH);  // turn the LED on (HIGH is the voltage level)
    delay(150);                      // wait for a second
    digitalWrite(Pin_to_Blink, LOW);   // turn the LED off by making the voltage LOW
    delay(150); 
  }
  delay(1000); 
}
// END of my function = = = = = = = + = = = = = = = + = = = = = = = + = = = = = = = + = = =


// FUNCTION = = = = = = = + = = = = = = = + = = = = = = = + = = = = = = = + = = = = = = = +
// This is my function for varying on-board LED brightness using PWM
void my_LED_dimmer(int Pin_to_Blink, int PercentON){

  for (int k=1; k<=10; k++) {
    // statement(s);
    digitalWrite(Pin_to_Blink, HIGH);  // turn the LED on (HIGH is the voltage level)
    delay((PercentON)/10);                      // wait for a second
    digitalWrite(Pin_to_Blink, LOW);   // turn the LED off by making the voltage LOW
    delay(  (100 - PercentON)/10  ); 
  }

}
// END of my function = = = = = = = + = = = = = = = + = = = = = = = + = = = = = = = + = = =


// END OF SKETCH = = = = = = = + = = = = = = = + = = = = = = = + = = = = = = = + = = = = = = = +
// = = = = = = + = = = = = = = + = = = = END OF SKETCH = = = = + = = = = = = = + = = = = = = = +
// = = = = = = = + = = = = = = = + = = = = = = = + = = = = = = + = = = = = = = + = END OF SKETCH 