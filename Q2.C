#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int maxDepth = 0;
void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];
    int i, j, k;
    for(i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for(j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;

    while(i < n1 && j < n2)
    {
        if(L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }
    while(i < n1)
        arr[k++] = L[i++];

    while(j < n2)
        arr[k++] = R[j++];
}
void mergeSort(int arr[], int left, int right, int depth)
{
    if(depth > maxDepth)
        maxDepth = depth;

    if(left < right)
    {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid, depth + 1);
        mergeSort(arr, mid + 1, right, depth + 1);

        merge(arr, left, mid, right);
    }
}
int main()
{
    int sizes[] = {10, 20, 50, 100, 200, 500, 1000};
    int totalSizes = 7;
    srand(time(NULL));
    printf("Input Size\tMaximum Recursion Depth\n");
    printf("--------------------------------------\n");

    for(int s = 0; s < totalSizes; s++)
    {
        int n = sizes[s];
        int arr[n];
        for(int i = 0; i < n; i++)
            arr[i] = rand() % 10000;
        maxDepth = 0;
        mergeSort(arr, 0, n - 1, 1);
        printf("%d\t\t%d\n", n, maxDepth);
    }
    return 0;
}
