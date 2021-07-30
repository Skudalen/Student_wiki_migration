/*
              +------------------------+
              |  +5V                   +
    +---------+------+                  /
    |                | PIN 3           +
    |                +-----------------+
    |   Arduino      | PIN 12          |
    |                +------------+    |
    |                |            |    |
    |                |            |    |
    |                |           | |  | |
    |                |      10k  | |  | |  10k
    +---------+------+           | |  | | PUL DOWN
              |  GND              |    |
              |                  ---   |
              |                  \ /   |
              |                   V    |
              |                  ===   |
              |                   |    |               
              |                   |    |
              +-------------------+----+


*/

#define LEDPIN 12
#define BUTTONPIN 3

int ledState;
int switchTime;

void setup() {
  pinMode(LEDPIN, OUTPUT);
  digitalWrite(LEDPIN, LOW);
  pinMode(BUTTONPIN, INPUT);
  ledState = 0;
  
}
void loop() {
  int val = digitalRead(BUTTONPIN);
  int t = millis();
  if (val){
    if (t - switchTime > 50){
      ledState = !ledState;
    }
    switchTime = t;
  }
  if (ledState){
    digitalWrite(LEDPIN, HIGH);
  }
  else {
    digitalWrite(LEDPIN, LOW);
  }  
}
