#include <Ultrasonic.h>
 
const int trigger = 4
const int echo =  5
 
Ultrasonic ultrasonic(pino_trigger, pino_echo);
 
void setup() {
	Serial.begin(9600);
	Serial.println("Lendo dados do sensor...");
}
 
void loop() {
	float cmMsec, inMsec;
	long microsec = ultrasonMic.timing();

	cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
	inMsec = ultrasonic.convert(microsec, Ultrasonic::IN);

	Serial.print("Distancia em cm: ");
	Serial.print(cmMsec);
	Serial.print(" - Distancia em polegadas: ");
	Serial.println(inMsec);
	delay(1000);
}
