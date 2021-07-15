
#include<Servo.h>
Servo servo1;
Servo servo2;

String state= " ";
int flag=0;       
void stp();
void fwd();
void left();
void right();
void back();
void setup()
{   servo1.attach(13);
    servo2.attach(12);
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
        right();
        if(flag == 0)
        {
          Serial.println("UpRoller");
          flag=1;
         }
    }
    else if (state == "Z")
  {
        right();
        if(flag == 0)
        {
          Serial.println("DownRoller");
          flag=1;
         }
    }else if (state == "X")
  {
        right();
        if(flag == 0)
        {
          Serial.println("Speed1x");
          flag=1;
         }
    }else if (state == "W")
  {
        right();
        if(flag == 0)
        {
          Serial.println("Speed2x");
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
void left()         
{
  digitalWrite(7,HIGH);
  digitalWrite(5,LOW);
  digitalWrite(8,LOW);
  digitalWrite(6,LOW);
}
void right()          
{
  digitalWrite(7,LOW);
  digitalWrite(5,HIGH);
  digitalWrite(8,LOW);
  digitalWrite(6,LOW);
}
void stp()            
{
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
}
void picker()
{servo1.write(50);
servo2.write(50);
}

void unpicker(){
  servo1.write(50);
servo2.write(50);
}
