#include <HCSR04.h>

// Here is the Pins scheme, you can change it if you want :)
const byte triggerPin = 3;
const byte echoPin    = 4;
const byte buzzerPin  = 9;

UltraSonicDistanceSensor distanceSensor(triggerPin, echoPin);

void setup() {
	Serial.begin(9600);
}

void loop () {
	    float distance = distanceSensor.measureDistanceCm();
	    
	    if (distance <= 12) {
		    tone(buzzerPin, 523, 250);
		    delay(250);
		    noTone(buzzerPin);
		    delay(500);
	    }	    
}
