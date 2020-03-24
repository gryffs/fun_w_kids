#include <Servo.h>

Servo myservo;

const int trigPin = 11;
const int echoPin = 12;

int pos = 0;

float duration, distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);

  myservo.attach(9);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration*.0343)/2 * 9;
  Serial.print("Distance: ");
  Serial.println(distance);

  if(distance > 180) {
    distance = 180;
  }
  
  myservo.write(distance);

  delay(15);

//  for (pos = 0; pos <= 180; pos += 1) {
//    myservo.write(pos);
//    delay(15);
//  }
//  for (pos = 180; pos >= 0; pos -= 1) {
//    myservo.write(pos);
//    delay(15);
//  }
}
