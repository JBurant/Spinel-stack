/*
 * message_wrapper.c
 *
 *  Created on: Jul 30, 2017
 *      Author: jirka
 */

#include <message_wrapper.h>
#include <device_config.h>
#include <utils.h>

void write_message(const int16_t data_length, const char address, const char signature, const char instr_ack, char * const data_ptr, char *output_buffer_ptr, message_t *message_ptr)
{
  char data_checksum = calculate_checksum(data_ptr, data_length);
  char message_checksum = calculate_checksum((char *) message_ptr, 7);

  message_ptr->prefix = PROTOCOL_PREFIX;
  message_ptr->format = PROTOCOL_BINARY_FORMAT;
  message_ptr->data_length = data_length;
  message_ptr->address = address;
  message_ptr->signature = signature;
  message_ptr->instr_ack = instr_ack;
  message_ptr->data_ptr = data_ptr;
  message_ptr->checksum = data_checksum ^ message_checksum;
  message_ptr->end_sign = PROTOCOL_END;

  memcpy_custom((char *) message_ptr, output_buffer_ptr, 7);
  memcpy_custom((char *) data_ptr, output_buffer_ptr + 7 , data_length);
  memcpy_custom((char *) message_ptr + 7 + sizeof(data_ptr), output_buffer_ptr + 7 + data_length, 2);

  output_buffer_ptr[7 + data_length] = message_ptr->checksum;
  output_buffer_ptr[8 + data_length] = message_ptr->end_sign;
}

message_ret_val read_message(char const input_buffer[], message_t *message_ptr, char *data_buffer_ptr)
{
	int retVal = RET_OK;

    if(PROTOCOL_PREFIX != (message_ptr->prefix = input_buffer[PREFIX_BYTE]))
    {
    	retVal = ERR_WRONG_PREFIX;
    	return retVal;
    }

    if(PROTOCOL_BINARY_FORMAT != (message_ptr->format = input_buffer[PROTOCOL_BYTE]))
    {
     	retVal = ERR_WRONG_FORMAT;
     	return retVal;
    }

    message_ptr->data_length = input_buffer[DATA_BYTE_1]*0xFF + input_buffer[DATA_BYTE_2];

    if(PROTOCOL_DATA_MIN > message_ptr->data_length)
    {
         retVal = ERR_SMALL_DATA_LENGTH;
         return retVal;
    }

    if(PROTOCOL_DATA_MAX < message_ptr->data_length)
    {
         retVal = ERR_BIG_DATA_LENGTH;
         return retVal;
    }

    message_ptr->address = input_buffer[ADDRESS_BYTE];

    if((DEVICE_ADDRESS != message_ptr->address) && (PROTOCOL_ADDR_BROADCAST != message_ptr->address) && (PROTOCOL_ADDR_UNIVERSAL != message_ptr->address))
    {
      	retVal = WARN_DIFFERENT_ADDRESS;
       	return retVal;
    }

    message_ptr->instr_ack = input_buffer[INSTR_ACK_BYTE];

    if((ACKNOWLEDGE_MIN > message_ptr->instr_ack) || (INSTRUCTION_MAX < message_ptr->instr_ack))
    {
         retVal = ERR_WRONG_INSTR_ACK;
         return retVal;
    }

    message_ptr->data_ptr = data_buffer_ptr;
    message_ptr->checksum = input_buffer[DATA_PTR_BYTE + message_ptr->data_length];

    if(message_ptr->checksum != calculate_checksum(input_buffer, DATA_PTR_BYTE + message_ptr->data_length))
    {
    	retVal = ERR_WRONG_CHECKSUM;
        return retVal;
    }

    message_ptr->end_sign = input_buffer[DATA_PTR_BYTE + (message_ptr->data_length) + 1];

    if(PROTOCOL_END != message_ptr->end_sign)
    {
    	retVal = ERR_WRONG_ENDSIGN;
        return retVal;
    }

    memcpy_custom(&input_buffer[DATA_PTR_BYTE], data_buffer_ptr, message_ptr->data_length);

  return retVal;
}
