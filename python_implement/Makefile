.DEFAULT_GOAL:= build
.PHONY: fmt lint build clean run-recursive run-iterative run-random-recursive run-random-iterative test

fmt:
	python -m black main.py recursive_merge_sort.py iterative_merge_sort.py 2>/dev/null || true
	python -m autopep8 --in-place main.py recursive_merge_sort.py iterative_merge_sort.py 2>/dev/null || true

lint:
	python -m pylint main.py recursive_merge_sort.py iterative_merge_sort.py 2>/dev/null || true
	python -m flake8 main.py recursive_merge_sort.py iterative_merge_sort.py 2>/dev/null || true

build: lint
	python -m py_compile main.py recursive_merge_sort.py iterative_merge_sort.py

test:
	python -m pytest test_merge_sort.py -v

clean:
	find . -type d -name __pycache__ -exec rm -rf {} + 2>/dev/null || true
	find . -type f -name "*.pyc" -delete 2>/dev/null || true
	find . -type d -name .pytest_cache -exec rm -rf {} + 2>/dev/null || true

run-recursive:
	MODE=recursive python main.py

run-iterative:
	MODE=iterative python main.py

run-random-recursive:
	python generate_array.py $(SIZE) | MODE=recursive python main.py

run-random-iterative:
	python generate_array.py $(SIZE) | MODE=iterative python main.py
