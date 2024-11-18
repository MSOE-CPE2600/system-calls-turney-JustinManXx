# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -g

# Default target
all: info pinfo pmod finfo

# Build info
info: info.c
	$(CC) $(CFLAGS) -o info info.c  
# Build pinfo
pinfo: pinfo.c
	$(CC) $(CFLAGS) -o pinfo pinfo.c  

# Build pmod
pmod: pmod.c
	$(CC) $(CFLAGS) -o pmod pmod.c  

# Build finfo
finfo: finfo.c
	$(CC) $(CFLAGS) -o finfo finfo.c  

# Clean target
clean:
	rm -f info pinfo pmod finfo  