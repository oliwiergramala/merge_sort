"""Main script for testing merge sort implementations."""

import os
import sys
import time
from recursive_merge_sort import merge_sort_recursive
from iterative_merge_sort import merge_sort_iterative


def is_sorted(arr):
    """Checks if the array is sorted in ascending order."""
    for i in range(1, len(arr)):
        if arr[i - 1] > arr[i]:
            return False
    return True


def main():
    """Main function to execute merge sort with user input or command-line arguments."""
    mode = os.getenv("MODE", "iterative").lower()

    if len(sys.argv) > 1:
        # Parse command-line arguments as array elements
        try:
            arr = [int(x) for x in sys.argv[1:]]
        except ValueError:
            print("Error: All arguments must be integers.")
            return
    else:
        # Read from standard input
        print("Insert array:")
        try:
            input_line = input().strip()
            if not input_line:
                print("Error: No input provided.")
                return
            arr = [int(x) for x in input_line.split()]
        except ValueError:
            print("Error: Input must contain only space-separated integers.")
            return

    if not arr:
        print("Error: Array cannot be empty.")
        return

    start = time.time()

    if mode == "recursive":
        sorted_arr = merge_sort_recursive(arr)
    else:  # iterative
        sorted_arr = merge_sort_iterative(arr)

    end = time.time()

    print(f"Sorted array: {sorted_arr}")
    print(f"Is sorted: {is_sorted(sorted_arr)}")
    print(f"mode: {mode}")
    print(f"Time: {(end - start) * 1000:.6f} ms")


if __name__ == "__main__":
    main()
