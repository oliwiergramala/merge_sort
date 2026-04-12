#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Merges two sorted halves of an array.
void merge(int arr[], int l, int m, int r, int temp[]) {
    int i = l, j = m + 1, k = l;
    while (i <= m && j <= r) {
        if (arr[i] <= arr[j]) temp[k++] = arr[i++];
        else temp[k++] = arr[j++];
    }
    while (i <= m) temp[k++] = arr[i++];
    while (j <= r) temp[k++] = arr[j++];
    for (i = l; i <= r; i++) arr[i] = temp[i];
}

// Recursively divides the array and merges parts.
void mergeSortRecursive(int arr[], int l, int r, int temp[]) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSortRecursive(arr, l, m, temp);
        mergeSortRecursive(arr, m + 1, r, temp);
        merge(arr, l, m, r, temp);
    }
}

// Allocates temporary memory and triggers recursive merge sort.
void mergeSort(int arr[], int size) {
    int *temp = (int *)malloc(size * sizeof(int));
    if (temp) {
        mergeSortRecursive(arr, 0, size - 1, temp);
        free(temp);
    }
}

// Checks if the array is sorted in ascending order.
int is_sorted(int *arr, int n) {
    for (int i = 1; i < n; i++) if (arr[i-1] > arr[i]) return 0;
    return 1;
}

// Prints array elements to the standard output.
void print_array(int *arr, int n) {
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

// Main function: parses flags and executes sorting logic.
int main(int argc, char *argv[]) {
    if (argc < 3) return 1;
    int n = 0, *arr = NULL, is_manual = 0;
    if (strcmp(argv[1], "-r") == 0) {
        n = atoi(argv[2]);
        arr = malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) arr[i] = rand() % 1000;
    } else if (strcmp(argv[1], "-m") == 0) {
        is_manual = 1;
        n = argc - 2;
        arr = malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) arr[i] = atoi(argv[i + 2]);
    }
    if (is_manual) { printf("Before: "); print_array(arr, n); }
    clock_t start = clock();
    mergeSort(arr, n);
    clock_t end = clock();
    if (is_manual) { printf("After:  "); print_array(arr, n); }
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time: %.6f s | Sorted: %s\n", time_spent, is_sorted(arr, n) ? "Yes" : "No");
    free(arr);
    return 0;
}