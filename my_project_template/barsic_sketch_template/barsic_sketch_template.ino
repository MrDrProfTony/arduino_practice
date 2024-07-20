// Author: Tony Barsic
// Date: 27 Dec 2023
// Project: Sketch Template (blinker)
// Purpose: - Make a general format for Sketches.
//          - Have a "baseline" program to leave on the board at all times.

#include "Arduino.h"  // include information about our HERO

const byte PIN_for_Onboard_LED = 13;  // pin controlling the on-board LED
// some morse code timing values:
const int morse_ON_short = 200; // ms
const int morse_ON_long  = 400; // ms
const int morse_space_letter  = 200; // ms
const int morse_space_word  = 500; // ms


// SETUP = = = = = = = + = = = = = = = + = = = = = = = + = = = = = = = + = = = = = = = +
// = = = = = = = + = = = = = = = + = = = = = = = + = = = = = = = + = = = = = = = + = = =
void setup() {
  // declare the built-in LED as an output
  // pinMode(LED_BUILTIN, OUTPUT); // This would work too
  pinMode(PIN_for_Onboard_LED, OUTPUT);  // pin controlling the on-board LED
}
// = = = = = = = + = = = = = = = + = = = = = = = + = = = = = = = + = = = = = = = + = = =
// = = = = = = = + = = = = = = = + = = = = = = = + = = = = = = = + = = = = = = = + = = =



// MAIN LOOP = = = = = = = + = = = = = = = + = = = = = = = + = = = = = = = + = = = = = = = +
// = = = = = = = + = = = = = = = + = = = = = = = + = = = = = = = + = = = = = = = + = = = = =
void loop() {
  // put your main code here, to run repeatedly:

  // blink a few times
  //my_LED_blinker_wTimes(PIN_for_Onboard_LED, morse_ON_short, morse_space_letter);
  //my_LED_blinker_wTimes(PIN_for_Onboard_LED, morse_ON_short, morse_space_letter);
  //my_LED_blinker_wTimes(PIN_for_Onboard_LED, morse_ON_short, morse_space_letter);

  // blink an SOS
  my_LED_blinker_S(PIN_for_Onboard_LED);
  delay(morse_space_letter);
  my_LED_blinker_O(PIN_for_Onboard_LED);
  delay(morse_space_letter);
  my_LED_blinker_S(PIN_for_Onboard_LED);

  // pause between loops
  delay(1000);
}
// = = = = = = = + = = = = = = = + = = = = = = = + = = = = = = = + = = = = = = = + = = =
// = = = = = = = + = = = = = = = + = = = = = = = + = = = = = = = + = = = = = = = + = = =



// FUNCTION = = = = = = = + = = = = = = = + = = = = = = = + = = = = = = = + = = = = = = = +
// This is my function for blinking the on-board LED in an S pattern
void my_LED_blinker_S(int Pin_to_Blink){
  // 3 short beeps

  /* // The manual way:
  for (int k=1; k<=3; k++) {
    digitalWrite(Pin_to_Blink, HIGH);  // turn the LED on (HIGH is the voltage level)
    delay(morse_ON_short);                      // wait for a second
    digitalWrite(Pin_to_Blink, LOW);   // turn the LED off by making the voltage LOW
    delay(morse_space_letter);
  }*/

  /* // The easy way:
  my_LED_blinker_wTimes(PIN_for_Onboard_LED, morse_ON_short, morse_space_letter);
  my_LED_blinker_wTimes(PIN_for_Onboard_LED, morse_ON_short, morse_space_letter);
  my_LED_blinker_wTimes(PIN_for_Onboard_LED, morse_ON_short, morse_space_letter);
  */

  // Yet another way
  for (int k=1; k<=3; k++) {
    my_LED_blinker_wTimes(PIN_for_Onboard_LED, morse_ON_short, morse_space_letter);
  }
}
// END of my function = = = = = = = + = = = = = = = + = = = = = = = + = = = = = = = + = = =



// FUNCTION = = = = = = = + = = = = = = = + = = = = = = = + = = = = = = = + = = = = = = = +
// This is my function for blinking the on-board LED in an o pattern
void my_LED_blinker_O(int Pin_to_Blink){
  // 3 long beeps
  my_LED_blinker_wTimes(PIN_for_Onboard_LED, morse_ON_long, morse_space_letter);
  my_LED_blinker_wTimes(PIN_for_Onboard_LED, morse_ON_long, morse_space_letter);
  my_LED_blinker_wTimes(PIN_for_Onboard_LED, morse_ON_long, morse_space_letter);
}
// END of my function = = = = = = = + = = = = = = = + = = = = = = = + = = = = = = = + = = =



// FUNCTION = = = = = = = + = = = = = = = + = = = = = = = + = = = = = = = + = = = = = = = +
// This is my function for blinking the on-board LED 
void my_LED_blinker_wTimes(int Pin_to_Blink, int ON_ms, int OFF_ms){
  digitalWrite(Pin_to_Blink, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(ON_ms);                      // wait for a second
  digitalWrite(Pin_to_Blink, LOW);   // turn the LED off by making the voltage LOW
  delay(OFF_ms); 
}
// END of my function = = = = = = = + = = = = = = = + = = = = = = = + = = = = = = = + = = =



// END OF SKETCH = = = = = = = + = = = = = = = + = = = = = = = + = = = = = = = + = = = = = = = +
// = = = = = = + = = = = = = = + = = = = END OF SKETCH = = = = + = = = = = = = + = = = = = = = +
// = = = = = = = + = = = = = = = + = = = = = = = + = = = = = = + = = = = = = = + = END OF SKETCH 