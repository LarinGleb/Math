#ifndef __MATRIX_DEF_H__
#define __MATRIX_DEF_H__

#include <stdio.h>
#include <stdlib.h>

typedef struct __matrix_s_float{
    size_t __c_row;
    size_t __c_col;

    float* __values;
} matrix_f;

typedef struct __matrix_s_int{
    size_t __c_row;
    size_t __c_col;

    int* __values;
} matrix_i;


typedef matrix_f matrix; 

inline void matrix_constructor(struct __matrix_s_float* __matrix, const size_t __c_rows, const size_t __c_columns, float** __values) {
    __matrix->__c_row = __c_rows;
    __matrix->__c_col = __c_columns;
    __matrix->__values = (float*) calloc(__c_columns*__c_rows, sizeof(float)); 
    __matrix->__values = *__values;
}

inline void matrix_constructor(struct __matrix_s_int* __matrix, const size_t __c_rows, const size_t __c_columns, int** __values) {
    __matrix->__c_row = __c_rows;
    __matrix->__c_col = __c_columns;
    __matrix->__values = (int*) calloc(__c_columns*__c_rows, sizeof(int)); 
    __matrix->__values = *__values;
}

inline void print_matrix(struct __matrix_s_int* __matrix) {
    for (size_t __row = 0; __row < __matrix->__c_row; __row++) {
        for (size_t __col = 0; __col < __matrix->__c_col; __col++) {
            printf("%d ", __matrix->__values[__row * __matrix->__c_row + __col]);
        }
        printf("\n");
    }
}
#endif