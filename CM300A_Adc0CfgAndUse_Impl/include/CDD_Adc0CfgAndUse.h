/**********************************************************************************************************************
* Copyright 2016 Nexteer 
* Nexteer Confidential
*
* Module File Name  : CDD_Adc0CfgAndUse.h
* Module Description: ADC 0 Complex Driver Header
* Project           : CBD
* Author            : Selva Sengottaiyan
***********************************************************************************************************************
* Version Control:
* %version:          3 %
* %derived_by:       rzk04c %
*----------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author         Change Description                                                           SCR #
* -------   -------  --------  ---------------------------------------------------------------------------     --------
* 04/12/15  1        Selva       Initial Version                                                                EA4#492
* 02/04/16  2        Rijvi      Modify to support Adc Dynamic Diagnostic (Design rev. 2.0.0)                    EA4#3393
* 06/09/16  3        AJM        Added extern linkage for Adc0CfgAndUsePer1					                    EA4#5915 
**********************************************************************************************************************/

/******************************************* Multiple Include Protection *********************************************/
#ifndef CDD_ADC0CFGANDUSE_H
#define CDD_ADC0CFGANDUSE_H

/************************************************ Include Statements *************************************************/


/******************************************** File Level Rule Deviations *********************************************/

/*********************************************** Exported Declarations ***********************************************/

#define ADC0CFGANDUSE_ADCSCAGFAC_VOLTPERCNT_F32  	0.001221001221F
#define ADC0CFGANDUSE_ADCD0VCR21_CNT_U32   			24584U
#define ADC0CFGANDUSE_ADCD0VCR22_CNT_U32   			24592U  
#define ADC0CFGANDUSE_ADCD0VCR23_CNT_U32   			24576U  
#define ADC0CFGANDUSE_DIAGCSCANGROUPMAX_CNT_U08   	23U
#define ADC0CFGANDUSE_DIAGCSCANGROUPMIN_CNT_U08   	21U

extern FUNC (void, CDD_Adc0CfgAndUse_CODE) Adc0CfgAndUsePer1 (void);
/**************************************** End Of Multiple Include Protection *****************************************/
#endif

