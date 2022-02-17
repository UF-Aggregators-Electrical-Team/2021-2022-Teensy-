/*
 * VNH3SP30 motor driver library - demo for a single motor
 * 
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public 
 * License as published by the Free Software Foundation; either  
 * version 2.1 of the License, or (at your option) any later version.
 *   
 * Created 2 June 2019 Bart Mellink
 * Edited  14 Feb. 2022 Bradley Shelley
 */

// The Drivers for Display need to be fixed. I have miss-copied them but its simple fix.
// Provides same functionality as the VNH5019 just has some different current/voltage specs
#include <VNH3SP30.h>
#include <Wire.h>               // SCL pin 19, SDA pin 18
#include <Adafruit_GFX.h>      
#include <Adafruit_SSD1306.h>   

VNH3SP30 Motor1;    // define control object for 1 motor

// motor pins
#define M1_PWM 0    // pwm pin motor
#define M1_INA 1    // control pin INA
#define M1_INB 2    // control pin INB
#define M1_DIAG 3   // diagnose pins (combined DIAGA/ENA and DIAGB/ENB)
#define M1_CS 4    // current sense pin // Not Really Needed for our use case

Adafruit_SSD1306 display(128, 64, &Wire, -1, 1000000);  // 1MHz I2C clock

void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  delay(100);
  display.clearDisplay();
  display.display();
  Motor1.begin(M1_PWM, M1_INA, M1_INB, M1_DIAG, M1_CS);    // Motor 1 object connected through specified pins 
}

void loop() {
  display.setTextSize(1);
  display.setTextColor(1);
  display.setCursor(0,0);
  display.print("3/4 speed forward");
  display.display();

  Motor1.setSpeed(300); // motor 3/4-speed "forward"
  delay(2000); // wait for 2 seconds
  display.setCursor(0,8);
  display.print("Current="); 
  display.print(Motor1.motorCurrent());
  display.display();
  Serial.print("Current="); Serial.println(Motor1.motorCurrent());


  delay(500);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(1);
  display.setCursor(0,0);
  display.print("Motor stop (coast)");
  Serial.println("Motor stop (coast)");
  Motor1.setSpeed(0); // motor stop (coasting)
  delay(2000); // wait for 2 seconds
  display.setCursor(0,8);
  display.print("Current="); 
  display.print(Motor1.motorCurrent());
  delay(200);
  Serial.print("Current at stop="); Serial.println(Motor1.motorCurrent());
  display.display();
  delay(200);

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(1);
  display.setCursor(0,0);
  display.print("Half speed backward");
  Serial.println("Half speed backward");
  Motor1.setSpeed(-200); // motor half-speed "backward"
  display.display();

  delay(2000); // wait for 2 seconds
  
  display.setCursor(0,8);
  display.print("Current="); 
  display.print(Motor1.motorCurrent());
  delay(200);

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(1);
  display.setCursor(0,0);
  display.print("Motor stop (coast)");
  Serial.println("Motor stop (coast)");
  Motor1.setSpeed(0); // motor stop 
  delay(2000); // wait for 2 seconds
  display.setCursor(0,8);
  display.print("Current="); 
  display.print(Motor1.motorCurrent());
  delay(200);

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(1);
  display.setCursor(0,0);
  display.print("Full speed backward");
  Serial.println("Full speed backward");
  Motor1.setSpeed(-400); // motor full-speed "backward"
  delay(2000); // wait for 2 seconds
  display.setCursor(0,8);
  display.print("Current="); 
  display.print(Motor1.motorCurrent());
  Serial.print("Current="); Serial.println(Motor1.motorCurrent());
  delay(200);


  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(1);
  display.setCursor(0,0);
  display.print("Break at 3/4 power");
  Serial.println("Break at 3/4 power");
  Motor1.brake(300); // motor brake at 3/4 power
  delay(10);
  display.setCursor(0,8);
  display.print("Current during brake="); 
  display.print(Motor1.motorCurrent());
  Serial.print("Current during brake="); Serial.println(Motor1.motorCurrent());
  delay(4000); // wait for 4 seconds
  display.setCursor(0,8);
  display.print("Current after brake="); 
  display.print(Motor1.motorCurrent());
  Serial.print("Current after brake="); Serial.println(Motor1.motorCurrent());
  delay(200);

}
