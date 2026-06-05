const int LED_PIN = PB1;
const int BUTTON_PIN = PB2;
const int BRIGHTNESS_PIN = PB3;

void setup() {
    pinMode(LED_PIN, OUTPUT);
    pinMode(BUTTON_PIN, INPUT_PULLUP);
    pinMode(BRIGHTNESS_PIN, INPUT);
    digitalWrite(LED_PIN, LOW); // initialize the LED off
}

void loop() {
    // read the button (input_pullup: low = presed, high = not pressed)
    if (digitalRead(BUTTON_PIN) == LOW) {
        digitalWrite(LED_PIN, HIGH); // button pressed = led on
    } else {
        digitalWrite(LED_PIN, LOW); // button released = led off
    }
}