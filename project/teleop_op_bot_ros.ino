#include <ros.h>
#include <std_msgs/String.h>

ros::NodeHandle nh;

String var;
const int motorPin1  = 8;  // Pin 14 of L293
const int motorPin2  = 9;  // Pin 10 of L293
const int motorPin3  = 10;  // Pin 14 of L293
const int motorPin4  = 11;  // Pin 10 of L293

void messageCb(const std_msgs::String &msg)
{
  var=msg.data;
 
  if(var == "f")
   forward();
  else if(var == "b")
   backward();
  else if(var == "l")
   leftward();
  else if(var == "r")
   rightward();
  else
   stops(); 
     
}

ros::Subscriber<std_msgs::String> sub("keys", &messageCb);

void setup()
{
  pinMode(13, OUTPUT);
  nh.initNode();
  nh.subscribe(sub);
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);
}

void loop()
{
  nh.spinOnce();
  delay(200);
}
void forward()
{
digitalWrite(motorPin1, HIGH);
digitalWrite(motorPin2, LOW);
digitalWrite(motorPin3, LOW);
digitalWrite(motorPin4, HIGH);
}
void stops()
{
digitalWrite(motorPin1,LOW);
digitalWrite(motorPin2, LOW);
digitalWrite(motorPin3, LOW);
digitalWrite(motorPin4,LOW);
}
void backward()
{
digitalWrite(motorPin1, LOW);
digitalWrite(motorPin2, HIGH);
digitalWrite(motorPin3, HIGH);
digitalWrite(motorPin4, LOW);  
}
void leftward()
{
digitalWrite(motorPin1, HIGH);
digitalWrite(motorPin2, LOW);
digitalWrite(motorPin3, LOW);
digitalWrite(motorPin4, LOW); 

}
void rightward()
{
digitalWrite(motorPin1, LOW);
digitalWrite(motorPin2, LOW);
digitalWrite(motorPin3, LOW);
digitalWrite(motorPin4, HIGH); 

}


