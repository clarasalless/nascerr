/*
 * experimento.h
 *
 *  Created on: Aug 28, 2024
 *      Author: Clara
 */

#ifndef INC_NASCERR_EXPERIMENTO_H_
#define INC_NASCERR_EXPERIMENTO_H_

#include <stdint.h>
#include "stm32l4xx_hal.h"
#include "NASCERR_Control.h"


#define NASCERR_SRAM_ADDRESS 0x60000000UL // Base address for SRAM

// Funções:
void nascerr_write_sram(uint16_t* buffer, uint32_t address, NASCERR_MODE ecc, W_DataTypeDef write_type, uint32_t length);
void nascerr_read_sram(uint16_t* read_buffer, uint32_t address, NASCERR_MODE ecc, uint32_t length);
void nascerr_write_sram1(SRAM_HandleTypeDef *hsram, uint16_t* write_buffer, uint32_t address, NASCERR_MODE ecc, W_DataTypeDef write_type, uint32_t length);
void nascerr_fill_buffer(uint16_t* buffer, W_DataTypeDef write_type, uint32_t length);
void nascerr_select_ecc(uint8_t ecc);
//void testErrorAmount(Telecommand command);


#endif /* INC_NASCERR_EXPERIMENTO_H_ */
