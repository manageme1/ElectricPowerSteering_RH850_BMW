/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Rte_BmwMsgSlot234Bas1Repn2BusFrChA.h
 *        Config:  C:/_PratikJadhav/_Synergy_Projects/Working/MM526A_BmwMsgSlot234Bas1Repn2BusFrChA_Impl/tools/Component.dpa
 *     SW-C Type:  BmwMsgSlot234Bas1Repn2BusFrChA
 *  Generated at:  Fri Apr 27 09:35:10 2018
 *
 *     Generator:  MICROSAR RTE Generator Version 4.13.0
 *                 RTE Core Version 1.13.0
 *       License:  Unlimited license CBD1400351 for Nexteer Automotive Corporation
 *
 *   Description:  Application header file for SW-C <BmwMsgSlot234Bas1Repn2BusFrChA> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_BMWMSGSLOT234BAS1REPN2BUSFRCHA_H
# define _RTE_BMWMSGSLOT234BAS1REPN2BUSFRCHA_H

# ifdef RTE_APPLICATION_HEADER_FILE
#  error Multiple application header files included.
# endif
# define RTE_APPLICATION_HEADER_FILE
# ifndef RTE_PTR2ARRAYBASETYPE_PASSING
#  define RTE_PTR2ARRAYBASETYPE_PASSING
# endif

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

/* include files */

# include "Rte_BmwMsgSlot234Bas1Repn2BusFrChA_Type.h"
# include "Rte_DataHandleType.h"


/**********************************************************************************************************************
 * Component Data Structures and Port Data Structures
 *********************************************************************************************************************/

struct Rte_CDS_BmwMsgSlot234Bas1Repn2BusFrChA
{
  /* PIM Handles section */
  P2VAR(BmwEpsFctSts1, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_BmwEpsFctStsPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_BurstModCntr; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_CycCntr; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(DrvgDynIfSt1, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_DrvgDynIfStPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(HaptcFbSt1, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_HaptcFbStPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_PerdCntr; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  /* Vendor specific section */
};

# define RTE_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern CONSTP2CONST(struct Rte_CDS_BmwMsgSlot234Bas1Repn2BusFrChA, RTE_CONST, RTE_CONST) Rte_Inst_BmwMsgSlot234Bas1Repn2BusFrChA; /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

typedef P2CONST(struct Rte_CDS_BmwMsgSlot234Bas1Repn2BusFrChA, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_BmwEpsFctSts_Val (128U)
# define Rte_InitValue_DrvgDynIfSt_Val (128U)
# define Rte_InitValue_HaptcFbSt_Val (14U)


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwMsgSlot234Bas1Repn2BusFrChA_BmwEpsFctSts_Val(P2VAR(BmwEpsFctSts1, AUTOMATIC, RTE_BMWMSGSLOT234BAS1REPN2BUSFRCHA_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwMsgSlot234Bas1Repn2BusFrChA_DrvgDynIfSt_Val(P2VAR(DrvgDynIfSt1, AUTOMATIC, RTE_BMWMSGSLOT234BAS1REPN2BUSFRCHA_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwMsgSlot234Bas1Repn2BusFrChA_HaptcFbSt_Val(P2VAR(HaptcFbSt1, AUTOMATIC, RTE_BMWMSGSLOT234BAS1REPN2BUSFRCHA_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwMsgSlot234Bas1Repn2BusFrChA_sigGroup_ST_EST_sigGroup_ST_EST(P2CONST(sigGroup_ST_EST1, AUTOMATIC, RTE_BMWMSGSLOT234BAS1REPN2BUSFRCHA_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */



/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Read_BmwEpsFctSts_Val Rte_Read_BmwMsgSlot234Bas1Repn2BusFrChA_BmwEpsFctSts_Val
# define Rte_Read_DrvgDynIfSt_Val Rte_Read_BmwMsgSlot234Bas1Repn2BusFrChA_DrvgDynIfSt_Val
# define Rte_Read_HaptcFbSt_Val Rte_Read_BmwMsgSlot234Bas1Repn2BusFrChA_HaptcFbSt_Val


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Write_sigGroup_ST_EST_sigGroup_ST_EST Rte_Write_BmwMsgSlot234Bas1Repn2BusFrChA_sigGroup_ST_EST_sigGroup_ST_EST


/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

# define Rte_Pim_BmwEpsFctStsPrev() (Rte_Inst_BmwMsgSlot234Bas1Repn2BusFrChA->Pim_BmwEpsFctStsPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_BurstModCntr() (Rte_Inst_BmwMsgSlot234Bas1Repn2BusFrChA->Pim_BurstModCntr) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_CycCntr() (Rte_Inst_BmwMsgSlot234Bas1Repn2BusFrChA->Pim_CycCntr) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_DrvgDynIfStPrev() (Rte_Inst_BmwMsgSlot234Bas1Repn2BusFrChA->Pim_DrvgDynIfStPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_HaptcFbStPrev() (Rte_Inst_BmwMsgSlot234Bas1Repn2BusFrChA->Pim_HaptcFbStPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_PerdCntr() (Rte_Inst_BmwMsgSlot234Bas1Repn2BusFrChA->Pim_PerdCntr) /* PRQA S 3453 */ /* MD_MSR_19.7 */




/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   BmwEpsFctSts1 *Rte_Pim_BmwEpsFctStsPrev(void)
 *   uint8 *Rte_Pim_BurstModCntr(void)
 *   uint8 *Rte_Pim_CycCntr(void)
 *   DrvgDynIfSt1 *Rte_Pim_DrvgDynIfStPrev(void)
 *   HaptcFbSt1 *Rte_Pim_HaptcFbStPrev(void)
 *   uint8 *Rte_Pim_PerdCntr(void)
 *
 *********************************************************************************************************************/


# define BmwMsgSlot234Bas1Repn2BusFrChA_START_SEC_CODE
# include "BmwMsgSlot234Bas1Repn2BusFrChA_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwMsgSlot234Bas1Repn2BusFrChAInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_BmwMsgSlot234Bas1Repn2BusFrChAInit1 BmwMsgSlot234Bas1Repn2BusFrChAInit1
FUNC(void, BmwMsgSlot234Bas1Repn2BusFrChA_CODE) BmwMsgSlot234Bas1Repn2BusFrChAInit1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwMsgSlot234Bas1Repn2BusFrChAPer1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_BmwEpsFctSts_Val(BmwEpsFctSts1 *data)
 *   Std_ReturnType Rte_Read_DrvgDynIfSt_Val(DrvgDynIfSt1 *data)
 *   Std_ReturnType Rte_Read_HaptcFbSt_Val(HaptcFbSt1 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_sigGroup_ST_EST_sigGroup_ST_EST(const sigGroup_ST_EST1 *data)
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_BmwMsgSlot234Bas1Repn2BusFrChAPer1 BmwMsgSlot234Bas1Repn2BusFrChAPer1
FUNC(void, BmwMsgSlot234Bas1Repn2BusFrChA_CODE) BmwMsgSlot234Bas1Repn2BusFrChAPer1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define BmwMsgSlot234Bas1Repn2BusFrChA_STOP_SEC_CODE
# include "BmwMsgSlot234Bas1Repn2BusFrChA_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_BMWMSGSLOT234BAS1REPN2BUSFRCHA_H */
