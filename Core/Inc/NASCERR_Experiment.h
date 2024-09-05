/*
 * experimento.h
 *
 *  Created on: Aug 28, 2024
 *      Author: Clara
 */

#ifndef INC_NASCERR_EXPERIMENT_H_
#define INC_NASCERR_EXPERIMENT_H_

#include <stdint.h>
#include "stm32l4xx_hal.h"
#include "NASCERR_Control.h"
#include "NASCERR_IOs.h"


// Funções:
void nascerr_experiment_select_ecc(uint8_t ecc);
uint16_t nascerr_experiment_test(NASCERR_CTRL command);
void nascerr_experiment_testrw(uint8_t* read8b, uint16_t* read16b, uint32_t* read32b);
uint16_t nascerr_experiment_process_buffers(uint32_t length, uint16_t* data_write, uint16_t* data_read, uint16_t* errors);


#endif /* INC_NASCERR_EXPERIMENT_H_ */
