# Debugging Memory Allocator for C++

This project implements a debugging memory allocator for managing dynamic memory allocation in C++ programs. The allocator tracks memory usage statistics, mitigates memory fragmentation, detects common programming errors, and stores allocation metadata within allocated memory blocks.

## Features

- Memory Usage Statistics
- Memory Reuse and Fragmentation Mitigation
- Error Detection
- Allocation Metadata

## Usage

Integrate the allocator functions (`m61_malloc`, `m61_free`, `m61_calloc`, `m61_realloc`) into your codebase and initialize the allocator at the beginning of your program. Use the allocator functions for dynamic memory allocation and deallocation, and monitor error messages and statistics generated during program execution.

## Extra 

- Internal Metadata
- Additional Tests
- Multiple Buffers
- Large Buffers
- High-Performance Allocation
