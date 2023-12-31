/**********************************************************************************************************************
* Copyright 2016 Nexteer 
* Nexteer Confidential
*
* Module File Name: CDD_ChkPt_Bsw.c
* Module Description: Check Point functions for BSW tasks
* Project           : CBD
* Author            : Lucas Wendling
************************************************************************************************************************
* Version Control:
* %version:          1 %
* %derived_by:       cz7lt6 %
*---------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author         Change Description                                                           SCR #
* -------   -------  --------  ---------------------------------------------------------------------------     ----------
* 04/20/16  1        KJS       Initial Version                                                                 EA4#5284
**********************************************************************************************************************/

/******************************************* Multiple Include Protection *********************************************/
#ifndef CDD_CHKPT_BSW_H
#define CDD_CHKPT_BSW_H

/************************************************ Include Statements *************************************************/
#include "Std_Types.h"

/******************************************** File Level Rule Deviations *********************************************/

/*********************************************** Exported Declarations ***********************************************/
extern FUNC(void, CDD_ChkPt_CODE) ChkPt_10msBswAppl10Strt(void);
extern FUNC(void, CDD_ChkPt_CODE) ChkPt_10msBswAppl10End(void);
/**************************************** End Of Multiple Include Protection *****************************************/
#endif
