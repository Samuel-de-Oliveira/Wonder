const int buzzer = 3;

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
