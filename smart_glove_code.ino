#include <LiquidCrystal.h>

#define voice1 8
#define voice2 9
#define voice3 10
const int flexPin1 = A0; 
const int flexPin2 = A1;
const int flexPin3 = A2;

LiquidCrystal lcd(2, 3, 4, 5, 6, 7); // LCD pins: RS, E, D4, D5, D6, D7
int value0;
int value1; 
int value2;
int value3;

void setup() {
  Serial.begin(9600);
  pinMode(voice1, OUTPUT);  
  pinMode(voice2, OUTPUT);
  pinMode(voice3, OUTPUT);
  digitalWrite(voice1, HIGH);
  digitalWrite(voice2, HIGH);
  digitalWrite(voice3, HIGH);
  lcd.begin(16, 2); // Initialize the LCD with 16 columns and 2 rows
  lcd.print("   WELCOME "); // Print label
delay(1000);
  lcd.clear();
  lcd.print("HAND GUSTURE WITH"); // Print value of flex sensor 1
  lcd.setCursor(0, 1); // Set cursor to the first column of the second row
  lcd.print("VOICE ANNOUNCEMENT ");
  delay(2000);
}

void loop() {
  value1 = analogRead(flexPin1);
  value2 = analogRead(flexPin2);
  value3 = analogRead(flexPin3);
     
  value1 = map(value1, 700, 900, 0, 255);
  value2 = map(value2, 700, 900, 0, 255);
  value3 = map(value3, 700, 900, 0, 255);
  
  Serial.println(value1);
  if(value0 <= -870) 
  {
  lcd.clear();  
   
  Serial.println("z");
  delay(2000);
  }
  
  else if(value1 <= -870) 
  {
  lcd.clear();  
  lcd.print("NEED GO WASHROOM"); // Print value of flex sensor 1
  digitalWrite(voice1, LOW);
  delay(2000);
  }
  else if(value2 <= -870) 
  {
    lcd.clear();  
    lcd.print("I NEED FOOD"); 
    digitalWrite(voice2, LOW);
    delay(2000);
  }
  else if(value3 <= -870) 
  {
    lcd.clear();  
    lcd.print("I NEED WATER"); 
    digitalWrite(voice3, LOW);
    delay(2000);
  }
  else 
  {
    lcd.clear();  
    lcd.print("  THANK YOU"); 
    digitalWrite(voice1, HIGH);
    digitalWrite(voice2, HIGH);
    digitalWrite(voice3, HIGH);
    delay(500);
  }
  
  
}
