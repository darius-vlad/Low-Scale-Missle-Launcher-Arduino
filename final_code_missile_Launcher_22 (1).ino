#include <Servo.h>

#define trigPin 2
#define echoPin 3
#define ledPin A5
#define calmPin A4
Servo servo_base;
Servo servo_middle;
Servo servo_top;

long duration;
int distance;
bool initialScanComplete = false;
void setup()
{
  servo_base.attach(5);
  servo_middle.attach(9);
  servo_top.attach(10);
  servo_top.write(180);
  servo_middle.write(90);
  Serial.begin(9600);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(calmPin, OUTPUT);

}

int i, j;
void loop()
{

  for ( i = 0; i <= 180; i += 5)
  {

    ultrasonic();

    servo_base.write(i);

    if (i == 0)
    {
      j = 160;
    }
    else if (i == 10)
    {
      j = 140;
    }
    else if (i == 30)
    {
      j = 160;
    }
    else if (i == 50)
    {
      j = 140;
    }
    else if (i == 70)
    {
      j = 160;
    }
    else if (i == 90)
    {
      j = 140;
    }
    else if (i == 110)
    {
      j = 160;
    }
    else if (i == 130)
    {
      j = 160;
    }
    else if (i == 150)
    {
      j = 160;
    }
    else if (i == 170)
    {
      j = 140;
    }


    servo_middle.write(j);
    delay(100);
     if (initialScanComplete && distance <= 30)
    {
      servo_top.write(120);
      digitalWrite(ledPin, HIGH);
      digitalWrite(calmPin, LOW);
      delay(500);
      ultrasonic();
    }
    else
    {
      servo_top.write(180);
      delay(100);
      digitalWrite(ledPin, LOW);
      digitalWrite(calmPin, HIGH);
    }

    // Set the flag to true after the first complete scan
    initialScanComplete = true;
  }


  



  for ( i = 180; i >= 0; i -= 5)
  {

    ultrasonic();

    servo_base.write(i);
    

    if (i == 170)
    {
      j = 160;
    }
    else if (i == 150)
    {
      j = 140;
    }
    else if (i == 130)
    {
      j = 160;
    }
    else if (i == 110)
    {
      j = 140;
    }
    else if (i == 90)
    {
      j = 160;
    }
    else if (i == 70)
    {
      j = 140;
    }
    else if (i == 50)
    {
      j = 160;
    }
    else if (i == 30)
    {
      j = 140;
    }
    else if (i == 10)
    {
      j = 160;
    }
   
    servo_middle.write(j);
    delay(100);


  if (initialScanComplete && distance <= 30)
    {
      servo_top.write(120);
      digitalWrite(ledPin, HIGH);
      digitalWrite(calmPin, LOW);
      delay(500);
      ultrasonic();
    }
    else
    {
      servo_top.write(180);
      delay(100);
      digitalWrite(ledPin, LOW);
      digitalWrite(calmPin, HIGH);
    }

    // Set the flag to true after the first complete scan
    initialScanComplete = true;
  }
    
   
  }


void ultrasonic()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distance = duration * 0.034 / 2;
  Serial.println(distance);

}
