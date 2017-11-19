/*
 * utils.c
 *
 *  Created on: Jul 30, 2017
 *      Author: jirka
 */

#include <utils.h>

void memcpy_custom(char const * const input_buffer_ptr, char * const output_buffer_ptr, int const length)
{
	for(int i=0; i < length; i++)
	{
		*(output_buffer_ptr + i) = *(input_buffer_ptr + i);
    }
}

char calculate_checksum(char const * const buffer_ptr, int const buffer_length)
{
	char checksum = 0x00;

	for(int i=0; i < buffer_length; i++)
    {
        checksum = checksum ^ (*(buffer_ptr + i));
    }

    return checksum;
}

void app_assert(bool expression)
{
    while(!expression)
    {

    }
}
