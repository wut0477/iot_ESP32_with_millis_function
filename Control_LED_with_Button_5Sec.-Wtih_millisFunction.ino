
// set pin number

const int buttonPin = 4;    //GPIO 4
const int ledPin = 16;       //GPIO 16


// Variable for storing the pushbutton pin

int buttonState = 0; 
int lastButtonState = 0;
unsigned long ledOnTime = 0;
const long ledDuration = 5000;
bool ledIsOn = false;


void setup(){
	Serial.begin(115200);
	pinMode(buttonPin, INPUT);
	pinMode(ledPin, OUTPUT);
}

void loop(){
	buttonState = digitalRead(buttonPin);
	Serial.println(buttonState);
	if (buttonState == HIGH && lastButtonState == LOW){
		digitalWrite(ledPin, HIGH);
		ledOnTime = millis();
		ledIsOn = true;
	}
	
	if (ledIsOn && ( millis() - ledOnTime >= ledDuration )) {
		digitalWrite(ledPin,LOW);
		ledIsOn = false;
	}

	lastButtonState = buttonState;
}



































