#include "matrix_op.h"
#include <stdio.h>

//Segment 1: Test Data
static void prepare_matrices(double A[SIZE][SIZE], double B[SIZE][SIZE]) {
    double a[SIZE][SIZE] = {
        {1, 2, 3},
        {0, 1, 4},
        {5, 6, 0}
    };
    double b[SIZE][SIZE] = {
        {-2, 1, 0},
        { 3, 0, 1},
        { 4, 5, 6}
    };
    mat_copy(a, A);
    mat_copy(b, B);
}
