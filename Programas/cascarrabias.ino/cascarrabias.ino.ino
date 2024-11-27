#include <Servo.h> 
#include <DHT.h>

// Initialice servos
Servo cabeza;
Servo brazo;

// Neccesary pins, EDIT AS YOU NEED
int LED = 13;
int SWITCH = 12;
int TRIG = 10;
int ECHO = 9;
int HUM = 7;

// State controller
unsigned long initial_time = 0;

// Motor angles. EDIT AS YOU NEED
int HEAD_UP = 100;
int HEAD_DOWN = -180;
int ARM_OUT = -180;
int ARM_IN = 180;
int HEAD_MED = -90;
int ARM_MED = -90;

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
  digitalWrite(LED, HIGH);
  delay(200);
  cabeza.write(HEAD_UP);
  delay(600);
  brazo.write(ARM_OUT);
  return;
}

void get_in_box(){
  digitalWrite(LED, LOW);
  delay(200);
  brazo.write(HEAD_DOWN);
  delay(600);
  cabeza.write(ARM_IN);
  return;
}

void move_head(int velocity){
  cabeza.write(HEAD_MED);
  delay(velocity);
  cabeza.write(HEAD_UP);
  delay(velocity);
  cabeza.write(HEAD_MED);
  delay(velocity);
  cabeza.write(HEAD_UP);
}

void move_arm(int velocity){
  brazo.write(ARM_OUT);
  delay(velocity);
  brazo.write(ARM_MED);
  delay(velocity);
  brazo.write(ARM_OUT);
  delay(velocity);
  brazo.write(ARM_MED);
  delay(velocity);
  brazo.write(ARM_IN);

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
  // Prepare motors' angle. EDIT IF YOU NEED
  cabeza.write(180);
  brazo.write(180);

  if (digitalRead(SWITCH) == false){
    get_out_of_box();
    delay(200);
    move_head(200);
    delay(100);
    move_arm(200);

    // esperar 2 segundos
    unsigned long current_time = millis();
    while (current_time - initial_time < 2){
      
      initial_time = current_time;
    }
    move_head(100);
    delay(100);
    move_arm(100);
    

    // esperar 3 segundos 
    move_arm(200);

    if (get_distance <= 3){
      get_in_box();
    }

    delay(100);
    get_out_of_box();
    delay(100);
    move_arm(100);
  
  }else{
    delay(1000);
    get_in_box();
  }     
}
