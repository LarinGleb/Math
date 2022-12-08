#ifndef __POINTER_MATRIX__
#define __POINTER_MATRIX__

#include <stdio.h>

#include "matrix_def.h" 

inline float* ptr_value(const struct __matrix_s_float* __matrix, const size_t __row, const size_t __col) {
    return __matrix->__values + __matrix->__c_row*__row + __col;
}

#endif