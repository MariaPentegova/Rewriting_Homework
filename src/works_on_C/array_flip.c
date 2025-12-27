#include <stdio.h>

void do_reverse(int *arr, int start, int end) {
    while (start < end) {
        int t = arr[start];
        arr[start] = arr[end];
        arr[end] = t;
        start++;
        end--;
    }
}

void swap_segments(int *arr, int len, int m) {
    do_reverse(arr, 0, m - 1);
    do_reverse(arr, m, len - 1);
    do_reverse(arr, 0, len - 1);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8}; 
    int m = 3; 
    int n = 5; 
    int len = m + n;

    swap_segments(arr, len, m);

    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
