/*
 * experimento.c
 *
 *  Created on: Aug 28, 2024
 *      Author: Clara
 */

#include <stdlib.h>
#include "NASCERR_Experimento.h"


uint16_t data_read;
volatile uint16_t * ptr = (volatile uint16_t *)NASCERR_SRAM_ADDRESS;
/*
 * ******************************************************************************
 *  Function Name: nascerr_write_sram
 *  @brief       : Writes a block of data to SRAM memory.
 *  @param       : hsram - A pointer to the SRAM_HandleTypeDef structure that
 *                          contains the configuration information for SRAM.
 *  @param       : offset - A 32-bit value indicating the starting address
 *                          in SRAM where the data should be written.
 *  @param       : data - An 8-bit value specifying the type of data to write.
 *                        Possible values:
 *                        00 - Fill the block with zeros.
 *                        01 - Fill the block with ones (0xFFFF).
 *                        02 - Fill the block with 0x5555.
 *                        03 - Fill the block with 0xAAAA.
 *                        04 - Fill the block with random 16-bit values.
 *  @param       : length - A 32-bit value specifying the size of the block to
 *                          be written in bytes. It should be an even number.
 *  @retval      : None
 * ******************************************************************************
 */
//void nascerr_write_sram(SRAM_HandleTypeDef *hsram, uint32_t offset, uint8_t data, uint32_t length){
//	uint16_t buffer[length/2]; // Buffer que guarda o dado a ser armazenado na memória.
//	uint16_t data_cell; // Guarda o tipo de palavra a ser armazenada.
//
//	switch(data){
//	// Preenche o buffer com zeros.
//	case 0:
//		data_cell = 0x0000;
//		for(uint32_t i = 0; i<(length/2); i++){
//			buffer[i] = data_cell;
//		}
//		break;
//
//	// Preenche o buffer com 0xFFFF.
//	case 1:
//		data_cell = 0xFFFF;
//		for(uint32_t i = 0; i<(length/2); i++){
//			buffer[i] = data_cell;
//		}
//		break;
//
//	// Preenche o buffer com 0x5555.
//	case 2:
//		data_cell = 0x5555;
//		for(uint32_t i = 0; i<(length/2); i++){
//			buffer[i] = data_cell;
//		}
//		break;
//
//	// Preenche o buffer com 0xAAAA.
//	case 3:
//		data_cell = 0xAAAA;
//		for(uint32_t i = 0; i<(length/2); i++){
//			buffer[i] = data_cell;
//		}
//		break;
//
//	// Preenche o buffer com dados aleatórios.
//	case 4:
//		for(uint32_t i = 0; i<(length/2); i++){
//			data_cell = (rand() % 65536); // Escolhe um número aleatório entre 0 e 65535 (16 bits) para colocar no buffer.
//			buffer[i] = data_cell;
//		}
//		break;
//	}
//
//	HAL_SRAM_Write_16b(hsram, (uint32_t*)offset, buffer, length);  // Escreve na memória usando a função da HAL.
//}
void nascerr_write_sram(uint16_t* write_buffer, uint32_t address, NASCERR_MODE ecc, W_DataTypeDef write_type, uint32_t length){
	nascerr_fill_buffer(write_buffer, write_type, length); // Preenche o buffer com o tipo de dado indicado no comando.
	nascerr_select_ecc(ecc); // seleciona o ECC.

	for(int i = 0; i < length; i++){
		*(ptr + i) = write_buffer[i];
	}
}

void nascerr_write_sram1(SRAM_HandleTypeDef *hsram, uint16_t* write_buffer, uint32_t address, NASCERR_MODE ecc, W_DataTypeDef write_type, uint32_t length){
	nascerr_fill_buffer(write_buffer, write_type, length); // Preenche o buffer com o tipo de dado indicado no comando.
	nascerr_select_ecc(ecc); // seleciona o ECC.

	HAL_SRAM_Write_16b(hsram, (uint32_t*) address, write_buffer, length);
}

/*
 * ******************************************************************************
 *  Function Name: nascerr_read_sram
 *  @brief       : Reads a block of data from SRAM memory.
 *  @param       : hsram - A pointer to the SRAM_HandleTypeDef structure that
 *                          contains the configuration information for SRAM.
 *  @param       : offset - A 32-bit value indicating the starting address
 *                          in SRAM from where the data should be read.
 *  @param       : buffer - A pointer to a memory area where the read data
 *                          will be stored.
 *  @param       : length - A 32-bit value specifying the size of the block to
 *                          be read in bytes. It should be an even number.
 *  @retval      : None
 * ******************************************************************************
 */
void nascerr_read_sram(uint16_t* read_buffer, uint32_t address, NASCERR_MODE ecc, uint32_t length){
	nascerr_select_ecc(ecc);
	for(int i = 0; i < length; i++){
		read_buffer[i] = *(ptr + address + i);
	}
}


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
void nascerr_select_ecc(NASCERR_MODE ecc){
	ptr = (uint16_t *)NASCERR_SRAM_ADDRESS;
	data_read =  *(ptr);

	switch(ecc){
	// 10
	case ECC_MOD1:
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_0,GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_1,GPIO_PIN_RESET);
		break;

	// 01
	case ECC_MOD2:
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_0,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_1,GPIO_PIN_SET);
		break;

	// 11
	case ECC_MOD3:
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

void nascerr_fill_buffer(uint16_t* buffer, W_DataTypeDef write_type, uint32_t length){
	uint16_t data_cell; // Guarda o tipo de palavra a ser armazenada.
	switch(write_type){
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
			data_cell = (rand() % 65536); // Escolhe um número aleatório entre 0 e 65535 (16 bits) para colocar no buffer.
			buffer[i] = data_cell;
		}
		break;
	}
}
//
//void testErrorAmount(Telecommand command){
//
//}



