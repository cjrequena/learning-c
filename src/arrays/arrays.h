//
// Created by Carlos José Requena Jiménez on 16/10/25.
//

#ifndef LEARNING_C_ARRAYS_H
#define LEARNING_C_ARRAYS_H
#include <stdio.h>

void printArrayAddresses(void);
int* returnAnArrayFromAfunction(void);
void mergeTwoSortedArrays(const int a[], size_t n, const int b[], size_t m, int c[n+m]);
int* mergeTwoSortedArraysV2(const int a[], size_t n, const int b[], size_t m);
int findTheMinimum(const int a[], int size);
int findTheMaximum(const int a[], int size);
int insertIntoArray(int a[], int size, int atIndex, int value);

#endif //LEARNING_C_ARRAYS_H