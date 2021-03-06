/**
 ******************************************************************************
 * @file    hal_dynalib_ota.h
 * @authors Matthew McGowan
 * @date    04 March 2015
 ******************************************************************************
  Copyright (c) 2015 Particle Industries, Inc.  All rights reserved.

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

#ifndef HAL_DYNALIB_OTA_H
#define	HAL_DYNALIB_OTA_H

#include "dynalib.h"

#ifdef DYNALIB_EXPORT
#include "ota_flash_hal.h"
#endif

DYNALIB_BEGIN(hal_ota)
DYNALIB_FN(hal_ota,HAL_OTA_FlashAddress)
DYNALIB_FN(hal_ota,HAL_OTA_FlashLength)
DYNALIB_FN(hal_ota,HAL_OTA_ChunkSize)

DYNALIB_FN(hal_ota,HAL_OTA_Flashed_GetStatus)
DYNALIB_FN(hal_ota,HAL_OTA_Flashed_ResetStatus)

DYNALIB_FN(hal_ota,HAL_FLASH_Begin)
DYNALIB_FN(hal_ota,HAL_FLASH_Update)
DYNALIB_FN(hal_ota,HAL_FLASH_End)        
DYNALIB_END(hal_ota)        

#endif	/* HAL_DYNALIB_OTA_H */

