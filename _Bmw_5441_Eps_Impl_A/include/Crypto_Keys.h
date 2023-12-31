/*----------------------------------------------------------------------------*/
/**
*  \file
*
*  \brief       Generated crypto keys
*
*  These crypto keys are generated by BMW backend system ASBC/SWL-SEC. New
*  format for SP2021 keys (supported by BAC 4, Release 3 and aBAC, Release 1).
*
*  \project     BMW Platform Software
*
*  \copyright   BMW Group 2017
*
*  \version     V02.00
*
*
*/
/*------------------------------------------------------------------------------
*
*  THIS FILE WAS GENERATED. DO NOT MODIFY! Otherwise no authentication and swe
*  signature check will be possible with PSdZ.
*
*  GENERATOR       :    ASBC / SWL-SEC
*
*  GENERATION TIME :    20.12.2017 09:49:47
*
*  REQUESTER       :    Q231240
*
*  SGBM-Nr         :    000064BD
*
------------------------------------------------------------------------------*/
/*************************************************************************************************************************
 * Version Control:
 * Date Created:      Wed Oct 19 12:16:01 2011
 * %version:          3 %
 * %derived_by:       tzyksv %
 * %date_modified:    Thu Oct 20 10:20:06 2011 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        	   SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  	----------
 * 10/20/11   1        BDO        Initial version - integrate BMW Crypto_Cfg_hotkey.h file
 * 10/05/16	  1.1.3	   ABS		  Authentication and Signature changes - 2048bit key and SHA256 hash		 	 EA3#7986
 * 04/10/18	  3	       AR		  Updated based on new file received from BMW                        		 	 EA4#22359

*************************************************************************************************************************/


#ifndef CRYPTO_KEYS_H
#define CRYPTO_KEYS_H

#define CRYPTO_SGBM_ID_BTLD                  0x000064BD


/*------------------------------------------------------------------------------
 Authentication keys for level 3 (test key!)
-------------------------------------------------------------------------------*/

/* With digest SHA-512 */
#define CRYPTO_AUTH_KEY_LEVEL_3_DIGEST_SHA_512

/* ECC domain parameter secp384r1 */
#define CRYPTO_AUTH_KEY_LEVEL_3_ECC_PARAM_SECP384R1

/* Key length in bits : 384 */
#define CRYPTO_AUTH_KEY_LEVEL_3_SIZE       384U

/* ECC key part X */
#define CRYPTO_AUTH_KEY_LEVEL_3_X                     \
   {                                                  \
      (uint32)0x0000000cUL,                           \
      (uint32)0xc0f0387aUL, (uint32)0xf6737019UL,     \
      (uint32)0xd5eb827cUL, (uint32)0xd1bb7c85UL,     \
      (uint32)0x7bebee3cUL, (uint32)0x7b19ffc2UL,     \
      (uint32)0x754a90edUL, (uint32)0x1556560bUL,     \
      (uint32)0x345d194dUL, (uint32)0x09b48a43UL,     \
      (uint32)0x176b418dUL, (uint32)0x5ee281c7UL      \
   }

/* ECC key part Y */
#define CRYPTO_AUTH_KEY_LEVEL_3_Y                     \
   {                                                  \
      (uint32)0x0000000cUL,                           \
      (uint32)0xc66ed709UL, (uint32)0x1897d255UL,     \
      (uint32)0x02711d36UL, (uint32)0x3cedf34aUL,     \
      (uint32)0xda5b24e4UL, (uint32)0x493972f7UL,     \
      (uint32)0x575ba5e4UL, (uint32)0x61ce26a9UL,     \
      (uint32)0x08e04e1bUL, (uint32)0x11770afaUL,     \
      (uint32)0xa509f234UL, (uint32)0xdd7c031fUL      \
   }


/*------------------------------------------------------------------------------
 Authentication keys for level 5 (test key!)
-------------------------------------------------------------------------------*/

/* With digest SHA-512 */
#define CRYPTO_AUTH_KEY_LEVEL_5_DIGEST_SHA_512

/* ECC domain parameter secp384r1 */
#define CRYPTO_AUTH_KEY_LEVEL_5_ECC_PARAM_SECP384R1

/* Key length in bits : 384 */
#define CRYPTO_AUTH_KEY_LEVEL_5_SIZE  384U

/* ECC key part X */
#define CRYPTO_AUTH_KEY_LEVEL_5_X                     \
   {                                                  \
      (uint32)0x0000000cUL,                           \
      (uint32)0x52c6f271UL, (uint32)0xbebaed61UL,     \
      (uint32)0x46e2edc8UL, (uint32)0x8dfaa0c6UL,     \
      (uint32)0xb3bbb6a3UL, (uint32)0x28836414UL,     \
      (uint32)0xb27abdc4UL, (uint32)0x69e9d326UL,     \
      (uint32)0x012d1599UL, (uint32)0x71f0a0a0UL,     \
      (uint32)0xb4f8b838UL, (uint32)0x79f935e6UL      \
   }

/* ECC key part Y */
#define CRYPTO_AUTH_KEY_LEVEL_5_Y                     \
   {                                                  \
      (uint32)0x0000000cUL,                           \
      (uint32)0x4d0f0244UL, (uint32)0xe83c1befUL,     \
      (uint32)0x7748c088UL, (uint32)0x5ab6e534UL,     \
      (uint32)0x14d8b6dbUL, (uint32)0xc79033c1UL,     \
      (uint32)0x6d77bccfUL, (uint32)0x675296acUL,     \
      (uint32)0x909798c5UL, (uint32)0x1e046300UL,     \
      (uint32)0xabd79242UL, (uint32)0x339f2497UL      \
   }


/*------------------------------------------------------------------------------
  SWE signature key (test key!)
-------------------------------------------------------------------------------*/

/* With digest SHA-512 */
#define CRYPTO_SIG_KEY_DIGEST_SHA_512

/* ECC domain parameter secp384r1 */
#define CRYPTO_SIG_KEY_ECC_PARAM_SECP384R1

/* Key length in bits : 384 */
#define CRYPTO_SIG_KEY_SIZE  384U

/* ECC key part X */
#define CRYPTO_SIG_KEY_X                              \
   {                                                  \
      (uint32)0x0000000cUL,                           \
      (uint32)0x63ab7071UL, (uint32)0xf4e8b234UL,     \
      (uint32)0xc51e5455UL, (uint32)0x8f8b3331UL,     \
      (uint32)0xe867cafcUL, (uint32)0x4def6bfeUL,     \
      (uint32)0xc2d5f666UL, (uint32)0x7f950f3fUL,     \
      (uint32)0x558b49a1UL, (uint32)0x61074098UL,     \
      (uint32)0x7a5dd16eUL, (uint32)0x9f65c720UL      \
   }

/* ECC key part Y */
#define CRYPTO_SIG_KEY_Y                              \
   {                                                  \
      (uint32)0x0000000cUL,                           \
      (uint32)0x20310aafUL, (uint32)0x36d55b23UL,     \
      (uint32)0x38e04c15UL, (uint32)0x220ab4a6UL,     \
      (uint32)0x3edcb985UL, (uint32)0x45af0f66UL,     \
      (uint32)0x94c7bd1aUL, (uint32)0x6bf9fffdUL,     \
      (uint32)0x67832130UL, (uint32)0x032461b9UL,     \
      (uint32)0x06a0e6c0UL, (uint32)0x06239311UL      \
   }


/*------------------------------------------------------------------------------
 NCD signature key (test key!)
-------------------------------------------------------------------------------*/

/* With digest SHA-512 */
#define CRYPTO_NCD_KEY_DIGEST_SHA_512

/* ECC domain parameter secp384r1 */
#define CRYPTO_NCD_KEY_ECC_PARAM_SECP384R1

/* Key length in bits : 384 */
#define CRYPTO_NCD_KEY_SIZE  384U

/* ECC key part X */
#define CRYPTO_NCD_KEY_X                              \
   {                                                  \
      (uint32)0x0000000cUL,                           \
      (uint32)0x7e8f7780UL, (uint32)0x7f8c5ce4UL,     \
      (uint32)0x237d1041UL, (uint32)0xff12e540UL,     \
      (uint32)0xfe501e7eUL, (uint32)0xcd9a1404UL,     \
      (uint32)0xfee74f56UL, (uint32)0xa1de5574UL,     \
      (uint32)0xe63b0621UL, (uint32)0x15adb669UL,     \
      (uint32)0x8451a95dUL, (uint32)0x4c2004ebUL      \
   }

/* ECC key part Y */
#define CRYPTO_NCD_KEY_Y                              \
   {                                                  \
      (uint32)0x0000000cUL,                           \
      (uint32)0x90effd03UL, (uint32)0xb6f2d308UL,     \
      (uint32)0x58530a57UL, (uint32)0x7768f69fUL,     \
      (uint32)0x3ac68d60UL, (uint32)0xc774f2b3UL,     \
      (uint32)0x38f302eeUL, (uint32)0x3a6c1d55UL,     \
      (uint32)0xb65d01ddUL, (uint32)0x08c8eb47UL,     \
      (uint32)0x383c0319UL, (uint32)0x526fe172UL      \
   }




#endif /* CRYPTO_KEY_H */

/*--- End of file ------------------------------------------------------------*/
