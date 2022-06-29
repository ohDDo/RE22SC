//#include <SoftwareSerial.h>

#define CLOCK_PIN 7
#define DATA_PIN 8
#define RESOLUTION 10

uint16_t data = 0;
//int a = 0;
uint16_t sensor = 0;
void setup() {
  Serial.begin(115200);
  
  pinMode(CLOCK_PIN, OUTPUT);
  pinMode(DATA_PIN, INPUT);
  digitalWrite(CLOCK_PIN, HIGH);
}

void loop() {
  for(int i=0; i<RESOLUTION; i++)
  {
    digitalWrite(CLOCK_PIN,LOW);
    delayMicroseconds(4);
    digitalWrite(CLOCK_PIN,HIGH);
    data = digitalRead(DATA_PIN);
    // debug
//    if(a == 1){
//      data = 1;
//    }
//    else if(a == 0){
//      data = 0;
//    }
//    else{
//      Serial.println(a);
//      Serial.println("fail");
//    }
    sensor = sensor|data;
    if(i<RESOLUTION-1)  sensor = sensor<<1;
    delayMicroseconds(5);
  }
  Serial.println(sensor);
  delayMicroseconds(6);
  sensor = 0;
}
