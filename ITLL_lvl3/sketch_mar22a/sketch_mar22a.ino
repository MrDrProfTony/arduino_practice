void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // Task 1: print Hello World to the serial monitor
  // (This is Tx, arduino is sending to laptop)
  // see the output in the serial monitor by clicking the magnifying glass in the upper right of this window
  //Serial.println("Hello World");
  //delay(1000);

  // Task 2: "Echo"
  // Write code that will receive input from laptop to arduino
  // (watch for "no line ending" vs "new line" in the serial monitor)
  //int x = Serial.read();
  //if (x != -1){
  //  Serial.println(x);
  //}
  //delay(1000); // this was useful before we had the if statement

  // Task 3: refine
  if (Serial.available()){
    int x = Serial.parseInt();
    Serial.println(x);
  }
}
