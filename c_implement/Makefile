CC = gcc
CFLAGS = -Wall -Wextra -O2
BINS = iterative_merge_sort recursive_merge_sort

# Compiles both programs
all: $(BINS)

iterative_merge_sort: iterative_merge_sort.c
	$(CC) $(CFLAGS) -o $@ $<

recursive_merge_sort: recursive_merge_sort.c
	$(CC) $(CFLAGS) -o $@ $<

# Allows manual entry of numbers (space-separated)
manual: all
	@read -p "Enter numbers to sort (space-separated): " vals; \
	echo "\n--- Iterative ---"; \
	./iterative_merge_sort -m $$vals; \
	echo "--- Recursive ---"; \
	./recursive_merge_sort -m $$vals

# Allows entering the size for a random array
auto: all
	@read -p "Enter array size (random values): " size; \
	echo "\n--- Iterative ---"; \
	./iterative_merge_sort -r $$size; \
	echo "--- Recursive ---"; \
	./recursive_merge_sort -r $$size

# Removes compiled binaries
clean:
	rm -f $(BINS) *.exe