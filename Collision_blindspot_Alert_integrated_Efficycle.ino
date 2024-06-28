// Pins for the first leftt ultrasonic sensor
const int trigPin1 = 22;
const int echoPin1 = 23;
int l1 = 40; // blue led left
int l2 = 41; // red led left


// Pins for the second front ultrasonic sensor
const int trigPin2 = 26;
const int echoPin2 = 27;
int l3 = 44; // blue led left
int l4 = 45; // red led left

// Pins for the third right ultrasonic sensor
const int trigPin3 = 30;
const int echoPin3 = 31; 
int l5 = 48; // blue led left
int l6 = 49 ; // red led left

// Pins for the 4th Back ultrasonic sensor
const int trigPin4 = 34;
const int echoPin4 = 35; 
int l7 = 52; // blue led left
int l8 = 53; // red led left

// Pins for the first leftt mirror ultrasonic sensor
const int trigPin5 = 4;
const int echoPin5 = 5;
int l9 = 9; // blue led left
int l10 = 10; // red led left

// Pins for the first right mirror ultrasonic sensor
const int trigPin6 = 6;
const int echoPin6 = 7;
int l11 = 11; // blue led left
int l12 = 12; // red led left

//buzzer pin
const int buzzerPin = 13;

void setup() {
  Serial.begin(9600);
  
  // Initialize trigger pins as OUTPUT
  pinMode(trigPin1, OUTPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(trigPin3, OUTPUT);
  pinMode(trigPin4, OUTPUT);
  pinMode(trigPin5, OUTPUT);
  pinMode(trigPin6, OUTPUT);  

  // Initialize echo pins as INPUT
  pinMode(echoPin1, INPUT);
  pinMode(echoPin2, INPUT);
  pinMode(echoPin3, INPUT);
  pinMode(echoPin4, INPUT);
  pinMode(echoPin5, INPUT);
  pinMode(echoPin6, INPUT);

  //initialize led pins
  pinMode(l1, OUTPUT);
  pinMode(l2, OUTPUT);
  pinMode(l3, OUTPUT);
  pinMode(l4, OUTPUT);
  pinMode(l5, OUTPUT);
  pinMode(l6, OUTPUT);
  pinMode(l7, OUTPUT);
  pinMode(l8, OUTPUT);
  pinMode(l9, OUTPUT);
  pinMode(l10, OUTPUT);
  pinMode(l11, OUTPUT);
  pinMode(l12, OUTPUT);
  

//initialize buzzer
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // Measure distance using the first ultrasonic sensor
  long duration1, distance1;
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  duration1 = pulseIn(echoPin1, HIGH);
  distance1 = duration1 * 0.034 / 2;

  // Measure distance using the second ultrasonic sensor
  long duration2, distance2;
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  duration2 = pulseIn(echoPin2, HIGH);
  distance2 = duration2 * 0.034 / 2;

  // Measure distance using the third ultrasonic sensor
  long duration3, distance3;
  digitalWrite(trigPin3, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin3, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin3, LOW);
  duration3 = pulseIn(echoPin3, HIGH);
  distance3 = duration3 * 0.034 / 2;

  // Measure distance using the fourth ultrasonic sensor
  long duration4, distance4;
  digitalWrite(trigPin4, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin4, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin4, LOW);
  duration4 = pulseIn(echoPin4, HIGH);
  distance4 = duration4 * 0.034 / 2;


  long duration5, distance5;
  digitalWrite(trigPin5, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin5, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin5, LOW);
  duration5 = pulseIn(echoPin5, HIGH);
  distance5 = duration5 * 0.034 / 2;

  long duration6, distance6;
  digitalWrite(trigPin6, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin6, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin6, LOW);
  duration6 = pulseIn(echoPin6, HIGH);
  distance6 = duration4 * 0.034 / 2;



  // Print the distances to the Serial Monitor
  Serial.print("Distance 1: ");
  Serial.print(distance1);
  Serial.print(" cm\t");
  Serial.print("Distance 2: ");
  Serial.print(distance2);
  Serial.print(" cm\t");
  Serial.print("Distance 3: ");
  Serial.print(distance3);
  Serial.println(" cm");
  Serial.print("distance 4 : ");
  Serial.print(distance4);
  Serial.println(" cm");
  Serial.print(distance5);
  Serial.println(" cm");
  Serial.print(distance6);
  Serial.println(" cm");

  if (distance1 < 300 && distance1 >50 )
  {
  digitalWrite(l1, HIGH);
  digitalWrite(l2, LOW);
  digitalWrite(l3, LOW);
  digitalWrite(l4, LOW);
  digitalWrite(l5, LOW);
  digitalWrite(l6, LOW);
  digitalWrite(l6, LOW);
  digitalWrite(l7, LOW);
  digitalWrite(buzzerPin, LOW);
  delay(10);
  }
   else
 {
  digitalWrite(l1, LOW);
  digitalWrite(l2, LOW);
  digitalWrite(l3, LOW);
  digitalWrite(l4, LOW);
  digitalWrite(l5, LOW);
  digitalWrite(l6, LOW);
  digitalWrite(l7, LOW);
  digitalWrite(l8, LOW);
  digitalWrite(buzzerPin, LOW);
  delay(10);
 }
 
  if (distance2 < 300 && distance2 >50 )
  {
  digitalWrite(l1, LOW);
  digitalWrite(l2, LOW);
  digitalWrite(l3, HIGH);
  digitalWrite(l4, LOW);
  digitalWrite(l5, LOW);
  digitalWrite(l6, LOW);
  digitalWrite(l7, LOW);
  digitalWrite(l8, LOW);
  digitalWrite(buzzerPin, LOW);
  delay(10);
  }
  else
 {
  digitalWrite(l1, LOW);
  digitalWrite(l2, LOW);
  digitalWrite(l3, LOW);
  digitalWrite(l4, LOW);
  digitalWrite(l5, LOW);
  digitalWrite(l6, LOW);
  digitalWrite(l7, LOW);
  digitalWrite(l8, LOW);
  digitalWrite(buzzerPin, LOW);
  delay(10);
 }
   if (distance3 < 300 && distance3 >50 )
  {
  digitalWrite(l1, LOW);
  digitalWrite(l2, LOW);
  digitalWrite(l3, LOW);
  digitalWrite(l4, LOW);
  digitalWrite(l5, HIGH);
  digitalWrite(l6, LOW);
  digitalWrite(l7, LOW);
  digitalWrite(l8, LOW);
  digitalWrite(buzzerPin, LOW);
  delay(10);
  }
  else
 {
  digitalWrite(l1, LOW);
  digitalWrite(l2, LOW);
  digitalWrite(l3, LOW);
  digitalWrite(l4, LOW);
  digitalWrite(l5, LOW);
  digitalWrite(l6, LOW);
  digitalWrite(l7, LOW);
  digitalWrite(l8, LOW);
  digitalWrite(buzzerPin, LOW);
  delay(10);
 } 

  if (distance4 < 300 && distance4 >50 )
  {
  digitalWrite(l1, LOW);
  digitalWrite(l2, LOW);
  digitalWrite(l3, LOW);
  digitalWrite(l4, LOW);
  digitalWrite(l5, LOW);
  digitalWrite(l6, LOW);
  digitalWrite(l7, HIGH);
  digitalWrite(l8, LOW);
  digitalWrite(buzzerPin, LOW);
  delay(10);
  }
  else
 {
  digitalWrite(l1, LOW);
  digitalWrite(l2, LOW);
  digitalWrite(l3, LOW);
  digitalWrite(l4, LOW);
  digitalWrite(l5, LOW);
  digitalWrite(l6, LOW);
  digitalWrite(l7, LOW);
  digitalWrite(l8, LOW);
  digitalWrite(buzzerPin, LOW);
  delay(10);
 } 


  if (distance1 < 50 )
  {
  digitalWrite(l1, LOW);
  digitalWrite(l2, HIGH);
  digitalWrite(l3, LOW);
  digitalWrite(l4, LOW);
  digitalWrite(l5, LOW);
  digitalWrite(l6, LOW);
  digitalWrite(l7, LOW);
  digitalWrite(l8, LOW);
  digitalWrite(buzzerPin, HIGH);
  delay(10);
  }
 else
 {
  digitalWrite(l1, LOW);
  digitalWrite(l2, LOW);
  digitalWrite(l3, LOW);
  digitalWrite(l4, LOW);
  digitalWrite(l5, LOW);
  digitalWrite(l6, LOW);
  digitalWrite(l7, LOW);
  digitalWrite(l8, LOW);
  digitalWrite(buzzerPin, LOW);
  delay(10);
 }
 
  if (distance2 < 50 )
  {
  digitalWrite(l1, LOW);
  digitalWrite(l2, LOW);
  digitalWrite(l3, LOW);
  digitalWrite(l4, HIGH);
  digitalWrite(l5, LOW);
  digitalWrite(l6, LOW);
  digitalWrite(l7, LOW);
  digitalWrite(l8, LOW);
  digitalWrite(buzzerPin, HIGH);
  delay(10);
  }
   else
 {
  digitalWrite(l1, LOW);
  digitalWrite(l2, LOW);
  digitalWrite(l3, LOW);
  digitalWrite(l4, LOW);
  digitalWrite(l5, LOW);
  digitalWrite(l6, LOW);
  digitalWrite(l7, LOW);
  digitalWrite(l8, LOW);
  digitalWrite(buzzerPin, LOW);
  delay(10);
 }
   if (distance3 < 50 )
  {
  digitalWrite(l1, LOW);
  digitalWrite(l2, LOW);
  digitalWrite(l3, LOW);
  digitalWrite(l4, LOW);
  digitalWrite(l5, LOW);
  digitalWrite(l6, HIGH);
  digitalWrite(l7, LOW);
  digitalWrite(l8, LOW);
  digitalWrite(buzzerPin, HIGH);
  delay(10);
  }
  else
  {
  digitalWrite(l1, LOW);
  digitalWrite(l2, LOW);
  digitalWrite(l3, LOW);
  digitalWrite(l4, LOW);
  digitalWrite(l5, LOW);
  digitalWrite(l6, LOW);
  digitalWrite(l7, LOW);
  digitalWrite(l8, LOW);
  digitalWrite(buzzerPin, LOW);
  delay(10);
  }
  if (distance4 < 50 )
  {
  digitalWrite(l1, LOW);
  digitalWrite(l2, LOW);
  digitalWrite(l3, LOW);
  digitalWrite(l4, LOW);
  digitalWrite(l5, LOW);
  digitalWrite(l6, LOW);
  digitalWrite(l7, LOW);
  digitalWrite(l8, HIGH);
  digitalWrite(buzzerPin, HIGH);
  delay(10);
  }
  else
  {
  digitalWrite(l1, LOW);
  digitalWrite(l2, LOW);
  digitalWrite(l3, LOW);
  digitalWrite(l4, LOW);
  digitalWrite(l5, LOW);
  digitalWrite(l6, LOW);
  digitalWrite(l7, LOW);
  digitalWrite(l8, LOW);
  digitalWrite(buzzerPin, LOW);
  delay(10);
  }

  if (distance4 < 50 )
  {
  digitalWrite(l1, LOW);
  digitalWrite(l2, LOW);
  digitalWrite(l3, LOW);
  digitalWrite(l4, LOW);
  digitalWrite(l5, LOW);
  digitalWrite(l6, LOW);
  digitalWrite(l7, LOW);
  digitalWrite(l8, HIGH);
  digitalWrite(buzzerPin, HIGH);
  delay(10);
  }
  else
  {
  digitalWrite(l1, LOW);
  digitalWrite(l2, LOW);
  digitalWrite(l3, LOW);
  digitalWrite(l4, LOW);
  digitalWrite(l5, LOW);
  digitalWrite(l6, LOW);
  digitalWrite(l7, LOW);
  digitalWrite(l8, LOW);
  digitalWrite(buzzerPin, LOW);
  delay(10);
  }

  if (distance5 > 300 )
  {
  digitalWrite(l1, LOW);
  digitalWrite(l2, LOW);
  digitalWrite(l3, LOW);
  digitalWrite(l4, LOW);
  digitalWrite(l5, LOW);
  digitalWrite(l6, LOW);
  digitalWrite(l7, LOW);
  digitalWrite(l8, LOW);
  digitalWrite(l9, LOW);
  digitalWrite(l10, LOW);
  digitalWrite(l11, LOW);
  digitalWrite(l12, LOW);
  digitalWrite(buzzerPin, LOW);
  delay(10);
  }
  else
  {
  digitalWrite(l1, LOW);
  digitalWrite(l2, LOW);
  digitalWrite(l3, LOW);
  digitalWrite(l4, LOW);
  digitalWrite(l5, LOW);
  digitalWrite(l6, LOW);
  digitalWrite(l7, LOW);
  digitalWrite(l8, LOW);
  digitalWrite(l9, LOW);
  digitalWrite(l10, LOW);
  digitalWrite(l11, LOW);
  digitalWrite(l12, LOW);
  digitalWrite(buzzerPin, LOW);
  delay(10);
  }

  if (distance6 > 300 )
  {
  digitalWrite(l1, LOW);
  digitalWrite(l2, LOW);
  digitalWrite(l3, LOW);
  digitalWrite(l4, LOW);
  digitalWrite(l5, LOW);
  digitalWrite(l6, LOW);
  digitalWrite(l7, LOW);
  digitalWrite(l8, LOW);
  digitalWrite(l9, LOW);
  digitalWrite(l10, LOW);
  digitalWrite(l11, LOW);
  digitalWrite(l12, LOW);
  digitalWrite(buzzerPin, LOW);
  delay(10);
  }
  else
  {
  digitalWrite(l1, LOW);
  digitalWrite(l2, LOW);
  digitalWrite(l3, LOW);
  digitalWrite(l4, LOW);
  digitalWrite(l5, LOW);
  digitalWrite(l6, LOW);
  digitalWrite(l7, LOW);
  digitalWrite(l8, LOW);
  digitalWrite(l9, LOW);
  digitalWrite(l10, LOW);
  digitalWrite(l11, LOW);
  digitalWrite(l12, LOW);
  digitalWrite(buzzerPin, LOW);
  delay(10);
  }

if (distance5 >100 && distance5<300 )
  {
  digitalWrite(l1, LOW);
  digitalWrite(l2, LOW);
  digitalWrite(l3, LOW);
  digitalWrite(l4, LOW);
  digitalWrite(l5, LOW);
  digitalWrite(l6, LOW);
  digitalWrite(l7, LOW);
  digitalWrite(l8, LOW);
  digitalWrite(l9, HIGH);
  digitalWrite(l10, LOW);
  digitalWrite(l11, LOW);
  digitalWrite(l12, LOW);
  digitalWrite(buzzerPin, LOW);
  delay(10);
  }
  else
  {
  digitalWrite(l1, LOW);
  digitalWrite(l2, LOW);
  digitalWrite(l3, LOW);
  digitalWrite(l4, LOW);
  digitalWrite(l5, LOW);
  digitalWrite(l6, LOW);
  digitalWrite(l7, LOW);
  digitalWrite(l8, LOW);
  digitalWrite(l9, LOW);
  digitalWrite(l10, LOW);
  digitalWrite(l11, LOW);
  digitalWrite(l12, LOW);
  digitalWrite(buzzerPin, LOW);
  delay(10);
  }

  if (distance6 >100 && distance6<300 )
  {
  digitalWrite(l1, LOW);
  digitalWrite(l2, LOW);
  digitalWrite(l3, LOW);
  digitalWrite(l4, LOW);
  digitalWrite(l5, LOW);
  digitalWrite(l6, LOW);
  digitalWrite(l7, LOW);
  digitalWrite(l8, LOW);
  digitalWrite(l9, LOW);
  digitalWrite(l10, LOW);
  digitalWrite(l11, HIGH);
  digitalWrite(l12, LOW);
  digitalWrite(buzzerPin, LOW);
  delay(10);
  }
  else
  {
  digitalWrite(l1, LOW);
  digitalWrite(l2, LOW);
  digitalWrite(l3, LOW);
  digitalWrite(l4, LOW);
  digitalWrite(l5, LOW);
  digitalWrite(l6, LOW);
  digitalWrite(l7, LOW);
  digitalWrite(l8, LOW);
  digitalWrite(l9, LOW);
  digitalWrite(l10, LOW);
  digitalWrite(l11, LOW);
  digitalWrite(l12, LOW);
  digitalWrite(buzzerPin, LOW);
  delay(10);
  }

  if (distance5<100)
  {
  digitalWrite(l1, LOW);
  digitalWrite(l2, LOW);
  digitalWrite(l3, LOW);
  digitalWrite(l4, LOW);
  digitalWrite(l5, LOW);
  digitalWrite(l6, LOW);
  digitalWrite(l7, LOW);
  digitalWrite(l8, LOW);
  digitalWrite(l9, LOW);
  digitalWrite(l10, HIGH);
  digitalWrite(l11, LOW);
  digitalWrite(l12, LOW);
  digitalWrite(buzzerPin, HIGH);
  delay(10);
  }
  else
  {
  digitalWrite(l1, LOW);
  digitalWrite(l2, LOW);
  digitalWrite(l3, LOW);
  digitalWrite(l4, LOW);
  digitalWrite(l5, LOW);
  digitalWrite(l6, LOW);
  digitalWrite(l7, LOW);
  digitalWrite(l8, LOW);
  digitalWrite(l9, LOW);
  digitalWrite(l10, LOW);
  digitalWrite(l11, LOW);
  digitalWrite(l12, LOW);
  digitalWrite(buzzerPin, LOW);
  delay(10);
  }

if (distance6 <100)
  {
  digitalWrite(l1, LOW);
  digitalWrite(l2, LOW);
  digitalWrite(l3, LOW);
  digitalWrite(l4, LOW);
  digitalWrite(l5, LOW);
  digitalWrite(l6, LOW);
  digitalWrite(l7, LOW);
  digitalWrite(l8, LOW);
  digitalWrite(l9, LOW);
  digitalWrite(l10, LOW); 
  digitalWrite(l11, LOW);
  digitalWrite(l12, HIGH);
  digitalWrite(buzzerPin, HIGH);
  delay(10);
  }
  else
  {
  digitalWrite(l1, LOW);
  digitalWrite(l2, LOW);
  digitalWrite(l3, LOW);
  digitalWrite(l4, LOW);
  digitalWrite(l5, LOW);
  digitalWrite(l6, LOW);
  digitalWrite(l7, LOW);
  digitalWrite(l8, LOW);
  digitalWrite(l9, LOW);
  digitalWrite(l10, LOW);
  digitalWrite(l11, LOW);
  digitalWrite(l12, LOW);
  digitalWrite(buzzerPin, LOW);
  delay(10);
  }  
  


}