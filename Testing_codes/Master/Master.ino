
//Master
#include<SPI.h>                               
#define MISO PB4
#define dummy PC7
#define MOSI PB5
#define SCK PB3     
#define SS PA15
byte tick = 0;
#define ipbutton 2
int buttonvalue;
uint8_t x = 0xFF;

byte rfid_tx_rx_byte (byte tx_data, byte get_response)
{
  byte rx_data = 0;


  digitalWrite(SCK, LOW);
  delay(1);     //Ensure the low state is long enough

  //INITIALISE THE SERIAL INTERFACE
  //(Low to high transition of DIN while SCLK is high marks the start of a transfer)
  digitalWrite(MOSI, LOW);
  tick++;
  digitalWrite(SCK, HIGH);
  tick++;
  digitalWrite(MOSI, HIGH);
  tick++;


  //BIT 7
  digitalWrite(SCK, LOW);
  tick++;
  
  #ifdef RFID_SPI_SAMPLE_CS_PIN
    RFID_SPI_SAMPLE_CS_PIN(0);
  #endif
  
  if (tx_data & 0x80)
    digitalWrite(MOSI, HIGH);
  else
    digitalWrite(MOSI, LOW);
  digitalWrite(SCK, HIGH);   //Data in valid in high state
  tick++;

  //BIT 6
  digitalWrite(SCK, LOW);
  tick++;
  if (tx_data & 0x40)
    digitalWrite(MOSI, HIGH);
  else
    digitalWrite(MOSI, LOW);
  digitalWrite(SCK, HIGH);
  tick++;

  //BIT 5
  digitalWrite(SCK, LOW);
  tick++;
  if (tx_data & 0x20)
    digitalWrite(MOSI, HIGH);
  else
    digitalWrite(MOSI, LOW);
  digitalWrite(SCK, HIGH);
  tick++;

  //BIT 4
  digitalWrite(SCK, LOW);
  tick++;
  if (tx_data & 0x10)
    digitalWrite(MOSI, HIGH);
  else
    digitalWrite(MOSI, LOW);
  digitalWrite(SCK, HIGH);
  tick++;

  //BIT 3
  digitalWrite(SCK, LOW);
  tick++;
  if (tx_data & 0x08)
    digitalWrite(MOSI, HIGH);
  else
    digitalWrite(MOSI, LOW);
  digitalWrite(SCK, HIGH);
  tick++;

  //BIT 2
  digitalWrite(SCK, LOW);
  tick++;
  if (tx_data & 0x04)
    digitalWrite(MOSI, HIGH);
  else
    digitalWrite(MOSI, LOW);
  digitalWrite(SCK, HIGH);
  tick++;

  //BIT 1
  digitalWrite(SCK, LOW);
  tick++;
  if (tx_data & 0x02)
    digitalWrite(MOSI, HIGH);
  else
    digitalWrite(MOSI, LOW);
  digitalWrite(SCK, HIGH);
  tick++;

  //BIT 0
  digitalWrite(SCK, LOW);
  tick++;
  if (tx_data & 0x01)
    digitalWrite(MOSI, HIGH);
  else
    digitalWrite(MOSI, LOW);
  digitalWrite(SCK, HIGH);
  tick++;


  if (get_response)
  {
    //BIT 7
    digitalWrite(SCK, LOW);
    tick++;
    digitalWrite(SCK, HIGH);   //Data out valid in high state
    tick++;
    if (digitalRead(MISO))
      rx_data |= 0x80;
  
    //BIT 6
    digitalWrite(SCK, LOW);
    tick++;
    digitalWrite(SCK, HIGH);
    tick++;
    if (digitalRead(MISO))
      rx_data |= 0x40;
  
    //BIT 5
    digitalWrite(SCK, LOW);
    tick++;
    digitalWrite(SCK, HIGH);
    tick++;
    if (digitalRead(MISO))
      rx_data |= 0x20;
  
    //BIT 4
    digitalWrite(SCK, LOW);
    tick++;
    digitalWrite(SCK, HIGH);
    tick++;
    if (digitalRead(MISO))
      rx_data |= 0x10;
  
    //BIT 3
    digitalWrite(SCK, LOW);
    tick++;
    digitalWrite(SCK, HIGH);
    tick++;
    if (digitalRead(MISO))
      rx_data |= 0x08;
  
    //BIT 2
    digitalWrite(SCK, LOW);
    tick++;
    digitalWrite(SCK, HIGH);
    tick++;
    if (digitalRead(MISO))
      rx_data |= 0x04;
  
    //BIT 1
    digitalWrite(SCK, LOW);
    tick++;
    digitalWrite(SCK, HIGH);
    tick++;
    if (digitalRead(MISO))
      rx_data |= 0x02;
  
    //BIT 0
    digitalWrite(SCK, LOW);
    tick++;
    digitalWrite(SCK, HIGH);
    tick++;
    if (digitalRead(MISO))
      rx_data |= 0x01;
  }
    
  digitalWrite(SCK, LOW);
  
  #ifdef RFID_SPI_SAMPLE_CS_PIN
    RFID_SPI_SAMPLE_CS_PIN(1);
  #endif

  return(rx_data);
}

void setup() {
  // put your setup code here, to run once:
//   Serial.begin(9600);                   //Starts Serial Communication at Baud Rate 115200
  pinMode(SCK, OUTPUT);
  pinMode(MISO, INPUT);
  pinMode(MOSI, OUTPUT);
  pinMode(SS, OUTPUT); 
  SPI.begin();
  SPI.setClockDivider(SPI_CLOCK_DIV8);
  digitalWrite(SS,HIGH);                  // Setting SlaveSelect as HIGH (So master doesnt connnect with slave)

}

void loop() {
  // put your main code here, to run repeatedly:
  byte Mastereceive;
                    //Starts communication with Slave connected to master
//  digitalWrite(MOSI, HIGH);                           
//  Mastereceive= rfid_tx_rx_byte(x, 1); //Send the mastersend value to slave also receives value from slave
//    Serial.println(Mastereceive);
//  SPI.beginTransaction();
  digitalWrite(SS, LOW);
  SPI.transfer(x);
  digitalWrite (SS, HIGH);
//  SPI.endTransaction();
  delay(100);

}
