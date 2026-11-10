#include <stdio.h>

void printArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - 1 - i; j++)
            if (arr[j] < arr[j + 1])
            { /* descending: highest marks first */
                int t = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = t;
            }
}

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int maxIdx = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] > arr[maxIdx])
                maxIdx = j;
        int t = arr[i];
        arr[i] = arr[maxIdx];
        arr[maxIdx] = t;
    }
}

void heapify(int arr[], int n, int i)
{
    int largest = i, left = 2 * i + 1, right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;
    if (largest != i)
    {
        int t = arr[i];
        arr[i] = arr[largest];
        arr[largest] = t;
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (int i = n - 1; i > 0; i--)
    {
        int t = arr[0];
        arr[0] = arr[i];
        arr[i] = t;
        heapify(arr, i, 0);
    }
    /* heapSort produces ascending order; reverse for descending merit list */
    for (int i = 0; i < n / 2; i++)
    {
        int t = arr[i];
        arr[i] = arr[n - 1 - i];
        arr[n - 1 - i] = t;
    }
}

int main()
{
    int marks1[] = {72, 88, 65, 91, 76, 83};
    int marks2[] = {72, 88, 65, 91, 76, 83};
    int marks3[] = {72, 88, 65, 91, 76, 83};
    int n = 6;

    printf("Original Marks       : ");
    printArr(marks1, n);

    bubbleSort(marks1, n);
    printf("Bubble Sort (Rank)   : ");
    printArr(marks1, n);

    selectionSort(marks2, n);
    printf("Selection Sort (Rank): ");
    printArr(marks2, n);

    heapSort(marks3, n);
    printf("Heap Sort (Rank)     : ");
    printArr(marks3, n);

    return 0;
}