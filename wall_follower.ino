#include <MeMCore.h>
#include <Arduino.h>
#include <Wire.h>
#include <SoftwareSerial.h>

MeRGBLed rgbled_7(7, 2);
MeRGBLed rgbled_1(1, 4);
MeUltrasonicSensor ultrasonic_3(3);
Me7SegmentDisplay seg7_4(4);
MeBuzzer buzzer;
MeDCMotor motor_9(9);
MeDCMotor motor_10(10);

void _delay(float seconds) {
  long endTime = millis() + seconds * 1000;
  while(millis() < endTime) _loop();
}

void setup() {
  rgbled_7.fillPixelsBak(0, 2, 1);
  rgbled_1.fillPixelsBak(0, 2, 1);

  rgbled_7.setColor(0,191,255,0);
  rgbled_7.show();

  rgbled_1.setColor(0,  170,255,0);
  rgbled_1.show();
  while(1) {

      seg7_4.display(float(ultrasonic_3.distanceCm()));

      buzzer.tone(random(300, 10000 +1), 0.1 * 1000);
      if(ultrasonic_3.distanceCm() < 15){

          motor_9.run(-1 * 50/100.0*255);
          motor_10.run(100/100.0*255);

      }else{
          if(ultrasonic_3.distanceCm() > 16){

              motor_9.run(-1 * 100/100.0*255);
              motor_10.run(50/100.0*255);

          }else{

              motor_9.run(-1 * 100/100.0*255);
              motor_10.run(100/100.0*255);

          }

      }

      _loop();
  }

}

void _loop() {
}

void loop() {
  _loop();
}
