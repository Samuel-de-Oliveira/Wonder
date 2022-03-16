/*
 * --*--* Wonder project *--*--
 * 
 * This project is based in a outher one made by studants
 * of Federal Institute of Mato Grosso. This project diferent
 * of outher is Open Source, so it's created to make a experiment
 * with studants to know the matters of Open Source for people
 * with disabilities.
 *
 * Author: Samuel de Oliveira (Github: Samuel-de-Oliveira)
 * Contribuitors: None
 *
 */

#include <HCSR04.h>

// Here is the pins scheme, you can change it if you want.
const byte triggerPin   = 3;
const byte echoPin      = 4;
const byte vibrationPin = 10;
const byte buzzerPin    = 9;

// Here is the values of fisiology of person (Required to change if you want a good experience).
const byte Height = 180; // if you digit a value lower than 130cm, the code couldn't work.

UltraSonicDistanceSensor distanceSensor(triggerPin, echoPin);

void setup() {
	pinMode(buzzerPin, OUTPUT);
	pinMode(vibrationPin, OUTPUT);
	Serial.begin(9600);
	Serial.println("The monitor serial is only to see if the components is working correctly");
	Serial.println("else this don't have anything to see here.");
	delay(1000);
}

void loop() {
	float distance = distanceSensor.measureDistanceCm();
	Serial.print(distance);
	Serial.println("cm");

	if ( distance == -1 or Height <= 130 ) {
		
		// Error message, will be showed if something is not working in code or circuit.
		Serial.println("Oh no! Something is not working well");
		Serial.println("Please check the software's repository in Github for support of this error:");
		Serial.println("www.github.com/Samuel-de-Oliveira/Wonder#fix-errors");

		for (byte i = 0; i < 3; i++) {

			tone(buzzerPin, 1000, 300);
			delay(100);
			noTone(buzzerPin);
			delay(250);
		}
		delay(250);

	} else if ( Height - 135 < distance and distance <= Height - 100 ) {
		
		// Slow beep.
		Serial.println("I found something far me!");
		tone(buzzerPin, 1100, 300);
		digitalWrite(vibrationPin, HIGH);
		delay(300);
		noTone(buzzerPin);
		digitalWrite(vibrationPin, LOW);
		delay(500);

	} else if ( distance <= Height - 135 ) {
		
		// Fast beep.
		Serial.println("I found something near me!");
		tone(buzzerPin, 1100, 300);
		digitalWrite(vibrationPin, HIGH);
		delay(200);
		noTone(buzzerPin);
		digitalWrite(vibrationPin, LOW);
		delay(200);
	}
}
