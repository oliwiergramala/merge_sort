#!/usr/bin/env python3
"""Generate a random array with user-friendly prompts."""

import random
import sys


def get_size():
    """Get array size from command line or user input."""
    if len(sys.argv) > 1:
        try:
            return int(sys.argv[1])
        except ValueError:
            print(f"Error: '{sys.argv[1]}' is not a valid number")
            sys.exit(1)
    
    while True:
        try:
            size = input("How many numbers to generate? (default 10): ").strip()
            if not size:
                return 10
            return int(size)
        except ValueError:
            print("Please enter a valid number")


def get_range():
    """Get value range from user."""
    while True:
        try:
            max_val = input("Maximum absolute value? (default 100): ").strip()
            if not max_val:
                return 100
            return int(max_val)
        except ValueError:
            print("Please enter a valid number")


def main():
    """Generate and print random array."""
    print("Random Array Generator")
    print("-" * 40)
    
    size = get_size()
    max_val = get_range()
    
    arr = [random.randint(-max_val, max_val) for _ in range(size)]
    
    print(f"\nGenerated array ({size} elements, range -{max_val} to {max_val}):")
    print(" ".join(map(str, arr)))


if __name__ == "__main__":
    main()
