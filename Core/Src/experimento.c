/*
 * experimento.c
 *
 *  Created on: Aug 28, 2024
 *      Author: Clara
 */

#include <stdlib.h>
#include "experimento.h"


void writeSRAM(SRAM_HandleTypeDef *hsram, uint32_t offset, uint8_t data, uint32_t length){
	uint16_t buffer[length/2]; // Buffer que guarda o dado a ser armazenado na memória.
	uint16_t data_cell; // Guarda o tipo de palavra a ser armazenada.

	switch(data){
	// Preenche o buffer com zeros.
	case 0:
		data_cell = 0x0000;
		for(uint32_t i = 0; i<(length/2); i++){
			buffer[i] = data_cell;
		}
		break;

	// Preenche o buffer com 0xFFFF.
	case 1:
		data_cell = 0xFFFF;
		for(uint32_t i = 0; i<(length/2); i++){
			buffer[i] = data_cell;
		}
		break;

	// Preenche o buffer com 0x5555.
	case 2:
		data_cell = 0x5555;
		for(uint32_t i = 0; i<(length/2); i++){
			buffer[i] = data_cell;
		}
		break;

	// Preenche o buffer com 0xAAAA.
	case 3:
		data_cell = 0xAAAA;
		for(uint32_t i = 0; i<(length/2); i++){
			buffer[i] = data_cell;
		}
		break;

	// Preenche o buffer com dados aleatórios.
	case 4:
		for(uint32_t i = 0; i<(length/2); i++){
			data_cell = (rand() % 65536); // Escolhe um número aleatório entre 0 e 65535 para colocar no buffer.
			buffer[i] = data_cell;
		}
		break;
	}

	offset += FMC_BASE;
	HAL_SRAM_Write_16b(hsram, (uint32_t*)offset, buffer, length);

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



