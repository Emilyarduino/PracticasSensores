const int echo = 2;
const int trigger = 3;
const int IN1 = 9;
const int IN2 = 10;
const int IN3 = 8;
const int IN4 = 7;
const int ENA = 6;
const int ENB = 5;
const int pinLed = 13;
long duration;
float distance;
void setup() {
  pinMode(echo, INPUT);
  pinMode(trigger, OUTPUT);
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  pinMode(ENA,OUTPUT);
  pinMode(ENB,OUTPUT);
  pinMode(pinLed,OUTPUT);
  digitalWrite(pinLed,LOW);
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);
  analogWrite(ENA,0);
  analogWrite(ENB,0);

}

void loop() {
  digitalWrite(pinLed,HIGH);
  digitalWrite(trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);

  duration = pulseIn(echo,HIGH);
  distance = duration * 0.034/2;
  if(distance>=10){
    digitalWrite(IN1,HIGH);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,HIGH);
    analogWrite(ENA,70);
    analogWrite(ENB,70);
  }
  else{
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,LOW);
    analogWrite(ENA,0);
    analogWrite(ENB,0);
    for(int i = 0; i<=10; i++){
      digitalWrite(pinLed,HIGH);
      delay(300);
      digitalWrite(pinLed,LOW);
      delay(300);
      i++;
    }
  }

}
