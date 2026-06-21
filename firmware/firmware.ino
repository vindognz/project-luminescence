const int HIGH = 1;
const int LOW = 0;
const int OUTPUT = 0;
const int INPUT = 0;
const int INPUT_PULLUP = 0;
const int PB1;
const int PB2;
const int PB3;

void pinMode(int PIN, int MODE) {}
void digitalWrite(int PIN, int MODE) {}
void analogWrite(int PIN, int MODE) {}
int digitalRead(int PIN) {}
int analogRead(int PIN) {}
int millis() {}
int sin(int THETA) {}

#include <stdint.h>



const int LED_PIN = PB1;
const int BUTTON_PIN = PB2;
const int BRIGHTNESS_PIN = PB3;

// debounce variables
unsigned long lastDebounceTime = 0;
const unsigned long debounceDelay = 50;

// mode cycling
enum Mode {
    MODE_OFF,
    MODE_ON,
    MODE_FADE,
    MODE_COUNT
};

Mode currentMode = MODE_OFF;

// gamma correction for smooth brightness
uint8_t gamma8(uint8_t x) {
    return (uint16_t)x * x / 255;
}

void setup() {
    pinMode(LED_PIN, OUTPUT);
    pinMode(BUTTON_PIN, INPUT_PULLUP);
    pinMode(BRIGHTNESS_PIN, INPUT);
    digitalWrite(LED_PIN, LOW);
}

void loop() {
    static bool lastReading = HIGH;
    static bool stableButtonState = HIGH;

    bool reading = digitalRead(BUTTON_PIN);

    if (reading != lastReading) {
        lastDebounceTime = millis();
    }

    if ((millis() - lastDebounceTime) > debounceDelay) {
        if (reading != stableButtonState) {
            stableButtonState = reading;
            if (stableButtonState == LOW) {
                currentMode = (Mode)((currentMode + 1) % MODE_COUNT);
            }
        }
    }

    lastReading = reading;
    handleLED();
}

void handleLED() {
    int rawBrightness = analogRead(BRIGHTNESS_PIN);
    uint8_t brightnessScale = (uint8_t)(rawBrightness / 4);
    
    switch (currentMode) {
        case MODE_OFF:
            analogWrite(LED_PIN, 0);
            break;
            
        case MODE_ON:
            analogWrite(LED_PIN, brightnessScale);
            break;
            
        case MODE_FADE: {
            float breathe = (sin(millis() / 1000.0) + 1.0) / 2.0;
            uint8_t brightness = gamma8((uint8_t)(breathe * brightnessScale));
            analogWrite(LED_PIN, brightness);
            break;
        }
    }
}