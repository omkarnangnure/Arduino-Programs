 //Program to get values from MQ2 gas sensor and give interpretation according to proposed title
int yellowLed=8;           //Blue Led is connected to digital pin no.8
int redLed = 10;          //Red Led is connected to  digital pin no.10
int greenLed = 12;       //Green Led is connected to digital pin no. 12
int smokeA0 = A5;        //Analog pin is connected analog pin no.A5

int sensorThres1 = 440;   //First threshold value
int sensorThres2 = 800;    //Second threshold value

void setup() {
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(yellowLed, OUTPUT);
  pinMode(smokeA0, INPUT);
  Serial.begin(9600);
  Serial.println("Getting ready ..  checking the sensor....");
  Serial.println("Calculating values....");
}

void loop() {
  int analogSensor = analogRead(smokeA0);
   
  Serial.print("Value is: ");
  Serial.println(analogSensor);
  
  // Checks if it has reached the threshold value
   if (analogSensor < sensorThres1 )
  {
    digitalWrite(yellowLed, LOW);
    digitalWrite(greenLed, HIGH);
    digitalWrite(redLed, LOW);

    delay(100);
  }
  else if (analogSensor > sensorThres1 && analogSensor < sensorThres2)
  {
    digitalWrite(yellowLed, HIGH);
    digitalWrite(greenLed, LOW);
    digitalWrite(redLed, LOW);

    delay(100);
  }
  else if(analogSensor > sensorThres2)
  {
    digitalWrite(redLed, HIGH);
    digitalWrite(greenLed, LOW);
    digitalWrite(yellowLed, LOW);
   
    delay(100);
  }
}
