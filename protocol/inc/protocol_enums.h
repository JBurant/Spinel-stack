/*
 * protocol_enums.h
 *
 *  Created on: Jul 30, 2017
 *      Author: jirka
 */

#ifndef PROTOCOL_PROTOCOL_ENUMS_H_
#define PROTOCOL_PROTOCOL_ENUMS_H_

typedef enum
{
  ACK_OK = 0,
  ACK_OTHER_ERR = 1,
  ACK_INVALID_INSTR_CODE = 2,
  ACK_INVALID_DATA = 3,
  ACK_RW_DENIED = 4,
  ACK_DEVICE_FAILURE = 5,
  ACK_DATA_TRANSFER = 0x0C,
  ACK_DATA_CHANGE_LOG_VALUE = 0xD,
  ACK_CONTINOUS_MEASUREMENT = 0xE,
  ACK_OTHER = 0xF
} ack_values;

typedef enum
{
	RET_OK,
	ERR_WRONG_PREFIX,
	ERR_WRONG_FORMAT,
	ERR_SMALL_DATA_LENGTH,
	ERR_BIG_DATA_LENGTH,
	WARN_DIFFERENT_ADDRESS,
	ERR_WRONG_INSTR_ACK,
	ERR_WRONG_CHECKSUM,
	ERR_WRONG_ENDSIGN
}message_ret_val;

#endif /* PROTOCOL_PROTOCOL_ENUMS_H_ */