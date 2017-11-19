/*
 * protocol_enums.h
 *
 * Contains basic values for protocol control
 *
 *  Created on: Jul 30, 2017
 *      Author: jirka
 */

#ifndef PROTOCOL_PROTOCOL_DEFINES_H_
#define PROTOCOL_PROTOCOL_DEFINES_H_

#define PROTOCOL_PREFIX 0x2A
#define PROTOCOL_BINARY_FORMAT 97
#define PROTOCOL_END 0x0D

#define PROTOCOL_DATA_MIN 5
#define PROTOCOL_DATA_MAX 65535

#define ACKNOWLEDGE_MIN 0
#define ACKNOWLEDGE_MAX 15

#define INSTRUCTION_MIN 16
#define INSTRUCTION_MAX 255

#define PROTOCOL_INST_MIN 0x10
#define PROTOCOL_INST_MAX 0xFF

#define PROTOCOL_ADDR_BROADCAST 0xFF
#define PROTOCOL_ADDR_UNIVERSAL 0xFE

#define PREFIX_BYTE    0
#define PROTOCOL_BYTE  1
#define DATA_BYTE_1    2
#define DATA_BYTE_2    3
#define ADDRESS_BYTE   4
#define SIGNATURE_BYTE 5
#define INSTR_ACK_BYTE 6
#define DATA_PTR_BYTE  7

#endif /* PROTOCOL_PROTOCOL_DEFINES_H_ */
