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

//Segment 2: Full Feature Tests
static void run_full_tests(const double A[SIZE][SIZE], const double B[SIZE][SIZE]) {
    double C[SIZE][SIZE];

    mat_add(A, B, C);
    mat_print("A + B =", C);

    mat_mul(A, B, C);
    mat_print("A * B =", C);

    double T[SIZE][SIZE];
    mat_transpose(A, T);
    mat_print("Transpose(A) =", T);

    double detA = mat_det3x3(A);
    printf("det(A) = %.6f\n\n", detA);

    double adjA[SIZE][SIZE];
    mat_adjoint(A, adjA);
    mat_print("adj(A) =", adjA);

    double invA[SIZE][SIZE];
    if (mat_inverse(A, invA)) {
        mat_print("inv(A) =", invA);

        double check[SIZE][SIZE];
        mat_mul(A, invA, check);
        mat_print("A * inv(A) (should be I) =", check);
    } else {
        printf("A is singular (det=0). No inverse.\n\n");
    }
}
