/**
 * Mahrj@msoe.edu
 * CPE 2600
 * 11/15/2024
 * pinfo.c
 * This program prints out the priority of the inputed process
 * out to the user
 */

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <sched.h>
#include <unistd.h>
#include <errno.h>
#include <sys/resource.h>

/**
 * This method look for user input from the command line and prints out the
 * priority of that given item to the user.
 */
int main(int argc, char *argv[]) {
    // Reads command line input
    pid_t pid;
    if (argc == 2) {
        pid = atoi(argv[1]);
    } else {
        pid = getpid();
    }
    int priority = getpriority(PRIO_PROCESS, pid);

    // Makes sure no errors have occured
    if (priority == -1 && errno != 0) {
        perror("Error retrieving priority");
        exit(EXIT_FAILURE);
    }

    printf("Process priority: %d\n", priority);

    int policy = sched_getscheduler(pid);
    // If the pid < 0
    if (policy == -1) {
        perror("Error retrieving scheduler policy");
        exit(EXIT_FAILURE);
    }
    // The policies the program can grab
    const char *policy_name = (policy == SCHED_FIFO) ? "SCHED_FIFO" :
                              (policy == SCHED_RR) ? "SCHED_RR" :
                              (policy == SCHED_OTHER) ? "SCHED_OTHER" :
                              (policy == SCHED_BATCH) ? "SCHED_BATCH" :
                              (policy == SCHED_IDLE) ? "SCHED_IDLE" : "UNKNOWN";

    printf("Scheduling method: %s\n", policy_name);

    return 0;
}