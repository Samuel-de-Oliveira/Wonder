/*
 * --*--* Bengala_upgraded *--*--
 * 
 * This project is based in a outher one made by studants
 * of Federal Institute of Mato Grosso.
 *
 * Author: Samuel de Oliveira (Github: Samuel-de-Oliveira)
 * Contribuitors: None
 *
 */

#include <HCSR04.h>

// Here is the pins scheme, you can change it if you want :)
const byte triggerPin   = 3;
const byte echoPin      = 4;
const byte vibrationPin = 10;
const byte buzzerPin    = 9;

UltraSonicDistanceSensor distanceSensor(triggerPin, echoPin);

void setup() {
	pinMode(buzzerPin, OUTPUT);
	pinMode(vibrationPin, OUTPUT);
	Serial.begin(9600);
}

void loop() {
	    float distance = distanceSensor.measureDistanceCm();

	    if (40 < distance and distance <= 65) {

		    Serial.println("I find something far me!");
		    tone(buzzerPin, 1100, 300);
		    digitalWrite(vibrationPin, HIGH);
		    delay(300);
		    noTone(buzzerPin);
		    digitalWrite(vibrationPin, LOW);
		    delay(500);
	    } else if (distance <= 40) {

		    Serial.println("I find something near me!");
		    tone(buzzerPin, 1100, 300);
		    digitalWrite(vibrationPin, HIGH);
		    delay(200);
		    noTone(buzzerPin);
		    digitalWrite(vibrationPin, LOW);
		    delay(200);
	    } 
}
