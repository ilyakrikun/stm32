#ifndef ENCODER_H
#define ENCODER_H

#include "stm32f10x.h"
#include "main.h"

void Encoder_Ini (void);
//void Sysytick_Enc (void);
uint8_t GetEnc_Counter(void);

#endif
