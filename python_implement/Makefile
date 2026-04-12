.PHONY: all recursive iterative run clean test benchmark

# Default target
all: test

# Run with recursive merge sort
recursive:
	@MODE=recursive python main.py

# Run with iterative merge sort
iterative:
	@MODE=iterative python main.py

# Run the program (default is recursive)
run: recursive

# Run tests
test:
	python -m pytest test_merge_sort.py -v

# Run benchmark
benchmark:
	python benchmark.py

# Clean up generated files
clean:
	@rm -f *.pyc
	@rm -rf __pycache__
	@rm -rf .pytest_cache
	@echo Cleaned up

help:
	@echo "Available targets:"
	@echo "  make recursive   - Run merge sort with recursive implementation"
	@echo "  make iterative   - Run merge sort with iterative implementation"
	@echo "  make run         - Run merge sort (default recursive)"
	@echo "  make test        - Run unit tests"
	@echo "  make benchmark   - Run performance benchmark"
	@echo "  make clean       - Clean up generated files"
	@echo "  make help        - Show this help message"
