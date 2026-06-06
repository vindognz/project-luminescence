const int LED_PIN = PB1;
const int BUTTON_PIN = PB2;
const int BRIGHTNESS_PIN = PB3;

// debounce variables
unsigned long lastDebounceTime = 0;
const unsigned long debounceDelay = 50; // 50ms debounce

// mode cycling
enum Mode {
    MODE_OFF,
    MODE_ON,
    MODE_FADE,
    MODE_COUNT
};

Mode currentMode = MODE_OFF;

void setup() {
    // initialize everything :)
    pinMode(LED_PIN, OUTPUT);
    pinMode(BUTTON_PIN, INPUT_PULLUP);
    pinMode(BRIGHTNESS_PIN, INPUT);
    digitalWrite(LED_PIN, LOW); // initialize the LED low
}

void loop() {
    static bool lastReading = HIGH;
    static bool stableButtonState = HIGH;

    bool reading = digitalRead(BUTTON_PIN);

    // if reading changed, reset debounce timer
    if (reading != lastReading) {
        lastDebounceTime = millis();
    }

    // after debounce delay, update stable state
    if ((millis() - lastDebounceTime) > debounceDelay) {
        if (reading != stableButtonState) {
            stableButtonState = reading;
            // button pressed (low transition)
            if (stableButtonState == LOW) {
                currentMode = (Mode)((currentMode + 1) % MODE_COUNT);
            }
        }
    }

    lastReading = reading;

    // handle LED based on mode
    handleLED();
}

void handleLED() {
    switch (currentMode) {
        case MODE_OFF:
            digitalWrite(LED_PIN, LOW);
            break;
        case MODE_ON:
            digitalWrite(LED_PIN, HIGH);
            break;
        case MODE_FADE:
            // 750 ms period blinking (will become fading soon)
            digitalWrite(LED_PIN, (millis() / 750) % 2);
            break;
    }
}