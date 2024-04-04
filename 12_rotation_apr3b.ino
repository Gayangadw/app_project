#include <Stepper.h>

const int stepsPerRevolution = 2048;  // change this to fit the number of steps per revolution

// ULN2003 Motor Driver Pins
#define IN1 19
#define IN2 18
#define IN3 5
#define IN4 17

// initialize the stepper library
Stepper myStepper(stepsPerRevolution, IN1, IN3, IN2, IN4);

void setup() {
  // set the speed at 5 rpm
  myStepper.setSpeed(5);
  // initialize the serial port
  Serial.begin(115200);
}

void loop() {
  // Rotate 12 times
  for (int i = 0; i < 12; i++) {
    // step one revolution in one direction:
    Serial.print("Rotation count: ");
    Serial.println(i + 1); // Display current rotation count
    Serial.println("clockwise");
    myStepper.step(stepsPerRevolution);
    delay(1000);
  }

  // End of rotation, you can add any additional actions here if needed

  // Infinite loop, you may add conditions to break out if needed
  while (true) {
    // Optional: Add any additional actions here
  }
}
