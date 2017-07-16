const int triggerPort = 7;
const int echoPort = 6;

#define R_PIN 11
#define G_PIN 10
#define B_PIN 9

float r = 0;
float g = 0;
float b = 0;
//1
//1 int far_r = 5;
//1 int far_g = 5;
//1 int far_b = 5;

//1 int near_r = 255;
//1 int near_g = 50;
//1 int near_b = 0;

//2
int far_r = 80;
int far_g = 80;
int far_b = 50;
//
int near_r = 230;
int near_g = 50;
int near_b = 0;

float k = 0.07;

//1
//1 int min_distance = 70;
//1 int max_distance = 200;

int min_distance = 70;
int max_distance = 200;

void setup() {
  pinMode(triggerPort, OUTPUT);
  pinMode(echoPort, INPUT);
  Serial.begin(9600);
  Serial.print( "Sensor: ");

  pinMode(R_PIN, OUTPUT);
  pinMode(G_PIN, OUTPUT);
  pinMode(B_PIN, OUTPUT);
}

void loop() {
  long distance = getDistance();

  float r_current = map(distance, min_distance, max_distance, near_r, far_r);
  float g_current = map(distance, min_distance, max_distance, near_g, far_g);
  float b_current = map(distance, min_distance, max_distance, near_b, far_b);

  float delta_r = k * (r_current - r);
  float delta_g = k * (g_current - g);
  float delta_b = k * (b_current - b);

  r += delta_r;
  g += delta_g;
  b += delta_b;
  led();
  
  Serial.print("R:");
  Serial.print(r);
  Serial.print(" G:");
  Serial.print(g);
  Serial.print(" B:");
  Serial.print(b);
  Serial.print(" D:");
  Serial.print(distance);
  Serial.println("");

  delay(10);
}

int getDistance() {
  digitalWrite( triggerPort, LOW );
  delayMicroseconds(2);
  //10microsec impulse on trigger
  digitalWrite( triggerPort, HIGH );
  delayMicroseconds(10);
  digitalWrite( triggerPort, LOW );

  long duration = pulseIn( echoPort, HIGH);
  long distance = 0.034 * duration / 2;
  return constrain(distance, min_distance, max_distance);
}

void led() {
  analogWrite(R_PIN, r);
  analogWrite(G_PIN, g);
  analogWrite(B_PIN, b);
}
