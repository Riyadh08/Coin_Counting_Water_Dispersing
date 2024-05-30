#include <Wire.h>
#include <LiquidCrystal_I2C.h>

int x1 = 0;
//int input1 = A1;
int state1 = 1;

int x2 = 0;
//int input2 = A2;
int state2 = 1;

int x3 = 0;
//int input3 = A3;
int state3 = 1;

int total = 0;

int relayPin = 4;  // Pin for the relay
unsigned long lastCoinTime = 0;  // Time of the last coin insertion
unsigned long currentTime = 0;  // Current time

LiquidCrystal_I2C lcd(0x27, 16, 2);  // Initialize the LCD object

void setup() {
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, LOW);  // Ensure relay is off at the start relay Pin = 4

  lcd.init();  // Initialize the LCD
  lcd.backlight();  // Turn on the LCD backlight

  lcd.setCursor(0, 0);  // Set the cursor to the first column of the first row
  lcd.print("Coin Value &");  // Print the first line of the welcome message
  lcd.setCursor(0, 1);  // Set the cursor to the first column of the second row
  lcd.print("Counter...");  // Print the second line of the welcome message

  delay(3000);  // Delay for 3 seconds to display the welcome message
  lcd.clear();  // Clear the LCD display

  lcd.setCursor(0, 0);
  lcd.print("1TK");  // Print the label for 1TK
  lcd.setCursor(4, 0);
  lcd.print("2TK");  // Print the label for 2TK
  lcd.setCursor(8, 0);
  lcd.print("5TK");  // Print the label for 5TK
  lcd.setCursor(0, 1);
  lcd.print(x1);  // Print the count of 1TK
  lcd.setCursor(4, 1);
  lcd.print(x2);  // Print the count of 2TK
  lcd.setCursor(8, 1);
  lcd.print(x3);  // Print the count of 5TK

  lastCoinTime = millis();  // Initialize the last coin time to the current time
}

void loop() {
  currentTime = millis();  // Update the current time

  // Counting logic
  int counter1 = digitalRead(A1);  // Read the state of counter 1 Analog Pin
  int counter2 = digitalRead(A2);  // Read the state of counter 2 Analog Pin
  int counter3 = digitalRead(A3);  // Read the state of counter 3 Analog Pin

  if (state1 == 0) {
    switch (counter1) {
      case 1:
        state1 = 1;
        lcd.setCursor(0, 1);  // Set the cursor to the first column of the second row
        x1 = x1 + 1;  // Increment the count of 1TK
        total = total + 1;  // Increment the total amount
        lcd.print(x1);  // Print the updated count of 1TK
        lastCoinTime = currentTime;  // Update the last coin time
        break;
      case 0:
        state1 = 0;
        break;
    }
  }

  if (counter1 == LOW) {
    state1 = 0;
  }

  if (state2 == 0) {
    switch (counter2) {
      case 1:
        state2 = 1;
        lcd.setCursor(4, 1);  // Set the cursor to the fifth column of the second row
        x2 = x2 + 1;  // Increment the count of 2TK
        total = total + 2;  // Increment the total amount
        lcd.print(x2);  // Print the updated count of 2TK
        lastCoinTime = currentTime;  // Update the last coin time
        break;
      case 0:
        state2 = 0;
        break;
    }
  }

  if (counter2 == LOW) {
    state2 = 0;
  }

  if (state3 == 0) {
    switch (counter3) {
      case 1:
        state3 = 1;
        lcd.setCursor(8, 1);  // Set the cursor to the ninth column of the second row
        x3 = x3 + 1;  // Increment the count of 5TK
        total = total + 5;  // Increment the total amount
        lcd.print(x3);  // Print the updated count of 5TK
        lastCoinTime = currentTime;  // Update the last coin time
        break;
      case 0:
        state3 = 0;
        break;
    }
  }

  if (counter3 == LOW) {
    state3 = 0;
  }

  // Display total amount
  lcd.setCursor(0, 0);
  lcd.print("Total Amount:");
  lcd.setCursor(0, 1);
  lcd.print(total);
  lcd.setCursor(4, 1);
  lcd.print("TK");

  // Check if 10 seconds have passed since the last coin
  if (total > 0 && (currentTime - lastCoinTime >= 10000)) {
    int delayTime = 250 * total;  // Delay time in milliseconds
    digitalWrite(relayPin, HIGH);
    delay(delayTime);  // Delay for the calculated time
    digitalWrite(relayPin, LOW);

    // Reinitialize the LCD after relay activation
    lcd.init();  // Reinitialize the LCD
    lcd.backlight();  // Turn on the LCD backlight
    lcd.clear();  // Clear the LCD display

    // Reset everything after relay activation
    x1 = 0;
    x2 = 0;
    x3 = 0;
    total = 0;
    lcd.setCursor(0, 0);
    lcd.print("1TK");
    lcd.setCursor(4, 0);
    lcd.print("2TK");
    lcd.setCursor(8, 0);
    lcd.print("5TK");
    lcd.setCursor(0, 1);
    lcd.print(x1);
    lcd.setCursor(4, 1);
    lcd.print(x2);
    lcd.setCursor(8, 1);
    lcd.print(x3);
  }
}