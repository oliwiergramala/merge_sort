"""Unit tests for merge sort implementations."""

import pytest
from recursive_merge_sort import merge_sort_recursive
from iterative_merge_sort import merge_sort_iterative


@pytest.mark.parametrize("implementation", [merge_sort_recursive, merge_sort_iterative])
class TestMergeSort:
    """Test suite for merge sort implementations."""

    def test_empty_array(self, implementation):
        """Test sorting an empty array."""
        assert implementation([]) == []

    def test_single_element(self, implementation):
        """Test sorting a single-element array."""
        assert implementation([5]) == [5]

    def test_two_elements_sorted(self, implementation):
        """Test sorting two elements already in order."""
        assert implementation([1, 2]) == [1, 2]

    def test_two_elements_unsorted(self, implementation):
        """Test sorting two elements out of order."""
        assert implementation([2, 1]) == [1, 2]

    def test_sorted_array(self, implementation):
        """Test sorting an already sorted array."""
        arr = [1, 2, 3, 4, 5]
        assert implementation(arr) == [1, 2, 3, 4, 5]

    def test_reverse_sorted_array(self, implementation):
        """Test sorting a reverse-sorted array."""
        arr = [5, 4, 3, 2, 1]
        assert implementation(arr) == [1, 2, 3, 4, 5]

    def test_random_array(self, implementation):
        """Test sorting a random array."""
        arr = [64, 34, 25, 12, 22, 11, 90]
        assert implementation(arr) == [11, 12, 22, 25, 34, 64, 90]

    def test_array_with_duplicates(self, implementation):
        """Test sorting an array with duplicate elements."""
        arr = [5, 2, 8, 2, 9, 1, 5, 5]
        assert implementation(arr) == [1, 2, 2, 5, 5, 5, 8, 9]

    def test_array_with_negative_numbers(self, implementation):
        """Test sorting an array with negative numbers."""
        arr = [3, -1, 4, -5, 2]
        assert implementation(arr) == [-5, -1, 2, 3, 4]

    def test_large_array(self, implementation):
        """Test sorting a large array."""
        arr = list(range(1000, 0, -1))
        result = implementation(arr.copy())
        assert result == sorted(arr)

    def test_array_with_zeros(self, implementation):
        """Test sorting an array containing zeros."""
        arr = [3, 0, -2, 0, 5]
        assert implementation(arr) == [-2, 0, 0, 3, 5]


if __name__ == "__main__":
    pytest.main([__file__, "-v"])
