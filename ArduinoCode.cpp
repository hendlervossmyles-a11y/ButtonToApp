void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(10, INPUT_PULLUP); 
  pinMode(11, INPUT_PULLUP);
  pinMode(12, INPUT_PULLUP);
  pinMode(13, INPUT_PULLUP);

}

void loop() {
  
  const int W = 10;
  const int A = 11;
  const int S = 12;
  const int D = 13;
  bool input = digitalRead(10);
  if (input == HIGH) {
    Serial.print("False");
  }
  
}
