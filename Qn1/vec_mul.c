#include <stdio.h>

void vec_mul(double *vector, int size, double factor) {
    for (int i = 0; i < size; ++i) {
        vector[i] *= factor;
    }
}
