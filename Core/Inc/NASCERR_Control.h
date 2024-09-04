/**
 * ******************************************************************************
 *  @file    : NASCERR_Control.h
 *  @brief   : Header for NASCERR_Control.c file.
 *  @author  : Marcus Anderson
 * ******************************************************************************
 */

#ifndef INC_NASCERR_CONTROL_H_
#define INC_NASCERR_CONTROL_H_

/*
 * ******************************************************************************
 *  Includes   <System Includes> , "Project Includes"
 * ******************************************************************************
 */
#include "NASCERR_System.h"
#include "main.h"

/*
 * ******************************************************************************
 *  Exported constants
 * ******************************************************************************
 */

/*
 * ******************************************************************************
 *  Exported types
 * ******************************************************************************
 */

typedef uint32_t nascerr_bock;
typedef uint16_t nascerr_rpt;

/* ... */
typedef enum
{
	READ_CMD = 0,     /* >              */
	WRITE_CMD,    	  /* >              */
} CmdTypeDef;

/* ... */
typedef enum
{
	WRITE_ZEROS = 0,   /* >              */
	WRITE_ONES,    	   /* >              */
	WRITE_x55h,    	   /* >              */
	WRITE_xAAh,    	   /* >              */
	WRITE_RANDOM,      /* >              */
} W_DataTypeDef;

/* ... */
typedef enum
{
	WORD_BY_WORD = 0,
	BOCK_BY_BOCK,
} Seq_ReadTypeDef;

/* ... */
typedef struct
{
	uint16_t        bytes_msg;
	CmdTypeDef      cmd_type;
	nascerr_bock    data_lenght;
	nascerr_rpt     repeat;
	W_DataTypeDef   write_type;
	Seq_ReadTypeDef data;
	NASCERR_MODE    mode;
	uint16_t        delay;
	uint16_t		crc16;
} NASCERR_CTRL;

/*
 * ******************************************************************************
 *  Exported global functions (to be accessed by other files)
 * ******************************************************************************
 */

#endif /* INC_NASCERR_CONTROL_H_ */
