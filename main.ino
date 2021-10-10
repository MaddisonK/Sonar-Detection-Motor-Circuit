int trigPin = 13;
int echoPin = 12;
int buzzer = 10;
int input1 = 2;
int input2 = 3;
int enable = 5;

void process(long distance);
void go();
void stop();
void reverse();

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(input1, OUTPUT);
  pinMode(input2, OUTPUT);
  pinMode(enable, OUTPUT);
  //pinMode(buzzer, OUTPUT); breaks it for no reason, TA unable to figure out why
}

void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW);  
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  process(distance);
  Serial.print(distance);
  Serial.println(" cm");

	
}

void process(long distance) {
  if (distance >= 200 || distance <= 0){
    Serial.println("Out of range");
    reverse();
  }
  else if (distance <= 15 && distance >= 10) { 
    stop();
  } else if (distance < 10){
    reverse();
  } else {
    go();
  }
}
  
  void go() {
    digitalWrite(input1, HIGH);
  	digitalWrite(input2, LOW);
  	digitalWrite(enable, HIGH);
    noTone(buzzer);
  }
  
  void stop() {
    digitalWrite(input1, LOW);
  	digitalWrite(input2, LOW);
  	digitalWrite(enable, HIGH);
    tone(buzzer, 2000);
  }
  
  void reverse() {
    digitalWrite(input1, LOW);
  	digitalWrite(input2, HIGH);
  	digitalWrite(enable, HIGH);
    tone(buzzer, 10000);
  }
 