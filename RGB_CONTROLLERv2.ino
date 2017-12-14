//SOME OF THIS WAS ORIGINALLY LISTED FROM THE INTERNET
//I HAVE SINCE HEAVILY MODIFIED
//IF YOU DONT HAVE A SELECTER THEN IT WILL JUST BE THE RGB FADE

#define REDPIN 11
#define GREENPIN 9
#define BLUEPIN 10
#define SELECTA A3 

// These constants won't change.  They're used to give names
// to the pins used:
const int analogInPin = A3;  // Analog input pin that the potentiometer is attached to

int sensorValue = 0;        // value read from the pot
int outputValue = 0;        // value output to the PWM (analog out)


void setup() {

  //THIS SETS UP THE PINS TO DO THE DESIRED TASKS
  pinMode(REDPIN, OUTPUT);
  pinMode(GREENPIN, OUTPUT);
  pinMode(BLUEPIN, OUTPUT);
  pinMode(SELECTA, INPUT);

  //THIS IS A SYSTEMS CHECKTO MAKE SURE ALL OF THE CIRCUITS 
  //ARE HUNKY DORY (IT SHOULD BE A WHITE LIGHT. IF ITS NOT THEN YOU HAVE A PROBLEM)
  digitalWrite(BLUEPIN, HIGH);
  digitalWrite(GREENPIN, HIGH);
  digitalWrite(REDPIN, HIGH);

  //THIS IS SO YOUR CAVEMAN EYE CAN CHECK THAT EVERYTHING WORKS
  delay(100);

  // initialize serial communications at 9600 bps:
  Serial.begin(9600);

}


void loop() {

  //R, G, B DO WHAT YOU THINK THEY DO
  //D IS FOR THE FADE SPEED
  //S IS FOR THE MODE SELECT
  //DD IS FOR THE STROBE
  int r, g, b, D, s, dd;

  // read the analog in value:
  sensorValue = analogRead(analogInPin);
  // map it to the range of the analog out:
  outputValue = map(sensorValue, 0, 1023, 0, 255);
  // change the analog out value:

  // print the results to the serial monitor:
  Serial.print("sensor = ");
  Serial.print(sensorValue);
  Serial.print("\t output = ");
  Serial.println(outputValue);

  // wait 2 milliseconds before the next loop
  // for the analog-to-digital converter to settle
  // after the last reading:

//THIS IS WHAT GETS THE VALUE FOR THE MODE SELECT
  s = analogRead(SELECTA);

  //THIS IS FOR THE REGULAR FADE SPEED
  D = 10;

  //THIS IS FOR THE PARTY MODE SPEED
  //A VALUE THAT IS TOO LOW STROBES TOO FAST AND LOOKS WHITE
  //ITS A PROBLEM WITH THE PHYSICS OF THE COMPONENTS IN THE SYSTEM
  //DONT BLAME MY CODE!
  dd = 50;
  //=================================
  //OFF
  //=================================
  if(s >= 800){
    digitalWrite(REDPIN, LOW);
    digitalWrite(GREENPIN, LOW);
    digitalWrite(BLUEPIN, LOW);
  }
  //================================
  //!!!PARTY MODE!!!
  //================================
  if(s >= 700 && s < 800){
    //RED PHASE
    digitalWrite(REDPIN, HIGH);
    digitalWrite(GREENPIN, LOW);
    digitalWrite(BLUEPIN, LOW);
    delay(dd);
    //GREEN PHASE
    digitalWrite(REDPIN, LOW);
    digitalWrite(GREENPIN, LOW);
    digitalWrite(BLUEPIN, HIGH);
    delay(dd);
    //BLUE PHASE
    digitalWrite(REDPIN, LOW);
    digitalWrite(GREENPIN, HIGH);
    digitalWrite(BLUEPIN, LOW);
    delay(dd);
  }

  //=================================
  //GETS US orange
  //=================================
  if(s >= 600 && s < 700){
    digitalWrite(REDPIN, HIGH);
    digitalWrite(GREENPIN, LOW);
    digitalWrite(BLUEPIN, HIGH);
  }
  
  //=================================
  //GETS US RED
  //=================================
  if(s >= 500 && s < 600){
    digitalWrite(REDPIN, HIGH);
    digitalWrite(GREENPIN, LOW);
    digitalWrite(BLUEPIN, LOW);
  }
  
  //=================================
  //GETS US PURPLE
  //=================================
  if(s >= 400 && s < 500){
    digitalWrite(REDPIN, HIGH);
    digitalWrite(GREENPIN, HIGH);
    digitalWrite(BLUEPIN, LOW);
  }

  
  //=================================
  //GETS US BLUE
  //=================================
  if(s >= 300 && s < 400){
    digitalWrite(REDPIN, LOW);
    digitalWrite(GREENPIN, HIGH);
    digitalWrite(BLUEPIN, LOW);
  }

   //================================
  //GETS US TEAL
  //=================================
  if(s >= 200 && s < 300){
    digitalWrite(REDPIN, LOW);
    digitalWrite(GREENPIN, HIGH);
    digitalWrite(BLUEPIN, HIGH);
  }
  
  //==================================
  //GETS US GREEN
  //==================================
  if(s >= 100 && s < 200){
    digitalWrite(REDPIN, LOW);
    digitalWrite(GREENPIN, LOW);
    digitalWrite(BLUEPIN, HIGH);
  }


  //=================================
  //REGULAR FADE
  //=================================
  if(s >= 0 && s < 100){
    // fade from blue to violet
    for (r = 0; r < 256; r++) {
      analogWrite(REDPIN, r);
      delay(D);
    }
    // fade from violet to red
    for (b = 255; b > 0; b--) {
      analogWrite(BLUEPIN, b);
      delay(D);
    }
    // fade from red to yellow
    for (g = 0; g < 256; g++) {
      analogWrite(GREENPIN, g);
      delay(D);
    }
    // fade from yellow to green
    for (r = 255; r > 0; r--) {
      analogWrite(REDPIN, r);
      delay(D);
    }
    // fade from green to teal
    for (b = 0; b < 256; b++) {
      analogWrite(BLUEPIN, b);
      delay(D);
    }
    // fade from teal to blue
    for (g = 255; g > 0; g--) {
      analogWrite(GREENPIN, g);
      delay(D);
    }

}
}
