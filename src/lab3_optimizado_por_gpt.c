
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define XDIM 10000
#define YDIM 10000

void alloc_matrix(double*** array) {
    *array = malloc(XDIM * sizeof(double*));
    for (int i = 0; i < XDIM; i++) {
        (*array)[i] = malloc(YDIM * sizeof(double));
        memset((*array)[i], 0, YDIM * sizeof(double));
    }
}

void fill(double** arr) {
    srand(time(NULL));
    for (int i = 0; i < XDIM; i++) {
        for (int j = 0; j < YDIM; j++) {
            arr[i][j] = (double)(rand() % 100);
        }
    }
}

void compute(double** arr, int kern[3][3]) {
    double accum;
    int i, j, k, l;

    for (i = 1; i < XDIM - 1; i++) {
        for (j = 1; j < YDIM - 1; j++) {
            accum = 0;
            for (k = -1; k <= 1; k++) {
                for (l = -1; l <= 1; l++) {
                    double dato = arr[i + l][j + k];
                    accum += 2 * kern[l + 1][k + 1] * dato / 1000 + 1;
                }
            }
            arr[i][j] = accum;
        }
    }
}

void print(double** arr) {
    for (int i = 0; i < XDIM; i++) {
        for (int j = 0; j < YDIM; j++) {
            printf("array[%d][%d] = %f\n", i, j, arr[i][j]);
        }
    }
}

int main(void) {
    double** arr;
    int kern[3][3] = {
        {0, -1, 0},
        {-1, 5, -1},
        {0, -1, 0}
    };

    alloc_matrix(&arr);
    fill(arr);
    compute(arr, kern);
    print(arr);

    return 0;
}
