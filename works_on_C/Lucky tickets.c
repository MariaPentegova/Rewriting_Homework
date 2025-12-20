#include <stdio.h>

int countTriplesForSum(int s) {
    int count = 0;
    for (int a = 0; a <= 9; ++a) {
        for (int b = 0; b <= 9; ++b) {
            for (int c = 0; c <= 9; ++c) {
                if (a + b + c == s)
                    ++count;
            }
        }
    }
    return count;
}

int getLuckyTicketsAmount() {
    int total = 0;
    for (int s = 0; s <= 27; ++s) {
        int count = countTriplesForSum(s);
        total += count * count;
    }
    return total;
}

int main() {
    printf("%d\n", getLuckyTicketsAmount());
    return 0;
}
