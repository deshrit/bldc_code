// output pins to the gate
const uint8_t high_yellow = 11;
const uint8_t low_yellow = 10;

const uint8_t high_green = 9;
const uint8_t low_green = 8;

const uint8_t high_blue = 6;
const uint8_t low_blue = 5;


// sensor input pins
const uint8_t in_yellow = 4;
const uint8_t in_green = 3;
const uint8_t in_blue = 2;

// sensor values
uint8_t val_yellow, val_green, val_blue;

// potentiometer for val_speed
const int pot = A0;
unsigned int val_pot = 0;
unsigned int val_speed = 0;

// variable for phase
uint8_t phase = 0;

/* ----------------------------------------------------------------------------------- setup ----------------------------------------------------------------------------------- */
void setup() {
  Serial.begin(9600);

  // pinmode output for gate driving pins
  pinMode(high_yellow, OUTPUT);
  pinMode(low_yellow, OUTPUT);
  
  pinMode(high_green, OUTPUT);
  pinMode(low_green, OUTPUT);
  
  pinMode(high_blue, OUTPUT);
  pinMode(low_blue, OUTPUT);

  // default value 0 to gates
  digitalWrite(high_yellow, LOW);
  digitalWrite(low_yellow, LOW);

  digitalWrite(high_green, LOW);
  digitalWrite(low_green, LOW);

  digitalWrite(high_blue, LOW);
  digitalWrite(low_blue, LOW);
}

/* ----------------------------------------------------------------------------------- loop ----------------------------------------------------------------------------------- */
void loop() {
  // read sensor data
  read_sensor_data();

  // print sensor data
  print_sensor_data();

   // get phase
   phase = get_phase();

   // run motor
   run_motor(phase);
}

void read_sensor_data()
{
  // potentiometer
  val_pot = analogRead(pot);
  val_speed = (unsigned int) val_pot / 4;
  
  // sensor pins
  val_yellow = digitalRead(in_yellow);
  val_green = digitalRead(in_green);
  val_blue = digitalRead(in_blue);
}

void print_sensor_data()
{
//   Serial.print("\nval: ");
//   Serial.print(val_pot);
  Serial.print("\nval_speedl: ");
  Serial.print(val_speed);
  Serial.print("\tyellow: ");
  Serial.print(val_yellow);
  Serial.print("\tgreen: ");
  Serial.print(val_green);
  Serial.print("\tblue: ");
  Serial.print(val_blue);
  Serial.print("\tphase: ");
  Serial.print(phase);
}

uint8_t get_phase()
{
  if(val_yellow == 1 && val_green == 0 && val_blue == 1) return 1;
  else if(val_yellow == 1 && val_green == 0 && val_blue == 0) return 2;
  else if(val_yellow == 1 && val_green == 1 && val_blue == 0) return  3;
  else if(val_yellow == 0 && val_green == 1 && val_blue == 0) return 4;
  else if(val_yellow == 0 && val_green == 1 && val_blue == 1) return 5;
  else if(val_yellow == 0 && val_green == 0 && val_blue == 1) return 6;
  return 0;
}

void run_motor(uint8_t phase)
{
  switch(phase) {
    
    case 0:
      while(true) {
        Serial.println("*********** ERROR ***********");
      }
    break;
    
    case 1:
      analogWrite(high_yellow, val_speed);
      digitalWrite(low_green, HIGH);
     break;

     case 2:
      analogWrite(high_yellow, val_speed);
      digitalWrite(low_blue, HIGH);
     break;

     case 3:
      analogWrite(high_green, val_speed);
      digitalWrite(low_blue, HIGH);
     break;

     case 4:
      analogWrite(high_green, val_speed);
      digitalWrite(low_yellow, HIGH);
     break;

     case 5:
      analogWrite(high_blue, val_speed);
      digitalWrite(low_yellow, HIGH);
     break;

     case 6:
      analogWrite(high_blue, val_speed);
      digitalWrite(low_green, HIGH);
     break;
  }
}
