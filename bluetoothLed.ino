#include "BluetoothSerial.h"

BluetoothSerial SerialBT;

char receivedChar;

const char turnON ='a';
const char turnOFF ='b';
const int LEDpin = 23;

void setup() 
{
  Serial.begin(115200);
  SerialBT.begin("ESP32_Ilia");
  Serial.println("The device started, now you can pair it with bluetooth!");
  Serial.println("To turn ON send: a");
  Serial.println("To turn OFF send: b");
  pinMode(LEDpin, OUTPUT);
}

void loop() 
{
  receivedChar =(char)SerialBT.read();
  if (Serial.available()) 
  {
    SerialBT.write(Serial.read());
  }
  if (SerialBT.available()) 
  {
    
    SerialBT.print("Received:");// write on BT app
    SerialBT.println(receivedChar);// write on BT app      
    Serial.print ("Received:");//print on serial monitor
    Serial.println(receivedChar);//print on serial monitor    
    if(receivedChar == turnON)
    {
     SerialBT.println("LED ON:");// write on BT app
     Serial.println("LED ON:");//write on serial monitor
     digitalWrite(LEDpin, HIGH);// turn the LED ON 
    }
    if(receivedChar == turnOFF)
    {
     SerialBT.println("LED OFF:");// write on BT app
     Serial.println("LED OFF:");//write on serial monitor
      digitalWrite(LEDpin, LOW);// turn the LED off 
    }    
  }
  delay(20);
}
