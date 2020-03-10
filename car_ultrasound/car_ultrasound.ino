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
int leftTrigPin = 18;
int leftEchoPin = 19;
int rightTrigPin = 16;
int rightEchoPin = 17;

// Prototypes
void drive_forwards();
void drive_backwards();
void drive_right();
void drive_left();
 
// Ultrasound variables
long duration;
int distance;

// Start variables
int forward = 15;
int left_start;
int right_start;
int forward_distance;
int left_distance;
int right_distance;

int read_sound(int trigPin, int echoPin){
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

    return distance;
}


void setup() 
{
    pinMode(forwardTrigPin, OUTPUT);
    pinMode(forwardEchoPin, INPUT);
    pinMode(leftTrigPin, OUTPUT);
    pinMode(leftEchoPin, INPUT);
    pinMode(rightTrigPin, OUTPUT);
    pinMode(rightEchoPin, INPUT);

    analogWrite(enA, 80);
    analogWrite(enB, 80);

    left_start = read_sound(leftTrigPin, leftEchoPin);
    right_start = read_sound(rightTrigPin, rightEchoPin);
}




void loop()
{   
    int forward_distance = read_sound(forwardTrigPin, forwardEchoPin);
    left_distance = read_sound(leftTrigPin, leftEchoPin);
    right_distance = read_sound(rightTrigPin, rightEchoPin);
    
    if (forward_distance >= forward) {
        drive_forwards();
        delay(200);
    } else {
        if (left_distance > (left_start+10)) {
            drive_left();
            delay(1000);
            drive_forwards();
            delay(1000);
        }
        else if (right_distance > (right_start+10)) {
            drive_right();
            delay(1000);
            drive_forwards();
            delay(1000);
        }
    }
}
 
//####################################################################################################
void drive_forwards() 
{
    // Set Motor A forward
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    
    // Set Motor B forward
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
}
 

void drive_backwards() 
{  
    // Set Motor A reverse
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
   
    // Set Motor B reverse
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
}
 

void drive_right() 
{   
    // Set Motor A reverse
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    
    // Set Motor B forward
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
}


void drive_left() 
{
    // Set Motor A forward
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    
    // Set Motor B reverse
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
}

void drive_stop()
{
    // Set Motor A forward
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    
    // Set Motor B reverse
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
}
