# Memory Management Simulator

A simple C program that simulates how memory can be allocated and released in a computer system. The project represents memory as a collection of blocks and manages them using a linked list.

## About the Project

The simulator starts with a fixed memory space of **1024 units**. Users can allocate memory, release previously allocated blocks, and view the current memory layout.

The project uses the **First Fit allocation technique**, where the program selects the first free block that is large enough for the requested memory.

## Features

- Fixed memory size of 1024 units
- Memory allocation using the First Fit strategy
- Automatic splitting of larger free blocks
- Memory deallocation using the starting address
- Display of allocated and free memory blocks
- Linked list-based memory block management

## Technologies and Concepts

- C Programming
- Structures
- Linked Lists
- Dynamic Memory Allocation
- Operating System Memory Management
- First Fit Algorithm

## Project Structure

```text
Memory-Management-Simulator/
│
├── memory_simulator.c
└── README.md
```

## How to Compile

Use GCC to compile the program:

```bash
gcc memory_simulator.c -o memory_simulator
```

## How to Run

On Windows PowerShell:

```powershell
.\memory_simulator
```

## Available Options

The program provides the following menu options:

1. Allocate memory
2. Free an allocated memory block
3. View the current memory status
4. Exit the program

## Example

After allocating 200 units and then 300 units, the memory may look like this:

```text
Start:    0 | Size:  200 | Status: ALLOCATED
Start:  200 | Size:  300 | Status: ALLOCATED
Start:  500 | Size:  524 | Status: FREE
```

## What I Learned

This project helped me understand how memory blocks can be represented and managed in C. It also provided hands-on practice with linked lists, dynamic memory allocation, block splitting, and the First Fit memory allocation approach.

## Possible Enhancements

- Add Best Fit and Worst Fit allocation strategies
- Merge adjacent free memory blocks
- Display memory usage statistics
- Extend the simulator with additional memory management techniques

## Author

**Shaik Baba Shareef**

GitHub: https://github.com/ShareefShaik1234
