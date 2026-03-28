CC = gcc
CFLAGS = -Wall -Wextra -O2

# default target
all: iterative_merge_sort recursive_merge_sort

# Compile
iterative_merge_sort: iterative_merge_sort.c
	$(CC) $(CFLAGS) -o $@ $<

recursive_merge_sort: recursive_merge_sort.c
	$(CC) $(CFLAGS) -o $@ $<

# Run
run: all
	@echo ===== Iterative =====
	./iterative_merge_sort
	@echo ===== Recursive =====
	./recursive_merge_sort

# Time measurement (Linux/Mac)
time: all
	@echo ===== Iterative =====
	@time ./iterative_merge_sort
	@echo ===== Recursive =====
	@time ./recursive_merge_sort

# Time measurement (Windows PowerShell)
time_win: all
	powershell -Command "Measure-Command { .\iterative_merge_sort.exe }"
	powershell -Command "Measure-Command { .\recursive_merge_sort.exe }"

# Benchmark
bench_sizes: all
	@echo "===== BENCHMARK ====="
	@for n in 99999999; do \
		echo ""; \
		echo "SIZE = $$n"; \
		echo "Iterative:"; \
		./iterative_merge_sort $$n; \
		echo "Recursive:"; \
		./recursive_merge_sort $$n; \
	done
#stress test
stress_test: all
	@echo "===== STRESS TEST ====="
	@size=10000; \
	while true; do \
		echo ""; \
		echo "Testing size = $$size"; \
		if ! ./iterative_merge_sort $$size > /dev/null 2>&1; then \
			echo "Iterative crashed at size $$size"; \
			break; \
		fi; \
		if ! ./recursive_merge_sort $$size > /dev/null 2>&1; then \
			echo "Recursive crashed at size $$size"; \
			break; \
		fi; \
		size=$$((size * 2)); \
	done

# clean
clean:
	rm -f *.exe iterative_merge_sort recursive_merge_sort