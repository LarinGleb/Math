#ifndef __MATRIX_CONSTRUCTOR_H__
#define __MATRIX_CONSTRUCTOR_H__

#include <stdio.h>
#include <stdlib.h>

typedef struct __matrix_s_float{
    size_t __c_row;
    size_t __c_col;

    float* __values;
} matrix_f;


typedef matrix_f matrix; 

inline void matrix_constructor(struct __matrix_s_float* __matrix, const size_t __c_rows, const size_t __c_columns, float** __values) {
    __matrix->__c_row = __c_rows;
    __matrix->__c_col = __c_columns;
    __matrix->__values = (float*) calloc(__c_columns*__c_rows, sizeof(float)); 
    __matrix->__values = *__values;
}

inline void matrix_constructor(struct __matrix_s_float* __matrix, const size_t __c_rows, const size_t __c_columns) {
    __matrix->__c_row = __c_rows;
    __matrix->__c_col = __c_columns;
    __matrix->__values = (float*) calloc(__c_rows*__c_columns, sizeof(float));
}

inline void print_matrix(struct __matrix_s_float* __matrix, const char *__restrict__ __format) {
    for (size_t __row = 0; __row < __matrix->__c_row; __row++) {
        for (size_t __col = 0; __col < __matrix->__c_col; __col++) {
            printf(__format,  *(__matrix->__values+ (__col * __matrix->__c_row) + __row));
        }
        printf("\n");
    }
}
#endif