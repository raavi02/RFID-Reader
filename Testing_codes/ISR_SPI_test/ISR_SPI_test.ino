#include <SPI.h>
#define MISO PB4
#define dummy PC7
#define MOSI PB5
#define SCK PB3
#define Green_LED PC2
#define Red_LED PC3



void setup() {
  // put your setup code here, to run once:
    Serial.begin(9600);
  pinMode(Green_LED, OUTPUT);
  pinMode(Red_LED, OUTPUT);
  pinMode(dummy, INPUT);
  pinMode(MOSI, INPUT);
  pinMode(MISO, OUTPUT);
  pinMode(SCK,OUTPUT);
  SPI.begin();                            //Begins the SPI commnuication
  SPI.setClockDivider(SPI_CLOCK_DIV8);    //Sets clock for SPI communication at 8 (16/8=2Mhz)
  digitalWrite(SS,HIGH);                  // Setting SlaveSelect as HIGH (So master doesnt connnect with slave)
  attachInterrupt(digitalPinToInterrupt(dummy), rfid_sampling_rising_edge , RISING);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(MISO, LOW);
  Serial.println(digitalRead(dummy));
  delay(100);
  digitalWrite(MISO, HIGH);
  Serial.println(digitalRead(dummy));
  delay(2000);
  
}

void rfid_sampling_rising_edge()
{
  Serial.println("Entered ISR!");
}
