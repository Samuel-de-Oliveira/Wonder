/*
 * --*--* Bengala_upgraded *--*--
 * 
 * Author: Samuel de Oliveira (Github: Samuel-de-Oliveira)
 * Contribuitors: None
 *
 */

#include <HCSR04.h>

// Here is the pins scheme, you can change it if you want :)
const byte triggerPin = 3;
const byte echoPin    = 4;
const byte buzzerPin  = 9;

UltraSonicDistanceSensor distanceSensor(triggerPin, echoPin);

void setup() {
	pinMode(buzzerPin, OUTPUT);
	Serial.begin(9600);
}

void loop () {
	    float distance = distanceSensor.measureDistanceCm();

	    if (25 < distance and distance <= 50) {

		    tone(buzzerPin, 800, 300);
		    delay(250);
		    noTone(buzzerPin);
		    delay(500);
	    } else if (distance <= 25) {

		    tone(buzzerPin, 800, 300);
		    delay(250);
		    noTone(buzzerPin);
		    delay(250);
	    } 
}
