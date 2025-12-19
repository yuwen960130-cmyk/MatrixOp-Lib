#include "matrix_op.h"
#include <stdio.h>


//Segment 1: Utility Functions
void mat_copy(const double src[SIZE][SIZE], double dst[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            dst[i][j] = src[i][j];
        }
    }
}

void mat_identity(double I[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            I[i][j] = (i == j) ? 1.0 : 0.0;
        }
    }
}

void mat_print(const char *title, const double A[SIZE][SIZE]) {
    if (title) printf("%s\n", title);
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%10.4f ", A[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}


//Segment 2: Basic Operations
void mat_add(const double A[SIZE][SIZE], const double B[SIZE][SIZE], double C[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void mat_sub(const double A[SIZE][SIZE], const double B[SIZE][SIZE], double C[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

void mat_elem_mul(const double A[SIZE][SIZE], const double B[SIZE][SIZE], double C[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            C[i][j] = A[i][j] * B[i][j];
        }
    }
}

//Segment 3: Linear Algebra Operations
void mat_mul(const double A[SIZE][SIZE], const double B[SIZE][SIZE], double C[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            double sum = 0.0;
            for (int k = 0; k < SIZE; k++) {
                sum += A[i][k] * B[k][j];
            }
            C[i][j] = sum;
        }
    }
}

void mat_transpose(const double A[SIZE][SIZE], double T[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            T[j][i] = A[i][j];
        }
    }
}
