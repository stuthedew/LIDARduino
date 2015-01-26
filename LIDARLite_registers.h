
#pragma once

//INTERNAL REGISTERS

#define LIDAR_COMMAND       0x0   //Command Register
#define LIDAR_SYS_STATUS    0x1   //Status system status.
#define LIDAR_MAX_COUNT     0x2   //Maximum acquisition count
#define LIDAR_CORR_LENGTH   0x3   //Correlation record length setting
#define LIDAR_MODE          0x4   //Acquisition mode control
#define LIDAR_THOLD_OFFSET  0x5   //Measured threshold offset during acquisition
#define LIDAR_REF_DELAY_H   0x6   //Measured delay of reference in correlation record (HIGH byte)
#define LIDAR_REF_DELAY_H   0x7   //Measured delay of reference in correlation record (LOW byte)
#define LIDAR_REF_PEAK      0x8   //Reference correlation measured peak value
#define LIDAR_VELOCITY_READ 0x9   //Velocity Measurement Output
#define LIDAR_CORR_DELAY_H  0xa   //Measured delay of signal return in correlation record (HIGH byte)
#define LIDAR_CORR_DELAY_L  0xb   //Measured delay of signal return in correlation record (LOW byte)
#define LIDAR_CORR_PEAK     0xc   //Signal correlation measured peak value
#define LIDAR_CORR_NOISE    0xd   //Correlation record noise floor * 1.25 (for setting valid signal threshold)
#define LIDAR_SIG_STRENGTH  0xe   //Received signal strength (typical range 10 min - 128 maximum)
#define LIDAR_DIST_READ_H   0xf   //Calculated distance in cm (difference between signal and reference delay) (HIGH Byte)
#define LIDAR_DIST_READ_L   0x10  //Calculated distance in cm (difference between signal and reference delay) (LOW Byte)
#define LIDAR_DISTANCE_READ 0x8f  //Two byte read (Distance High and LOW)
#define LIDAR_DC_THRESHOLD  0x11  //DC threshold command value
#define LIDAR_BURST_DELAY   0x12  //Added delay to reduce signal acquisition burst frequency
#define LIDAR_DISTANCE_CAL  0x13  //Distance calibration. Signed 8 bit value adds or subtracts from distance
#define LIDAR_PREV_DIST_H   0x14  //Previous measured distance (HIGH Byte)
#define LIDAR_PREV_DIST_L   0x15  //Previous measured distance (LOW Byte)


//EXTERNAL REGISTERS

#define LIDAR_CMD_CTRL      0x40  //Command Control
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
