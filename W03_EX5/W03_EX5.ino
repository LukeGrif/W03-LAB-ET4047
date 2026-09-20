// Exercise 5 - Polling, two buttons (breadboard build)
// Author: Luke Griffin
 
const int BUTTON1_PIN = 2;                    // S1 push button on pin D2
const int BUTTON2_PIN = 3;                    // S2 push button on pin D3
const int LED1_PIN = 4;                       // LED 1 on pin D4
const int LED2_PIN = 5;                       // LED 2 on pin D5
 
void setup() {                                // runs once at power-on
  Serial.begin(9600);                         // open serial monitor (9600 baud)
  pinMode(BUTTON1_PIN, INPUT_PULLUP);         // S1 idle HIGH, pressed LOW
  pinMode(BUTTON2_PIN, INPUT_PULLUP);         // S2 idle HIGH, pressed LOW
  pinMode(LED1_PIN, OUTPUT);                  // LED 1 pin is an output
  pinMode(LED2_PIN, OUTPUT);                  // LED 2 pin is an output
  digitalWrite(LED1_PIN, LOW);                // start with LED 1 off
  digitalWrite(LED2_PIN, LOW);                // start with LED 2 off
}                                             // end of setup()
 
void loop() {                                 // repeats forever
  bool s1 = (digitalRead(BUTTON1_PIN) == LOW);  // true when S1 is pressed
  bool s2 = (digitalRead(BUTTON2_PIN) == LOW);  // true when S2 is pressed
 
  if (s1) {                                   // if S1 is pressed
    digitalWrite(LED1_PIN, HIGH);             // turn LED 1 on
    Serial.println("S1 pressed -> LED 1 ON"); // print status
    delay(3000);                              // keep LED 1 on for 3 s
  } else {                                    // otherwise
    digitalWrite(LED1_PIN, LOW);              // turn LED 1 off
  }                                           // end of S1 block
 
  if (s2) {                                   // if S2 is pressed
    digitalWrite(LED2_PIN, HIGH);             // turn LED 2 on
    Serial.println("S2 pressed -> LED 2 ON"); // print status
    delay(3000);                              // keep LED 2 on for 3 s
  } else {                                    // otherwise
    digitalWrite(LED2_PIN, LOW);              // turn LED 2 off
  }                                           // end of S2 block
 
  delay(50);                                  // small pause between checks
}                                             // end of loop()
