#include <iostream>

#include "gtest/gtest.h"

#include "matrix_constructor.h"
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
TEST(constructor_case_diffence_column, constructor_test)
{   
    // Arrange
    float *values = new float[4]{1, 2, 3, 4};
    float *values_2 = new float[6]{1, 2, 3, 4, 5, 6};
    matrix m;
    matrix m_2 = {2, 3, values};
    // Act
    matrix_constructor(&m, 2, 2, &values_2);
    // Assertion
    EXPECT_FALSE(matrix_eq(&m , &m_2));
}


TEST(constructor_case_diffence_row, constructor_test)
{   
    // Arrange
    float *values = new float[4]{1, 2, 3, 4};
    float *values_2 = new float[6]{1, 2, 3, 4, 5, 6};
    matrix m;
    matrix m_2 = {3, 2, values};
    // Act
    matrix_constructor(&m, 2, 2, &values_2);
    // Assertion
    EXPECT_FALSE(matrix_eq(&m , &m_2));
}

TEST(constructor_case_diffence_value, constructor_test)
{   
    // Arrange
    float *values = new float[4]{1, 2, 3, 4};
    float *values_2 = new float[4]{1, 3, 4, 4};
    matrix m;
    matrix m_2 = {2, 2, values};
    // Act
    matrix_constructor(&m, 2, 2, &values_2);
    // Assertion
    EXPECT_FALSE(matrix_eq(&m , &m_2));
}
