//CHECK THE SENSORS PINS WHILE CONNECTING TO ARDUINO BOARD IT MAY DIFFERENT FROM CIRCUIT DIAGRAM

//If you're using the built-in LED for testing, remember that it works with inverted logic
//(HIGH=LOW, and LOW=HIGH)
int led = 13;                // the pin that the AC BULB/FAN is attached to
int sensor = 12;              // the pin that the sensor is attached to
int state = LOW;             // by default, no motion detected
int val = 0;                 // variable to store the sensor status (value)

void setup() {
  pinMode(led, OUTPUT);      // initalize AC BULB/FAN as an output
  pinMode(sensor, INPUT);    // initialize sensor as an input
  Serial.begin(9600);        // initialize serial
}

void loop(){
  val = digitalRead(sensor);   // read sensor value
  if (val == HIGH) {           // check if the sensor is HIGH
    digitalWrite(led, HIGH);   // turn AC BULB/FAN ON
    
    if (state == LOW) {
      Serial.println("Motion detected!"); 
      state = HIGH;       // update variable state to HIGH
    }
  } 
  else {
      digitalWrite(led, LOW); // turn AC BULB/FAN OFF
      
      if (state == HIGH){
        Serial.println("Motion stopped!");
        state = LOW;       // update variable state to LOW
    }
  }
}