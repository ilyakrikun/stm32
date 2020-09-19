
#include "X9C103.h"


//-------------------------------------------------------------
//Инициализация выводов
//-------------------------------------------------------------

void Digital_Pot_GPIO_Init (void)
{
	GPIO_InitTypeDef GPIO_Pot_Init;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);

	GPIO_Pot_Init.GPIO_Pin = GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9;
	GPIO_Pot_Init.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Pot_Init.GPIO_Speed = GPIO_Speed_10MHz;

	GPIO_Init(GPIOB, &GPIO_Pot_Init);
}
