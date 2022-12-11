#ifndef __MATRIX_DEF_H__
#define __MATRIX_DEF_H__

#include "matrix_basic_op.h"
#include "matrix_pointers.h
"
#define add(__lvalue, __rvalue) operator_add_get(__lvalue, __rvalue)
#define get(__matrix, __row, __col) opeator_get_return(__matrix, __row, __col)
#define v_ptr(__matrix, __row, __col) *ptr_value(__matrix, __row, __col)
#define mul(__lvalue, __rvalue) operator_mul_get(__lvalue, __rvalue)
	

#endif
