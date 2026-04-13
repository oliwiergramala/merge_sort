"""Iterative implementation of merge sort algorithm."""


def merge_iter(arr, temp, left, mid, right):
    """Merges two sorted sub-arrays within the same array."""
    i = left
    j = mid + 1
    k = left

    while i <= mid and j <= right:
        if arr[i] <= arr[j]:
            temp[k] = arr[i]
            i += 1
        else:
            temp[k] = arr[j]
            j += 1
        k += 1

    while i <= mid:
        temp[k] = arr[i]
        i += 1
        k += 1

    while j <= right:
        temp[k] = arr[j]
        j += 1
        k += 1

    for i in range(left, right + 1):
        arr[i] = temp[i]


def merge_sort_iterative(arr):
    """Sorts an array using an iterative bottom-up merge sort algorithm."""
    '''We start by treating the array as a collections of cells size 1 and we merge them in sorted arrays'''
    n = len(arr)
    temp = [0] * n # temp is a table of size n we use to store merge results

    size = 1 # current size of a 'cell'
    while size < n:
        left = 0
        while left < n - 1:
            mid = min(left + size - 1, n - 1) # mid is the last index of the left sub-array
            right = min(left + 2 * size - 1, n - 1) # right is the last index of the right sub-array

            merge_iter(arr, temp, left, mid, right)

            left += 2 * size

        size *= 2

    return arr
