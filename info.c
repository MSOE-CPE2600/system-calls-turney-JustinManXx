/**
 * Mahrj@msoe.edu
 * CPE 2600
 * 11/15/2024
 * info.c
 * This program prints out the system information to the console
 */

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/utsname.h>
#include <sys/sysinfo.h>
#include <time.h>
#include <unistd.h>

/**
 * Prints out system info by using system calls to the console
 */
int main() {
    struct timespec timeNow;
    struct utsname sysInfo;
    struct sysinfo info;
    char hostName[100];
    
    // Get time of world in Nanoseconds
    if(clock_gettime(CLOCK_REALTIME, &timeNow) == 0) {
        printf("The current time in nanoseconds is: %ld nanoseconds\n", 
        timeNow.tv_nsec);
    }

    // System network name
    if(gethostname(hostName,sizeof(hostName)) == 0) {
        printf("System network name is: %s\n", hostName);
    }

    // Operating system details
    if(uname(&sysInfo) == 0) {
        printf("Operating system: %s\n", sysInfo.sysname);
        printf("Operating system release: %s\n",sysInfo.release);
        printf("Operating system version: %s\n",sysInfo.version);
        printf("Hardware: %s\n", sysInfo.machine);
    }

    // Total number of CPU's
    int numSysCPUs = sysconf(_SC_NPROCESSORS_ONLN);
    printf("Number of CPUs: %d\n",numSysCPUs);

    // System memory
    if(sysinfo(&info) == 0) {
        printf("Total amount of Physical memory: %lu bytes\n",
        info.totalram * info.mem_unit);
        printf("Total amount of Free memory: %lu bytes\n", 
        info.freeram * info.mem_unit);
    }
    return 0;
}