int TIMEOUT = 10000;
String Read = "OK";


void setup() {
  Serial.begin(115200);
  delay(5000);
  Serial.println("AT+RST");
  delay(5000);
  SendCommand("AT+CWMODE=1","OK");
  
}

void loop() {
  // put your main code here, to run repeatedly:

}

boolean SendCommand(String cmd, String ack){
  Serial.println(cmd); // Send "AT+" command to module
  boolean Ackn = echoFind(ack);
  Serial.println(Ackn);
  if (!Ackn) // timed out waiting for ack string
    return true; // ack blank or ack found
}

boolean echoFind(String keyword){
 byte current_char = 0;
 byte keyword_length = keyword.length();
 long deadline = millis() + TIMEOUT;
 while(millis() < deadline){
  //if (Serial.available()){
    char ch = Serial.read();
    Serial.print(ch);
    //Serial.print(ch);
    if (ch == keyword[current_char]){
      if (++current_char == keyword_length){
       Serial.println();
       return true;}
    }
   }
 
 return false; // Timed out
}
