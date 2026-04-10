CC = gcc
CFLAGS = -Wall -Wextra -O2
SIZE = 1000000

all: iterative_merge_sort recursive_merge_sort

iterative_merge_sort: iterative_merge_sort.c
	$(CC) $(CFLAGS) -o $@ $<

recursive_merge_sort: recursive_merge_sort.c
	$(CC) $(CFLAGS) -o $@ $<

run: all
	@echo ===== Iterative =====
	./iterative_merge_sort $(SIZE)
	@echo ===== Recursive =====
	./recursive_merge_sort $(SIZE)

time: all
	@echo ===== Iterative =====
	@time ./iterative_merge_sort $(SIZE)
	@echo ===== Recursive =====
	@time ./recursive_merge_sort $(SIZE)

time_win: all
	powershell -Command "Measure-Command { .\iterative_merge_sort.exe $(SIZE) }"
	powershell -Command "Measure-Command { .\recursive_merge_sort.exe $(SIZE) }"

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

clean:
	rm -f *.exe iterative_merge_sort recursive_merge_sort