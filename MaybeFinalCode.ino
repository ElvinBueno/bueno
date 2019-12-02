 //initialize the analog pin for the distance sensor
 int sensorpin = A0;
 int Solenoid = 7;


 
 //store a value for the sensorpin read out
 int val = 0; 

 int red = 9;       //Yellow Wire; Red Output
 int green = 10;    //Green Wire; Green Output
 int blue = 11;     //Blue Wire; Blue Output

void setup() {
  
Serial.begin(9600);

pinMode(red, OUTPUT);
pinMode(green, OUTPUT);
pinMode(blue, OUTPUT);

pinMode(Solenoid, OUTPUT);

}

void loop() {

//pinMode(Solenoid, LOW);
val = analogRead(sensorpin);
delay(100);

  if (val < 480)
  {
  BlinkGreen();
  }

  else{
    WhileRed();
  }
Serial.println(val);

}

void WhileRed()
{

  
  while (val > 480) {
  digitalWrite(red, HIGH);
  digitalWrite(green, LOW);
  digitalWrite(blue, LOW);

delay(1000);
  
  digitalWrite(Solenoid, HIGH);
  
  delay(5000);

  digitalWrite(Solenoid, LOW);

  loop();
  }
  
}

void BlinkGreen()
{
  digitalWrite(red, LOW);
  digitalWrite(green, LOW);
  digitalWrite(blue, LOW);

  delay (100);

  digitalWrite(red, LOW);
  digitalWrite(green, HIGH);
  digitalWrite(blue, LOW);

  delay (100);
}
