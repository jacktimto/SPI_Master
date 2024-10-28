#ifndef _DISPLAY_EPD_W21_SPI_
#define _DISPLAY_EPD_W21_SPI_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "driver/spi_master.h"
#include "driver/gpio.h"

#define MOSI  23
#define SCK   19
#define CS    22
#define DC    21
#define RST   18
#define BUSY   5


#define EPD_W21_MOSI_0	gpio_set_level(MOSI, 0) 
#define EPD_W21_MOSI_1	gpio_set_level(MOSI, 1)

#define EPD_W21_CLK_0	gpio_set_level(SCK, 0)
#define EPD_W21_CLK_1	gpio_set_level(SCK, 1)

#define EPD_W21_CS_0	gpio_set_level(CS, 0)
#define EPD_W21_CS_1	gpio_set_level(CS, 1)

#define EPD_W21_DC_0	gpio_set_level(DC, 0)
#define EPD_W21_DC_1	gpio_set_level(DC, 1)

#define EPD_W21_RST_0	gpio_set_level(RST, 0)
#define EPD_W21_RST_1	gpio_set_level(RST, 1)

#define isEPD_W21_BUSY gpio_get_level(BUSY)


void SPI_Write(unsigned char value);
void EPD_W21_WriteDATA(unsigned char datas);
void EPD_W21_WriteCMD(unsigned char command);
void EPD_GPIO_Init(void);

#endif  //#ifndef _MCU_SPI_H_


