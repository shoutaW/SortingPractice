#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void bubbleSort(int arr[], int n);
void selectionSort(int arr[], int n);
void quickSort(int arr[], int low, int high);
int partition(int arr[], int low, int high);
void printArray(int arr[], int n);

int main() {
    int n, choice;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int *arr = (int*)malloc(n * sizeof(int));

    printf("Enter the elements:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\nChoose a sorting algorithm:\n");
    printf("1. Bubble Sort\n2. Selection Sort\n3. Quick Sort\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            bubbleSort(arr, n);
            printf("Sorted array using Bubble Sort:\n");
            break;
        case 2:
            selectionSort(arr, n);
            printf("Sorted array using Selection Sort:\n");
            break;
        case 3:
            quickSort(arr, 0, n-1);
            printf("Sorted array using Quick Sort:\n");
            break;
        default:
            printf("Invalid choice.\n");
            free(arr);
            return 1;
    }

    printArray(arr, n);
    free(arr);
    return 0;
}

// Bubble Sort
void bubbleSort(int arr[], int n) {
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// Selection Sort
void selectionSort(int arr[], int n) {
    for(int i = 0; i < n-1; i++) {
        int minIdx = i;
        for(int j = i+1; j < n; j++) {
            if(arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        int temp = arr[minIdx];
        arr[minIdx] = arr[i];
        arr[i] = temp;
    }
}

// Quick Sort
void quickSort(int arr[], int low, int high) {
    if(low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low-1;
    for(int j = low; j < high; j++) {
        if(arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i+1];
    arr[i+1] = arr[high];
    arr[high] = temp;
    return i+1;
}

// Print array
void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
