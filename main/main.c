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
#include "driver/spi_master.h"
#include "driver/gpio.h"

#include "pretty_effect.h"

#include "Display_EPD_W21_spi.h"
#include "Display_EPD_W21.h"
#include "Ap_29demo.h"

void app_main(void)
{
    EPD_GPIO_Init();

    EPD_HW_Init();                   // Full screen refresh initialization.
    EPD_WhiteScreen_White();         // Clear screen function.
    EPD_DeepSleep();                 // Enter the sleep mode and please do not delete it, otherwise it will reduce the lifespan of the screen.
    vTaskDelay(pdMS_TO_TICKS(2000)); // Delay for 2s.

    // EPD_HW_Init();
    // for (int i = 0; i < 100; i++)
    //     EPD_Dis_Part_Time(16, 60 + 32 * 0, Num[i],          // x-A,y-A,DATA-A
    //                       16, 60 + 32 * 1, Num[0],          // x-B,y-B,DATA-B
    //                       16, 60 + 32 * 2, gImage_numdot,   // x-C,y-C,DATA-C
    //                       16, 60 + 32 * 3, Num[0],          // x-D,y-D,DATA-D
    //                       16, 60 + 32 * 4, Num[1], 32, 64); // x-E,y-E,DATA-E,Resolution 32*64
    // EPD_DeepSleep();
    // vTaskDelay(pdMS_TO_TICKS(2000));

    while (1)
    {
        vTaskDelay(pdMS_TO_TICKS(2000)); // Delay for 2s.
    }
}