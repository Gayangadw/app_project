#include <Stepper.h>

const int stepsPerRevolution = 2048; 


#define IN1 19
#define IN2 18
#define IN3 5
#define IN4 17


Stepper myStepper(stepsPerRevolution, IN1, IN3, IN2, IN4);

void setup() {
  myStepper.setSpeed(5);
  Serial.begin(115200);
}

void loop() {
  // Rotate 12 times
  for (int i = 0; i < 12; i++) {
    Serial.print("Rotation count: ");
    Serial.println(i + 1); 
    Serial.println("clockwise");
    myStepper.step(stepsPerRevolution);
    delay(1000);
  }
  while (true) {
    
  }
}
