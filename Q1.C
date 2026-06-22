#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
void threeWayQuickSort(int arr[], int low, int high)
{
    if (low >= high)
        return;
    int lt = low;
    int gt = high;
    int pivot = arr[low];
    int i = low;
    while (i <= gt)
    {
        if (arr[i] < pivot)
        {
            swap(&arr[i], &arr[lt]);
            i++;
            lt++;
        }
        else if (arr[i] > pivot)
        {
            swap(&arr[i], &arr[gt]);
            gt--;
        }
        else
        {
            i++;
        }
    }

    threeWayQuickSort(arr, low, lt - 1);
    threeWayQuickSort(arr, gt + 1, high);
}

int main()
{
    int n = 10000;
    int arr1[10000], arr2[10000];

    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        arr1[i] = rand() % 10;
        arr2[i] = arr1[i];
    }
    clock_t start, end;
    double time1, time2;
    start = clock();
    quickSort(arr1, 0, n - 1);
    end = clock();
    time1 = (double)(end - start) / CLOCKS_PER_SEC;
    start = clock();
    threeWayQuickSort(arr2, 0, n - 1);
    end = clock();
    time2 = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Standard Quick Sort Time: %f seconds\n", time1);
    printf("Three-Way Quick Sort Time: %f seconds\n", time2);

    return 0;
}
