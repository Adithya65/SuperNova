#include <Servo.h>

int angle1=180; //initial angle for servo
int angle2=0;   //final angle

Servo servo1; 
Servo servo2;


int state;
int flag=0;       
void stp();
void fwd();
void left();
void right();
void back();
void setup()
{   servo1.attach(2);
    servo1.write(angle1);
    pinMode(7,OUTPUT);                  
    pinMode(8,OUTPUT);                  
    pinMode(5,OUTPUT);                  
    pinMode(6,OUTPUT);   
                 
Serial.begin(9600);                                         
}
void loop() {
    if(Serial.available() > 0)      
    {    
      state = Serial.read();
      Serial.println(state);  
      flag=0;
    }  
    if (state == '1')     
    {
        stp();
        if(flag == 0){
          Serial.println("Stop");
          flag=1;
       }
    }
    else if (state == '2')
    {
        fwd();
        if(flag == 0)
        {
          Serial.println("Forward");
          flag=1;
         }
    }
    else if (state == '3')
    {
        back();
        if(flag == 0)
        {
          Serial.println("Backward");
          flag=1;
        }
    }
    else if (state == '4')
    {
        serv_rotate();
        if(flag == 0)
        {
          Serial.println("Sevo actuated");
          flag=1;
         }
    }
   else if (state == '5')
  {
        stepper_rotate();
        if(flag == 0)
        {
          Serial.println("Stepper actuated");
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
void serv_rotate()         
{
 servo1.write(angle2);
}
void stepper_rotate()          
{
  //stepper
}
void stp()            
{
 
}
