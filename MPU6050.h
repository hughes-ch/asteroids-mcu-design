// I2Cdev library collection - MPU6050 I2C device class
// Based on InvenSense MPU-6050 register map document rev. 2.0, 5/19/2011 (RM-MPU-6000A-00)
// 10/3/2011 by Jeff Rowberg <jeff@rowberg.net>
// Updates should (hopefully) always be available at https://github.com/jrowberg/i2cdevlib
//
// Changelog:
//     ... - ongoing debug release

// NOTE: THIS IS ONLY A PARIAL RELEASE. THIS DEVICE CLASS IS CURRENTLY UNDERGOING ACTIVE
// DEVELOPMENT AND IS STILL MISSING SOME IMPORTANT FEATURES. PLEASE KEEP THIS IN MIND IF
// YOU DECIDE TO USE THIS PARTICULAR CODE FOR ANYTHING.

/* ============================================
I2Cdev device library code is placed under the MIT license
Copyright (c) 2012 Jeff Rowberg

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
===============================================
*/

#ifndef _MPU6050_H_
#define _MPU6050_H_

#include "xil_types.h"
#include "xbasic_types.h"
#include "atv_types.h"

#include <stdint.h>
#define uint8_t u8
#define uint16_t u16
#define uint32_t u32

#define I2C_CLOCK   (400000)


// supporting link:  http://forum.arduino.cc/index.php?&topic=143444.msg1079517#msg1079517
// also: http://forum.arduino.cc/index.php?&topic=141571.msg1062899#msg1062899s

#ifdef __AVR__
#include <avr/pgmspace.h>
#else
//#define PROGMEM /* empty */
//#define pgm_read_byte(x) (*(x))
//#define pgm_read_word(x) (*(x))
//#define pgm_read_float(x) (*(x))
//#define PSTR(STR) STR
#endif


#define MPU6050_ADDRESS_AD0_LOW     0x68 // address pin low (GND), default for InvenSense evaluation board
#define MPU6050_ADDRESS_AD0_HIGH    0x69 // address pin high (VCC)
#define MPU6050_DEFAULT_ADDRESS     MPU6050_ADDRESS_AD0_LOW

#define MPU6050_RA_XG_OFFS_TC       0x00 //[7] PWR_MODE, [6:1] XG_OFFS_TC, [0] OTP_BNK_VLD
#define MPU6050_RA_YG_OFFS_TC       0x01 //[7] PWR_MODE, [6:1] YG_OFFS_TC, [0] OTP_BNK_VLD
#define MPU6050_RA_ZG_OFFS_TC       0x02 //[7] PWR_MODE, [6:1] ZG_OFFS_TC, [0] OTP_BNK_VLD
#define MPU6050_RA_X_FINE_GAIN      0x03 //[7:0] X_FINE_GAIN
#define MPU6050_RA_Y_FINE_GAIN      0x04 //[7:0] Y_FINE_GAIN
#define MPU6050_RA_Z_FINE_GAIN      0x05 //[7:0] Z_FINE_GAIN
#define MPU6050_RA_XA_OFFS_H        0x06 //[15:0] XA_OFFS
#define MPU6050_RA_XA_OFFS_L_TC     0x07
#define MPU6050_RA_YA_OFFS_H        0x08 //[15:0] YA_OFFS
#define MPU6050_RA_YA_OFFS_L_TC     0x09
#define MPU6050_RA_ZA_OFFS_H        0x0A //[15:0] ZA_OFFS
#define MPU6050_RA_ZA_OFFS_L_TC     0x0B
#define MPU6050_RA_SELF_TEST_X      0x0D //[7:5] XA_TEST[4-2], [4:0] XG_TEST[4-0]
#define MPU6050_RA_SELF_TEST_Y      0x0E //[7:5] YA_TEST[4-2], [4:0] YG_TEST[4-0]
#define MPU6050_RA_SELF_TEST_Z      0x0F //[7:5] ZA_TEST[4-2], [4:0] ZG_TEST[4-0]
#define MPU6050_RA_SELF_TEST_A      0x10 //[5:4] XA_TEST[1-0], [3:2] YA_TEST[1-0], [1:0] ZA_TEST[1-0]
#define MPU6050_RA_XG_OFFS_USRH     0x13 //[15:0] XG_OFFS_USR
#define MPU6050_RA_XG_OFFS_USRL     0x14
#define MPU6050_RA_YG_OFFS_USRH     0x15 //[15:0] YG_OFFS_USR
#define MPU6050_RA_YG_OFFS_USRL     0x16
#define MPU6050_RA_ZG_OFFS_USRH     0x17 //[15:0] ZG_OFFS_USR
#define MPU6050_RA_ZG_OFFS_USRL     0x18
#define MPU6050_RA_SMPLRT_DIV       0x19
#define MPU6050_RA_CONFIG           0x1A
#define MPU6050_RA_GYRO_CONFIG      0x1B
#define MPU6050_RA_ACCEL_CONFIG     0x1C
#define MPU6050_RA_FF_THR           0x1D
#define MPU6050_RA_FF_DUR           0x1E
#define MPU6050_RA_MOT_THR          0x1F
#define MPU6050_RA_MOT_DUR          0x20
#define MPU6050_RA_ZRMOT_THR        0x21
#define MPU6050_RA_ZRMOT_DUR        0x22
#define MPU6050_RA_FIFO_EN          0x23
#define MPU6050_RA_I2C_MST_CTRL     0x24
#define MPU6050_RA_I2C_SLV0_ADDR    0x25
#define MPU6050_RA_I2C_SLV0_REG     0x26
#define MPU6050_RA_I2C_SLV0_CTRL    0x27
#define MPU6050_RA_I2C_SLV1_ADDR    0x28
#define MPU6050_RA_I2C_SLV1_REG     0x29
#define MPU6050_RA_I2C_SLV1_CTRL    0x2A
#define MPU6050_RA_I2C_SLV2_ADDR    0x2B
#define MPU6050_RA_I2C_SLV2_REG     0x2C
#define MPU6050_RA_I2C_SLV2_CTRL    0x2D
#define MPU6050_RA_I2C_SLV3_ADDR    0x2E
#define MPU6050_RA_I2C_SLV3_REG     0x2F
#define MPU6050_RA_I2C_SLV3_CTRL    0x30
#define MPU6050_RA_I2C_SLV4_ADDR    0x31
#define MPU6050_RA_I2C_SLV4_REG     0x32
#define MPU6050_RA_I2C_SLV4_DO      0x33
#define MPU6050_RA_I2C_SLV4_CTRL    0x34
#define MPU6050_RA_I2C_SLV4_DI      0x35
#define MPU6050_RA_I2C_MST_STATUS   0x36
#define MPU6050_RA_INT_PIN_CFG      0x37
#define MPU6050_RA_INT_ENABLE       0x38
#define MPU6050_RA_DMP_INT_STATUS   0x39
#define MPU6050_RA_INT_STATUS       0x3A
#define MPU6050_RA_ACCEL_XOUT_H     0x3B
#define MPU6050_RA_ACCEL_XOUT_L     0x3C
#define MPU6050_RA_ACCEL_YOUT_H     0x3D
#define MPU6050_RA_ACCEL_YOUT_L     0x3E
#define MPU6050_RA_ACCEL_ZOUT_H     0x3F
#define MPU6050_RA_ACCEL_ZOUT_L     0x40
#define MPU6050_RA_TEMP_OUT_H       0x41
#define MPU6050_RA_TEMP_OUT_L       0x42
#define MPU6050_RA_GYRO_XOUT_H      0x43
#define MPU6050_RA_GYRO_XOUT_L      0x44
#define MPU6050_RA_GYRO_YOUT_H      0x45
#define MPU6050_RA_GYRO_YOUT_L      0x46
#define MPU6050_RA_GYRO_ZOUT_H      0x47
#define MPU6050_RA_GYRO_ZOUT_L      0x48
#define MPU6050_RA_EXT_SENS_DATA_00 0x49
#define MPU6050_RA_EXT_SENS_DATA_01 0x4A
#define MPU6050_RA_EXT_SENS_DATA_02 0x4B
#define MPU6050_RA_EXT_SENS_DATA_03 0x4C
#define MPU6050_RA_EXT_SENS_DATA_04 0x4D
#define MPU6050_RA_EXT_SENS_DATA_05 0x4E
#define MPU6050_RA_EXT_SENS_DATA_06 0x4F
#define MPU6050_RA_EXT_SENS_DATA_07 0x50
#define MPU6050_RA_EXT_SENS_DATA_08 0x51
#define MPU6050_RA_EXT_SENS_DATA_09 0x52
#define MPU6050_RA_EXT_SENS_DATA_10 0x53
#define MPU6050_RA_EXT_SENS_DATA_11 0x54
#define MPU6050_RA_EXT_SENS_DATA_12 0x55
#define MPU6050_RA_EXT_SENS_DATA_13 0x56
#define MPU6050_RA_EXT_SENS_DATA_14 0x57
#define MPU6050_RA_EXT_SENS_DATA_15 0x58
#define MPU6050_RA_EXT_SENS_DATA_16 0x59
#define MPU6050_RA_EXT_SENS_DATA_17 0x5A
#define MPU6050_RA_EXT_SENS_DATA_18 0x5B
#define MPU6050_RA_EXT_SENS_DATA_19 0x5C
#define MPU6050_RA_EXT_SENS_DATA_20 0x5D
#define MPU6050_RA_EXT_SENS_DATA_21 0x5E
#define MPU6050_RA_EXT_SENS_DATA_22 0x5F
#define MPU6050_RA_EXT_SENS_DATA_23 0x60
#define MPU6050_RA_MOT_DETECT_STATUS    0x61
#define MPU6050_RA_I2C_SLV0_DO      0x63
#define MPU6050_RA_I2C_SLV1_DO      0x64
#define MPU6050_RA_I2C_SLV2_DO      0x65
#define MPU6050_RA_I2C_SLV3_DO      0x66
#define MPU6050_RA_I2C_MST_DELAY_CTRL   0x67
#define MPU6050_RA_SIGNAL_PATH_RESET    0x68
#define MPU6050_RA_MOT_DETECT_CTRL      0x69
#define MPU6050_RA_USER_CTRL        0x6A
#define MPU6050_RA_PWR_MGMT_1       0x6B
#define MPU6050_RA_PWR_MGMT_2       0x6C
#define MPU6050_RA_BANK_SEL         0x6D
#define MPU6050_RA_MEM_START_ADDR   0x6E
#define MPU6050_RA_MEM_R_W          0x6F
#define MPU6050_RA_DMP_CFG_1        0x70
#define MPU6050_RA_DMP_CFG_2        0x71
#define MPU6050_RA_FIFO_COUNTH      0x72
#define MPU6050_RA_FIFO_COUNTL      0x73
#define MPU6050_RA_FIFO_R_W         0x74
#define MPU6050_RA_WHO_AM_I         0x75

#define MPU6050_SELF_TEST_XA_1_BIT     0x07
#define MPU6050_SELF_TEST_XA_1_LENGTH  0x03
#define MPU6050_SELF_TEST_XA_2_BIT     0x05
#define MPU6050_SELF_TEST_XA_2_LENGTH  0x02
#define MPU6050_SELF_TEST_YA_1_BIT     0x07
#define MPU6050_SELF_TEST_YA_1_LENGTH  0x03
#define MPU6050_SELF_TEST_YA_2_BIT     0x03
#define MPU6050_SELF_TEST_YA_2_LENGTH  0x02
#define MPU6050_SELF_TEST_ZA_1_BIT     0x07
#define MPU6050_SELF_TEST_ZA_1_LENGTH  0x03
#define MPU6050_SELF_TEST_ZA_2_BIT     0x01
#define MPU6050_SELF_TEST_ZA_2_LENGTH  0x02

#define MPU6050_SELF_TEST_XG_1_BIT     0x04
#define MPU6050_SELF_TEST_XG_1_LENGTH  0x05
#define MPU6050_SELF_TEST_YG_1_BIT     0x04
#define MPU6050_SELF_TEST_YG_1_LENGTH  0x05
#define MPU6050_SELF_TEST_ZG_1_BIT     0x04
#define MPU6050_SELF_TEST_ZG_1_LENGTH  0x05

#define MPU6050_TC_PWR_MODE_BIT     7
#define MPU6050_TC_OFFSET_BIT       6
#define MPU6050_TC_OFFSET_LENGTH    6
#define MPU6050_TC_OTP_BNK_VLD_BIT  0

#define MPU6050_VDDIO_LEVEL_VLOGIC  0
#define MPU6050_VDDIO_LEVEL_VDD     1

#define MPU6050_CFG_EXT_SYNC_SET_BIT    5
#define MPU6050_CFG_EXT_SYNC_SET_LENGTH 3
#define MPU6050_CFG_DLPF_CFG_BIT    2
#define MPU6050_CFG_DLPF_CFG_LENGTH 3

#define MPU6050_EXT_SYNC_DISABLED       0x0
#define MPU6050_EXT_SYNC_TEMP_OUT_L     0x1
#define MPU6050_EXT_SYNC_GYRO_XOUT_L    0x2
#define MPU6050_EXT_SYNC_GYRO_YOUT_L    0x3
#define MPU6050_EXT_SYNC_GYRO_ZOUT_L    0x4
#define MPU6050_EXT_SYNC_ACCEL_XOUT_L   0x5
#define MPU6050_EXT_SYNC_ACCEL_YOUT_L   0x6
#define MPU6050_EXT_SYNC_ACCEL_ZOUT_L   0x7

#define MPU6050_DLPF_BW_256         0x00
#define MPU6050_DLPF_BW_188         0x01
#define MPU6050_DLPF_BW_98          0x02
#define MPU6050_DLPF_BW_42          0x03
#define MPU6050_DLPF_BW_20          0x04
#define MPU6050_DLPF_BW_10          0x05
#define MPU6050_DLPF_BW_5           0x06

#define MPU6050_GCONFIG_FS_SEL_BIT      4
#define MPU6050_GCONFIG_FS_SEL_LENGTH   2

#define MPU6050_GYRO_FS_250         0x00
#define MPU6050_GYRO_FS_500         0x01
#define MPU6050_GYRO_FS_1000        0x02
#define MPU6050_GYRO_FS_2000        0x03

#define MPU6050_ACONFIG_XA_ST_BIT           7
#define MPU6050_ACONFIG_YA_ST_BIT           6
#define MPU6050_ACONFIG_ZA_ST_BIT           5
#define MPU6050_ACONFIG_AFS_SEL_BIT         4
#define MPU6050_ACONFIG_AFS_SEL_LENGTH      2
#define MPU6050_ACONFIG_ACCEL_HPF_BIT       2
#define MPU6050_ACONFIG_ACCEL_HPF_LENGTH    3

#define MPU6050_ACCEL_FS_2          0x00
#define MPU6050_ACCEL_FS_4          0x01
#define MPU6050_ACCEL_FS_8          0x02
#define MPU6050_ACCEL_FS_16         0x03

#define MPU6050_DHPF_RESET          0x00
#define MPU6050_DHPF_5              0x01
#define MPU6050_DHPF_2P5            0x02
#define MPU6050_DHPF_1P25           0x03
#define MPU6050_DHPF_0P63           0x04
#define MPU6050_DHPF_HOLD           0x07

#define MPU6050_TEMP_FIFO_EN_BIT    7
#define MPU6050_XG_FIFO_EN_BIT      6
#define MPU6050_YG_FIFO_EN_BIT      5
#define MPU6050_ZG_FIFO_EN_BIT      4
#define MPU6050_ACCEL_FIFO_EN_BIT   3
#define MPU6050_SLV2_FIFO_EN_BIT    2
#define MPU6050_SLV1_FIFO_EN_BIT    1
#define MPU6050_SLV0_FIFO_EN_BIT    0

#define MPU6050_MULT_MST_EN_BIT     7
#define MPU6050_WAIT_FOR_ES_BIT     6
#define MPU6050_SLV_3_FIFO_EN_BIT   5
#define MPU6050_I2C_MST_P_NSR_BIT   4
#define MPU6050_I2C_MST_CLK_BIT     3
#define MPU6050_I2C_MST_CLK_LENGTH  4

#define MPU6050_CLOCK_DIV_348       0x0
#define MPU6050_CLOCK_DIV_333       0x1
#define MPU6050_CLOCK_DIV_320       0x2
#define MPU6050_CLOCK_DIV_308       0x3
#define MPU6050_CLOCK_DIV_296       0x4
#define MPU6050_CLOCK_DIV_286       0x5
#define MPU6050_CLOCK_DIV_276       0x6
#define MPU6050_CLOCK_DIV_267       0x7
#define MPU6050_CLOCK_DIV_258       0x8
#define MPU6050_CLOCK_DIV_500       0x9
#define MPU6050_CLOCK_DIV_471       0xA
#define MPU6050_CLOCK_DIV_444       0xB
#define MPU6050_CLOCK_DIV_421       0xC
#define MPU6050_CLOCK_DIV_400       0xD
#define MPU6050_CLOCK_DIV_381       0xE
#define MPU6050_CLOCK_DIV_364       0xF

#define MPU6050_I2C_SLV_RW_BIT      7
#define MPU6050_I2C_SLV_ADDR_BIT    6
#define MPU6050_I2C_SLV_ADDR_LENGTH 7
#define MPU6050_I2C_SLV_EN_BIT      7
#define MPU6050_I2C_SLV_BYTE_SW_BIT 6
#define MPU6050_I2C_SLV_REG_DIS_BIT 5
#define MPU6050_I2C_SLV_GRP_BIT     4
#define MPU6050_I2C_SLV_LEN_BIT     3
#define MPU6050_I2C_SLV_LEN_LENGTH  4

#define MPU6050_I2C_SLV4_RW_BIT         7
#define MPU6050_I2C_SLV4_ADDR_BIT       6
#define MPU6050_I2C_SLV4_ADDR_LENGTH    7
#define MPU6050_I2C_SLV4_EN_BIT         7
#define MPU6050_I2C_SLV4_INT_EN_BIT     6
#define MPU6050_I2C_SLV4_REG_DIS_BIT    5
#define MPU6050_I2C_SLV4_MST_DLY_BIT    4
#define MPU6050_I2C_SLV4_MST_DLY_LENGTH 5

#define MPU6050_MST_PASS_THROUGH_BIT    7
#define MPU6050_MST_I2C_SLV4_DONE_BIT   6
#define MPU6050_MST_I2C_LOST_ARB_BIT    5
#define MPU6050_MST_I2C_SLV4_NACK_BIT   4
#define MPU6050_MST_I2C_SLV3_NACK_BIT   3
#define MPU6050_MST_I2C_SLV2_NACK_BIT   2
#define MPU6050_MST_I2C_SLV1_NACK_BIT   1
#define MPU6050_MST_I2C_SLV0_NACK_BIT   0

#define MPU6050_INTCFG_INT_LEVEL_BIT        7
#define MPU6050_INTCFG_INT_OPEN_BIT         6
#define MPU6050_INTCFG_LATCH_INT_EN_BIT     5
#define MPU6050_INTCFG_INT_RD_CLEAR_BIT     4
#define MPU6050_INTCFG_FSYNC_INT_LEVEL_BIT  3
#define MPU6050_INTCFG_FSYNC_INT_EN_BIT     2
#define MPU6050_INTCFG_I2C_BYPASS_EN_BIT    1
#define MPU6050_INTCFG_CLKOUT_EN_BIT        0

#define MPU6050_INTMODE_ACTIVEHIGH  0x00
#define MPU6050_INTMODE_ACTIVELOW   0x01

#define MPU6050_INTDRV_PUSHPULL     0x00
#define MPU6050_INTDRV_OPENDRAIN    0x01

#define MPU6050_INTLATCH_50USPULSE  0x00
#define MPU6050_INTLATCH_WAITCLEAR  0x01

#define MPU6050_INTCLEAR_STATUSREAD 0x00
#define MPU6050_INTCLEAR_ANYREAD    0x01

#define MPU6050_INTERRUPT_FF_BIT            7
#define MPU6050_INTERRUPT_MOT_BIT           6
#define MPU6050_INTERRUPT_ZMOT_BIT          5
#define MPU6050_INTERRUPT_FIFO_OFLOW_BIT    4
#define MPU6050_INTERRUPT_I2C_MST_INT_BIT   3
#define MPU6050_INTERRUPT_PLL_RDY_INT_BIT   2
#define MPU6050_INTERRUPT_DMP_INT_BIT       1
#define MPU6050_INTERRUPT_DATA_RDY_BIT      0

// TODO: figure out what these actually do
// UMPL source code is not very obivous
#define MPU6050_DMPINT_5_BIT            5
#define MPU6050_DMPINT_4_BIT            4
#define MPU6050_DMPINT_3_BIT            3
#define MPU6050_DMPINT_2_BIT            2
#define MPU6050_DMPINT_1_BIT            1
#define MPU6050_DMPINT_0_BIT            0

#define MPU6050_MOTION_MOT_XNEG_BIT     7
#define MPU6050_MOTION_MOT_XPOS_BIT     6
#define MPU6050_MOTION_MOT_YNEG_BIT     5
#define MPU6050_MOTION_MOT_YPOS_BIT     4
#define MPU6050_MOTION_MOT_ZNEG_BIT     3
#define MPU6050_MOTION_MOT_ZPOS_BIT     2
#define MPU6050_MOTION_MOT_ZRMOT_BIT    0

#define MPU6050_DELAYCTRL_DELAY_ES_SHADOW_BIT   7
#define MPU6050_DELAYCTRL_I2C_SLV4_DLY_EN_BIT   4
#define MPU6050_DELAYCTRL_I2C_SLV3_DLY_EN_BIT   3
#define MPU6050_DELAYCTRL_I2C_SLV2_DLY_EN_BIT   2
#define MPU6050_DELAYCTRL_I2C_SLV1_DLY_EN_BIT   1
#define MPU6050_DELAYCTRL_I2C_SLV0_DLY_EN_BIT   0

#define MPU6050_PATHRESET_GYRO_RESET_BIT    2
#define MPU6050_PATHRESET_ACCEL_RESET_BIT   1
#define MPU6050_PATHRESET_TEMP_RESET_BIT    0

#define MPU6050_DETECT_ACCEL_ON_DELAY_BIT       5
#define MPU6050_DETECT_ACCEL_ON_DELAY_LENGTH    2
#define MPU6050_DETECT_FF_COUNT_BIT             3
#define MPU6050_DETECT_FF_COUNT_LENGTH          2
#define MPU6050_DETECT_MOT_COUNT_BIT            1
#define MPU6050_DETECT_MOT_COUNT_LENGTH         2

#define MPU6050_DETECT_DECREMENT_RESET  0x0
#define MPU6050_DETECT_DECREMENT_1      0x1
#define MPU6050_DETECT_DECREMENT_2      0x2
#define MPU6050_DETECT_DECREMENT_4      0x3

#define MPU6050_USERCTRL_DMP_EN_BIT             7
#define MPU6050_USERCTRL_FIFO_EN_BIT            6
#define MPU6050_USERCTRL_I2C_MST_EN_BIT         5
#define MPU6050_USERCTRL_I2C_IF_DIS_BIT         4
#define MPU6050_USERCTRL_DMP_RESET_BIT          3
#define MPU6050_USERCTRL_FIFO_RESET_BIT         2
#define MPU6050_USERCTRL_I2C_MST_RESET_BIT      1
#define MPU6050_USERCTRL_SIG_COND_RESET_BIT     0

#define MPU6050_PWR1_DEVICE_RESET_BIT   7
#define MPU6050_PWR1_SLEEP_BIT          6
#define MPU6050_PWR1_CYCLE_BIT          5
#define MPU6050_PWR1_TEMP_DIS_BIT       3
#define MPU6050_PWR1_CLKSEL_BIT         2
#define MPU6050_PWR1_CLKSEL_LENGTH      3

#define MPU6050_CLOCK_INTERNAL          0x00
#define MPU6050_CLOCK_PLL_XGYRO         0x01
#define MPU6050_CLOCK_PLL_YGYRO         0x02
#define MPU6050_CLOCK_PLL_ZGYRO         0x03
#define MPU6050_CLOCK_PLL_EXT32K        0x04
#define MPU6050_CLOCK_PLL_EXT19M        0x05
#define MPU6050_CLOCK_KEEP_RESET        0x07

#define MPU6050_PWR2_LP_WAKE_CTRL_BIT       7
#define MPU6050_PWR2_LP_WAKE_CTRL_LENGTH    2
#define MPU6050_PWR2_STBY_XA_BIT            5
#define MPU6050_PWR2_STBY_YA_BIT            4
#define MPU6050_PWR2_STBY_ZA_BIT            3
#define MPU6050_PWR2_STBY_XG_BIT            2
#define MPU6050_PWR2_STBY_YG_BIT            1
#define MPU6050_PWR2_STBY_ZG_BIT            0

#define MPU6050_WAKE_FREQ_1P25      0x0
#define MPU6050_WAKE_FREQ_2P5       0x1
#define MPU6050_WAKE_FREQ_5         0x2
#define MPU6050_WAKE_FREQ_10        0x3

#define MPU6050_BANKSEL_PRFTCH_EN_BIT       6
#define MPU6050_BANKSEL_CFG_USER_BANK_BIT   5
#define MPU6050_BANKSEL_MEM_SEL_BIT         4
#define MPU6050_BANKSEL_MEM_SEL_LENGTH      5

#define MPU6050_WHO_AM_I_BIT        6
#define MPU6050_WHO_AM_I_LENGTH     6

#define MPU6050_DMP_MEMORY_BANKS        8
#define MPU6050_DMP_MEMORY_BANK_SIZE    256
#define MPU6050_DMP_MEMORY_CHUNK_SIZE   16

// note: DMP code memory blocks defined at end of header file

typedef struct {
  uint8_t devAddr;
  uint8_t buffer[14];
}MPU6050_t;

void MPU6050_initialize(MPU6050_t* this);
BOOL MPU6050_testConnection(MPU6050_t* this);

// AUX_VDDIO register
uint8_t MPU6050_getAuxVDDIOLevel(MPU6050_t* this);
void MPU6050_setAuxVDDIOLevel(MPU6050_t* this, uint8_t level);

// SMPLRT_DIV register
uint8_t MPU6050_getRate(MPU6050_t* this);
void MPU6050_setRate(MPU6050_t* this, uint8_t rate);

// CONFIG register
uint8_t MPU6050_getExternalFrameSync(MPU6050_t* this);
void MPU6050_setExternalFrameSync(MPU6050_t* this, uint8_t sync);
uint8_t MPU6050_getDLPFMode(MPU6050_t* this);
void MPU6050_setDLPFMode(MPU6050_t* this, uint8_t bandwidth);

// GYRO_CONFIG register
uint8_t MPU6050_getFullScaleGyroRange(MPU6050_t* this);
void MPU6050_setFullScaleGyroRange(MPU6050_t* this, uint8_t range);

// SELF_TEST registers
uint8_t MPU6050_getAccelXSelfTestFactoryTrim(MPU6050_t* this);
uint8_t MPU6050_getAccelYSelfTestFactoryTrim(MPU6050_t* this);
uint8_t MPU6050_getAccelZSelfTestFactoryTrim(MPU6050_t* this);

uint8_t MPU6050_getGyroXSelfTestFactoryTrim(MPU6050_t* this);
uint8_t MPU6050_getGyroYSelfTestFactoryTrim(MPU6050_t* this);
uint8_t MPU6050_getGyroZSelfTestFactoryTrim(MPU6050_t* this);

// ACCEL_CONFIG register
BOOL MPU6050_getAccelXSelfTest(MPU6050_t* this);
void MPU6050_setAccelXSelfTest(MPU6050_t* this, BOOL enabled);
BOOL MPU6050_getAccelYSelfTest(MPU6050_t* this);
void MPU6050_setAccelYSelfTest(MPU6050_t* this, BOOL enabled);
BOOL MPU6050_getAccelZSelfTest(MPU6050_t* this);
void MPU6050_setAccelZSelfTest(MPU6050_t* this, BOOL enabled);
uint8_t MPU6050_getFullScaleAccelRange(MPU6050_t* this);
void MPU6050_setFullScaleAccelRange(MPU6050_t* this, uint8_t range);
uint8_t MPU6050_getDHPFMode(MPU6050_t* this);
void MPU6050_setDHPFMode(MPU6050_t* this, uint8_t mode);

// FF_THR register
uint8_t MPU6050_getFreefallDetectionThreshold(MPU6050_t* this);
void MPU6050_setFreefallDetectionThreshold(MPU6050_t* this, uint8_t threshold);

// FF_DUR register
uint8_t MPU6050_getFreefallDetectionDuration(MPU6050_t* this);
void MPU6050_setFreefallDetectionDuration(MPU6050_t* this, uint8_t duration);

// MOT_THR register
uint8_t MPU6050_getMotionDetectionThreshold(MPU6050_t* this);
void MPU6050_setMotionDetectionThreshold(MPU6050_t* this, uint8_t threshold);

// MOT_DUR register
uint8_t MPU6050_getMotionDetectionDuration(MPU6050_t* this);
void MPU6050_setMotionDetectionDuration(MPU6050_t* this, uint8_t duration);

// ZRMOT_THR register
uint8_t MPU6050_getZeroMotionDetectionThreshold(MPU6050_t* this);
void MPU6050_setZeroMotionDetectionThreshold(MPU6050_t* this, uint8_t threshold);

// ZRMOT_DUR register
uint8_t MPU6050_getZeroMotionDetectionDuration(MPU6050_t* this);
void MPU6050_setZeroMotionDetectionDuration(MPU6050_t* this, uint8_t duration);

// FIFO_EN register
BOOL MPU6050_getTempFIFOEnabled(MPU6050_t* this);
void MPU6050_setTempFIFOEnabled(MPU6050_t* this, BOOL enabled);
BOOL MPU6050_getXGyroFIFOEnabled(MPU6050_t* this);
void MPU6050_setXGyroFIFOEnabled(MPU6050_t* this, BOOL enabled);
BOOL MPU6050_getYGyroFIFOEnabled(MPU6050_t* this);
void MPU6050_setYGyroFIFOEnabled(MPU6050_t* this, BOOL enabled);
BOOL MPU6050_getZGyroFIFOEnabled(MPU6050_t* this);
void MPU6050_setZGyroFIFOEnabled(MPU6050_t* this, BOOL enabled);
BOOL MPU6050_getAccelFIFOEnabled(MPU6050_t* this);
void MPU6050_setAccelFIFOEnabled(MPU6050_t* this, BOOL enabled);
BOOL MPU6050_getSlave2FIFOEnabled(MPU6050_t* this);
void MPU6050_setSlave2FIFOEnabled(MPU6050_t* this, BOOL enabled);
BOOL MPU6050_getSlave1FIFOEnabled(MPU6050_t* this);
void MPU6050_setSlave1FIFOEnabled(MPU6050_t* this, BOOL enabled);
BOOL MPU6050_getSlave0FIFOEnabled(MPU6050_t* this);
void MPU6050_setSlave0FIFOEnabled(MPU6050_t* this, BOOL enabled);

// I2C_MST_CTRL register
BOOL MPU6050_getMultiMasterEnabled(MPU6050_t* this);
void MPU6050_setMultiMasterEnabled(MPU6050_t* this, BOOL enabled);
BOOL MPU6050_getWaitForExternalSensorEnabled(MPU6050_t* this);
void MPU6050_setWaitForExternalSensorEnabled(MPU6050_t* this, BOOL enabled);
BOOL MPU6050_getSlave3FIFOEnabled(MPU6050_t* this);
void MPU6050_setSlave3FIFOEnabled(MPU6050_t* this, BOOL enabled);
BOOL MPU6050_getSlaveReadWriteTransitionEnabled(MPU6050_t* this);
void MPU6050_setSlaveReadWriteTransitionEnabled(MPU6050_t* this, BOOL enabled);
uint8_t MPU6050_getMasterClockSpeed(MPU6050_t* this);
void MPU6050_setMasterClockSpeed(MPU6050_t* this, uint8_t speed);

// I2C_SLV* registers (Slave 0-3)
uint8_t MPU6050_getSlaveAddress(MPU6050_t* this, uint8_t num);
void MPU6050_setSlaveAddress(MPU6050_t* this, uint8_t num, uint8_t address);
uint8_t MPU6050_getSlaveRegister(MPU6050_t* this, uint8_t num);
void MPU6050_setSlaveRegister(MPU6050_t* this, uint8_t num, uint8_t reg);
BOOL MPU6050_getSlaveEnabled(MPU6050_t* this, uint8_t num);
void MPU6050_setSlaveEnabled(MPU6050_t* this, uint8_t num, BOOL enabled);
BOOL MPU6050_getSlaveWordByteSwap(MPU6050_t* this, uint8_t num);
void MPU6050_setSlaveWordByteSwap(MPU6050_t* this, uint8_t num, BOOL enabled);
BOOL MPU6050_getSlaveWriteMode(MPU6050_t* this, uint8_t num);
void MPU6050_setSlaveWriteMode(MPU6050_t* this, uint8_t num, BOOL mode);
BOOL MPU6050_getSlaveWordGroupOffset(MPU6050_t* this, uint8_t num);
void MPU6050_setSlaveWordGroupOffset(MPU6050_t* this, uint8_t num, BOOL enabled);
uint8_t MPU6050_getSlaveDataLength(MPU6050_t* this, uint8_t num);
void MPU6050_setSlaveDataLength(MPU6050_t* this, uint8_t num, uint8_t length);

// I2C_SLV* registers (MPU6050_t* thisSlave 4)
uint8_t MPU6050_getSlave4Address(MPU6050_t* this);
void MPU6050_setSlave4Address(MPU6050_t* this, uint8_t address);
uint8_t MPU6050_getSlave4Register(MPU6050_t* this);
void MPU6050_setSlave4Register(MPU6050_t* this, uint8_t reg);
void MPU6050_setSlave4OutputByte(MPU6050_t* this, uint8_t data);
BOOL MPU6050_getSlave4Enabled(MPU6050_t* this);
void MPU6050_setSlave4Enabled(MPU6050_t* this, BOOL enabled);
BOOL MPU6050_getSlave4InterruptEnabled(MPU6050_t* this);
void MPU6050_setSlave4InterruptEnabled(MPU6050_t* this, BOOL enabled);
BOOL MPU6050_getSlave4WriteMode(MPU6050_t* this);
void MPU6050_setSlave4WriteMode(MPU6050_t* this, BOOL mode);
uint8_t MPU6050_getSlave4MasterDelay(MPU6050_t* this);
void MPU6050_setSlave4MasterDelay(MPU6050_t* this, uint8_t delay);
uint8_t MPU6050_getSlate4InputByte(MPU6050_t* this);

// I2C_MST_STATUS register
BOOL MPU6050_getPassthroughStatus(MPU6050_t* this);
BOOL MPU6050_getSlave4IsDone(MPU6050_t* this);
BOOL MPU6050_getLostArbitration(MPU6050_t* this);
BOOL MPU6050_getSlave4Nack(MPU6050_t* this);
BOOL MPU6050_getSlave3Nack(MPU6050_t* this);
BOOL MPU6050_getSlave2Nack(MPU6050_t* this);
BOOL MPU6050_getSlave1Nack(MPU6050_t* this);
BOOL MPU6050_getSlave0Nack(MPU6050_t* this);

// INT_PIN_CFG register
BOOL MPU6050_getInterruptMode(MPU6050_t* this);
void MPU6050_setInterruptMode(MPU6050_t* this, BOOL mode);
BOOL MPU6050_getInterruptDrive(MPU6050_t* this);
void MPU6050_setInterruptDrive(MPU6050_t* this, BOOL drive);
BOOL MPU6050_getInterruptLatch(MPU6050_t* this);
void MPU6050_setInterruptLatch(MPU6050_t* this, BOOL latch);
BOOL MPU6050_getInterruptLatchClear(MPU6050_t* this);
void MPU6050_setInterruptLatchClear(MPU6050_t* this, BOOL clear);
BOOL MPU6050_getFSyncInterruptLevel(MPU6050_t* this);
void MPU6050_setFSyncInterruptLevel(MPU6050_t* this, BOOL level);
BOOL MPU6050_getFSyncInterruptEnabled(MPU6050_t* this);
void MPU6050_setFSyncInterruptEnabled(MPU6050_t* this, BOOL enabled);
BOOL MPU6050_getI2CBypassEnabled(MPU6050_t* this);
void MPU6050_setI2CBypassEnabled(MPU6050_t* this, BOOL enabled);
BOOL MPU6050_getClockOutputEnabled(MPU6050_t* this);
void MPU6050_setClockOutputEnabled(MPU6050_t* this, BOOL enabled);

// INT_ENABLE register
uint8_t MPU6050_getIntEnabled(MPU6050_t* this);
void MPU6050_setIntEnabled(MPU6050_t* this, uint8_t enabled);
BOOL MPU6050_getIntFreefallEnabled(MPU6050_t* this);
void MPU6050_setIntFreefallEnabled(MPU6050_t* this, BOOL enabled);
BOOL MPU6050_getIntMotionEnabled(MPU6050_t* this);
void MPU6050_setIntMotionEnabled(MPU6050_t* this, BOOL enabled);
BOOL MPU6050_getIntZeroMotionEnabled(MPU6050_t* this);
void MPU6050_setIntZeroMotionEnabled(MPU6050_t* this, BOOL enabled);
BOOL MPU6050_getIntFIFOBufferOverflowEnabled(MPU6050_t* this);
void MPU6050_setIntFIFOBufferOverflowEnabled(MPU6050_t* this, BOOL enabled);
BOOL MPU6050_getIntI2CMasterEnabled(MPU6050_t* this);
void MPU6050_setIntI2CMasterEnabled(MPU6050_t* this, BOOL enabled);
BOOL MPU6050_getIntDataReadyEnabled(MPU6050_t* this);
void MPU6050_setIntDataReadyEnabled(MPU6050_t* this, BOOL enabled);

// INT_STATUS register
uint8_t MPU6050_getIntStatus(MPU6050_t* this);
BOOL MPU6050_getIntFreefallStatus(MPU6050_t* this);
BOOL MPU6050_getIntMotionStatus(MPU6050_t* this);
BOOL MPU6050_getIntZeroMotionStatus(MPU6050_t* this);
BOOL MPU6050_getIntFIFOBufferOverflowStatus(MPU6050_t* this);
BOOL MPU6050_getIntI2CMasterStatus(MPU6050_t* this);
BOOL MPU6050_getIntDataReadyStatus(MPU6050_t* this);

// ACCEL_*OUT_* registers
void MPU6050_getMotion9(MPU6050_t* this, int16_t* ax, int16_t* ay, int16_t* az, int16_t* gx, int16_t* gy, int16_t* gz, int16_t* mx, int16_t* my, int16_t* mz);
void MPU6050_getMotion6(MPU6050_t* this, int16_t* ax, int16_t* ay, int16_t* az, int16_t* gx, int16_t* gy, int16_t* gz);
void MPU6050_getAcceleration(MPU6050_t* this, int16_t* x, int16_t* y, int16_t* z);
int16_t MPU6050_getAccelerationX(MPU6050_t* this);
int16_t MPU6050_getAccelerationY(MPU6050_t* this);
int16_t MPU6050_getAccelerationZ(MPU6050_t* this);

// TEMP_OUT_* registers
int16_t MPU6050_getTemperature(MPU6050_t* this);

// GYRO_*OUT_* registers
void MPU6050_getRotation(MPU6050_t* this, int16_t* x, int16_t* y, int16_t* z);
int16_t MPU6050_getRotationX(MPU6050_t* this);
int16_t MPU6050_getRotationY(MPU6050_t* this);
int16_t MPU6050_getRotationZ(MPU6050_t* this);

// EXT_SENS_DATA_* registers
uint8_t MPU6050_getExternalSensorByte(MPU6050_t* this, int position);
uint16_t MPU6050_getExternalSensorWord(MPU6050_t* this, int position);
uint32_t MPU6050_getExternalSensorDWord(MPU6050_t* this, int position);

// MOT_DETECT_STATUS register
uint8_t MPU6050_getMotionStatus(MPU6050_t* this);
BOOL MPU6050_getXNegMotionDetected(MPU6050_t* this);
BOOL MPU6050_getXPosMotionDetected(MPU6050_t* this);
BOOL MPU6050_getYNegMotionDetected(MPU6050_t* this);
BOOL MPU6050_getYPosMotionDetected(MPU6050_t* this);
BOOL MPU6050_getZNegMotionDetected(MPU6050_t* this);
BOOL MPU6050_getZPosMotionDetected(MPU6050_t* this);
BOOL MPU6050_getZeroMotionDetected(MPU6050_t* this);

// I2C_SLV*_DO register
void MPU6050_setSlaveOutputByte(MPU6050_t* this, uint8_t num, uint8_t data);

// I2C_MST_DELAY_CTRL register
BOOL MPU6050_getExternalShadowDelayEnabled(MPU6050_t* this);
void MPU6050_setExternalShadowDelayEnabled(MPU6050_t* this, BOOL enabled);
BOOL MPU6050_getSlaveDelayEnabled(MPU6050_t* this, uint8_t num);
void MPU6050_setSlaveDelayEnabled(MPU6050_t* this, uint8_t num, BOOL enabled);

// SIGNAL_PATH_RESET register
void MPU6050_resetGyroscopePath(MPU6050_t* this);
void MPU6050_resetAccelerometerPath(MPU6050_t* this);
void MPU6050_resetTemperaturePath(MPU6050_t* this);

// MOT_DETECT_CTRL register
uint8_t MPU6050_getAccelerometerPowerOnDelay(MPU6050_t* this);
void MPU6050_setAccelerometerPowerOnDelay(MPU6050_t* this, uint8_t delay);
uint8_t MPU6050_getFreefallDetectionCounterDecrement(MPU6050_t* this);
void MPU6050_setFreefallDetectionCounterDecrement(MPU6050_t* this, uint8_t decrement);
uint8_t MPU6050_getMotionDetectionCounterDecrement(MPU6050_t* this);
void MPU6050_setMotionDetectionCounterDecrement(MPU6050_t* this, uint8_t decrement);

// USER_CTRL register
BOOL MPU6050_getFIFOEnabled(MPU6050_t* this);
void MPU6050_setFIFOEnabled(MPU6050_t* this, BOOL enabled);
BOOL MPU6050_getI2CMasterModeEnabled(MPU6050_t* this);
void MPU6050_setI2CMasterModeEnabled(MPU6050_t* this, BOOL enabled);
void MPU6050_switchSPIEnabled(MPU6050_t* this, BOOL enabled);
void MPU6050_resetFIFO(MPU6050_t* this);
void MPU6050_resetI2CMaster(MPU6050_t* this);
void MPU6050_resetSensors(MPU6050_t* this);

// PWR_MGMT_1 register
void MPU6050_reset(MPU6050_t* this);
BOOL MPU6050_getSleepEnabled(MPU6050_t* this);
void MPU6050_setSleepEnabled(MPU6050_t* this, BOOL enabled);
BOOL MPU6050_getWakeCycleEnabled(MPU6050_t* this);
void MPU6050_setWakeCycleEnabled(MPU6050_t* this, BOOL enabled);
BOOL MPU6050_getTempSensorEnabled(MPU6050_t* this);
void MPU6050_setTempSensorEnabled(MPU6050_t* this, BOOL enabled);
uint8_t MPU6050_getClockSource(MPU6050_t* this);
void MPU6050_setClockSource(MPU6050_t* this, uint8_t source);

// PWR_MGMT_2 register
uint8_t MPU6050_getWakeFrequency(MPU6050_t* this);
void MPU6050_setWakeFrequency(MPU6050_t* this, uint8_t frequency);
BOOL MPU6050_getStandbyXAccelEnabled(MPU6050_t* this);
void MPU6050_setStandbyXAccelEnabled(MPU6050_t* this, BOOL enabled);
BOOL MPU6050_getStandbyYAccelEnabled(MPU6050_t* this);
void MPU6050_setStandbyYAccelEnabled(MPU6050_t* this, BOOL enabled);
BOOL MPU6050_getStandbyZAccelEnabled(MPU6050_t* this);
void MPU6050_setStandbyZAccelEnabled(MPU6050_t* this, BOOL enabled);
BOOL MPU6050_getStandbyXGyroEnabled(MPU6050_t* this);
void MPU6050_setStandbyXGyroEnabled(MPU6050_t* this, BOOL enabled);
BOOL MPU6050_getStandbyYGyroEnabled(MPU6050_t* this);
void MPU6050_setStandbyYGyroEnabled(MPU6050_t* this, BOOL enabled);
BOOL MPU6050_getStandbyZGyroEnabled(MPU6050_t* this);
void MPU6050_setStandbyZGyroEnabled(MPU6050_t* this, BOOL enabled);

// FIFO_COUNT_* registers
uint16_t MPU6050_getFIFOCount(MPU6050_t* this);

// FIFO_R_W register
uint8_t MPU6050_getFIFOByte(MPU6050_t* this);
void MPU6050_setFIFOByte(MPU6050_t* this, uint8_t data);
void MPU6050_getFIFOBytes(MPU6050_t* this, uint8_t *data, uint8_t length);

// WHO_AM_I register
uint8_t MPU6050_getDeviceID(MPU6050_t* this);
void MPU6050_setDeviceID(MPU6050_t* this, uint8_t id);

// ======== UNDOCUMENTED/DMP REGISTERS/METHODS ========

// XG_OFFS_TC register
uint8_t MPU6050_getOTPBankValid(MPU6050_t* this);
void MPU6050_setOTPBankValid(MPU6050_t* this, BOOL enabled);
int8_t MPU6050_getXGyroOffsetTC(MPU6050_t* this);
void MPU6050_setXGyroOffsetTC(MPU6050_t* this, int8_t offset);

// YG_OFFS_TC register
int8_t MPU6050_getYGyroOffsetTC(MPU6050_t* this);
void MPU6050_setYGyroOffsetTC(MPU6050_t* this, int8_t offset);

// ZG_OFFS_TC register
int8_t MPU6050_getZGyroOffsetTC(MPU6050_t* this);
void MPU6050_setZGyroOffsetTC(MPU6050_t* this, int8_t offset);

// X_FINE_GAIN register
int8_t MPU6050_getXFineGain(MPU6050_t* this);
void MPU6050_setXFineGain(MPU6050_t* this, int8_t gain);

// Y_FINE_GAIN register
int8_t MPU6050_getYFineGain(MPU6050_t* this);
void MPU6050_setYFineGain(MPU6050_t* this, int8_t gain);

// Z_FINE_GAIN register
int8_t MPU6050_getZFineGain(MPU6050_t* this);
void MPU6050_setZFineGain(MPU6050_t* this, int8_t gain);

// XA_OFFS_* registers
int16_t MPU6050_getXAccelOffset(MPU6050_t* this);
void MPU6050_setXAccelOffset(MPU6050_t* this, int16_t offset);

// YA_OFFS_* register
int16_t MPU6050_getYAccelOffset(MPU6050_t* this);
void MPU6050_setYAccelOffset(MPU6050_t* this, int16_t offset);

// ZA_OFFS_* register
int16_t MPU6050_getZAccelOffset(MPU6050_t* this);
void MPU6050_setZAccelOffset(MPU6050_t* this, int16_t offset);

// XG_OFFS_USR* registers
int16_t MPU6050_getXGyroOffset(MPU6050_t* this);
void MPU6050_setXGyroOffset(MPU6050_t* this, int16_t offset);

// YG_OFFS_USR* register
int16_t MPU6050_getYGyroOffset(MPU6050_t* this);
void MPU6050_setYGyroOffset(MPU6050_t* this, int16_t offset);

// ZG_OFFS_USR* register
int16_t MPU6050_getZGyroOffset(MPU6050_t* this);
void MPU6050_setZGyroOffset(MPU6050_t* this, int16_t offset);

// INT_ENABLE register (MPU6050_t* thisDMP functions)
BOOL MPU6050_getIntPLLReadyEnabled(MPU6050_t* this);
void MPU6050_setIntPLLReadyEnabled(MPU6050_t* this, BOOL enabled);
BOOL MPU6050_getIntDMPEnabled(MPU6050_t* this);
void MPU6050_setIntDMPEnabled(MPU6050_t* this, BOOL enabled);

// DMP_INT_STATUS
BOOL MPU6050_getDMPInt5Status(MPU6050_t* this);
BOOL MPU6050_getDMPInt4Status(MPU6050_t* this);
BOOL MPU6050_getDMPInt3Status(MPU6050_t* this);
BOOL MPU6050_getDMPInt2Status(MPU6050_t* this);
BOOL MPU6050_getDMPInt1Status(MPU6050_t* this);
BOOL MPU6050_getDMPInt0Status(MPU6050_t* this);

// INT_STATUS register (MPU6050_t* thisDMP functions)
BOOL MPU6050_getIntPLLReadyStatus(MPU6050_t* this);
BOOL MPU6050_getIntDMPStatus(MPU6050_t* this);

// USER_CTRL register (MPU6050_t* thisDMP functions)
BOOL MPU6050_getDMPEnabled(MPU6050_t* this);
void MPU6050_setDMPEnabled(MPU6050_t* this, BOOL enabled);
void MPU6050_resetDMP(MPU6050_t* this);

// BANK_SEL register
void MPU6050_setMemoryBank(MPU6050_t* this, uint8_t bank, BOOL prefetchEnabled, BOOL userBank);

// MEM_START_ADDR register
void MPU6050_setMemoryStartAddress(MPU6050_t* this, uint8_t address);

// MEM_R_W register
uint8_t MPU6050_readMemoryByte(MPU6050_t* this);
void MPU6050_writeMemoryByte(MPU6050_t* this, uint8_t data);
void MPU6050_readMemoryBlock(MPU6050_t* this, uint8_t *data, uint16_t dataSize, uint8_t bank, uint8_t address);
BOOL MPU6050_writeMemoryBlock(MPU6050_t* this, const uint8_t *data, uint16_t dataSize, uint8_t bank, uint8_t address, BOOL verify, BOOL useProgMem);
BOOL MPU6050_writeProgMemoryBlock(MPU6050_t* this, const uint8_t *data, uint16_t dataSize, uint8_t bank, uint8_t address, BOOL verify);

BOOL MPU6050_writeDMPConfigurationSet(MPU6050_t* this, const uint8_t *data, uint16_t dataSize, BOOL useProgMem);
BOOL MPU6050_writeProgDMPConfigurationSet(MPU6050_t* this, const uint8_t *data, uint16_t dataSize);

// DMP_CFG_1 register
uint8_t MPU6050_getDMPConfig1(MPU6050_t* this);
void MPU6050_setDMPConfig1(MPU6050_t* this, uint8_t config);

// DMP_CFG_2 register
uint8_t MPU6050_getDMPConfig2(MPU6050_t* this);
void MPU6050_setDMPConfig2(MPU6050_t* this, uint8_t config);

#endif /* _MPU6050_H_ */
