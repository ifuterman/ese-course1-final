/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file stats.h 
 * @brief Header file for assessment 1 m 1
 *
 * @author Iosif Futerman
 * @date 04.03.2023
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/**
 * @brief Comparator for sorting
 This is thr revers comparator for qsort function
 * @param v1  pointer to the first caomparable variable
 * @param v2  pointer to the second caomparable variable
 */
int comparator (const void* v1, const void* v2);
/**
 * @brief Prints array
 * This function prints entire array
 * @param array  array of unsigned char* to be printed
 * @param size size of the array
 */
void print_array(const unsigned char* array, int size);
/**
 * @brief Prints array statistic
 * A function that prints the statistics of an array including minimum, maximum, mean, and median
 * @param array  array of unsigned char* to be analised
 * @param size size of the array
 */
void print_statistics(const unsigned char* array, int size);
/**
 * @brief Returns a median value of a given array
 * A function that evaluates median value and returns it
 * @param array  array of unsigned char* to be analised
 * @param size size of the array
 * @Return median value
 */
unsigned char find_median(const unsigned char* array, int size);
/**
 * @brief Returns a mean value of a given array
 * A function that evaluates mean value and returns it
 * @param array  array of unsigned char* to be analised
 * @param size size of the array
 * @Return mean value
 */
unsigned char find_mean(const unsigned char* array, int size);
/**
 * @brief Returns a maximum value of a given array
 * A function that evaluates maximum value and returns it
 * @param array  array of unsigned char* to be analised
 * @param size size of the array
 * @Return maximum value
 */
unsigned char find_maximum(const unsigned char* array, int size);
/**
 * @brief Returns a minimum value of a given array
 * A function that evaluates minimum value and returns it
 * @param array  array of unsigned char* to be analised
 * @param size size of the array
 * @Return minimum value
 */
unsigned char find_minimum(const unsigned char* array, int size);
/**
 * @brief Sorts given array
 * Given an array of data and a length, sorts the array from largest to smallest.
 * (The zeroth Element will be the largest value, and the last element (n-1) will be the smallest value. )
 * @param array  array of unsigned char* to be sorted
 * @param size size of the array
 */
void sort_array(unsigned char* array, int size);


#endif /* __STATS_H__ */
