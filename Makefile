.DEFAULT_GOAL := build
MAKEFLAGS += -s
.PHONY: build clean run-recursive run-iterative

build:
	$(MAKE) -C python_implement build
	$(MAKE) -C go_implement build
	$(MAKE) -C c_implement

clean:
	$(MAKE) -C python_implement clean
	$(MAKE) -C go_implement clean
	$(MAKE) -C c_implement clean

random:
	shuf -i 0-100 -n $(SIZE)| tr '\n' ' ' > array

run-test-random: random run-recursive run-iterative


run-recursive-random: random run-recursive 
run-recursive:
	echo "Recursive";
	echo "=== PYTHON ==="; \
	cat ./array | $(MAKE) -C python_implement run-recursive; \
	echo "=== GO ==="; \
	cat ./array | $(MAKE) -C go_implement run-recursive; \
	echo "=== C ==="; \
	cat ./array | $(MAKE) -C c_implement run-recursive

run-iterative-random: random run-iterative
run-iterative:
	echo "Iterative";
	echo "=== PYTHON ==="; \
	cat ./array | $(MAKE) -C python_implement run-iterative; \
	echo "=== GO ==="; \
	cat ./array | $(MAKE) -C go_implement run-iterative; \
	echo "=== C ==="; \
	cat ./array | $(MAKE) -C c_implement run-iterative

