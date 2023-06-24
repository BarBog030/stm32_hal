/*
 * led_line.h
 *
 *  Created on: Jun 24, 2023
 *      Author: barbog
 */

#ifndef INC_LED_LINE_H_
#define INC_LED_LINE_H_

#include <stdbool.h>
#include "gpio.h"

typedef struct {
	GPIO_TypeDef* port;
	uint16_t pin;
} pin_t;

typedef enum {
	FORWARD_BTN,
	BACKWARD_BTN,
	RESET_BTN
} functionalButton_t;

static const pin_t LED[] = {
		{ LED1_GPIO_Port, LED1_Pin },
		{ LED2_GPIO_Port, LED2_Pin },
		{ LED3_GPIO_Port, LED3_Pin },
		{ LED4_GPIO_Port, LED4_Pin },
		{ LED5_GPIO_Port, LED5_Pin },
		{ LED6_GPIO_Port, LED6_Pin },
		{ LED7_GPIO_Port, LED7_Pin },
		{ LED8_GPIO_Port, LED8_Pin },
		{ LED9_GPIO_Port, LED9_Pin },
		{ LED10_GPIO_Port, LED10_Pin }
};

void led_line_set(int led, bool turn_on);

void led_line_reset(int* currentLed);

bool is_button_pressed(functionalButton_t button);

#endif /* INC_LED_LINE_H_ */
