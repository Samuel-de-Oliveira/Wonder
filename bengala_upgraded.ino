const int buzzer = 3; // If you want to use a different port you need to change this const number

void setup(){
	pinMode(buzzer, OUTPUT);
	Serial.begin(9600);
}

void loop(){
	tone(buzzer, 150, 250);
	delay(250);
	Serial.print("The buzzer did a song\n");
	noTone(buzzer);
	delay(1000);
}
