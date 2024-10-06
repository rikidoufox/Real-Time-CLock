#include "Arduino.h"

#include "main.hpp"

#include "lib_util.h"

#include "UTFR_PIN_DRIVER_RC.hpp"

#include "UTFR_WATCHDOG.hpp"

#include "UTFR_CAN_TEENSY.hpp"

#include "UTFR_CAN_TEENSY.tpp"

#include "UTFR_CAN_TEENSY_TYPES.hpp"

#include "UTFR_CAN_RC_PRIMARY.hpp"

#include "TEMP_CONVERSION.hpp"

#include "UTFR_CAN_RC_SECONDARY.hpp"

#include "UTFR_REGEN.hpp"

#include "TimeLib.h"


bool runAlready = false;

int dayval;

int monthval;

int yearval;

int minuteval;

int hourval;

int secondval;


void setup() {

  Serial.begin(9600);

  pinMode(13, INPUT_PULLDOWN); //Digital input pin.

  pinMode(6, OUTPUT); //Digital output pin

  digitalWrite(6, HIGH); //Always driven high, so when switch closes, pin 13 will read HIGH.


  // setTime(14, 0, 0, 9, 7, 2024); // hr,min,sec,day,month,year

  delay(1000);

  Serial.print("Initial Time: ");

  Serial.println(millis()); //The time in milliseconds since the program began running.

}

void loop() {

  if(digitalRead(13)==1 && runAlready == false){//runAlready is checked to ensure that we only enter this if statement once.

    Serial.print("Hello World!");

    runAlready = true;//Prevents re-entry into the if statement

    dayval = day(); //Stores the day at which the event occurred in dayval

    monthval = month(); //Stores the month when the event occurred in monthval

    yearval = year();

    minuteval = minute();

    hourval = hour();

    secondval = second();


    //Prints out the time recorded

    Serial.print("Event logged: ");

    Serial.print(dayval);

    Serial.print("/");

    Serial.print(monthval);

    Serial.print("/");

    Serial.print(yearval);

    Serial.print("-");

    Serial.print(hourval);

    Serial.print(":");

    Serial.print(minuteval); 

    Serial.print(":");

    Serial.println(secondval); 

    Serial.print(millis());

    delay(1000);

  }

}
