/*
 * experimento.c
 *
 *  Created on: Aug 28, 2024
 *      Author: Clara
 */

#include "experimento.h"

void writeSRAM(uint32_t offset, uint8_t* data, uint32_t length){

}


void readSRAM(uint32_t offset, uint8_t* buffer, uint32_t length){

}

/*
 * ******************************************************************************
 *  Function Name: selectECC
 *  @brief       : Configures the Error Correcting Code (ECC) selection using GPIO pins.
 *  @param       : ecc - An 8-bit unsigned integer specifying the ECC type to be selected.
 *                        Possible values:
 *                        01 - HAMMING
 *                        02 - TBEC
 *                        03 - EDAC
 *                        04 - BYPASS (no ECC)
 *  @retval      : None
 * ******************************************************************************
 */
void selectECC(uint8_t ecc){
	switch(ecc){
	// 10
	case HAMMING:
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_0,GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_1,GPIO_PIN_RESET);
		break;

	// 01
	case TBEC:
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_0,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_1,GPIO_PIN_SET);
		break;

	// 11
	case EDAC:
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_0,GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_1,GPIO_PIN_SET);
		break;

	// 00
	case BYPASS:
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_0,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_1,GPIO_PIN_RESET);
		break;

	}
}


void testErrorAmount(Telecommand command){

}



