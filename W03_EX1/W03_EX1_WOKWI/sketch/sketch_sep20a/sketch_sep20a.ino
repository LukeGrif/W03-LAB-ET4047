// Exercise 1 - Getting Started (breadboard build)
// Author: Luke Griffin
 
const int LED1_PIN = 4;                       // LED 1 on pin D4
const int LED2_PIN = 5;                       // LED 2 on pin D5
 
void setup() {                                // runs once at power-on (initialising)
  Serial.begin(9600);                         // start the serial monitor (9600 baud)
  pinMode(LED1_PIN, OUTPUT);                  // set LED 1 pin as an output
  pinMode(LED2_PIN, OUTPUT);                  // set LED 2 pin as an output
  Serial.println("Setup complete");           // print a message once
}                                             // end of setup()
 
void loop() {                                 // repeats forever
  digitalWrite(LED1_PIN, HIGH);               // turn LED 1 on (pin goes to 5V)
  digitalWrite(LED2_PIN, LOW);                // turn LED 2 off (pin goes to 0V)
  Serial.println("LED 1 on, LED 2 off");      // report the state to serial
  delay(500);                                 // wait half a second
 
  digitalWrite(LED1_PIN, LOW);                // turn LED 1 off
  digitalWrite(LED2_PIN, HIGH);               // turn LED 2 on
  Serial.println("LED 1 off, LED 2 on");      // report the state to serial
  delay(500);                                 // wait half a second
}                                             // end of loop()
