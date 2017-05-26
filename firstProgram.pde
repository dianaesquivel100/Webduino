import processing.serial.*;
Serial port;
void setup(){
  println("Available serial ports:");
  println(Serial.list());
  port = new Serial(this, Serial.list()[0], 9600);  // Open the port that the Arduino board is connected to, at 9600 baud
}
void draw(){
  String[] colors = new String[3];
  colors = loadStrings("pruebaLed.txt"); // Insert the location of your .txt file
  /* text file contains 3 lines of numbers for RGB values, eg:
  255
  125
  0
  */
  for(int n=0;n<3;n++){
    println(colors[n]);
    int num;
    num = parseInt(colors[n]); // change string into Int
    port.write((byte)(num)); // write as a byte over serial
  }
  port.write(0xff); //write our marker
  //delay(20);
}