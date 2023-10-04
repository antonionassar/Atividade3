int ledPins[] = { 4, 16, 17, 5 };
int butPins[] = { 34, 35, 32, 33 };
int start = 25;
bool gameStart = false;
int said[300];
int len = 0;

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 4; i++) {
    pinMode(ledPins[i], OUTPUT);
    pinMode(butPins[i], INPUT);
    digitalWrite(ledPins[i], LOW);
  }
  pinMode(start, INPUT);
}

void readSeq() {
  for (int i = 0; i < len; i++) {
    int command = said[i];
    int led = ledPins[command];
    digitalWrite(led, HIGH);
    delay(500);
    digitalWrite(led, LOW);
    delay(100);
  }
}

void checkBegin() {
  if (digitalRead(start) == HIGH && !gameStart) {
    gameStart = true;
    Serial.println("Start!");
  }
}

int readInput() {
  while (true) {
    for (int u = 0; u < 4; u++) {
      int pin = butPins[u];
      if (digitalRead(pin) == HIGH) {
        return u;
      }
    }
    delay(10);
  }
}

bool userSeq() {
  for (int i = 0; i < len; i++) {
    int expected = (int)said[i];
    Serial.println(expected);
    int input = (int)readInput();
    Serial.println(input);
    digitalWrite(ledPins[input], HIGH);
    delay(300);
    digitalWrite(ledPins[input], LOW);
    if (expected != input) {
      return false;
    }
  }
  return true;
}

void gameOver() {
  Serial.println("Game over!");
  for (int i = 0; i < 4; i++) {
    digitalWrite(ledPins[i], HIGH);
    delay(100);
  }
  delay(400);
  for (int i = 3; i > -1; i--) {
    digitalWrite(ledPins[i], LOW);
    delay(100);
  }
  gameStart = false;
  len = 0;
}

void menu() {
  for (int i = 0; i < 4; i++) {
    digitalWrite(ledPins[i], HIGH);
    checkBegin();
    delay(300);
    digitalWrite(ledPins[i], LOW);
    delay(100);
  }
}

void loop() {
  checkBegin();
  if (!gameStart) {
    menu();
  } else {
    said[len] = (int)random(0, 4);
    len++;
    readSeq();
    delay(200);
    if (!userSeq()) {
      gameOver();
    }
    delay(300);
  }
}
