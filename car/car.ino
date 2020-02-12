int enA = 10;
int in1 = 9;
int in2 = 8;

int enB = 5;
int in3 = 7;
int in4 = 6;

//void forwards();
//void backwards();
//void right();
//void left();
//void stop_car();

void forwards() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void backwards() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void right() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void left() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void stop_car() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

void setup() {
  Serial.begin(9600);
  analogWrite(enA, 45);
  analogWrite(enB, 45);
}

void turn_left(){
  while (digitalRead(11) != 0)
  {
    left();
  }
}

void turn_right(){
  while (digitalRead(12) != 0)
  {
    right();
  }
}

void loop() {
 if (digitalRead(11) >= 0 and digitalRead(12) >= 0)
 {
  forwards();
  delay(200);
 }
 if(digitalRead(11) == 0)
 {
  turn_left();
  delay(200);
 }
 if(digitalRead(12) == 0)
 {
  turn_right();
  delay(200); 
 }
}
