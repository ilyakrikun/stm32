#include "encoder.h"

//-------------------------------------------------------------
//
//-------------------------------------------------------------

void Encoder_Ini (void)
{

	GPIO_InitTypeDef GPIO_Init_Enc;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO|RCC_APB2Periph_GPIOA, ENABLE);

	GPIO_Init_Enc.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1;
	GPIO_Init_Enc.GPIO_Mode = GPIO_Mode_IPU;
	//GPIO_Init_Enc.GPIO_Speed = GPIO_Speed_2MHz;

	GPIO_Init(GPIOA, &GPIO_Init_Enc);

	TIM_TimeBaseInitTypeDef TIM_ini;

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);

	TIM_TimeBaseStructInit(&TIM_ini);

	TIM_ini.TIM_Prescaler = 0;
	TIM_ini.TIM_Period = 256;
	TIM_ini.TIM_CounterMode = TIM_CounterMode_Up;

	TIM_TimeBaseInit(TIM2, &TIM_ini);

	TIM_EncoderInterfaceConfig(TIM2, TIM_EncoderMode_TI1, TIM_ICPolarity_Rising, TIM_ICPolarity_Rising);

	TIM_Cmd(TIM2, ENABLE);


}

//-------------------------------------------------------------
//
//-------------------------------------------------------------

/*
void Sysytick_Enc (void)
{

}
*/
//-------------------------------------------------------------
//
//-------------------------------------------------------------

uint8_t GetEnc_Counter(void)
{
	return TIM_GetCounter(TIM2);
}
