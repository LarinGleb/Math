#ifndef __MATRIX_EQ_H__
#define __MATRIX_EQ_H__

#include <iostream>

#include "gtest/gtest.h"

#include "matrix_constructor.h"

inline bool values_eq(const float* __lvalue, const float* __rvalue, const std::size_t __c_row, const std::size_t __c_col) {
    //std::cout << __c_row << " " << __c_col << std::endl;
    for (std::size_t __row = 0; __row < __c_row; __row++) {
        for (std::size_t __col = 0; __col < __c_col; __col ++) {
            //std::cout << *(__lvalue + __c_row * __row + __col) << " " << *(__rvalue + __c_row * __row + __col) << std::endl;
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
        std::cout << "Difference row count: " << __lvalue->__c_row << " and " << __rvalue->__c_row << std::endl;
        return ::testing::AssertionFailure();
    }

    if (!values_eq(__lvalue->__values, __rvalue->__values, __lvalue->__c_row, __lvalue->__c_col)) {
        std::cout << "Difference values" << std::endl;
        return ::testing::AssertionFailure();
    }

    return ::testing::AssertionSuccess();   

}

#endif