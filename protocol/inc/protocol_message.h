/*
 * protocol_message.h
 *
 *  Created on: Jul 30, 2017
 *      Author: jirka
 */

#ifndef PROTOCOL_PROTOCOL_MESSAGE_H_
#define PROTOCOL_PROTOCOL_MESSAGE_H_

#include <stdint.h>

typedef struct
{
  char    prefix;
  char    format;
  int16_t data_length;
  char    address;
  char    signature;
  char    instr_ack;
  char   *data_ptr;
  char    checksum;
  char    end_sign;
} message_t;

#endif /* PROTOCOL_PROTOCOL_MESSAGE_H_ */
