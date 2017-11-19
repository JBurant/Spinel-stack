/*
 * message_wrapper.h
 *
 *  Created on: Jul 30, 2017
 *      Author: jirka
 */

#ifndef PROTOCOL_INC_MESSAGE_WRAPPER_H_
#define PROTOCOL_INC_MESSAGE_WRAPPER_H_

#include <protocol_message.h>
#include <protocol_defines.h>
#include <protocol_enums.h>

#include <stdint.h>

void write_message(const int16_t data_length, const char address, const char signature, const char instr_ack, char * const data_ptr, char *output_buffer_ptr, message_t *message_ptr);
message_ret_val read_message(char const input_buffer[], message_t *message_ptr, char *data_buffer_ptr);

#endif /* PROTOCOL_INC_MESSAGE_WRAPPER_H_ */
