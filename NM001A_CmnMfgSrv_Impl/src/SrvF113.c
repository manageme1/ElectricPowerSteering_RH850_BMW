/***********************************************************************************************************************
* Copyright 2015 Nexteer
* Nexteer Confidential
*
* Module File Name: SrvF113.c
* Module Description: 0xF113 - Defeat Inertial Compensation
* Project           : Common Manufacturing Services
* Author            : Jared Julien
************************************************************************************************************************
* Version Control:
* %version:         2 %
* %derived_by:      kzdyfh %
* ---------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author    Change Description                                                           SCR #
* --------  -------  --------  ---------------------------------------------------------------------------  ----------
* 08/11/15  1        JWJ       Initial file creation                                                        EA4#1332
* 10/15/15  2        JWJ       Moved Rte write to main CmnMfgSrv.c file                                     EA4#2034
* 01/26/16  3        JWJ       Updates for newly generated function names                                   EA4#2518
***********************************************************************************************************************/

/* ================================================================================================================== */
/* Includes */
/* ------------------------------------------------------------------------------------------------------------------ */
#include "Rte_CmnMfgSrv.h"
#include "CmnMfgSrv.h"
#include "CmnMfgSrvTyp.h"
#include "MfgSrvCfg.h"


/* ================================================================================================================== */
/* Service Function Definitions */
/* ------------------------------------------------------------------------------------------------------------------ */

/* ---------------------------------------------------------------------------------------------------------------------
 *        Name:  CmnMfgSrv_SrvF113RoutineStrt
 * Description:  0xF113: Defeat Inertia Compensation Start
 *          ID:  0xF113
 *        Type:  0x31 (Routine)
 *    Sub-Func:  0x01 (Start)
 *    Req. Len:  0 bytes
 *   Resp. Len:  0 bytes
 * ------------------------------------------------------------------------------------------------------------------ */
#if (CMNMFGSRV_F113ENA_CNT_LGC == CMNMFGSRV_ENAD_CNT_LGC)
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvF113RoutineStrt(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[])
{
	VAR(NegRespCodEnum, AUTOMATIC) RspCod_Cnt_T_enum = MFGSRVNRCPOSRSP;

	*Rte_Pim_DiInertiaCmp() = TRUE;

	return RspCod_Cnt_T_enum;
}
#endif


/* ---------------------------------------------------------------------------------------------------------------------
 *        Name:  CmnMfgSrv_SrvF113RoutineStop
 * Description:  0xF113: Defeat Inertia Compensation Stop
 *          ID:  0xF113
 *        Type:  0x31 (Routine)
 *    Sub-Func:  0x02 (Stop)
 *    Req. Len:  0 bytes
 *   Resp. Len:  0 bytes
 * ------------------------------------------------------------------------------------------------------------------ */
#if (CMNMFGSRV_F113ENA_CNT_LGC == CMNMFGSRV_ENAD_CNT_LGC)
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvF113RoutineStop(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[])
{
	VAR(NegRespCodEnum, AUTOMATIC) RspCod_Cnt_T_enum = MFGSRVNRCPOSRSP;

	*Rte_Pim_DiInertiaCmp() = FALSE;

	return RspCod_Cnt_T_enum;
}
#endif


/* ---------------------------------------------------------------------------------------------------------------------
 *        Name:  CmnMfgSrv_SrvF113RoutineSts
 * Description:  0xF113: Defeat Inertia Compensation Results
 *          ID:  0xF113
 *        Type:  0x31 (Routine)
 *    Sub-Func:  0x03 (Status)
 *    Req. Len:  0 bytes
 *   Resp. Len:  1 byte
 * ------------------------------------------------------------------------------------------------------------------ */
#if (CMNMFGSRV_F113ENA_CNT_LGC == CMNMFGSRV_ENAD_CNT_LGC)
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvF113RoutineSts(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[])
{
	VAR(NegRespCodEnum, AUTOMATIC) RspCod_Cnt_T_enum = MFGSRVNRCPOSRSP;

	DataBuf_Uls_T_u08[0U] = (uint8)(*Rte_Pim_DiInertiaCmp());

	return RspCod_Cnt_T_enum;
}
#endif


/* End of File: SrvF113.c */
