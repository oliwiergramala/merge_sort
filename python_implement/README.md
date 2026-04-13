# Python Implementation

Implementation of merge sort in Python.

## Overview

This directory contains two implementations of the merge sort algorithm in Python:

1. **Recursive Implementation** (`recursive_merge_sort.py`)
   - Divides the array recursively into halves
   - Merges the sorted halves back together
   - More intuitive and easier to understand
   - Uses more stack space due to recursion

2. **Iterative Implementation** (`iterative_merge_sort.py`)
   - Uses a bottom-up approach
   - Starts with small subarrays and progressively merges larger ones
   - More memory-efficient in terms of stack usage
   - Better for large datasets

## Requirements

- Python 3.6 or higher

## Installation

No external dependencies are required for running the main implementations. For testing and benchmarking, install pytest:

```bash
pip install pytest
```

## How to Run

### Interactive Mode

```bash
python main.py
```

You'll be prompted to enter an array of integers:

```
Insert array:
5 3 8 1 2
```

### With Arguments

```bash
python main.py 5 3 8 1 2
```

### Using Make

- Run with recursive implementation (default):
  ```bash
  make run
  ```

- Run with recursive implementation explicitly:
  ```bash
  make recursive
  ```

- Run with iterative implementation:
  ```bash
  make iterative
  ```

### Run Tests

```bash
make test
```

This runs all unit tests using pytest.

### Run Benchmark

```bash
make benchmark
```

This compares the performance of both implementations across different array sizes.

### Clean Upss

```bash
make clean
```

## Implementation Details

### Time Complexity
- **Best Case**: O(n log n)
- **Average Case**: O(n log n)
- **Worst Case**: O(n log n)

### Space Complexity
- **Recursive**: O(n) for the merged arrays + O(log n) for recursion stack
- **Iterative**: O(n) for the temporary array

## Files

- `recursive_merge_sort.py` - Recursive implementation
- `iterative_merge_sort.py` - Iterative implementation
- `main.py` - Main driver program
- `test_merge_sort.py` - Unit tests
- `benchmark.py` - Performance benchmarks
- `Makefile` - Build and test automation
- `README.md` - This file
