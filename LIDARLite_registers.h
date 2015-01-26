
#pragma once

//INTERNAL REGISTERS

#define LIDAR_CC            0x0   //Command Control
#define LIDAR_SYS_STATUS    0x1   //Status system status.
#define LIDAR_MAX_COUNT     0x2   //Maximum acquisition count
#define LIDAR_CORR_LENGTH   0x3   //Correlation record length setting
#define LIDAR_MODE          0x4   //Acquisition mode control
#define LIDAR_DC_OFFSET     0x5   //Measured threshold offset during acquisition
#define LIDAR_REF_DELAY_H   0x6   //Measured delay of reference in correlation record (HIGH byte)
#define LIDAR_REF_DELAY_H   0x7   //Measured delay of reference in correlation record (LOW byte)
#define LIDAR_REF_PEAK      0x8   //Reference correlation measured peak value
#define LIDAR_VELOCITY_READ 0x9   //Velocity Measurement Output
#define LIDAR_CORR_DELAY_H  0xa   //Measured delay of signal return in correlation record (HIGH byte)
#define LIDAR_TEMP 0xb   //Measured delay of signal return in correlation record (LOW byte)
#define LIDAR_TEMP 0xc   //Signal correlation measured peak value
#define LIDAR_TEMP 0xd   //Correlation record noise floor * 1.25 (for setting valid signal threshold)
#define LIDAR_TEMP 0xe   //Received signal strength (typical range 10 min - 128 maximum)
#define LIDAR_TEMP 0xf   //Calculated distance in cm (difference between signal and reference delay)
#define LIDAR_TEMP 0x10  //Calculated distance in cm (difference between signal and reference delay)
#define LIDAR_TEMP 0x11  //DC threshold command value
#define LIDAR_TEMP 0x12  //Added delay to reduce signal acquisition burst frequency
#define LIDAR_TEMP 0x13  //Distance calibration. Signed 8 bit value adds or subtracts from distance
#define LIDAR_TEMP 0x14  //Previous measured distance
#define LIDAR_TEMP 0x15  //Previous measured distance


//EXTERNAL REGISTERS

#define LIDAR_TEMP 0x40    //Command register
#define LIDAR_TEMP 0x41    //Hardware Version
#define LIDAR_TEMP 0x42    //Preamp DC control
#define LIDAR_TEMP 0x43    //Transmit power control
#define LIDAR_TEMP 0x44    //Processing range gate (low byte)
#define LIDAR_TEMP 0x45    //Processing range gate (high byte)
#define LIDAR_TEMP 0x46    //Range Measurement PWM output pin bit[0] used
#define LIDAR_TEMP 0x47    //Acquisition status
#define LIDAR_TEMP 0x49    //Measured preamp DC offset
#define LIDAR_TEMP 0x4a    //Output port
#define LIDAR_TEMP 0x4b    //Range Processing Criteria for two echoes. Max signal, Max/Min Range.
#define LIDAR_TEMP 0x4c    //2nd largest detected peak in signal correlation record.
#define LIDAR_TEMP 0x4f    //Software Version.
#define LIDAR_TEMP 0x51    //Correlation record size select – (reference and signal return)
#define LIDAR_TEMP 0x52    //Correlation Data access port (low byte)
#define LIDAR_TEMP 0x53    //Acquisition Settings – selects ext. memory access, signal record select
#define LIDAR_TEMP 0x57    //Measured delay of reference or signal in correlation window
#define LIDAR_TEMP 0x58    //Measured delay of reference or signal in correlation window
#define LIDAR_TEMP 0x59    //Correlation peak value of reference or signal
#define LIDAR_TEMP 0x5a    //Correlation record noise floor * 1.25 (for setting valid signal threshold)
#define LIDAR_TEMP 0x5b    //Received signal strength (typical range 10min - 255 maximum)
#define LIDAR_TEMP 0x5c    //Reset correlator / increment transmit signal pattern
#define LIDAR_TEMP 0x5d    //Correlation Data access port (sign bit)
#define LIDAR_TEMP 0x5e    //Clock synchronizer control
#define LIDAR_TEMP 0x5f    //Measured transmit power – Supports Laser safety monitoring
#define LIDAR_TEMP 0x60    //Measured fine delay (used as part of measured delay calculation)
#define LIDAR_TEMP 0x61    //Coarse delay (used as part of measured delay calculation)
#define LIDAR_TEMP 0x62    //Coarse delay (used as part of measured delay calculation)
#define LIDAR_TEMP 0x63    //Positive correlation sample before zero crossing (correlation pulse falling edge)
#define LIDAR_TEMP 0x64    //Negative correlation sample after zero crossing (correlation pulse falling edge)
#define LIDAR_TEMP 0x65    //Power control settings
#define LIDAR_TEMP 0x68    //Velocity measurement window setting register
