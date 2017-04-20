#include <SoftwareSerial.h>
#include <Servo.h>

char data = 0;                
Servo motor0;
Servo motor1;
Servo motor2;
Servo motor3;
int ledPin = 13;
void setup() 
{
  Serial.begin(9600);
  
  motor0.attach(7);
  motor1.attach(6);
  motor2.attach(5);
  motor3.attach(4);
  
  motor0.writeMicroseconds(2200); 
  motor1.writeMicroseconds(2200); 
  motor2.writeMicroseconds(2200); 
  motor3.writeMicroseconds(2200); 
  delay(2000);
  motor0.writeMicroseconds(800); 
  motor1.writeMicroseconds(800); 
  motor2.writeMicroseconds(800); 
  motor3.writeMicroseconds(800); 
  delay(6000);
}
void loop()
{
  if(Serial.available() > 0)
  {
    data = Serial.read();      
    Serial.print(data);        
    Serial.print("\n");        
    if(data == '1'){            
      motor0.writeMicroseconds(2000);
      motor1.writeMicroseconds(1000);
      motor2.writeMicroseconds(1000);
      motor3.writeMicroseconds(1000);
      //digitalWrite(ledPin, HIGH);   
    }
    else if(data == '0'){       
      motor0.writeMicroseconds(800);
      motor1.writeMicroseconds(800);
      motor2.writeMicroseconds(800);
      motor3.writeMicroseconds(800);
      //digitalWrite(ledPin, LOW);   
    }
  }
}
