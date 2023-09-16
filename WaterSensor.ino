// S pin of water sensor --> A3 pin
// + pin of water sensor --> 5V pin
// - pin of water sensor --> GRND pin
// The pin of red led --> pin8 
// The pin of yellow led --> pin9 
// The pin of blue led --> pin10
 
const int Spin = A3;
const int REDpin = 8;
const int YELLOWpin = 9;
const int BLUEpin = 10;
const float RedThreshold = 2.5;
const float YellowThreshold = 3.0;
const float BlueThreshold = 3.5;


float v2;




void setup() {
  // put your setup code here, to run once
  pinMode(Spin,INPUT);
  pinMode(REDpin,OUTPUT);
  pinMode(YELLOWpin,OUTPUT);
  pinMode(BLUEpin,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  v2 = analogRead(Spin);
  float voltage = v2 * (5./1023.);
  Serial.print("Voltage: ");
  Serial.println(voltage);
  delay(500);
  if(voltage >= RedThreshold){
    digitalWrite(REDpin,HIGH);
  }
  if(voltage >= YellowThreshold){
    digitalWrite(YELLOWpin,HIGH);
  }
  if (voltage >= BlueThreshold){
    digitalWrite(BLUEpin,HIGH);
  }
  else {
    digitalWrite(REDpin,LOW);
    digitalWrite(YELLOWpin,LOW);
    digitalWrite(BLUEpin,LOW);
  };

   


  

 
}
