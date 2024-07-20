/*
 * 30 Days - Lost in Space
 * Day 4 - Cabin Lighting
 *
 * Learn more at https://inventr.io/adventure
 *
 * In addition to our cabin lights we have lights in the storage room and even some
 * exterior lights.  Let's extend our previous project by adding the others and use
 * all three switches on our DIP switch module.  Each time through our loop() code we'll
 * check each switch, and set the corresponding light's state appropriately.
 *
 * Alex Eschenauer
 * David Schmidt
 * Greg Lyzenga
 */

/*
 * Arduino concepts introduced/documented in this lesson.
 * - const: Better than #define for defining constants that do not change
 * - byte: A data type representing an unsigned 8 bit integer (values from 0 to 255)
 *         Equivalent to "unsigned char" or "uint8_t" which are sometimes seen.
 *
 * Parts and electronics concepts introduced in this lesson.
 * - Use of breadboard "power rails" to allow us to use one 5V and one GND pin on
 *   HERO to connect to multiple components on our breadboard.
 */

#include "Arduino.h"  // include information about our HERO

/*
 * #define vs. const
 *
 * Until now we have been using #define to define our constants.  When the C language
 * was first created that was the only way to define constants.  However, because
 * of the way #define operates there were instances where the use of #define can
 * cause and hide bugs in programs.
 *
 * Becasuse of this, the language maintainers added a new C commands named "const".
 * For most Arduino programs it operates much the same, though it does contain some
 * additional type information that can help communicate how it is to be used.
 *
 * You will see both used in Arduino code and libraries.  However the general
 * language calls for preferring the use of "const" over using #define.  Our first
 * sketches have used #define so that you are familiar with them and see how they
 * work, but from this lesson on we will be using the preferred "const" expression
 * to define our constants.
 *
 * Here, on Day 4 we will show *both* versions, with the #define version commented
 * out to prevent compile errors.  This will help you learn the difference between
 * them.  After today the sketches will only use the preferred "const" versions.
 */

// Each lander light will be controlled using a different pin on our HERO.
// We will use three different color LEDs to make it more clear which switch
// controls which light.

/*
 * The "const" declaration adds another word that will indicate what type of value
 * is to be represented.  Since pins are small numbers they fit into a "byte", which
 * is an unsigned integer value that can hold values from 0 to 255.
 *
 * Other types you may sometimes see in various Arduino code are "uint8_t" or
 * "unsigned char" which are the same as "byte".  We will use the term "byte"
 * in our lessons to indicate 8 bit unsigned integers.
 */
// #define LED_b 10             // pin controlling the cabin lights
// #define LED_g 11           // pin controlling the storage lights
// #define LED_r 12           // pin controlling the exterior lights
const byte LED_b = 10;    // pin controlling the cabin lights
const byte LED_g = 11;  // pin controlling the storage lights
const byte LED_r = 12;  // pin controlling the exterior lights

// We will use a different input pin for each of our DIP switches and
// we'll label them using the color of the LED that each switch will control.
// #define DIP_1 2             // cabin lights controlled by switch 1
// #define DIP_2 3           // storage lights controlled by switch 2
// #define DIP_3 4           // exterior lights controlled by switch 3
const byte DIP_1 = 2;    // cabin lights controlled by switch 1
const byte DIP_2 = 3;  // storage lights controlled by switch 2
const byte DIP_3 = 4;  // exterior lights controlled by switch 3

// the setup function runs once when you press reset or power the board
void setup() {
  // Configure our LED control pins as OUTPUT pins
  pinMode(LED_b, OUTPUT);    // pin controlling the cabin lights
  pinMode(LED_g, OUTPUT);  // pin controlling the storage lights
  pinMode(LED_r, OUTPUT);  // pin controlling the exterior lights

  // Configure the switch pins as INPUT pins
  pinMode(DIP_1, INPUT);    // pin connected to switch 1 (cabin lights)
  pinMode(DIP_2, INPUT);  // pin connected to switch 2 (storage lights)
  pinMode(DIP_3, INPUT);  // pin connected to switch 3 (exterior lights)
}

// Each time through loop() we will check each switch in turn and set each light's
// state appropriately.
void loop() {
  // DIP123 = [100] --- waterfall mode
  if (digitalRead(DIP_1) == HIGH & digitalRead(DIP_2) == LOW  & digitalRead(DIP_3) == LOW ) {
    digitalWrite(LED_r, HIGH);              // turn on LED by providing HIGH voltage (5v)
    delay(100);
    digitalWrite(LED_g, HIGH);              // turn on LED by providing HIGH voltage (5v)
    delay(100);
    digitalWrite(LED_b, HIGH);              // turn on LED by providing HIGH voltage (5v)
    delay(100);
    digitalWrite(LED_r, LOW);              // turn on LED by providing HIGH voltage (5v)
    delay(100);
    digitalWrite(LED_g, LOW);              // turn on LED by providing HIGH voltage (5v)
    delay(100);
    digitalWrite(LED_b, LOW);              // turn on LED by providing HIGH voltage (5v)
    delay(100);
  } else {
    //digitalWrite(LED_b, LOW);  // turn off LED by setting output to LOW (zero volts)
  }

  // DIP123 = [010] --- unison blink
  if (digitalRead(DIP_1) == LOW & digitalRead(DIP_2) == HIGH  & digitalRead(DIP_3) == LOW ) {
    digitalWrite(LED_r, HIGH);              // turn on LED by providing HIGH voltage (5v)
    digitalWrite(LED_g, HIGH);              // turn on LED by providing HIGH voltage (5v)
    digitalWrite(LED_b, HIGH);              // turn on LED by providing HIGH voltage (5v)
    delay(500);
    digitalWrite(LED_r, LOW);              // turn on LED by providing HIGH voltage (5v)
    digitalWrite(LED_g, LOW);              // turn on LED by providing HIGH voltage (5v)
    digitalWrite(LED_b, LOW);              // turn on LED by providing HIGH voltage (5v)
    delay(500);
  } else {
    //digitalWrite(LED_g, LOW);  // turn off LED by setting output to LOW (zero volts)
  }

  // DIP123 = [001] --- sequential blink
  if (digitalRead(DIP_1) == LOW & digitalRead(DIP_2) == LOW  & digitalRead(DIP_3) == HIGH ) {
    digitalWrite(LED_r, HIGH);              // turn on LED by providing HIGH voltage (5v)
    delay(300);
    digitalWrite(LED_r, LOW);              // turn on LED by providing HIGH voltage (5v)
    digitalWrite(LED_g, HIGH);              // turn on LED by providing HIGH voltage (5v)
    delay(300);
    digitalWrite(LED_g, LOW);              // turn on LED by providing HIGH voltage (5v)
    digitalWrite(LED_b, HIGH);              // turn on LED by providing HIGH voltage (5v)
    delay(300);
    digitalWrite(LED_b, LOW);              // turn on LED by providing HIGH voltage (5v)
  } else {
    //digitalWrite(LED_b, LOW);  // turn off LED by setting output to LOW (zero volts)
  }
}