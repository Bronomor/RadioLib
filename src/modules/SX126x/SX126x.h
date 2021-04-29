#if !defined(_RADIOLIB_SX126X_H)
#define _RADIOLIB_SX126X_H

#include "../../TypeDef.h"

#if !defined(RADIOLIB_EXCLUDE_SX126X)

#include "../../Module.h"

#include "../../protocols/PhysicalLayer/PhysicalLayer.h"

// SX126X physical layer properties
#define SX126X_FREQUENCY_STEP_SIZE                    0.9536743164
#define SX126X_MAX_PACKET_LENGTH                      255
#define SX126X_CRYSTAL_FREQ                           32.0
#define SX126X_DIV_EXPONENT                           25

// SX126X SPI commands
// operational modes commands
#define SX126X_CMD_NOP                                0x00
#define SX126X_CMD_SET_SLEEP                          0x84
#define SX126X_CMD_SET_STANDBY                        0x80
#define SX126X_CMD_SET_FS                             0xC1
#define SX126X_CMD_SET_TX                             0x83
#define SX126X_CMD_SET_RX                             0x82
#define SX126X_CMD_STOP_TIMER_ON_PREAMBLE             0x9F
#define SX126X_CMD_SET_RX_DUTY_CYCLE                  0x94
#define SX126X_CMD_SET_CAD                            0xC5
#define SX126X_CMD_SET_TX_CONTINUOUS_WAVE             0xD1
#define SX126X_CMD_SET_TX_INFINITE_PREAMBLE           0xD2
#define SX126X_CMD_SET_REGULATOR_MODE                 0x96
#define SX126X_CMD_CALIBRATE                          0x89
#define SX126X_CMD_CALIBRATE_IMAGE                    0x98
#define SX126X_CMD_SET_PA_CONFIG                      0x95
#define SX126X_CMD_SET_RX_TX_FALLBACK_MODE            0x93

// register and buffer access commands
#define SX126X_CMD_WRITE_REGISTER                     0x0D
#define SX126X_CMD_READ_REGISTER                      0x1D
#define SX126X_CMD_WRITE_BUFFER                       0x0E
#define SX126X_CMD_READ_BUFFER                        0x1E

// DIO and IRQ control
#define SX126X_CMD_SET_DIO_IRQ_PARAMS                 0x08
#define SX126X_CMD_GET_IRQ_STATUS                     0x12
#define SX126X_CMD_CLEAR_IRQ_STATUS                   0x02
#define SX126X_CMD_SET_DIO2_AS_RF_SWITCH_CTRL         0x9D
#define SX126X_CMD_SET_DIO3_AS_TCXO_CTRL              0x97

// RF, modulation and packet commands
#define SX126X_CMD_SET_RF_FREQUENCY                   0x86
#define SX126X_CMD_SET_PACKET_TYPE                    0x8A
#define SX126X_CMD_GET_PACKET_TYPE                    0x11
#define SX126X_CMD_SET_TX_PARAMS                      0x8E
#define SX126X_CMD_SET_MODULATION_PARAMS              0x8B
#define SX126X_CMD_SET_PACKET_PARAMS                  0x8C
#define SX126X_CMD_SET_CAD_PARAMS                     0x88
#define SX126X_CMD_SET_BUFFER_BASE_ADDRESS            0x8F
#define SX126X_CMD_SET_LORA_SYMB_NUM_TIMEOUT          0x0A

// status commands
#define SX126X_CMD_GET_STATUS                         0xC0
#define SX126X_CMD_GET_RSSI_INST                      0x15
#define SX126X_CMD_GET_RX_BUFFER_STATUS               0x13
#define SX126X_CMD_GET_PACKET_STATUS                  0x14
#define SX126X_CMD_GET_DEVICE_ERRORS                  0x17
#define SX126X_CMD_CLEAR_DEVICE_ERRORS                0x07
#define SX126X_CMD_GET_STATS                          0x10
#define SX126X_CMD_RESET_STATS                        0x00


// SX126X register map
#define SX126X_REG_WHITENING_INITIAL_MSB              0x06B8
#define SX126X_REG_WHITENING_INITIAL_LSB              0x06B9
#define SX126X_REG_CRC_INITIAL_MSB                    0x06BC
#define SX126X_REG_CRC_INITIAL_LSB                    0x06BD
#define SX126X_REG_CRC_POLYNOMIAL_MSB                 0x06BE
#define SX126X_REG_CRC_POLYNOMIAL_LSB                 0x06BF
#define SX126X_REG_SYNC_WORD_0                        0x06C0
#define SX126X_REG_SYNC_WORD_1                        0x06C1
#define SX126X_REG_SYNC_WORD_2                        0x06C2
#define SX126X_REG_SYNC_WORD_3                        0x06C3
#define SX126X_REG_SYNC_WORD_4                        0x06C4
#define SX126X_REG_SYNC_WORD_5                        0x06C5
#define SX126X_REG_SYNC_WORD_6                        0x06C6
#define SX126X_REG_SYNC_WORD_7                        0x06C7
#define SX126X_REG_NODE_ADDRESS                       0x06CD
#define SX126X_REG_BROADCAST_ADDRESS                  0x06CE
#define SX126X_REG_LORA_SYNC_WORD_MSB                 0x0740
#define SX126X_REG_LORA_SYNC_WORD_LSB                 0x0741
#define SX126X_REG_RANDOM_NUMBER_0                    0x0819
#define SX126X_REG_RANDOM_NUMBER_1                    0x081A
#define SX126X_REG_RANDOM_NUMBER_2                    0x081B
#define SX126X_REG_RANDOM_NUMBER_3                    0x081C
#define SX126X_REG_RX_GAIN                            0x08AC
#define SX126X_REG_OCP_CONFIGURATION                  0x08E7
#define SX126X_REG_XTA_TRIM                           0x0911
#define SX126X_REG_XTB_TRIM                           0x0912

// undocumented registers
#define SX126X_REG_SENSITIVITY_CONFIG                 0x0889 // SX1268 datasheet v1.1, section 15.1
#define SX126X_REG_TX_CLAMP_CONFIG                    0x08D8 // SX1268 datasheet v1.1, section 15.2
#define SX126X_REG_RTC_STOP                           0x0920 // SX1268 datasheet v1.1, section 15.3
#define SX126X_REG_RTC_EVENT                          0x0944 // SX1268 datasheet v1.1, section 15.3
#define SX126X_REG_IQ_CONFIG                          0x0736 // SX1268 datasheet v1.1, section 15.4
#define SX126X_REG_RX_GAIN_RETENTION_0                0x029F // SX1268 datasheet v1.1, section 9.6
#define SX126X_REG_RX_GAIN_RETENTION_1                0x02A0 // SX1268 datasheet v1.1, section 9.6
#define SX126X_REG_RX_GAIN_RETENTION_2                0x02A1 // SX1268 datasheet v1.1, section 9.6


// SX126X SPI command variables
//SX126X_CMD_SET_SLEEP                                                MSB   LSB   DESCRIPTION
#define SX126X_SLEEP_START_COLD                       0b00000000  //  2     2     sleep mode: cold start, configuration is lost (default)
#define SX126X_SLEEP_START_WARM                       0b00000100  //  2     2                 warm start, configuration is retained
#define SX126X_SLEEP_RTC_OFF                          0b00000000  //  0     0     wake on RTC timeout: disabled
#define SX126X_SLEEP_RTC_ON                           0b00000001  //  0     0                          enabled

//SX126X_CMD_SET_STANDBY
#define SX126X_STANDBY_RC                             0x00        //  7     0     standby mode: 13 MHz RC oscillator
#define SX126X_STANDBY_XOSC                           0x01        //  7     0                   32 MHz crystal oscillator

//SX126X_CMD_SET_RX
#define SX126X_RX_TIMEOUT_NONE                        0x000000    //  23    0     Rx timeout duration: no timeout (Rx single mode)
#define SX126X_RX_TIMEOUT_INF                         0xFFFFFF    //  23    0                          infinite (Rx continuous mode)

//SX126X_CMD_SET_TX
#define SX126X_TX_TIMEOUT_NONE                        0x000000    //  23    0     Tx timeout duration: no timeout (Tx single mode)

//SX126X_CMD_STOP_TIMER_ON_PREAMBLE
#define SX126X_STOP_ON_PREAMBLE_OFF                   0x00        //  7     0     stop timer on: sync word or header (default)
#define SX126X_STOP_ON_PREAMBLE_ON                    0x01        //  7     0                    preamble detection

//SX126X_CMD_SET_REGULATOR_MODE
#define SX126X_REGULATOR_LDO                          0x00        //  7     0     set regulator mode: LDO (default)
#define SX126X_REGULATOR_DC_DC                        0x01        //  7     0                         DC-DC

//SX126X_CMD_CALIBRATE
#define SX126X_CALIBRATE_IMAGE_OFF                    0b00000000  //  6     6     image calibration: disabled
#define SX126X_CALIBRATE_IMAGE_ON                     0b01000000  //  6     6                        enabled
#define SX126X_CALIBRATE_ADC_BULK_P_OFF               0b00000000  //  5     5     ADC bulk P calibration: disabled
#define SX126X_CALIBRATE_ADC_BULK_P_ON                0b00100000  //  5     5                             enabled
#define SX126X_CALIBRATE_ADC_BULK_N_OFF               0b00000000  //  4     4     ADC bulk N calibration: disabled
#define SX126X_CALIBRATE_ADC_BULK_N_ON                0b00010000  //  4     4                             enabled
#define SX126X_CALIBRATE_ADC_PULSE_OFF                0b00000000  //  3     3     ADC pulse calibration: disabled
#define SX126X_CALIBRATE_ADC_PULSE_ON                 0b00001000  //  3     3                            enabled
#define SX126X_CALIBRATE_PLL_OFF                      0b00000000  //  2     2     PLL calibration: disabled
#define SX126X_CALIBRATE_PLL_ON                       0b00000100  //  2     2                      enabled
#define SX126X_CALIBRATE_RC13M_OFF                    0b00000000  //  1     1     13 MHz RC osc. calibration: disabled
#define SX126X_CALIBRATE_RC13M_ON                     0b00000010  //  1     1                                 enabled
#define SX126X_CALIBRATE_RC64K_OFF                    0b00000000  //  0     0     64 kHz RC osc. calibration: disabled
#define SX126X_CALIBRATE_RC64K_ON                     0b00000001  //  0     0                                 enabled
#define SX126X_CALIBRATE_ALL                          0b01111111  //  6     0     calibrate all blocks

//SX126X_CMD_CALIBRATE_IMAGE
#define SX126X_CAL_IMG_430_MHZ_1                      0x6B
#define SX126X_CAL_IMG_430_MHZ_2                      0x6F
#define SX126X_CAL_IMG_470_MHZ_1                      0x75
#define SX126X_CAL_IMG_470_MHZ_2                      0x81
#define SX126X_CAL_IMG_779_MHZ_1                      0xC1
#define SX126X_CAL_IMG_779_MHZ_2                      0xC5
#define SX126X_CAL_IMG_863_MHZ_1                      0xD7
#define SX126X_CAL_IMG_863_MHZ_2                      0xDB
#define SX126X_CAL_IMG_902_MHZ_1                      0xE1
#define SX126X_CAL_IMG_902_MHZ_2                      0xE9

//SX126X_CMD_SET_PA_CONFIG
#define SX126X_PA_CONFIG_HP_MAX                       0x07
#define SX126X_PA_CONFIG_PA_LUT                       0x01
#define SX126X_PA_CONFIG_SX1262_8                     0x00

//SX126X_CMD_SET_RX_TX_FALLBACK_MODE
#define SX126X_RX_TX_FALLBACK_MODE_FS                 0x40        //  7     0     after Rx/Tx go to: FS mode
#define SX126X_RX_TX_FALLBACK_MODE_STDBY_XOSC         0x30        //  7     0                        standby with crystal oscillator
#define SX126X_RX_TX_FALLBACK_MODE_STDBY_RC           0x20        //  7     0                        standby with RC oscillator (default)

//SX126X_CMD_SET_DIO_IRQ_PARAMS
#define SX126X_IRQ_TIMEOUT                          0b1000000000  //  9     9     Rx or Tx timeout
#define SX126X_IRQ_CAD_DETECTED                     0b0100000000  //  8     8     channel activity detected
#define SX126X_IRQ_CAD_DONE                         0b0010000000  //  7     7     channel activity detection finished
#define SX126X_IRQ_CRC_ERR                          0b0001000000  //  6     6     wrong CRC received
#define SX126X_IRQ_HEADER_ERR                       0b0000100000  //  5     5     LoRa header CRC error
#define SX126X_IRQ_HEADER_VALID                     0b0000010000  //  4     4     valid LoRa header received
#define SX126X_IRQ_SYNC_WORD_VALID                  0b0000001000  //  3     3     valid sync word detected
#define SX126X_IRQ_PREAMBLE_DETECTED                0b0000000100  //  2     2     preamble detected
#define SX126X_IRQ_RX_DONE                          0b0000000010  //  1     1     packet received
#define SX126X_IRQ_TX_DONE                          0b0000000001  //  0     0     packet transmission completed
#define SX126X_IRQ_ALL                              0b1111111111  //  9     0     all interrupts
#define SX126X_IRQ_NONE                             0b0000000000  //  9     0     no interrupts

//SX126X_CMD_SET_DIO2_AS_RF_SWITCH_CTRL
#define SX126X_DIO2_AS_IRQ                            0x00        //  7     0     DIO2 configuration: IRQ
#define SX126X_DIO2_AS_RF_SWITCH                      0x01        //  7     0                         RF switch control

//SX126X_CMD_SET_DIO3_AS_TCXO_CTRL
#define SX126X_DIO3_OUTPUT_1_6                        0x00        //  7     0     DIO3 voltage output for TCXO: 1.6 V
#define SX126X_DIO3_OUTPUT_1_7                        0x01        //  7     0                                   1.7 V
#define SX126X_DIO3_OUTPUT_1_8                        0x02        //  7     0                                   1.8 V
#define SX126X_DIO3_OUTPUT_2_2                        0x03        //  7     0                                   2.2 V
#define SX126X_DIO3_OUTPUT_2_4                        0x04        //  7     0                                   2.4 V
#define SX126X_DIO3_OUTPUT_2_7                        0x05        //  7     0                                   2.7 V
#define SX126X_DIO3_OUTPUT_3_0                        0x06        //  7     0                                   3.0 V
#define SX126X_DIO3_OUTPUT_3_3                        0x07        //  7     0                                   3.3 V

//SX126X_CMD_SET_PACKET_TYPE
#define SX126X_PACKET_TYPE_GFSK                       0x00        //  7     0     packet type: GFSK
#define SX126X_PACKET_TYPE_LORA                       0x01        //  7     0                  LoRa

//SX126X_CMD_SET_TX_PARAMS
#define SX126X_PA_RAMP_10U                            0x00        //  7     0     ramp time: 10 us
#define SX126X_PA_RAMP_20U                            0x01        //  7     0                20 us
#define SX126X_PA_RAMP_40U                            0x02        //  7     0                40 us
#define SX126X_PA_RAMP_80U                            0x03        //  7     0                80 us
#define SX126X_PA_RAMP_200U                           0x04        //  7     0                200 us
#define SX126X_PA_RAMP_800U                           0x05        //  7     0                800 us
#define SX126X_PA_RAMP_1700U                          0x06        //  7     0                1700 us
#define SX126X_PA_RAMP_3400U                          0x07        //  7     0                3400 us

//SX126X_CMD_SET_MODULATION_PARAMS
#define SX126X_GFSK_FILTER_NONE                       0x00        //  7     0     GFSK filter: none
#define SX126X_GFSK_FILTER_GAUSS_0_3                  0x08        //  7     0                  Gaussian, BT = 0.3
#define SX126X_GFSK_FILTER_GAUSS_0_5                  0x09        //  7     0                  Gaussian, BT = 0.5
#define SX126X_GFSK_FILTER_GAUSS_0_7                  0x0A        //  7     0                  Gaussian, BT = 0.7
#define SX126X_GFSK_FILTER_GAUSS_1                    0x0B        //  7     0                  Gaussian, BT = 1
#define SX126X_GFSK_RX_BW_4_8                         0x1F        //  7     0     GFSK Rx bandwidth: 4.8 kHz
#define SX126X_GFSK_RX_BW_5_8                         0x17        //  7     0                        5.8 kHz
#define SX126X_GFSK_RX_BW_7_3                         0x0F        //  7     0                        7.3 kHz
#define SX126X_GFSK_RX_BW_9_7                         0x1E        //  7     0                        9.7 kHz
#define SX126X_GFSK_RX_BW_11_7                        0x16        //  7     0                        11.7 kHz
#define SX126X_GFSK_RX_BW_14_6                        0x0E        //  7     0                        14.6 kHz
#define SX126X_GFSK_RX_BW_19_5                        0x1D        //  7     0                        19.5 kHz
#define SX126X_GFSK_RX_BW_23_4                        0x15        //  7     0                        23.4 kHz
#define SX126X_GFSK_RX_BW_29_3                        0x0D        //  7     0                        29.3 kHz
#define SX126X_GFSK_RX_BW_39_0                        0x1C        //  7     0                        39.0 kHz
#define SX126X_GFSK_RX_BW_46_9                        0x14        //  7     0                        46.9 kHz
#define SX126X_GFSK_RX_BW_58_6                        0x0C        //  7     0                        58.6 kHz
#define SX126X_GFSK_RX_BW_78_2                        0x1B        //  7     0                        78.2 kHz
#define SX126X_GFSK_RX_BW_93_8                        0x13        //  7     0                        93.8 kHz
#define SX126X_GFSK_RX_BW_117_3                       0x0B        //  7     0                        117.3 kHz
#define SX126X_GFSK_RX_BW_156_2                       0x1A        //  7     0                        156.2 kHz
#define SX126X_GFSK_RX_BW_187_2                       0x12        //  7     0                        187.2 kHz
#define SX126X_GFSK_RX_BW_234_3                       0x0A        //  7     0                        234.3 kHz
#define SX126X_GFSK_RX_BW_312_0                       0x19        //  7     0                        312.0 kHz
#define SX126X_GFSK_RX_BW_373_6                       0x11        //  7     0                        373.6 kHz
#define SX126X_GFSK_RX_BW_467_0                       0x09        //  7     0                        467.0 kHz
#define SX126X_LORA_BW_7_8                            0x00        //  7     0     LoRa bandwidth: 7.8 kHz
#define SX126X_LORA_BW_10_4                           0x08        //  7     0                     10.4 kHz
#define SX126X_LORA_BW_15_6                           0x01        //  7     0                     15.6 kHz
#define SX126X_LORA_BW_20_8                           0x09        //  7     0                     20.8 kHz
#define SX126X_LORA_BW_31_25                          0x02        //  7     0                     31.25 kHz
#define SX126X_LORA_BW_41_7                           0x0A        //  7     0                     41.7 kHz
#define SX126X_LORA_BW_62_5                           0x03        //  7     0                     62.5 kHz
#define SX126X_LORA_BW_125_0                          0x04        //  7     0                     125.0 kHz
#define SX126X_LORA_BW_250_0                          0x05        //  7     0                     250.0 kHz
#define SX126X_LORA_BW_500_0                          0x06        //  7     0                     500.0 kHz
#define SX126X_LORA_CR_4_5                            0x01        //  7     0     LoRa coding rate: 4/5
#define SX126X_LORA_CR_4_6                            0x02        //  7     0                       4/6
#define SX126X_LORA_CR_4_7                            0x03        //  7     0                       4/7
#define SX126X_LORA_CR_4_8                            0x04        //  7     0                       4/8
#define SX126X_LORA_LOW_DATA_RATE_OPTIMIZE_OFF        0x00        //  7     0     LoRa low data rate optimization: disabled
#define SX126X_LORA_LOW_DATA_RATE_OPTIMIZE_ON         0x01        //  7     0                                      enabled

//SX126X_CMD_SET_PACKET_PARAMS
#define SX126X_GFSK_PREAMBLE_DETECT_OFF               0x00        //  7     0     GFSK minimum preamble length before reception starts: detector disabled
#define SX126X_GFSK_PREAMBLE_DETECT_8                 0x04        //  7     0                                                           8 bits
#define SX126X_GFSK_PREAMBLE_DETECT_16                0x05        //  7     0                                                           16 bits
#define SX126X_GFSK_PREAMBLE_DETECT_24                0x06        //  7     0                                                           24 bits
#define SX126X_GFSK_PREAMBLE_DETECT_32                0x07        //  7     0                                                           32 bits
#define SX126X_GFSK_ADDRESS_FILT_OFF                  0x00        //  7     0     GFSK address filtering: disabled
#define SX126X_GFSK_ADDRESS_FILT_NODE                 0x01        //  7     0                             node only
#define SX126X_GFSK_ADDRESS_FILT_NODE_BROADCAST       0x02        //  7     0                             node and broadcast
#define SX126X_GFSK_PACKET_FIXED                      0x00        //  7     0     GFSK packet type: fixed (payload length known in advance to both sides)
#define SX126X_GFSK_PACKET_VARIABLE                   0x01        //  7     0                       variable (payload length added to packet)
#define SX126X_GFSK_CRC_OFF                           0x01        //  7     0     GFSK packet CRC: disabled
#define SX126X_GFSK_CRC_1_BYTE                        0x00        //  7     0                      1 byte
#define SX126X_GFSK_CRC_2_BYTE                        0x02        //  7     0                      2 byte
#define SX126X_GFSK_CRC_1_BYTE_INV                    0x04        //  7     0                      1 byte, inverted
#define SX126X_GFSK_CRC_2_BYTE_INV                    0x06        //  7     0                      2 byte, inverted
#define SX126X_GFSK_WHITENING_OFF                     0x00        //  7     0     GFSK data whitening: disabled
#define SX126X_GFSK_WHITENING_ON                      0x01        //  7     0                          enabled
#define SX126X_LORA_HEADER_EXPLICIT                   0x00        //  7     0     LoRa header mode: explicit
#define SX126X_LORA_HEADER_IMPLICIT                   0x01        //  7     0                       implicit
#define SX126X_LORA_CRC_OFF                           0x00        //  7     0     LoRa CRC mode: disabled
#define SX126X_LORA_CRC_ON                            0x01        //  7     0                    enabled
#define SX126X_LORA_IQ_STANDARD                       0x00        //  7     0     LoRa IQ setup: standard
#define SX126X_LORA_IQ_INVERTED                       0x01        //  7     0                    inverted

//SX126X_CMD_SET_CAD_PARAMS
#define SX126X_CAD_ON_1_SYMB                          0x00        //  7     0     number of symbols used for CAD: 1
#define SX126X_CAD_ON_2_SYMB                          0x01        //  7     0                                     2
#define SX126X_CAD_ON_4_SYMB                          0x02        //  7     0                                     4
#define SX126X_CAD_ON_8_SYMB                          0x03        //  7     0                                     8
#define SX126X_CAD_ON_16_SYMB                         0x04        //  7     0                                     16
#define SX126X_CAD_GOTO_STDBY                         0x00        //  7     0     after CAD is done, always go to STDBY_RC mode
#define SX126X_CAD_GOTO_RX                            0x01        //  7     0     after CAD is done, go to Rx mode if activity is detected

//SX126X_CMD_GET_STATUS
#define SX126X_STATUS_MODE_STDBY_RC                   0b00100000  //  6     4     current chip mode: STDBY_RC
#define SX126X_STATUS_MODE_STDBY_XOSC                 0b00110000  //  6     4                        STDBY_XOSC
#define SX126X_STATUS_MODE_FS                         0b01000000  //  6     4                        FS
#define SX126X_STATUS_MODE_RX                         0b01010000  //  6     4                        RX
#define SX126X_STATUS_MODE_TX                         0b01100000  //  6     4                        TX
#define SX126X_STATUS_DATA_AVAILABLE                  0b00000100  //  3     1     command status: packet received and data can be retrieved
#define SX126X_STATUS_CMD_TIMEOUT                     0b00000110  //  3     1                     SPI command timed out
#define SX126X_STATUS_CMD_INVALID                     0b00001000  //  3     1                     invalid SPI command
#define SX126X_STATUS_CMD_FAILED                      0b00001010  //  3     1                     SPI command failed to execute
#define SX126X_STATUS_TX_DONE                         0b00001100  //  3     1                     packet transmission done
#define SX126X_STATUS_SPI_FAILED                      0b11111111  //  7     0     SPI transaction failed

//SX126X_CMD_GET_PACKET_STATUS
#define SX126X_GFSK_RX_STATUS_PREAMBLE_ERR            0b10000000  //  7     7     GFSK Rx status: preamble error
#define SX126X_GFSK_RX_STATUS_SYNC_ERR                0b01000000  //  6     6                     sync word error
#define SX126X_GFSK_RX_STATUS_ADRS_ERR                0b00100000  //  5     5                     address error
#define SX126X_GFSK_RX_STATUS_CRC_ERR                 0b00010000  //  4     4                     CRC error
#define SX126X_GFSK_RX_STATUS_LENGTH_ERR              0b00001000  //  3     3                     length error
#define SX126X_GFSK_RX_STATUS_ABORT_ERR               0b00000100  //  2     2                     abort error
#define SX126X_GFSK_RX_STATUS_PACKET_RECEIVED         0b00000010  //  2     2                     packet received
#define SX126X_GFSK_RX_STATUS_PACKET_SENT             0b00000001  //  2     2                     packet sent

//SX126X_CMD_GET_DEVICE_ERRORS
#define SX126X_PA_RAMP_ERR                           0b100000000  //  8     8     device errors: PA ramping failed
#define SX126X_PLL_LOCK_ERR                          0b001000000  //  6     6                    PLL failed to lock
#define SX126X_XOSC_START_ERR                        0b000100000  //  5     5                    crystal oscillator failed to start
#define SX126X_IMG_CALIB_ERR                         0b000010000  //  4     4                    image calibration failed
#define SX126X_ADC_CALIB_ERR                         0b000001000  //  3     3                    ADC calibration failed
#define SX126X_PLL_CALIB_ERR                         0b000000100  //  2     2                    PLL calibration failed
#define SX126X_RC13M_CALIB_ERR                       0b000000010  //  1     1                    RC13M calibration failed
#define SX126X_RC64K_CALIB_ERR                       0b000000001  //  0     0                    RC64K calibration failed


// SX126X SPI register variables
//SX126X_REG_LORA_SYNC_WORD_MSB + LSB
#define SX126X_SYNC_WORD_PUBLIC                       0x34        // actually 0x3444  NOTE: The low nibbles in each byte (0x_4_4) are masked out since apparently, they're reserved.
#define SX126X_SYNC_WORD_PRIVATE                      0x12        // actually 0x1424        You couldn't make this up if you tried.


/*!
  \class SX126x

  \brief Base class for %SX126x series. All derived classes for %SX126x (e.g. SX1262 or SX1268) inherit from this base class.
  This class should not be instantiated directly from Arduino sketch, only from its derived classes.
*/
class SX126x: public PhysicalLayer {
  public:
    // introduce PhysicalLayer overloads
    using PhysicalLayer::transmit;
    using PhysicalLayer::receive;
    using PhysicalLayer::startTransmit;
    using PhysicalLayer::readData;

    /*!
      \brief Default constructor.

      \param mod Instance of Module that will be used to communicate with the radio.
    */
    SX126x(Module* mod);

    // basic methods

    /*!
      \brief Initialization method for LoRa modem.

      \param bw LoRa bandwidth in kHz. Allowed values are 7.8, 10.4, 15.6, 20.8, 31.25, 41.7, 62.5, 125.0, 250.0 and 500.0 kHz.

      \param sf LoRa spreading factor. Allowed values are in range 5 to 12.

      \param cr LoRa coding rate denominator. Allowed values range from 5 to 8.

      \param syncWord 1-byte LoRa sync word.

      \param preambleLength LoRa preamble length in symbols. Allowed values range from 1 to 65535.

      \param tcxoVoltage TCXO reference voltage to be set on DIO3. Defaults to 1.6 V, set to 0 to skip.

      \param useRegulatorLDO use the LDO instead of DC-DC converter (default false). This is necessary for some modules such as the LAMBDA from RF solutions.

      \returns \ref status_codes
    */
    int16_t begin(float bw, uint8_t sf, uint8_t cr, uint8_t syncWord, uint16_t preambleLength, float tcxoVoltage, bool useRegulatorLDO = false);

    /*!
      \brief Initialization method for FSK modem.

      \param br FSK bit rate in kbps. Allowed values range from 0.6 to 300.0 kbps.

      \param freqDev Frequency deviation from carrier frequency in kHz. Allowed values range from 0.0 to 200.0 kHz.

      \param rxBw Receiver bandwidth in kHz. Allowed values are 4.8, 5.8, 7.3, 9.7, 11.7, 14.6, 19.5, 23.4, 29.3, 39.0, 46.9, 58.6, 78.2, 93.8, 117.3, 156.2, 187.2, 234.3, 312.0, 373.6 and 467.0 kHz.

      \param preambleLength FSK preamble length in bits. Allowed values range from 0 to 65535.

      \param tcxoVoltage TCXO reference voltage to be set on DIO3. Defaults to 1.6 V, set to 0 to skip.

      \param useRegulatorLDO use the LDO instead of DC-DC converter (default false). This is necessary for some modules such as the LAMBDA from RF solutions.

      \returns \ref status_codes
    */
    int16_t beginFSK(float br, float freqDev, float rxBw, uint16_t preambleLength, float tcxoVoltage, bool useRegulatorLDO = false);

    /*!
      \brief Reset method. Will reset the chip to the default state using RST pin.

      \param verify Whether correct module startup should be verified. When set to true, RadioLib will attempt to verify the module has started correctly
      by repeatedly issuing setStandby command. Enabled by default.

      \returns \ref status_codes
    */
    int16_t reset(bool verify = true);

    /*!
      \brief Blocking binary transmit method.
      Overloads for string-based transmissions are implemented in PhysicalLayer.

      \param data Binary data to be sent.

      \param len Number of bytes to send.

      \param addr Address to send the data to. Will only be added if address filtering was enabled.

      \returns \ref status_codes
    */
    int16_t transmit(uint8_t* data, size_t len, uint8_t addr = 0) override;

    /*!
      \brief Blocking binary receive method.
      Overloads for string-based transmissions are implemented in PhysicalLayer.

      \param data Binary data to be sent.

      \param len Number of bytes to send.

      \returns \ref status_codes
    */
    int16_t receive(uint8_t* data, size_t len) override;

    /*!
      \brief Starts direct mode transmission.

      \param frf Raw RF frequency value. Defaults to 0, required for quick frequency shifts in RTTY.

      \returns \ref status_codes
    */
    int16_t transmitDirect(uint32_t frf = 0) override;

    /*!
      \brief Starts direct mode reception. Only implemented for PhysicalLayer compatibility, as %SX126x series does not support direct mode reception.
      Will always return ERR_UNKNOWN.

      \returns \ref status_codes
    */
    int16_t receiveDirect() override;

    /*!
      \brief Performs scan for LoRa transmission in the current channel. Detects both preamble and payload.

      \returns \ref status_codes
    */
    int16_t scanChannel();

    /*!
      \brief Sets the module to sleep mode.

      \param retainConfig Set to true to retain configuration of the currently active modem ("warm start") or to false to discard current configuration ("cold start"). Defaults to true.

      \returns \ref status_codes
    */
    int16_t sleep(bool retainConfig = true);

    /*!
      \brief Sets the module to standby mode (overload for PhysicalLayer compatibility, uses 13 MHz RC oscillator).

      \returns \ref status_codes
    */
    int16_t standby() override;

    /*!
      \brief Sets the module to standby mode.

      \param mode Oscillator to be used in standby mode. Can be set to SX126X_STANDBY_RC (13 MHz RC oscillator) or SX126X_STANDBY_XOSC (32 MHz external crystal oscillator).

      \returns \ref status_codes
    */
    int16_t standby(uint8_t mode);

    // interrupt methods

    /*!
      \brief Sets interrupt service routine to call when DIO1 activates.

      \param func ISR to call.
    */
    void setDio1Action(void (*func)(void));

    /*!
      \brief Clears interrupt service routine to call when DIO1 activates.
    */
    void clearDio1Action();

    /*!
      \brief Interrupt-driven binary transmit method.
      Overloads for string-based transmissions are implemented in PhysicalLayer.

      \param data Binary data to be sent.

      \param len Number of bytes to send.

      \param addr Address to send the data to. Will only be added if address filtering was enabled.

      \returns \ref status_codes
    */
    int16_t startTransmit(uint8_t* data, size_t len, uint8_t addr = 0) override;

    /*!
      \brief Interrupt-driven receive method. DIO1 will be activated when full packet is received.

      \param timeout Raw timeout value, expressed as multiples of 15.625 us. Defaults to SX126X_RX_TIMEOUT_INF for infinite timeout (Rx continuous mode), set to SX126X_RX_TIMEOUT_NONE for no timeout (Rx single mode).

      \returns \ref status_codes
    */
    int16_t startReceive(uint32_t timeout = SX126X_RX_TIMEOUT_INF);

    /*!
      \brief Interrupt-driven receive method where the device mostly sleeps and periodically wakes to listen.
      Note that this function assumes the unit will take 500us + TCXO_delay to change state. See datasheet section 13.1.7, version 1.2.

      \param rxPeriod The duration the receiver will be in Rx mode, in microseconds.

      \param sleepPeriod The duration the receiver will not be in Rx mode, in microseconds.

      \returns \ref status_codes
    */
    int16_t startReceiveDutyCycle(uint32_t rxPeriod, uint32_t sleepPeriod);

    /*!
      \brief Calls \ref startReceiveDutyCycle with rxPeriod and sleepPeriod set so the unit shouldn't miss any messages.

      \param senderPreambleLength Expected preamble length of the messages to receive.
      If set to zero, the currently configured preamble length will be used. Defaults to zero.

      \param minSymbols Parameters will be chosen to ensure that the unit will catch at least this many symbols of any preamble of the specified length. Defaults to 8.
      According to Semtech, receiver requires 8 symbols to reliably latch a preamble. This makes this method redundant when transmitter preamble length is less than 17 (2*minSymbols + 1).

      \returns \ref status_codes
    */
    int16_t startReceiveDutyCycleAuto(uint16_t senderPreambleLength = 0, uint16_t minSymbols = 8);

    /*!
      \brief Reads data received after calling startReceive method.

      \param data Pointer to array to save the received binary data.

      \param len Number of bytes that will be received. Must be known in advance for binary transmissions.

      \returns \ref status_codes
    */
    int16_t readData(uint8_t* data, size_t len) override;

    // configuration methods

    /*!
      \brief Sets LoRa bandwidth. Allowed values are 7.8, 10.4, 15.6, 20.8, 31.25, 41.7, 62.5, 125.0, 250.0 and 500.0 kHz.

      \param bw LoRa bandwidth to be set in kHz.

      \returns \ref status_codes
    */
    int16_t setBandwidth(float bw);

    /*!
      \brief Sets LoRa spreading factor. Allowed values range from 5 to 12.

      \param sf LoRa spreading factor to be set.

      \returns \ref status_codes
    */
    int16_t setSpreadingFactor(uint8_t sf);

    /*!
      \brief Sets LoRa coding rate denominator. Allowed values range from 5 to 8.

      \param cr LoRa coding rate denominator to be set.

      \returns \ref status_codes
    */
    int16_t setCodingRate(uint8_t cr);

    /*!
      \brief Sets LoRa sync word.

      \param syncWord LoRa sync word to be set.

      \param controlBits Undocumented control bits, required for compatibility purposes.

      \returns \ref status_codes
    */
    int16_t setSyncWord(uint8_t syncWord, uint8_t controlBits = 0x44);

    /*!
      \brief Sets current protection limit. Can be set in 0.25 mA steps.

      \param currentLimit current protection limit to be set in mA.

      \returns \ref status_codes
    */
    int16_t setCurrentLimit(float currentLimit);

    /*!
      \brief Reads current protection limit.

      \returns Currently configured overcurrent protection limit in mA.
    */
    float getCurrentLimit();

    /*!
      \brief Sets preamble length for LoRa or FSK modem. Allowed values range from 1 to 65535.

      \param preambleLength Preamble length to be set in symbols (LoRa) or bits (FSK).

      \returns \ref status_codes
    */
    int16_t setPreambleLength(uint16_t preambleLength);

    /*!
      \brief Sets FSK frequency deviation. Allowed values range from 0.0 to 200.0 kHz.

      \param freqDev FSK frequency deviation to be set in kHz.

      \returns \ref status_codes
    */
    int16_t setFrequencyDeviation(float freqDev) override;

    /*!
      \brief Sets FSK bit rate. Allowed values range from 0.6 to 300.0 kbps.

      \param br FSK bit rate to be set in kbps.

      \returns \ref status_codes
    */
    int16_t setBitRate(float br);

    /*!
      \brief Sets FSK receiver bandwidth. Allowed values are 4.8, 5.8, 7.3, 9.7, 11.7, 14.6, 19.5, 23.4, 29.3, 39.0, 46.9, 58.6, 78.2, 93.8, 117.3, 156.2, 187.2, 234.3, 312.0, 373.6 and 467.0 kHz.

      \param FSK receiver bandwidth to be set in kHz.

      \returns \ref status_codes
    */
    int16_t setRxBandwidth(float rxBw);

    /*!
      \brief Sets time-bandwidth product of Gaussian filter applied for shaping.
      Allowed values are RADIOLIB_SHAPING_0_3, RADIOLIB_SHAPING_0_5, RADIOLIB_SHAPING_0_7 or RADIOLIB_SHAPING_1_0.
      Set to RADIOLIB_SHAPING_NONE to disable data shaping.

      \param sh Time-bandwidth product of Gaussian filter to be set.

      \returns \ref status_codes
    */
    int16_t setDataShaping(uint8_t sh) override;

    /*!
      \brief Sets FSK sync word in the form of array of up to 8 bytes.

      \param syncWord FSK sync word to be set.

      \param len FSK sync word length in bytes.

      \returns \ref status_codes
    */
    int16_t setSyncWord(uint8_t* syncWord, uint8_t len);

    /*!
      \brief Sets FSK sync word in the form of array of up to 8 bytes.

      \param syncWord FSK sync word to be set.

      \param bitsLen FSK sync word length in bits. If length is not divisible by 8, least significant bits of syncWord will be ignored.

      \returns \ref status_codes
    */
    int16_t setSyncBits(uint8_t *syncWord, uint8_t bitsLen);

    /*!
      \brief Sets node address. Calling this method will also enable address filtering for node address only.

      \param nodeAddr Node address to be set.

      \returns \ref status_codes
    */
    int16_t setNodeAddress(uint8_t nodeAddr);

    /*!
      \brief Sets broadcast address. Calling this method will also enable address filtering for node and broadcast address.

      \param broadAddr Node address to be set.

      \returns \ref status_codes
    */
    int16_t setBroadcastAddress(uint8_t broadAddr);

    /*!
      \brief Disables address filtering. Calling this method will also erase previously set addresses.

      \returns \ref status_codes
    */
    int16_t disableAddressFiltering();

    /*!
      \brief Sets CRC configuration.

      \param len CRC length in bytes, Allowed values are 1 or 2, set to 0 to disable CRC.

      \param initial Initial CRC value. FSK only. Defaults to 0x1D0F (CCIT CRC).

      \param polynomial Polynomial for CRC calculation. FSK only. Defaults to 0x1021 (CCIT CRC).

      \param inverted Invert CRC bytes. FSK only. Defaults to true (CCIT CRC).

      \returns \ref status_codes
    */
    int16_t setCRC(uint8_t len, uint16_t initial = 0x1D0F, uint16_t polynomial = 0x1021, bool inverted = true);

    /*!
      \brief Sets FSK whitening parameters.

      \param enabled True = Whitening enabled

      \param initial Initial value used for the whitening LFSR in FSK mode. Defaults to 0x0100, use 0x01FF for SX127x compatibility.

      \returns \ref status_codes
    */
    int16_t setWhitening(bool enabled, uint16_t initial = 0x0100);

    /*!
      \brief Sets TCXO (Temperature Compensated Crystal Oscillator) configuration.

      \param TCXO reference voltage in volts. Allowed values are 1.6, 1.7, 1.8, 2.2. 2.4, 2.7, 3.0 and 3.3 V. Set to 0 to disable TCXO.
      NOTE: After setting this parameter to 0, the module will be reset (since there's no other way to disable TCXO).

      \param TCXO timeout in us. Defaults to 5000 us.

      \returns \ref status_codes
    */
    int16_t setTCXO(float voltage, uint32_t delay = 5000);

    /*!
      \brief Set DIO2 to function as RF switch (default in Semtech example designs).

      \returns \ref status_codes
    */
    int16_t setDio2AsRfSwitch(bool enable = true);

    /*!
      \brief Gets effective data rate for the last transmitted packet. The value is calculated only for payload bytes.

      \returns Effective data rate in bps.
    */
    float getDataRate() const;

    /*!
      \brief Gets RSSI (Recorded Signal Strength Indicator) of the last received packet.

      \returns RSSI of the last received packet in dBm.
    */
    float getRSSI();

    /*!
      \brief Gets SNR (Signal to Noise Ratio) of the last received packet. Only available for LoRa modem.

      \returns SNR of the last received packet in dB.
    */
    float getSNR();

    /*!
      \brief Query modem for the packet length of received payload.

      \param update Update received packet length. Will return cached value when set to false.

      \returns Length of last received packet in bytes.
    */
    size_t getPacketLength(bool update = true) override;

    /*!
     \brief Set modem in fixed packet length mode. Available in FSK mode only.

     \param len Packet length.

     \returns \ref status_codes
   */
   int16_t fixedPacketLengthMode(uint8_t len = SX126X_MAX_PACKET_LENGTH);

   /*!
     \brief Set modem in variable packet length mode. Available in FSK mode only.

     \param len Maximum packet length.

     \returns \ref status_codes
   */
   int16_t variablePacketLengthMode(uint8_t maxLen = SX126X_MAX_PACKET_LENGTH);

   /*!
     \brief Get expected time-on-air for a given size of payload

     \param len Payload length in bytes.

     \returns Expected time-on-air in microseconds.
   */
   uint32_t getTimeOnAir(size_t len);

   /*!
     \brief Get instantaneous RSSI value during recption of the packet. Should switch to FSK receive mode for LBT implementation.

     \returns Instantaneous RSSI value in dBm, in steps of 0.5dBm
   */
   float getRSSIInst();

   /*!
     \brief Set implicit header mode for future reception/transmission.

     \returns \ref status_codes
   */
   int16_t implicitHeader(size_t len);

   /*!
     \brief Set explicit header mode for future reception/transmission.

     \param len Payload length in bytes.

     \returns \ref status_codes
   */
   int16_t explicitHeader();

   /*!
     \brief Set regulator mode to LDO.

     \returns \ref status_codes
   */
   int16_t setRegulatorLDO();

   /*!
     \brief Set regulator mode to DC-DC.

     \returns \ref status_codes
   */
   int16_t setRegulatorDCDC();

   /*!
     \brief Sets transmission encoding. Available in FSK mode only. Serves only as alias for PhysicalLayer compatibility.

     \param encoding Encoding to be used. Set to 0 for NRZ, and 2 for whitening.

     \returns \ref status_codes
   */
   int16_t setEncoding(uint8_t encoding) override;

   /*!
     \brief Some modules contain external RF switch controlled by two pins. This function gives RadioLib control over those two pins to automatically switch Rx and Tx state.
     When using automatic RF switch control, DO NOT change the pin mode of rxEn or txEn from Arduino sketch!

     \param rxEn RX enable pin.

     \param txEn TX enable pin.
   */
   void setRfSwitchPins(RADIOLIB_PIN_TYPE rxEn, RADIOLIB_PIN_TYPE txEn);

   /*!
     \brief Forces LoRa low data rate optimization. Only available in LoRa mode. After calling this method, LDRO will always be set to
     the provided value, regardless of symbol length. To re-enable automatic LDRO configuration, call SX126x::autoLDRO()

     \param enable Force LDRO to be always enabled (true) or disabled (false).

     \returns \ref status_codes
   */
   int16_t forceLDRO(bool enable);

   /*!
     \brief Re-enables automatic LDRO configuration. Only available in LoRa mode. After calling this method, LDRO will be enabled automatically
     when symbol length exceeds 16 ms.

     \returns \ref status_codes
   */
   int16_t autoLDRO();

   /*!
    \brief Get one truly random byte from RSSI noise.

    \returns TRNG byte.
  */
   uint8_t random();

   /*!
      \brief Enables/disables Invert the LoRa I and Q signals.

      \param invertIQ Enable (true) or disable (false) LoRa I and Q signals.

      \returns \ref status_codes
   */
   int16_t invertIQ(bool invertIQ);

#ifndef RADIOLIB_GODMODE
  protected:
#endif
    // SX126x SPI command implementations
    int16_t setTx(uint32_t timeout = 0);
    int16_t setRx(uint32_t timeout);
    int16_t setCad();
    int16_t setPaConfig(uint8_t paDutyCycle, uint8_t deviceSel, uint8_t hpMax = SX126X_PA_CONFIG_HP_MAX, uint8_t paLut = SX126X_PA_CONFIG_PA_LUT);
    int16_t writeRegister(uint16_t addr, uint8_t* data, uint8_t numBytes);
    int16_t readRegister(uint16_t addr, uint8_t* data, uint8_t numBytes);
    int16_t writeBuffer(uint8_t* data, uint8_t numBytes, uint8_t offset = 0x00);
    int16_t readBuffer(uint8_t* data, uint8_t numBytes);
    int16_t setDioIrqParams(uint16_t irqMask, uint16_t dio1Mask, uint16_t dio2Mask = SX126X_IRQ_NONE, uint16_t dio3Mask = SX126X_IRQ_NONE);
    uint16_t getIrqStatus();
    int16_t clearIrqStatus(uint16_t clearIrqParams = SX126X_IRQ_ALL);
    int16_t setRfFrequency(uint32_t frf);
    int16_t calibrateImage(uint8_t* data);
    uint8_t getPacketType();
    int16_t setTxParams(uint8_t power, uint8_t rampTime = SX126X_PA_RAMP_200U);
    int16_t setModulationParams(uint8_t sf, uint8_t bw, uint8_t cr, uint8_t ldro);
    int16_t setModulationParamsFSK(uint32_t br, uint8_t pulseShape, uint8_t rxBw, uint32_t freqDev);
    int16_t setPacketParams(uint16_t preambleLength, uint8_t crcType, uint8_t payloadLength, uint8_t headerType, uint8_t invertIQ = SX126X_LORA_IQ_STANDARD);
    int16_t setPacketParamsFSK(uint16_t preambleLength, uint8_t crcType, uint8_t syncWordLength, uint8_t addrComp, uint8_t whitening, uint8_t packetType = SX126X_GFSK_PACKET_VARIABLE, uint8_t payloadLength = 0xFF, uint8_t preambleDetectorLength = SX126X_GFSK_PREAMBLE_DETECT_16);
    int16_t setBufferBaseAddress(uint8_t txBaseAddress = 0x00, uint8_t rxBaseAddress = 0x00);
    int16_t setRegulatorMode(uint8_t mode);
    uint8_t getStatus();
    uint32_t getPacketStatus();
    uint16_t getDeviceErrors();
    int16_t clearDeviceErrors();

    int16_t startReceiveCommon();
    int16_t setFrequencyRaw(float freq);
    int16_t setPacketMode(uint8_t mode, uint8_t len);
    int16_t setHeaderType(uint8_t headerType, size_t len = 0xFF);

    // fixes to errata
    int16_t fixSensitivity();
    int16_t fixPaClamping();
    int16_t fixImplicitTimeout();
    int16_t fixInvertedIQ(uint8_t iqConfig);

#if !defined(RADIOLIB_GODMODE) && !defined(RADIOLIB_LOW_LEVEL)
  protected:
#endif
    Module* _mod;

    // common low-level SPI interface
    int16_t SPIwriteCommand(uint8_t cmd, uint8_t* data, uint8_t numBytes, bool waitForBusy = true);
    int16_t SPIwriteCommand(uint8_t* cmd, uint8_t cmdLen, uint8_t* data, uint8_t numBytes, bool waitForBusy = true);
    int16_t SPIreadCommand(uint8_t cmd, uint8_t* data, uint8_t numBytes, bool waitForBusy = true);
    int16_t SPIreadCommand(uint8_t* cmd, uint8_t cmdLen, uint8_t* data, uint8_t numBytes, bool waitForBusy = true);
    int16_t SPItransfer(uint8_t* cmd, uint8_t cmdLen, bool write, uint8_t* dataOut, uint8_t* dataIn, uint8_t numBytes, bool waitForBusy, uint32_t timeout = 5000);

#if !defined(RADIOLIB_GODMODE)
  protected:
#endif

    uint8_t _bw = 0, _sf = 0, _cr = 0, _ldro = 0, _crcType = 0, _headerType = 0;
    uint16_t _preambleLength = 0;
    float _bwKhz = 0;
    bool _ldroAuto = true;

    uint32_t _br = 0, _freqDev = 0;
    uint8_t _rxBw = 0, _pulseShape = 0, _crcTypeFSK = 0, _syncWordLength = 0, _addrComp = 0, _whitening = 0, _packetType = 0;
    uint16_t _preambleLengthFSK = 0;
    float _rxBwKhz = 0;

    float _dataRate = 0;

    uint32_t _tcxoDelay = 0;

    size_t _implicitLen = 0;

    int16_t config(uint8_t modem);
};

#endif

#endif
