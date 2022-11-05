/*
 * button.c
 *
 *  Created on: Nov 5, 2022
 *      Author: trinh huy
 */

#include "button.h"
	//RESET
int KeyReg0 = NORMAL_STATE;
int KeyReg1 = NORMAL_STATE;
int KeyReg2 = NORMAL_STATE;
int KeyReg3 = NORMAL_STATE;
	//INC
int KeyReg4 = NORMAL_STATE;
int KeyReg5 = NORMAL_STATE;
int KeyReg6 = NORMAL_STATE;
int KeyReg7 = NORMAL_STATE;
	//DEC
int KeyReg8 = NORMAL_STATE;
int KeyReg9 = NORMAL_STATE;
int KeyReg10 = NORMAL_STATE;
int KeyReg11 = NORMAL_STATE;

int TimeOutForKeyRESETPress =  200;
int TimeOutForKeyINCPress =  200;
int TimeOutForKeyDECPress =  200;
int reset1_flag = 0;
int inc1_flag = 0;
int dec1_flag = 0;


int isReset1Pressed(){
	if(reset1_flag == 1){
		reset1_flag = 0 ;
		return 1;
	}
	return 0;
}

int isIncrease1Pressed(){
	if(inc1_flag== 1){
		inc1_flag = 0 ;
		return 1;
	}
	return 0;
}

int isDecrease1Pressed(){
	if(dec1_flag == 1){
		dec1_flag = 0 ;
		return 1;
	}
	return 0;
}


void subKeyProcess(){
	reset1_flag = 1;
	inc1_flag = 1;
	dec1_flag = 1;
}


//RESET
void getKeyInput_1(){
  KeyReg0 = KeyReg1;
  KeyReg1 = KeyReg2;
  KeyReg2 = HAL_GPIO_ReadPin(RESET_GPIO_Port, RESET_Pin);
  if ((KeyReg1 == KeyReg0) && (KeyReg1 == KeyReg2)){
	  if (KeyReg3 != KeyReg2){
		  KeyReg3 = KeyReg2;
		  if (KeyReg2 == PRESSED_STATE){
			  subKeyProcess();
			  TimeOutForKeyRESETPress = 200;}
    }
	  else
	  {
		  TimeOutForKeyRESETPress--;
		  if (TimeOutForKeyRESETPress == 0){
			  KeyReg3 = NORMAL_STATE;
		  }
	  }
  }
}

//INC
void getKeyInput_2(){
	KeyReg4 = KeyReg5;
	KeyReg5 = KeyReg6;
	KeyReg6 = HAL_GPIO_ReadPin(INC_GPIO_Port, INC_Pin);
	if ((KeyReg5 == KeyReg4) && (KeyReg5 == KeyReg6)){
	  if (KeyReg7 != KeyReg6){
	    KeyReg7 = KeyReg6;
	    if (KeyReg6 == PRESSED_STATE){
	    	subKeyProcess();
	        TimeOutForKeyINCPress = 200;
	    }
	  }else{
		  TimeOutForKeyINCPress --;
	     if (TimeOutForKeyINCPress == 0){
	          KeyReg7 = NORMAL_STATE;
	      }
	   }
	}
}

//DEC
void getKeyInput_3(){
	KeyReg8 = KeyReg9;
	KeyReg9 = KeyReg10;
	KeyReg10 = HAL_GPIO_ReadPin(DEC_GPIO_Port, DEC_Pin);
	if ((KeyReg9 == KeyReg8) && (KeyReg9 == KeyReg10)){
	  if (KeyReg11 != KeyReg10){
		  KeyReg11 = KeyReg10;
	      if (KeyReg10 == PRESSED_STATE){
	    	  subKeyProcess();
	    	  TimeOutForKeyDECPress = 200;
	      }
	  }else{
		  TimeOutForKeyDECPress --;
	     if (TimeOutForKeyDECPress == 0){
	       KeyReg11 = NORMAL_STATE;
	     }
	  }
	}
}





















































