#define MAX_SIZE 100
#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (arr[j] <= pivot) {
                i++;
                swap(&arr[i], &arr[j]);
            }
        }
        swap(&arr[i + 1], &arr[high]);
        int pi = i + 1;
      
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int arr[MAX_SIZE];
    int n = 0;

    while (n < MAX_SIZE && scanf("%d", &arr[n]) == 1) {
        n++;
    }

    int original[MAX_SIZE];
    for (int i = 0; i < n; i++) {
        original[i] = arr[i];
    }

    quickSort(arr, 0, n - 1);

    int changed_positions = 0;
    for (int i = 0; i < n; i++) {
        if (original[i] != arr[i]) {
            changed_positions++;
        }
    }

    printf("%d\n", changed_positions);
    return changed_positions;
}
