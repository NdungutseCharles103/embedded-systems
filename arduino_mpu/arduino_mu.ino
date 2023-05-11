#include <Wire.h>
#include <MPU6050.h>

MPU6050 mpu;
int amberLED=6;
int blueLED=10;
int greenLED=11;
void setup(){
 pinMode(amberLED, OUTPUT);
 pinMode(blueLED, OUTPUT);
 pinMode(greenLED, OUTPUT);

 Serial.begin(115200);
 Serial.println("Initialize MPU6050");
 while(!mpu.begin(MPU6050_SCALE_2000DPS, MPU6050_RANGE_2G)){
 Serial.println("Could not find a valid MPU6050 sensor, check wiring!");
 delay(500);
 }
}
void loop(){
 // Read normalized values
 Vector normAccel = mpu.readNormalizeAccel();
 // Calculate Pitch & Roll
 int pitch = -(atan2(normAccel.XAxis, sqrt(normAccel.YAxis*normAccel.YAxis + normAccel.ZAxis*normAccel.ZAxis))*180.0)/M_PI;
 int roll = (atan2(normAccel.YAxis, normAccel.ZAxis)*180.0)/M_PI;
 // Output
 Serial.print(" Pitch = ");
 Serial.print(pitch);
 Serial.print(" Roll = ");
 Serial.print(roll);

 Serial.println();
 Serial.println("**********************************************");
/*
 * PITCH DETECTION INDICATION
 */
 if(pitch<-6 || pitch>-1){
 Serial.println("Pitch detected!");
 digitalWrite(blueLED, HIGH);
 }else{
 digitalWrite(blueLED, LOW);
 }
 /*
 * ROLL DETECTION INDICATION
 */
 if(roll<0 || roll>2){
 Serial.println("Roll detected!");
 digitalWrite(amberLED, HIGH);
 }else{
 digitalWrite(amberLED, LOW);
 }

/*
 * STABILITY INDICATION
 */
 if((pitch>-6 && pitch<-1) && (roll>0 && roll<2) ){
 Serial.println("No Pitch and No Roll");
 digitalWrite(greenLED, HIGH);
 }else{
 digitalWrite(greenLED, LOW);
 }
 delay(10);
}