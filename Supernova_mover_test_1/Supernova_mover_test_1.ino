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

String state= "";
int flag=0;   

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
    if(Serial.available())      
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
        
        if(flag == 0)
        {
          Serial.println("Forward");
          flag=1;
         }
         fwd();
    }
    else if (state="T")
    {
      if(flag == 0)
        {
          Serial.println("Trigger");
          flag=1;
         }
        trigger();
    }
    else if (state == "M")
    {
      if(flag == 0)
        {
          Serial.println("unTrigger");
          flag=1;
         }
        untrigger();
    }
    else if (state == "B")
    {
        
        if(flag == 0)
        {
          Serial.println("Backward");
          flag=1;
        }
        back();
    }
    else if (state == "P")
    {
        
        if(flag == 0)
        {
          Serial.println("Picker");
          flag=1;
         }
         picker();
    }
    else if (state == "U")
  {
        
        if(flag == 0)
        {
          Serial.println("Unpicker");
          flag=1;
         }
         unpicker();
    }
   else if (state == "O")
  {
        
        if(flag == 0)
        {
          Serial.println("UpRoller");
          flag=1;
         }
         uproller();
    }
    else if (state == "Z")
  {
        
        if(flag == 0)
        {
          Serial.println("DownRoller");
          flag=1;
         }
         downroller();
    }
}                                          
void fwd()          
{
  digitalWrite(7,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(6,LOW);
  digitalWrite(8,LOW);
  Serial.println("fwd is working");
  delay(100);
}
void back()          
{
  digitalWrite(8,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(7,LOW);
  digitalWrite(5,LOW);
  delay(100);
  Serial.println("back is working");
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
  Serial.println("downroller is working");
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
  Serial.println("uproller is working");
}
void stp()            
{
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  Serial.println("stop is working");
  delay(100);
}
void picker()
{servo1.write(60);
delay(100);
servo2.write(30);
Serial.println("picker is working");
}

void unpicker(){
servo1.write(50);
delay(100);
servo2.write(50);
Serial.println("unpicker is working");
}


void trigger()
{servo3.write(90);
Serial.println("trigger is working");
}
void untrigger(){
servo3.write(0);
//Serial.println("untrigger is working");
}
