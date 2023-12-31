/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  File: Effort.c
 *  SW-C Type:Effort
 *  C/C++ source code generated on : Tue May 22 11:55:58 2018
   Code generated for Simulink model 'Effort'.
 ***********************************************************************************************************************
   Tool Information
 *-----------------------------------------------------------------------------------------------------------------------
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 **********************************************************************************************************************
 * Copyright '2018' Nexteer
 * Nexteer Confidential
 *
 * Module File Name  : Effort.c
 * Module Description: This function produces a handwheel reference torque for the closed loop system.
 * Project           : CBD
 * Author            : Nimmy Mathews
 ***********************************************************************************************************************
 * Version Control:
 * %version:  		4 %
 * %derived_by:      dzvc93%
 **********************************************************************************************************************
 * CHANGE LOG COPIED FROM SIMULINK MODEL
 *---------------------------------------
 * Change Log:

   v2.1.0
   Date: 21 May 2018
   Change Control #: EA4#24062
   Author: Nimmy Mathews
   Description:
   -Added Polarity Correction to change the polarity of
   the output HwTqCmdEffort


   v2.0.0
   Date: 30 Apr 2018
   Change Control #: EA4#22637
   Author: Nimmy Mathews
   Description:
   - Added new input EffortCmdSca
   - Added blending between EffortCmdSca and a constant value

   v1.0.1
   Date: 19 Feb 2018
   Change Control #: EA4#20871
   Author: Nimmy Mathews
   Description:
   - Design updated for autocoding without any functionality change.

   v1.0.0
   Date: 29 Nov 2017
 **********************************************************************************************************************/
/*********************File Level Rule Deviations**********************************************************************/

/* MISRA-AGC Rule 16.10 [NXTRDEV 16.10.1]: There is no appropriate action to take on the return value for Rte_Read, Rte_Write */
/* MISRA-AGC Rule 19.1  [NXTRDEV 19.1.1]:  AUTOSAR requires deviation from this rule for Memory Mapping include statements */

/* MISRA-AGC Rule 8.1   [NXTRDEV 8.1.1] :  Deviation for autocode only, due to tools limitation.
   �_Init� function does not have a declaration/prototype in autocode. This init function is generated by embedded coder and is not present in the Simulink model.
   This function is always empty and is not called */

/* MISRA-AGC Rule 8.10  [NXTRDEV 8.10.2]:  Deviation for autocode only, due to tools limitation.
   �_Init� function is not defined as �static� even though no external linkage is required. This init function is generated by embedded coder and is not present in the Simulink model.
   This function is always empty and is not called */

/*********************End of File Level Rule Deviations***************************************************************/
#include "Effort.h"
#define Effort_START_SEC_CODE
#include "Effort_MemMap.h"

/*
 * Check that imported macros with storage class "ImportedDefine" are defined
 */
#ifndef NXTRFIXDPT_FLOATTOP0_ULS_F32
#error The variable for the parameter "NXTRFIXDPT_FLOATTOP0_ULS_F32" is not defined
#endif

#ifndef NXTRFIXDPT_FLOATTOP1_ULS_F32
#error The variable for the parameter "NXTRFIXDPT_FLOATTOP1_ULS_F32" is not defined
#endif

#ifndef NXTRFIXDPT_FLOATTOP7_ULS_F32
#error The variable for the parameter "NXTRFIXDPT_FLOATTOP7_ULS_F32" is not defined
#endif

#ifndef NXTRFIXDPT_P12TOFLOAT_ULS_F32
#error The variable for the parameter "NXTRFIXDPT_P12TOFLOAT_ULS_F32" is not defined
#endif

#ifndef NXTRFIXDPT_P15TOFLOAT_ULS_F32
#error The variable for the parameter "NXTRFIXDPT_P15TOFLOAT_ULS_F32" is not defined
#endif

/* Exported data define */

/* Definition for custom storage class: Const_Local */
#define EFFORTSCADFT_ULS_F32           ((float32)(1.0F))
#define HWTQCMDEFFORTHILIM_HWNWTMTR_F32 ((float32)(10.0F))
#define HWTQCMDEFFORTLOLIM_HWNWTMTR_F32 ((float32)(-10.0F))
#define POLARITYCORRN_ULS_F32          ((float32)(-1.0F))

/* Model step function for TID1 */
FUNC(void, Effort_CODE) EffortInit1(void) /* Sample time: [0.002s, 0.0s] */
{
  /* (no output/update code required) */
}

/* Model step function for TID2 */
FUNC(void, Effort_CODE) EffortPer1(void) /* Sample time: [0.002s, 0.0s] */
{
  /* local block i/o variables */
  float32 rtb_TmpSignalConversionAtRackFE;
  float32 rtb_Subtract1;
  float32 rtb_Product1;
  float32 rtb_FixdToFloat_f32_u16_n;
  sint8 rtb_Sign_s08_f32;
  float32 tmpRead;
  float32 tmpRead_0;
  float32 tmpWrite;

  /* Inport: '<Root>/EffortCmdSca' */
  Rte_Read_EffortCmdSca_Val(&tmpRead_0);

  /* Inport: '<Root>/VehSpd' */
  Rte_Read_VehSpd_Val(&tmpRead);

  /* RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_call_EffortPer1_at_outport_1' incorporates:
   *  SubSystem: '<S1>/EffortPer1'
   */
  /* SignalConversion: '<S4>/TmpSignal ConversionAtRackFEstimdOutport1' incorporates:
   *  Inport: '<Root>/RackFEstimd'
   */
  Rte_Read_RackFEstimd_Val(&rtb_TmpSignalConversionAtRackFE);

  /* Sum: '<S5>/Subtract1' incorporates:
   *  Constant: '<S5>/Constant: Add to DD (Imported cal?)2'
   *  S-Function (Abslt_f32_f32): '<S5>/Abslt_f32_f32'
   */
  rtb_Subtract1 = Abslt_f32_f32( (float32)rtb_TmpSignalConversionAtRackFE) -
    Rte_Prm_EffortScaRackFThd_Val();

  /* S-Function (FixdToFloat_f32_u16): '<S12>/FixdToFloat_f32_u16' incorporates:
   *  Constant: '<S11>/Constant'
   *  Constant: '<S11>/Constant1'
   *  Constant: '<S11>/Constant2'
   *  Constant: '<S12>/Constant'
   *  Constant: '<S13>/Constant'
   *  Constant: '<S14>/Constant'
   *  Inport: '<Root>/VehSpd'
   *  S-Function (Abslt_f32_f32): '<S7>/Abslt_f32_f32'
   *  S-Function (BilnrIntrpnWithRound_u16_u16MplXu16MplY): '<S11>/BilnrIntrpnWithRound_u16_u16MplXu16MplY'
   *  S-Function (FloatToFixd_u16_f32): '<S13>/FloatToFixd_u16_f32'
   *  S-Function (FloatToFixd_u16_f32): '<S14>/FloatToFixd_u16_f32'
   */
  rtb_FixdToFloat_f32_u16_n = FixdToFloat_f32_u16( (uint16)((uint16)
    BilnrIntrpnWithRound_u16_u16MplXu16MplY(((uint16)FloatToFixd_u16_f32
    ( (float32)tmpRead, (float32)((float32)NXTRFIXDPT_FLOATTOP7_ULS_F32))),
    ((uint16)FloatToFixd_u16_f32( (float32)Abslt_f32_f32( (float32)
    rtb_TmpSignalConversionAtRackFE), (float32)((float32)
    NXTRFIXDPT_FLOATTOP1_ULS_F32))), (const uint16*)
    Rte_Prm_EffortVehSpdBilnrSeln_Ary1D(),(uint16)10U, (const uint16*)
    Rte_Prm_EffortRackFX_Ary2D(), (const uint16*)Rte_Prm_EffortRackFY_Ary2D(),
    (uint16)24U)), (float32)((float32)NXTRFIXDPT_P12TOFLOAT_ULS_F32));

  /* S-Function (Sign_s08_f32): '<S7>/Sign_s08_f32' */
  rtb_Sign_s08_f32 = Sign_s08_f32( (float32)rtb_TmpSignalConversionAtRackFE);

  /* Product: '<S4>/Product1' incorporates:
   *  Constant: '<S10>/Constant'
   *  Constant: '<S10>/Constant1'
   *  Constant: '<S4>/Constant'
   *  Constant: '<S5>/Constant: Add to DD (Imported cal?)13'
   *  Constant: '<S5>/Constant: Add to DD (Imported cal?)2'
   *  Constant: '<S8>/Constant'
   *  Constant: '<S9>/Constant'
   *  Inport: '<Root>/EffortCmdSca'
   *  Product: '<S4>/Product'
   *  Product: '<S7>/Product'
   *  S-Function (Abslt_f32_f32): '<S5>/Abslt_f32_f32'
   *  S-Function (Blnd_f32): '<S5>/Blnd_f32'
   *  S-Function (FixdToFloat_f32_u16): '<S8>/FixdToFloat_f32_u16'
   *  S-Function (FloatToFixd_s16_f32): '<S9>/FloatToFixd_s16_f32'
   *  S-Function (LnrIntrpn_u16_s16VariXu16VariY): '<S10>/LnrIntrpn_u16_s16VariXu16VariY'
   *  Sum: '<S5>/Subtract1'
   */
  rtb_Product1 = ((rtb_FixdToFloat_f32_u16_n * ((float32)rtb_Sign_s08_f32)) *
                  Blnd_f32( (float32)EFFORTSCADFT_ULS_F32, (float32)tmpRead_0,
    (float32)FixdToFloat_f32_u16( (uint16)((uint16)
    LnrIntrpn_u16_s16VariXu16VariY((const sint16*)Rte_Prm_EffortScaBlndX_Ary1D(),
    (const uint16*)Rte_Prm_EffortScaBlndY_Ary1D(),(uint16)10U, ((sint16)
    FloatToFixd_s16_f32( (float32)rtb_Subtract1, (float32)((float32)
    NXTRFIXDPT_FLOATTOP0_ULS_F32))))), (float32)((float32)
    NXTRFIXDPT_P15TOFLOAT_ULS_F32)))) * POLARITYCORRN_ULS_F32;

  /* S-Function (Lim_f32): '<S6>/Lim_f32' incorporates:
   *  Constant: '<S6>/Constant'
   *  Constant: '<S6>/Constant1'
   *  Outport: '<Root>/HwTqCmdEffort'
   */
  tmpWrite = Lim_f32( (float32)rtb_Product1, (float32)
                     HWTQCMDEFFORTLOLIM_HWNWTMTR_F32, (float32)
                     HWTQCMDEFFORTHILIM_HWNWTMTR_F32);

  /* End of Outputs for RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_call_EffortPer1_at_outport_1' */

  /* Outport: '<Root>/HwTqCmdEffort' */
  (void) Rte_Write_HwTqCmdEffort_Val(tmpWrite);
}

/* Model initialize function */
FUNC(void, Effort_CODE) Effort_Init(void)
{
  /* (no initialization code required) */
}

#define Effort_STOP_SEC_CODE
#include "Effort_MemMap.h"

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
