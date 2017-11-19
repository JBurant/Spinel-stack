/*
 * write_test.c
 *
 *  Created on: Aug 19, 2017
 *      Author: jirka
 */

#include <protocol_message.h>
#include <protocol_defines.h>
#include <protocol_enums.h>

void write_test()
{
	char output_buffer[48];
	char data_buffer[4];

	data_buffer[0] = 't';
	data_buffer[1] = 'e';
	data_buffer[2] = 's';
	data_buffer[3] = 't';

	message_t message;

	write_message(4, 0x0a, 0x0d, 0x01, data_buffer, output_buffer, &message);

	app_assert(PROTOCOL_PREFIX == message.prefix);
	app_assert(PROTOCOL_BINARY_FORMAT == message.format);
	app_assert(4 == message.data_length);
	app_assert(0x0a == message.address);
	app_assert(0x0d == message.signature);
	app_assert(0x01 == message.instr_ack);
	//app_assert( == message.checksum);
	app_assert(PROTOCOL_END == message.end_sign);

	app_assert(output_buffer[PREFIX_BYTE] == message.prefix);
	app_assert(output_buffer[PROTOCOL_BYTE] == message.format);
	app_assert((output_buffer[DATA_BYTE_1] + output_buffer[DATA_BYTE_2]*256) == message.data_length);
	app_assert(output_buffer[ADDRESS_BYTE] == message.address);
	app_assert(output_buffer[SIGNATURE_BYTE] == message.signature);
	app_assert(output_buffer[INSTR_ACK_BYTE] == message.instr_ack);

	for(int i=0; i < message.data_length; i++)
	{
		app_assert(output_buffer[INSTR_ACK_BYTE + i + 1] == data_buffer[i]);
	}

	//app_assert( == message.checksum);
	app_assert(output_buffer[INSTR_ACK_BYTE + message.data_length + 2] == message.end_sign);

}
