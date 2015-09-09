/**
 * Copyright (c) 2015 Google Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 1. Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 * 3. Neither the name of the copyright holder nor the names of its
 * contributors may be used to endorse or promote products derived from this
 * software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef __COMMON_INCLUDE_UNIPRO_H
#define __COMMON_INCLUDE_UNIPRO_H

/*
 * "Don't care" selector index
 */
#define UNIPRO_SELINDEX_NULL 0

/*
 * L1 attributes
 */
#define TX_HSMODE_CAPABILITY                     0x0001
#define TX_HSGEAR_CAPABILITY                     0x0002
#define TX_PWMG0_CAPABILITY                      0x0003
#define TX_PWMGEAR_CAPABILITY                    0x0004
#define TX_AMPLITUDE_CAPABILITY                  0x0005
#define TX_EXTERNALSYNC_CAPABILITY               0x0006
#define TX_HS_UNTERMINATED_LINE_DRIVE_CAPABILITY 0x0007
#define TX_LS_TERMINATED_LINE_DRIVE_CAPABILITY   0x0008
#define TX_MIN_SLEEP_NOCONFIG_TIME_CAPABILITY    0x0009
#define TX_MIN_STALL_NOCONFIG_TIME_CAPABILITY    0x000a
#define TX_MIN_SAVE_CONFIG_TIME_CAPABILITY       0x000b
#define TX_REF_CLOCK_SHARED_CAPABILITY           0x000c
#define TX_PHY_MAJORMINOR_RELEASE_CAPABILITY     0x000d
#define TX_PHY_EDITORIAL_RELEASE_CAPABILITY      0x000e
#define TX_HIBERN8TIME_CAPABILITY                0x000f
#define TX_ADVANCED_GRANULARITY_CAPABILITY       0x0010
#define TX_ADVANCED_HIBERN8TIME_CAPABILITY       0x0011
#define TX_HS_EQUALIZER_SETTING_CAPABILITY       0x0012
#define TX_MODE                                  0x0021
#define TX_HSRATE_SERIES                         0x0022
#define TX_HSGEAR                                0x0023
#define TX_PWMGEAR                               0x0024
#define TX_AMPLITUDE                             0x0025
#define TX_HS_SLEWRATE                           0x0026
#define TX_SYNC_SOURCE                           0x0027
#define TX_HS_SYNC_LENGTH                        0x0028
#define TX_HS_PREPARE_LENGTH                     0x0029
#define TX_LS_PREPARE_LENGTH                     0x002a
#define TX_HIBERN8_CONTROL                       0x002b
#define TX_LCC_ENABLE                            0x002c
#define TX_PWM_BURST_CLOSURE_EXTENSION           0x002d
#define TX_BYPASS_8B10B_ENABLE                   0x002e
#define TX_DRIVER_POLARITY                       0x002f
#define TX_HS_UNTERMINATED_LINE_DRIVE_ENABLE     0x0030
#define TX_LS_TERMINATED_LINE_DRIVE_ENABLE       0x0031
#define TX_LCC_SEQUENCER                         0x0032
#define TX_MIN_ACTIVATETIME                      0x0033
#define TX_ADVANCED_GRANULARITY_SETTING          0x0035
#define TX_ADVANCED_GRANULARITY                  0x0036
#define TX_HS_EQUALIZER_SETTING                  0x0037
#define TX_FSM_STATE                             0x0041
#define MC_OUTPUT_AMPLITUDE                      0x0061
#define MC_HS_UNTERMINATED_ENABLE                0x0062
#define MC_LS_TERMINATED_ENABLE                  0x0063
#define MC_HS_UNTERMINATED_LINE_DRIVE_ENABLE     0x0064
#define MC_LS_TERMINATED_LINE_DRIVE_ENABLE       0x0065
#define RX_HSMODE_CAPABILITY                     0x0081
#define RX_HSGEAR_CAPABILITY                     0x0082
#define RX_PWMG0_CAPABILITY                      0x0083
#define RX_PWMGEAR_CAPABILITY                    0x0084
#define RX_HS_UNTERMINATED_CAPABILITY            0x0085
#define RX_LS_TERMINATED_CAPABILITY              0x0086
#define RX_MIN_SLEEP_NOCONFIG_TIME_CAPABILITY    0x0087
#define RX_MIN_STALL_NOCONFIG_TIME_CAPABILITY    0x0088
#define RX_MIN_SAVE_CONFIG_TIME_CAPABILITY       0x0089
#define RX_REF_CLOCK_SHARED_CAPABILITY           0x008a
#define RX_HS_G1_SYNC_LENGTH_CAPABILITY          0x008b
#define RX_HS_G1_PREPARE_LENGTH_CAPABILITY       0x008c
#define RX_LS_PREPARE_LENGTH_CAPABILITY          0x008d
#define RX_PWM_BURST_CLOSURE_LENGTH_CAPABILITY   0x008e
#define RX_MIN_ACTIVATETIME_CAPABILITY           0x008f
#define RX_PHY_MAJORMINOR_RELEASE_CAPABILITY     0x0090
#define RX_PHY_EDITORIAL_RELEASE_CAPABILITY      0x0091
#define RX_HIBERN8TIME_CAPABILITY                0x0092
#define RX_HS_G2_SYNC_LENGTH_CAPABILITY          0x0094
#define RX_HS_G3_SYNC_LENGTH_CAPABILITY          0x0095
#define RX_HS_G2_PREPARE_LENGTH_CAPABILITY       0x0096
#define RX_HS_G3_PREPARE_LENGTH_CAPABILITY       0x0097
#define RX_ADVANCED_GRANULARITY_CAPABILITY       0x0098
#define RX_ADVANCED_HIBERN8TIME_CAPABILITY       0x0099
#define RX_ADVANCED_MIN_ACTIVATETIME_CAPABILITY  0x009a
#define RX_MODE                                  0x00a1
#define RX_HSRATE_SERIES                         0x00a2
#define RX_HSGEAR                                0x00a3
#define RX_PWMGEAR                               0x00a4
#define RX_LS_TERMINATED_ENABLE                  0x00a5
#define RX_HS_UNTERMINATED_ENABLE                0x00a6
#define RX_ENTER_HIBERN8                         0x00a7
#define RX_BYPASS_8B10B_ENABLE                   0x00a8
#define RX_TERMINATION_FORCE_ENABLE              0x00a9
#define RX_FSM_STATE                             0x00c1
#define OMC_TYPE_CAPABILITY                      0x00d1
#define MC_HSMODE_CAPABILITY                     0x00d2
#define MC_HSGEAR_CAPABILITY                     0x00d3
#define MC_HS_START_TIME_VAR_CAPABILITY          0x00d4
#define MC_HS_START_TIME_RANGE_CAPABILITY        0x00d5
#define MC_RX_SA_CAPABILITY                      0x00d6
#define MC_RX_LA_CAPABILITY                      0x00d7
#define MC_LS_PREPARE_LENGTH                     0x00d8
#define MC_PWMG0_CAPABILITY                      0x00d9
#define MC_PWMGEAR_CAPABILITY                    0x00da
#define MC_LS_TERMINATED_CAPABILITY              0x00db
#define MC_HS_UNTERMINATED_CAPABILITY            0x00dc
#define MC_LS_TERMINATED_LINE_DRIVE_CAPABILITY   0x00dd
#define MC_HS_UNTERMINATED_LINE_DRIVE_CAPABILIT  0x00de
#define MC_MFG_ID_PART1                          0x00df
#define MC_MFG_ID_PART2                          0x00e0
#define MC_PHY_MAJORMINOR_RELEASE_CAPABILITY     0x00e1
#define MC_PHY_EDITORIAL_RELEASE_CAPABILITY      0x00e2
#define MC_VENDOR_INFO_PART1                     0x00e3
#define MC_VENDOR_INFO_PART2                     0x00e4
#define MC_VENDOR_INFO_PART3                     0x00e5
#define MC_VENDOR_INFO_PART4                     0x00e6

/*
 * L1.5 attributes
 */
#define PA_PHYTYPE                     0x1500
#define PA_AVAILTXDATALANES            0x1520
#define PA_AVAILRXDATALANES            0x1540
#define PA_MINRXTRAILINGCLOCKS         0x1543
#define PA_TXHSG1SYNCLENGTH            0x1552
#define PA_TXHSG1PREPARELENGTH         0x1553
#define PA_TXHSG2SYNCLENGTH            0x1554
#define PA_TXHSG2PREPARELENGTH         0x1555
#define PA_TXHSG3SYNCLENGTH            0x1556
#define PA_TXHSG3PREPARELENGTH         0x1557
#define PA_TXMK2EXTENSION              0x155a
#define PA_PEERSCRAMBLING              0x155b
#define PA_TXSKIP                      0x155c
#define PA_SAVECONFIGEXTENSIONENABLE   0x155d
#define PA_LOCALTXLCCENABLE            0x155e
#define PA_PEERTXLCCENABLE             0x155f
#define PA_ACTIVETXDATALANES           0x1560
#define PA_CONNECTEDTXDATALANES        0x1561
#define PA_TXTRAILINGCLOCKS            0x1564
#define PA_TXPWRSTATUS                 0x1567
#define PA_TXGEAR                      0x1568
#define PA_TXTERMINATION               0x1569
#define PA_HSSERIES                    0x156a
#define PA_PWRMODE                     0x1571
#define PA_ACTIVERXDATALANES           0x1580
#define PA_CONNECTEDRXDATALANES        0x1581
#define PA_RXPWRSTATUS                 0x1582
#define PA_RXGEAR                      0x1583
#define PA_RXTERMINATION               0x1584
#define PA_SCRAMBLING                  0x1585
#define PA_MAXRXPWMGEAR                0x1586
#define PA_MAXRXHSGEAR                 0x1587
#define PA_PACPREQTIMEOUT              0x1590
#define PA_PACPREQEOBTIMEOUT           0x1591
#define PA_REMOTEVERINFO               0x15a0
#define PA_LOGICALLANEMAP              0x15a1
#define PA_SLEEPNOCONFIGTIME           0x15a2
#define PA_STALLNOCONFIGTIME           0x15a3
#define PA_SAVECONFIGTIME              0x15a4
#define PA_RXHSUNTERMINATIONCAPABILITY 0x15a5
#define PA_RXLSTERMINATIONCAPABILITY   0x15a6
#define PA_HIBERN8TIME                 0x15a7
#define PA_TACTIVATE                   0x15a8
#define PA_LOCALVERINFO                0x15a9
#define PA_GRANULARITY                 0x15aa
#define PA_MK2EXTENSIONGUARDBAND       0x15ab
#define PA_PWRMODEUSERDATA0            0x15b0
#define PA_PWRMODEUSERDATA1            0x15b1
#define PA_PWRMODEUSERDATA2            0x15b2
#define PA_PWRMODEUSERDATA3            0x15b3
#define PA_PWRMODEUSERDATA4            0x15b4
#define PA_PWRMODEUSERDATA5            0x15b5
#define PA_PWRMODEUSERDATA6            0x15b6
#define PA_PWRMODEUSERDATA7            0x15b7
#define PA_PWRMODEUSERDATA8            0x15b8
#define PA_PWRMODEUSERDATA9            0x15b9
#define PA_PWRMODEUSERDATA10           0x15ba
#define PA_PWRMODEUSERDATA11           0x15bb
#define PA_PACPFRAMECOUNT              0x15c0
#define PA_PACPERRORCOUNT              0x15c1
#define PA_PHYTESTCONTROL              0x15c2

/*
 * L2 attributes
 */
#define DL_TXPREEMPTIONCAP         0x2000
#define DL_TC0TXMAXSDUSIZE         0x2001
#define DL_TC0RXINITCREDITVAL      0x2002
#define DL_TC1TXMAXSDUSIZE         0x2003
#define DL_TC1RXINITCREDITVAL      0x2004
#define DL_TC0TXBUFFERSIZE         0x2005
#define DL_TC1TXBUFFERSIZE         0x2006
#define DL_TC0TXFCTHRESHOLD        0x2040
#define DL_FC0PROTECTIONTIMEOUTVAL 0x2041
#define DL_TC0REPLAYTIMEOUTVAL     0x2042
#define DL_AFC0REQTIMEOUTVAL       0x2043
#define DL_AFC0CREDITTHRESHOLD     0x2044
#define DL_TC0OUTACKTHRESHOLD      0x2045
#define DL_PEERTC0PRESENT          0x2046
#define DL_PEERTC0RXINITCREDITVAL  0x2047
#define DL_TC1TXFCTHRESHOLD        0x2060
#define DL_FC1PROTECTIONTIMEOUTVAL 0x2061
#define DL_TC1REPLAYTIMEOUTVAL     0x2062
#define DL_AFC1REQTIMEOUTVAL       0x2063
#define DL_AFC1CREDITTHRESHOLD     0x2064
#define DL_TC1OUTACKTHRESHOLD      0x2065
#define DL_PEERTC1PRESENT          0x2066
#define DL_PEERTC1RXINITCREDITVAL  0x2067

/*
 * L3 attributes
 */
#define N_DEVICEID        0x3000
#define N_DEVICEID_VALID  0x3001
#define N_TC0TXMAXSDUSIZE 0x3020
#define N_TC1TXMAXSDUSIZE 0x3021

/*
 * L4 attributes
 */
#define T_NUMCPORTS                  0x4000
#define T_NUMTESTFEATURES            0x4001
#define T_TC0TXMAXSDUSIZE            0x4060
#define T_TC1TXMAXSDUSIZE            0x4061
#define T_TSTCPORTID                 0x4080
#define T_TSTSRCON                   0x4081
#define T_TSTSRCPATTERN              0x4082
#define T_TSTSRCINCREMENT            0x4083
#define T_TSTSRCMESSAGESIZE          0x4084
#define T_TSTSRCMESSAGECOUNT         0x4085
#define T_TSTSRCINTERMESSAGEGAP      0x4086
#define T_TSTDSTON                   0x40a1
#define T_TSTDSTERRORDETECTIONENABLE 0x40a2
#define T_TSTDSTPATTERN              0x40a3
#define T_TSTDSTINCEMENT             0x40a4
#define T_TSTDSTMESSAGECOUNT         0x40a5
#define T_TSTDSTMESSAGEOFFSET        0x40a6
#define T_TSTDSTMESSAGESIZE          0x40a7
#define T_TSTDSTFCCREDITS            0x40a8
#define T_TSTDSTINTERFCTOKENGAP      0x40a9
#define T_TSTDSTINITIALFCCREDITS     0x40aa
#define T_TSTDSTERRORCODE            0x40ab
#define T_PEERDEVICEID               0x4021
#define T_PEERCPORTID                0x4022
#define T_CONNECTIONSTATE            0x4020
#define T_TRAFFICCLASS               0x4023
    #define CPORT_TC0               (0x0)
    #define CPORT_TC1               (0x1)
#define T_PROTOCOLID                 0x4024
#define T_CPORTFLAGS                 0x4025
    #define CPORT_FLAGS_E2EFC       (1)
    #define CPORT_FLAGS_CSD_N       (2)
    #define CPORT_FLAGS_CSV_N       (4)
#define T_TXTOKENVALUE               0x4026
#define T_RXTOKENVALUE               0x4027
#define T_LOCALBUFFERSPACE           0x4028
#define T_PEERBUFFERSPACE            0x4029
#define T_CREDITSTOSEND              0x402a
#define T_CPORTMODE                  0x402b
    #define CPORT_MODE_APPLICATION  (1)
    #define CPORT_MODE_UNDER_TEST   (2)

/*
 * DME attributes
 * NB. The chip manufacturer hard-wires the values of
 * DME_DDBL1_REVISION..DME_DDBL1_LENGTH.
 */
#define DME_DDBL1_REVISION          0x5000
#define DME_DDBL1_LEVEL             0x5001
#define DME_DDBL1_DEVICECLASS       0x5002
#define DME_DDBL1_MANUFACTURERID    0x5003
#define DME_DDBL1_PRODUCTID         0x5004
#define DME_DDBL1_LENGTH            0x5005
#define DME_DDBL2_VID               0x6000
#define DME_DDBL2_PID               0x6001
#define DME_DDBL2_SERIALNO_L        0x6002
#define DME_DDBL2_SERIALNO_H        0x6003
#define DME_DDBL2_INIT_TYPE         0x6100
    #define INIT_TYPE_TOSHIBA                                    (0x01260001)
#define DME_DDBL2_INIT_STATUS       0x6101
    #define INIT_STATUS_UNINITIALIZED                            (0x000000000)
    #define INIT_STATUS_OPERATING                                (1 << 24)
    #define INIT_STATUS_SPI_BOOT_STARTED                         (2 << 24)
    #define INIT_STATUS_TRUSTED_SPI_FLASH_BOOT_FINISHED          (3 << 24)
    #define INIT_STATUS_UNTRUSTED_SPI_FLASH_BOOT_FINISHED        (4 << 24)
    #define INIT_STATUS_UNIPRO_BOOT_STARTED                      (6 << 24)
    #define INIT_STATUS_TRUSTED_UNIPRO_BOOT_FINISHED             (7 << 24)
    #define INIT_STATUS_UNTRUSTED_UNIPRO_BOOT_FINISHED           (8 << 24)
    #define INIT_STATUS_FALLLBACK_UNIPRO_BOOT_STARTED            (9 << 24)
    #define INIT_STATUS_FALLLBACK_TRUSTED_UNIPRO_BOOT_FINISHED   (10 << 24)
    #define INIT_STATUS_FALLLBACK_UNTRUSTED_UNIPRO_BOOT_FINISHED (11 << 24)
    #define INIT_STATUS_RESUMED_FROM_STANDBY                     (12 << 24)
    #define INIT_STATUS_FAILED                                   (0x80000000)
    #define INIT_STATUS_ERROR_MASK                               (0x80000000)
    #define INIT_STATUS_STATUS_MASK                              (0x7f000000)
    #define INIT_STATUS_ERROR_CODE_MASK                          (0x00ffffff)
#define DME_DDBL2_ENDPOINTID_H      0x6102
#define DME_DDBL2_ENDPOINTID_L      0x6103
#define DME_FC0PROTECTIONTIMEOUTVAL 0xd041
#define DME_TC0REPLAYTIMEOUTVAL     0xd042
#define DME_AFC0REQTIMEOUTVAL       0xd043
#define DME_FC1PROTECTIONTIMEOUTVAL 0xd044
#define DME_TC1REPLAYTIMEOUTVAL     0xd045
#define DME_AFC1REQTIMEOUTVAL       0xd046

/*
 * Switch attributes and related values
 */
#define TSB_INTERRUPTSTATUS        0xd081
#define TSB_MAILBOX                0xa000

/*
 * Mailbox attribute values
 */
#define TSB_MAIL_RESET              (0x00)
#define TSB_MAIL_READY_AP           (0x01)
#define TSB_MAIL_READY_OTHER        (0x02)

/*
 * Interrupt Status attribute values
 */
#define TSB_INTERRUPTSTATUS_MAILBOX (1 << 15)

/**
 * @brief Synchronously read from local mailbox.
 * @return 0 on success, <0 on error
 */
int read_mailbox(uint32_t *val);
/**
 * @brief Acknowledge that we've read local mailbox, clearing it.
 * @return 0 on success, <0 on error
 */
int ack_mailbox(void);
/**
 * @brief Synchronously write to the peer mailbox, polling for it to be cleared
 * once we've written it.
 * @return 0 on success, <0 on error
 */
int write_mailbox(uint32_t val);

/**
 * @brief Abstract out the chip-common parts of advertising readiness.
 */
int advertise_ready(void);

#endif /* __COMMON_INCLUDE_UNIPRO_H */
