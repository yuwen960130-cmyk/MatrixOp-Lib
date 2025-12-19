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
double mat_det2x2(double a11, double a12, double a21, double a22) {
    return a11 * a22 - a12 * a21;
}

double mat_det3x3(const double A[SIZE][SIZE]) {
    double a = A[0][0], b = A[0][1], c = A[0][2];
    double d = A[1][0], e = A[1][1], f = A[1][2];
    double g = A[2][0], h = A[2][1], i = A[2][2];
    return a * (e * i - f * h) - b * (d * i - f * g) + c * (d * h - e * g);
}

void mat_adjoint(const double A[SIZE][SIZE], double adj[SIZE][SIZE]) {
    double C[SIZE][SIZE];

    for (int r = 0; r < SIZE; r++) {
        for (int c = 0; c < SIZE; c++) {
            double m[2][2];
            int mi = 0;

            for (int i = 0; i < SIZE; i++) {
                if (i == r) continue;
                int mj = 0;
                for (int j = 0; j < SIZE; j++) {
                    if (j == c) continue;
                    m[mi][mj] = A[i][j];
                    mj++;
                }
                mi++;
            }

            double minor_det = mat_det2x2(m[0][0], m[0][1], m[1][0], m[1][1]);
            double sign = ((r + c) % 2 == 0) ? 1.0 : -1.0;
            C[r][c] = sign * minor_det;
        }
    }

    mat_transpose(C, adj);
}

bool mat_inverse(const double A[SIZE][SIZE], double inv[SIZE][SIZE]) {
    const double EPS = 1e-12;
    double det = mat_det3x3(A);

    if (det > -EPS && det < EPS) {
        return false;
    }

    double adj[SIZE][SIZE];
    mat_adjoint(A, adj);

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            inv[i][j] = adj[i][j] / det;
        }
    }
    return true;
}
