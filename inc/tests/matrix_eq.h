#ifndef __MATRIX_EQ_H__
#define __MATRIX_EQ_H__

#include <iostream>

#include "gtest/gtest.h"

#include "matrix_def.h"

inline bool values_eq(const float* __lvalue, const float* __rvalue, const std::size_t __c_row, const std::size_t __c_col) {
    for (std::size_t __row = 0; __row < __c_row; __row++) {
        for (std::size_t __col; __col < __c_col; __col ++) {
            if (*(__lvalue + __c_row * __row + __col) != *(__rvalue + __c_row * __row + __col)) {
                return false;
            }
        }
    }
    return true;
}

inline ::testing::AssertionResult matrix_eq(const struct __matrix_s_float* __lvalue, const struct __matrix_s_float* __rvalue) {

    if (__lvalue->__c_col != __rvalue->__c_col) {
        std::cout << "Difference column count: " << __lvalue->__c_col << " and " << __rvalue->__c_col << std::endl;
        return ::testing::AssertionFailure();
    }

    if (__lvalue->__c_row != __rvalue->__c_row) {
        std::cout << "Difference column count: " << __lvalue->__c_row << " and " << __rvalue->__c_row << std::endl;
        return ::testing::AssertionFailure();
    }

    if (!values_eq(__lvalue->__values, __rvalue->__values, __lvalue->__c_row, __lvalue->__c_col)) {
        std::cout << "Difference values count: " << std::endl;
        return ::testing::AssertionFailure();
    }

    return ::testing::AssertionSuccess();   

}

#endif