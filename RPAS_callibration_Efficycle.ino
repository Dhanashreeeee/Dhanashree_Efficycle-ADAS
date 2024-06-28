#include <Wire.h>
#include <Servo.h>

#define MPU6050_ADDRESS 0x68
#define MPU6050_REG_ACCEL_XOUT_H 0x3B
#define MPU6050_REG_PWR_MGMT_1 0x6B
#define MPU6050_REG_GYRO_CONFIG 0x1B
#define SERVO_PIN 11 // Change this to your servo pin

Servo steeringServo;

int16_t gyroX, gyroY, gyroZ;
float lastAngle = 0;

void setup() {
  Wire.begin();
  Serial.begin(9600);

  Wire.beginTransmission(MPU6050_ADDRESS);
  Wire.write(MPU6050_REG_PWR_MGMT_1);
  Wire.write(0);
  Wire.endTransmission(true);

  Wire.beginTransmission(MPU6050_ADDRESS);
  Wire.write(MPU6050_REG_GYRO_CONFIG);
  Wire.write(0x08);
  Wire.endTransmission(true);

  steeringServo.attach(SERVO_PIN);
}

void loop() {
  Wire.beginTransmission(MPU6050_ADDRESS);
  Wire.write(MPU6050_REG_ACCEL_XOUT_H);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU6050_ADDRESS, 6, true);
  gyroX = Wire.read() << 8 | Wire.read();
  gyroY = Wire.read() << 8 | Wire.read();
  gyroZ = Wire.read() << 8 | Wire.read();

  // Calculate roll angle
  float rollAngle = atan2(gyroY, sqrt(pow(gyroZ, 2) + pow(gyroX, 2))) * 180 / PI;

  // Smooth the movement
  float smoothedAngle = 0.9 * lastAngle + 0.1 * rollAngle;

  // Map the angle to servo position (adjust these values based on your setup)
  int servoPos = map(smoothedAngle, -90, 90, 0, 180);
  servoPos = constrain(servoPos, 0, 180);

  // Set the servo position
  steeringServo.write(servoPos);

  // Print roll angle to Serial monitor
  Serial.println(smoothedAngle);

  // Update last angle for smoothing
  lastAngle = smoothedAngle;

  // Delay for stability
  delay(10);
}