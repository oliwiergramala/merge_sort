#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void merge(int l[], int l_size, int r[], int r_size, int result[])
{
    int i = 0, j = 0, k = 0;
    while (i < l_size && j < r_size)
    {
        if (l[i] < r[j])
            result[k++] = l[i++];
        else
            result[k++] = r[j++];
    }
    while (i < l_size)
        result[k++] = l[i++];
    while (j < r_size)
        result[k++] = r[j++];
}

void mergeSort(int arr[], int length)
{
    int step = 1;
    while (step < length)
    {
        for (int i = 0; i < length; i += 2 * step)
        {
            int l_size = step;
            int r_size = step;
            if (i + step >= length)
            {
                l_size = length - i;
                r_size = 0;
            }
            else if (i + 2 * step > length)
            {
                r_size = length - (i + step);
            }
            int *l = (int *)malloc(l_size * sizeof(int));
            int *r = (int *)malloc(r_size * sizeof(int));
            int *merged = (int *)malloc((l_size + r_size) * sizeof(int));
            for (int j = 0; j < l_size; ++j)
                l[j] = arr[i + j];
            for (int j = 0; j < r_size; ++j)
                r[j] = arr[i + step + j];
            merge(l, l_size, r, r_size, merged);
            for (int j = 0; j < l_size + r_size; ++j)
                arr[i + j] = merged[j];
            free(l);
            free(r);
            free(merged);
        }
        step *= 2;
    }
}

int is_sorted(int *arr, int n)
{
    for (int i = 1; i < n; i++)
        if (arr[i - 1] > arr[i])
            return 0;
    return 1;
}

void print_array(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(int argc, char *argv[])
{
    if (argc < 3)
        return 1;
    int n = 0, *arr = NULL, is_manual = 0;
    if (strcmp(argv[1], "-r") == 0)
    {
        n = atoi(argv[2]);
        arr = malloc(n * sizeof(int));
        for (int i = 0; i < n; i++)
            arr[i] = rand() % 1000;
    }
    else if (strcmp(argv[1], "-m") == 0)
    {
        is_manual = 1;
        n = argc - 2;
        arr = malloc(n * sizeof(int));
        for (int i = 0; i < n; i++)
            arr[i] = atoi(argv[i + 2]);
    }

    if (is_manual)
    {
        printf("Before: ");
        print_array(arr, n);
    }

    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);

    mergeSort(arr, n);

    clock_gettime(CLOCK_MONOTONIC, &end);

    if (is_manual)
    {
        printf("After:  ");
        print_array(arr, n);
    }

    double time_spent = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1000000000.0;
    printf("Time: %.9f s | Sorted: %s\n", time_spent, is_sorted(arr, n) ? "Yes" : "No");

    free(arr);
    return 0;
}