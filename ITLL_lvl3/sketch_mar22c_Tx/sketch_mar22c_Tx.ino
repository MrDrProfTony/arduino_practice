#include <RF24.h>
RF24 radio(9,10);

int button_pin = 3;

// code: itlp.link/workshopresources

void setup() {
  // put your setup code here, to run once:
  while(!radio.begin());

  // Tx
  radio.openWritingPipe(20); // Send messages to address "20" (our of i trillion)
  radio.stopListening(); // This radio is only sending
  // Rx
  // radio.openReadingPipe(0,20);

  // set up the button pin
  pinMode(button_pin, INPUT_PULLUP); // Set the button pin mode
  // "input_pullup" causes the arduino to set the pin to high when the button is not pressed
  // it avoids needing to have an actual pullup resistor to High
}

void loop() {
  // Task 5: Radio communication (bluetooth to bluetooth)
  bool TXmsg; 

  TXmsg = digitalRead(button_pin);

  radio.write(&TXmsg, sizeof(TXmsg));

}