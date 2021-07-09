/*code by prabin
 you can give pin no. as your wish .
 this code is simple and easy to use
 you can change the distance(sensitivity) of robot and also you can change the PWM (0-255) for speed of motor
 https://github.com/prabin7777/
 */

const int ftp = 11;

const int fep = 10;

const int rtp = A3;

const int rep = A4;

const int ltp = A2;

const int lep = A5;

const int d1 = 9;

const int d2 = 8;

const int d3 = 4;

const int d4 = 3;

const int dA = 5;

const int dB = 6;

#define PWM 200  // you can change pwm to change speed of motor 

#define DIS 25 // minimum distance needed to dectect or sensitivity

//setup our circuit
void setup() 

{

 pinMode(trigPin1, OUTPUT);

 pinMode(echoPin1, INPUT);

 

 pinMode(trigPin2, OUTPUT);

 pinMode(echoPin2, INPUT);

 pinMode(trigPin3, OUTPUT);

 pinMode(echoPin3, INPUT);

 

 pinMode (d1, OUTPUT);

 pinMode (d2, OUTPUT);

 pinMode (d3, OUTPUT);

 pinMode (d4, OUTPUT);

 pinMode (dA, OUTPUT);

 pinMode (dB, OUTPUT);
 Serial.begin(9600);

}

void loop()// loop to solve mesh.

{ 

 if ( FrontSensor() < DIS && RightSensor () <DIS && LeftSensor 

()<DIS) // obstacle infront of all 3 sides




 {

        turn_right (); 

        delay(3000);



 }

 else if (FrontSensor() <DIS && RightSensor () <DIS && LeftSensor 

()>DIS) // obstacle on right and front sides

 {

 turn_left (); 
 Serial.print('obstacles on right and front');

// turn left side

 }

 else if (FrontSensor() <DIS && RightSensor () >DIS && LeftSensor 

()<DIS) // obstacle on left and front sides
    {

 turn_right (); 

// turn right side



 }

 else if (FrontSensor() <DIS && RightSensor () >DIS && LeftSensor 

()>DIS) // obstacle on front sides

 {

 turn_right (); 

// then turn right

 }

 else if (FrontSensor() >DIS && RightSensor () >DIS && LeftSensor 

()<DIS) // obstacle on left sides

 {

 turn_right (); 

// then turn right and then forward

 delay(180);

 forward();

 }

 else if (FrontSensor() >DIS && RightSensor () <DIS && LeftSensor 

()>DIS) // obstacle on right sides

 {

  forward(); 

 }







 else 

 {

 forward();

 }

}

void forward ()

{

 digitalWrite(d1, HIGH);

 digitalWrite(d2, LOW);

 digitalWrite(d3, HIGH);

 digitalWrite(d4, LOW);

 analogWrite(dA, PWM); 

 analogWrite(dB, PWM);

}

void turn_left () 

{

 digitalWrite(d1, HIGH);

 digitalWrite(d2, LOW);

 digitalWrite(d3, LOW);

 digitalWrite(d4, HIGH);

 analogWrite(dA, PWM); 

 analogWrite(dB, PWM);

}

void turn_right () 

{

 digitalWrite(d1, LOW); 
  digitalWrite(d2, HIGH);

 digitalWrite(d3, HIGH);

 digitalWrite(d4, LOW);

 analogWrite(dA, PWM);

 analogWrite(dB, PWM);

}

void reverse ()

{

 digitalWrite(d1, LOW);

 digitalWrite(d2, HIGH);

 digitalWrite(d3, LOW);

 digitalWrite(d4, HIGH);

 analogWrite(dA, PWM);

 analogWrite(dB, PWM);

}

void stop()

{

 digitalWrite(d1, LOW);

 digitalWrite(d2, LOW);

 digitalWrite(d3, LOW);

 digitalWrite(in4, LOW);

 analogWrite(dA, LOW);

 analogWrite(dB, LOW);

}

long FrontSensor ()

{

long dur;

 digitalWrite(ftp, LOW); 

 delayMicroseconds(5); 

 digitalWrite(ftp, HIGH);

 delayMicroseconds(10); 

 digitalWrite(ftp, LOW);

 dur = pulseIn(fep, HIGH);

 return (dur/30);// convert the distance to centimeters.

}

long RightSensor () 

{

long dur;

 digitalWrite(rtp, LOW);

 delayMicroseconds(5); 

 digitalWrite(rtp, HIGH);

 delayMicroseconds(10); 

 digitalWrite(rtp, LOW);

 dur = pulseIn(rep, HIGH);

 return (dur/30);// convert the distance to centimeters.


}

long LeftSensor ()    
{

long dur;

 digitalWrite(ltp, LOW); 

 delayMicroseconds(5); 

 digitalWrite(ltp, HIGH);

 delayMicroseconds(10); 

 digitalWrite(ltp, LOW);

 dur = pulseIn(lep, HIGH);

 return (dur/30);// convert the distance to centimeters.

}
