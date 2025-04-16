#include <stdio.h>
#include <stdlib.h>

void improved_buble_sort(int arr[], int size)
{
    int bound = size, t, i, temp, count = 0;
    do
    {
        t = 0;
        for (i = 0; i < bound - 1; i++)
        {
            count++;
            if (arr[i] > arr[i + 1])
            {
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                t = i;
            }
        }
        bound = t + 1;
    } while (t > 0);
    printf("Number of comparisions %d\n", count);
}

void insertion_sort(int arr[], int size)
{
    int i, j, key, count = 0;
    for (i = 1; i < size; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            count++;
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    printf("Number of comparisions %d\n", count);
}

void heapify(int arr[], int size, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < size && arr[left] > arr[largest])
    {
        largest = left;
    }
    if (right < size && arr[right] > arr[largest])
    {
        largest = right;
    }
    if (largest != i)
    {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, size, largest);
    }
}

void heap_sort(int arr[], int size)
{
    int i;
    int count = 0;
    for (i = (size / 2) - 1; i >= 0; i--)
    {
        heapify(arr, size, i);
    }
    for (i = size - 1; i > 0; i--)
    {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
        count++;
    }
    printf("Number of comparisions %d\n", count);
}
void display(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d, ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int A[] = {10, 34, 5, 96, 67};
    int B[] = {10, 20, 30, 40, 50};
    int C[] = {50, 40, 30, 20, 10};
    display(A, 5);

    improved_buble_sort(A, 5);
    display(A, 5);
    insertion_sort(A, 5);
    display(A, 5);
    heap_sort(A, 5);
    display(A, 5);
    return 0;
}