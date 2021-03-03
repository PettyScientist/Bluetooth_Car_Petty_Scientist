/*Made By:Vardan Kulshreshtha
  From:Petty Scientist
  Made for: All our youtube viewers
  link:  https://www.youtube.com/channel/UC1O3wigNYK_TBPgUkHXkGGQ
  
  
  This is code made for bluetooth Car which work with made by our team. The .apk of app can be found in the included .zip file
  */



#include <AFMotor.h>// this is library which we use to run motors with L293d Motor Driver Shield.

AF_DCMotor motor1(1);//this step is taken to introduce the component to Library and Motor driver shield
AF_DCMotor motor2(3);


char value;// Data Type(Value)= Character set/String Variable
void setup()
{
  //Set initial speed of the motor & stop
  motor1.setSpeed(255);//to set the speed of motor but writing release prevent the acciedental acceleration of motor
  motor1.run(RELEASE);

  motor2.setSpeed(255);
  motor2.run(RELEASE);
                                                                         //____________________________________________________________
  Serial.begin(9600);//to establish communication with bluetooth.          while uploading code remove Tx and Rx then plug them in again
}                                                                        //______________________________________________________________

void loop()
  {
   if(Serial.available()>0){                  //this is to declare the value of variable to the data we will recieve from the bluetooth module. 
   char value=Serial.read();
  }
  
  if(value='FORWARD')
  {
     motor1.run(FORWARD);
     motor2.run(FORWARD);
  }

  if(value='BACKWARD')
  {
   motor1.run(BACKWARD); 
   motor2.run(BACKWARD);
   }
 
  if(value='RIGHT')
  {
    motor1.run(FORWARD);
    motor2.run(RELEASE);
  }

  if(value='LEFT');
  {
    motor1.run(RELEASE);
    motor2.run(FORWARD);
  }

  if(value='STOP'){
    motor1.run(RELEASE);       //the motor stops when no button is pressed so car may still.
    motor2.run(RELEASE);
  }

  
  }
