/*
 * Dr. Anthony Barsic
 * University of Vermont
 * Department of Electrical Engineering
 * CMPE 3815
 * 2024 June 22
 * The purpose of this script is to read a value from a 2-button keypad.
 * This is based on code provided as part of Arduino's "30 days Lost in Space" kit, 
 * which includes a keypad routine.
 * This code is a simplified version of that.
 */

// Explicitly include Arduino.h
#include "Arduino.h"

// This is their library, which takes care of a lot of the details of pin interaction and conversion
#include <Keypad.h>

// Our SIMPLIFIED keypad has 1 rows, each with 2 columns.
const byte ROWS = 1;
const byte COLS = 2;

// These constant arrays contain the pins connected to the keypad's row and column pins.
const byte ROW_PINS[ROWS] = { 5};
const byte COL_PINS[COLS] = { 6, 7};


// Uuse a two dimensional array to
// configure what character will be returned when each button is pressed.
const char BUTTONS[ROWS][COLS] = {
  { '1', '2'},  // Row 0
};

/*
 * Using the Keypad.h Library, we are going to define a custom keypad to return
 * the characters we wish when each key is pressed.
 *
 * To do this, we create a heroKeypad object configured with our BUTTONS array,
 * the pins used for the rows and columns and lastly how many rows and how many
 * columns are on our kepad.
 *
 * NOTE: this also does the proper pinMode() commands so we don't need them in our setup()
 */
Keypad heroKeypad = Keypad(makeKeymap(BUTTONS), ROW_PINS, COL_PINS, ROWS, COLS);

void setup() {
  Serial.begin(9600);  // Initialize the serial monitor
}

void loop() {
  // heroKeypad.waitForKey() will wait here until any button is pressed and
  // returns the character we defined in our BUTTONS array.
  char pressedButton = heroKeypad.waitForKey();  // Wait until a button is pressed

  // Display the character returned for the button that was pressed.
  Serial.println(pressedButton);
}