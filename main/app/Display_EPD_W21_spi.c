#include "Display_EPD_W21_spi.h"
#include "esp_rom_sys.h"

#define GPIO_OUTPUT_PIN_SEL (1ULL << MOSI) | (1ULL << SCK) | (1ULL << CS) | (1ULL << DC) | (1ULL << RST)
#define GPIO_INPUT_PIN_SEL (1ULL << BUSY)
#define GPIO_MOSI_SEL (1ULL << MOSI) //
// E-paper GPIO initialization
void EPD_GPIO_Init(void)
{
	gpio_config_t output_conf = {};
	output_conf.intr_type = GPIO_INTR_DISABLE;
	output_conf.mode = GPIO_MODE_OUTPUT;
	output_conf.pin_bit_mask = GPIO_OUTPUT_PIN_SEL;
	output_conf.pull_down_en = 0;
	output_conf.pull_up_en = 1;
	gpio_config(&output_conf);

	gpio_config_t input_conf = {};
	input_conf.intr_type = GPIO_INTR_DISABLE;
	input_conf.mode = GPIO_MODE_INPUT;
	input_conf.pin_bit_mask = GPIO_INPUT_PIN_SEL;
	gpio_config(&input_conf);
}

// SPI write byte
void SPI_Write(unsigned char value)
{
	unsigned char i;
	EPD_W21_CLK_0;
	for (i = 0; i < 8; i++)
	{
		if (value & 0x80)
			EPD_W21_MOSI_1;
		else
			EPD_W21_MOSI_0;
		EPD_W21_CLK_1;
		EPD_W21_CLK_0;
		value = value << 1;
	}
}

// SPI write command
void EPD_W21_WriteCMD(unsigned char command)
{
	EPD_W21_CS_0;
	EPD_W21_DC_0; // D/C#   0:command  1:data
	SPI_Write(command);
	EPD_W21_CS_1;
}
// SPI write data
void EPD_W21_WriteDATA(unsigned char datas)
{
	EPD_W21_CS_0;
	EPD_W21_DC_1; // D/C#   0:command  1:data
	SPI_Write(datas);
	EPD_W21_CS_1;
}

void SPI_Delay(unsigned char time)
{
	esp_rom_delay_us(time);
}

/*spi read data*/
unsigned char EPD_W21_ReadDATA(void)
{
	unsigned char i, j = 0;
	EPD_W21_CS_0;
	EPD_W21_DC_1; // command write(Must be added)
	SPI_Delay(2);
	for (i = 0; i < 8; i++)
	{
		EPD_W21_CLK_0;
		SPI_Delay(20);
		j = (j << 1);
		if (EPD_W21_READ == 1)
			j |= 0x01;
		else
			j &= ~0x01;
		SPI_Delay(20);
		EPD_W21_CLK_1;
		SPI_Delay(5);
	}
	EPD_W21_CS_1;
	return (j);
}
