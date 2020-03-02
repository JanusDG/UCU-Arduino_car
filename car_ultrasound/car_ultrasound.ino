const byte MOTOR_A = 3;
const byte MOTOR_B = 2;

// Motor A
int enA = 10;
int in1 = 9;
int in2 = 8;

// Motor B
int enB = 5;
int in3 = 7;
int in4 = 6;

// Ultrasound detectors
int forwardTrigPin = 3;
int forwardEchoPin = 2;
int leftTrigPin;
int leftEchoPin;
int rightTrigPin;
int rightEchoPin;


// Prototypes
void forwards();
void backwards();
void right();
void left();
 
// Ultrasound variables
long duration;
int distance;

// Start variables
int forward = 15;
int left;
int right;

void setup() 
{
    pinMode(forwardTrigPin, OUTPUT);
    pinMode(forwardEchoPin, INPUT);
    pinMode(leftTrigPin, OUTPUT);
    pinMode(leftEchoPin, INPUT);
    pinMode(rightTrigPin, OUTPUT);
    pinMode(rightEchoPin, INPUT);

    analogWrite(enA, 45);
    analogWrite(enB, 45);

    left = read_sound(leftTrigPin, leftEchoPin);
    right = read_sound(rightTrigPin, rightEchoPin);
}

int read_sound(trigPin, echoPin){
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
}


void loop()
{   
    forward_distance = read_sound(forwardTrigPin, forwardEchoPin);
    left_distance = read_sound(leftTrigPin, leftEchoPin);
    right_distance = read_sound(rightTrigPin, rightEchoPin);
    
    if (distance >= 15) {
      forwards();
      delay(200);
    } else {
      backwards();
      delay(200);
    }
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
