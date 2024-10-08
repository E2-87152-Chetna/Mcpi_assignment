/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>
#include <stdio.h>
#include "stm32f4xx.h"
#include "system_stm32f4xx.h"
#include "adc.h"
#include "uart.h"
#include "led.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

int main(void) {
	uint16_t val;
	char str[32];
	SystemInit();
	ADC_Init();
	LedInit(LED_RED_PIN);
	UartInit(9600);
	while(1) {
		LedBlink(LED_RED_PIN,100);
		val = ADC_GetValue();
		sprintf(str, "ADC = %u\r\n", val);
		UartPuts(str);
		DelayMs(1000);

	}
	return 0;
}
