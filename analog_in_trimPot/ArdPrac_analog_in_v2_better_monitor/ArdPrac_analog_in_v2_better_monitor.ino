/*
 * Dr. Anthony Barsic
 * University of Vermont
 * Department of Electrical Engineering
 * CMPE 3815
 * 2024 June 28
 * The purpose of this script is to use an analog input pin. We will use it to control the brightness of the on-boar LED.
 *
 * The hardware set-up is a trim pot hooked up to 5V, gnd, and A0. the "floating" pin of the pot is on A0.
 */

// INIT and SETUP ===+=== ===+=== ===+=== ===+=== ===+=== ===+=== ===+=== ===+=== ===+=== ===+=== ===+===

// Explicitly include Arduino.h
#include "Arduino.h"

// some example variable definitions
const int sensorPin = A0;   // analog pin
// int ledPin = 13;      // select the pin for the LED (on-board)
int sensorValue = 0;  // sensor value (analog in, 10-bit)
int sensorValuePerc = 0; // sensor value converted to percent
int sensorValuePerc_prior = 0; // sensor value converted to percent

void setup() {
  Serial.begin(9600);  // Initialize the serial monitor
  // declare the ledPin as an OUTPUT:
  // pinMode(ledPin, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
}


// LOOP ===+=== ===+=== ===+=== ===+=== ===+=== ===+=== ===+=== ===+=== ===+=== ===+=== ===+===

void loop() {
  // Section L1:  ===+=== ===+=== ===+=== ===+=== ===+=== ===+=== ===+=== 
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);
  // ADC is 10-bit, so this takes a value between 0 and 1023
  // convet it to a percentage:
  sensorValuePerc = sensorValue/10.23; // *100/1023, but integer math

  // Section L2:  ===+=== ===+=== ===+=== ===+=== ===+=== ===+=== ===+=== 
  // display to the serial monitor
  // Serial.println("Sensor Value:");
  // Serial.println(sensorValue);
  // Serial.println("Sensor Value (percent):");
  // Serial.println(sensorValuePerc);

  // replace this with a version that only displays when changed
  // display_delta_to_SrMon(sensorValuePerc,sensorValuePerc_prior)
  // sensorValuePerc_prior = sensorValuePerc;
  // this isn't working...
  if ( abs(sensorValuePerc_prior - sensorValuePerc) > 1.1 ){
    Serial.print("Sensor Value (percent): ");
    Serial.println(sensorValuePerc);
    sensorValuePerc_prior = sensorValuePerc;
  }



  // Section L3:  ===+=== ===+=== ===+=== ===+=== ===+=== ===+=== ===+=== 
  // change the brightness of the LED
  my_LED_dimmer_v2(LED_BUILTIN, sensorValuePerc);

  // add a delay (so the serial monitor goes at a reasonable rate)
  // (this can be removed once we are not using the serial monitor)
  // delay(500);

/*digitalWrite(ledPin, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(1000);                      // wait for a second
  digitalWrite(ledPin, LOW);   // turn the LED off by making the voltage LOW
  delay(1000);                      // wait for a second
  */
}



// FUNCTION = = = = = = = + = = = = = = = + = = = = = = = + = = = = = = = + = = = = = = = +
// This is my function for varying on-board LED brightness using PWM
void my_LED_dimmer(int Pin_to_Blink, int PercentON){

  // problem: this only has 10 values, because (PercentON)/10 is still an int
  for (int k=1; k<=10; k++) {
    // statement(s);
    digitalWrite(Pin_to_Blink, HIGH);  // turn the LED on (HIGH is the voltage level)
    delay((PercentON)/10);                      // wait for a second
    digitalWrite(Pin_to_Blink, LOW);   // turn the LED off by making the voltage LOW
    delay(  (100 - PercentON)/10  ); 
  }

}
// END of my function = = = = = = = + = = = = = = = + = = = = = = = + = = = = = = = + = = = 


// FUNCTION = = = = = = = + = = = = = = = + = = = = = = = + = = = = = = = + = = = = = = = +
// This is my function for varying on-board LED brightness using PWM.
// Version 2! it's not percent, but fraction out of 1023
void my_LED_dimmer_v2(int Pin_to_Blink, double PercentON){



  // problem: this only has 10 values, because (PercentON)/10 is still an int
  // that was version 1
  // Version 2 ought to have 100 values (levels)
  for (int k=1; k<=10; k++) {
    // this loop runs 10 times, and each run is 10ms (total delay is 10ms). 100ms total.
    // statement(s);
    digitalWrite(Pin_to_Blink, HIGH);  // turn the LED on (HIGH is the voltage level)
    delay((PercentON)/10);                      // wait for a second
    digitalWrite(Pin_to_Blink, LOW);   // turn the LED off by making the voltage LOW
    delay(  (100 - PercentON)/10  ); 
  }

}
// END of my function = = = = = = = + = = = = = = = + = = = = = = = + = = = = = = = + = = = 


/*
// FUNCTION = = = = = = = + = = = = = = = + = = = = = = = + = = = = = = = + = = = = = = = +
// This is my function for displaying a variable to the serial montior only when it changes
void display_delta_to_SrMon(newValue,oldValue)
{
  if (newValue != oldValue)
  {
    // Serial.print(F("Value changed to "));
    Serial.print(F("Value changed to "));
    Serial.println(newValue);
  }
}
// END of my function = = = = = = = + = = = = = = = + = = = = = = = + = = = = = = = + = = =
*/

// ===+=== ===+=== ===+=== END OF SKETCH ===+=== ===+=== ===+===
// ===+=== ===+=== ===+=== END OF SKETCH ===+=== ===+=== ===+===
// ===+=== ===+=== ===+=== END OF SKETCH ===+=== ===+=== ===+===