#define PRESS_SEN_PIN A2
#define LM35_SEN_PIN2 A1


long time=0;

float readPressure(){
  float pressureValue = analogRead(PRESS_SEN_PIN);
  float pressure=((pressureValue/1024.0)+0.095)/0.0009;
  return pressure;
}

float readTempLM35(int pin){
  float temp = analogRead(pin);
  temp = temp * 500.0/1023.0;
  return temp;
}



void setup() {
       
   Serial.begin(9600); 
   Serial1.begin(19200);

}

void loop() {

  float pressure=readPressure();
  float LM35temp2 = readTempLM35(LM35_SEN_PIN2);

  Serial1.print(pressure);
  Serial1.print(" "); 

  Serial1.print(LM35temp2);
  Serial1.print(" "); 
 
  Serial1.println();

  time++;
  delay(1000);
}



