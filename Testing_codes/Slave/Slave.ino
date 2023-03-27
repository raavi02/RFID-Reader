#include <SPI.h>
#define MISO 12
#define dummy PC7
#define MOSI 11
#define SCK 13
#define SS 10

volatile boolean received;
volatile byte Slavereceived,Slavesend;
int buttonvalue;
int x;



void setup() {
  // put your setup code here, to run once:
  pinMode(dummy, INPUT);
  pinMode(MOSI, OUTPUT);
  pinMode(MISO, INPUT);
  pinMode(SCK,OUTPUT);
  SPCR |= _BV(SPE);                       //Turn on SPI in Slave Mode
  received = false;
  SPI.begin();                            //Begins the SPI commnuication
  SPI.setClockDivider(SPI_CLOCK_DIV8);    //Sets clock for SPI communication at 8 (16/8=2Mhz)
  SPI.attachInterrupt(); 

}

ISR (SPI_STC_vect)                        //Inerrrput routine function 

{
  Slavereceived = SPDR;         // Value received from master if store in variable slavereceived
  received = true;                        //Sets received as True 
}

void loop() {
  // put your main code here, to run repeatedly:
  if(received)                            //Logic to SET LED ON OR OFF depending upon the value recerived from master
   {
      Serial.println(Slavereceived);
      if (Slavereceived==1) 
      {
        digitalWrite(LEDpin,HIGH);         //Sets pin 7 as HIGH LED ON
        Serial.println("Slave LED ON");
      }else
      {
        digitalWrite(LEDpin,LOW);          //Sets pin 7 as LOW LED OFF
        Serial.println("Slave LED OFF");
      }
//      buttonvalue = digitalRead(buttonpin);  // Reads the status of the pin 2
//      if (buttonvalue == HIGH)               //Logic to set the value of x to send to master
//      {
//        x=1;
//      }else
//      {
//        x=0;
//      }
  Slavesend=x;  
  x = 1 - x;                           
  SPDR = Slavesend;                           //Sends the x value to master via SPDR 
  delay(1000);
  }
}
