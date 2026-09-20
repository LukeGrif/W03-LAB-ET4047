// Exercise 4 - Interrupts (breadboard build)
// Author: Luke Griffin
 
const int BUTTON1_PIN = 2;                    // S1 on pin D2 (interrupt pin)
const int LED1_PIN = 4;                       // LED 1 on pin D4
const int LED2_PIN = 5;                       // LED 2 on pin D5
 
volatile bool s1Flag = false;                 // flag set by the ISR
 
void setup() {                                // runs once at power-on
  Serial.begin(9600);                         // open serial monitor (9600 baud)
  Serial.println("Program started - waiting for S1...");  // startup message
  pinMode(BUTTON1_PIN, INPUT_PULLUP);         // idle HIGH, pressed LOW
  pinMode(LED1_PIN, OUTPUT);                  // LED 1 pin is an output
  pinMode(LED2_PIN, OUTPUT);                  // LED 2 pin is an output
  digitalWrite(LED1_PIN, LOW);                // start with LED 1 off
  digitalWrite(LED2_PIN, LOW);                // start with LED 2 off
  // link the button to the ISR (fires on the HIGH->LOW press)
  attachInterrupt(digitalPinToInterrupt(BUTTON1_PIN), handleS1ISR, FALLING);  // attach ISR
}                                             // end of setup()
 
void loop() {                                 // repeats forever
  if (s1Flag) {                               // did the ISR fire?
    s1Flag = false;                           // clear the flag
    Serial.println("S1 interrupt detected - LEDs ON");  // print status
    digitalWrite(LED1_PIN, HIGH);             // turn LED 1 on
    digitalWrite(LED2_PIN, HIGH);             // turn LED 2 on
    delay(3000);                              // keep LEDs on for 3 s
    Serial.println("3 seconds elapsed - LEDs OFF");  // print status
    digitalWrite(LED1_PIN, LOW);              // turn LED 1 off
    digitalWrite(LED2_PIN, LOW);              // turn LED 2 off
  }                                           // end of if
  // main loop is otherwise idle
}                                             // end of loop()
 
void handleS1ISR() {                          // interrupt service routine
  s1Flag = true;                              // keep it short: set the flag
}                                             // end of ISR
