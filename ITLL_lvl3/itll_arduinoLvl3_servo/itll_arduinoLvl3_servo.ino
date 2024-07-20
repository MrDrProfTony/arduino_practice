#include <Servo.h>
Servo myServo;

void setup() {
  // put your setup code here, to run once:
  myServo.attach(9);
  Serial.begin(9600);
}

void loop() {
  // Task 4: control servo over serial monitor
  // This is sending angle values from the laptop to the servo
  if (Serial.available()){
    int angle = Serial.parseInt();
    myServo.write(angle);
    //delay(1000);
  }

  // This allows us to send code from laptop to servo

  // actually, without changing the code, we connect the HM10 and connect our phone to the HM10 with BLE scanner (app)
  // Jonah recommends the "Dabble" app

  // I tried to break the servo. Sorry servo...
  //myServo.write(0);
  //myServo.write(180);
}