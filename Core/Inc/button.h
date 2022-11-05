/*
 * button.h
 *
 *  Created on: Nov 5, 2022
 *      Author: trinh huy
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"
#include "button.h"

#define NORMAL_STATE GPIO_PIN_SET
#define PRESSED_STATE GPIO_PIN_RESET

int isReset1Pressed() ;
int isIncrease1Pressed();
int isDecrease1Pressed();

void getKeyInput_1();
void getKeyInput_2();
void getKeyInput_3();


#endif /* INC_BUTTON_H_ */
