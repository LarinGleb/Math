#include <iostream>

#include "gtest/gtest.h"

#include "matrix_constructor.h"
#include "matrix_defines.h"
#include "matrix_eq.h"

TEST(basic_op_case_get_set, basic_operators_test) {
    // Arrange
    float *values = new float[4]{1, 2, 3, 4};
    matrix m;
    matrix_constructor(&m, 2, 2, &values);
    float value;
    // Act
    operator_get_set(&m, 0, 0, &value);
    // Assertion
    EXPECT_TRUE(value == 1.0f);
}
TEST(basic_op_case_get_return, basic_operators_test) {
    // Arrange
    float *values = new float[4]{1, 2, 3, 4};
    matrix m;
    matrix_constructor(&m, 2, 2, &values);
    // Assertion
    EXPECT_TRUE(operator_get_return(&m, 0, 0) == 1.0f);
}


TEST(basic_op_case_add_set, basic_operators_test) {

    // Arrange
    float *values = new float[4]{1, 2, 3, 4};
    float *values_2 = new float[4]{1, 8, 5, 2};
    matrix m;
    matrix_constructor(&m, 2, 2, &values);
    matrix m_2 = {2, 2, values_2};
    float *values_3 = new float[4]{2, 10, 8, 6};
    matrix m_3;
    matrix_constructor(&m_3, 2, 2, &values_3);
    // Act
    add(&m, &m_2);

    // Assertion
    EXPECT_TRUE(matrix_eq(&m_3, &m));
}
TEST(basic_op_case_add_return, basic_operators_test) {
    // Arrange
    float *values = new float[4]{1, 2, 3, 4};
    float *values_2 = new float[4]{1, 8, 5, 2};
    matrix m;
    matrix_constructor(&m, 2, 2, &values);
    matrix m_2 = {2, 2, values_2};
    float *values_3 = new float[4]{2, 10, 8, 6};
    matrix m_4;
    matrix_constructor(&m_4, 2, 2, &values_3);
    matrix m_3;
    matrix_constructor(&m_3, 2, 2);
    // Act
    m_3 = *operator_add_return(&m, &m_2);
    // Assertion
    EXPECT_TRUE(matrix_eq(&m_3, &m_4));
}


TEST(basic_op_case_mul_set, basic_operators_test) {
    // Arrange
    float *values = new float[4]{1, 2, 3, 4};
    float *values_2 = new float[4]{1, 8, 5, 2};
    matrix m;
    matrix_constructor(&m, 2, 2, &values);
    matrix m_2 = {2, 2, values_2};
    float *values_3 = new float[4]{25, 34, 11, 18};
    matrix m_3;
    matrix_constructor(&m_3, 2, 2, &values_3);
    // Act
    matrix* m_4 = (matrix*) malloc(sizeof(matrix));
    matrix_constructor(m_4, 2, 2);
    
    operator_mul_set(&m, &m_2, m_4);
    // Assertion
    EXPECT_TRUE(matrix_eq(&m_3, m_4));
}
TEST(basic_op_case_mul_return, basic_operators_test) {
    // Arrange
    float *values = new float[4]{1, 2, 3, 4};
    float *values_2 = new float[4]{1, 8, 5, 2};
    matrix m;
    matrix_constructor(&m, 2, 2, &values);
    matrix m_2 = {2, 2, values_2};
    float *values_3 = new float[4]{25, 34, 11, 18};
    matrix m_3;
    matrix_constructor(&m_3, 2, 2, &values_3);
    // Act
    matrix* m_4 = (matrix*) malloc(sizeof(matrix));
    m_4 = mul(&m, &m_2);
    // Assertion
    EXPECT_TRUE(matrix_eq(&m_3, m_4));
}


TEST(basic_op_case_mul_set_diffence_size, basic_operators_test) {
    // Arrange
    float *values = new float[12]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    float *values_2 = new float[20]{5, 6, 7, 8, 9, 11, 12, 14, 15, 20, 41, 101, 10, 1, 2, 3, 4, 5, 6, 7};
    matrix m;
    matrix_constructor(&m, 3, 4, &values);
    matrix m_2 = {4, 5, values_2};
    float *values_3 = new float[15]{158, 184, 210, 277, 323, 369, 1392, 1569, 1746, 58, 74, 90, 136, 158, 180};
    matrix m_3;
    matrix_constructor(&m_3, 3, 5, &values_3);
    // Act
    matrix* m_4 = (matrix*) malloc(sizeof(matrix));
    matrix_constructor(m_4, 3, 5);
    operator_mul_set(&m, &m_2, m_4);
    // Assertion
    EXPECT_TRUE(matrix_eq(&m_3, m_4));
}

TEST(basic_op_case_mul_return_diffence_size, basic_operators_test) {
    // Arrange
    float *values = new float[12]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    float *values_2 = new float[20]{5, 6, 7, 8, 9, 11, 12, 14, 15, 20, 41, 101, 10, 1, 2, 3, 4, 5, 6, 7};
    matrix m;
    matrix_constructor(&m, 3, 4, &values);
    matrix m_2 = {4, 5, values_2};
    float *values_3 = new float[15]{158, 184, 210, 277, 323, 369, 1392, 1569, 1746, 58, 74, 90, 136, 158, 180};
    matrix m_3;
    matrix_constructor(&m_3, 3, 5, &values_3);
    // Act
    matrix* m_4 = (matrix*) malloc(sizeof(matrix));
    
    m_4 = operator_mul_return(&m, &m_2);
    // Assertion
    EXPECT_TRUE(matrix_eq(&m_3, m_4));
}