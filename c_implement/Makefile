CC = gcc
CFLAGS = -Wall -Wextra -O2
BINS = iterative_merge_sort recursive_merge_sort

all: $(BINS)

iterative_merge_sort: iterative_merge_sort.c
	$(CC) $(CFLAGS) -o $@ $<

recursive_merge_sort: recursive_merge_sort.c
	$(CC) $(CFLAGS) -o $@ $<

manual: all
	@read -p "Enter numbers to sort (space-separated): " vals; \
	echo "\n--- Iterative ---"; \
	./iterative_merge_sort -m $$vals; \
	echo "--- Recursive ---"; \
	./recursive_merge_sort -m $$vals

auto: all
	@read -p "Enter array size (random values): " size; \
	echo "\n--- Iterative ---"; \
	./iterative_merge_sort -r $$size; \
	echo "--- Recursive ---"; \
	./recursive_merge_sort -r $$size

run-iterative: iterative_merge_sort
	@read -p "Enter numbers to sort (space-separated): " vals; \
	./iterative_merge_sort -m $$vals

run-recursive: recursive_merge_sort
	@read -p "Enter numbers to sort (space-separated): " vals; \
	./recursive_merge_sort -m $$vals

clean:
	rm -f $(BINS) *.exe