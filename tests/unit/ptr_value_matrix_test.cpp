#include <iostream>

#include "gtest/gtest.h"

#include "matrix_constructor.h"
#include "matrix_defines.h"

TEST(ptr_value_case_eq, ptr_value_test) {
    // Arrange
    float *values = new float[4]{1, 2, 3, 4};
    matrix m;
    matrix m_2 = {2, 2, values};
    matrix_constructor(&m, 2, 2, &values);
    // Act
    EXPECT_TRUE(*v_ptr(&m, 0, 0) == 1.0f);
    EXPECT_TRUE(*v_ptr(&m, 0, 0) == *ptr_value(&m_2, 0, 0));
}

TEST(ptr_value_case_not_eq, ptr_value_test) {
    // Arrange
    float *values = new float[4]{1, 2, 3, 4};
    matrix m;
    matrix m_2 = {2, 2, values};
    matrix_constructor(&m, 2, 2, &values);
    // Act
    EXPECT_FALSE(*ptr_value(&m, 0, 0) == 2.0f);
    EXPECT_FALSE(*ptr_value(&m, 0, 0) == *ptr_value(&m_2, 1, 0));
}


