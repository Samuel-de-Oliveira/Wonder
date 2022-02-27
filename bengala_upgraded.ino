#include <HCSR04.h>

// Initialize sensor that uses digital pins 13 and 12.
const byte triggerPin = 3;
const byte echoPin = 4;
UltraSonicDistanceSensor distanceSensor(triggerPin, echoPin);

void setup () {
	    Serial.begin(9600);  // We initialize serial connection so that we could print values from sensor.
	    
}

void loop () {
	    // Every 500 miliseconds, do a measurement using the sensor and print the distance in centimeters.
	    float distance = distanceSensor.measureDistanceCm();
	        Serial.println(distance);
		    delay(500);
		    
}
