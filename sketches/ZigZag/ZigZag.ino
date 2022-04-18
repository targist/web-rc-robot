#define A 11
#define B 10
#define C 9
#define D 8

#define SPEED_AB_PIN 12
#define SPEED_CD_PIN 7
#define SPEED 255
#define LED 13
#define DELAY_MS 1000

void setup() {
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);

  pinMode(SPEED_AB_PIN, OUTPUT);
  pinMode(SPEED_CD_PIN, OUTPUT);

  analogWrite(SPEED_AB_PIN, SPEED);
  analogWrite(SPEED_CD_PIN, SPEED);

  stop();

  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);
}

void stop() {
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW);
}

void forward() {
  digitalWrite(LED, LOW);
  digitalWrite(A, HIGH);
  digitalWrite(B, LOW);
  digitalWrite(C, HIGH);
  digitalWrite(D, LOW);
}

void backward() {
  digitalWrite(LED, HIGH);
  digitalWrite(A, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(C, LOW);
  digitalWrite(D, HIGH);
}

void loop() {
  forward();
  delay(DELAY_MS);

  stop();
  delay(DELAY_MS);

  backward();
  delay(DELAY_MS);
}
