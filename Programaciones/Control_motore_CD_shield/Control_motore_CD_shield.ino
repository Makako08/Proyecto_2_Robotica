int adelante = 10;
int atras = 11;

void setup() {
  pinMode(adelante, OUTPUT);
  pinMode(atras, OUTPUT);
  pinMode(8, INPUT);
  pinMode(9, INPUT);
}

void loop() {
  digitalWrite(adelante, LOW);
  digitalWrite(atras, LOW);


  while (digitalRead(8) == HIGH) {
    digitalWrite(atras, HIGH);
    digitalWrite(adelante, LOW);
  }

  while (digitalRead(9) == HIGH) {
    digitalWrite(adelante, HIGH);
    digitalWrite(atras, LOW);
  }  
}
