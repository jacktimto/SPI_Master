1. Display_EPD_W21_spi.h 负责的是底层的GPIO驱动
2. Display_EPD_W21 负责数据的发送
3. Ap_29demo是需要显示的图形
4. EPD_HW_Init_Fast2()函数必须和EPD_WhiteScreen_ALL_Fast2()函数配套使用
5. EPD_HW_Init_Fast()与函数必须和EPD_WhiteScreen_ALL_Fast()
6. EPD_HW_Init()与EPD_WhiteScreen_ALL()
7. Fast refresh mode(需要最少延时1.5s),Fast2 refresh mode(需要最少延时1s),正常刷新(需要延时2s)
8. | function                                                  | 功能             |      |
   | --------------------------------------------------------- | ---------------- | ---- |
   | EPD_SetRAMValue_BaseMap                                   | 局部刷新背景图片 |      |
   | EPD_Dis_Part(x_start,y_start,*data,PART_COLUMN,PART_LINE) | 局部刷新         |      |
   |                                                           |                  |      |

   