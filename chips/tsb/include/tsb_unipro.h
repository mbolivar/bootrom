/*
 * Copyright (c) 2014 Google Inc.
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

#ifndef __ARCH_ARM_SRC_TSB_TSB_UNIPRO_H
#define __ARCH_ARM_SRC_TSB_TSB_UNIPRO_H

#include "chip.h"
#include "unipro.h"

#define CPORT_STATUS_0                         0x00000000
    #define CPORT_STATUS_CONNECTED                  (0x0)
    #define CPORT_STATUS_DISCONNECTED               (0x1)
#define CPORT_STATUS_1                         0x00000004
#define CPORT_STATUS_2                         0x00000008
#define CPORT_CREDIT_0                         0x0000000C
#define CPORT_CREDIT_1                         0x00000010
#define UNIPRO_INT_AFT                         0x00000100
#define AHS_TIMEOUT_INT_AFT_0                  0x00000104
#define AHS_TIMEOUT_INT_AFT_1                  0x00000108
#define AHM_HRESP_ERR_INT_AFT_0                0x0000010C
#define AHM_HRESP_ERR_INT_AFT_1                0x00000110
#define CPB_RX_E2EFC_RSLT_ERR_INT_AFT_0        0x0000011C
#define CPB_RX_E2EFC_RSLT_ERR_INT_AFT_1        0x00000120
#define CPB_TX_RSLTCODE_ERR_INT_AFT_0          0x00000124
#define CPB_TX_RSLTCODE_ERR_INT_AFT_1          0x00000128
#define CPB_RX_MSGST_ERR_INT_AFT_0             0x0000012C
#define CPB_RX_MSGST_ERR_INT_AFT_1             0x00000130
#define LUP_INT_AFT                            0x00000134
#define A2D_ATTRACS_INT_AFT                    0x00000138
#define AHM_RX_EOM_INT_AFT_0                   0x0000013C
#define AHM_RX_EOM_INT_AFT_1                   0x00000140
#define AHM_RX_EOM_INT_AFT_2                   0x00000144
#define AHM_RX_EOT_INT_AFT_0                   0x00000148
#define AHM_RX_EOT_INT_AFT_1                   0x0000014C
#define UNIPRO_INT_EN                          0x00000200
#define AHS_TIMEOUT_INT_EN_0                   0x00000204
#define AHS_TIMEOUT_INT_EN_1                   0x00000208
#define AHM_HRESP_ERR_INT_EN_0                 0x0000020C
#define AHM_HRESP_ERR_INT_EN_1                 0x00000210
#define CPB_RX_E2EFC_RSLT_ERR_INT_EN_0         0x0000021C
#define CPB_RX_E2EFC_RSLT_ERR_INT_EN_1         0x00000220
#define CPB_TX_RSLTCODE_ERR_INT_EN_0           0x00000224
#define CPB_TX_RSLTCODE_ERR_INT_EN_1           0x00000228
#define CPB_RX_MSGST_ERR_INT_EN_0              0x0000022C
#define CPB_RX_MSGST_ERR_INT_EN_1              0x00000230
#define LUP_INT_EN                             0x00000234
#define A2D_ATTRACS_INT_EN                     0x00000238
#define AHM_RX_EOM_INT_EN_0                    0x0000023C
#define AHM_RX_EOM_INT_EN_1                    0x00000240
#define AHM_RX_EOM_INT_EN_2                    0x00000244
#define AHM_RX_EOT_INT_EN_0                    0x00000248
#define AHM_RX_EOT_INT_EN_1                    0x0000024C
#define UNIPRO_INT_BEF                         0x00000300
#define AHS_TIMEOUT_INT_BEF_0                  0x00000304
#define AHS_TIMEOUT_INT_BEF_1                  0x00000308
#define AHM_HRESP_ERR_INT_BEF_0                0x0000030C
#define AHM_HRESP_ERR_INT_BEF_1                0x00000310
#define CPB_RX_E2EFC_RSLT_ERR_INT_BEF_0        0x0000031C
#define CPB_RX_E2EFC_RSLT_ERR_INT_BEF_1        0x00000320
#define CPB_TX_RSLTCODE_ERR_INT_BEF_0          0x00000324
#define CPB_TX_RSLTCODE_ERR_INT_BEF_1          0x00000328
#define CPB_RX_MSGST_ERR_INT_BEF_0             0x0000032C
#define CPB_RX_MSGST_ERR_INT_BEF_1             0x00000330
#define LUP_INT_BEF                            0x00000334
#define A2D_ATTRACS_INT_BEF                    0x00000338
#define AHM_RX_EOM_INT_BEF_0                   0x0000033C
#define AHM_RX_EOM_INT_BEF_1                   0x00000340
#define AHM_RX_EOM_INT_BEF_2                   0x00000344
#define AHM_RX_EOT_INT_BEF_0                   0x00000348
#define AHM_RX_EOT_INT_BEF_1                   0x0000034C
#define LUP_LINKSUP_STOP                       0x00000400
#define LUP_LINKSUP_RESTART                    0x00000404
#define A2D_ATTRACS_MSTR_CTRL                  0x00000500
    #define REG_ATTRACS_UPD                    (0x1)
    #define REG_ATTRACS_CNT(x)                 ((x) << 16)
#define A2D_ATTRACS_CTRL_00                    0x00000504
#define A2D_ATTRACS_CTRL_01                    0x00000508
#define A2D_ATTRACS_CTRL_02                    0x0000050C
#define A2D_ATTRACS_CTRL_03                    0x00000510
#define A2D_ATTRACS_CTRL_04                    0x00000514
#define A2D_ATTRACS_CTRL_05                    0x00000518
#define A2D_ATTRACS_CTRL_06                    0x0000051C
#define A2D_ATTRACS_CTRL_07                    0x00000520
#define A2D_ATTRACS_CTRL_08                    0x00000524
#define A2D_ATTRACS_CTRL_09                    0x00000528
#define A2D_ATTRACS_CTRL_10                    0x0000052C
#define A2D_ATTRACS_CTRL_11                    0x00000530
#define A2D_ATTRACS_CTRL_12                    0x00000534
#define A2D_ATTRACS_CTRL_13                    0x00000538
#define A2D_ATTRACS_CTRL_14                    0x0000053C
#define A2D_ATTRACS_CTRL_15                    0x00000540
    #define REG_ATTRACS_CTRL_PEERENA(x)        (!!(x) << 29)
    #define REG_ATTRACS_CTRL_SELECT(x)         (((x) & 0x7FF) << 16)
    #define REG_ATTRACS_CTRL_WRITE(x)          (!!(x) << 28)
#define A2D_ATTRACS_DATA_CTRL_00               0x00000550
#define A2D_ATTRACS_DATA_CTRL_01               0x00000554
#define A2D_ATTRACS_DATA_CTRL_02               0x00000558
#define A2D_ATTRACS_DATA_CTRL_03               0x0000055C
#define A2D_ATTRACS_DATA_CTRL_04               0x00000560
#define A2D_ATTRACS_DATA_CTRL_05               0x00000564
#define A2D_ATTRACS_DATA_CTRL_06               0x00000568
#define A2D_ATTRACS_DATA_CTRL_07               0x0000056C
#define A2D_ATTRACS_DATA_CTRL_08               0x00000570
#define A2D_ATTRACS_DATA_CTRL_09               0x00000574
#define A2D_ATTRACS_DATA_CTRL_10               0x00000578
#define A2D_ATTRACS_DATA_CTRL_11               0x0000057C
#define A2D_ATTRACS_DATA_CTRL_12               0x00000580
#define A2D_ATTRACS_DATA_CTRL_13               0x00000584
#define A2D_ATTRACS_DATA_CTRL_14               0x00000588
#define A2D_ATTRACS_DATA_CTRL_15               0x0000058C
#define A2D_ATTRACS_STS_00                     0x00000590
#define A2D_ATTRACS_STS_01                     0x00000594
#define A2D_ATTRACS_DATA_STS_00                0x000005A0
#define A2D_ATTRACS_DATA_STS_01                0x000005A4
#define A2D_ATTRACS_DATA_STS_02                0x000005A8
#define A2D_ATTRACS_DATA_STS_03                0x000005AC
#define A2D_ATTRACS_DATA_STS_04                0x000005B0
#define A2D_ATTRACS_DATA_STS_05                0x000005B4
#define A2D_ATTRACS_DATA_STS_06                0x000005B8
#define A2D_ATTRACS_DATA_STS_07                0x000005BC
#define A2D_ATTRACS_DATA_STS_08                0x000005C0
#define A2D_ATTRACS_DATA_STS_09                0x000005C4
#define A2D_ATTRACS_DATA_STS_10                0x000005C8
#define A2D_ATTRACS_DATA_STS_11                0x000005CC
#define A2D_ATTRACS_DATA_STS_12                0x000005D0
#define A2D_ATTRACS_DATA_STS_13                0x000005D4
#define A2D_ATTRACS_DATA_STS_14                0x000005D8
#define A2D_ATTRACS_DATA_STS_15                0x000005DC
#define CPA_DEEPSTALL_CTRL                     0x00000600
#define CPA_ARBITER_CTRL                       0x00000604
#define CPA_WRIF_TC_CTRL_0                     0x00000608
#define CPA_WRIF_TC_CTRL_1                     0x0000060C
#define AHM_MODE_CTRL_0                        0x00000610
#define AHM_MODE_CTRL_1                        0x00000614
#define AHM_MODE_CTRL_2                        0x00000618
#define CPB_TX_E2EFC_EN_0                      0x0000061C
#define CPB_TX_E2EFC_EN_1                      0x00000620
#define CPB_RX_E2EFC_EN_0                      0x00000624
#define CPB_RX_E2EFC_EN_1                      0x00000628
#define TX_CLK_ENA_0                           0x0000062C
#define TX_CLK_ENA_1                           0x00000630
#define RX_CLK_ENA_0                           0x00000634
#define RX_CLK_ENA_1                           0x00000638
#define AHS_HRESP_MODE_0                       0x0000063C
#define AHS_HRESP_MODE_1                       0x00000640
#define AHS_TIMEOUT_00                         0x00000700
#define AHS_TIMEOUT_01                         0x00000704
#define AHS_TIMEOUT_02                         0x00000708
#define AHS_TIMEOUT_03                         0x0000070C
#define AHS_TIMEOUT_04                         0x00000710
#define AHS_TIMEOUT_05                         0x00000714
#define AHS_TIMEOUT_06                         0x00000718
#define AHS_TIMEOUT_07                         0x0000071C
#define AHS_TIMEOUT_08                         0x00000720
#define AHS_TIMEOUT_09                         0x00000724
#define AHS_TIMEOUT_10                         0x00000728
#define AHS_TIMEOUT_11                         0x0000072C
#define AHS_TIMEOUT_12                         0x00000730
#define AHS_TIMEOUT_13                         0x00000734
#define AHS_TIMEOUT_14                         0x00000738
#define AHS_TIMEOUT_15                         0x0000073C
#define AHS_TIMEOUT_18                         0x00000740
#define AHS_TIMEOUT_19                         0x00000744
#define AHS_TIMEOUT_20                         0x00000748
#define AHS_TIMEOUT_21                         0x0000074C
#define AHS_TIMEOUT_22                         0x00000750
#define AHS_TIMEOUT_23                         0x00000754
#define AHS_TIMEOUT_24                         0x00000758
#define AHS_TIMEOUT_25                         0x0000075C
#define AHS_TIMEOUT_26                         0x00000760
#define AHS_TIMEOUT_27                         0x00000764
#define AHS_TIMEOUT_28                         0x00000768
#define AHS_TIMEOUT_29                         0x0000076C
#define AHS_TIMEOUT_30                         0x00000770
#define AHS_TIMEOUT_31                         0x00000774
#define AHS_TIMEOUT_32                         0x00000778
#define AHS_TIMEOUT_33                         0x0000077C
#define AHS_TIMEOUT_34                         0x00000780
#define AHS_TIMEOUT_35                         0x00000784
#define AHS_TIMEOUT_36                         0x00000788
#define AHS_TIMEOUT_37                         0x0000078C
#define AHS_TIMEOUT_38                         0x00000790
#define AHS_TIMEOUT_39                         0x00000794
#define AHS_TIMEOUT_40                         0x00000798
#define AHS_TIMEOUT_41                         0x0000079C
#define AHS_TIMEOUT_42                         0x000007A0
#define AHS_TIMEOUT_43                         0x000007A4
#define AHM_ADDRESS_00                         0x00000800
#define AHM_ADDRESS_01                         0x00000804
#define AHM_ADDRESS_02                         0x00000808
#define AHM_ADDRESS_03                         0x0000080C
#define AHM_ADDRESS_04                         0x00000810
#define AHM_ADDRESS_05                         0x00000814
#define AHM_ADDRESS_06                         0x00000818
#define AHM_ADDRESS_07                         0x0000081C
#define AHM_ADDRESS_08                         0x00000820
#define AHM_ADDRESS_09                         0x00000824
#define AHM_ADDRESS_10                         0x00000828
#define AHM_ADDRESS_11                         0x0000082C
#define AHM_ADDRESS_12                         0x00000830
#define AHM_ADDRESS_13                         0x00000834
#define AHM_ADDRESS_14                         0x00000838
#define AHM_ADDRESS_15                         0x0000083C
#define AHM_ADDRESS_18                         0x00000840
#define AHM_ADDRESS_19                         0x00000844
#define AHM_ADDRESS_20                         0x00000848
#define AHM_ADDRESS_21                         0x0000084C
#define AHM_ADDRESS_22                         0x00000850
#define AHM_ADDRESS_23                         0x00000854
#define AHM_ADDRESS_24                         0x00000858
#define AHM_ADDRESS_25                         0x0000085C
#define AHM_ADDRESS_26                         0x00000860
#define AHM_ADDRESS_27                         0x00000864
#define AHM_ADDRESS_28                         0x00000868
#define AHM_ADDRESS_29                         0x0000086C
#define AHM_ADDRESS_30                         0x00000870
#define AHM_ADDRESS_31                         0x00000874
#define AHM_ADDRESS_32                         0x00000878
#define AHM_ADDRESS_33                         0x0000087C
#define AHM_ADDRESS_34                         0x00000880
#define AHM_ADDRESS_35                         0x00000884
#define AHM_ADDRESS_36                         0x00000888
#define AHM_ADDRESS_37                         0x0000088C
#define AHM_ADDRESS_38                         0x00000890
#define AHM_ADDRESS_39                         0x00000894
#define AHM_ADDRESS_40                         0x00000898
#define AHM_ADDRESS_41                         0x0000089C
#define AHM_ADDRESS_42                         0x000008A0
#define AHM_ADDRESS_43                         0x000008A4
#define CPB_RX_E2EFC_RETRY_TIMES_00            0x00000900
#define CPB_RX_E2EFC_RETRY_TIMES_01            0x00000904
#define CPB_RX_E2EFC_RETRY_TIMES_02            0x00000908
#define CPB_RX_E2EFC_RETRY_TIMES_03            0x0000090C
#define CPB_RX_E2EFC_RETRY_TIMES_04            0x00000910
#define CPB_RX_E2EFC_RETRY_TIMES_05            0x00000914
#define CPB_RX_E2EFC_RETRY_TIMES_06            0x00000918
#define CPB_RX_E2EFC_RETRY_TIMES_07            0x0000091C
#define CPB_RX_E2EFC_RETRY_TIMES_08            0x00000920
#define CPB_RX_E2EFC_RETRY_TIMES_09            0x00000924
#define CPB_RX_E2EFC_RETRY_TIMES_10            0x00000928
#define CPB_RX_E2EFC_RETRY_TIMES_11            0x0000092C
#define CPB_RX_E2EFC_RETRY_TIMES_12            0x00000930
#define CPB_RX_E2EFC_RETRY_TIMES_13            0x00000934
#define CPB_RX_E2EFC_RETRY_TIMES_14            0x00000938
#define CPB_RX_E2EFC_RETRY_TIMES_15            0x0000093C
#define CPB_RX_E2EFC_RETRY_TIMES_16            0x00000940
#define CPB_RX_E2EFC_RETRY_TIMES_17            0x00000944
#define CPB_RX_E2EFC_RETRY_TIMES_18            0x00000948
#define CPB_RX_E2EFC_RETRY_TIMES_19            0x0000094C
#define CPB_RX_E2EFC_RETRY_TIMES_20            0x00000950
#define CPB_RX_E2EFC_RETRY_TIMES_21            0x00000954
#define CPB_RX_E2EFC_RETRY_TIMES_22            0x00000958
#define CPB_RX_E2EFC_RETRY_TIMES_23            0x0000095C
#define CPB_RX_E2EFC_RETRY_TIMES_24            0x00000960
#define CPB_RX_E2EFC_RETRY_TIMES_25            0x00000964
#define CPB_RX_E2EFC_RETRY_TIMES_26            0x00000968
#define CPB_RX_E2EFC_RETRY_TIMES_27            0x0000096C
#define CPB_RX_E2EFC_RETRY_TIMES_28            0x00000970
#define CPB_RX_E2EFC_RETRY_TIMES_29            0x00000974
#define CPB_RX_E2EFC_RETRY_TIMES_30            0x00000978
#define CPB_RX_E2EFC_RETRY_TIMES_31            0x0000097C
#define CPB_RX_E2EFC_RETRY_TIMES_32            0x00000980
#define CPB_RX_E2EFC_RETRY_TIMES_33            0x00000984
#define CPB_RX_E2EFC_RETRY_TIMES_34            0x00000988
#define CPB_RX_E2EFC_RETRY_TIMES_35            0x0000098C
#define CPB_RX_E2EFC_RETRY_TIMES_36            0x00000990
#define CPB_RX_E2EFC_RETRY_TIMES_37            0x00000994
#define CPB_RX_E2EFC_RETRY_TIMES_38            0x00000998
#define CPB_RX_E2EFC_RETRY_TIMES_39            0x0000099C
#define CPB_RX_E2EFC_RETRY_TIMES_40            0x000009A0
#define CPB_RX_E2EFC_RETRY_TIMES_41            0x000009A4
#define CPB_RX_E2EFC_RETRY_TIMES_42            0x000009A8
#define CPB_RX_E2EFC_RETRY_TIMES_43            0x000009AC
#define CPB_TXQUEUEEMPTY_0                     0x00000F08
#define CPB_TXQUEUEEMPTY_1                     0x00000F0C
#define CPB_TXDATAEMPTY_0                      0x00000F10
#define CPB_TXDATAEMPTY_1                      0x00000F14
#define CPB_RXDATAEMPTY_0                      0x00000F18
#define CPB_RXDATAEMPTY_1                      0x00000F1C
#define CPB_RX_E2EFC_RSLTCODE_0                0x00000F20
#define CPB_RX_E2EFC_RSLTCODE_1                0x00000F24
#define CPB_RX_E2EFC_RSLTCODE_2                0x00000F28
#define CPB_RX_E2EFC_RSLTCODE_3                0x00000F2C
#define CPB_RX_E2EFC_RSLTCODE_4                0x00000F30
#define CPB_RX_E2EFC_RSLTCODE_5                0x00000F34
#define CPB_TX_RESULTCODE_0                    0x00000F40
#define CPB_TX_RESULTCODE_1                    0x00000F44
#define CPB_TX_RESULTCODE_2                    0x00000F48
#define CPB_TX_RESULTCODE_3                    0x00000F4C
#define CPB_TX_RESULTCODE_4                    0x00000F50
#define CPB_TX_RESULTCODE_5                    0x00000F54
#define CPB_TX_BUFFER_SPACE_00                 0x00001000
#define CPB_TX_BUFFER_SPACE_01                 0x00001004
#define CPB_TX_BUFFER_SPACE_02                 0x00001008
#define CPB_TX_BUFFER_SPACE_03                 0x0000100C
#define CPB_TX_BUFFER_SPACE_04                 0x00001010
#define CPB_TX_BUFFER_SPACE_05                 0x00001014
#define CPB_TX_BUFFER_SPACE_06                 0x00001018
#define CPB_TX_BUFFER_SPACE_07                 0x0000101C
#define CPB_TX_BUFFER_SPACE_08                 0x00001020
#define CPB_TX_BUFFER_SPACE_09                 0x00001024
#define CPB_TX_BUFFER_SPACE_10                 0x00001028
#define CPB_TX_BUFFER_SPACE_11                 0x0000102C
#define CPB_TX_BUFFER_SPACE_12                 0x00001030
#define CPB_TX_BUFFER_SPACE_13                 0x00001034
#define CPB_TX_BUFFER_SPACE_14                 0x00001038
#define CPB_TX_BUFFER_SPACE_15                 0x0000103C
#define CPB_TX_BUFFER_SPACE_16                 0x00001040
#define CPB_TX_BUFFER_SPACE_17                 0x00001044
#define CPB_TX_BUFFER_SPACE_18                 0x00001048
#define CPB_TX_BUFFER_SPACE_19                 0x0000104C
#define CPB_TX_BUFFER_SPACE_20                 0x00001050
#define CPB_TX_BUFFER_SPACE_21                 0x00001054
#define CPB_TX_BUFFER_SPACE_22                 0x00001058
#define CPB_TX_BUFFER_SPACE_23                 0x0000105C
#define CPB_TX_BUFFER_SPACE_24                 0x00001060
#define CPB_TX_BUFFER_SPACE_25                 0x00001064
#define CPB_TX_BUFFER_SPACE_26                 0x00001068
#define CPB_TX_BUFFER_SPACE_27                 0x0000106C
#define CPB_TX_BUFFER_SPACE_28                 0x00001070
#define CPB_TX_BUFFER_SPACE_29                 0x00001074
#define CPB_TX_BUFFER_SPACE_30                 0x00001078
#define CPB_TX_BUFFER_SPACE_31                 0x0000107C
#define CPB_TX_BUFFER_SPACE_32                 0x00001080
#define CPB_TX_BUFFER_SPACE_33                 0x00001084
#define CPB_TX_BUFFER_SPACE_34                 0x00001088
#define CPB_TX_BUFFER_SPACE_35                 0x0000108C
#define CPB_TX_BUFFER_SPACE_36                 0x00001090
#define CPB_TX_BUFFER_SPACE_37                 0x00001094
#define CPB_TX_BUFFER_SPACE_38                 0x00001098
#define CPB_TX_BUFFER_SPACE_39                 0x0000109C
#define CPB_TX_BUFFER_SPACE_40                 0x000010A0
#define CPB_TX_BUFFER_SPACE_41                 0x000010A4
#define CPB_TX_BUFFER_SPACE_42                 0x000010A8
#define CPB_TX_BUFFER_SPACE_43                 0x000010AC
#define REG_TX_BUFFER_SPACE_OFFSET_00          0x00001100
#define REG_TX_BUFFER_SPACE_OFFSET_01          0x00001104
#define REG_TX_BUFFER_SPACE_OFFSET_02          0x00001108
#define REG_TX_BUFFER_SPACE_OFFSET_03          0x0000110C
#define REG_TX_BUFFER_SPACE_OFFSET_04          0x00001110
#define REG_TX_BUFFER_SPACE_OFFSET_05          0x00001114
#define REG_TX_BUFFER_SPACE_OFFSET_06          0x00001118
#define REG_TX_BUFFER_SPACE_OFFSET_07          0x0000111C
#define REG_TX_BUFFER_SPACE_OFFSET_08          0x00001120
#define REG_TX_BUFFER_SPACE_OFFSET_09          0x00001124
#define REG_TX_BUFFER_SPACE_OFFSET_10          0x00001128
#define REG_TX_BUFFER_SPACE_OFFSET_11          0x0000112C
#define REG_TX_BUFFER_SPACE_OFFSET_12          0x00001130
#define REG_TX_BUFFER_SPACE_OFFSET_13          0x00001134
#define REG_TX_BUFFER_SPACE_OFFSET_14          0x00001138
#define REG_TX_BUFFER_SPACE_OFFSET_15          0x0000113C
#define REG_TX_BUFFER_SPACE_OFFSET_16          0x00001140
#define REG_TX_BUFFER_SPACE_OFFSET_17          0x00001144
#define REG_TX_BUFFER_SPACE_OFFSET_18          0x00001148
#define REG_TX_BUFFER_SPACE_OFFSET_19          0x0000114C
#define REG_TX_BUFFER_SPACE_OFFSET_20          0x00001150
#define REG_TX_BUFFER_SPACE_OFFSET_21          0x00001154
#define REG_TX_BUFFER_SPACE_OFFSET_22          0x00001158
#define REG_TX_BUFFER_SPACE_OFFSET_23          0x0000115C
#define REG_TX_BUFFER_SPACE_OFFSET_24          0x00001160
#define REG_TX_BUFFER_SPACE_OFFSET_25          0x00001164
#define REG_TX_BUFFER_SPACE_OFFSET_26          0x00001168
#define REG_TX_BUFFER_SPACE_OFFSET_27          0x0000116C
#define REG_TX_BUFFER_SPACE_OFFSET_28          0x00001170
#define REG_TX_BUFFER_SPACE_OFFSET_29          0x00001174
#define REG_TX_BUFFER_SPACE_OFFSET_30          0x00001178
#define REG_TX_BUFFER_SPACE_OFFSET_31          0x0000117C
#define REG_TX_BUFFER_SPACE_OFFSET_32          0x00001180
#define REG_TX_BUFFER_SPACE_OFFSET_33          0x00001184
#define REG_TX_BUFFER_SPACE_OFFSET_34          0x00001188
#define REG_TX_BUFFER_SPACE_OFFSET_35          0x0000118C
#define REG_TX_BUFFER_SPACE_OFFSET_36          0x00001190
#define REG_TX_BUFFER_SPACE_OFFSET_37          0x00001194
#define REG_TX_BUFFER_SPACE_OFFSET_38          0x00001198
#define REG_TX_BUFFER_SPACE_OFFSET_39          0x0000119C
#define REG_TX_BUFFER_SPACE_OFFSET_40          0x000011A0
#define REG_TX_BUFFER_SPACE_OFFSET_41          0x000011A4
#define REG_TX_BUFFER_SPACE_OFFSET_42          0x000011A8
#define REG_TX_BUFFER_SPACE_OFFSET_43          0x000011AC
#define REG_RX_PAUSE_SIZE_00                   0x00001200
#define REG_RX_PAUSE_SIZE_01                   0x00001204
#define REG_RX_PAUSE_SIZE_02                   0x00001208
#define REG_RX_PAUSE_SIZE_03                   0x0000120C
#define REG_RX_PAUSE_SIZE_04                   0x00001210
#define REG_RX_PAUSE_SIZE_05                   0x00001214
#define REG_RX_PAUSE_SIZE_06                   0x00001218
#define REG_RX_PAUSE_SIZE_07                   0x0000121C
#define REG_RX_PAUSE_SIZE_08                   0x00001220
#define REG_RX_PAUSE_SIZE_09                   0x00001224
#define REG_RX_PAUSE_SIZE_10                   0x00001228
#define REG_RX_PAUSE_SIZE_11                   0x0000122C
#define REG_RX_PAUSE_SIZE_12                   0x00001230
#define REG_RX_PAUSE_SIZE_13                   0x00001234
#define REG_RX_PAUSE_SIZE_14                   0x00001238
#define REG_RX_PAUSE_SIZE_15                   0x0000123C
#define REG_RX_PAUSE_SIZE_16                   0x00001240
#define REG_RX_PAUSE_SIZE_17                   0x00001244
#define REG_RX_PAUSE_SIZE_18                   0x00001248
#define REG_RX_PAUSE_SIZE_19                   0x0000124C
#define REG_RX_PAUSE_SIZE_20                   0x00001250
#define REG_RX_PAUSE_SIZE_21                   0x00001254
#define REG_RX_PAUSE_SIZE_22                   0x00001258
#define REG_RX_PAUSE_SIZE_23                   0x0000125C
#define REG_RX_PAUSE_SIZE_24                   0x00001260
#define REG_RX_PAUSE_SIZE_25                   0x00001264
#define REG_RX_PAUSE_SIZE_26                   0x00001268
#define REG_RX_PAUSE_SIZE_27                   0x0000126C
#define REG_RX_PAUSE_SIZE_28                   0x00001270
#define REG_RX_PAUSE_SIZE_29                   0x00001274
#define REG_RX_PAUSE_SIZE_30                   0x00001278
#define REG_RX_PAUSE_SIZE_31                   0x0000127C
#define REG_RX_PAUSE_SIZE_32                   0x00001280
#define REG_RX_PAUSE_SIZE_33                   0x00001284
#define REG_RX_PAUSE_SIZE_34                   0x00001288
#define REG_RX_PAUSE_SIZE_35                   0x0000128C
#define REG_RX_PAUSE_SIZE_36                   0x00001290
#define REG_RX_PAUSE_SIZE_37                   0x00001294
#define REG_RX_PAUSE_SIZE_38                   0x00001298
#define REG_RX_PAUSE_SIZE_39                   0x0000129C
#define REG_RX_PAUSE_SIZE_40                   0x000012A0
#define REG_RX_PAUSE_SIZE_41                   0x000012A4
#define REG_RX_PAUSE_SIZE_42                   0x000012A8
#define REG_RX_PAUSE_SIZE_43                   0x000012AC
    #define RX_PAUSE_RESTART                   0x80000000
#define CPB_RX_TRANSFERRED_DATA_SIZE_00        0x00001300
#define CPB_RX_TRANSFERRED_DATA_SIZE_01        0x00001304
#define CPB_RX_TRANSFERRED_DATA_SIZE_02        0x00001308
#define CPB_RX_TRANSFERRED_DATA_SIZE_03        0x0000130C
#define CPB_RX_TRANSFERRED_DATA_SIZE_04        0x00001310
#define CPB_RX_TRANSFERRED_DATA_SIZE_05        0x00001314
#define CPB_RX_TRANSFERRED_DATA_SIZE_06        0x00001318
#define CPB_RX_TRANSFERRED_DATA_SIZE_07        0x0000131C
#define CPB_RX_TRANSFERRED_DATA_SIZE_08        0x00001320
#define CPB_RX_TRANSFERRED_DATA_SIZE_09        0x00001324
#define CPB_RX_TRANSFERRED_DATA_SIZE_10        0x00001328
#define CPB_RX_TRANSFERRED_DATA_SIZE_11        0x0000132C
#define CPB_RX_TRANSFERRED_DATA_SIZE_12        0x00001330
#define CPB_RX_TRANSFERRED_DATA_SIZE_13        0x00001334
#define CPB_RX_TRANSFERRED_DATA_SIZE_14        0x00001338
#define CPB_RX_TRANSFERRED_DATA_SIZE_15        0x0000133C
#define CPB_RX_TRANSFERRED_DATA_SIZE_16        0x00001340
#define CPB_RX_TRANSFERRED_DATA_SIZE_17        0x00001344
#define CPB_RX_TRANSFERRED_DATA_SIZE_18        0x00001348
#define CPB_RX_TRANSFERRED_DATA_SIZE_19        0x0000134C
#define CPB_RX_TRANSFERRED_DATA_SIZE_20        0x00001350
#define CPB_RX_TRANSFERRED_DATA_SIZE_21        0x00001354
#define CPB_RX_TRANSFERRED_DATA_SIZE_22        0x00001358
#define CPB_RX_TRANSFERRED_DATA_SIZE_23        0x0000135C
#define CPB_RX_TRANSFERRED_DATA_SIZE_24        0x00001360
#define CPB_RX_TRANSFERRED_DATA_SIZE_25        0x00001364
#define CPB_RX_TRANSFERRED_DATA_SIZE_26        0x00001368
#define CPB_RX_TRANSFERRED_DATA_SIZE_27        0x0000136C
#define CPB_RX_TRANSFERRED_DATA_SIZE_28        0x00001370
#define CPB_RX_TRANSFERRED_DATA_SIZE_29        0x00001374
#define CPB_RX_TRANSFERRED_DATA_SIZE_30        0x00001378
#define CPB_RX_TRANSFERRED_DATA_SIZE_31        0x0000137C
#define CPB_RX_TRANSFERRED_DATA_SIZE_32        0x00001380
#define CPB_RX_TRANSFERRED_DATA_SIZE_33        0x00001384
#define CPB_RX_TRANSFERRED_DATA_SIZE_34        0x00001388
#define CPB_RX_TRANSFERRED_DATA_SIZE_35        0x0000138C
#define CPB_RX_TRANSFERRED_DATA_SIZE_36        0x00001390
#define CPB_RX_TRANSFERRED_DATA_SIZE_37        0x00001394
#define CPB_RX_TRANSFERRED_DATA_SIZE_38        0x00001398
#define CPB_RX_TRANSFERRED_DATA_SIZE_39        0x0000139C
#define CPB_RX_TRANSFERRED_DATA_SIZE_40        0x000013A0
#define CPB_RX_TRANSFERRED_DATA_SIZE_41        0x000013A4
#define CPB_RX_TRANSFERRED_DATA_SIZE_42        0x000013A8
#define CPB_RX_TRANSFERRED_DATA_SIZE_43        0x000013AC
#define TX_SW_RESET_00                         0x00001400
#define TX_SW_RESET_01                         0x00001404
#define TX_SW_RESET_02                         0x00001408
#define TX_SW_RESET_03                         0x0000140C
#define TX_SW_RESET_04                         0x00001410
#define TX_SW_RESET_05                         0x00001414
#define TX_SW_RESET_06                         0x00001418
#define TX_SW_RESET_07                         0x0000141C
#define TX_SW_RESET_08                         0x00001420
#define TX_SW_RESET_09                         0x00001424
#define TX_SW_RESET_10                         0x00001428
#define TX_SW_RESET_11                         0x0000142C
#define TX_SW_RESET_12                         0x00001430
#define TX_SW_RESET_13                         0x00001434
#define TX_SW_RESET_14                         0x00001438
#define TX_SW_RESET_15                         0x0000143C
#define TX_SW_RESET_16                         0x00001440
#define TX_SW_RESET_17                         0x00001444
#define TX_SW_RESET_18                         0x00001448
#define TX_SW_RESET_19                         0x0000144C
#define TX_SW_RESET_20                         0x00001450
#define TX_SW_RESET_21                         0x00001454
#define TX_SW_RESET_22                         0x00001458
#define TX_SW_RESET_23                         0x0000145C
#define TX_SW_RESET_24                         0x00001460
#define TX_SW_RESET_25                         0x00001464
#define TX_SW_RESET_26                         0x00001468
#define TX_SW_RESET_27                         0x0000146C
#define TX_SW_RESET_28                         0x00001470
#define TX_SW_RESET_29                         0x00001474
#define TX_SW_RESET_30                         0x00001478
#define TX_SW_RESET_31                         0x0000147C
#define TX_SW_RESET_32                         0x00001480
#define TX_SW_RESET_33                         0x00001484
#define TX_SW_RESET_34                         0x00001488
#define TX_SW_RESET_35                         0x0000148C
#define TX_SW_RESET_36                         0x00001490
#define TX_SW_RESET_37                         0x00001494
#define TX_SW_RESET_38                         0x00001498
#define TX_SW_RESET_39                         0x0000149C
#define TX_SW_RESET_40                         0x000014A0
#define TX_SW_RESET_41                         0x000014A4
#define TX_SW_RESET_42                         0x000014A8
#define TX_SW_RESET_43                         0x000014AC
#define RX_SW_RESET_00                         0x00001500
#define RX_SW_RESET_01                         0x00001504
#define RX_SW_RESET_02                         0x00001508
#define RX_SW_RESET_03                         0x0000150C
#define RX_SW_RESET_04                         0x00001510
#define RX_SW_RESET_05                         0x00001514
#define RX_SW_RESET_06                         0x00001518
#define RX_SW_RESET_07                         0x0000151C
#define RX_SW_RESET_08                         0x00001520
#define RX_SW_RESET_09                         0x00001524
#define RX_SW_RESET_10                         0x00001528
#define RX_SW_RESET_11                         0x0000152C
#define RX_SW_RESET_12                         0x00001530
#define RX_SW_RESET_13                         0x00001534
#define RX_SW_RESET_14                         0x00001538
#define RX_SW_RESET_15                         0x0000153C
#define RX_SW_RESET_16                         0x00001540
#define RX_SW_RESET_17                         0x00001544
#define RX_SW_RESET_18                         0x00001548
#define RX_SW_RESET_19                         0x0000154C
#define RX_SW_RESET_20                         0x00001550
#define RX_SW_RESET_21                         0x00001554
#define RX_SW_RESET_22                         0x00001558
#define RX_SW_RESET_23                         0x0000155C
#define RX_SW_RESET_24                         0x00001560
#define RX_SW_RESET_25                         0x00001564
#define RX_SW_RESET_26                         0x00001568
#define RX_SW_RESET_27                         0x0000156C
#define RX_SW_RESET_28                         0x00001570
#define RX_SW_RESET_29                         0x00001574
#define RX_SW_RESET_30                         0x00001578
#define RX_SW_RESET_31                         0x0000157C
#define RX_SW_RESET_32                         0x00001580
#define RX_SW_RESET_33                         0x00001584
#define RX_SW_RESET_34                         0x00001588
#define RX_SW_RESET_35                         0x0000158C
#define RX_SW_RESET_36                         0x00001590
#define RX_SW_RESET_37                         0x00001594
#define RX_SW_RESET_38                         0x00001598
#define RX_SW_RESET_39                         0x0000159C
#define RX_SW_RESET_40                         0x000015A0
#define RX_SW_RESET_41                         0x000015A4
#define RX_SW_RESET_42                         0x000015A8
#define RX_SW_RESET_43                         0x000015AC

#define TSB_MAXSEGMENTCONFIG        0xd089

#define CPORT_BUF_SIZE            (0x2000U)
#define CPORT_RX_BUF_BASE         (0x20000000U)
#define CPORT_RX_BUF_SIZE         (CPORT_BUF_SIZE)
#define CPORT_RX_BUF(cport)       (void*)(CPORT_RX_BUF_BASE + \
                                      (CPORT_RX_BUF_SIZE * cport))
#define CPORT_TX_BUF_BASE         (0x50000000U)
#define CPORT_TX_BUF_SIZE         (0x20000U)
#define CPORT_TX_BUF(cport)       (uint8_t*)(CPORT_TX_BUF_BASE + \
                                      (CPORT_TX_BUF_SIZE * cport))
#define CPORT_EOM_BIT(cport)      (cport->tx_buf + (CPORT_TX_BUF_SIZE - 1))

/*
 * Common UniPro structures and functions
 */

#define DECLARE_CPORT(id) {            \
    .tx_buf      = CPORT_TX_BUF(id),   \
    .rx_buf      = CPORT_RX_BUF(id),   \
    .cportid     = id,                 \
}

struct cport {
    uint8_t *tx_buf;                /* TX region for this CPort */
    uint8_t *rx_buf;                /* RX region for this CPort */
    uint16_t cportid;
};

extern struct cport cporttable[4];
#define CPORT_MAX  (sizeof(cporttable)/sizeof(struct cport))

static inline struct cport *cport_handle(uint16_t cportid) {
    if (cportid >= CPORT_MAX) {
        return NULL;
    } else {
        return &cporttable[cportid];
    }
}

int tsb_reset_all_cports(void);

int tsb_unipro_init_cport(uint32_t cportid);
int tsb_unipro_recv_cport(uint32_t *cportid);

uint32_t tsb_unipro_read(uint32_t offset);
void tsb_unipro_write(uint32_t offset, uint32_t v);
void tsb_unipro_restart_rx(struct cport *cport);

/**
 * @brief Enable E2EFC on a specific CPort
 * @param cportid cport on which to enable End-to-End Flow Control
 */
void tsb_enable_e2efc(uint16_t cportid);
/**
 * @brief Disable E2EFC on all CPorts
 */
void tsb_disable_all_e2efc(void);

/**
 * @brief Chip-common parts of resetting before signalling readiness.
 */
void tsb_reset_before_ready(void);

#endif /* __ARCH_ARM_SRC_TSB_TSB_UNIPRO_H */
