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
int HEAD_PIN = 4; 
int ARM_PIN = 5;
int BUZZER = 2;

// Motor angles. EDIT AS YOU NEED
int HEAD_UP = 50;
int HEAD_DOWN = 180;
int ARM_OUT = -180;
int ARM_IN = 180;
int HEAD_MED = 90;
int ARM_MED = 90;

// initialise dht11 sensor
DHT dht(HUM, DHT11);

// For control states
bool pressed_button = false;
unsigned long initial_time = 0;

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
  return;
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
  pinMode(BUZZER, OUTPUT);
  digitalWrite(TRIG, LOW);
  dht.begin();
  cabeza.attach(HEAD_PIN);
  brazo.attach(ARM_PIN); 
}

// Principal program
void loop() {
  get_in_box() // puede que esto no haga falta

  if (digitalRead(SWITCH) == false) {
    if (!pressed_button) {
      // just pressed the button
      pressed_button = true;
      initial_time = millis();
    }

    // Elapsed time since button is pressed
    unsigned long elapsed_time = millis() - initial_time;
    
    if (elapsed_time <= 3000){ // SIENDO AMABLES
      tone(BUZZER, 900);
      delay(100);
      tone(BUZZER, 800);
      delay(100);
      noTone(BUZZER);
      delay(100);

      get_out_of_box();
      delay(100);
      move_arm(1000);

    }else if (elapsed_time > 11000 && elapsed_time <= 15000) { // SIENDO MENOS AMABLES
      tone(BUZZER, 900);
      delay(1000);
      tone(BUZZER, 800);
      delay(1000);
      noTone(BUZZER);
      
      delay(100);
      move_arm(700);
    
    }else if (elapsed_time > 15000 && elapsed_time <= 20000) { // RECORDANDO NUESTRA EXISTENCIA
      
    }else if (elapsed_time > 25000 && elapsed_time <= 30000) { // COMENZANDO A ENFADARNOS
      
    }else if (elapsed_time > 35000 && elapsed_time <= 40000) { // PERDIENDO LA CORDURA
      
    }else if (elapsed_time > 500000) { // VOLVIENDONOS LOCOS
      
    }

  } else {
    // Button don't pressed, be inside the box and do nothing
    if (pressed_button) {
      pressed_button = false;
      get_in_box();
    }
  } 
}
