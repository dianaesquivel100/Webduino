int r = 3;
int g = 5;
int b = 6;

void setup() {
  // put your setup code here, to run once:
  pinMode(r, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(b, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  byte redValue;
  byte greenValue;
  byte blueValue;
  
  // put your main code here, to run repeatedly:
  if(Serial.available() >= 4){
    if(Serial.read() == 0xff){
      redValue = Serial.read();
      greenValue = Serial.read();
      blueValue = Serial.read();
    }
  }

  analogWrite(r,redValue);
  analogWrite(g,greenValue);
  analogWrite(b,blueValue);
  delay(15);
}
