/**
 * @file data.h
 * @brief Declaration of function for basic memory manipulation
 *
 * This header file provides an abstraction of data manipulation
 * via function calls. 
 *
 * @author Iosif Futerman
 * @date 22.03.2023
 *
 */
 
#ifndef __DATA_H__
#define __DATA_H__

#include <stddef.h>
#include <stdint.h>

/**
 * @brief Converts integer to string representation
 *
 *
 * @param data integer to be converted
 * @param ptr pointer to string
 * @param base base for converting
 *
 * @return count of symbols including \0
 */
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);

/**
 * @brief Converts string to integer representation
 *
 *
 * @param ptr string to be converted
 * @param digits count of digits in char representation
 * @param base base for converting
 *
 * @return resulting digit in integer representation.
 */
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);

#endif

