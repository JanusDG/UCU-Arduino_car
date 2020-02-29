const byte MOTOR_A = 3;  // Motor 2 Interrupt Pin - INT 3 - Right Motor
const byte MOTOR_B = 2;  // Motor 1 Interrupt Pin - INT 2 - Left Motor

// Motor A
int enA = 10;
int in1 = 9;
int in2 = 8;

// Motor B
int enB = 5;
int in3 = 7;
int in4 = 6;

// Ultrasound detector
int trigPin = 3;
int echoPin = 2;

// Prototypes
void forwards();
void backwards();
void right();
void left();
 
// Ultrasound variables
long duration;
int distance;

void setup() 
{
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);

    analogWrite(enA, 45);
    analogWrite(enB, 45);
}


void loop()
{ 
    // Clear the trigPin by setting it to LOW:
    digitalWrite(trigPin, LOW);
    delayMicroseconds(5);
  
    // Trigger the sensor by setting the trigPin high for 10 microseconds:
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
  
    // Read the echoPin, pulseIn() returns the duration (length of the pulse) in microseconds:
    duration = pulseIn(echoPin, HIGH);
    // Calculate the distance:
    distance = (duration)/58;
    
    if (distance < 15) {
      forwards(); 
      delay(200);
    }
    else {
      backwards();
      delay(200);
    }

    delay(100);
}
 
//####################################################################################################
void forwards() 
{
    // Set Motor A forward
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    
    // Set Motor B forward
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
}
 

void backwards() 
{  
    // Set Motor A reverse
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
   
    // Set Motor B reverse
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
}
 

void right() 
{   
    // Set Motor A reverse
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    
    // Set Motor B forward
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
}


void left() 
{
    // Set Motor A forward
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    
    // Set Motor B reverse
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
}

void stop()
{
    // Set Motor A forward
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    
    // Set Motor B reverse
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
}
