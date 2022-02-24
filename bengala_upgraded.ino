const int buzzer = 3; // If you want to use a different port you need to change this const number
int noise = 1000;

void setup() {
	pinMode(buzzer, OUTPUT);
	Serial.begin(9600);
}

void loop() {
	tone(buzzer, noise, 250);
	Serial.print("Frequance: ");
	Serial.print(noise);
	Serial.println("Hz");
	delay(250);

	noTone(buzzer);
	noise = noise - 50;
	if (noise <= 0) { noise = 1000; }
	delay(750);
}
