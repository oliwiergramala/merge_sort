#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int arr[], int l, int m, int r, int temp[]) {
    int i = l;
    int j = m + 1;
    int k = l;

    while (i <= m && j <= r) {
        if (arr[i] <= arr[j]) {
            temp[k] = arr[i];
            i++;
        } else {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

    while (i <= m) {
        temp[k] = arr[i];
        i++;
        k++;
    }

    while (j <= r) {
        temp[k] = arr[j];
        j++;
        k++;
    }

    for (i = l; i <= r; i++) {
        arr[i] = temp[i];
    }
}

void mergeSortRecursive(int arr[], int l, int r, int temp[]) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSortRecursive(arr, l, m, temp);
        mergeSortRecursive(arr, m + 1, r, temp);

        merge(arr, l, m, r, temp);
    }
}

void mergeSort(int arr[], int size) {
    int *temp = (int *)malloc(size * sizeof(int));
    if (temp == NULL) {
        return;
    }

    mergeSortRecursive(arr, 0, size - 1, temp);

    free(temp);
}

int is_sorted(int *arr, int n) {
    for (int i = 1; i < n; i++) {
        if (arr[i-1] > arr[i]) return 0;
    }
    return 1;
}
int main(int argc, char *argv[]) {
    int n = atoi(argv[1]);

    int *arr = malloc(n * sizeof(int));

    if (!arr) {
        printf("Failed to allocate array of size %d\n", n);
        return 1;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = rand();
    }

    clock_t start = clock();

    mergeSort(arr, n);

    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time spent: %.6f seconds\n | Sorted: %s |\n", time_spent, is_sorted(arr, n) ? "Yes" : "No");
    printf("\n");

    free(arr);
    return 0;
}