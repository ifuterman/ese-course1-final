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
 * @file stats.c 
 * @brief Implementation file for assessment 1 m 1
 *
 * @author Iosif Futerman
 * @date 04.03.2023
 *
 */



#include <stdio.h>
#include <stdlib.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

    printf("Original array:\n");
    print_array(test, SIZE);
    printf("Sorted array:\n");
    sort_array(test, SIZE);
    print_array(test, SIZE);
    printf("Array statistics\n");
    print_statistics(test, SIZE);

}

void print_array(const unsigned char* arr, int size){
    for(int i = 0; i < size; i++){
        printf( "array[%d] = %u\n",i, arr[i]);
    }
}

void print_statistics(const unsigned char* array, int size){
    printf("Array of unsigned chars.\n");
    printf("Array size is:%d\n", size);
    printf("Minimum value is: %u; ", find_minimum(array, size));
    printf("Maximun value is: %u;\n", find_maximum(array, size));
    printf("Mean value is: %u; ", find_mean(array, size));
    printf("Median value is: %u;\n", find_median(array, size));
}

void sort_array(unsigned char* array, int size){
    qsort(array, size, sizeof(unsigned char), comparator);
}

int comparator (const void* p1, const void* p2){
    return -1 * (*(unsigned char*)p1 - *(unsigned char*)p2);
}

unsigned char find_median(const unsigned char* array, int size){
    unsigned char* arrayCpy = calloc(size, sizeof(unsigned char));
    for(int i = 0; i < size; i++){
        arrayCpy[i] = array[i];
    }
    qsort(arrayCpy, size, sizeof(unsigned char), comparator);
    unsigned char res = 0;
    if(size % 2 != 0){
        res = array[(size / 2) + 1];
    }
    else{
        res = (array[size / 2] + array[(size / 2) + 1]) / 2;
    }
    free(arrayCpy);
    return  res;
}

unsigned char find_mean(const unsigned char* array, int size){
    int sum = 0;//int - because we need find the summ of all elements
    for(int i = 0; i < size; i++){
        sum += array[i];
    }
    return sum / size;
}

unsigned char find_maximum(const unsigned char* array, int size){
    if(size <= 0){
        return 0;
    }
    unsigned char max = array[0];
    for(int i = 1; i < size; i++){
        if(array[i] > max){
            max = array[i];
        }
    }
    return max;
}

unsigned char find_minimum(const unsigned char* array, int size){
    if(size <= 0){
        return 0;
    }
    unsigned char min = array[0];
    for(int i = 1; i < size; i++){
        if(array[i] < min){
            min = array[i];
        }
    }
    return min;
}
