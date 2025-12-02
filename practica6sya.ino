//Librerias
#include<Wire.h>
#include<Servo.h>
#include<LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
Servo ventana;
//constantes
const int servoPin = 9;
const int steamPin = A1;
const int UMBRAL = 500;
const int sensorGas = 12;
const int botonAbierto = 6;
const int botonCerrado = 7;
const int ventilador = 11;
//variables
float temp = 0;
int estadoVentana = 0;
void setup() {
  lcd.init();
  lcd.backlight();
  pinMode(sensorGas,INPUT);
  pinMode(ventilador,OUTPUT);
  pinMode(botonAbierto, INPUT_PULLUP);
  pinMode(botonCerrado, INPUT_PULLUP);
  ventana.attach(servoPin);
  ventana.write(0);

}

void loop() {
  int valor = analogRead(steamPin);
  if(digitalRead(botonAbierto)==LOW || estadoVentana == 1){
    digitalWrite(ventilador,LOW);
    ventana.write(90);
    lcd.setCursor(0,0);
    lcd.clear();
    lcd.print("Lluvia:");
    lcd.setCursor(13,0);
    lcd.print("OFF");
    lcd.setCursor(0,1);
    lcd.print("GAS:");
    lcd.setCursor(13,1);
    lcd.print("OFF");
    estadoVentana = 1;
  }
  if(digitalRead(botonCerrado)==LOW || estadoVentana == 0){
    digitalWrite(ventilador,LOW);
    estadoVentana = 0;
    lcd.setCursor(0,0);
    lcd.clear();
    lcd.print("Lluvia:");
    lcd.setCursor(13,0);
    lcd.print("OFF");
    lcd.setCursor(0,1);
    lcd.print("GAS:");
    lcd.setCursor(13,1);
    lcd.print("OFF");
    ventana.write(0);
  }
  if(valor >= UMBRAL && digitalRead(sensorGas)==LOW){
    lcd.setCursor(0,0);
    lcd.clear();
    lcd.print("Lluvia:");
    lcd.setCursor(13,0);
    lcd.print("ON");
    lcd.setCursor(0,1);
    lcd.print("GAS:");
    lcd.setCursor(13,1);
    lcd.print("ON");
    ventana.write(90);
    delay(1000);
    digitalWrite(ventilador,HIGH);
    estadoVentana = 1;
  }
  if(valor < UMBRAL && digitalRead(sensorGas)==LOW){
    lcd.setCursor(0,0);
    lcd.clear();
    lcd.print("Lluvia:");
    lcd.setCursor(13,0);
    lcd.print("OFF");
    lcd.setCursor(0,1);
    lcd.print("GAS:");
    lcd.setCursor(13,1);
    lcd.print("ON");
    ventana.write(90);
    delay(1000);
    digitalWrite(ventilador,HIGH);
    estadoVentana = 1;
  }
  if(digitalRead(sensorGas)==HIGH && valor >= UMBRAL){
    digitalWrite(ventilador,LOW);
    lcd.setCursor(0,0);
    lcd.clear();
    lcd.print("Lluvia:");
    lcd.setCursor(13,0);
    lcd.print("ON");
    lcd.setCursor(0,1);
    lcd.print("GAS:");
    lcd.setCursor(13,1);
    lcd.print("OFF");
    ventana.write(0);
    estadoVentana = 0;

  }
  delay(500);
}
