
struct DCMotor {
  int pin1, pin2, speedPin;

  void setup() {
    pinMode(pin1, OUTPUT);
    pinMode(pin2, OUTPUT);
    pinMode(speedPin, OUTPUT);
  }

  void setSpeed(int s) {
    analogWrite(speedPin, s);
  }

  void forward() {
    digitalWrite(pin1, HIGH);
    digitalWrite(pin2, LOW);
  }

  void backward() {
    digitalWrite(pin1, LOW);
    digitalWrite(pin2, HIGH);
  }
};

DCMotor m1{2, 3, 9}, m2{4, 5, 10};

void setup() {
  // put your setup code here, to run once:
  m1.setup();
  m2.setup();

  m1.setSpeed(128);
  m2.setSpeed(255);
}

void loop() {
  // put your main code here, to run repeatedly:
  m1.forward();
  m2.forward();
  
  delay(1000);

  m1.backward();
  m2.backward();

  delay(1000);
}