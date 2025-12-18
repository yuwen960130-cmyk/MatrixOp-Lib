#include <stdbool.h>
#ifndef MATRIX_OP_H
#define MATRIX_OP_H
#define SIZE 3


void mat_add(
    const double A[SIZE][SIZE],
    const double B[SIZE][SIZE],
    double C[SIZE][SIZE]
);// C = A + B 


void mat_sub(
    const double A[SIZE][SIZE],
    const double B[SIZE][SIZE],
    double C[SIZE][SIZE]
);// C = A - B 

void mat_elem_mul(
    const double A[SIZE][SIZE],
    const double B[SIZE][SIZE],
    double C[SIZE][SIZE]
);


void mat_mul(
    const double A[SIZE][SIZE],
    const double B[SIZE][SIZE],
    double C[SIZE][SIZE]
);//C = A * B

void mat_transpose(
    const double A[SIZE][SIZE],
    double T[SIZE][SIZE]
);


double mat_det2x2(
    double a11, double a12,
    double a21, double a22
);

double mat_det3x3(
    const double A[SIZE][SIZE]
);

void mat_adjoint(
    const double A[SIZE][SIZE],
    double adj[SIZE][SIZE]
);

bool mat_inverse(
    const double A[SIZE][SIZE],
    double inv[SIZE][SIZE]
);


