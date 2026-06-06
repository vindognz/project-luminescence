const int LED_PIN = PB1;
const int BUTTON_PIN = PB2;
const int BRIGHTNESS_PIN = PB3;

// debounce variables
unsigned long lastDebounceTime = 0;
const unsigned debounceDelay = 50; // 50ms debounce

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
        }
    }

    lastReading = reading;

    // update LED to debounced button state
    if (stableButtonState == LOW) {
        digitalWrite(LED_PIN, HIGH); // button pressed
    } else {
        digitalWrite(LED_PIN, LOW); // button released
    }
}