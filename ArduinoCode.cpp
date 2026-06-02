const int W = 10;
const int A = 11;
const int S = 12;
const int D = 13;

void setup() {
  Serial.begin(9600);
  pinMode(W, INPUT_PULLUP);
  pinMode(A, INPUT_PULLUP);
  pinMode(S, INPUT_PULLUP);
  pinMode(D, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(W) == LOW) {
    Serial.print("W\n");
  }
  else if (digitalRead(A) == LOW) {
    Serial.print("A\n");
  }
  else if (digitalRead(S) == LOW) {
    Serial.print("S\n");
  }
  else if (digitalRead(D) == LOW) {
    Serial.print("D\n");
  }
}