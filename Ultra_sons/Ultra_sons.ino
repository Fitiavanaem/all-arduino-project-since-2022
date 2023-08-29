#define echoPin 11
#define trigPin 12
long duration, distance;
//La durée utilisée pour calculer la distance


void setup() {
 Serial.begin(115200);
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
 pinMode(2, OUTPUT);
 digitalWrite(2, LOW);
 pinMode(3, OUTPUT);
 digitalWrite(3, HIGH);
 
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(10);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);
  duration=pulseIn(echoPin, HIGH);

  //Calculer la distance (en cm) en 
  //fonction de la vitesse du son 

  distance=duration/58.2;
  Serial.println(distance);
  delay(50);

  if(distance > 600){
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, HIGH);
  }
   else if(distance < 1){
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  digitalWrite(4, LOW);
  } 
  else {
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  } 
  delay(300); 
}
