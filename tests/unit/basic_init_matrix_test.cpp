#include <iostream>

#include "gtest/gtest.h"

#include "matrix_def.h"
#include "matrix_pointers.h"
#include "matrix_eq.h"

TEST(constructor_case_default, constructor_test)
{   
    // Arrange
    float *values = new float[4]{1, 2, 3, 4};
    matrix m;
    matrix m_2 = {2, 2, values};

    // Act
    matrix_constructor(&m, 2, 2, &values);

    // Assertion
    EXPECT_TRUE(matrix_eq(&m , &m_2));
}

TEST(ptr_cases, ptr_test)
{   
    // Arrange
    float *values = new float[4]{1, 2, 3, 4};
    matrix m;
    matrix_constructor(&m, 2, 2, &values);

    // Assertion
    EXPECT_EQ(1, *ptr_value(&m, 0, 0));
    EXPECT_EQ(4, *ptr_value(&m, 1, 1));
}


