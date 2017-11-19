/*
 * utils.h
 *
 *  Created on: Jul 30, 2017
 *      Author: jirka
 */

#ifndef PROTOCOL_INC_UTILS_H_
#define PROTOCOL_INC_UTILS_H_

#include <stdbool.h>

void memcpy_custom(char const * const input_buffer_ptr, char * const output_buffer_ptr, int const length);
char calculate_checksum(char const * const buffer_ptr, int const buffer_length);
void app_assert(bool expression);

#endif /* PROTOCOL_INC_UTILS_H_ */
