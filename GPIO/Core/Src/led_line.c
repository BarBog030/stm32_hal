/*
 * led_line.c
 *
 *  Created on: Jun 24, 2023
 *      Author: barbog
 */

#include "led_line.h"

void led_line_set(int led, bool turn_on)
{
	GPIO_PinState state = (turn_on) ? GPIO_PIN_SET : GPIO_PIN_RESET;

	if (led >= 0 && led < 10) {
		HAL_GPIO_WritePin(LED[led].port, LED[led].pin, state);
	}
}

void led_line_reset(int* currentLed)
{
	*currentLed = 0;
	for (int i = 1; i < 10; i++) {
		led_line_set(i, false);
	}
	led_line_set(*currentLed, true);
}

bool is_button_pressed(functionalButton_t button)
{
	switch(button) {
	case BACKWARD_BTN:
		if (HAL_GPIO_ReadPin(USER_BTN_BACKWARD_GPIO_Port, USER_BTN_BACKWARD_Pin) == GPIO_PIN_RESET) {
			return true;
		} else {
			return false;
		}
	case FORWARD_BTN:
		if (HAL_GPIO_ReadPin(USER_BTN_FORWARD_GPIO_Port, USER_BTN_FORWARD_Pin) == GPIO_PIN_RESET) {
			return true;
		} else {
			return false;
		}
	case RESET_BTN:
		if (HAL_GPIO_ReadPin(USER_BTN_RESET_GPIO_Port, USER_BTN_RESET_Pin) == GPIO_PIN_RESET) {
			return true;
		} else {
			return false;
		}
	default:
		return false;
	}
}

