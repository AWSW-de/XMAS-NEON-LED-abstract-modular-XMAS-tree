// ###########################################################################################################################################
// #
// # Code for the printables "XMAS NEON LED abstract modular XMAS tree" project:
// # https://www.printables.com/model/1103950-xmas-neon-led-abstract-modular-xmas-tree
// #
// # Code by https://github.com/AWSW-de
// #
// # Released under license: GNU General Public License v3.0: https://github.com/AWSW-de/XMAS-NEON-LED-abstract-modular-XMAS-tree#GPL-3.0-1-ov-file
// #
// ###########################################################################################################################################


// ###########################################################################################################################################
// # Code version:
// ###########################################################################################################################################
String Code_Version = "V1.0.0";


// ###########################################################################################################################################
// # Includes:
// #
// # FastLED                // by Daniel Garcia               // https://github.com/FastLED/FastLED
// #
// ###########################################################################################################################################
#include "FastLED.h"


// ###########################################################################################################################################
// # Hardware settings:
// ###########################################################################################################################################
// How many LEDs are in your neon LED strip?:
#define NUM_LEDS 22  // 161 is the max. amount in the neon led strip
// Data pin on the ESP32:
#define DATA_PIN 32


// ###########################################################################################################################################
// # LED and animation settings:
// ###########################################################################################################################################
int UseStartTestRGB = 1;     // Perform the RGB startup test (1) or not (0)
int LEDbrightness = 128;     // Set LED brightness (0-255)
int UseAnimation = 1;        // Use animation (1) in the loop function or not (0)
int AnimationSpeed = 10000;  // Animation speed in milliseconds, 10000 = 10 seconds


// ###########################################################################################################################################
// # Definitions:
// ###########################################################################################################################################
// Define the array of leds:
CRGB leds[NUM_LEDS];


// ###########################################################################################################################################
// # Startup function:
// ###########################################################################################################################################
void setup() {
  // Serial.begin(115200);

  // Initialize the LED strip:
  FastLED.addLeds<WS2811, DATA_PIN, BRG>(leds, NUM_LEDS);

  // Switch all LEDs off first:
  LEDS.showColor(CRGB(0, 0, 0));

  // Set LED brightness (0-255):
  LEDS.setBrightness(LEDbrightness);

  // Some animation and LED RGB color output testing first:
  if (UseStartTestRGB == 1) {
    // Set all LEDs to red:
    for (int i = 0; i < NUM_LEDS; i++) {
      leds[i] = CRGB::Red;
      FastLED.show();
      // delay(25);
    }
    delay(500);

    // Set all LEDs to green:
    for (int i = 0; i < NUM_LEDS; i++) {
      leds[i] = CRGB::Green;
      FastLED.show();
      // delay(25);
    }
    delay(500);

    // Set all LEDs to blue:
    for (int i = 0; i < NUM_LEDS; i++) {
      leds[i] = CRGB::Blue;
      FastLED.show();
      // delay(25);
    }
    delay(500);
  }

  // Set all LEDs to white:
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::White;
    FastLED.show();
    delay(25);
  }
  delay(1000);


  // XMAS tree mode:
  if (UseAnimation == 1) {
    // Set all LEDs in the tree to green:
    for (int i = 0; i < NUM_LEDS; i++) {
      leds[i] = CRGB::Green;
      FastLED.show();
      delay(25);
    }

    // Set the top 2 LEDs to yellow:
    for (int i = NUM_LEDS - 2; i < NUM_LEDS; i++) {
      leds[i] = CRGB::Yellow;
      FastLED.show();
      delay(25);
    }
  }
}


// ###########################################################################################################################################
// # Runtime function:
// ###########################################################################################################################################
void loop() {
  if (UseAnimation == 1) {  // XMAS tree mode:
    // Set all LEDs to green:
    for (int i = 0; i < NUM_LEDS - 2; i++) {
      leds[i] = CRGB::Green;
    }
    // 5 random "ornament" pixels:
    for (int i = 0; i <= 5; i++) {
      int randNumber = random(0, NUM_LEDS - 3);
      leds[randNumber] = CRGB::Red;  // Red ornament color
      FastLED.show();
      delay(AnimationSpeed / 5);
    }
  }
}