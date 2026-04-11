.DEFAULT_GOAL:= build
.PHONY:fmt vet build

fmt:
	go fmt ./...

vet:
	go vet ./...

build: vet fmt
	go build
clean:
	go clean
run-recursive:
	MODE=recursive go run .

run-iterative:
	MODE=iterative go run .

run-random-recursive:
	echo "5 2 9 1 7 3" | MODE=recursive go run .

run-random-iterative:
	echo "5 2 9 1 7 3" | MODE=iterative go run .
