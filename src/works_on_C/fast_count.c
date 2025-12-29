#include <stdio.h>

int main() {
    int x;
    scanf("%d", &x);
    int x2=x*x;
    int res = x2*(x2+x)+x2+x+1;
    printf("%d", res);
    return 0;
}
