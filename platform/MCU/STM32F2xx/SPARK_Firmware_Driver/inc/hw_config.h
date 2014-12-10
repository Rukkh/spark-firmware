/**
 ******************************************************************************
 * @file    hw_config.h
 * @author  Satish Nair
 * @version V1.0.0
 * @date    22-Oct-2014
 * @brief   Hardware Configuration & Setup
 ******************************************************************************
  Copyright (c) 2013-14 Spark Labs, Inc.  All rights reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation, either
  version 3 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, see <http://www.gnu.org/licenses/>.
  ******************************************************************************
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __HW_CONFIG_H
#define __HW_CONFIG_H
/* Includes ------------------------------------------------------------------*/

#include <limits.h>
#include "platform_config.h"
#include "config.h"
#include "rgbled.h"
#include "system_tick_hal.h"
#include "usb_hal.h"
#include "platform_system_flags.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Exported types ------------------------------------------------------------*/
typedef enum
{
	BUTTON1 = 0
} Button_TypeDef;

typedef enum
{
	BUTTON_MODE_GPIO = 0, BUTTON_MODE_EXTI = 1
} ButtonMode_TypeDef;

/* Exported constants --------------------------------------------------------*/

/* Exported macros ------------------------------------------------------------*/

#ifndef INTERNAL_FLASH_SIZE
#   error "INTERNAL_FLASH_SIZE not defined"
#endif

// Firmware image size is usually same size as internal flash
#ifndef FIRMWARE_IMAGE_SIZE
#define FIRMWARE_IMAGE_SIZE INTERNAL_FLASH_SIZE
#endif

#if FIRMWARE_IMAGE_SIZE > INTERNAL_FLASH_SIZE 
#   error "FIRMWARE_IMAGE_SIZE too large to fit into internal flash"
#endif

/* Internal Flash memory address where various firmwares are located */
#ifndef INTERNAL_FLASH_START
#define INTERNAL_FLASH_START        ((uint32_t)0x08000000)
#endif

//Bootloader firmware at the start of internal flash
#define USB_DFU_ADDRESS             INTERNAL_FLASH_START
//Main firmware begin address after 128KB (4 x 16K + 64K) from start of flash
#define CORE_FW_ADDRESS             ((uint32_t)0x08020000)
#define APP_START_MASK              ((uint32_t)0x2FF10000)
/* Internal Flash memory address where the System Flags will be saved and loaded from  */

/* Bootloader Flash regions that needs to be protected: 0x08000000 - 0x08003FFF */
#define BOOTLOADER_FLASH_PAGES      (OB_WRP_Sector_0) //Sector 0

#define SYSTEM_US_TICKS		(SystemCoreClock / 1000000)//cycles per microsecond

/* Exported functions ------------------------------------------------------- */
void Set_System(void);
void NVIC_Configuration(void);
void SysTick_Configuration(void);

/**
 * Disable the system timer.
 */
void SysTick_Disable(void);

void System1MsTick(void);
system_tick_t GetSystem1MsTick(void);

void RTC_Configuration(void);

void IWDG_Reset_Enable(uint32_t msTimeout);

void UI_Timer_Configure(void);

void BUTTON_Init(Button_TypeDef Button, ButtonMode_TypeDef Button_Mode);
void BUTTON_EXTI_Config(Button_TypeDef Button, FunctionalState NewState);
uint8_t BUTTON_GetState(Button_TypeDef Button);
uint16_t BUTTON_GetDebouncedTime(Button_TypeDef Button);
void BUTTON_ResetDebouncedState(Button_TypeDef Button);

#ifdef USE_SERIAL_FLASH
/* Serial Flash Hardware related methods */
void sFLASH_SPI_DeInit(void);
void sFLASH_SPI_Init(void);
void sFLASH_CS_LOW(void);
void sFLASH_CS_HIGH(void);
#endif

void USB_Cable_Config(FunctionalState NewState);

#define SYSTEM_FLAG(x) (system_flags.x)
void Load_SystemFlags(void);
void Save_SystemFlags(void);
extern platform_system_flags_t system_flags;

/* Internal Flash Routines */
void FLASH_ClearFlags(void);
void FLASH_WriteProtection_Enable(uint32_t FLASH_Sectors);
void FLASH_WriteProtection_Disable(uint32_t FLASH_Sectors);
void FLASH_Erase(void);
void FLASH_Backup(uint32_t FLASH_Address);
void FLASH_Restore(uint32_t FLASH_Address);
void FLASH_Begin(uint32_t FLASH_Address, uint32_t fileSize);
uint16_t FLASH_Update(uint8_t *pBuffer, uint32_t bufferSize);
void FLASH_End(void);

void FACTORY_Flash_Reset(void);
void BACKUP_Flash_Reset(void);
void OTA_Flash_Reset(void);

bool OTA_Flashed_GetStatus(void);
void OTA_Flashed_ResetStatus(void);

void Finish_Update(void);

/* External variables --------------------------------------------------------*/
extern uint8_t USE_SYSTEM_FLAGS;

extern volatile uint32_t TimingDelay;

#define KICK_WDT() IWDG_ReloadCounter()


#ifdef __cplusplus
}
#endif


#endif  /*__HW_CONFIG_H*/
