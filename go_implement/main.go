package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func merge(left, right []int) []int {
	result := []int{}
	i, j := 0, 0

	for i < len(left) && j < len(right) {
		if left[i] < right[j] {
			result = append(result, left[i])
			i++
		} else {
			result = append(result, right[j])
			j++
		}
	}

	result = append(result, left[i:]...)
	result = append(result, right[j:]...)

	return result
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Println("Insert array:")

	input, _ := reader.ReadString('\n')
	fields := strings.Fields(input)

	arr := []int{}
	for _, f := range fields {
		num, _ := strconv.Atoi(f)
		arr = append(arr, num)
	}

	mode := os.Getenv("MODE")

	var sorted []int

	if mode == "recursive" {
		sorted = MergeSortRecursive(arr)
	} else {
		sorted = MergeSortIterative(arr)
	}

	fmt.Println("Sorted array:", sorted)
}
