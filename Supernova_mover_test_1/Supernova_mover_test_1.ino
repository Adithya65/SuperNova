#include <Stepper.h>

#include<Servo.h>
Servo servo1; //for clamping
Servo servo2; //for picking
Servo servo3; //for adjustment

const int dirPin1 = 2;
const int stepPin1 = 3;
const int dirPin2 = 4;
const int stepPin2 = 5;
const int stepsPerRevolution = 200;

String state= " ";
int flag=0;       
void stp();
void fwd();
void left();
void right();
void back();
void setup()
{  pinMode(stepPin1, OUTPUT);
  pinMode(dirPin1, OUTPUT);
  pinMode(stepPin2, OUTPUT);
  pinMode(dirPin2, OUTPUT);
  
  servo1.attach(13);
    servo2.attach(12);
    servo3.attach(11);
    pinMode(7,OUTPUT);                  
    pinMode(8,OUTPUT);                  
    pinMode(5,OUTPUT);                  
    pinMode(6,OUTPUT);                  
Serial.begin(9600);                                         
}
void loop() {
    if(Serial.available()== true)      
    {    
       state= Serial.readString();
       Serial.println(state);
       
      flag=0;
    }  
    if (state == "S")     
    {
        stp();
        if(flag == 0){
          Serial.println("Stop");
          flag=1;
       }
    }
    else if (state == "F")
    {
        fwd();
        if(flag == 0)
        {
          Serial.println("Forward");
          flag=1;
         }
    }
    else if (state == "B")
    {
        back();
        if(flag == 0)
        {
          Serial.println("Backward");
          flag=1;
        }
    }
    else if (state == "p")
    {
        picker();
        if(flag == 0)
        {
          Serial.println("Picker");
          flag=1;
         }
    }
    else if (state == "U")
  {
        unpicker();
        if(flag == 0)
        {
          Serial.println("Unpicker");
          flag=1;
         }
    }
   else if (state == "O")
  {
        uproller();
        if(flag == 0)
        {
          Serial.println("UpRoller");
          flag=1;
         }
    }
    else if (state == "Z")
  {
        downroller();
        if(flag == 0)
        {
          Serial.println("DownRoller");
          flag=1;
         }
    }
}                                          
void fwd()          
{
  digitalWrite(7,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(6,LOW);
  digitalWrite(8,LOW);
}
void back()          
{
  digitalWrite(8,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(7,LOW);
  digitalWrite(5,LOW);
}
void downroller()         
{
  digitalWrite(dirPin1, LOW);
   digitalWrite(dirPin2, LOW);
 
  // Spin motor slowly
  for(int x = 0; x < stepsPerRevolution; x++)
  {
    digitalWrite(stepPin1, HIGH);
     digitalWrite(stepPin2, HIGH);
    delayMicroseconds(2000);
    digitalWrite(stepPin1, LOW);
     digitalWrite(stepPin2, LOW);
    delayMicroseconds(2000);
  }
  delay(1000); 
}
void uproller()          
{
   digitalWrite(dirPin1, HIGH);
   digitalWrite(dirPin2, HIGH);
 
  // Spin motor slowly
  for(int x = 0; x < stepsPerRevolution; x++)
  {
    digitalWrite(stepPin1, HIGH);
     digitalWrite(stepPin2, HIGH);
    delayMicroseconds(2000);
    digitalWrite(stepPin1, LOW);
     digitalWrite(stepPin2, LOW);
    delayMicroseconds(2000);
  }
  delay(1000); 
}
void stp()            
{
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
}
void picker()
{servo1.write(60);
delay(100);
servo2.write(30);
}

void unpicker(){
servo1.write(50);
delay(100);
servo2.write(50);
}
