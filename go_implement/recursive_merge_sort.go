package main

func MergeSortRecursive(arr []int) []int {
	if len(arr) <= 1 {
		return arr
	}

	mid := len(arr) / 2
	left := MergeSortRecursive(arr[:mid])
	right := MergeSortRecursive(arr[mid:])

	return merge(left, right)
}
