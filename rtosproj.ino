

/* Arduino based multitasking with the following applications: (loops executing at differenct time periods)
1. Motors running in the main loop
2. PIR sensed LED Toggle ,headlight indicator when vehicle approaching
3. LDR based LED ON/OFF, headlights turn on when darkness is detected
*/

//Pin definition

int a;
const int ledPin = 9;
int ledState = LOW;             // ledState used to set the LED


int sensorPin = A0; // select the input pin for the LDR
int sensorValue = 0; // variable to store the value coming from the sensor
int LDRled = 3;


static int outputPin1=5;   // PINS FOR MOTOR
static int outputPin2=6;
static int outputPin3=10;
static int outputPin4=11;

void setup() {
  //Serial communication
  Serial.begin(9600);

  //Pin setup
 pinMode(ledPin,OUTPUT); //OUTPUT TO GLOW LED
  pinMode(7,INPUT);  //INPUT FROM PIR
  
 pinMode(LDRled, OUTPUT);
  
  pinMode(outputPin1, OUTPUT);  //Setting the dc motor pins as output to L293D
  pinMode(outputPin2, OUTPUT);
  pinMode(outputPin3, OUTPUT);
  pinMode(outputPin4, OUTPUT);
  
  
}

void loop() {
  
  //This loop is responsible for always rotating the motors and it follows the following logic chart:
  /*Input 1	Input 2	            Result
    0	          0	             Stop
    0	          1	             Anti Clockwise
    1	          0	             Clockwise
    1	          1	             Stop
*/
    digitalWrite(outputPin1, HIGH);
    digitalWrite(outputPin2, LOW);
    digitalWrite(outputPin3, HIGH);
    digitalWrite(outputPin4, LOW); 
    delay(20000);
}
  


void loop1(1000){
  //This task uses a PIR to sense a forthcoming vehicle and toggle the headlights
  //Send a HIGH pulse to the trigger pin
  
//This loop will toggle the LEDs When PIR detects object

  a=digitalRead(7);  //this variable is set to read the pir inputs and it gets stored here
  Serial.println(a);
  
  
  if(a==1){  //PIR has detected object
  for(int i=0; i<5;i++)
  {
  digitalWrite(ledPin, HIGH); 
  delay(100);
  digitalWrite(ledPin, LOW); 
  delay(100);
  }

  } 
  else
  digitalWrite(ledPin,LOW);

  
}

void loop2(1500) {
  
  // This task senses the value of the LDR and glows the LED accordingly 
  // Application : Headlights turn on when it gets dark, automated headlights
  
  
sensorValue = analogRead(sensorPin);

Serial.println(sensorValue);

    if (sensorValue < 100)

    {

      Serial.println("LED light on");

      digitalWrite(LDRled,HIGH);

       delay(1000);

    }
    
      digitalWrite(LDRled,LOW);

       delay(sensorValue);         // delay to make output readable on serial monitor.
       
}
//}

void loop3(11000) {
  // NO APPLICATION HERE 
 
}
