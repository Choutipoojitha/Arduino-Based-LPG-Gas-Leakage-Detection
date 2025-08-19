#include <Servo.h>
#include <LiquidCrystal_I2C.h>

// Define the pins
const int gasSensor = A0;
const int buzzer = 8;
LiquidCrystal_I2C lcd(0X27, 16, 2);

int gasThreshold = 130;

void setup() {
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);

  pinMode(gasSensor, INPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  delay(1000);
  lcd.setCursor(0,0);

  int gasLevel = analogRead(gasSensor);

  Serial.print("Gas level: ");
  Serial.println(gasLevel);

  if (gasLevel > gasThreshold) {
    digitalWrite(buzzer, HIGH);
    lcd.println("gas leak detected");
    delay(1000);
    Serial.println("Gas leak detected! Buzzer activated.");
  } else {
    lcd.setCursor(0,1);
    digitalWrite(buzzer, LOW);
    lcd.println("gas leak not detected");
    delay(1000);
    Serial.println("Gas level normal. System safe.");
  }
  delay(1000);
}
