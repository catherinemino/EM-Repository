#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define I2C_ADDR 0x27 // Common I2C address for 16x2 LCD
#define LCD_WIDTH 20
#define LCD_HEIGHT 4

LiquidCrystal_I2C lcd(I2C_ADDR, LCD_WIDTH, LCD_HEIGHT);

// Message to display
const char* message = "dont hurt em! ";

void setup() {
    lcd.init(); // Initialize the LCD
    lcd.backlight(); // Turn on the backlight
}

void loop() {
    moveTextUpDown(message); // Move the text up and down
}

// Function to move text up and down the screen
void moveTextUpDown(const char* text) {
    int maxRows = LCD_HEIGHT; // Number of rows on the LCD

    // Move text down
    for (int row = 0; row < maxRows; row++) {
        lcd.clear();
        lcd.setCursor(0, row);
        lcd.print(text);
        delay(300); // Adjust the speed of the movement
    }

    // Move text up
    for (int row = maxRows - 1; row >= 0; row--) {
        lcd.clear();
        lcd.setCursor(0, row);
        lcd.print(text);
        delay(300); // Adjust the speed of the movement
    }
}
