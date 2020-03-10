// Motor A
int enA = 22;
int in1 = 24;
int in2 = 26;

// Motor B
int enB = 23;
int in3 = 25;
int in4 = 27;

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

    analogWrite(enA, 150);
    analogWrite(enB, 150);

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
    
    if (forward_distance >= forward) {
        forwards();
        delay(200);
    } else {
        if (left_distance > (left+10)) {
            left();
            delay(1000);
            forwards();
            delay(1000);
        }
        else if (right_distance > (right+10)) {
            right();
            delay(1000);
            forwards();
            delay(1000);
        }
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
