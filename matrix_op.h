#ifndef MATRIX_OP_H
#define MATRIX_OP_H

#include <stdbool.h>

#define SIZE 3

//Basic Matrix Operations
void mat_add(const double A[SIZE][SIZE], const double B[SIZE][SIZE], double C[SIZE][SIZE]);
void mat_sub(const double A[SIZE][SIZE], const double B[SIZE][SIZE], double C[SIZE][SIZE]);
void mat_elem_mul(const double A[SIZE][SIZE], const double B[SIZE][SIZE], double C[SIZE][SIZE]);

//Linear Algebra Operations
void mat_mul(const double A[SIZE][SIZE], const double B[SIZE][SIZE], double C[SIZE][SIZE]);
void mat_transpose(const double A[SIZE][SIZE], double T[SIZE][SIZE]);

//Advanced Operations
double mat_det2x2(double a11, double a12, double a21, double a22);
double mat_det3x3(const double A[SIZE][SIZE]);
void mat_adjoint(const double A[SIZE][SIZE], double adj[SIZE][SIZE]);

//Inverse
bool mat_inverse(const double A[SIZE][SIZE], double inv[SIZE][SIZE]);

//Utility
void mat_copy(const double src[SIZE][SIZE], double dst[SIZE][SIZE]);
void mat_identity(double I[SIZE][SIZE]);
void mat_print(const char *title, const double A[SIZE][SIZE]);

#endif

