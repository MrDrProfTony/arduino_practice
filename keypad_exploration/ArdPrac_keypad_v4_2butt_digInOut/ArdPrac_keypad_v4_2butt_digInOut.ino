/*
 * Dr. Anthony Barsic
 * University of Vermont
 * Department of Electrical Engineering
 * CMPE 3815
 * 2024 June 22
 * The purpose of this script is to read a value from a 2-button keypad.
 * This is a step in a series of sketches that break down the keypad reading without using a library.
 */

// INIT and SETUP ===+=== ===+=== ===+=== ===+=== ===+=== ===+=== ===+=== ===+=== ===+=== ===+=== ===+===

// Explicitly include Arduino.h
#include "Arduino.h"

// These constant arrays contain the pins connected to the keypad's row and column pins.
const byte ROW_1 = 2;  // digital pin for common row "rail" (determined by breadboard wiring)
const byte BUTTON_1 = 6;  // digital pin for button 1 (determined by breadboard wiring)
const byte BUTTON_2 = 7;  // digital pin for button 2

void setup() {
  Serial.begin(9600);  // Initialize the serial monitor

  // Configure the row "rail" (common to all buttons) as OUTPUT
  pinMode(ROW_1, OUTPUT);  // pin connected to button 1
  // Configure the switch pins as INPUT pins
  pinMode(BUTTON_1, INPUT);  // pin connected to button 1
  pinMode(BUTTON_2, INPUT);  // pin connected to button 2
}



// LOOP ===+=== ===+=== ===+=== ===+=== ===+=== ===+=== ===+=== ===+=== ===+=== ===+=== ===+===

void loop() {
  // Section L1: Read values from digital pins ===+=== ===+=== ===+=== ===+=== ===+=== ===+=== ===+=== 

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


  // Section L2: Interpret digitral inputs ===+=== ===+=== ===+=== ===+=== ===+=== ===+=== ===+=== 

  // reset the output variable
  char keypress = '.';

  // interpret those inputs
  if (BUT1_val == 1) {
    // set the output value
    keypress = '1';
  }
  else if (BUT2_val == 1) {
    // set the output value
    keypress = '2';
  }


  // Section L3: Display output to serial monitor ===+=== ===+=== ===+=== ===+=== ===+=== ===+=== ===+=== 

  if (keypress != '.'){
    // Display the character returned for the button that was pressed.
    Serial.println(keypress);
    // build in a delay so we don't get so many repeats
    delay(300); 
  }
  
}
// ===+=== ===+=== ===+=== END OF SKETCH ===+=== ===+=== ===+===
// ===+=== ===+=== ===+=== END OF SKETCH ===+=== ===+=== ===+===
// ===+=== ===+=== ===+=== END OF SKETCH ===+=== ===+=== ===+===