#ifndef MAIN.H
#define MAIN.H

#include "stm32f10x.h"
#include "X9C103.h"
#include "encoder.h"

#define UD_ON()					GPIO_SetBits(GPIOB, GPIO_Pin_7)
#define UD_OFF()				GPIO_ResetBits(GPIOB ,GPIO_Pin_7)
#define INC_ON()				GPIO_SetBits(GPIOB, GPIO_Pin_8)
#define INC_OFF()				GPIO_ResetBits(GPIOB, GPIO_Pin_8)
#define CS_ON()					GPIO_SetBits(GPIOB, GPIO_Pin_9)
#define CS_OFF()				GPIO_ResetBits(GPIOB,GPIO_Pin_9)


#endif
