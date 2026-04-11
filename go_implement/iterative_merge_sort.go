package main

func MergeSortIterative(arr []int) []int {
	n := len(arr)
	temp := make([]int, n)

	for size := 1; size < n; size *= 2 {
		for left := 0; left < n-1; left += 2 * size {
			mid := min(left+size-1, n-1)
			right := min(left+2*size-1, n-1)

			mergeIter(arr, temp, left, mid, right)
		}
	}

	return arr
}

func mergeIter(arr, temp []int, left, mid, right int) {
	i, j, k := left, mid+1, left

	for i <= mid && j <= right {
		if arr[i] <= arr[j] {
			temp[k] = arr[i]
			i++
		} else {
			temp[k] = arr[j]
			j++
		}
		k++
	}

	for i <= mid {
		temp[k] = arr[i]
		i++
		k++
	}

	for j <= right {
		temp[k] = arr[j]
		j++
		k++
	}

	for i := left; i <= right; i++ {
		arr[i] = temp[i]
	}
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
