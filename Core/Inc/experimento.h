/*
 * experimento.h
 *
 *  Created on: Aug 28, 2024
 *      Author: Clara
 */

#ifndef INC_EXPERIMENTO_H_
#define INC_EXPERIMENTO_H_

#include <stdint.h>
#include "stm32l4xx_hal.h"

// Enumeração para determinar o tipo de ECC a ser utilizado:
enum ECC {HAMMING=1, TBEC, EDAC, BYPASS};


// Estruturas:
typedef struct {
	uint8_t command;
	uint32_t block;
	uint8_t repeat;
	uint8_t data_type;
	uint8_t sequence;
	uint8_t ecc;
	uint16_t delay;
} Telecommand;


// Funções:
void writeSRAM(SRAM_HandleTypeDef *hsram, uint32_t offset, uint8_t data, uint32_t length);
void readSRAM(SRAM_HandleTypeDef *hsram, uint32_t offset, uint16_t* buffer, uint32_t length);
void selectECC(uint8_t ecc);
void testErrorAmount(Telecommand command);


#endif /* INC_EXPERIMENTO_H_ */
