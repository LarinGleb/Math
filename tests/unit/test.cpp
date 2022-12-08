#include <iostream>

#include "gtest/gtest.h"

#include "matrix_def.h"
#include "matrix_basic_op.h"

TEST(sample_test_case, sample_test)
{
   
    EXPECT_EQ(1, 1);
}

int main() {
    matrix_i test;
    int *values = new int[4]{1, 2, 1, 2};
    matrix_constructor(&test, 2, 2, &values);

    matrix_i test_2;
    int *values_2 = new int[4]{8, 2, 1, 9};
    matrix_constructor(&test, 2, 2, &values_2);

    
    add(test, test_2);
    print_matrix(&test);
    EXPECT_EQ(1, 1);
}