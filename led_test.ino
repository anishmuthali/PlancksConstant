int ledPin = 9;
int redPin = 5;
int bluePin = 2;
int brightness = 0;
boolean redDepressed = false;
boolean blueDepressed = false;

void setup() {
  pinMode(5, INPUT);
  Serial.begin(9600);
  Serial.println("start");
}

void loop() {
  analogWrite(ledPin, brightness);
  int redPress = digitalRead(redPin);
  if(redPress == HIGH && !redDepressed && brightness < 255){
    brightness += 1;
    redDepressed = true;
    Serial.println(brightness);
  }
  else if(redPress == LOW && redDepressed){
    redDepressed = false;
  }

  int bluePress = digitalRead(bluePin);
  if(bluePress == HIGH && !blueDepressed && brightness > 0){
    brightness -= 1;
    blueDepressed = true;
    Serial.println(brightness);
  }
  else if(bluePress == LOW && blueDepressed){
    blueDepressed = false;
  }
  
}
