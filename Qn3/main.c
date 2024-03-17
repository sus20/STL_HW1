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

int main()
{
    // Initialize PAPI
    PAPI_library_init(PAPI_VER_CURRENT);
    long long start_time, end_time, elapsed_time;
    long long values[3];

    int n = 1000000;

    // events to measure
    int events[] = {PAPI_TOT_CYC, PAPI_L2_TCM, PAPI_TOT_INS};

    // Start the PAPI timer
    start_time = PAPI_get_real_usec();

    // Start counting the events
    PAPI_start_counters(events, 3);

    printf("Sum of integers from 1 to %d is %lld\n", n, sum(n));

    // Stop counting the events
    PAPI_stop_counters(values, 3);

    // Stop the PAPI timer
    end_time = PAPI_get_real_usec();

    // Calculate elapsed time
    elapsed_time = end_time - start_time;

    printf("Elapsed time: %lld microseconds\n", elapsed_time);

    // Print the measured values
    printf("CPU time: %lld cycles\n", values[0]);
    printf("L2 cache misses: %lld\n", values[1]);
    printf("Total instructions executed: %lld\n", values[2]);

    // Shutdown PAPI
    PAPI_shutdown();

    return 0;
}