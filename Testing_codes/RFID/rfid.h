/*
 * rfid.h
 *
 *  Created on: Mar 21, 2023
 *      Author: Raavi_Gupta
 */

#ifndef SRC_RFID_H_
#define SRC_RFID_H_


//----- RFID PARAMETERS -----
#define  RFID_T_OC           0x3F    //Offset Compensation value.  0x3F is typical (if no capacitor is connected to RX).  See section 9.2.4 of the Philips "Read/Write Devices
                          //based on the HITAG Read/Write IC HTRC110" application note AN97070 (rev 1.1)

#define RFID_C
typedef enum _SM_RFID
{
  RFID_INITIALISE,
    RFID_SET_IDLE,
    RFID_IDLE,
    RFID_READ_TAG,
    RFID_READ_TAG_READING,
    RFID_READ_FAIL
} SM_RFID;

typedef enum _SM_RFID_CAPTURE
{
  RFID_CAPTURE_INITIALISE,
  RFID_CAPTURE_GET_BIT_RATE,
  RFID_CAPTURE_GET_HEADER,
  RFID_CAPTURE_GET_DATA,
  RFID_CAPTURE_SUCCESS,
  RFID_CAPTURE_FAILED,
  RFID_CAPTURE_FAILED_GIVEN_UP
} SM_RFID_CAPTURE;


#endif


//*******************************
//*******************************
//********** FUNCTIONS **********
//*******************************
//*******************************
#ifdef RFID_C
//-----------------------------------
//----- INTERNAL ONLY FUNCTIONS -----
//-----------------------------------
//uint8_t rfid_tx_rx_byte (uint8_t tx_data, uint8_t get_response);
//void rfid_start_read_tag (void);
//void rfid_end_read_tag (void);
//uint8_t rfid_sampling_rising_edge_add_bit (uint8_t bit_state);


//-----------------------------------------
//----- INTERNAL & EXTERNAL FUNCTIONS -----
//-----------------------------------------
//(Also defined below as extern)
//void rfid_read_tag (void);
//uint8_t rfid_get_read_tag_result (void);
//void rfid_force_initialise (void);
//void rfid_process (void);
//void rfid_sampling_rising_edge (uint16_t us_since_last_rising_edge);


//#else
////------------------------------
////----- EXTERNAL FUNCTIONS -----
////------------------------------
//extern void rfid_read_tag (void);
//extern uint8_t rfid_get_read_tag_result (void);
//extern void rfid_force_initialise (void);
//extern void rfid_process (void);
//extern void rfid_sampling_rising_edge (WORD us_since_last_rising_edge);


#endif




//****************************
//****************************
//********** MEMORY **********
//****************************
//****************************
#ifdef RFID_C
//--------------------------------------------
//----- INTERNAL ONLY MEMORY DEFINITIONS -----
//--------------------------------------------
uint8_t rfid_gain;
uint8_t rfid_read_tag_pending = 1;
uint8_t rfid_read_tag_success;
uint8_t rfid_capture_state;
uint8_t rfid_bit_count;
uint8_t rfid_tries_count;
volatile unsigned long us_since_last_rising_edge = 0;
volatile unsigned long time1 = 0;
uint16_t general_use_10ms_timer = 0;


//--------------------------------------------------
//----- INTERNAL & EXTERNAL MEMORY DEFINITIONS -----
//--------------------------------------------------
//(Also defined below as extern)
uint8_t rfid_data_nibbles[11];
volatile uint8_t rfid_1ms_timer;


//#else
////---------------------------------------
////----- EXTERNAL MEMORY DEFINITIONS -----
////---------------------------------------
//extern uint8_t rfid_data_nibbles[11];
//extern uint8_t rfid_state;
//extern volatile uint8_t rfid_1ms_timer;


#endif /* SRC_RFID_H_ */
