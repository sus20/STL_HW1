#include <stdio.h>
#include <stdlib.h> // For exit()
#include <papi.h>

// calculate the sum of integers from 1 to n
long long int sum(int n)
{
    long long int result = 0;
    for (int i = 1; i <= n; ++i)
    {
        result += i;
    }
    return result;
}

// PAPI initialization, event setup, counting, and cleanup void measurePerformance(int n)
void measurePerformance(int n)
{
    // Initialize PAPI
    if (PAPI_library_init(PAPI_VER_CURRENT) != PAPI_VER_CURRENT)
    {
        fprintf(stderr, "PAPI library init error!\n");
        exit(1);
    }

    // Create an event set
    int event_set = PAPI_NULL;
    if (PAPI_create_eventset(&event_set) != PAPI_OK)
    {
        fprintf(stderr, "PAPI event set creation error!\n");
        exit(1);
    }
    // Add events for wall clock time, CPU time, and cache misses
    if (PAPI_add_event(event_set, PAPI_TOT_CYC) != PAPI_OK ||
        PAPI_add_event(event_set, PAPI_TOT_INS) != PAPI_OK ||
        PAPI_add_event(event_set, PAPI_L1_DCM) != PAPI_OK)
    {
        fprintf(stderr, "PAPI event add error!\n");
        exit(1);
    }

    // Start counting
    if (PAPI_start(event_set) != PAPI_OK)
    {
        fprintf(stderr, "PAPI start error!\n");
        exit(1);
    }

    // Call the function to be measured
    long long int result = sum(n);

    // Stop counting
    if (PAPI_stop(event_set, NULL) != PAPI_OK)
    {
        fprintf(stderr, "PAPI stop error!\n");
        exit(1);
    }

    // Get the results
    long long values[3]; // Array to store results for three events
    if (PAPI_read(event_set, values) != PAPI_OK)
    {
        fprintf(stderr, "PAPI read error!\n");
        exit(1);
    }
    printf("Total cycles: %lld\n", values[0]);
    printf("Total instructions: %lld\n", values[1]);
    printf("L1 data cache misses: %lld\n", values[2]);

    // Clean up
    if (PAPI_cleanup_eventset(event_set) != PAPI_OK)
    {
        fprintf(stderr, "PAPI cleanup event set error!\n");
        exit(1);
    }
    if (PAPI_destroy_eventset(&event_set) != PAPI_OK)
    {
        fprintf(stderr, "PAPI destroy event set error!\n");
        exit(1);
    }
}

int main()
{
    int n = 1000000;
    printf("Sum of integers from 1 to %d is %lld\n", n, sum(n));
    measurePerformance(n);
    return 0;
}