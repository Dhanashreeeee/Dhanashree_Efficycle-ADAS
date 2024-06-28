const int ldr_pin =8;
const int led_pin =13;
int fsrAnalogPin = 0;
int buzzer=9;
int ledbrightness;
int buzzerdelay;
int fsrReading;


void setup(){
  pinMode(ldr_pin, INPUT);
  pinMode(led_pin, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(fsrAnalogPin, INPUT);
  Serial.begin(9600);

}
void loop(){
 if (digitalRead(ldr_pin)==0)
 {
 ledbrightness=map(fsrReading,0,200,0,55);
 (tone(buzzer, 1000));
 }
 else
 {
  (digitalWrite(led_pin, LOW));
  (noTone(buzzer));
  delay(100);
 }
}const int ldr_pin =8;
const int led_pin =13;
int fsrAnalogPin = 0;
int buzzer=9;
int ledbrightness;
int buzzerdelay;
int fsrReading;


void setup(){
  pinMode(ldr_pin, INPUT);
  pinMode(led_pin, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(fsrAnalogPin, INPUT);
  Serial.begin(9600);

}
void loop(){
 if (digitalRead(ldr_pin)==0)
 {
 ledbrightness=map(fsrReading,0,200,0,55);
 (tone(buzzer, 1000));
 }
 else
 {
  (digitalWrite(led_pin, LOW));
  (noTone(buzzer));
  delay(100);
 }
}