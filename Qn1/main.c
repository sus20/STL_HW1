#include <stdio.h>
#include <stdlib.h>
#include "vec_mul.c"

int main()
{
    int vector_size, factor;

    printf("Enter the size of the vector: ");
    scanf("%d", &vector_size);

    printf("Enter the factor: ");
    scanf("%d", &factor);

    printf("\n");

    double vector[vector_size];

    // Fill the vector with random numbers
    for (int i = 0; i < vector_size; ++i)
    {
        vector[i] = rand();
    }

    printf("Original vector: \n");
    for (int i = 0; i < vector_size; ++i)
    {
        printf("%.2f , ", vector[i]);
    }
    printf("\n");

    vec_mul(vector, vector_size, factor);
    printf("\n");

    printf("Vector after multiplication: \n");
    for (int i = 0; i < vector_size; ++i)
    {
        printf("%.2f , ", vector[i]);
    }
    printf("\n");

    return 0;
}