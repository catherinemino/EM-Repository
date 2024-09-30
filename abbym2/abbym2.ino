#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define I2C_ADDR 0x27 // Common I2C address for 16x2 LCD
#define LCD_WIDTH 20
#define LCD_HEIGHT 4

LiquidCrystal_I2C lcd(I2C_ADDR, LCD_WIDTH, LCD_HEIGHT);

// Message to display
const char* message = "happy Computer :)";

// Custom character for crying face
byte cryingFace[8] = {
    0b00000, // -----
    0b10001, // *   *
    0b10101, // * * *
    0b10001, // *   *
    0b01110, //  ***
    0b00100, //   *
    0b01010, //  * *
    0b10001  // *   *
};

void setup() {
    lcd.init();      // Initialize the LCD
    lcd.backlight(); // Turn on the backlight
    lcd.createChar(0, cryingFace); // Create the custom crying face character
}

void loop() {
    revealText(message);  // Reveal the message
    delay(2000);          // Pause after the message
    lcd.clear();          // Clear the LCD

    // Display the crying face
    lcd.setCursor(0, 0); // Set cursor to the first row
    lcd.write(byte(0));  // Write the custom crying face
    delay(5000);         // Show the crying face for a while
    lcd.clear();         // Clear the LCD for the next loop
}

// Function to reveal text one character at a time
void revealText(const char* text) {
    lcd.clear(); // Clear the LCD
    for (int i = 0; text[i] != '\0'; i++) {
        lcd.setCursor(i, 0); // Set cursor to the current position
        lcd.print(text[i]);  // Print the current character
        delay(150);          // Decrease the delay to speed up typing
    }
}