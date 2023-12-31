/***********************************************************************************************************************
 *  COPYRIGHT
 *  --------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2017 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  --------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/**
 *  \ingroup    Os_Hal
 *  \addtogroup Os_Hal_Timer_OSTM
 *
 *  \{
 *
 *  \file       Os_Hal_Timer_OSTM.h
 *  \brief
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os_Hal_Os.h.
 **********************************************************************************************************************/

#if !defined(OS_HAL_TIMER_OSTM_H)                                                                                       /* PRQA S 0883 */ /* MD_Os_Hal_0883 */
# define OS_HAL_TIMER_OSTM_H

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
# include "Os_Hal_Timer_OSTMInt.h"
# include "Os_Hal_Compiler.h"
# include "Os_Hal_Interrupt.h"

/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_19.1 */

/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  Os_Hal_TimerPitInit_OSTM()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Hal_3219 */
Os_Hal_TimerPitInit_OSTM,
(
  P2CONST(Os_Hal_TimerPitConfigType, AUTOMATIC, OS_CONST) TimerConfig
))                                                                                                                      /* COV_OS_HALTIMEROSTMUNSUPPORTED_XX */
{
  /* #10 Initialize timer's hardware. */
  Os_Hal_OSTMRefType TimerRef = (Os_Hal_OSTMRefType)(TimerConfig->TimerBaseAddr);                                       /* PRQA S 0303 */ /* MD_Os_Hal_0303 */
  TimerRef->osOSTMnTT  = 1;                                                                                             /* SBSW_OS_HAL_PWA_PITCONFIG */
  TimerRef->osOSTMnCTL = 0;                                                                                             /* SBSW_OS_HAL_PWA_PITCONFIG */
  TimerRef->osOSTMnCMP = TimerConfig->CompareValue;                                                                     /* SBSW_OS_HAL_PWA_PITCONFIG */
  TimerRef->osOSTMnTS  = 1;                                                                                             /* SBSW_OS_HAL_PWA_PITCONFIG */
}

/***********************************************************************************************************************
 *  Os_Hal_TimerFrtInit_OSTM()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Hal_3219 */
Os_Hal_TimerFrtInit_OSTM,
(
  P2CONST(Os_Hal_TimerFrtConfigType, AUTOMATIC, OS_CONST) TimerConfig
))                                                                                                                      /* COV_OS_HALTIMEROSTMUNSUPPORTED_XX */
{
  /* #10 Initialize the given timer hardware. */
  Os_Hal_OSTMRefType TimerRef = (Os_Hal_OSTMRefType)(TimerConfig->TimerBaseAddr);                                       /* PRQA S 0303 */ /* MD_Os_Hal_0303 */
  TimerRef->osOSTMnTT  = 1;                                                                                             /* SBSW_OS_HAL_PWA_FRTCONFIG */
  TimerRef->osOSTMnCTL = 2;                                                                                             /* SBSW_OS_HAL_PWA_FRTCONFIG */
  TimerRef->osOSTMnCMP = TimerConfig->CompareValue;                                                                     /* SBSW_OS_HAL_PWA_FRTCONFIG */
  TimerRef->osOSTMnTS  = 1;                                                                                             /* SBSW_OS_HAL_PWA_FRTCONFIG */
}

/***********************************************************************************************************************
 *  Os_Hal_GetCounterValue_OSTM()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_Hal_TimerFrtTickType, OS_CODE, OS_ALWAYS_INLINE,                        /* PRQA S 3219 */ /* MD_Os_Hal_3219 */
Os_Hal_GetCounterValue_OSTM,
(
  P2CONST(Os_Hal_TimerFrtConfigType, AUTOMATIC, OS_CONST) TimerConfig
))                                                                                                                      /* COV_OS_HALTIMEROSTMUNSUPPORTED_XX */
{
  return ((Os_Hal_OSTMRefType)TimerConfig->TimerBaseAddr)->osOSTMnCNT;                                                  /* PRQA S 0303 */ /* MD_Os_Hal_0303 */
}

/***********************************************************************************************************************
 *  Os_Hal_SetCompareValue_OSTM()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Hal_3219 */
Os_Hal_SetCompareValue_OSTM,
(
  P2CONST(Os_Hal_TimerFrtConfigType, AUTOMATIC, OS_CONST) TimerConfig,
  Os_Hal_TimerFrtTickType ExpirationTime
))                                                                                                                      /* COV_OS_HALTIMEROSTMUNSUPPORTED_XX */
{
  ((Os_Hal_OSTMRefType)TimerConfig->TimerBaseAddr)->osOSTMnCMP = ExpirationTime;                                        /* PRQA S 0303 */ /* MD_Os_Hal_0303 */ /* SBSW_OS_HAL_PWA_FRTCONFIG */
}

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_19.1 */

#endif /* OS_HAL_TIMER_OSTM_H */

/*!
 * \}
 */

/***********************************************************************************************************************
 *  END OF FILE: Os_Hal_Timer_OSTM.h
 **********************************************************************************************************************/

