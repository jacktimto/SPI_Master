/* SPI Master example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_log.h"
#include "driver/spi_master.h"
#include "driver/gpio.h"

#include "pretty_effect.h"

#include "Display_EPD_W21_spi.h"
#include "Display_EPD_W21.h"
#include "Ap_29demo.h"

void app_main(void)
{
    int temperature = 0;
    EPD_GPIO_Init(); // gpio初始化

    EPD_HW_Init();                   // Full screen refresh initialization.
    EPD_WhiteScreen_White();         // Clear screen function.
    EPD_DeepSleep();                 // Enter the sleep mode and please do not delete it, otherwise it will reduce the lifespan of the screen.
    vTaskDelay(pdMS_TO_TICKS(2000)); // Delay for 3s.

    /*display content*/
    EPD_HW_Init();
    EPD_WhiteScreen_ALL(gImage_p5); //全屏显示
    EPD_DeepSleep(); 
    vTaskDelay(pdMS_TO_TICKS(2000));

    


    while (1)
    {
        EPD_HW_Init();
        temperature = EPD_Tempsensor_Read();
        ESP_LOGI("test","temperature:%d",temperature);
        EPD_DeepSleep();
        vTaskDelay(pdMS_TO_TICKS(2000)); // Delay for 2s.
    }
}