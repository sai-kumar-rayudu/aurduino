// Defining pins
const int pirPin = 2;
const int relayPin = 3;

void setup() {
  // Initializing the PIR sensor pin as an input
  pinMode(pirPin, INPUT);
  // Initializing the relay pin as an output
  pinMode(relayPin, OUTPUT);
  // Starting with the relay off
  digitalWrite(relayPin, LOW);
  // Start serial communication for debugging
  Serial.begin(9600);
}

void loop() {
  // Reads the value from the PIR sensor
  int motionDetected = digitalRead(pirPin);
  
  if (motionDetected == HIGH) {
    // if Motion detected, turn on the relay
    digitalWrite(relayPin, HIGH);
    Serial.println("Motion detected - lights ON");
  } else {
    // if No motion, turn off the relay
    digitalWrite(relayPin, LOW);
    Serial.println("No motion - lights OFF");
  }
  
  // Small delay to avoid multiple triggers
  delay(1000);
}