#include <SoftwareSerial.h>

#define RX 12
#define TX 13

#define SPEED 100

#define BAUD 9600

#define DELAY_MS 100

#define FORWARD ('1')
#define BACKWARD ('2')
#define RIGHT ('3')
#define LEFT ('4')
#define STOP ('5')

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

  void stop() {
    digitalWrite(pin1, LOW);
    digitalWrite(pin2, LOW);
  }
};

DCMotor m1{2, 3, 9}, m2{4, 5, 10};

SoftwareSerial BT(RX, TX);

int r = '0';

void setup() {
  // put your setup code here, to run once:
  BT.begin(BAUD);
  Serial.begin(BAUD);

  m1.setup();
  m2.setup();
  m1.setSpeed(SPEED);
  m2.setSpeed(SPEED);
}

void stop() {
  BT.println("S");
  m1.stop();
  m2.stop();
}

void forward() {
  BT.println("F");
  m1.forward();
  m2.forward();
}

void backward() {
  BT.println("B");
  m1.backward();
  m2.backward();
}

void right() {
  BT.println("R");
  m1.forward();
  m2.backward();
}

void left() {
  BT.println("L");
  m1.backward();
  m2.forward();
}

void loop() {
  // put your main code here, to run repeatedly:
  if (BT.available() > 0) {
    r = BT.read();
    Serial.println((char)r);
  }

  if (r == FORWARD)
    forward();
  else if (r == BACKWARD)
    backward();
  else if (r == RIGHT)
    right();
  else if (r == LEFT)
    left();
  else if (r == STOP)
    stop();

  delay(DELAY_MS);
}
