/**
 * Mahrj@msoe.edu
 * CPE 2600
 * 11/15/2024
 * finfo.c
 * This program reads in a file, directory, Link, etc. and prints out
 * info about the file such as permissions, owner info, fize size, 
 * & last modification date
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>

// Prototype methods
void printPermissions(mode_t mode);
void printFileType(mode_t mode);

/**
 * This function prints out information for a file, directory, etc. that
 * the user has inputed in via the command line when running the program
 */
int main(int argc, char *argv[]) {
    // Check for user input
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }


    struct stat fileInfo;
    if (stat(argv[1], &fileInfo) == -1) {
        perror("Error retrieving file information");
        exit(EXIT_FAILURE);
    }

    printFileType(fileInfo.st_mode);
    printPermissions(fileInfo.st_mode);
    printf("Owner UID: %d\n", fileInfo.st_uid);
    printf("File size: %ld bytes\n", fileInfo.st_size);

    char mod_time[20];
    strftime(mod_time, sizeof(mod_time), "%Y-%m-%d %H:%M:%S", localtime(&fileInfo.st_mtime));
    printf("Last modified: %s\n", mod_time);

    return 0;
}
/**
 * Prints the permissions of the file
 */
void printPermissions(mode_t mode) {
    printf("Permissions: ");
    printf((mode & S_IRUSR) ? "r" : "-");
    printf((mode & S_IWUSR) ? "w" : "-");
    printf((mode & S_IXUSR) ? "x" : "-");
    printf((mode & S_IRGRP) ? "r" : "-");
    printf((mode & S_IWGRP) ? "w" : "-");
    printf((mode & S_IXGRP) ? "x" : "-");
    printf((mode & S_IROTH) ? "r" : "-");
    printf((mode & S_IWOTH) ? "w" : "-");
    printf((mode & S_IXOTH) ? "x" : "-");
    printf("\n");
}

/**
 * Prints out the file type to the user
 */
void printFileType(mode_t mode) {
    if (S_ISREG(mode)) printf("File type: regular file\n");
    else if (S_ISDIR(mode)) printf("File type: directory\n");
    else if (S_ISLNK(mode)) printf("File type: link\n");
    else printf("File type: other\n");
}
