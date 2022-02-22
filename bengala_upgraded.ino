const int buzzer = 7;

void setup(){
	pinMode(buzzer, OUTPUT);
	Serial.begin(9600);
}

void loop(){
	tone(buzzer, 150, 250);
	delay(250);
	untone(buzzer);
	delay(250);
}
