// Exercise 2 - Button Debounce (breadboard build)
// Author: Luke Griffin
 
const int BUTTON1_PIN = 2;                    // S1 push button on pin D2
const int LED1_PIN = 4;                       // LED 1 on pin D4
 
int buttonState = HIGH;                       // current debounced state (idle HIGH)
int lastReading = HIGH;                       // previous raw reading (idle HIGH)
unsigned long lastChangeTime = 0;             // time the raw reading last changed
const unsigned long debounceDelay = 50;       // wait 50 ms for it to settle
bool ledOn = false;                           // remembers if LED 1 is on
 
void setup() {                                // runs once at power-on
  Serial.begin(9600);                         // open serial monitor (9600 baud)
  pinMode(BUTTON1_PIN, INPUT_PULLUP);         // pull-up; idle HIGH, pressed LOW
  pinMode(LED1_PIN, OUTPUT);                  // LED 1 pin is an output
  digitalWrite(LED1_PIN, LOW);                // start with LED 1 off
}                                             // end of setup()
 
void loop() {                                 // repeats forever
  int reading = digitalRead(BUTTON1_PIN);     // read S1 (LOW = pressed)
 
  if (reading != lastReading) {               // raw reading changed (a bounce?)
    lastChangeTime = millis();                // note the time of the change
  }                                           // end of if
 
  if ((millis() - lastChangeTime) > debounceDelay) {  // steady long enough?
    if (reading != buttonState) {             // stable state actually changed
      buttonState = reading;                  // save the new stable state
      if (buttonState == LOW) {               // a clean press (active-low)
        ledOn = !ledOn;                       // flip the LED memory
        digitalWrite(LED1_PIN, ledOn);        // apply it to LED 1
        Serial.println("Debounced press -> LED toggled");  // print status
      }                                       // end of press check
    }                                         // end of state-change check
  }                                           // end of debounce check
 
  lastReading = reading;                      // remember reading for next pass
}                                             // end of loop()
