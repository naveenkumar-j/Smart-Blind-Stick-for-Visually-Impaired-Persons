#define echoPin1 10
#define triggerPin1 13
#define echoPin2 9
#define triggerPin2 12
#define echoPin3 8
#define triggerPin3 11
#define buz 7
#define vibrator1 A2
#define vibrator2 A3
#define vibrator3 A4
int temppin=1;
int bt1=digitalRead(6); 
int switchPin1 = 6;
int switchPin2 = 5;
int sensorValue=0;
// defines variables
long duration1,duration2,duration3; // variable for the duration of sound wave travel
int distance1,distance2,distance3; // variable for the distance measurement
int val;


void setup() {
 Serial.begin(9600);
 pinMode(triggerPin1, OUTPUT);
 pinMode(echoPin1, INPUT);
 pinMode(triggerPin2, OUTPUT);
 pinMode(echoPin2, INPUT);
 pinMode(triggerPin3, OUTPUT);
 pinMode(echoPin3, INPUT);
 pinMode(buz, OUTPUT);
 pinMode(vibrator1, OUTPUT);
 pinMode(vibrator2, OUTPUT);
 pinMode(vibrator3, OUTPUT);
 pinMode(switchPin1, INPUT);
 pinMode(switchPin2, INPUT);
 pinMode(A5, INPUT);
 Serial.begin(9600);
}
void loop() {
 // Clears the trigPin condition
 delay(300);
 int v=300;
 
 digitalWrite(triggerPin1, LOW);
 digitalWrite(triggerPin2, LOW);
 digitalWrite(triggerPin3, LOW);
 delayMicroseconds(2);
 // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
 digitalWrite(triggerPin1, HIGH);
 delayMicroseconds(10);
 digitalWrite(triggerPin1, LOW);
 duration1 = pulseIn(echoPin1, HIGH);
 distance1 = duration1 * 0.034 / 2; // Calculating the distance
 
 digitalWrite(triggerPin2, HIGH);
 delayMicroseconds(10);
 digitalWrite(triggerPin2, LOW);
 duration2 = pulseIn(echoPin2, HIGH);
 distance2 = duration2 * 0.034 / 2; // Calculating the distance
 
 digitalWrite(triggerPin3, HIGH);
 delayMicroseconds(10);
 digitalWrite(triggerPin3, LOW);
 duration3 = pulseIn(echoPin3, HIGH);
 distance3 = duration3 * 0.034 / 2; // Calculating the distance
 
 sensorValue = analogRead(A5); 
 Serial.println(sensorValue);

 val=analogRead(temppin);
 float mv=(val/1024.0)*5000;
 float cel=mv/10;
 Serial.println(cel);
 

 int switchvalue1 = digitalRead(switchPin1); 
 if(switchvalue1==HIGH) //If button press only this condition may happen
 {
 
 if(cel<25) //Celsius can be low buzzer will on
 {
 tone(buz,1000);
 delay(300);
 noTone(buz);
 }
 if(cel>35) //Celsius can be high buzzer will on
 {
 tone(buz,1000);
 delay(300);
 noTone(buz);
 }
 }

  
 int switchvalue2 = digitalRead(switchPin2);
 if(switchvalue2==HIGH) // This button press only ldr work
 {
 if(sensorValue<200) //LDR detects its night then buzzer will on
 {
 tone(buz,1000);
 delay(500);
 noTone(buz);
 }
 }
 
 
 if(distance1<=v) //First sensor find obstacles then buzzer work
 {
 digitalWrite(vibrator1,HIGH);
 tone(buz,100,200);
 }
 else{
 digitalWrite(vibrator1,LOW);
 }
 if(distance2<=v) //Second sensor find obstacles then buzzer work
 {
 digitalWrite(vibrator2,HIGH);
 tone(buz,300,200);
 }
 else{
 digitalWrite(vibrator2,LOW);
 }
 if(distance3<=v) //Third sensor find obstacles then buzzer work
 {
 digitalWrite(vibrator3,HIGH);
 tone(buz,500,200);
 }
 else{
 digitalWrite(vibrator3,LOW);
 }
}
  