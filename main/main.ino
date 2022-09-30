// pt = phototransistor 
int ptValue;
int ptLow = 1023;
int ptHigh = 0;

const int ledPin = 13;

void setup() {
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);

  while(millis() < 5000){
    if(ptValue > ptHigh){
      ptHigh = ptValue;
    }

    if(ptValue < ptLow){
      ptLow = ptValue;
    }
  }
  digitalWrite(ledPin, LOW);
}

void loop() {
  ptValue = analogRead(A0);
  int pitch = map(ptValue, ptLow, ptHigh, 40, 4000);
  tone(8, pitch, 20);

  delay(10);
}
