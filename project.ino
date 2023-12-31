int trigPin = 9; // Trig Pin Of HC-SR04
int echoPin = 8; // Echo Pin Of HC-SR04
int revleft4 = 10; // Motor Pins
int fwdleft5 = 11;
int revright6 = 12;
int fwdright7 = 13;
long time, distance;
void setup() {
Serial.begin(9600);
pinMode(revleft4, OUTPUT); // Set Motor Pins
//As O/P
pinMode(fwdleft5, OUTPUT);
pinMode(revright6, OUTPUT);
pinMode(fwdright7, OUTPUT);
pinMode(trigPin, OUTPUT); // Set Trig Pin As
//O/P To Transmit Waves
pinMode(echoPin, INPUT); //Set Echo Pin As
//I/P To Recieve Reflected Waves
}
void loop() {
digitalWrite(trigPin,LOW);
delayMicroseconds(2);
digitalWrite(trigPin,HIGH);
delayMicroseconds(10);
digitalWrite(trigPin,LOW);
delayMicroseconds(2);
time=pulseIn(echoPin,HIGH);
distance=time*340/20000;
delay(10);
if (distance > 5) // Condition For Absence Of
//Obstacle
{
digitalWrite(fwdright7, HIGH); // Move
//Forward
digitalWrite(revright6, LOW);
digitalWrite(fwdleft5, HIGH);
digitalWrite(revleft4, LOW);
}
if (distance < 5) // Condition For Presence Of
//Obstacle
{
digitalWrite(fwdright7, LOW); //Stop
digitalWrite(revright6, LOW);
digitalWrite(fwdleft5, LOW);
digitalWrite(revleft4, LOW);
delay(500);
digitalWrite(fwdright7, LOW); // Move
//Backward  
 digitalWrite(revright6, HIGH); 
 digitalWrite(fwdleft5, LOW);  
 digitalWrite(revleft4, HIGH); 
 delay(500); 
 digitalWrite(fwdright7, LOW); //Stop   digitalWrite(revright6, LOW); 
 digitalWrite(fwdleft5, LOW);  
 digitalWrite(revleft4, LOW);  
delay(100);  
 digitalWrite(fwdright7, HIGH); // Move Left   digitalWrite(revright6, LOW);  
 digitalWrite(revleft4, LOW);  
 digitalWrite(fwdleft5, LOW);  
 delay(500);}}
