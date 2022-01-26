#include <LiquidCrystal.h>

const int pingpin = 10;
const int ledlight = 7;
const int buzzer = 12;
const int enable = 8;
const int reg_sel = 9;
const int lcdpins[4] = {2, 3, 4, 5};
int total = 0;

LiquidCrystal lcd(reg_sel, enable, lcdpins[0], lcdpins[1], lcdpins[2], lcdpins[3]);


void setup()
{
  pinMode(ledlight, OUTPUT);
  pinMode(buzzer, OUTPUT);
  
  notify();
  print("START", total);
}


void loop()
{
  long duration, distance;
  
  pinMode(pingpin, OUTPUT);
  
  digitalWrite(pingpin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingpin, HIGH);
  delayMicroseconds(5);
  
  pinMode(pingpin, INPUT);
  
  duration = pulseIn(pingpin, HIGH);
   
  distance = microtocm(duration);
  
  if(distance > 20 && distance < 200){
    total++;
    notify();
    print("People Visited", total);
    delay(3000);
  }
}


long microtocm(long microseconds){
  return microseconds/29/2;
}


void notify(){
  digitalWrite(ledlight, HIGH);
  digitalWrite(buzzer, HIGH);
  
  delay(100);
  
  digitalWrite(ledlight, LOW);
  digitalWrite(buzzer, LOW);
}

void print(String a, int num){
  lcd.begin(16, 2);
  lcd.setCursor(0,0);
  lcd.print(a);
  lcd.setCursor(0,1);
  lcd.print(num);
}