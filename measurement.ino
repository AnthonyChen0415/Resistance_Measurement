// resistance measurement
// Xi Chen, Saarland University
#include <FileIO.h>

int s0 = 8;
int s1 = 9;
int s2 = 10;
int s3 = 11;
int s4 = 2;
int s5 = 3;
int s6 = 4;
int s7 = 5;
int reading1 = A0;
float samples[199];
int num;

void open_port_A(int num){
  switch (num){
    case 1:   
      digitalWrite(s0, HIGH);  
      digitalWrite(s1, LOW);  
      digitalWrite(s2, LOW);  
      digitalWrite(s3, LOW);
      break;
    case 2:
      digitalWrite(s0, HIGH);  
      digitalWrite(s1, HIGH);  
      digitalWrite(s2, LOW);  
      digitalWrite(s3, LOW);
      break;
    case 3:
      digitalWrite(s0, HIGH);  
      digitalWrite(s1, LOW);  
      digitalWrite(s2, HIGH);  
      digitalWrite(s3, LOW);
      break;
    case 4:
      digitalWrite(s0, HIGH);  
      digitalWrite(s1, HIGH);  
      digitalWrite(s2, HIGH);  
      digitalWrite(s3, LOW);
      break;
    case 5:
      digitalWrite(s0, HIGH);  
      digitalWrite(s1, LOW);  
      digitalWrite(s2, LOW);  
      digitalWrite(s3, HIGH);
      break;
  }
}
void open_port_B(int num){
  switch (num){
    case 1:   
      digitalWrite(s4, HIGH);  
      digitalWrite(s5, LOW);  
      digitalWrite(s6, LOW);  
      digitalWrite(s7, LOW);
      break;
    case 2:
      digitalWrite(s4, HIGH);  
      digitalWrite(s5, HIGH);  
      digitalWrite(s6, LOW);  
      digitalWrite(s7, LOW);
      break;
    case 3:
      digitalWrite(s4, HIGH);  
      digitalWrite(s5, LOW);  
      digitalWrite(s6, HIGH);  
      digitalWrite(s7, LOW);
      break;
    case 4:
      digitalWrite(s4, HIGH);  
      digitalWrite(s5, HIGH);  
      digitalWrite(s6, HIGH);  
      digitalWrite(s7, LOW);
      break;
    case 5:
      digitalWrite(s4, HIGH);  
      digitalWrite(s5, LOW);  
      digitalWrite(s6, LOW);  
      digitalWrite(s7, HIGH);
      break;
  }
}
float measurement(){
  int sensorValue = analogRead(reading1);
  float voltage = sensorValue * (5.0/1023.0);
  //Serial.println(voltage);
  float resistance = (voltage*2000000) / (5-voltage);
  Serial.println(resistance);
  return resistance;
}
void experiment(){
  for (int i = 1; i<= 5; i++){
    for (int j = i+1; j<=5; j++){
      for (int n = 1; n<= 10; n++){
        for (int m = 1; m<=10; m++){
          open_port_A(i);
          open_port_B(j);
          samples[num] += measurement();
          delay(60);
        }
        samples[num] = samples[num] / 10;
        num++;
      }
    } 
  }
  Serial.println("Measurement is done..");  
}
void setup() {
  // put your setup code here, to run once:
  pinMode(s0, OUTPUT);
  pinMode(s1, OUTPUT);
  pinMode(s2, OUTPUT);
  pinMode(s3, OUTPUT);
  pinMode(s4, OUTPUT);
  pinMode(s5, OUTPUT);
  pinMode(s6, OUTPUT);
  pinMode(s7, OUTPUT);
  Serial.begin(9600);
      
}
void loop() {
  // put your main code here, to run repeatedly:
  while(!Serial);
  if(Serial.available()){
    if (Serial.read() == '1'){
      num = 0;
      experiment();
    }
  }
}