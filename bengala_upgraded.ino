/*
 * --*--* Bengala_upgraded *--*--
 * 
 * This project is based in a outher one made by studants
 * of Federal Institute of Mato Grosso. This project diferent
 * of outher is Open Source, so it's created to make a experiment
 * with studants to know the matters of Open Source for people
 * with disabilities
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

const byte Height = 80;

UltraSonicDistanceSensor distanceSensor(triggerPin, echoPin);

void setup() {
	pinMode(buzzerPin, OUTPUT);
	pinMode(vibrationPin, OUTPUT);
	Serial.begin(9600);
}

void loop() {
	float distance = distanceSensor.measureDistanceCm();
	Serial.println(distance);

	if (distance == -1) {

		Serial.println("The ultrasonic is inactive!");
		for (int i = 0; i < 3; i++) {

			tone(buzzerPin, 1000, 300);
			delay(100);
			noTone(buzzerPin);
			delay(250);
		}
		delay(250);
	} else if (Height - 35 < distance and distance <= Height) {

		Serial.println("I find something far me!");
		tone(buzzerPin, 1100, 300);
		digitalWrite(vibrationPin, HIGH);
		delay(300);
		noTone(buzzerPin);
		digitalWrite(vibrationPin, LOW);
		delay(500);
	} else if (distance <= Height - 35) {

		Serial.println("I find something near me!");
		tone(buzzerPin, 1100, 300);
		digitalWrite(vibrationPin, HIGH);
		delay(200);
		noTone(buzzerPin);
		digitalWrite(vibrationPin, LOW);
		delay(200);
	}
}
