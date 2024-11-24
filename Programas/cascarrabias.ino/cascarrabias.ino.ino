#include <Servo.h> 
#include <DHT.h>

// Initialice servos
Servo cabeza;
Servo brazo;

// Neccesary pins, EDIT AS YOU NEED
int LED = 13;
int state = 0;
int SWITCH = 12;
int TRIG = 10;
int ECHO = 9;
int HUM = 7;

// initialise dht11 sensor
DHT dht(HUM, DHT11);

// FUNCTIONS WE NEED
long get_distance(){
  long t;
  long d;

  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  
  t = pulseIn(ECHO, HIGH);
  d = t/59;
  
  // Serial.print("Distancia: ");
  // Serial.print(d);
  // Serial.println("cm");
  
  return d;
}

float get_humidity(){
  float h = dht.readHumidity();
  // Serial.print("Humedad: ");
  // Serial.println(h);
  return h;
}

void get_out_of_box(){
  digitalWrite(LED, HIGH); // enciendo
  delay(200);
  cabeza.write(); // levanto
  delay(600);
  brazo.write(); // muevo brazo
  return;
}

void get_in_box(){
  digitalWrite(LED, LOW);
  delay(200);
  brazo.write(); // meto brazo
  delay(600);
  cabeza.write(); // me escondo
  return;
}

// Setup function for getting started our proyect
void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(HUM, INPUT);
  pinMode(SWITCH, INPUT_PULLUP);
  digitalWrite(TRIG, LOW);
  dht.begin();

  // Servo pins, EDIT AS YOU NEED
  cabeza.attach(4);
  brazo.attach(5); 
}

// Principal program
void loop() {
   switch (state) {
    case 0:
      if (digitalRead(SWITCH) == false){
        get_out_of_box();
        delay(100)
        get_in_box();
        state = state+1;
      }     
      break;
    case 1:
      if (digitalRead(SWITCH) == false){
        get_out_of_box();
        delay(100)
        get_in_box();
        state = state+1;
      }     
      break;
    case 2:
      if (digitalRead(SWITCH) == false){
        get_out_of_box();
        delay(100)
        get_in_box();
        state = state+1;
      
      }
      break;
    case 3:
      if (digitalRead(SWITCH) == false){
        get_out_of_box();
        delay(100)
        get_in_box();
        state = state+1;
      
      }
      break;
    case 4:
      if (digitalRead(SWITCH) == false){
        get_out_of_box();
        delay(100)
        get_in_box();
        state = state+1;
      
      }
      break;
    case 5:
      if (digitalRead(SWITCH) == false){
        get_out_of_box();
        delay(100)
        get_in_box();
        state = state+1;
      }
      break;
  }
}
