const int stepPin = 2;    // STEP pulse input pin
const int dirPin  = 5;    // DIRECTION control pin

void setup() {
  Serial.begin(115200);              // initialize serial port
  while (!Serial);                   // wait for serial to be ready (for Leonardo/Micro)
  Serial.println("Test begin");      
  Serial.println("EN‑GND already connected");

  pinMode(stepPin, OUTPUT);         // configure STEP pin as output
  pinMode(dirPin,  OUTPUT);         // configure DIR pin as output
}
// Generate a specified number of STEP pulses at a given frequency
void rotateSteps(int stepCount, int stepHz) {
  unsigned long halfPeriod = 1000000UL / stepHz / 2; // half-period in microseconds
  for (int i = 0; i < stepCount; i++) {
    digitalWrite(stepPin, HIGH);      
    delayMicroseconds(halfPeriod);    // high for half period
    digitalWrite(stepPin, LOW);
    delayMicroseconds(halfPeriod);    // low for half period
  }
}

void loop() {
  // Rotate one full revolution clockwise
  digitalWrite(dirPin, HIGH);    // set direction to clockwise
  rotateSteps(200, 800);         // 200 steps @ 800 Hz = 1 revolution
  delay(1000);                    // wait 1 second

  // Rotate one full revolution counter‑clockwise
  digitalWrite(dirPin, LOW);     // set direction to counter‑clockwise
  rotateSteps(200, 800);         // 200 steps @ 800 Hz = 1 revolution
  delay(1000);                    // wait 1 second
}

