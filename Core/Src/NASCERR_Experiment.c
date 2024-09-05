/*
 * experimento.c
 *
 *  Created on: Aug 28, 2024
 *      Author: Clara
 */

#include <NASCERR_Experiment.h>
#include <NASCERR_Memory.h>
#include <stdlib.h>

uint16_t write_buffer[1024];
uint16_t read_buffer[1024];
uint16_t errors[1024];

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


uint16_t nascerr_experiment_test_error_amount(NASCERR_CTRL command){
	uint16_t error_total = 0;
	//definir elas como variáveis globais de tamanho 1024 (tamanho máximo de mensagens)
//	uint16_t write_buffer[command.data_lenght/2];
//	uint16_t read_buffer[command.data_lenght/2];
//	uint16_t errors[command.data_lenght/2];

	for(int i = 0; i < command.repeat; i++){
		nascerr_memory_write_sram((uint16_t*)write_buffer, 0, command.mode, command.write_type, command.data_lenght);
		nascerr_memory_read_sram(read_buffer, 0, command.mode, command.data_lenght);
		// rodar a função de erros
		error_total = nascerr_experiment_process_buffers(command.data_lenght, (uint16_t*)write_buffer, read_buffer, errors);
	}

	return error_total;
}


uint16_t nascerr_experiment_process_buffers(uint32_t length, uint16_t* data_write, uint16_t* data_read, uint16_t* errors) {
	uint16_t error_total = 0;

	for (uint32_t i = 0; i < length; ++i) {

		// Perform XOR operation between buffer1 and buffer2 and store the result in buffer3
		errors[i] = data_write[i] ^ data_read[i];
		if (errors[i]!=0)
			error_total++;
	}
	return error_total;
	// Further processing as needed
}
