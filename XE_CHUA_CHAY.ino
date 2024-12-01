#include <Servo.h>
Servo servo; 
#define cambienP A0
#define cambienG A1
#define cambienT A2
#define bom A3
#define gas 7
#define IN1 8
#define IN2 9
#define IN3 10
#define IN4 11
#define coi A4
void setup() {
  // put your setup code here, to run once:
  servo.attach(12);
  Serial.begin(9600);
  servo.write(90);
pinMode(cambienP, INPUT_PULLUP);
pinMode(cambienG, INPUT_PULLUP);
pinMode(cambienT, INPUT_PULLUP);
pinMode(gas, INPUT_PULLUP);
pinMode(bom, OUTPUT);
pinMode(IN1, OUTPUT);
pinMode(IN2, OUTPUT);
pinMode(IN3, OUTPUT);
pinMode(IN4, OUTPUT);
pinMode(coi, OUTPUT);
delay(5000);
delay(1000);
  Serial.println("AT"); //Check GSM Module
  delay(1000);
  Serial.println("ATE1"); //Echo ON
  delay(1000);
  Serial.println("AT+CPIN?"); //Check SIM ready
  delay(1000);
  Serial.println("AT+CMGF=1"); //SMS text mode
  delay(1000);
  Serial.println("AT+CNMI=2,2,0,0,0"); //set sms received format
  delay(3000); 
}
void tien(){
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void trai(){
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void phai(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}
void dung(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
void loop() {
 if(digitalRead(gas) == 0){
  digitalWrite(coi, HIGH);
   Serial.println("AT+CMGF=1");
    delay(1000);
    Serial.println("AT+CMGS=\"+0777015705\"\r");   //Số điện thoại nhận tin nhắn phản hồi
    delay(1000);
    Serial.print("PHAT HIEN RO RI KHI GAS");
    delay(1000);
    Serial.println((char)26); //ascii code for ctrl-26 //Serial.println((char)26); //ascii code for ctrl-26
    delay(1000);
  }
if(digitalRead(cambienG) == 0){
  digitalWrite(coi, HIGH);
   Serial.println("ATD+84777015705;");
   delay(1000);
   tien();
  delay(1000);
  dung();
  digitalWrite(bom, HIGH);
  
  delay(2000);
  servo.write(90);

}

if(digitalRead(cambienP) == 0){
  tien();
  delay(1000);
  dung();
  delay(1000);
  servo.write(30);
  delay(100);
  digitalWrite(coi, HIGH);
  digitalWrite(bom, HIGH);
  delay(1000);
  
}

if(digitalRead(cambienT) == 0){
   tien();
  delay(1000);
  dung();
  delay(1000);
  servo.write(150);
  delay(100)
  ;
  digitalWrite(bom, HIGH);
  digitalWrite(coi, HIGH);
  delay(1000);
}
if(digitalRead(cambienT) == 1 && digitalRead(cambienT) == 1 && digitalRead(cambienT) == 1)
{digitalWrite(bom,LOW);
digitalWrite(coi, LOW);
  dung();
  servo.write(90);
}
}
