/*
 * fsm_simple_button.c
 *
 *  Created on: 5 thg 11, 2022
 *      Author: trinh huy
 */
#include "fsm_simple_button.h"
#include "button.h"
#include "global.h"
#include "software_timer.h"


int counter = 0 ;
void fsm_simple_buttons_run(){
		if (HAL_GPIO_ReadPin(RESET_GPIO_Port, RESET_Pin)){
			counter = HAL_GPIO_ReadPin(RESET_GPIO_Port, RESET_Pin);
			if(counter  || !counter){
				counter = 0;
			}
		}
		if (HAL_GPIO_ReadPin(INC_GPIO_Port, INC_Pin) >= 0){
			counter = HAL_GPIO_ReadPin(INC_GPIO_Port, INC_Pin);
			if (counter > 9){
				counter = 0;
			}
			else {
				counter++;
			}
		}
		if (HAL_GPIO_ReadPin(DEC_GPIO_Port, DEC_Pin) <= 9){
			counter = HAL_GPIO_ReadPin(DEC_GPIO_Port, DEC_Pin);
			if(counter < 1){
				counter = 9;
			}
			else {
				counter--;
			}
		}

		display7Segments(counter);
}

void display7Segments(int counter){
	if ( counter == 0 ){
		HAL_GPIO_WritePin(LED7_0_GPIO_Port, LED7_0_Pin, RESET);
		HAL_GPIO_WritePin(LED7_1_GPIO_Port, LED7_1_Pin, RESET);
		HAL_GPIO_WritePin(LED7_2_GPIO_Port, LED7_2_Pin, RESET);
		HAL_GPIO_WritePin(LED7_3_GPIO_Port, LED7_3_Pin, RESET);
		HAL_GPIO_WritePin(LED7_4_GPIO_Port, LED7_4_Pin, RESET);
		HAL_GPIO_WritePin(LED7_5_GPIO_Port, LED7_5_Pin, RESET);
		HAL_GPIO_WritePin(LED7_6_GPIO_Port, LED7_6_Pin, SET);
	}
	if ( counter == 1 ){
			HAL_GPIO_WritePin(LED7_0_GPIO_Port, LED7_0_Pin, SET);
			HAL_GPIO_WritePin(LED7_1_GPIO_Port, LED7_1_Pin, RESET);
			HAL_GPIO_WritePin(LED7_2_GPIO_Port, LED7_2_Pin, RESET);
			HAL_GPIO_WritePin(LED7_3_GPIO_Port, LED7_3_Pin, SET);
			HAL_GPIO_WritePin(LED7_4_GPIO_Port, LED7_4_Pin, SET);
			HAL_GPIO_WritePin(LED7_5_GPIO_Port, LED7_5_Pin, SET);
			HAL_GPIO_WritePin(LED7_6_GPIO_Port, LED7_6_Pin, SET);
	}
	if ( counter == 2 ){
			HAL_GPIO_WritePin(LED7_0_GPIO_Port, LED7_0_Pin, RESET);
			HAL_GPIO_WritePin(LED7_1_GPIO_Port, LED7_1_Pin, RESET);
			HAL_GPIO_WritePin(LED7_2_GPIO_Port, LED7_2_Pin, SET);
			HAL_GPIO_WritePin(LED7_3_GPIO_Port, LED7_3_Pin, RESET);
			HAL_GPIO_WritePin(LED7_4_GPIO_Port, LED7_4_Pin, RESET);
			HAL_GPIO_WritePin(LED7_5_GPIO_Port, LED7_5_Pin, SET);
			HAL_GPIO_WritePin(LED7_6_GPIO_Port, LED7_6_Pin, RESET);
	}
	if ( counter == 3 ){
			HAL_GPIO_WritePin(LED7_0_GPIO_Port, LED7_0_Pin, RESET);
			HAL_GPIO_WritePin(LED7_1_GPIO_Port, LED7_1_Pin, RESET);
			HAL_GPIO_WritePin(LED7_2_GPIO_Port, LED7_2_Pin, RESET);
			HAL_GPIO_WritePin(LED7_3_GPIO_Port, LED7_3_Pin, RESET);
			HAL_GPIO_WritePin(LED7_4_GPIO_Port, LED7_4_Pin, SET);
			HAL_GPIO_WritePin(LED7_5_GPIO_Port, LED7_5_Pin, SET);
			HAL_GPIO_WritePin(LED7_6_GPIO_Port, LED7_6_Pin, RESET);
	}
	if ( counter == 4 ){
			HAL_GPIO_WritePin(LED7_0_GPIO_Port, LED7_0_Pin, SET);
			HAL_GPIO_WritePin(LED7_1_GPIO_Port, LED7_1_Pin, RESET);
			HAL_GPIO_WritePin(LED7_2_GPIO_Port, LED7_2_Pin, RESET);
			HAL_GPIO_WritePin(LED7_3_GPIO_Port, LED7_3_Pin, SET);
			HAL_GPIO_WritePin(LED7_4_GPIO_Port, LED7_4_Pin, SET);
			HAL_GPIO_WritePin(LED7_5_GPIO_Port, LED7_5_Pin, RESET);
			HAL_GPIO_WritePin(LED7_6_GPIO_Port, LED7_6_Pin, RESET);
	}
	if ( counter == 5 ){
				HAL_GPIO_WritePin(LED7_0_GPIO_Port, LED7_0_Pin, RESET);
				HAL_GPIO_WritePin(LED7_1_GPIO_Port, LED7_1_Pin, SET);
				HAL_GPIO_WritePin(LED7_2_GPIO_Port, LED7_2_Pin, RESET);
				HAL_GPIO_WritePin(LED7_3_GPIO_Port, LED7_3_Pin, RESET);
				HAL_GPIO_WritePin(LED7_4_GPIO_Port, LED7_4_Pin, SET);
				HAL_GPIO_WritePin(LED7_5_GPIO_Port, LED7_5_Pin, RESET);
				HAL_GPIO_WritePin(LED7_6_GPIO_Port, LED7_6_Pin, RESET);
	}
	if ( counter == 6 ){
				HAL_GPIO_WritePin(LED7_0_GPIO_Port, LED7_0_Pin, RESET);
				HAL_GPIO_WritePin(LED7_1_GPIO_Port, LED7_1_Pin, SET);
				HAL_GPIO_WritePin(LED7_2_GPIO_Port, LED7_2_Pin, RESET);
				HAL_GPIO_WritePin(LED7_3_GPIO_Port, LED7_3_Pin, RESET);
				HAL_GPIO_WritePin(LED7_4_GPIO_Port, LED7_4_Pin, RESET);
				HAL_GPIO_WritePin(LED7_5_GPIO_Port, LED7_5_Pin, RESET);
				HAL_GPIO_WritePin(LED7_6_GPIO_Port, LED7_6_Pin, RESET);
	}
	if ( counter == 7 ){
				HAL_GPIO_WritePin(LED7_0_GPIO_Port, LED7_0_Pin, RESET);
				HAL_GPIO_WritePin(LED7_1_GPIO_Port, LED7_1_Pin, RESET);
				HAL_GPIO_WritePin(LED7_2_GPIO_Port, LED7_2_Pin, RESET);
				HAL_GPIO_WritePin(LED7_3_GPIO_Port, LED7_3_Pin, SET);
				HAL_GPIO_WritePin(LED7_4_GPIO_Port, LED7_4_Pin, SET);
				HAL_GPIO_WritePin(LED7_5_GPIO_Port, LED7_5_Pin, SET);
				HAL_GPIO_WritePin(LED7_6_GPIO_Port, LED7_6_Pin, SET);
	}
	if ( counter == 8 ){
					HAL_GPIO_WritePin(LED7_0_GPIO_Port, LED7_0_Pin, RESET);
					HAL_GPIO_WritePin(LED7_1_GPIO_Port, LED7_1_Pin, RESET);
					HAL_GPIO_WritePin(LED7_2_GPIO_Port, LED7_2_Pin, RESET);
					HAL_GPIO_WritePin(LED7_3_GPIO_Port, LED7_3_Pin, RESET);
					HAL_GPIO_WritePin(LED7_4_GPIO_Port, LED7_4_Pin, RESET);
					HAL_GPIO_WritePin(LED7_5_GPIO_Port, LED7_5_Pin, RESET);
					HAL_GPIO_WritePin(LED7_6_GPIO_Port, LED7_6_Pin, RESET);
	}
	if ( counter == 9 ){
					HAL_GPIO_WritePin(LED7_0_GPIO_Port, LED7_0_Pin, RESET);
					HAL_GPIO_WritePin(LED7_1_GPIO_Port, LED7_1_Pin, RESET);
					HAL_GPIO_WritePin(LED7_2_GPIO_Port, LED7_2_Pin, RESET);
					HAL_GPIO_WritePin(LED7_3_GPIO_Port, LED7_3_Pin, RESET);
					HAL_GPIO_WritePin(LED7_4_GPIO_Port, LED7_4_Pin, SET);
					HAL_GPIO_WritePin(LED7_5_GPIO_Port, LED7_5_Pin, RESET);
					HAL_GPIO_WritePin(LED7_6_GPIO_Port, LED7_6_Pin, RESET);
	}

}









