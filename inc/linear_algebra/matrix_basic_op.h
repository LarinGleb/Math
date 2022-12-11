#ifndef __MATRIX_OPERATIONS_BASIC__
#define __MATRIX_OPERATIONS_BASIC__

#include <stdio.h>
#include <limits.h>

#include "matrix_constructor.h"
#include "matrix_pointers.h"

// ---------- OPERATORS-GETERS FLOAT----------
inline float operator_get_return(const struct __matrix_s_float* __matrix, const size_t __row, const size_t __col) {
    if (__matrix->__c_row * __row + __col >= __matrix->__c_row * __matrix->__c_col) {return INT_MIN;}
    return *ptr_value(__matrix, __row, __col);
}
inline struct __matrix_s_float* operator_add_return(const struct __matrix_s_float* __lvalue, const struct __matrix_s_float* __rvalue) {
    struct __matrix_s_float *__matrix_add = (__matrix_s_float*) malloc(sizeof(__matrix_s_float));
    matrix_constructor(__matrix_add,  __lvalue->__c_row, __lvalue->__c_col);
    if (__lvalue->__c_col * __lvalue->__c_row != __rvalue->__c_col * __rvalue->__c_row ) {return __matrix_add; }
    for (size_t __row = 0; __row < __lvalue->__c_row; __row++) {
        for (size_t __col = 0; __col < __lvalue->__c_col; __col++ ) {
            *ptr_value(__matrix_add, __row, __col) += *ptr_value(__rvalue, __row, __col) + *ptr_value(__lvalue, __row, __col);
        }
    }
    return __matrix_add;
}
inline struct __matrix_s_float* operator_mul_return(const struct __matrix_s_float* __lvalue, const struct __matrix_s_float* __rvalue) {
    struct __matrix_s_float* __matrix_mul = (__matrix_s_float*) malloc(sizeof(__matrix_s_float));;
    matrix_constructor(__matrix_mul,  __lvalue->__c_row, __rvalue->__c_col);
    if(__lvalue->__c_col != __rvalue->__c_row) {return __matrix_mul;}
    for (size_t __row = 0; __row < __lvalue->__c_row; __row++) {
        for (size_t __col = 0; __col < __rvalue->__c_col; __col++ ) {
            for (size_t __temp = 0; __temp < __rvalue->__c_col; __temp ++) {
                *ptr_value(__matrix_mul, __row, __col) += *ptr_value(__lvalue, __row, __temp) * *ptr_value(__rvalue, __temp, __col);
            }
        }
    }
    return __matrix_mul;
}


// ---------- OPERATORS-SETERS FLOAT----------
inline void operator_get_set(const struct __matrix_s_float* __matrix, const size_t __row, const size_t __col, float* __value) {
    if (__matrix->__c_row * __row + __col >= __matrix->__c_row * __matrix->__c_col) {return;}
    *__value = *ptr_value(__matrix, __row, __col);
}
inline void operator_add_set(const struct __matrix_s_float* __lvalue, const struct __matrix_s_float* __rvalue, const struct __matrix_s_float* __set_value) {
    if (__lvalue->__c_col * __lvalue->__c_row != __rvalue->__c_col * __rvalue->__c_row ) {return;}
    for (size_t __row = 0; __row < __lvalue->__c_row; __row++) {
        for (size_t __col = 0; __col < __lvalue->__c_col; __col++ ) {
            *ptr_value(__set_value, __row, __col) = *ptr_value(__lvalue, __row, __col) + *ptr_value(__rvalue, __row, __col);
        }
    }
}
inline void operator_mul_set(const struct __matrix_s_float* __lvalue, const struct __matrix_s_float* __rvalue, const struct __matrix_s_float* __matrix_mul) {
    if(__lvalue->__c_col != __rvalue->__c_row) {return;}
    for (size_t __row = 0; __row < __lvalue->__c_row; __row++) {
        for (size_t __col = 0; __col < __rvalue->__c_col; __col++ ) {
            for (size_t __temp = 0; __temp < __rvalue->__c_row; __temp ++) {
                *ptr_value(__matrix_mul, __row, __col) += *ptr_value(__lvalue, __row, __temp) * *ptr_value(__rvalue, __temp, __col);
            }
        }
    }
}

#endif
