/** Generated code, do not change!
 ** Written by Protection Wrapper Generator (V 2.0.1)
 ** Module: E2EPW_BmwMsgSlot274Bas0Repn8BusFrChA_sigGroup_SU_EPS_sigGroup_SU_EPS_tx.h
 ** Thu, 26-Oct-2017, 17:45:02
 **/

#ifndef E2EPW_BmwMsgSlot274Bas0Repn8BusFrChA_sigGroup_SU_EPS_sigGroup_SU_EPS_TX_H
#define E2EPW_BmwMsgSlot274Bas0Repn8BusFrChA_sigGroup_SU_EPS_sigGroup_SU_EPS_TX_H

#include "Rte_Type.h"
#include "E2E_P01.h"

#define BmwMsgSlot274Bas0Repn8BusFrChA_START_SEC_CODE
#include "BmwMsgSlot274Bas0Repn8BusFrChA_MemMap.h"

/**********************************************************
 * Function name: E2EPW_Init_sigGroup_SU_EPS_sigGroup_SU_EPS_tx ()
 * Description:   Initialize the E2Elib transmission-state.
 * Parameter:     None
 * Return value:  None
 * Remarks:       Call this function after an application or
 *                communication startup or reset and prior
 *                to any other E2EPW API-call.
 **********************************************************/
extern FUNC (void, BmwMsgSlot274Bas0Repn8BusFrChA_CODE) E2EPW_WriteInit_sigGroup_SU_EPS_sigGroup_SU_EPS (void);

/**********************************************************
 * Function name: E2EPW_Get_SenderState_sigGroup_SU_EPS_sigGroup_SU_EPS ()
 * Description:   Returns a pointer to the current E2Elib
 *                transmission-state.
 * Parameter:     None
 * Return value:  The current E2Elib transmission-status
 * Remarks:       Can be used to manipulate the state.
 *                Use this function with care.
 **********************************************************/
extern FUNC_P2VAR ( E2E_P01ProtectStateType
                  , BmwMsgSlot274Bas0Repn8BusFrChA_VAR_NOINIT
                  , BmwMsgSlot274Bas0Repn8BusFrChA_CODE
                  )
    E2EPW_Get_ProtectState_sigGroup_SU_EPS_sigGroup_SU_EPS (void);

/**********************************************************
 * Function name: E2EPW_Write_sigGroup_SU_EPS_sigGroup_SU_EPS (sigGroup_SU_EPS *  AppData);
 * Description:   Protects data with E2Elib, transmits it
 *                with Rte_Write_<p>_<o> and return an
 *                error-code.
 *   Parameter AppData:
 *                The data to be protected and transmitted.
 * Return value:  Error-code
 * Remarks:       None
 **********************************************************/
extern FUNC (uint32, BmwMsgSlot274Bas0Repn8BusFrChA_CODE) E2EPW_Write_sigGroup_SU_EPS_sigGroup_SU_EPS
    (P2VAR (sigGroup_SU_EPS1, AUTOMATIC, BmwMsgSlot274Bas0Repn8BusFrChA_VAR_INIT) AppData);

#define BmwMsgSlot274Bas0Repn8BusFrChA_STOP_SEC_CODE
#include "BmwMsgSlot274Bas0Repn8BusFrChA_MemMap.h"

#endif
/*  << EOF >>  */