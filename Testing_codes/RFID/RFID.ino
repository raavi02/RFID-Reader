#include <SPI.h>
//#include <MsTimer2.h>
//#include <Servo.h>
#include "rfid.h"
uint8_t rfid_state = RFID_INITIALISE;
#include "functions.h"

#define MISO PB4
#define MOSI PB5
#define SCK PB3
#define SS PA15
#define Green_LED PC2
#define Red_LED PC3


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(Green_LED, OUTPUT);
  pinMode(Red_LED, OUTPUT);
  pinMode(MOSI, OUTPUT);
  pinMode(MISO, INPUT);
  pinMode(SCK,OUTPUT);
  SPI.begin();                            //Begins the SPI commnuication
  SPI.setClockDivider(SPI_CLOCK_DIV8);    //Sets clock for SPI communication at 8 (16/8=2Mhz)
  digitalWrite(SS,HIGH);                  // Setting SlaveSelect as HIGH (So master doesnt connnect with slave)
  attachInterrupt(digitalPinToInterrupt(MISO), rfid_sampling_rising_edge , RISING);
}

void loop() {
  // put your main code here, to run repeatedly:
    rfid_process();
    static uint8_t doing_read = 0;
    uint8_t result;
    if (!doing_read)
    {
         //-----------------------------------
         //----- WAITING TO DO NEXT READ -----
         //-----------------------------------
     if (general_use_10ms_timer == 0)
            {
              //----- START THE NEXT READ -----
              rfid_read_tag();
              doing_read = 1;
              general_use_10ms_timer = 25;
            }
          }
          else
          {
            //----------------------------------------
            //----- WAITING FOR READ TO COMPLETE -----
            //----------------------------------------
            result = rfid_get_read_tag_result();
//            if (result == 0)
//              return;     //Not complete

            if (result == 1)
            {
              //----- VALID RFID TAG DETECTED -----
//              RED_LED_ON = 0;
//              GREEN_LED_ON = 1;
              digitalWrite(Red_LED, LOW);
              digitalWrite(Green_LED, HIGH);
            }
            else
            {
              //----- READ ERROR - NO VALID TAG DETECTED -----
//              RED_LED_ON = 1;
//              GREEN_LED_ON = 0;
              digitalWrite(Red_LED, HIGH);
              digitalWrite(Green_LED, LOW);
            }
            doing_read = 0;
          }

}
