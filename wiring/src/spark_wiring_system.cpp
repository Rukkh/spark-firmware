
#include "core_hal.h"
#include "rtc_hal.h"
#include "rgbled.h"
#include "spark_wiring_wifi.h"
#include "spark_wiring_cloud.h"
#include "system_task.h"
#include "system_network.h"


SystemClass System;

void SystemClass::factoryReset(void)
{
    //This method will work only if the Core is supplied
    //with the latest version of Bootloader
    HAL_Core_Factory_Reset();
}

void SystemClass::dfu(bool persist)
{
    // true  - DFU mode persist if firmware upgrade is not completed
    // false - Briefly enter DFU bootloader mode (works with latest bootloader only )
    //         Subsequent reset or power off-on will execute normal firmware
    HAL_Core_Enter_Bootloader(persist);
}

void SystemClass::reset(void)
{
    HAL_Core_System_Reset();
}

void SystemClass::sleep(Spark_Sleep_TypeDef sleepMode, long seconds)
{
    system_sleep(sleepMode, seconds, 0, NULL);
}

void SystemClass::sleep(uint16_t wakeUpPin, uint16_t edgeTriggerMode, long seconds)
{
    system_sleep_pin(wakeUpPin, edgeTriggerMode, seconds, 0, NULL);
}
