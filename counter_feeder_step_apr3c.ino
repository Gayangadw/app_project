#include <Stepper.h>
#include <LiquidCrystal_I2C.h>

const int stepsPerRevolution = 2048;  // change this to fit the number of steps per revolution

// ULN2003 Motor Driver Pins
#define IN1 19
#define IN2 18
#define IN3 5
#define IN4 17

// LCD configuration
int lcdColumns = 16;
int lcdRows = 2;

LiquidCrystal_I2C lcd(0x27, lcdColumns, lcdRows);

// initialize the stepper library
Stepper myStepper(stepsPerRevolution, IN1, IN3, IN2, IN4);

void setup() {
  // Set up LCD
  lcd.init(); // Initialize LCD
  lcd.backlight(); // Turn on backlight
  lcd.clear(); // Clear the LCD
  lcd.print("Ball Feeder"); // Display a message on the LCD
  delay(5000); // Wait for 2 seconds
  // Set up stepper motor
  myStepper.setSpeed(5);
  // Initialize serial port for debugging (optional)
  Serial.begin(115200);
}

void loop() {
  // Rotate 12 times
  for (int i = 0; i < 12; i++) {
    // step one revolution in one direction:
    lcd.clear(); // Clear previous content
    lcd.setCursor(0, 0);
    lcd.print("Ball count:");
    lcd.setCursor(0, 1);
    lcd.print(i + 1); // Display current rotation count
    delay(1000);
    Serial.print("Rotation count: ");
    Serial.println(i + 1); // Print rotation count to serial monitor (optional)
    myStepper.step(stepsPerRevolution);
    delay(1000);
  }

  // End of rotation, you can add any additional actions here if needed

  // Infinite loop, you may add conditions to break out if needed
  while (true) {
    // Optional: Add any additional actions here
  }
}
