const int buzzer = 3; // If you want to use a different port you need to change this const number
int noise = 1000;

void setup() {
	pinMode(buzzer, OUTPUT);
	Serial.begin(9600);
}

void loop() {
	tone(buzzer, noise, 250);
	Serial.println("The buzzer did a noise");
	delay(250);
	noTone(buzzer);
	noise = noise - 100;
	if (noise <= 0) { noise = 1000; }
	delay(1000);
}
