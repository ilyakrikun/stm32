#include "main.h"

uint32_t delay_count = 0;


//-------------------------------------------------------------
//Настройка задержки
//-------------------------------------------------------------

void SysTick_Handler(void)
{
	if (delay_count > 0)
	{
		delay_count--;
	}
}

void delay_ms(uint16_t delay_par)
{
	delay_count = delay_par;
	while(delay_count) {}
}

//-------------------------------------------------------------
//Управление потенциометром
//-------------------------------------------------------------

void Increased_Resistance (void)		// Наростание
{
	UD_ON();
	INC_ON();
	CS_OFF();
	delay_ms(1);
	INC_OFF();
	delay_ms(1);
	INC_ON();
	delay_ms(1);
	CS_ON();
}

void Decreas_Resistance (void)			// Понижение
{
	UD_OFF();
	INC_ON();
	CS_OFF();
	delay_ms(1);
	INC_OFF();
	delay_ms(1);
	INC_ON();
	delay_ms(1);
	CS_ON();
}

//-------------------------------------------------------------
//Main
//-------------------------------------------------------------

int main (void)
{
	SysTick_Config(SystemCoreClock/1000);
	Encoder_Ini();
	Digital_Pot_GPIO_Init();
	CS_ON();

	count = GetEnc_Counter();

	while(1)
	{
		if (count != last_count) // нужно проверить, что будет если last_count = count; поставить в концке основного if*
		{
			if (count > last_count)
			{
				Increased_Resistance();
				last_count = count;

			}
			else if (count < last_count)
			{
				Decreas_Resistance();
				last_count = count;
			}
			// тут*
		}
	}

}

