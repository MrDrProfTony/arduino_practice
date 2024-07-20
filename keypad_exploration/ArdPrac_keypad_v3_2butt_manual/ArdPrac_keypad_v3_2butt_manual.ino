/*
 * Dr. Anthony Barsic
 * University of Vermont
 * Department of Electrical Engineering
 * CMPE 3815
 * 2024 June 22
 * The purpose of this script is to read a value from a 2-button keypad.
 * This is a step in a series of sketches that break down the keypad reading without using a library.
 */

// Explicitly include Arduino.h
#include "Arduino.h"

/*
// Our SIMPLIFIED keypad has 1 rows, each with 2 columns.
const byte ROWS = 1;
const byte COLS = 2;*/

// These constant arrays contain the pins connected to the keypad's row and column pins.
const byte BUTTON_1 = 2;  // digital pin for button 1 (determined by breadboard wiring)
const byte BUTTON_2 = 3;  // digital pin for button 2

/*
// Use a two dimensional array to
// configure what character will be returned when each button is pressed.
const char BUTTONS[ROWS][COLS] = {
  { '1', '2'},  // Row 0
};
*/

void setup() {
  Serial.begin(9600);  // Initialize the serial monitor

    // Configure the switch pins as INPUT pins
  pinMode(BUTTON_1, INPUT);  // pin connected to button 1
  pinMode(BUTTON_2, INPUT);  // pin connected to button 2
}

void loop() {
  // read the values of the 2 input pins
  byte BUT1_val = digitalRead(BUTTON_1);
  byte BUT2_val = digitalRead(BUTTON_2);
  // reset the output variable
  char keypress = 'x';

  // interpret those inputs
  if (BUT1_val == 1) {
    // set the output value
    keypress = '1';
    // Display the character returned for the button that was pressed.
    Serial.println(keypress);
  }
  else if (BUT2_val == 1) {
    // set the output value
    keypress = '2';
    // Display the character returned for the button that was pressed.
    Serial.println(keypress);
  }

  
  

  // build in a delay so we don't get so manyt repeats
  delay(200); 
}


// ===+=== ===+=== ===+=== END OF SKETCH ===+=== ===+=== ===+===
// ===+=== ===+=== ===+=== END OF SKETCH ===+=== ===+=== ===+===
// ===+=== ===+=== ===+=== END OF SKETCH ===+=== ===+=== ===+===