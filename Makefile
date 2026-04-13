build_projects:
	MODE=recursive
	go run ./go_implement/
	python ./python_implement/main.py
	./c_implement/recursive_merge_sort 10


