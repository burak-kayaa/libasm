# Libasm

A small library written entirely in **x86-64 Assembly (NASM)** that re-implements several standard C library functions.
This project focuses on understanding low-level programming, system calls, calling conventions, and memory manipulation on Linux.

The project is part of the **42 School curriculum** and aims to provide hands-on experience with Assembly language by recreating commonly used C functions.


# Table of Contents

* Overview
* Mandatory Functions
* Bonus Functions
* Project Structure
* Compilation
* Testing
* Implementation Details
* What This Project Teaches
* Author


# Overview

The goal of this project is to recreate several functions from the C standard library using **x86-64 Assembly**.

The implementation follows the **System V AMD64 ABI**, which defines:

* register usage
* function calling conventions
* stack alignment
* return values

All functions are compiled into a static library:

```
libasm.a
```

This library can then be linked with C programs.


# Mandatory Functions

The following functions were implemented in Assembly:

| Function    | Description                        |
| ----------- | ---------------------------------- |
| `ft_strlen` | Returns the length of a string     |
| `ft_strcpy` | Copies a string                    |
| `ft_strcmp` | Compares two strings               |
| `ft_write`  | Wrapper around the `write` syscall |
| `ft_read`   | Wrapper around the `read` syscall  |
| `ft_strdup` | Duplicates a string using `malloc` |

Example usage:

```c
#include "libasm.h"

int main(void)
{
    char *s = ft_strdup("hello");
    printf("%zu\n", ft_strlen(s));
}
```


# Bonus Functions

Additional features include linked list manipulation and base conversion.

## Linked List Utilities

Using the structure:

```c
typedef struct s_list
{
    void            *data;
    struct s_list   *next;
} t_list;
```

Implemented functions:

| Function             | Description                           |
| -------------------- | ------------------------------------- |
| `ft_list_size`       | Returns number of elements in a list  |
| `ft_list_push_front` | Adds a new element at the beginning   |
| `ft_list_sort`       | Sorts the list using a comparator     |
| `ft_list_remove_if`  | Removes elements matching a condition |


## Base Conversion

```
ft_atoi_base
```

Converts a string representing a number in an arbitrary base into an integer.

Example:

```c
ft_atoi_base("1011", "01") -> 11
ft_atoi_base("2A", "0123456789ABCDEF") -> 42
```


# Project Structure

```
libasm/
│
├── Makefile
├── README.md
│
├── include/
│   ├── libasm.h
│   └── libasm_bonus.h
│
├── src/
│   ├── ft_strlen.s
│   ├── ft_strcmp.s
│   ├── ft_strcpy.s
│   ├── ft_write.s
│   ├── ft_read.s
│   └── ft_strdup.s
│
├── src_bonus/
│   ├── ft_list_size_bonus.s
│   ├── ft_list_push_front_bonus.s
│   ├── ft_list_sort_bonus.s
│   ├── ft_list_remove_if_bonus.s
│   └── ft_atoi_base_bonus.s
│
├── obj/
├── obj_bonus/
│
└── test/
    ├── main.c
    ├── main_bonus.c
    └── tests...
```


# Compilation

The project uses **NASM** to assemble the source files.

### Build library

```bash
make
```

Produces:

```
libasm.a
```

### Build with bonus

```bash
make bonus
```


# Testing

The repository contains test programs written in C.

Compile and run tests:

```
make test
./test_libasm
```

Bonus tests:

```
make test_bonus
./test_bonus
```

Sanitizers may be enabled during development to help detect memory issues.


# Implementation Details

## Calling Convention

The project follows the **System V AMD64 ABI**.

Function arguments are passed through registers:

| Argument | Register |
| -------- | -------- |
| 1        | `rdi`    |
| 2        | `rsi`    |
| 3        | `rdx`    |
| 4        | `rcx`    |
| 5        | `r8`     |
| 6        | `r9`     |

Return values are stored in:

```
rax
```


## Stack Alignment

External function calls (such as `malloc`) require the stack to be **16-byte aligned**.

Improper alignment can cause crashes or undefined behavior.


## Syscalls

`ft_write` and `ft_read` directly use Linux syscalls.

Example:

```
write -> syscall number 1
read  -> syscall number 0
```

Errors are handled by setting `errno` accordingly.
