// Exercise 3 - Polling (breadboard build)
// Author: Luke Griffin
 
const int BUTTON1_PIN = 2;                    // S1 push button on pin D2
const int LED1_PIN = 4;                       // LED 1 on pin D4
const int LED2_PIN = 5;                       // LED 2 on pin D5
 
void setup() {                                // runs once at power-on
  Serial.begin(9600);                         // open serial monitor (9600 baud)
  pinMode(BUTTON1_PIN, INPUT_PULLUP);         // idle HIGH, pressed LOW
  pinMode(LED1_PIN, OUTPUT);                  // LED 1 pin is an output
  pinMode(LED2_PIN, OUTPUT);                  // LED 2 pin is an output
  digitalWrite(LED1_PIN, LOW);                // start with LED 1 off
  digitalWrite(LED2_PIN, LOW);                // start with LED 2 off
}                                             // end of setup()
 
void loop() {                                 // repeats forever
  bool s1 = (digitalRead(BUTTON1_PIN) == LOW);  // true when S1 is pressed
 
  if (s1) {                                   // if the button is pressed
    digitalWrite(LED1_PIN, HIGH);             // turn LED 1 on
    digitalWrite(LED2_PIN, HIGH);             // turn LED 2 on
    Serial.println("Button S1 pressed -> LEDs ON");  // print status
    delay(3000);                              // keep LEDs on for 3 s
  } else {                                    // otherwise (not pressed)
    digitalWrite(LED1_PIN, LOW);              // turn LED 1 off
    digitalWrite(LED2_PIN, LOW);              // turn LED 2 off
    Serial.println("Button S1 released -> LEDs OFF");  // print status
  }                                           // end of if/else
 
  delay(300);                                 // short pause; keeps 
}