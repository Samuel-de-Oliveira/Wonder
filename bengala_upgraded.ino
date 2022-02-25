#include <Ultrasonic.h>
 
// Define pin nunbers here
const byte trigger = 3;
const byte echo = 4;
 
Ultrasonic ultrasonic(trigger, echo);
 
void setup() {
	Serial.begin(9600);
	Serial.println("Reading the data of sensor...");
}

void loop() {
	float cmMsec, inMsec;
	long microsec = ultrasonic.timing();
	cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
	inMsec = ultrasonic.convert(microsec, Ultrasonic::IN);

	Serial.print("Distancia em cm: ");
	Serial.print(cmMsec);
	Serial.print(" - Distancia em polegadas: ");
	Serial.println(inMsec);
	delay(1000);
}
