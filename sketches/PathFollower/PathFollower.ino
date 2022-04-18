#include <SoftwareSerial.h>

#define RX 6
#define TX 5

#define A 11
#define B 10
#define C 9
#define D 8

#define SPEED_AB_PIN 12
#define SPEED_CD_PIN 7

#define SPEED 100

#define LED 13
#define BAUD 9600
#define DELAY_MS 200

SoftwareSerial BT(RX, TX);
int r = '0';

void setup() {
  // put your setup code here, to run once:
  BT.begin(BAUD);

  pinMode(LED, OUTPUT);

  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);

  pinMode(SPEED_AB_PIN, OUTPUT);
  pinMode(SPEED_CD_PIN, OUTPUT);

  analogWrite(SPEED_AB_PIN, SPEED);
  analogWrite(SPEED_CD_PIN, SPEED);

  digitalWrite(LED, LOW);
}

void stop() {
  BT.println("S");
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW);
}

void forward() {
  BT.println("F");
  digitalWrite(A, HIGH);
  digitalWrite(B, LOW);
  digitalWrite(C, HIGH);
  digitalWrite(D, LOW);
}

void backward() {
  BT.println("B");
  digitalWrite(A, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(C, LOW);
  digitalWrite(D, HIGH);
}

void right() {
  BT.println("R");
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, HIGH);
  digitalWrite(D, LOW);
}

void left() {
  BT.println("L");
  digitalWrite(A, HIGH);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (BT.available() > 0) {
    r = BT.read();
    BT.println((char)r);
    digitalWrite(LED, HIGH);
  }

  if (r == '1')
    forward();
  else if (r == '2')
    backward();
  else if (r == '3')
    right();
  else if (r == '4')
    left();
  else if (r == '5')
    stop();

  delay(DELAY_MS);
  digitalWrite(LED, LOW);
}
