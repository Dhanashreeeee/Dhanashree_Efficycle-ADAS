const int sensorPin = 2;  // Pin connected to the LM393 output
float speed; // Distance covered per pulse (change according to your sensor)
volatile unsigned int pulseCount = 1;
unsigned long lastTime;
bool vehicleDetected = false;  // Flag to track vehicle detection
float speedlimit=25;
int buzzer = 9;

void setup() {
  Serial.begin(9600);
  pinMode(sensorPin, INPUT);
  pinMode(buzzer,OUTPUT);
  attachInterrupt(digitalPinToInterrupt(sensorPin), pulseCounter, FALLING);
 
  }

void pulseCounter() {
  pulseCount++;
  vehicleDetected = true;  // Set the flag when a vehicle is detected
}

void loop() {
  // Calculate speed every second
  if (millis() - lastTime >= 1000) {
    detachInterrupt(digitalPinToInterrupt(sensorPin));  // Disable interrupts while calculating speed
    float timeElapsed = millis() - lastTime;

    if (vehicleDetected) {
      speed = ((pulseCount * 1.57) / (timeElapsed / 1000.0 ) * 3.6/2.09);  // Convert time to seconds
     
      Serial.println(speed);
     
      vehicleDetected = false; 
      // Reset the vehicle detection flag
    } else {
      Serial.println("0");
        // No vehicle detected
    }
    
    pulseCount = 0;
    lastTime = millis();
    attachInterrupt(digitalPinToInterrupt(sensorPin), pulseCounter, FALLING); 
  } // Re-enable interrupts
  if(speed>=speedlimit)
{
  digitalWrite(buzzer,HIGH);   
}  
else
{
  digitalWrite(buzzer,LOW);
}
}