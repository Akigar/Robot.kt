#define PIN_TRIG 11
#define PIN_ECHO 12
#define PIN_PIR 2

long duration, cm;

void setup() {

  Serial.begin (9600);
  //Определяем вводы и выводы
  pinMode(PIN_TRIG, OUTPUT);
  pinMode(PIN_ECHO, INPUT);
}

void loop() {

  int pirVal = digitalRead(PIN_PIR);


  digitalWrite(PIN_TRIG, LOW);
  delayMicroseconds(5);
  digitalWrite(PIN_TRIG, HIGH);

  delayMicroseconds(10);
  digitalWrite(PIN_TRIG, LOW);

  duration = pulseIn(PIN_ECHO, HIGH);

  Serial.println("Motion detected");
  Serial.println(digitalRead(PIN_PIR));
  delay(500);
  

  if (digitalRead(PIN_PIR))
  {
    cm = (duration / 2) / 29.1;

    Serial.print("Distance: ");
    Serial.print(cm);
    Serial.println(" cm.");
  }

  delay(250);
}
