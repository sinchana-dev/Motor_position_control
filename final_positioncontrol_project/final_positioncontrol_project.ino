#define PWM_PIN 5
#define DIR_PIN 6
#define ENCA 18
#define ENCB 19

volatile long encoderCount = 0;
long targetCount = 0;

void readEncoder() {
  int b = digitalRead(ENCB);
  if (b == HIGH) encoderCount++;
  else encoderCount--;
}

void setup() {
  pinMode(PWM_PIN, OUTPUT);
  pinMode(DIR_PIN, OUTPUT);
  pinMode(ENCA, INPUT);
  pinMode(ENCB, INPUT);
  attachInterrupt(digitalPinToInterrupt(ENCA), readEncoder, RISING);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    int val = Serial.parseInt();
    if (val != 0) {
      targetCount = encoderCount + val;
      if (val > 0) digitalWrite(DIR_PIN, HIGH);
      else digitalWrite(DIR_PIN, LOW);

      while ((val > 0 && encoderCount < targetCount) || (val < 0 && encoderCount > targetCount)) {
        long error = abs(targetCount - encoderCount);
        int speed = map(error, 0, 100, 80, 200);
        speed = constrain(speed, 80, 200);
        analogWrite(PWM_PIN, speed);
      }
      analogWrite(PWM_PIN, 0);
    }
  }
}

