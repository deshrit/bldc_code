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

// potentiometer for speed
const int pot = A0;
int val_pot = 0;

void setup() {
  Serial.begin(9600);

  // pinmode output for gate driving pins
  pinMode(high_yellow, OUTPUT);
  pinMode(low_yellow, OUTPUT);
  
  pinMode(high_green, OUTPUT);
  pinMode(low_green, OUTPUT);
  
  pinMode(high_blue, OUTPUT);
  pinMode(low_blue, OUTPUT);
}

void loop() {
  // read sensor data
  read_sensor_data();

  // print sensor data
  print_sensor_data();
   
}

void read_sensor_data()
{
  // potentiometer
  val_pot = analogRead(pot);

  // sensor pins
  val_yellow = digitalRead(in_yellow);
  val_green = digitalRead(in_green);
  val_blue = digitalRead(in_blue);
}

void print_sensor_data()
{
  Serial.print("\nval: ");
  Serial.print(val_pot);
  Serial.print("\tyellow: ");
  Serial.print(val_yellow);
  Serial.print("\tgreen: ");
  Serial.print(val_green);
  Serial.print("\tblue: ");
  Serial.print(val_blue);
}
