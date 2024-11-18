/**
 * Mahrj@msoe.edu
 * CPE 2600
 * 11/15/2024
 * pmod.c
 * Changes the process priority
 */

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

/**
 * changes the process priority by decreasing it by 10
 * then it will sleep for "x-time" before printing 'goodbye'
 */
int main() {
    // Change process priority by -10 
    if (nice(10) == -1) {
        perror("Error changing priority");
        exit(EXIT_FAILURE);
    }
    printf("Priority decreased by 10.\n");

    // Sleep
    struct timespec req = {1, 837272638};
    if (nanosleep(&req, NULL) == -1) {
        perror("Error during nanosleep");
        exit(EXIT_FAILURE);
    }

    printf("Goodbye!\n");
    return 0;
}
