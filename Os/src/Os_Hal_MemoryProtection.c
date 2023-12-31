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
 *  \addtogroup Os_Hal_MemoryProtection
 *  \{
 *
 *  \file       Os_Hal_MemoryProtection.c
 *  \brief      This component handles the memory protection unit.
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os_Hal_Os.h.
 **********************************************************************************************************************/

                                                                                                                        /* PRQA S 0777, 0779, 0810, 0828, 0857 EOF */ /* MD_MSR_5.1_777, MD_MSR_5.1_779, MD_MSR_1.1_810, MD_MSR_1.1_828, MD_MSR_1.1_857 */

#define OS_HAL_MEMORYPROTECTION_SOURCE

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_Hal_MemoryProtection.h"

/* Os module dependencies */
#include "Os_Cfg.h"
#include "Os_Kernel.h"

/* Os HAL dependencies */
#include "Os_Hal_Compiler.h"

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

#define OS_START_SEC_CODE
#include "Os_MemMap_OsCode.h"                                                                                           /* PRQA S 5087 */ /* MD_MSR_19.1 */

/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  Os_Hal_MpSystemInit()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, OS_CODE) Os_Hal_MpSystemInit(P2CONST(Os_Hal_MpSystemConfigType , TYPEDEF, OS_CONST) SystemConfig)
{
  /* #10 Nothing to be done. */
  OS_IGNORE_UNREF_PARAM(SystemConfig);                                                                                  /* PRQA S 3112 */ /* MD_Os_Hal_3112 */
}

/***********************************************************************************************************************
 *  Os_Hal_MpCoreInit()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 */
FUNC(void, OS_CODE) Os_Hal_MpCoreInit
(
  P2CONST(Os_Hal_MpCoreConfigType, TYPEDEF, OS_CONST) CoreConfig,
  P2CONST(Os_Hal_ContextStackConfigType, AUTOMATIC, OS_VAR_NOINIT) InitialStackRegion
)
{
  /* #10 Switch off MPU. */
  Os_Hal_SetMPM(OS_HAL_MPU_DISABLE); 

  /* #20 Configure all MPU regions except for the stack region. */
  Os_Hal_MpuConfigSwitch(CoreConfig);                                                                                   /* SBSW_OS_HAL_FC_CALLER */

  /* #30 Set the MPU region 0 for stacks. */
  Os_Hal_SetMPLA0(InitialStackRegion->Os_Hal_StackStart);
  Os_Hal_SetMPUA0(InitialStackRegion->Os_Hal_StackEnd);
  Os_Hal_SetMPAT0(OS_HAL_MPU_MPAT0);

  /* #40 Set ASID. */
  Os_Hal_SetASID(CoreConfig->MpuASID);

  /* #50 Synchronize the pipeline. */
  Os_Hal_SyncPipeline();

  /* #60 Switch on MPU. */
  Os_Hal_SetMPM(OS_HAL_MPU_ENABLE);

  /* #70 Synchronize the instructions. */
  Os_Hal_SyncInstruction();
}

#define OS_STOP_SEC_CODE
#include "Os_MemMap_OsCode.h"                                                                                           /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*!
 * \}
 */

/***********************************************************************************************************************
 *  END OF FILE: Os_Hal_MemoryProtection.c
 **********************************************************************************************************************/

