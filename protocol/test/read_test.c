/*
 * read_test.c
 *
 *  Created on: Aug 19, 2017
 *      Author: jirka
 */

#include <protocol_message.h>
#include <protocol_defines.h>
#include <protocol_enums.h>

void read_test()
{
	message_ret_val retVal;
	message_t message;
	char test_data[8];
    char input_buffer[100];
    char data_checksum = 0x00;

    uint16_t data_length = (uint16_t) sizeof(test_data);

	test_data[0] ='t';
	test_data[1] ='e';
	test_data[2] ='s';
	test_data[3] ='t';
	test_data[4] ='d';
	test_data[5] ='a';
	test_data[6] ='t';
	test_data[7] ='a';

	input_buffer[PREFIX_BYTE] = PROTOCOL_PREFIX;
	input_buffer[PROTOCOL_BYTE] = PROTOCOL_BINARY_FORMAT;
	input_buffer[DATA_BYTE_1] = data_length / 256;
	input_buffer[DATA_BYTE_2] = data_length & 0x00FF;
	input_buffer[ADDRESS_BYTE] = 0x0A;
	input_buffer[SIGNATURE_BYTE] = 0x09;
	input_buffer[INSTR_ACK_BYTE] = 0x01;

	for(int i=0; i<data_length; i++)
	{
		input_buffer[INSTR_ACK_BYTE + 1 + i] = test_data[i];
	}

	input_buffer[INSTR_ACK_BYTE + 1 + data_length] = input_buffer[PREFIX_BYTE] ^ input_buffer[PROTOCOL_BYTE] ^ input_buffer[DATA_BYTE_1] ^ input_buffer[DATA_BYTE_2] ^ input_buffer[ADDRESS_BYTE] ^ input_buffer[SIGNATURE_BYTE] ^ input_buffer[INSTR_ACK_BYTE];

	for(int i=0; i<data_length; i++)
	{
		data_checksum = data_checksum ^ test_data[i];
		input_buffer[INSTR_ACK_BYTE + 1 + data_length] = input_buffer[INSTR_ACK_BYTE + 1 + data_length] ^ test_data[i];
	}

	input_buffer[INSTR_ACK_BYTE + 2 + data_length] = PROTOCOL_END;

	retVal = read_message(input_buffer, &message, test_data);
	app_assert(retVal == RET_OK);
}
