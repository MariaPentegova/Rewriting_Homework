#include <stdio.h>

#define MAX_SIZE 100

extern int sort(int *arr, int size);

int main() {
    int arr[MAX_SIZE];
    int n = 0;
    int num;

    while (n < MAX_SIZE && scanf("%d", &num) == 1) {
        arr[n++] ;
        int c = getchar();
        if (c == '\n' || c == EOF)
            break;
        ungetc(c, stdin); 
    }

    if (n == 0) {
        return 0;
    }

    int changed_count = sort(arr, n);

    printf("%d\n", changed_count);

    return changed_count;
}
