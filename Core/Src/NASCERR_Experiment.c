/*
 * experimento.c
 *
 *  Created on: Aug 28, 2024
 *      Author: Clara
 */

#include <NASCERR_Experiment.h>
#include <NASCERR_Memory.h>
#include <stdlib.h>


/*
 * ******************************************************************************
 *  Function Name: nascerr_select_ecc
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
void nascerr_experiment_select_ecc(NASCERR_MODE ecc){
//	ptr = (uint16_t *)NASCERR_SRAM_ADDRESS;

	switch(ecc){
	// 10
	case ECC_MOD1: // Hamming
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_0,GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_1,GPIO_PIN_RESET);
		break;

	// 01
	case ECC_MOD2: // TBEC
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_0,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_1,GPIO_PIN_SET);
		break;

	// 11
	case ECC_MOD3: // EDAC
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_0,GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_1,GPIO_PIN_SET);
		break;

	// 00
	case BYPASS_TO_SRAM:
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_0,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_1,GPIO_PIN_RESET);
		break;

	}
}


uint8_t nascerr_experiment_test_error_amount(NASCERR_CTRL command){
	uint8_t errors = 0;
	uint16_t write_buffer[command.bytes_msg];
	uint16_t read_buffer[command.bytes_msg];

	for(int i = 0; i < command.repeat; i++){
		nascerr_memory_write_sram(write_buffer, 0, command.mode, command.write_type, command.data_lenght);
		nascerr_memory_read_sram(read_buffer, 0, command.mode, command.data_lenght);
		// rodar a função de erros
	}

	return errors;
}

//void nascerr_experiment_testrw(uint8_t* read8b, uint16_t* read16b, uint32_t* read32b){
//	uint8_t data8b = 0xAA;
//	uint16_t data16b = 0x5555;
//	uint32_t data32b = 0xFFFFFFFF;
//
//	nascerr_select_ecc(BYPASS_TO_SRAM);
//
//	// write 8b
//	for(int i = 0; i < 10; i++){
//		*(ptr + i) = data8b;
//	}
//
//	// read 8b
//	for(int i = 0; i < 10; i++){
//		read8b[i] = *(ptr + i);
//	}
//
//	// write 16b
//	for(int i = 0; i < 10; i++){
//		*(ptr + i) = data16b;
//	}
//
//	// read 16b
//	for(int i = 0; i < 10; i++){
//		read16b[i] = *(ptr + i);
//	}
//
//	// write 32b
//	for(int i = 0; i < 10; i++){
//		*(ptr + i) = data32b;
//	}
//
//	// read 32b
//	for(int i = 0; i < 10; i++){
//		read32b[i] = *(ptr + i);
//	}
//
//}


