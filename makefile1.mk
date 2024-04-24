# # Compiler
# CC = gcc
# CFLAGS = -Wall -Wextra -Werror

# # Target executable
# TARGET = a1.exe

# # Source files
# SRCS = mainn.c storee.c

# # Object files
# OBJS = $(SRCS:.c=.o)

# # Default target
# all: $(TARGET)

# # Compile source files into object files
# %.o: %.c storee.h
# 	$(CC) $(CFLAGS) -c $< -o $@

# # Link object files into the executable
# $(TARGET): $(OBJS)
# 	$(CC) $(CFLAGS) $^ -o $@

# # Clean up
# clean:
# 	rm -f $(OBJS) $(TARGET)


# Compiler
CC=gcc

a1.exe: mass.o has.o
	gcc mass.o has.o -o a1.exe

mass.o: mass.c has.h
	gcc -c mass.c

has.o: has.c has.h
	gcc -c has.c