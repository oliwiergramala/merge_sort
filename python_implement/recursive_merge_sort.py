"""Recursive implementation of merge sort algorithm."""


def merge(left, right):
    """Merges two sorted lists into a single sorted list."""
    result = []
    i = j = 0

    while i < len(left) and j < len(right):
        if left[i] <= right[j]:
            result.append(left[i])
            i += 1
        else:
            result.append(right[j])
            j += 1

    result.extend(left[i:])
    result.extend(right[j:])

    return result


def merge_sort_recursive(arr):
    """Recursively divides and sorts the array."""
    if len(arr) <= 1:
        return arr

    mid = len(arr) // 2
    left = merge_sort_recursive(arr[:mid])
    right = merge_sort_recursive(arr[mid:])

    return merge(left, right)
