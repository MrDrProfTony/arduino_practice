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

// These constant arrays contain the pins connected to the keypad's row and column pins.
const byte ROW_1 = 2;  // digital pin for common row "rail" (determined by breadboard wiring)
const byte BUTTON_1 = 6;  // digital pin for button 1 (determined by breadboard wiring)
const byte BUTTON_2 = 7;  // digital pin for button 2

// Our SIMPLIFIED keypad has 1 rows, each with 2 columns.
const byte ROWS = 1;
const byte COLS = 2;
// Uuse a two dimensional array to
// configure what character will be returned when each button is pressed.
const char BUTTON_MAP[ROWS][COLS] = {
  { '1', '2'},  // Row 0
};

void setup() {
  Serial.begin(9600);  // Initialize the serial monitor

  // Configure the row "rail" (common to all buttons) as OUTPUT
  pinMode(ROW_1, OUTPUT);  // pin connected to button 1
  // Configure the switch pins as INPUT pins
  pinMode(BUTTON_1, INPUT);  // pin connected to button 1
  pinMode(BUTTON_2, INPUT);  // pin connected to button 2
}

void loop() {
  // set the rail to HIGH
  digitalWrite(ROW_1, HIGH);


  // We also need to make sure the input pins are "reset"
  // this was added as an afterthought, since we were getting multiple outputs pre press
  pinMode(BUTTON_1, OUTPUT);
  pinMode(BUTTON_2, OUTPUT);
  digitalWrite(BUTTON_1, LOW);
  digitalWrite(BUTTON_2, LOW);
  pinMode(BUTTON_1, INPUT);
  pinMode(BUTTON_2, INPUT);


  // read the values of the 2 input pins
  byte BUT1_val = digitalRead(BUTTON_1);
  byte BUT2_val = digitalRead(BUTTON_2);


  // reset the output variable
  bool keyTF = false;
  char keypress = 'x';

  // check for keypress
  if (BUT1_val == 1 || BUT2_val == 1){
    keyTF = true;
  }

  // interpret those inputs
  if (keyTF) {
    // set the output value
    keypress = '1';
    // Display the character returned for the button that was pressed.
    Serial.println(keypress);

    // build in a delay so we don't get so many repeats
    delay(300); 
  }

  
  

  
}


// ===+=== ===+=== ===+=== END OF SKETCH ===+=== ===+=== ===+===
// ===+=== ===+=== ===+=== END OF SKETCH ===+=== ===+=== ===+===
// ===+=== ===+=== ===+=== END OF SKETCH ===+=== ===+=== ===+===