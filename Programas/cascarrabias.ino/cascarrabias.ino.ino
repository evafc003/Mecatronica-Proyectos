#include <Servo.h> 
#include <DHT.h>

// Initialice servos
Servo cabeza;
Servo brazo;

// Neccesary pins, edit as you need
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

  // Servo pins, edit as you need
  cabeza.attach(4);
  brazo.attach(5); 
}

// Principal program
void loop() {
   switch (state) {
    case 0:
      if (digitalRead(SWITCH) == false){
        digitalWrite(LED, HIGH); // enciendo
        delay(200);
        cabeza.write(270); // levanto
        delay(600);
        brazo.write(90); // muevo brazo
      
      }else{
        digitalWrite(LED, LOW);
        delay(200);
        brazo.write(-90); // meto brazo
        delay(600);
        cabeza.write(-270); // me escondo
        state = state+1;
      }     
      break;
    case 1:
      //do something when var equals 2
      state = state+1;
      break;
    case 2:
      //do something when var equals 2
      state = state+1;
      break;
    case 3:
      //do something when var equals 2
      state = state+1;
      break;
    case 4:
      //do something when var equals 2
      state = state+1;
      break;
    case 5:
      //do something when var equals 2
      state = state+1;
      break;
    case 6:
      //do something when var equals 2
      state = 0;
      break;
  }
}
