#include <Stepper.h>
const int stepsPerRevolution = 90;
//22
#include<Servo.h>
Servo servo1; //for clamping
Servo servo2; //for picking
Servo servo3; //for adjustment

Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);

String state= " ";
int flag=0;       
void stp();
void fwd();
void left();
void right();
void back();
void setup()
{ myStepper.setSpeed(5);
  
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
  Serial.println("counterclockwise");
   myStepper.step(-stepsPerRevolution);
   delay(500);
}
void uproller()          
{
  Serial.println("clockwise");
   myStepper.step(stepsPerRevolution);
   delay(500);
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
