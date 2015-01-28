/**************************************************************************/
/*!
@file     LIDARLite_registers.h
@author   Stuart Feichtinger
@license  MIT (see license.txt)

Arduino Library for the LIDAR-Lite from PulsedLight, Inc.

@section  HISTORY
v0.0.1 - First release

*/
/**************************************************************************/


#pragma once

//TODO: Finish adding bit definitions and descriptions
//TODO: Clean up file and make more readable

//DEFAULT I2C ADDRESS
#define LIDARLite_ADDRESS   0x62


/*####################INTERNAL REGISTERS######################*/


/**************************************************************/
/*                COMMAND CONTROL REGISTER                    */
/*                    control_reg[0x0]                        */
/*                     (READ & WRITE)                         */
/**************************************************************/
#define LIDAR_COMMAND       0x0   // Register Address

  /*Bit definitions*/
  #define RESET_FPGA          0   // Reset FPGA. Re-loads FPGA from internal Flash memory – all registers return to default values
  #define PROCESS_2ND         1   // Correlation processing without new acquisition – used to process delay of second peak after bit 0 in control register  0x4b is set to 1
  #define REPROCESS           2   // Process correlation without new acquisition – used to reprocess
  #define NO_DC               3   // Take acquisition& correlation processing WITHOUT DC correction
  #define USE_DC              4   // Take acquisition & correlation processing WITH DC correction

/*------------------------END REGISTER------------------------*/



/**************************************************************/
/*                  SYSTEM STATUS REGISTER                    */
/*                    control_reg[0x1]                        */
/*                     (READ & WRITE)                         */
/**************************************************************/

#define LIDAR_SYS_STATUS    0x1   //Register Address

  /*Bit definitions*/
  #define HEALTH              0   // “1” state indicates that all health monitoring criteria were met on the last acquisition. ”0” possible problem
  #define REF_OVRFLOW         1   // Overflow detected in correlation process associated with a reference acquisition
  #define SIG_OVERFLOW        2   // Overflow detected in correlation process associated with a signal acquisition
  #define SIGNAL_NOT_VALID    3   // Indicates that the signal correlation peak is equal to or below correlation record noise threshold
  #define SECOND_RETURN       4   // Secondary return detected above correlation noise floor threshold
  #define VELOCITY_COMPLETE   5   // Velocity measurement completed
  #define EXT_TRIG_COMPLETE   6   // External measurement performed
  #define EYE_SAFE            7   // This bit will go high if eye-safety protection has been activated

/*------------------------END REGISTER------------------------*/



/**************************************************************/
/*             MAXIMUM AQUISITION COUNT REGISTER              */
/*                    control_reg[0x2]                        */
/*                     (READ & WRITE)                         */
/**************************************************************/

#define LIDAR_MAX_COUNT     0x2   // Register Address

//  Bits 0 - 7  Maximum Acquisition Count - 0-255. Control the FPGA maximum signal integration time. Stronger signal results in reduced acquisition count to prevent internal register overflow. Sig overflow flag and Ref overflow flag in control register 1 are set  when automatic limiting occurs.


/*------------------------END REGISTER------------------------*/



/**************************************************************/
/*           CORRELATION RECORD LENGTH REGISTER               */
/*                    control_reg[0x3]                        */
/*                     (READ & WRITE)                         */
/**************************************************************/

// control_reg[0x51] is WRITE only version of register

#define LIDAR_CORR_LENGTH   0x3   // Register Address
  /*Bit definitions*/
  #define CORR_START_ADDR   0      // Value in the range from 0x00-0x0f – starting point in correlation record (record broken into 64 element segments 1024 total (Default "1" corresponding to 64)
  #define CORR_STOP_ADDR    4     // Value in the range from 0x00-0x0f – stopping point in correlation record (Default "5" corresponding to 512) TODO: Makesure that's not a typo. 8 * 64 corresponds to 512?

/*
Note: With longer correlation records, burst pulse period is
roughly proportional to the length of the  correlation record.
Unnecessarily long record length increases the probability of
false detections.
*/

/*------------------------END REGISTER------------------------*/



/**************************************************************/
/*             AQUISITION MODE CONTROL REGISTER               */
/*                    control_reg[0x4]                        */
/*                     (READ & WRITE)                         */
/**************************************************************/
#define LIDAR_MODE          0x4   // Acquisition mode control

  /*Bit definitions*/
  #define PREAMP_OFF          0     //Shutdown preamp between measurements
  #define CLK_SHUT            1   //External Clock Shutdown – Not used in standard LidarLite
  #define FPGA_SLEEP          2   //Full FPGA sleep after measurement
  #define DET_OFF             3   //Turns off detector bias after measurement
  // bit 4 not currently used
  #define V_SCALE             5   //“1” sets the velocity measurement separation to 10msec resulting in a velocity calibration in meters/sec. A “0” value results  in a measurement separation of 100msec.
  #define REF_INHIBIT         6 // If “1” inhibits the acquisition of reference pulses reducing measurement times and reducing measurement variations at the  expense of decreasing accuracy over time. “0” allows normal operation
  #define V_ENABLE            7   // Enable velocity measurement

/*------------------------END REGISTER------------------------*/



/**************************************************************/
/*       MEASURED AQUISITION THRESHOLD OFFSET REGISTER        */
/*                    control_reg[0x5]                        */
/*                     (READ & WRITE)                         */
/**************************************************************/

#define LIDAR_THOLD_OFFSET  0x5   // Measured threshold offset during acquisition

// BITS 1-7 Measured DC value out of correlation sampler input. Value based on the ratio of 1’s and 0’s (read only) preamp (Parameter used as part of health flag criteria)

/*------------------------END REGISTER------------------------*/



/**************************************************************/
/*       MEASURED REFERENCE CORRELATION DELAY REGISTERS       */
/*                    control_reg[0x6-7]                      */
/*                     (READ & WRITE)                         */
/**************************************************************/

#define LIDAR_REF_DELAY_H   0x6   // Measured delay of reference in correlation record (HIGH byte)
#define LIDAR_REF_DELAY_L   0x7   // Measured delay of reference in correlation record (LOW byte)

/*------------------------END REGISTER------------------------*/



/**************************************************************/
/*          REFERENCE PEAK CORRELATION VALUE REGISTER         */
/*                    control_reg[0x8]                        */
/*                       (READ ONLY)                          */
/**************************************************************/

#define LIDAR_REF_PEAK      0x8   // Reference correlation measured peak value
  //BITS 1-7 Correlation Peak value reference (scaled to 0 – 0xff max peak value) - (read only)  – Parameter used as part of health flag criteria


/*------------------------END REGISTER------------------------*/



/**************************************************************/
/*            VELOCITY MEASURMENT OUTPUT REGISTER             */
/*                    control_reg[0x9]                        */
/*                       (READ ONLY)                          */
/**************************************************************/

#define LIDAR_VELOCITY_READ 0x9   // Velocity in .1 meters/sec - (read only, 8 bit signed value) See Mode control, Register 4 for information on changing the  scale factor to 1m/sec 


#define LIDAR_CORR_DELAY_H  0xa   //Measured delay of signal return in correlation record (HIGH byte)
#define LIDAR_CORR_DELAY_L  0xb   //Measured delay of signal return in correlation record (LOW byte)
#define LIDAR_CORR_PEAK     0xc   //Signal correlation measured peak value
#define LIDAR_CORR_NOISE    0xd   //Correlation record noise floor * 1.25 (for setting valid signal threshold)
#define LIDAR_SIG_STRENGTH  0xe   //Received signal strength (typical range 10 min - 128 maximum)
#define LIDAR_DIST_READ_H   0xf   //Calculated distance in cm (difference between signal and reference delay) (HIGH Byte)
#define LIDAR_DIST_READ_L   0x10  //Calculated distance in cm (difference between signal and reference delay) (LOW Byte)
#define LIDAR_DIST_READ_HL  0x8f  //Two byte read (Distance High and LOW)
#define LIDAR_DC_THRESHOLD  0x11  //DC threshold command value
#define LIDAR_BURST_DELAY   0x12  //Added delay to reduce signal acquisition burst frequency
#define LIDAR_DISTANCE_CAL  0x13  //Distance calibration. Signed 8 bit value adds or subtracts from distance
#define LIDAR_PREV_DIST_H   0x14  //Previous measured distance (HIGH Byte)
#define LIDAR_PREV_DIST_L   0x15  //Previous measured distance (LOW Byte)


/*####################EXTERNAL REGISTERS######################*/

#define LIDAR_CMD_CTRL      0x40    //Command Control
#define LIDAR_HW_VER        0x41    //Hardware Version
#define LIDAR_PREAMP_CTRL   0x42    //Preamp DC control
#define LIDAR_TX_PWR_CTRL   0x43    //Transmit power control
#define LIDAR_GATE_L        0x44    //Processing range gate (low byte)
#define LIDAR_GATE_H        0x45    //Processing range gate (high byte)
#define LIDAR_PWM_MODE      0x46    //Range Measurement PWM output pin bit[0] used
#define LIDAR_READ_STATUS   0x47    //Acquisition status
#define LIDAR_DC_OFFSET     0x49    //Measured preamp DC offset
#define LIDAR_OUTPUT_PORT   0x4a    //Output port
#define LIDAR_TWO_ECHO      0x4b    //Range Processing Criteria for two echoes. Max signal, Max/Min Range.
#define LIDAR_NXT_LG_PEAK   0x4c    //2nd largest detected peak in signal correlation record.
#define LIDAR_SW_VER        0x4f    //Software Version.
#define LIDAR_CORR_SIZE     0x51    //Correlation record size select – (reference and signal return)
#define LIDAR_CORR_DATA_L   0x52    //Correlation Data access port (low byte)
#define LIDAR_READ_SETTINGS 0x53    //Acquisition Settings – selects ext. memory access, signal record select
#define LIDAR_READ_DELAY_H  0x57    //Measured delay of reference or signal in correlation window
#define LIDAR_READ_DELAY_L  0x58    //Measured delay of reference or signal in correlation window
#define LIDAR_CORR_PEAK_EXT 0x59    //Correlation peak value of reference or signal
#define LIDAR_MAX_NOISE     0x5a    //Correlation record noise floor * 1.25 (for setting valid signal threshold)
#define LIDAR_RSSI          0x5b    //Received signal strength (typical range 10min - 255 maximum)
#define LIDAR_CORR_SIG_PAT  0x5c    //Reset correlator / increment transmit signal pattern
#define LIDAR_CORR_SIGN_BIT 0x5d    //Correlation Data access port (sign bit)
#define LIDAR_READ_TX_PWR   0x5f    //Measured transmit power – Supports Laser safety monitoring
#define LIDAR_FINE_DELAY    0x60    //Measured fine delay (used as part of measured delay calculation)
#define LIDAR_COARSE_DELAY_H 0x61    //Coarse delay (used as part of measured delay calculation)(HIGH Byte)
#define LIDAR_COARSE_DELAY_L 0x62    //Coarse delay (used as part of measured delay calculation)(LOW Byte)
#define LIDAR_POS_CROSS     0x63    //Positive correlation sample before zero crossing (correlation pulse falling edge)
#define LIDAR_NEG_CROSS     0x64    //Negative correlation sample after zero crossing (correlation pulse falling edge)
#define LIDAR_PWR_CTRL      0x65    //Power control settings
#define LIDAR_VELOCITY_CTRL 0x68    //Velocity measurement window setting register
